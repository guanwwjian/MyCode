// Terrain3DTestView.cpp : implementation of the CTerrain3DTestView class
// Download by http://www.codefans.net

#include "stdafx.h"
#include "Terrain3DTest.h"
#include "MilkShapeModel.h"

#include "Terrain3DTestDoc.h"
#include "Terrain3DTestView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
GLuint texturem = 0;
GLfloat XPOS = -MAX/2;
GLfloat YPOS = 0;
GLfloat ZPOS = -MAX/2;
GLfloat XP=0;
GLfloat YP=0;
GLfloat ZP=0;

GLfloat xtrans = MAX/2;
GLfloat ytrans = 0;
GLfloat ztrans = MAX/2;

GLfloat visual_distance = 100;
GLfloat sun_height = 1000;
GLfloat sun_zdistance = -5000;

GLfloat xtexa; 
GLfloat ytexa; 
GLfloat xtexa2; 
GLfloat ytexa2; 
    
int xrange1 ; 
int xrange2 ;
int zrange1 ;
int zrange2 ;   

GLfloat	xrot=0;				// 绕 X 轴旋转
GLfloat	yrot=0;				// 绕 Y 轴旋转
GLfloat	zrot=0;				// 绕 Z 轴旋转
GLfloat	xr = 0;
GLfloat	yr = 0;
GLfloat	zr = 0;
GLfloat	xt = 0;
GLfloat	yt = 0;
GLfloat	zt = 0;
GLfloat size = 1;
GLfloat Throttlei;
GLfloat Throttle = 5;
GLfloat _Throttle=Throttle;
GLfloat Speed = Throttle;
GLfloat Speedi;
GLfloat piover180 = 0.0174532925f;
GLfloat sceneroty;
GLfloat heading;
GLfloat pitch = 0;
GLfloat yaw = 0;

GLfloat zprot;

int quality = 3;

GLfloat H = 0;

GLfloat glow = .4;
GLfloat glowp = 0;

bool  wireframe = FALSE;	// 线框绘制模式ON/OFF
bool  water = true;			// 是否绘制水 ON/OFF
bool  Afterburner = false;

GLUquadricObj *quadratic;
GLuint	texture[8];

GLuint MODEL;

GLfloat V;
GLfloat Angle;
int loop;

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestView

IMPLEMENT_DYNCREATE(CTerrain3DTestView, CView)

BEGIN_MESSAGE_MAP(CTerrain3DTestView, CView)
	//{{AFX_MSG_MAP(CTerrain3DTestView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestView construction/destruction
void Changesight()
{
	glLoadIdentity();
	//glTranslatef(xt, yt, -1.9);
	//glTranslatef(0, 0.5f, 10);
	glTranslatef(0+xt, -0.5f-yt, -10+zt);
	glRotatef(yr, 0, 1, 0);
	glScalef(size, size, size);
}
CTerrain3DTestView::CTerrain3DTestView()
{
	// TODO: add construction code here
	pModel = NULL;
}

CTerrain3DTestView::~CTerrain3DTestView()
{
}

BOOL CTerrain3DTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
////////////////////////////////////////////////////////////////
//设置窗口类型
	cs.style |=WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
////////////////////////////////////////////////////////////////
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestView drawing

void CTerrain3DTestView::OnDraw(CDC* pDC)
{
	CTerrain3DTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//////////////////////////////////////////////////////////////////
	RenderScene();	//渲染场景
//////////////////////////////////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestView printing

BOOL CTerrain3DTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTerrain3DTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTerrain3DTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestView diagnostics

#ifdef _DEBUG
void CTerrain3DTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTerrain3DTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTerrain3DTestDoc* CTerrain3DTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTerrain3DTestDoc)));
	return (CTerrain3DTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestView message handlers

int CTerrain3DTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
//////////////////////////////////////////////////////////////////
//初始化OpenGL和设置定时器
	m_pDC = new CClientDC(this);
	SetTimer(1, 20, NULL);
	InitializeOpenGL(m_pDC);
//////////////////////////////////////////////////////////////////
	pModel = new MilkShapeModel();									// Memory To Hold The Model
	if ( pModel->loadModelData( "model.ms3d" ) == false )		// Loads The Model And Checks For Errors
	{
		MessageBox( _T("Couldn't load the model data\\model.ms3d"), _T("Error"), MB_OK | MB_ICONERROR );
		return 0;													// If Model Didn't Load Quit
	}

	InitGL();
	return 0;
}

void CTerrain3DTestView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
/////////////////////////////////////////////////////////////////
//删除调色板和渲染上下文、定时器
	::wglMakeCurrent(0,0);
	::wglDeleteContext( m_hRC);
	if (m_hPalette)
	    DeleteObject(m_hPalette);
	if ( m_pDC )
	{
		delete m_pDC;
	}
	KillTimer(1);		
/////////////////////////////////////////////////////////////////
	
}

void CTerrain3DTestView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (cy==0)	
	{
		cy=1;	
	}
/////////////////////////////////////////////////////////////////
//添加窗口缩放时的图形变换函数
	glViewport(0,0,cx,cy);
/////////////////////////////////////////////////////////////////
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,0.9f,50000.0f);

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
}

void CTerrain3DTestView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
/////////////////////////////////////////////////////////////////
//添加定时器响应函数和场景更新函数
	Invalidate(FALSE);	
/////////////////////////////////////////////////////////////////
	
	CView::OnTimer(nIDEvent);
}

/////////////////////////////////////////////////////////////////////
//	                  设置逻辑调色板
//////////////////////////////////////////////////////////////////////
void CTerrain3DTestView::SetLogicalPalette(void)
{
    struct
    {
        WORD Version;
        WORD NumberOfEntries;
        PALETTEENTRY aEntries[256];
    } logicalPalette = { 0x300, 256 };

	BYTE reds[] = {0, 36, 72, 109, 145, 182, 218, 255};
	BYTE greens[] = {0, 36, 72, 109, 145, 182, 218, 255};
	BYTE blues[] = {0, 85, 170, 255};

    for (int colorNum=0; colorNum<256; ++colorNum)
    {
        logicalPalette.aEntries[colorNum].peRed =
            reds[colorNum & 0x07];
        logicalPalette.aEntries[colorNum].peGreen =
            greens[(colorNum >> 0x03) & 0x07];
        logicalPalette.aEntries[colorNum].peBlue =
            blues[(colorNum >> 0x06) & 0x03];
        logicalPalette.aEntries[colorNum].peFlags = 0;
    }

    m_hPalette = CreatePalette ((LOGPALETTE*)&logicalPalette);
}


//////////////////////////////////////////////////////////
//						初始化openGL场景
//////////////////////////////////////////////////////////
BOOL CTerrain3DTestView::InitializeOpenGL(CDC* pDC)
{
	m_pDC = pDC;
	SetupPixelFormat();
	//生成绘制描述表
	m_hRC = ::wglCreateContext(m_pDC->GetSafeHdc());
	//置当前绘制描述表
	::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);

	return TRUE;
}

//////////////////////////////////////////////////////////
//						设置像素格式
//////////////////////////////////////////////////////////
BOOL CTerrain3DTestView::SetupPixelFormat()
{
	PIXELFORMATDESCRIPTOR pfd = { 
	    sizeof(PIXELFORMATDESCRIPTOR),    // pfd结构的大小 
	    1,                                // 版本号 
	    PFD_DRAW_TO_WINDOW |              // 支持在窗口中绘图 
	    PFD_SUPPORT_OPENGL |              // 支持 OpenGL 
	    PFD_DOUBLEBUFFER,                 // 双缓存模式 
	    PFD_TYPE_RGBA,                    // RGBA 颜色模式 
	    24,                               // 24 位颜色深度 
	    0, 0, 0, 0, 0, 0,                 // 忽略颜色位 
	    0,                                // 没有非透明度缓存 
	    0,                                // 忽略移位位 
	    0,                                // 无累加缓存 
	    0, 0, 0, 0,                       // 忽略累加位 
	    32,                               // 32 位深度缓存     
	    0,                                // 无模板缓存 
	    0,                                // 无辅助缓存 
	    PFD_MAIN_PLANE,                   // 主层 
	    0,                                // 保留 
	    0, 0, 0                           // 忽略层,可见性和损毁掩模 
	}; 	
	int pixelformat;
	pixelformat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);//选择像素格式
	::SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd);	//设置像素格式
	if(pfd.dwFlags & PFD_NEED_PALETTE)
		SetLogicalPalette();	//设置逻辑调色板
	return TRUE;
}



//////////////////////////////////////////////////////////
//						场景绘制与渲染
//////////////////////////////////////////////////////////
BOOL CTerrain3DTestView::RenderScene() 
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	RestoreMyDefaultSettings();
   
	if (-XPOS < 0) XPOS -= MAX; 
	if (-XPOS > MAX) XPOS += MAX;
	if (-ZPOS < 0) ZPOS -= MAX; 
	if (-ZPOS > MAX) ZPOS += MAX;

	xtrans = -XPOS;
	ytrans = YPOS;   
	ztrans = -ZPOS;
	
	yrot = heading;
    
	sceneroty = 360.0f - yrot;
	H = sceneroty;
	if (H > 360) H = 0;
	else if (H < 0) H = 360;

	Changesight();
	glTranslatef(0,0,-10);
	glRotatef(sceneroty,0,1,0);
	glTranslatef(xtrans,ytrans-3.5-ABS(Speed)/5,ztrans);    
   
	xrange1 = int(MAX-xtrans - visual_distance); 
	xrange2 = int(MAX-xtrans + visual_distance);
	zrange1 = int(MAX-ztrans - visual_distance);
	zrange2 = int(MAX-ztrans + visual_distance);   
  
	if (quality != 1)
	{
		xrange1 /= quality;
		xrange1 *= quality;
		xrange2 /= quality;
		xrange2 *= quality;

		zrange1 /= quality;
		zrange1 *= quality;
		zrange2 /= quality;
		zrange2 *= quality;
	}    

	if (wireframe)
	{  
		DrawWireframe();
	}
	else
	{ 
		DrawTexture();
	}

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	Caculate();

	::SwapBuffers(m_pDC->GetSafeHdc());		//交互缓冲区
	return TRUE;
}

bool CTerrain3DTestView::InitGL(GLvoid)
{

	if (!m_texture.LoadGLTextures())				// 装入纹理
	{
		return FALSE;								// 如果纹理不存在,则返回FALSE
	}
	float fog_r = 211.f/255.f;
	float fog_g = 237.f/255.f;
	float fog_b = 254.f/255.f;
	glClearColor(fog_r, fog_g, fog_b, 1);			// 黑背景颜色
	glClearDepth(1.0f);		   							// 深度缓冲设置
  
	RestoreMyDefaultSettings();
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
    // 设置光照效果
	GLfloat LightAmbient[]=		{ 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat LightDiffuse[]=		{ 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightSpecular[]=	{ 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat LightPosition[]=	{ 0.0f, 0.0f, 0.0f, 1.0f };
	
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);	
	glLightfv(GL_LIGHT1, GL_SPECULAR,LightSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
	glEnable(GL_LIGHT1);							
	// 设置雾化效果
	GLuint	fogMode[]= { GL_EXP, GL_EXP2, GL_LINEAR };	// 保存三种雾的模式
	GLuint	fogfilter = 0;								// 当前使用的雾的模式 
	GLfloat	fogColor[4] = {fog_r, fog_g, fog_b, 1};		// 雾的颜色

	glFogi(GL_FOG_MODE, fogMode[2]);			        // 设置雾的模式
	glFogfv(GL_FOG_COLOR, fogColor);					// 设置雾的颜色
	glFogf(GL_FOG_DENSITY, 0.294f);						// 设置雾的浓度
	glHint(GL_FOG_HINT, GL_NICEST);					    // Fog Hint Value
	glFogf(GL_FOG_START, 10.0f);						// 设置雾的开始深度
	glFogf(GL_FOG_END, visual_distance);				// 设置雾的结束深度
	glEnable(GL_FOG);									// 使用雾

	quadratic=gluNewQuadric();						
	gluQuadricNormals(quadratic, GLU_SMOOTH);			// 生成光滑法向
	gluQuadricTexture(quadratic, GL_TRUE);				// 生成纹理坐标

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	InitTerrain();
	InitSmoke();
	MODEL = pModel->makeDisplayList();			// 生成模型的显示列表

	return TRUE;

}

GLfloat CTerrain3DTestView::Hypot(GLfloat A, GLfloat B)
{
	return sqrt(A*A+B*B);
}

GLfloat CTerrain3DTestView::ABS(GLfloat A)
{
	if (A < 0)
		A = -A; 
	return A;
}
void CTerrain3DTestView::RestoreMyDefaultSettings()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_FOG);
}

void CTerrain3DTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 32)
	{
		xt = 0; yt = 0; zt = 0;
		xr = 0; yr = 0; zr = 0;
		size = 1;
	}
	if (nChar == 87)
	{
		yt+=0.1;
	}
	if (nChar == 83)
	{
		yt-=0.1;
	}
	if (nChar == 65)
	{
		xt+=0.1;
	}
	if (nChar == 68)
	{
		xt-=0.1;
	}
	if (nChar == 73)
	{
		zt += 0.1;
	}
	if (nChar == 75)
	{
		zt -= 0.1;
	}
	if (nChar == 74)
	{
		yr += 1;
	}
	if (nChar == 76)
	{
		yr -= 1;
	}
	if (nChar == 187)
	{
		size *= 1.1;
	}
	if (nChar == 189)
	{
		if (size>0.1)size /= 1.1;
	}
	if (nChar == 49)	// 按下'1'键
	{
		_Throttle = 1;
	}
	if (nChar == 50)	// 按下'2'键
	{
		_Throttle = 2;
	}
	if (nChar == 51)	// 按下'3'键
	{
		_Throttle = 3;
	}
	if (nChar == 52)	// 按下'4'键
	{
		_Throttle = 4;
	}
	if (nChar == 53)	// 按下'5'键
	{
		_Throttle = 5;
	}
	if (nChar == 54)	// 按下'6'键
	{
		_Throttle = 6;
	}
	if (nChar == 55)	// 按下'7'键
	{
		_Throttle = 7;
	}
	if (nChar == 56)	// 按下'8'键
	{
		_Throttle = 8;
	}
	if (nChar == 57)	// 按下'9'键
	{
		_Throttle = 9;
	}
	if (nChar == 48)	// 按下'0'键
	{
		_Throttle = 15;
	}
	if(nChar==VK_UP)
	{
		pitch -= 15 / (ABS(Speed)+1);
	}
	if(nChar==VK_DOWN)
	{
		pitch += 15 / (ABS(Speed)+1);
	}
	if(nChar==VK_LEFT)
	{
		zprot += 5/(ABS(Speed)+1);
		Throttle*=.99;               

	}
	if(nChar==VK_RIGHT)
	{
		zprot -= 5/(ABS(Speed)+1);
		Throttle*=.99;
	}

	if (Throttle == 15)
	{
		Afterburner = true;
	}
	else 
	{
		Afterburner = false;
	}

	if(nChar==112)		// 按下'L'键	
	{
		water=!water;
	}
	if(nChar==113)		// 按下'W'键
	{
		wireframe=!wireframe;  
	}	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

bool CTerrain3DTestView::InitTerrain(GLvoid)
{
	int i,i2;     
    
	field[0][0].y=(GLfloat(rand()%100)-50)/3;

	// 生成地形数据
	for (i = 0; i < MAX; i++)
	{  
		for (i2 = 0; i2 < MAX; i2++)
		{
			if (i<10 || i2<10 || i>MAX-10 || i2>MAX-10)
				field[i][i2].y=0;   
			else
				field[i][i2].y=(GLfloat(rand()%151)-75)/50+(field[i-1][i2-1].y+field[i-1][i2].y+field[i-1][i2+1].y+field[i-1][i2-2].y+field[i-1][i2+2].y)/5.05; //Calculate the y coordinate on the same principle. 				
		}
	}
	// 地形光滑处理
   for (int cnt = 0; cnt < 3; cnt++)
   {
	   for (int t = 1; t < MAX-1; t++)
	   {
		   for (int t2 = 1; t2 < MAX-1; t2++)
		   {
			   field[t][t2].y = (field[t+1][t2].y+field[t][t2-1].y+field[t-1][t2].y+field[t][t2+1].y)/4;           
			   if (cnt == 0)
			   {
				   if (field[t][t2].y < -1 && field[t][t2].y > -1-.5) 
					   field[t][t2].y -= .45, field[t][t2].y *= 2;
				   else if (field[t][t2].y > -1 && field[t][t2].y < -1+.5) 
					   field[t][t2].y += .5, field[t][t2].y /= 5;
			   }
		   }
	   }
   }
   return true;
}

bool CTerrain3DTestView::InitSmoke(GLvoid)
{
	// 粒子系统的初始化
	for (loop=0;loop<MAX_PARTICLES;loop++)				
	{
		particle[loop].active=true;					// 使所有的粒子激活
		particle[loop].life=1.0f;					// 给予新的生命
		particle[loop].fade=GLfloat(rand()%100)/7500 + 0.0075f;	// 随机淡化数值
		if (loop < MAX_PARTICLES/2) 
			particle[loop].x= .75f;
		else
			particle[loop].x= -.75f;
		particle[loop].y= -.15;						// Center On Y Axis
		particle[loop].z= 3;						// Center On Z Axis
		V = (GLfloat((rand()%5))+2)/5;
		Angle = GLfloat(rand()%360);
		particle[loop].zg = .15;
		particle[loop].xi = sin(Angle) * V;
		particle[loop].yi = cos(Angle) * V;
		particle[loop].zi = ((rand()%10)-5)/5;
	}
	return true;
}

bool CTerrain3DTestView::DrawWireframe(GLvoid)
{
	int i;    
	int i2;    
	int t, t2;
	glDisable(GL_TEXTURE_2D);
	glColor4f(0.0f,0.0f,0.0f,1.0f);
	for (t = xrange1; t < xrange2; t+=quality)
	{
		for (t2 = zrange1; t2 < zrange2; t2+=quality)
  		{
			i = t;
			i2 = t2;
            
			while (i < 0) i += MAX;             
			while (i > MAX) i -= MAX;            
			while (i2 < 0) i2 += MAX;             
			while (i2 > MAX) i2 -= MAX;
			int coord=t-MAX;
			int coord2=t2-MAX;

			glBegin(GL_LINE_LOOP);
			glVertex3f(coord,field[i][i2].y,coord2);        
			glVertex3f(coord+quality,field[i+quality][i2].y,coord2);
			glVertex3f(coord+quality,field[i+quality][i2+quality].y,coord2+quality);
			glVertex3f(coord,field[i][i2+quality].y,coord2+quality);
			glVertex3f(coord+quality,field[i+quality][i2].y,coord2);
			glEnd();
		}
	}
	glEnable(GL_TEXTURE_2D);
	  
	Changesight();
	//glTranslatef(0,-.5f,-10);    
	glRotatef(yaw,0,1,0);
	glRotatef(zprot*15,0,0,1);
	glRotatef(pitch,1,0,0);

	glEnable(GL_LIGHTING);
	glCallList(MODEL);		// 绘制飞机模型
	glDisable(GL_LIGHTING);

	return true;
}

bool CTerrain3DTestView::DrawTexture(GLvoid)
{
	DrawTerrain();		// 绘制地形
	DrawSky();			// 绘制天空
	if(water)
	{ 
		DrawWater();	// 绘制水
	}         
   
	DrawPlane();		// 绘制飞机及其尾焰
	DrawSun();			// 绘制太阳
	return true;
}

bool CTerrain3DTestView::DrawWater(GLvoid)
{
	glEnable(GL_BLEND);
	Changesight();
	glTranslatef(0,0,-10);
	glRotatef(sceneroty,0,1,0);
	glTranslatef(xtrans,ytrans-3.5-ABS(Speed)/5,ztrans);

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glColor4f(1,1,1,.35f);
	glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(xtexa2,ytexa2); glVertex3f(xrange2-MAX,-1,zrange2-MAX);
		glTexCoord2f(xtexa2,ytexa);  glVertex3f(xrange2-MAX,-1,zrange1-MAX); 
		glTexCoord2f(xtexa,ytexa2);  glVertex3f(xrange1-MAX,-1,zrange2-MAX); 
		glTexCoord2f(xtexa,ytexa);   glVertex3f(xrange1-MAX,-1,zrange1-MAX); 
	glEnd();

	glDisable(GL_BLEND);
	return true;
}

bool CTerrain3DTestView::DrawSun(GLvoid)
{
	float sun_flare_size;
	sun_flare_size = 5000;
	glColor4f(1,.5f,0,.5f);
	glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
		glTexCoord2f(1,1); glVertex3f(MAX/2+sun_flare_size,sun_height+sun_flare_size,sun_zdistance); // Top Right
		glTexCoord2f(0,1); glVertex3f(MAX/2-sun_flare_size,sun_height+sun_flare_size,sun_zdistance); // Top Left
		glTexCoord2f(1,0); glVertex3f(MAX/2+sun_flare_size,sun_height-sun_flare_size,sun_zdistance); // Bottom Right
		glTexCoord2f(0,0); glVertex3f(MAX/2-sun_flare_size,sun_height-sun_flare_size,sun_zdistance); // Bottom Left
	glEnd();										// Done Building Triangle Strip
	
	sun_flare_size = 500;
	glColor4f(1,.5f,0,1);
	glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
		glTexCoord2f(1,1); glVertex3f(MAX/2+sun_flare_size,sun_height+sun_flare_size,sun_zdistance); // Top Right
		glTexCoord2f(0,1); glVertex3f(MAX/2-sun_flare_size,sun_height+sun_flare_size,sun_zdistance); // Top Left
		glTexCoord2f(1,0); glVertex3f(MAX/2+sun_flare_size,sun_height-sun_flare_size,sun_zdistance); // Bottom Right
		glTexCoord2f(0,0); glVertex3f(MAX/2-sun_flare_size,sun_height-sun_flare_size,sun_zdistance); // Bottom Left
	glEnd();										// Done Building Triangle Strip
	return true;

}

bool CTerrain3DTestView::DrawPlane(GLvoid)
{
	glColor4f(1,1,1,1);
	Changesight();
	//glTranslatef(0,-.5f,-10);
     
	glRotatef(yaw,0,1,0);
	glRotatef(zprot*15,0,0,1);
	glRotatef(pitch,1,0,0);

	glEnable(GL_LIGHTING);
	glCallList(MODEL);		// 绘制飞机模型
	glDisable(GL_LIGHTING);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBindTexture(GL_TEXTURE_2D,texture[5]);

	GLfloat exhaust_r, exhaust_g, exhaust_b;
	if (Afterburner)
	{
		exhaust_r = 1;
		exhaust_g = .5f;
		exhaust_b = 0;
	}
	else
	{
		exhaust_r = .5f;
		exhaust_g = .5f;
		exhaust_b = 1;
	}
	
	glowp += .5f-glow;    
	glow += glowp*(ABS(Throttle)/500);
	if (glow > 1) glow = 1;
	else if (glow < .25f) glow = .25f;
	glColor4f(exhaust_r,exhaust_g,exhaust_b,glow);
	float glowsize = 1;
	for (float glowpos = 3; glowpos <= 3.25f; glowpos+=.25f)
	{
		glowsize -= .175f;
		glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
			glTexCoord2f(1,1); glVertex3f(.52+glowsize,-.8f+glowsize,glowpos); // Top Right
			glTexCoord2f(0,1); glVertex3f(.52-glowsize,-.8f+glowsize,glowpos); // Top Left
			glTexCoord2f(1,0); glVertex3f(.52+glowsize,-.8f-glowsize,glowpos); // Bottom Right
			glTexCoord2f(0,0); glVertex3f(.52-glowsize,-.8f-glowsize,glowpos); // Bottom Left
		glEnd();										// Done Building Triangle Strip
		glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
			glTexCoord2f(1,1); glVertex3f(-.52+glowsize,-.8f+glowsize,glowpos); // Top Right
			glTexCoord2f(0,1); glVertex3f(-.52-glowsize,-.8f+glowsize,glowpos); // Top Left
			glTexCoord2f(1,0); glVertex3f(-.52+glowsize,-.8f-glowsize,glowpos); // Bottom Right
			glTexCoord2f(0,0); glVertex3f(-.52-glowsize,-.8f-glowsize,glowpos); // Bottom Left
		glEnd();										// Done Building Triangle Strip
	} 
	
	for (loop=0;loop<MAX_PARTICLES;loop++)					// Loop Through All The Particles
	{       	
		GLfloat x=particle[loop].x;						// Grab Our Particle X Position
		GLfloat y=particle[loop].y;						// Grab Our Particle Y Position
		GLfloat z=particle[loop].z;					// Particle Z Pos + Zoom           
		glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life/2);		  	                  
    
		glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
			glTexCoord2f(1,1); glVertex3f(x+0.1f,y+0.1f,z); // Top Right
			glTexCoord2f(0,1); glVertex3f(x-0.1f,y+0.1f,z); // Top Left
			glTexCoord2f(1,0); glVertex3f(x+0.1f,y-0.1f,z); // Bottom Right
			glTexCoord2f(0,0); glVertex3f(x-0.1f,y-0.1f,z); // Bottom Left
		glEnd();										// Done Building Triangle Strip
            
		particle[loop].x+=particle[loop].xi/250;// Move On The X Axis By X Speed
		particle[loop].y+=particle[loop].yi/250;// Move On The Y Axis By Y Speed
		particle[loop].z+=particle[loop].zi/250;// Move On The Z Axis By Z Speed
		particle[loop].xi*=.975f;
		particle[loop].yi*=.975f;
		particle[loop].zi*=.975f;
		particle[loop].zi+=particle[loop].zg;			// Take Pull On Z Axis Into Account
		particle[loop].life-=particle[loop].fade*3;		// Reduce Particles Life By 'Fade'
		if (particle[loop].life < .5f) 
			particle[loop].life*=.975;

		if (particle[loop].life<0.05f)					// If Particle Is Burned Out
		{ 			    
			particle[loop].r=exhaust_r;
			particle[loop].g=exhaust_g;
			particle[loop].b=exhaust_b;
			
			particle[loop].life=1.0f;					// Give It New Life
			particle[loop].fade=GLfloat(rand()%100)/2500 + 0.02f;	// Random Fade Value
			if (loop < MAX_PARTICLES/2) 
				particle[loop].x= .52f;						
			else  
				particle[loop].x= -.52f;						
			particle[loop].y= -.8f;						
			particle[loop].z= 3.f;						
			V = (GLfloat((rand()%5))+2)/5;
			Angle = GLfloat(rand()%360);
              
			particle[loop].xi = sin(Angle) * V;
			particle[loop].yi = cos(Angle) * V;
			particle[loop].zi = ((rand()%10)-5)/5 + Throttle*4;
		}
	} 
	glDisable(GL_FOG);
	Changesight();
	glRotatef(sceneroty,0,1,0);
	return true;
}

bool CTerrain3DTestView::DrawTerrain(GLvoid)
{
	int i;    
	int i2;  
	int t, t2;	
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glColor4f(1,1,1,1);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (t = xrange1; t < xrange2; t+=quality)
	{        
		for (t2 = zrange1; t2 < zrange2; t2+=quality)
		{                                     
			i = t;
			i2 = t2;
            
			while (i < 0) i += MAX;             
			while (i > MAX) i -= MAX;            
			while (i2 < 0) i2 += MAX;             
			while (i2 > MAX) i2 -= MAX;

   			xtexa = (GLfloat(i)/MAX)*57;
			xtexa2 = (GLfloat(i+quality)/MAX)*57;    
			ytexa = (GLfloat(i2)/MAX)*57;
			ytexa2 = (GLfloat(i2+quality)/MAX)*57;       
			int coord=t-MAX;
			int coord2=t2-MAX;
      
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(xtexa2,ytexa2);  glVertex3f(coord+quality,field[i+quality][i2+quality].y,  coord2+quality);
			glTexCoord2f(xtexa2,ytexa);   glVertex3f(coord+quality,field[i+quality][i2].y,coord2); 
			glTexCoord2f(xtexa,ytexa2);   glVertex3f(coord,field[i][i2+quality].y,coord2+quality); 
			glTexCoord2f(xtexa,ytexa);   glVertex3f(coord,field[i][i2].y,coord2); 
			glEnd();       
		}   
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR, GL_ZERO);
	// 第二次绘制地形(多重纹理)
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glColor4f(1,1,1,.5f);
	for (t = xrange1; t < xrange2; t+=quality)
	{   
		for (t2 = zrange1; t2 < zrange2; t2+=quality)
		{               
			i = t;
			i2 = t2;
            
			while (i < 0) i += MAX;             
			while (i > MAX) i -= MAX;            
			while (i2 < 0) i2 += MAX;             
			while (i2 > MAX) i2 -= MAX;

			xtexa = (GLfloat(i)/MAX)*1;
			xtexa2 = (GLfloat(i+quality)/MAX)*1;
			ytexa = (GLfloat(i2)/MAX)*1;
			ytexa2 = (GLfloat(i2+quality)/MAX)*1;       
			int coord=t-MAX;
			int coord2=t2-MAX;
            
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(xtexa2,ytexa2);  glVertex3f(coord+quality,field[i+quality][i2+quality].y,  coord2+quality);
			glTexCoord2f(xtexa2,ytexa);   glVertex3f(coord+quality,field[i+quality][i2].y,coord2); 
			glTexCoord2f(xtexa,ytexa2);   glVertex3f(coord,field[i][i2+quality].y,coord2+quality); 
			glTexCoord2f(xtexa,ytexa);   glVertex3f(coord,field[i][i2].y,coord2); 
			glEnd();            
		}
	}   
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_BLEND);
       
	glFrontFace(GL_CW);
	glDisable(GL_CULL_FACE);
	return true;
}

bool CTerrain3DTestView::DrawSky(GLvoid)
{
	glFogf(GL_FOG_START, MAX*2);					// 雾的开始深度
	glFogf(GL_FOG_END, MAX*15);						// 雾的结束深度
	glColor4f(1,1,1,1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTranslatef(-xtrans,-ytrans-MAX*48,-ztrans);
	glRotatef(90,1,0,1);
	gluSphere(quadratic,MAX*50,20,20);
	glFogf(GL_FOG_START, 10.0f);					// 雾的开始深度
	glFogf(GL_FOG_END, visual_distance);			// 雾的结束深度
	return true;
}

void CTerrain3DTestView::Caculate(GLvoid)
{
	zprot*=0.935f;
	heading += zprot/3;
	yaw += zprot/5;
	yaw*=.95f; 

	Throttlei += (_Throttle-Throttle)/10;
	Throttlei *= .9f;
	Throttle += Throttlei/10;
				
	GLfloat MAX_Speed = (sqrt(Throttle+1)) * 10; 
	Speedi += MAX_Speed-Speed;
	Speedi *= .9f;
	Speed += Speedi/1000;
	XP = -(GLfloat)sin(heading*piover180) * Speed;	
	YP = -(GLfloat)sin(pitch*piover180) * Speed;
	ZP = -(GLfloat)cos(heading*piover180) * Speed;
    GLfloat overallspeed = Hypot(Hypot(XP,YP),ZP) / (ABS(Speed)+1);  				
				
	YP *= overallspeed;
	XP *= overallspeed;
	ZP *= overallspeed;

	XPOS += XP/30;
	YPOS += YP/30;
	ZPOS += ZP/30;
}