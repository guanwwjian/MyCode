#pragma once
#include "stdafx.h"
#include "Form1.h"
namespace shoushishibie
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Threading;
	using namespace Emgu::CV;
	using namespace Emgu::CV::Structure;
	using namespace Emgu::CV::CvEnum;
	using namespace Emgu::Util;
Void Form1::emgucapture()
	{
		int i,j;
		Emgu::CV::Image<Bgr, Byte> ^frame = cam->QueryFrame();
		Emgu::CV::CvInvoke::cvSmooth(frame,frame,CvEnum::SMOOTH_TYPE::CV_GAUSSIAN,3,3,3,3);
		Emgu::CV::Structure::Bgr white(255,255,255),black(0,0,0),red(0,0,255);
		int a[camheight][camwidth];
		se->getmap(frame,a);
		List<array<int>^> ^fl=data->classify(a,frame);
		bit=gcnew Bitmap(frame->Bitmap);
		for (i=0;i<camwidth;i++)
			for (j=0;j<camheight;j++)
				if (a[j][i]==-1) frame[j,i]=black;
		bit2=gcnew Bitmap(frame->Bitmap);
		for (int i=0;i<fl->Count;i++)
		{
			frame->Draw(LineSegment2D(Point(fl[i][0],fl[i][1]),Point(fl[i][2],fl[i][3])),Bgr(255,0,255),1);
		}
		circle ^tt1=cp->getcomitem();
		for (i=0;i<data->circount();i++)
		{
			circle ^tt=data->getcir(i);
			if (tt->count>0)	
			{
				if ((tt1)&&(tt->no==tt1->no)) frame->Draw(tt->no.ToString()+"/"+tt->hcla.ToString(),MCvFont(Emgu::CV::CvEnum::FONT::CV_FONT_HERSHEY_COMPLEX, 0.2, 0.2),Point(tt->x,tt->y),Bgr(0,255,0));
				else frame->Draw(tt->no.ToString()+"/"+tt->hcla.ToString(),MCvFont(Emgu::CV::CvEnum::FONT::CV_FONT_HERSHEY_COMPLEX, 0.2, 0.2),Point(tt->x,tt->y),Bgr(0,0,255));
				frame->Draw(Ellipse(Drawing::PointF(tt->x,tt->y),Drawing::SizeF(tt->a*2,tt->b*2),tt->c/pi*180+90),Bgr(255,0,0),1);
			}
			
		}
		bit1=frame->Bitmap;
		pictureBox1->Image=bit1;
		pictureBox3->Image=bit;
		pictureBox4->Image=bit1;
	}
System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				firstflag=true;
				exit=false;
				notifyIcon1->ContextMenuStrip=contextMenuStrip1;
				bp=gcnew Bpnet();
				bp->load();
				cam=gcnew Emgu::CV::Capture(0);
				cam->SetCaptureProperty(CvEnum::CAP_PROP::CV_CAP_PROP_FRAME_WIDTH, camwidth);
				cam->SetCaptureProperty(CvEnum::CAP_PROP::CV_CAP_PROP_FRAME_HEIGHT, camheight);
				data=gcnew Dataset(bp);
				cp= gcnew Commandposter(data);
				se=gcnew SkinExtractor(this);
				dc=gcnew Devicecontroler();
				curfiles=gcnew List<String^>;
				curfiles->Add(gcnew String("hand0.cur"));
				curfiles->Add(gcnew String("hand1.cur"));
				curfiles->Add(gcnew String("hand2.cur"));
				curfiles->Add(gcnew String("hand3.cur"));
				curfiles->Add(gcnew String("hand4.cur"));
				se->initstart();
			 }
		Void Form1::button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 se->modetwo();
		 }
		Void Form1::button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 se->modeone();
		 }
		Void Form1::button12_Click(System::Object^  sender, System::EventArgs^  e) {
			se->initstart();
		 }
		Void Form1::button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 se->reset();
		 }
}