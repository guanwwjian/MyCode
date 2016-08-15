///////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ��ӭʹ������3D��ʾƽ̨��Ŀ������, ͨ������ϵͳ���Զ�Ϊ���ɿ�������ģ��������ļ�, ���Ҳ���Ҫ����
//  �κ����ü��ɱ��.
// 
//  ����: Physics3D4 ������ʾ
//
///////////////////////////////////////////////////////////////////////////////////////////////////


// =============��������Ϊ�����������,���ɾ��֮================================================

// һ��Ҫ�������ļ����˿�İ����ļ�
#include "ztopengldev.h"

// ��Դ�ļ�
#include "Resource.h"

// ������ѧ����
#include <math.h>

// ��׼C�⺯��
#include <stdlib.h>
#include <stdio.h>

// ʹ�û�ͼ��������ռ�
using namespace DW;

// ȫ����̫��ʵ��
HINSTANCE h_3dInstance = NULL;

// ��̬�����, �벻Ҫ�༭��Щ����
BOOL APIENTRY DllMain( HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) 
{ 
    switch(ul_reason_for_call) 
    { 
    case DLL_PROCESS_ATTACH: 
       h_3dInstance = (HINSTANCE)hModule;
    case DLL_PROCESS_DETACH: 
       break; 
    } 
  return TRUE; 
}
// ==============================����������ݽ���=================================================


// TODO: �������������������������д�����ļ�

// TODO: �����Ҫ����ȫ�ֱ������ṹ����д������

/*

 �˺���������ʼ����������3Dģ�ͣ��������������������

 @params : ��ʾ������ һ����ͨ�����ʵ�ֲ����ĳ�ʼ��������Ҳ����ʹ�÷���ĺ����ݣ�ConfigParam����Ӳ�����
 @count  : ��ʾ�����ĸ������м��������͸�ֵ���ٸ������磺 *count = 1;
 @sysConfig : ����

 */
bool play=false,show=false;
void ZTInitParamsEx(PZTParamTable params, int *count, PZTDrawConfig sysConfig, PExDrawConfig exconfig)
{
	// ʹ��Ĭ�ϵ���������
	DW::OpenGL::DW_CreateFont();
	// ��������趨ģ�ͻ�����Ϣ
	// sysConfig,�̶���100 - ��ʾѭ��ʱ����(ÿһ�����ʱ��)����λΪms��-30��Z�����, �������˿ɼ���Χ��1 - ��ʾ�˳����а����˶��ٸ���ģ�ͣ� ��Physics3D4�� ��ʾģ�����ƣ�"Physic3D Author" - �˳���Ŀ�������˭��

	DW::OpenGL::ConfigModule(sysConfig, 1, -30, 1, "Physics3D4", "Physic3D Author");


	// ����������趨��������������ģ�͵����ƣ�0/1��ʾ��˳���趨��������ַ���ʾģ�͵����ơ�������ĵ��ô���Ϊ��һ�����е�1λ�õĲ�����ʾ������
	// �ڻ�ͼ�����п���ͨ����config->curModule����ȡ��ǰ�����û�ѡ����������ͼ����ֵ�������趨��˳��ֵһ��
	//DW::OpenGL::SetSubModule(sysConfig, 0, "3Dģ��");
	//DW::OpenGL::SetSubModule(sysConfig, 1, "������");


	// TODO: ��Ӱ�ť (����Ҫʱ)
	// DW::UI::ClearButtons();  // �����ť
	// DW::UI::AddButton(0, "¼��", 20, 100, 60, 20); // ��ӵ�һ����ť, 0 - ���,�����0��ʼ,�����ظ�, ��RawWindowProc��id��wParam����, �ڶ�������Ϊ��ť������, ���ĸ�����,�ⰴť���δ�С,ǰ������ʾleft,top, ��������ʾ��/��
	// DW::UI::AddButton(1, "����", 100, 100, 60, 20); // ��ӵڶ�����ť
	DW::OpenGL::Param(params, 0, "��ת�ٶ�", 2, -5, 5, 10);
	*count=1;
	DW::UI::AddButton(0,"����",20, 100, 60, 20);
	DW::UI::AddButton(1, "��ʾ����", 100, 100, 60, 20);
//		OpenGL::OpenLight(1);

	// �趨����
	//DW::OpenGL::Param(params, INDEX, NAME, CURVALUE, MINVALUE, MAXVALUE, SPLITTICKS);
	// ͨ����һ�������趨����
	// INDEX���밴˳��0,1,2,3,4.....
	// NAME�������ƣ���������
	// CURVALUE��ǰֵ��Ĭ��ֵ
	// MINVALUE - MAXVALUE, �˲�������Ч��Χ��
	// SPLITTICKS �Ѵ˲����� MINVALUE��MAXVALUE��ֳɶ��ٶ�

	// ����趨���������� NΪ�����ĸ���������1,2,3
	// *count = N;

	// =======�������==============
	
	// ʹ�����·�δ�ܴ��ļ��м�������, ע��:�ļ��е�����,����������ҳ��ʹ��
	//DW::OpenGL::LoadGLTextures(0, "texturefilename.bmp");

	// ʹ�����·�����VC��Դ���������
	//DW::OpenGL::LoadGLTexturesFromRES(h_3dInstance, 0, RES_ID);


	// =========����ģ�͵Ķ�����Ƶ===============
	/*
	char vpath[250] = {0};
	strcat(vpath, exconfig->modulePath);  // ��ǰģ������·��(.phy3d), ������ʾ��Ƶ��ģ��ͬĿ¼
	strcat(vpath, "\\test.mpg");
	strcpy(exconfig->videoPath, vpath);  // ������Ƶ�ļ�·��
	*/

	// ����������
	//DW::UI::AddCoor(0, "��һ������", 10);

	//�����Ƿ����ת��/�ƶ�/����
	//DW::OpenGL::ConfigAllow(sysConfig, false, true, false);

	// ע��:��ԴҲ�����ڴ˴�����
	//DW::OpenGL::OpenColorLight(0, toCF(1,1,1), toP(3,3,0)); // ����ɫ��Դ(��Դ���泡��һ��)

	// TODO: �������������һЩ��ͼ�ĳ�ʼ������,���罨����	ʾ�б�, ��������� 
}


/*
	��ͼ�����������Ļ�ͼ����д������

 */
double i=0;
void Cylinder(double bradius, double tradius,  bool fill = false, P3D p1 = toP(0,0,0), P3D p2 = toP(1,0,0), int slice = 32, int stack = 32)
{
    
}
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_ambient_color1[] = { 0.8, 0.8, 0.8, 0.5 };
	GLfloat mat_diffuse[] = { 1.0, 1.0,1.0,1.0};
//	GLfloat mat_specular[] = { 0.8, 0.8, 0.8, 0.8 };
	GLfloat mat_specular[] = { 1.0, 1.0,1.0,1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

void ZTDraw(ZTOpenGLConfig *config)
{
	// ������������������ɫ���ĸ��������ɫ���Զ�����
	DW::OpenGL::DW_DrawBackground(toC(0,0,0),toC(0,0,0),toC(0,0,0),toC(0,0,0));
	

	// ��������ת�����ƶ������ŵȣ� �����ý����������ת���ƶ����Ŵ��Ч����
     OpenGL::BeginDraw(config);
	
	//==========���ϼ���һ�㲻Ҫɾ��======================

	// �������ã���ʾ��������һ�����������õĲ���ֵ�����ã�
	// config->paramValueListΪһ��double�Ե�ָ�룬���Զ���������������һ���������ú��������õĲ���������ʾ��ǰֵ
	// ͨ��paramValueList[INDEX]��INDEX����Ϊ��0 - ��������������������ֱ����ò�ͬ�Ĳ�����Ҳ���Ը��ݣ�DW::OpenGL::pv(index)����ȡ����
	// double xxx = config->paramValueList[0];

	// ===============================TODO: ���޸����³�����������ģ�͵Ļ���=======================================

	//DW::OpenGL::OpenColorLight(0, toCF(1,1,1), toP(0,3,10)); // ����ɫ��Դ(��Դ���泡��һ��)
 	DW::OpenGL::OpenColorLight(0, toCF(0.2,0.2,0.2), toP(50,50,20)); // ����ɫ��Դ
 	DW::OpenGL::OpenColorLight(1, toCF(0.2,0.2,0.2), toP(-50,50,-20)); // ����ɫ��Դ
 	DW::OpenGL::OpenColorLight(2, toCF(0.2,0.2,0.2), toP(50,10,10)); // ����ɫ��Դ
//	OpenGL::OpenLight(0);
/*	GLfloat position[] = { 8.0, 8.0, 8.0, 0.0 };	
	GLfloat ambient[] = {3.0, 3.0, 3.0, 3.0 };
	GLfloat diffuse[] = { 3.0, 3.0, 3.0, 3.0 };
	GLfloat specular[] = { 3.0, 3.0, 3.0, 3.0 };
	OpenGL::DW_SetupLight(0, position, ambient, diffuse, specular);*/
	DW::OpenGL::OpenColor();   // ������ɫ���ʹ���

	 // �������λ�õ������ɫ

	//DW::OpenGL::CloseColor();  // �ر���ɫ���ʹ���
	//  // �رչ�Դ,�رչ�Դ��,����ĵ�ʱ������һ��Ҫ��,�����Դ��Ч
//DW::OpenGL::CloseLight(0);

	// ==============================����ģ��һ����ͼ���=============================================================
	int v=OpenGL::pv(config,0)*2;
	
	  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, no_mat);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);

    //OpenGL::DW_Reset(); OpenGL::BeginDraw(config);
	glPushMatrix();
	/*GLfloat position[] = { 1.0, 0.0, 0.0, 0.0 };	
	GLfloat ambient[] = {0.8, 0.8, 0.8, 0.0 };
	GLfloat diffuse[] = { 0.24, 0.45, 0.68, 1.0 };
	GLfloat specular[] = { 0.5,0.5,0.5,1.0 };
	GLfloat emission[]={1,1,1,1};
	OpenGL::DW_SetupMat(GL_FRONT,  ambient, diffuse, specular);*/
	OpenGL::DW_SetColor(toC(150,140,80));
	OpenGL::DW_DrawSphere(0.2);
	OpenGL::DW_DrawCylinder(0.2,0.2,10,true,toP(0,0,0),toD(90,0,0));
	glPopMatrix();
	//OpenGL::DW_Reset();OpenGL::BeginDraw(config);
	glPushMatrix();
	if (v!=0)
	{
	OpenGL::DW_RotateZ((30/v*sin((double)(i/10))));
	OpenGL::DW_RotateY(i*8/v);
	//OpenGL::DW_RotateZ(-60);

	}
	//OpenGL::DW_SetColor(toC(80,80,80));
	OpenGL::DW_DrawCylinder(0.2,0.2,6.2,true,toP(0,0,0),toD(-30,0,0));
	//OpenGL::DW_SetColor(toC(30,120,120));
	OpenGL::DW_SetColor(toC(120,120,120));
	OpenGL::DW_DrawGear(toP(0,3,3.0*sqrt((double)3)),0,3,0.03,8,2.5,toD(-30,0,i*5*v/2));
	//OpenGL::DW_DrawTorus(0.5,4,toP(0,3,3.0*sqrt((double)3)),toD(-30,0,i*5*v/2));
	OpenGL::DW_SetColor(toC(30,30,30));
	DW::OpenGL::DrawTuros(0.5,4,toP(0,3,3.0*sqrt((double)3)),toD(-30,0,i*5*v/2));
	//DW::OpenGL::CloseColor();
//	DW::OpenGL::CloseLight(0);
	if ((show)&&(v!=0))
	{
		OpenGL::DW_SetColor(toC(255,0,0));
		OpenGL::DW_DrawArrowEx(toP(0,0,0),toP(0,v*1.3,(double)v*1.3*sqrt((double)3)),0.21);
		OpenGL::DW_SetColor(toC(0,255,0));
		OpenGL::DW_DrawArrowEx(toP(0,v*1.3,(double)v*1.3*sqrt((double)3)),toP(2,v*1.3,(double)v*1.3*sqrt((double)3)),0.21);
		OpenGL::DW_SetColor(toC(0,0,255));
		OpenGL::DW_DrawArrowEx(toP(0,0,0),toP(2,v*1.3,(double)v*1.3*sqrt((double)3)),0.21);


	}

	glPopMatrix();
	OpenGL::DW_SetColor(toC(80,80,80));
	OpenGL::DW_DrawBox(10,0.5,10,toP(0,-10,0));
	OpenGL::DW_DrawBox(100,0.2,100,toP(0,-10.2,0));

	// ==========================================================�벻Ҫɾ���������==========================
	// �����ô����������GL��ͼ������ͼ�ν���
;
	DW::OpenGL::DW_GLValid();
	if (play) i=i+1;
	if (i>100000000) i=0;
}

/*
	������Ϣ�ı��,�������ڱ���������,��ť��, �˲��ֲ���Ҫ�ر�С��,��������ѭ��,���򽫵��²�������Ĵ���
 */
void RawWindowProc(int winId, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, int ctlId, LPARAM reserved1, LPARAM reserved2)
{
	switch(msg)
	{
	case D3_WM_BUTTON_CLICK:  // �Զ��尴ť�����
		// TODO: �ڴ���Ӱ�ť�Ĳ���, int b_id = (int)wParam; ���Զ�ȡ��ǰ���µİ�ť��ID
		switch ((int)wParam)
		{
		case 1:
			play=!play;
			if (play) DW::UI::SetButtonText(0,"��ͣ");
			else DW::UI::SetButtonText(0,"����");
			break;
		case 2:
			show=!show;
			if (show) DW::UI::SetButtonText(1,"��������");
			else DW::UI::SetButtonText(1,"��ʾ����");
			break;
		}
		break;
	// TODO: �������������case����������Ϣ(ztopengldev.h�ж���[D3_��ͷ]��mmsystem.h������������Ϣ�����Զ�ӳ�䵽����Ϣ����)
	}
}

/* 
   �˷�������ģ�͹ر�ʱ����һ��,����ִ��һЩ�ڴ�������
 */
void RawDestroy(HWND hwnd)
{
	// TODO: ����������ִ���ڴ�������
	
}

