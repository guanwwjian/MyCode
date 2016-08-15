///////////////////////////////////////////////////////////////////////////////////////////////////
//
//  欢迎使用物理3D演示平台项目生成向导, 通过此向导系统将自动为生成开发物理模型所需的文件, 而且不需要进行
//  任何配置即可编程.
// 
//  创建: Physics3D4 物理演示
//
///////////////////////////////////////////////////////////////////////////////////////////////////


// =============以下内容为程序必须内容,请匆删除之================================================

// 一定要包含此文件，此库的包含文件
#include "ztopengldev.h"

// 资源文件
#include "Resource.h"

// 包括数学函数
#include <math.h>

// 标准C库函数
#include <stdlib.h>
#include <stdio.h>

// 使用画图库的命名空间
using namespace DW;

// 全部动太库实例
HINSTANCE h_3dInstance = NULL;

// 动态库入口, 请不要编辑这些内容
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
// ==============================程序必须内容结束=================================================


// TODO: 如果还有其它函数库请在这里写包含文件

// TODO: 如果你要定义全局变量，结构等请写在这里

/*

 此函数用来初始化您开发的3D模型，比如参数个数，等设置

 @params : 表示参数表， 一般是通过编程实现参数的初始化，但你也可以使用方便的函数据：ConfigParam来添加参数。
 @count  : 表示参数的个数，有几个参数就赋值多少个，比如： *count = 1;
 @sysConfig : 待定

 */
bool play=false,show=false;
void ZTInitParamsEx(PZTParamTable params, int *count, PZTDrawConfig sysConfig, PExDrawConfig exconfig)
{
	// 使用默认的宋体文字
	DW::OpenGL::DW_CreateFont();
	// 下面语句设定模型基本信息
	// sysConfig,固定，100 - 表示循环时间间隔(每一贴间隔时间)，单位为ms，-30，Z轴深度, 它决定了可见范围，1 - 表示此程序中包含了多少个子模型， “Physics3D4” 表示模型名称，"Physic3D Author" - 此程序的开发者是谁？

	DW::OpenGL::ConfigModule(sysConfig, 1, -30, 1, "Physics3D4", "Physic3D Author");


	// 下面过程来设定本程序中所有子模型的名称，0/1表示按顺度设定，后面的字符表示模型的名称。，这里的调用次数为上一函数中的1位置的参数表示的数量
	// 在绘图函数中可以通过：config->curModule来获取当前操作用户选择了哪种作图，其值与这里设定的顺序值一致
	//DW::OpenGL::SetSubModule(sysConfig, 0, "3D模型");
	//DW::OpenGL::SetSubModule(sysConfig, 1, "画曲线");


	// TODO: 添加按钮 (在需要时)
	// DW::UI::ClearButtons();  // 清除按钮
	// DW::UI::AddButton(0, "录制", 20, 100, 60, 20); // 添加第一个按钮, 0 - 序号,必须从0开始,不可重复, 在RawWindowProc中id以wParam传递, 第二个参数为按钮的文字, 后四个参数,库按钮矩形大小,前两个表示left,top, 后两个表示宽/高
	// DW::UI::AddButton(1, "播放", 100, 100, 60, 20); // 添加第二个按钮
	DW::OpenGL::Param(params, 0, "旋转速度", 2, -5, 5, 10);
	*count=1;
	DW::UI::AddButton(0,"播放",20, 100, 60, 20);
	DW::UI::AddButton(1, "显示力矩", 100, 100, 60, 20);
//		OpenGL::OpenLight(1);

	// 设定参数
	//DW::OpenGL::Param(params, INDEX, NAME, CURVALUE, MINVALUE, MAXVALUE, SPLITTICKS);
	// 通过这一语句可以设定参数
	// INDEX必须按顺序0,1,2,3,4.....
	// NAME参数名称，比如周期
	// CURVALUE当前值，默认值
	// MINVALUE - MAXVALUE, 此参数的有效范围。
	// SPLITTICKS 把此参数从 MINVALUE到MAXVALUE间分成多少段

	// 最后，设定参数个数， N为参数的个数，比如1,2,3
	// *count = N;

	// =======纹理操作==============
	
	// 使用以下方未能从文件中加载纹理, 注意:文件中的纹理,将不能在网页中使用
	//DW::OpenGL::LoadGLTextures(0, "texturefilename.bmp");

	// 使用以下方法从VC资源中添加纹理
	//DW::OpenGL::LoadGLTexturesFromRES(h_3dInstance, 0, RES_ID);


	// =========设置模型的额外视频===============
	/*
	char vpath[250] = {0};
	strcat(vpath, exconfig->modulePath);  // 当前模型所在路径(.phy3d), 本例表示视频与模型同目录
	strcat(vpath, "\\test.mpg");
	strcpy(exconfig->videoPath, vpath);  // 保存视频文件路径
	*/

	// 添加坐标参数
	//DW::UI::AddCoor(0, "第一点坐标", 10);

	//设置是否充许转动/移动/缩放
	//DW::OpenGL::ConfigAllow(sysConfig, false, true, false);

	// 注意:光源也可以在此处定义
	//DW::OpenGL::OpenColorLight(0, toCF(1,1,1), toP(3,3,0)); // 打开有色光源(光源不随场景一起动)

	// TODO: 可以在这里添加一些画图的初始化操作,比如建立显	示列表, 大量计算等 
}


/*
	画图函数，请把你的绘图代码写在这里

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
	// 画背景，可以设置颜色，四个顶点的颜色，自动渐变
	DW::OpenGL::DW_DrawBackground(toC(0,0,0),toC(0,0,0),toC(0,0,0),toC(0,0,0));
	

	// 完成坐标的转动，移动，缩放等， 不调用将不会产生旋转，移动，放大的效果。
     OpenGL::BeginDraw(config);
	
	//==========以上几句一般不要删除======================

	// 参数引用，表示你在上面一个函数中设置的参数值的引用，
	// config->paramValueList为一个double性的指针，它自动分配与你在上面一个参数设置函数中设置的参数，并表示当前值
	// 通过paramValueList[INDEX]，INDEX必须为：0 - 参数个数间的整数，来分别引用不同的参数，也可以根据：DW::OpenGL::pv(index)来获取参数
	// double xxx = config->paramValueList[0];

	// ===============================TODO: 请修改以下程序来完成你的模型的绘制=======================================

	//DW::OpenGL::OpenColorLight(0, toCF(1,1,1), toP(0,3,10)); // 打开有色光源(光源将随场景一起动)
 	DW::OpenGL::OpenColorLight(0, toCF(0.2,0.2,0.2), toP(50,50,20)); // 打开有色光源
 	DW::OpenGL::OpenColorLight(1, toCF(0.2,0.2,0.2), toP(-50,50,-20)); // 打开有色光源
 	DW::OpenGL::OpenColorLight(2, toCF(0.2,0.2,0.2), toP(50,10,10)); // 打开有色光源
//	OpenGL::OpenLight(0);
/*	GLfloat position[] = { 8.0, 8.0, 8.0, 0.0 };	
	GLfloat ambient[] = {3.0, 3.0, 3.0, 3.0 };
	GLfloat diffuse[] = { 3.0, 3.0, 3.0, 3.0 };
	GLfloat specular[] = { 3.0, 3.0, 3.0, 3.0 };
	OpenGL::DW_SetupLight(0, position, ambient, diffuse, specular);*/
	DW::OpenGL::OpenColor();   // 开启颜色材质功能

	 // 设置鼠标位置的球的颜色

	//DW::OpenGL::CloseColor();  // 关闭颜色材质功能
	//  // 关闭光源,关闭光源后,在需的地时候首先一定要打开,否则光源无效
//DW::OpenGL::CloseLight(0);

	// ==============================物理模型一贴绘图完成=============================================================
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

	// ==========================================================请不要删除以下语句==========================
	// 最后调用此语句来交换GL绘图场景与图形界面
;
	DW::OpenGL::DW_GLValid();
	if (play) i=i+1;
	if (i>100000000) i=0;
}

/*
	基于消息的编程,可以用于编制声音等,按钮等, 此部分操作要特别小心,不得有死循环,否则将导致不可想象的错误
 */
void RawWindowProc(int winId, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, int ctlId, LPARAM reserved1, LPARAM reserved2)
{
	switch(msg)
	{
	case D3_WM_BUTTON_CLICK:  // 自定义按钮被点击
		// TODO: 在此添加按钮的操作, int b_id = (int)wParam; 可以读取当前按下的按钮的ID
		switch ((int)wParam)
		{
		case 1:
			play=!play;
			if (play) DW::UI::SetButtonText(0,"暂停");
			else DW::UI::SetButtonText(0,"播放");
			break;
		case 2:
			show=!show;
			if (show) DW::UI::SetButtonText(1,"隐藏力矩");
			else DW::UI::SetButtonText(1,"显示力矩");
			break;
		}
		break;
	// TODO: 可以在这里添加case来处理常用消息(ztopengldev.h中定义[D3_开头]和mmsystem.h中声音处理消息均会自动映射到此消息中来)
	}
}

/* 
   此方法将在模型关闭时调用一次,可以执行一些内存清理工作
 */
void RawDestroy(HWND hwnd)
{
	// TODO: 可以在这里执行内存清理工作
	
}

