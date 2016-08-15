#pragma once
const int defsubmittime=50;
#include"HandMenuForm.h"
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
ref class Handmenu:shoushishibie::HandMenuForm
{
	int screenw,screenh,status,time,submittime,menuno,count;
	float sr,mr,lr,wr,midx,midy,com,da;
	bool enabled;
	List<List<String^>^> ^menutexts;
	Bitmap ^bit;
	Graphics ^g;
	SolidBrush ^back,^word,^selback,^selword,^out;
	Pen ^line;
	Drawing::Font ^wf;
	array<RectangleF> ^wrect;
public:
	Handmenu():HandMenuForm()
	{
		updatescreensize();
		menutexts=gcnew List<List<String^>^>;
		status=0;
		submittime=defsubmittime;
		int a=255;
		back=gcnew SolidBrush(Color::FromArgb(a,0,0,0));
		word=gcnew SolidBrush(Color::FromArgb(a,254,254,254));
		selback=gcnew SolidBrush(Color::FromArgb(a,254,254,254));
		selword=gcnew SolidBrush(Color::FromArgb(a,0,0,0));
		out=gcnew SolidBrush(Color::FromArgb(a,128,128,128));
		line=gcnew Pen(Color::FromArgb(a,255,255,255),10.0);
		wf=gcnew Drawing::Font(gcnew String("ËÎÌו"),15.0);
		enabled=false;
		this->Width=screenw;
		this->Height=screenh;
		this->Location=Point(0,0);
		bit=gcnew Bitmap(screenw,screenh);
		g=Graphics::FromImage(bit);
		this->BackgroundImage=bit;
	}
	void updatescreensize()
	{
		updatescreensize(1366,768);
	}
	void updatescreensize(int w,int h)
	{
		screenw=w;
		screenh=h;
		sr=screenh/6;
		mr=sr*2;
		wr=(sr+mr)/2;  
		lr=sr*2.3;
		midx=screenw/2;
		midy=screenh/2;
	}
	void addmenufromstring(String ^s)
	{
		String ^ts=gcnew String(s);
		menutexts->Add(gcnew List<String^>);
		while (ts->Length>0)
		{
			int tt=ts->IndexOf(',');
			if (tt>=0)
			{
				menutexts[menutexts->Count-1]->Add(gcnew String(ts->ToCharArray(),0,tt));
				ts=ts->Remove(0,tt+1);
			}
			else
			{
				menutexts[menutexts->Count-1]->Add(gcnew String(ts));
				ts=ts->Remove(0);
			}
		}
	}
	void changestatus(int x)
	{
		status=x;
	}
	void menustart(int no)
	{
		status=0;
		time=0;
		enabled=true;
		menuno=no;
		count=menutexts[menuno]->Count;
		da=360.0/(count-1);
		wrect=gcnew array<RectangleF>(count);
		float leng=(mr-sr)/Math::Sqrt(2);
		wrect[0]=RectangleF(midx-leng/2,midy-leng/2,leng,leng);
		for (int i=1;i<count;i++)
		{
			float a=(i-1)*da-90;
			wrect[i]=RectangleF(midx+Math::Cos(a/180*Math::PI)*wr-leng/2,midy+Math::Sin(a/180*Math::PI)*wr-leng/2,leng,leng);
		}
		this->Show();
	}
	void menuend()
	{
		enabled=false;
		g->Clear(this->TransparencyKey);
		this->Refresh();
		this->Hide();
	}
	int updatemenu()
	{
		com=-1;
		if (enabled)
		{
			g->Clear(this->TransparencyKey);
			g->FillPie(out,midx-lr,midy-lr,lr*2,lr*2,-90.0,360.0*time/(submittime-1));
			for (int i=0;i<count-1;i++)
			{
					
				if (status==i+1) g->FillPie(selback,midx-mr,midy-mr,mr*2,mr*2,i*da-da/2-90,da);
				else g->FillPie(back,midx-mr,midy-mr,mr*2,mr*2,i*da-da/2-90,da);
				g->DrawPie(line,midx-mr,midy-mr,mr*2,mr*2,i*da-da/2-90,da);
			}
			if (status==0) g->FillEllipse(selback,midx-sr,midy-sr,sr*2,sr*2);
			else g->FillEllipse(back,midx-sr,midy-sr,sr*2,sr*2);
			g->DrawEllipse(line,midx-sr,midy-sr,sr*2,sr*2);
			StringFormat ^sf = gcnew StringFormat();
			sf->Alignment = StringAlignment::Center;
			sf->LineAlignment = StringAlignment::Center;
			for (int i=0;i<count;i++)
			{
				if (status==i) g->DrawString(menutexts[menuno][i],wf,selword,wrect[i],sf);
				else g->DrawString(menutexts[menuno][i],wf,word,wrect[i],sf);
			}
			
			this->Refresh();
			if (time==submittime) 
			{
				com=status;
				menuend();
			}
			time++;
		}
		return com;
	}
	int getmenuno()
	{
		return menuno;
	}
	int getselectcount()
	{
		return count;
	}
};