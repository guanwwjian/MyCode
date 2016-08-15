#ifndef _DW_OPEN_GL_LIB
#define _DW_OPEN_GL_LIB

//#ifdef  __cplusplus
//extern "C" {
//#endif

#define DllExport   __declspec( dllexport )



#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
// Windows 头文件：
#include <windows.h>
//#include <afxwin.h>         // MFC 核心和标准组件
//#include <vector>

#include <math.h>

#include <gl/gl.h>
#include <gl/glu.h>
#include "gl/glaux.h"



// C 运行时头文件
//#include <stdlib.h>
//#include <stdio.h>


#pragma comment(lib, "opengl32.lib")							// 链接时使用OpenGL32.lib
#pragma comment(lib, "glu32.lib")								// 链接时使用GLu32.lib 
#pragma comment(lib, "glaux.lib")								// 链接时使用GLaux.lib
#pragma comment(lib, "PubOpenglLib.lib")


#ifdef __cplusplus
extern "C" {
#endif


// 消息定义
// 按钮被点击
#ifndef D3_WM_BUTTON_CLICK
#define D3_WM_BUTTON_CLICK (WM_USER + 5501)
#endif



// 参数改变
#ifndef D3_WM_PARAMS_CHANGE
#define D3_WM_PARAMS_CHANGE (WM_USER + 5503)
#endif

// 暂停/播放被按
#ifndef D3_WM_PAUSE_ACTION
#define D3_WM_PAUSE_ACTION (WM_USER + 5504)
#endif

// 重置模型的消息
#ifndef D3_WM_RESET_MODULE
#define D3_WM_RESET_MODULE (WM_USER + 5505)
#endif

// 重置模型的消息
#ifndef D3_WM_BGCOLOR_CHANGE
#define D3_WM_BGCOLOR_CHANGE (WM_USER + 5506)
#endif

// 画图区域被点击
#ifndef D3_WM_DRAW_AREA_CLICK
#define D3_WM_DRAW_AREA_CLICK (WM_USER + 5507)
#endif

// 画图区域被双击
#ifndef D3_WM_DRAW_AREA_DBCLICK
#define D3_WM_DRAW_AREA_DBCLICK (WM_USER + 5508)
#endif

// 画图区域按键
#ifndef D3_WM_DRAW_AREA_KEYUP
#define D3_WM_DRAW_AREA_KEYUP (WM_USER + 5509)
#endif

// 画图区域按键按下
#ifndef D3_WM_DRAW_AREA_KEYDOWN
#define D3_WM_DRAW_AREA_KEYDOWN (WM_USER + 5510)
#endif



#define X 0
#define Y 1
#define Z 2

/*
 *
 * 此结构是ZHETAO绘图框架与用户程序的标准接口
 *
 */
typedef struct ZTOpenGLConfig
{
	HWND hwnd;  // 缓图环境DC
	double rx; // X方向旋转
	double ry; // Y方向旋转
	double rz; // Z方向旋转

	double tx; // X方向移动
	double ty; // Y方向移动
	double tz; // Z方向移动

	int rm; // 转动模式 x,y,z,all
	int tm; // 移动模式 x,y,z,all

	int curModule; // 当前模型

	bool switchs[50]; // 开关变量的值

	int paramCount; // 参数个数

	
	float scale; // 放大缩小

	double reserved[10]; // 10组double型的保留信息
	long reservedlong[10]; // 10组long型保留言信息

	double *paramValueList; // 按顺序每一个参数当前的值
}ZTOpenGLConfig, *PZTOpenGLConfig;

/*
 * 参数表
 */
typedef struct ZTParamTable
{
	int index;
	char name[150];
	char unit[100];
	double defaultValue; // 默认值
	int type; // 参数类型, 0 - 文本输入，1-滑块输入， 2 - 下拉选择
	double minv; // 最大值
	double maxv; // 最小值
	int tics; // 在滑块中把minv到maxv之间的数等分多少份？，此参数影响参数改变的精度
	double curValue; // 当前参数值
	struct ZTParamTable *next;
}ZTParamTable, *PZTParamTable;

/*
 * 缓图环境设置
 *
 * double a = 45.0, double fNear = 0.01, double fFar = 10000.0
 *
 */
typedef struct ZTDrawConfig
{
	int loop;     // 主循环次数, 0表示允远调用用户编的绘图函数
	long interval; // 主循环间隔时间
	bool useDefaultDraw; // 是否使用默认的绘图函数

	float zdepth;       // Z方向默认深度,Z轴初始移动
	float xtrans;  //X轴初始移动
	float ytrans;  //Y轴初始移动
	float initRotx;  // X轴初始转动角度
	float initRoty;  // Y轴初始转动角度
	float initRotz;  // Z轴初始转动角度


	double angle; // 角度,默认是45度
	double fnear;  // 近裁点,默认为0.01
	double ffar;   // 远裁点,默认为10000


	char name[200]; // 名称
	char description[2048]; // 描述
	char author[100]; // 作者
	char url[255]; // 网址
	int subModuleCount; // 子模型个数
	char subModules[50][100]; // 最多可以添加50个子模型

	// 开关变量
	int switchCount; // 启用的开关数量
	char switchNames[50][100]; // 开关的名称
	bool switchDefaults[50]; // 开关的默认值

	float scale; // 放大缩小

	int viewType; // 视图类型，0 - gluPerspective, 1 - glOrtho

	bool allowRotate; // 是否充许转动,  默认true
	bool allowScale; // 是否充许放大缩小， 默认true
	bool allowTrans; // 是否充许移动, 默认true

	int leftRightType;  // 左右移动轴，默认X, 0 - X, 1 - Y, 2 - Z
	int topBottomType;  // 上下移动轴, 默认Y, 0 - X, 1 - Y, 2 - Z

	double reserved[10]; // 10组double型的保留信息
	long reservedlong[10]; // 10组long型保留言信息

}ZTDrawConfig, *PZTDrawConfig;


/*
 * 此结构定义模型的随带信息和路径。
 * 仅适用于本地运行时使用，在网络中可以独立上传相应的资源。
 */
typedef struct ExDrawConfig
{
	char appPath[255];         // 程序模块路径   ------ IN
	char modulePath[255];      // 模型物理路径   ------ IN
	char videoPath[255];       // 模型视频路径   ------ OUT
	char audioPath[255];       // 模型音频路径   ------ OUT
	char docPath[255];         // 模型相关文档路径 ---- OUT
}ExDrawConfig, *PExDrawConfig;
// 哲涛OPENGL库开始
// 结构
typedef struct VEC
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}VECTOR;

typedef struct P3D
{
	GLdouble x;
	GLdouble y;
	GLdouble z;
}P3D;

typedef struct ZTRGB
{
	float r;
	float g;
	float b;
}ZTRGB;

typedef struct D3P{
	GLdouble x;
	GLdouble y;
	GLdouble z;
}Point3D;
typedef struct C3P{
	int r;
	int g;
	int b;
}CCRGB;

typedef struct DIRECTION
{
	GLfloat alpha;
	GLfloat beta;
	GLfloat sita;
}DIRECTION;

// 索引double 数据
typedef struct IndexValue
{
	int index;
	int y;
	double cx;
	double cy;
	double cz;
	char text[128];
}INDEXVALUE;

// 箭头类型
typedef enum ARRAY_TYPE
{
	DW_ARRAY_SOLID,  // 实线
	DW_ARRAY_OPEN,   // 开放的线
	DW_ARRAY_FILL,   // 填充
	DW_ARRAY_UP,     // 上边
	DW_ARRAY_DOWN    // 下边   
}ARRAY_TYPE;

typedef struct FONTS// 保存中文轮廓字体
{
	DWORD val;// 保存显示表的值(用来比较)
	GLuint listName;// 保存显示表的名称
	GLfloat zex;  // Z负方向的缩放
	GLYPHMETRICSFLOAT gmf;// 保存字体的详细信息
	FONTS *next;// 下一个轮廓字体的指针
}FONTS;

// PI
#define PI 3.1415926535897932354626
// 角度转成弧度
#define A2R(x) ((x) * 0.017453292519943295769236907684886)
// 弧度转成角度
#define R2A(x) ((x) * 57.295779513082320876798154814105)
// 平角
#define PAN_ANGLE 180.0
// 直角
#define DIR_ANGLE 90.0
// 数学中的常量
#define MM_E        2.71828182845904523536
#define MM_LOG2E    1.44269504088896340736
#define MM_LOG10E   0.434294481903251827651
#define MM_LN2      0.693147180559945309417
#define MM_LN10     2.30258509299404568402
#define MM_PI       3.14159265358979323846
#define MM_PI_2     1.57079632679489661923
#define MM_PI_4     0.785398163397448309616
#define MM_1_PI     0.318309886183790671538
#define MM_2_PI     0.636619772367581343076
#define MM_2_SQRTPI 1.12837916709551257390
#define MM_SQRT2    1.41421356237309504880
#define MM_SQRT1_2  0.707106781186547524401

extern "C"
{
	// 数学函数
	double DIS(P3D a, P3D b);
			// 转换
	//P3D toP(float x, float y, float z);
	//DIRECTION toD(float alpha, float beta, float sita);
	ZTRGB toC(int r, int g, int b);
	//ZTRGB toCF(float r, float g, float b);

	P3D toP(double x, double y, double z);
	DIRECTION toD(double alpha, double beta, double sita);
	ZTRGB toCF(double r, double g, double b);
	// 通用函数
	double toCH(double v, double a, double b, double c = 0, double d = 1.0);
}

namespace DW
{
	class DllExport OpenGL{
	public:
		typedef enum GLFACE{
			FRONT = GL_FRONT,
			BACK = GL_BACK,
			FRONT_AND_BACK = GL_FRONT_AND_BACK
		};
		// ambient float *diffuse = 0, float *specular = 0, float *emission = 0, float shiness = 0
		typedef enum COLOR_TYPE{
			AMBIENT = GL_AMBIENT,
			DIFFUSE = GL_DIFFUSE,
			SPECULAR = GL_SPECULAR,
			EMISSION = GL_EMISSION,
			SHININESS = GL_SHININESS
		};
		static HDC hdc; // 当前设备上下文件
		static HGLRC hRc; // 当前Opengl上下文件
	public:
		static PZTParamTable GetParam(int i); // 返回参数的值
		static void SetParamMinMax(int i, double m_min, double m_max); // 设置参数的最大值和最小值
		static void SetPauseOnStart(PZTDrawConfig config, bool bPause = false);  // 设定模型在启动时是否暂停，仅可以在初始函数中调用
		static bool IsAllowIncrease(ZTOpenGLConfig* config); // 判断目前是否充许进行增量
	private:
		static FONTS *begin;
		static FONTS *end;// 指向第一个与最后一个轮廓字体的指针
		static FONTS *AddFont(DWORD dwChar, float zex);

		static PZTParamTable CurrentParamTable; // 当前的参数表
		static int CurrentParamCount;
	public:
		// 场景信息保存
		// 图图宽
		static float m_ScreenWidth;
		// 视图高
		static float m_ScreenHeight;

		static float m_fOrigin[3]; // =   {0.0f, 2.0f, 15.0f};
		//m_fOrigin[1] =   2.0f;
		//m_fOrigin[2] =  15.0f;
		static float m_fRotation[3];

		// 模纵比
		static float m_fAspect;

		//m_fRotation[0] = -75.0f;
		//m_fRotation[1] =   0.0f;
		//m_fRotation[2] = -15.0f;
		// 以下变量用于在Orth坐标系模式中使用，可以不用初始化
		static GLfloat			m_fLeft;
		static GLfloat			m_fRight;
		static GLfloat			m_fBottom;
		static GLfloat			m_fTop;

		static float m_fFovY; // = 45.0f;
		
		static float m_fNear; // =    1.0f;
		static float m_fFar; //  = 5000.0f;

		static double m_dModelViewMatrix[16];

		static int viewType; // 坐标系模式
		static float m_fScale;
	private:
		static void KillFonts(void); // 删除
	public:
		// 字符处理
		static void FontSelect(int size = 20, const char *fontName = "宋体", int fontType = GB2312_CHARSET, bool bold = false, bool itl = false, bool underline = false, bool deleteline = false);
		// 在XY处画字符串，注意此画字体不会转动，除于完全的2D效果，适用于2D绘图操作
		static void DrawFont2D(const char *str, double x = 0, double y = 0, ZTRGB c = toC(0, 0, 0));
		//
	public:
		// 设置子模型
		static void SetSubModule(PZTDrawConfig drawConfig, int index, const char *name);

		// 设置视井内容
		static void SetDrawSence(PZTDrawConfig drawConfig, double angle = 45.0, double fnear = 0.01, double ffar = 10000.0);

		// 设置初始转到和移动（先移动，再转动）
		static void SetDefaultRotAndTrans(PZTDrawConfig drawConfig, float tx = 0, float ty = 0, float tz = -30, float rx = 0, float ry = -45.0, float rz = 0);

		// 设置坐标系显示类型
		static void SetViewType(PZTDrawConfig drawConfig, int viewType);

		// 命名开关变量，不使用
		static void AddSwitchName(PZTDrawConfig drawConfig, int index, const char *name, bool defStatus = false);

		// 判断第index个开关是否为真，index >= 0 && index < 50
		static bool IsTrue(ZTOpenGLConfig *config, int index);

		// 设置模型基本信息
		static void ConfigModule(PZTDrawConfig drawConfig, int interval = 50, int zdepth = -30, int subModuleCounter = 1, const char *mname = 0, const char *author = 0, const char* url = 0, const char *mdesc = 0);
		
		// 保存画图状态信息
		static void SaveDraw(ZTOpenGLConfig *config);

		// 设置变换, allowR - 是否充许转动，allowT - 是否充许移动， allowS - 是否充许放大/缩小
		static void ConfigAllow(PZTDrawConfig drawConfig, bool allowR = true, bool allowT = true, bool allowS = true);
	public:
		// GL list操作
		static GLuint CreateDrawList(int range);
		static void BeginDrawList(GLuint gllist);
		static void EndDrawList();
		static void DeleteList(GLuint gllist, int range);
		static void DrawList(GLuint gllist, int range = 0);
		static void DrawLists(int n, GLenum type, GLvoid* lists);
	public:
		// 结构操作
		static void P(P3D &p, float x, float y, float z);
		static void C(ZTRGB &c, float r, float g, float b);
		static void D(DIRECTION &d, float al, float bt, float st);
		static P3D MID(P3D a, P3D b); // 两点的中点
	public: // 基本操作
		// 画三角形，每个顶可指定颜色
		static void DrawTri(P3D p1, P3D p2, P3D p3, ZTRGB c1, ZTRGB c2, ZTRGB c3, bool fill = true);
		// 使用纹理画一个三角形，纹理图的左下对角三角形部分作为纹理，此方法将关闭纹理，所以在一个开启纹理的过程调用后要重新打开纹理
		static void DrawTri(P3D p1, P3D p2, P3D p3, int texIndex = 0);
		// 画四边形
		static void DrawQuad(P3D p1, P3D p2, P3D p3, P3D p4, ZTRGB c1, ZTRGB c2, ZTRGB c3, ZTRGB c4, bool fill = true, int alpha = 100);
		// 画四边形
		static void DrawQuad(P3D p1, P3D p2, P3D p3, P3D p4, ZTRGB c1, bool fill = true, int alpha = 100);
		// 画带有纹理的四边形,此方法将关闭纹理，所以在一个开启纹理的过程调用后要重新打开纹理
		static void DrawQuad(P3D p1, P3D p2, P3D p3, P3D p4, ZTRGB c1, int texIndex);
		// 画N边形
		static void DrawNBlock(P3D *p, int pCount, ZTRGB *c, bool fill = true, int alpha = 100);
		// 画圆，等
		static void DrawEllipse(P3D pos, float radius, ZTRGB c, float start = 0.0f, float end = 360.0f, float step = 1.0f, bool closed = false, bool slice = false, DIRECTION d = toD(0,0,0));
		// 画填充的圆
		static void DrawEllipseFill(P3D pos, float radius, ZTRGB c, float start = 0.0f, float end = 360.0f, float step = 1.0f, DIRECTION d = toD(0,0,0));
		// 设置透明度颜色
		static void SetColor(ZTRGB c, int alpha = 100);
		// 保存当前矩阵状态
		static void SaveState();
		// 使用最后一次矩阵状态
		static void UseLastState();
		// 使用透明
		static void EnableBlend();
		// 使用透明颜色
		static void EnableBlendAlpha(ZTRGB c = toC(255,255,255), int alpha = 50);
		// 使用透明颜色r,g,b(0-255)
		static void EnableBlendAlphai(int r = 255, int g = 255, int b = 255, int alpha = 50);
		// 使用GL——ONE透明
		static void EnableBlendGLONE();
		// 关闭透明
		static void CloseBlend();
		// 开启深度测试
		static void EnableDepth();
		// 关闭深度测试
		static void CloseDepth();

		static void Color(ZTRGB &color, int r, int g, int b);
		static void Color(ZTRGB &color, float r, float g, float b);
		static void Point(P3D &p, float x, float y, float z);
		static void Direct(DIRECTION &p, float a, float b, float s);
		static void Vector(VECTOR &p, float a, float b, float c);
		// 初始化交互式参数
		static void Param(PZTParamTable param, int index, const char *name, double curValue, double minValue, double maxValue, int ticks, const char *unit = NULL, int type = 0);
		// 获取第index个参数
		static double pv(ZTOpenGLConfig *config, int index = 0);
		// 开始画图
		static void BeginDraw(ZTOpenGLConfig *config);

		// 观察点
		static void LookAt(double eyex, double eyey, double eyez, double cx, double cy, double cz, double upx = 0, double upy = 1, double upz = 0);

		// 坐标变换，vE[a,b], 返回v均匀映射到[c,d]中的值
		static double CH(double v, double a, double b, double c, double d);

		// 空间点a,b之间的距离
		static double DL(P3D a, P3D b);
	public:
		enum FILTER
		{
			CLAMP = GL_CLAMP,
			REPEAT = GL_REPEAT,

			NEAREST = GL_NEAREST,
			LINEAR = GL_LINEAR,
			NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
			NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,
			LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
			LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR 
		};
		// 纹理处理API
		// 打开纹理
		static void OpenTexture2D();
		// 关闭纹理
		static void CloseTexture2D();
		
		// 设置纹理FILTER，以下函数均为gl原始函数
		static void Texture2DFilter(int wraps = CLAMP, int wrapt = CLAMP, int mag = NEAREST, int min = NEAREST);

		static void Texture2DEnv(GLenum target,GLenum pname,const float* param);
		static void Texture2DEnv(GLenum target,GLenum pname,float param);
		static void Tex2DCoord(double s, double t);
		static void Tex2DCoord(P3D p);
		static void Tex2DGen(GLenum coord,GLenum pname,int param);
		static void Tex2DGen(GLenum coord,GLenum pname,float param);
		static void Tex2DGen(GLenum coord,GLenum pname,const float* param);

		static void TexImage2D(const GLvoid *pixels,
				GLsizei width, GLsizei height,GLint components = 3,GLint border = 0,
				GLenum format = GL_RGB,GLenum type = GL_UNSIGNED_BYTE, GLint level = 0);
		static void TexImage1D(const GLvoid *pixels,GLsizei width,GLint components = 3,
				GLint border = 0,GLenum format = GL_RGB,GLenum type = GL_UNSIGNED_BYTE,GLint level = 0);

		//=================
		// 控制纹理的S/T方向自动生成（主要是对不规则的形状）
		static void EnableOrDisableTextureST(bool s = false, bool t = false, GLint s_mode = GL_OBJECT_LINEAR, GLint t_mode = GL_OBJECT_LINEAR, GLfloat *s_coeff = 0, GLfloat *t_coeff = 0);
		static void EnableOrDisableTextureS(bool s = false, GLint s_mode = GL_OBJECT_LINEAR, GLfloat *s_coeff = 0);
		static void EnableOrDisableTextureT(bool t = false, GLint t_mode = GL_OBJECT_LINEAR, GLfloat *t_coeff = 0);

	private:
		// 纹理存储
		static GLuint texture[50]; // 最多50个纺理
	public:
		// 加截位图为纹理
		static AUX_RGBImageRec *LoadBMP(char *Filename);
		// 加载纹理到指定的存储空间，index 0 - 50, filename - 位图，一定要是位图
		static int LoadGLTextures(int index, char *Filename);

		static void LoadGLTexturesFromRES(int index, int RID); // 从资源ID中加载纹理

		static void LoadGLTexturesFromRES(HINSTANCE hinst, int index, int RID); // 从资源ID中加载纹理，指定模块实例句柄

		// 使用第index号纺理, 0 - 50，具体要根据您加载的纺理多少来定
		static void UseTexture(int index);
		// 打开2D纹理功能，并绑定index号纹理
		static void OpenAndUseTexture(int index);
		// 返回第index个纹理
		static GLuint GetTexture(int index);
	public:
		static GLUquadricObj *quobj;
		// 设置颜色
		static void DW_SetColor(ZTRGB c);
		// 开始进行Opengl绘图
		static void DW_GLSetting(int w, int h, double a = 45.0, double fNear = 0.01, double fFar = 10000.0, GLenum vm = GL_MODELVIEW);
		// 初始化GL
		static void DW_InitGL(void);
		// 初始化GL使用背京
		static void DW_InitGLWithBG(ZTRGB c);
		// 开始opengl
		static void DW_BeginGL(HDC hdc);
		// 结束OpenGL
		static void DW_EndGL(void);
		// 获取当前画图的上下文
		static HGLRC GetCurrentLRC(void);
		static HDC GetCurrentDC(void);
		// 画背景，必须在画图前进行调用
		static void DW_DrawBackground(ZTRGB c1 = toC(255, 0, 0), ZTRGB c2 = toC(0, 0, 0), ZTRGB c3 = toC(255,255, 0), ZTRGB c4 = toC(255, 0, 255));
		// 画背景，必须在画图前进行调用
		static void DW_DrawColorBackground(ZTRGB c1 = toC(0, 0, 0));
		// 开始变换
		static void DW_Translate(VECTOR v);
		// 交换GL内存与WINDOWS GUI图形界面，使画的图生效
		static void DW_GLValid(void);
		// 沿X，Y，Z方向移动x,y,z
		static void DW_Translatef(float x, float y, float z);
		// 旋转
		static void DW_Rotate(float angle);
		static void DW_RotateD(DIRECTION d);
		static void DW_RotateX(float angle);
		static void DW_RotateY(float angle);
		static void DW_RotateZ(float angle);
		// 设置起点
		static void DW_SetStart(P3D p, DIRECTION d);
		// 设置画图的宽度
		static void DW_SetDrawWidth(float width);
		// 设置画点宽度
		static void DW_SetPointSize(float width);
		// 光照开关
		static void DW_OpenLighting(void);
		// 关闭光照
		static void DW_CloseLighting(void);
		// 打开光照，并且开第index灯
		static void OpenLight(int index);
		// 关闭光照，并关闭index灯
		static void CloseLight(int index);
		// 打开颜色材质开关
		static void OpenColor();
		// 关闭颜色材质开关
		static void CloseColor();
		//static void ConfigColor();
		// 光源开关(打开index灯，注意不开启光照功能)
		static void DW_OpenLight(int index);
		// 光源开关，关闭index灯，注意不关闭光照功能
		static void DW_CloseLight(int index);
		// 光源设置
		static void DW_SetupLight(int index, float *position = 0, float *ambient = 0, float *diffuse = 0, float *specular = 0);
		static void DW_SetupLight(int index, P3D *position = 0, ZTRGB *ambient = 0, ZTRGB *diffuse = 0, ZTRGB *specular = 0);

		static void ConfigColor(GLFACE face, COLOR_TYPE type);

		static void ClearColor(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);

		static void DW_SetupLightEx(int index, float *spotDirection = 0 /*SPOT_DIRECTION*/, float *spotExponent = 0/*SPOT_EXPONENT*/, float *spotCutoff = 0/*SPOT_CUTOFF*/, float *constantAttenuation = 0/*CONSTANT_ATTENUATION*/, float *linerAttenuation = 0/*LINER_ATTENUATION*/, float *quadraticAttenuation = 0/*QUADRATIC_ATTENUATION*/);
		// 构建材料
		static void DW_SetupMat(int face, float *ambient = 0, float *diffuse = 0, float *specular = 0, float *emission = 0, float shiness = 0);

		static void DW_SetupMat(int face, ZTRGB *ambient = 0, ZTRGB *diffuse = 0, ZTRGB *specular = 0, ZTRGB *emission = 0, float shiness = 0.0f);

		static void DW_SetupMatEx(int face, float *ambientAndDiffuse = 0/*AMBIENT_AND_DIFFUSE*/, float *shiness = 0/*GL_SHINESS*/, float *colorIndexes = 0/*GL_COLOR_INDEXES*/);
		// 重置
		static void DW_Reset(void);
		// 开始画线
		static void DW_BeginLineStrip(void);
		static void DW_BeginLines(void);
		static void DW_BeginLineLoop(void);
		static void DW_LineTo(P3D p);
		static void DW_LineToC(P3D p, ZTRGB c);
		static void DW_EndDraw(void);
		// 画图工具
		static void DW_DrawLine(P3D p1, P3D p2, ZTRGB color); // 画线
		static void DW_DrawLine(P3D p1, P3D p2); // 画线
		static void DW_DrawLineC(P3D p1, P3D p2, ZTRGB c1, ZTRGB c2);
		static void DW_DrawLines(P3D *p, int pCount, ZTRGB color);
		static void DW_DrawLines(P3D *p, int pCount);
		static void DW_DrawLinesC(P3D *p, int pCount, ZTRGB *color);
		static void DW_DrawTraiangle(P3D a, P3D b, P3D c, ZTRGB cc, bool fill); //GL_TRIANGLES
		static void DW_DrawTraiangleTex(P3D a, P3D b, P3D c, ZTRGB cc, int texIndex); //GL_TRIANGLES
		static void DW_DrawArrow(P3D s, P3D e, ZTRGB c, float al, float d = 10, ARRAY_TYPE fill = DW_ARRAY_FILL); // 画箭头， al 箭头长度，d - 角度

		static void DW_DrawArrowEx(P3D s, P3D e, float radius = 0.1, float al = 1, float d = 15); // 画箭头， al 箭头长度，d - 角度, radius为半径

		static void DW_DrawPoints(P3D *p, int pCount, float size = 1.0f, ZTRGB c = toC(255,0,0));
		static void DW_DrawPoint(P3D p, float size = 1.0f, ZTRGB c = toC(255,0,0));

		static int sign(double v);


		static void DW_DrawArrowDouble(P3D s, P3D e, ZTRGB c, float al, float d = 10, ARRAY_TYPE fill = DW_ARRAY_FILL); // 两端画箭头
		static void DW_DrawCurve(P3D *p, int pCount, ZTRGB color, int level = 5);
		static void DW_DrawCurveC(P3D *p, int pCount, ZTRGB *color, int level = 5);
		static void DW_DrawBall(P3D p, double r, ZTRGB c, DIRECTION v = toD(0, 0, 0)); // v 为向不同的方向转动的角度
		// 画圆，颜色由外部控制
		static void DW_DrawBall(P3D p, double r, DIRECTION v = toD(0, 0, 0));

		// 创建字体
		static void DW_CreateFont(char *fontName = "宋体", bool bold = true, bool underline = false, bool its = false, bool delline = false, int width = 0, int height = 0, int angle = 0);

		// 画字符串，zs: 表示字符的厚度，默认为平面字符，fcx,fcy,fcz为X，Y，Z方向的缩放, start表示起始位置
		static void DW_DrawString(char *text, P3D start, ZTRGB c, float zs = 0.0f, float fcx = 1.0f, float fcy = 1.0f, float fcz = 1.0f); // 画字符串
		static void DW_DrawString(char *text, P3D start, float zs = 0.0f, float fcx = 1.0f, float fcy = 1.0f, float fcz = 1.0f); // 画字符串
		// 画具有方向选择的字符
		static void DW_DrawString(char *text, P3D start, ZTRGB c, DIRECTION v, float zs = 0.0f, float fcx = 1.0f, float fcy = 1.0f, float fcz = 1.0f); // 画字符串
		// 在最底层画字符串(平面字符)
		static void DW_DrawString(char *text, ZTRGB c = toC(0, 0, 0), double x = 0.0, double y = 0.0, float zs = 0.0f, float fcx = 0.1f, float fcy = 0.1f, float fcz = 0.1f); // 画字符串

		static void GLDrawSurface(P3D *p,ZTRGB *c,int row,int col,bool autoz, double radius = 2, int slice = 1, int stack = 1);
		static void GLDrawSurface(P3D *p,ZTRGB *c,int row,int col,bool autoz,int ii,int ji);
		// 画Nurbs曲线
		static void GLDrawNursSurface(P3D *p, int sstride, int tstride, bool fill = true, float *sknot = NULL, int sknot_count = 0, 
			float *tknot = 0, int tknot_count = 0, int sOrder = 4, int tOrder = 4, GLenum type = GL_MAP2_VERTEX_3, float glutolerange = 50.0f);
		// 画Nurbs曲线
		static void GLDrawNursSurface(const float *p, int sstride, int tstride, bool fill = true, float *sknot = NULL, int sknot_count = 0, 
			float *tknot = 0, int tknot_count = 0, int sOrder = 4, int tOrder = 4, GLenum type = GL_MAP2_VERTEX_3, float glutolerange = 50.0f);

		// 恢复材质为默认值
		static void RestorMaterial(void);

		
		// 画茶杯,size - 大小，pos中心坐标，d方向,c颜色
		static void DW_DrawTeapot(double size, P3D pos, ZTRGB c, DIRECTION d = toD(0,0,0));
		// 画茶杯，不设置颜色, size - 大小，pos中心坐标，d方向
		static void DW_DrawTeapot(double size, P3D pos, DIRECTION d = toD(0,0,0));

		// 画弹簧，size粗细，rd-半径,nc-材料半径，dis-两圈之间的距离,c-颜色，注意向到环境光的影响, start - 第一圈弹簧的圆心， d - 画弹簧方向, step - 360的等分间隔
		static void DW_DrawSpring(double size, double rd, int nc, double dis, ZTRGB c = toC(255,255,255), P3D start = toP(0,0,0), DIRECTION d = toD(0,0,0), double step = 5);

		// 画弹簧，size粗细，rd-半径,nc-材料半径，dis-两圈之间的距离, start - 第一圈弹簧的圆心， d - 画弹簧方向, step - 360的等分间隔
		static void DW_DrawSpringNoColor(double size, double rd, int nc, double dis, P3D start = toP(0,0,0), DIRECTION d = toD(0,0,0), double step = 5);
		// 画弹簧，size粗细，rd-半径,nc-材料半径，dis-两圈之间的距离, start - 第一圈弹簧的圆心， d - 画弹簧方向, step - 360的等分间隔, alen - 两端的长度(has=true时才画)
		static void DW_DrawSpringEx(double size, double rd, int nc, double dis, P3D start = toP(0,0,0), DIRECTION d = toD(0,0,0), double step = 5, bool hasa = false, double alen = 0.2);

		// 画圆柱/锥, bradius底部圆半径，tradius顶部圆半径，为0表示圆锥，height:高度,bcp 底部圆心位置, d 方向, slice/stack经/纬细分
		static void DW_DrawCylinder(double bradius, double tradius, double height, bool fill = false, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), int slice = 32, int stack = 32);

		static void DW_DrawAuxCylinder(double radius, double height, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);
		static void DW_DrawAuxCone(double radius, double height, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// 画光盘
		static void DW_DrawDisk(double inradius, double outradius, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), int slice = 32, int loops = 32);

		// 画球
		static void DW_DrawSphere(double radius, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// 画环
		static void DW_DrawTorus(GLdouble innerRadius,GLdouble outerRadius, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// 画立方体
		static void DW_DrawCube(double width, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);
		// 画长方体
		static void DW_DrawBox(double width, double height, double depth, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// 画坐标轴
		static void DW_DrawCoor(double length, bool is3d = false, double radius = 0.2, P3D drawPos = toP(0,0,0), DIRECTION d = toD(0,0,0));

		
		// 画坐标轴
		static void DW_DrawCoorEx(double length, double linesize = 0.2, double radius = 0.3, float alen = 1, P3D drawPos = toP(0,0,0), DIRECTION d = toD(0,0,0));

		// 画齿轮
		static void DW_DrawGear(float inner_radius, float outter_radius, float width, int teeth, float tooth_depth);

		static void DW_DrawGear(P3D point, float inner_radius, float outer_radius, float width, int teeth, float tooth_depth, DIRECTION d = toD(0,0,0));

		//画表面
		static void DrawSurface(P3D *p, ZTRGB *c, int row,int col, bool fill = true);
		// 画表面，单色，需要使用OpenColor()打开颜色功能
		static void DrawSurface(P3D *p, int row, int col, ZTRGB c, bool fill = true);

		// 恢复光照为默认值
		static void RestLight(int index = 0);
		// 打开具有颜色的光源，默认为白色
		static void OpenColorLight(int index = 0, ZTRGB c = toC(255,255,255), P3D pos = toP(0,0,1));

		// 裁剪平面
		// 打开裁剪平面index
		static void OpenClip(int index = 0);
		// 关闭裁剪平面的index
		static void CloseClip(int index = 0);
		// 建立裁剪平面的方程，ax+by+cz+d=0
		static void SetupClip(int index, double a, double b, double c, double d = 0);

		// 坐标转换
		static void GetWorldCoord(int ix, int iy, float fz, P3D &p);
		static void GetWindowMousePos(HWND hwnd, P3D &p);
		static void Get3DMousePos(HWND hwnd, P3D &p);

		// 二次曲线画图使用纹理
		static void EnableQuadricTexture(GLUquadricObj *qobj = 0);
		// 不使用纹理
		static void DisableQuadricTexture(GLUquadricObj *qobj = 0);

	private:
		static void drawBez(P3D *p, int pCount, ZTRGB c, int level);
	public:
		// 新增2D绘图
		static void Draw2DAix(int flag = 0, const char* aixName = "X", double dstart = -15, double dend = 15, int ec = 15, 
			  double factStart = -15, double factEnd = 15, 
			  int numFormat = 0, ZTRGB lineColor = toC(0, 0, 0), ZTRGB tColor = toC(0, 0, 0), ZTRGB lblColor = toC(0, 0, 0), 
			  double offRuler = 0.07, double offY = 0.2, double offYText = 0.25);
		static void Draw2DXAix(const char* aixName = "X Aix", double dstart = -15, double dend = 15, int equalCount = 15, double dstartf = -15, double dendf = 15, int numFormat = 0, ZTRGB lineColor = toC(0, 0, 0), ZTRGB tColor = toC(0, 0, 0), ZTRGB lblColor = toC(0, 0, 0));
		static void Draw2DYAix(const char* aixName = "Y Aix", double dstart = -8, double dend = 8, int equalCount = 8, double dstartf = -8, double dendf = 8, int numFormat = 0, ZTRGB lineColor = toC(0, 0, 0), ZTRGB tColor = toC(0, 0, 0), ZTRGB lblColor = toC(0, 0, 0));
		// 画坐标网格
		static void Draw2DAixGrid(double x, double y, double cx, double cy, int xsplit = 10, int ysplit = 10, ZTRGB borderColor = toC(0, 0, 0), ZTRGB bgColor = toC(200, 200, 200), ZTRGB gridLineColor = toC(220, 220, 220));
	public:
		// 补充函数
		// 设置下一个顶点为x,y,z
		static void LineTo(double x = 0, double y = 0, double z = 0);
		// 设置RGB颜色
		static void SetColor(int r = 255, int g = 255, int b = 255);
		// 设置RGB颜色
		static void SetColor(int r, int g, int b, int alpha);
		// 设置线宽
		static void SetDrawWidth(GLfloat width = 1.0f);
		// 设置点宽
		static void SetPointSize(GLfloat size = 1.0f);
		// 自动设置法向向量, p1,p2,p3三面的平面
		static void SetNormal(P3D p1, P3D p2, P3D p3);
		// 建议在INIT中使用（整个场景使用）启动雾效果fogColor[ZTRGB]-雾颜色，fogDensity-雾浓度（值越大越浓）,fogStart/fogEnd(雾离屏幕远近), fogMode[GL_EXP, GL_EXP2, GL_LINEAR]-雾模式，hint-确定了雾的渲染方式[GL_NICEST,GL_FASTEST,GL_DONT_CARE]
		static void EnableFog(ZTRGB fogColor = toCF(0.5, 0.5, 0.5), float fogDensity = 0.02, float fogStart = -20, float fogEnd = -10.0, GLenum fogMode = GL_EXP, GLenum hint = GL_DONT_CARE);
		// 建议在INIT中使用（整个场景使用）启动雾效果fogColor[float*v，四元组, 0-1之间]-雾颜色，fogDensity-雾浓度（值越大越浓）,fogStart/fogEnd(雾离屏幕远近), fogMode[GL_EXP, GL_EXP2, GL_LINEAR]-雾模式，hint-确定了雾的渲染方式[GL_NICEST,GL_FASTEST,GL_DONT_CARE]
		static void EnableFogv(float *fogColor = 0, float fogDessity = 0.02, float fogStart = -20, float fogEnd = -10.0, GLenum fogMode = GL_DONT_CARE, GLenum hint = GL_DONT_CARE);
		// 关闭雾
		static void CloseFog();
		// 打开雾功能
		static void OpenFog();
		// 设置深度缓冲读写, GL_TRUE - 只读，GL_FALSE - 读写，此功能仅用在二次曲面本面的透明开启之后，在用完透明一定要关闭，否则整个场景的深度测试将出现问题
		static void SetDepthReadOnly(GLboolean action = GL_TRUE);
		// 画3D弹簧相关函数
		static double DISv(double *p1, double *p2); //两点间距
		// 根据两点坐标，画半径为r的圆柱(startPoint, endPoint为double型的四元组), qObj - 为二次曲线配置环境
		static void DrawCylinderByEndPoint(GLUquadricObj*qObj, double* startPoint, double* endPoint, double r);
		// 画弹簧的一圈 innerRadius - 粗细半径，midLineRadius - 中线半径, slices,rings - 分块大小, v - 螺线上升速度（由圈数和长度可以计算出来）
		static void DrawOnCircleSpringPiece(GLfloat innerRadius, GLfloat midLineRadius, GLint slices, GLint rings, float v);
		// 画圆环(有限元建模)innerRadius - 粗细半径，midRadius- 中线半径，ori - 自身圆心（相对于场景坐标）, d - 按X，Y，Z顺序转动的角度, slices, rings - 精度（分块）
		static void DrawTuros(GLfloat innerRadius, GLfloat midRadius, P3D ori = toP(0, 0, 0), DIRECTION d = toD(0, 0, 0), GLint slices = 50, GLint rings = 50);
		// circleCount - 圈数, len - 弹簧长度（注意：不包括两端的柄，相当于两端中心位置）, midLineRadius - 中线半径，innerRadius - 粗细半径，ori - 弹簧起点坐标（相对于场景坐标）, d - 弹簧按X，Y，Z轴顺序转的角度, drawstartpoint - 是否画起始端的柄，drawendpoint - 是否画未端柄，endlen - 柄长度
		static void DrawSpring3D(int circleCount, double len, double midLineRadius, double innerRadius, P3D ori = toP(0, 0, 0), DIRECTION d = toD(0, 0, 0), bool drawstartpoint = false, bool drawendpoint = false, double endlen = 0.8, int slices = 50, int rings = 50);

	public: // 2009-10-17补充函数
		// 画表面, 自动计算法向量，注意表面只能为X/Y表面，Z为深度
		static void DrawCommonFace(P3D *p, ZTRGB *c, int row,int col, bool fill = true);
		// 画表面，自动计算法向量，注意表面只能为X/Y表面，Z为深度
		static void DrawCommonFace(P3D *p, int row,int col, bool fill = true);
		// 归一化处理
		static void normalize(double *v); // 归一，一般用于内部调用
		// 自动设备法向量
		static void SetCommonNormal(P3D *p, int i, int j, int row, int col); // 一般用于内部调用
	public: // 2010-01-27新增函数
		// p - 一维点列表，其中p按row行*col列，顺序存储, row - 行数，col - 列数, fill - 是否填充, c - 如果指定则必须与p具有相同的大小
		static void DrawSurfaceExtends(P3D *p, int row, int col, bool fill = true, ZTRGB *c = 0);
		// 画回转曲面
		// 如果sita闭合 sita =0 - 360, 则option_sita=true; 
		// 如果为不闭合顶点 option_r=0, 闭合光滑顶点option_r=1, 闭合尖顶点option_r=2 
		static void DrawSurfaceCircle(P3D *p, int maxsita, int maxr, bool option_sita, int option_r);
	};
	
	// MFC Supports
	class DllExport UI{
	public:
		UI(void);
		~UI(void);
	public:
		static HWND m_hWndParam; // 参数表的HWND
		static HWND m_hWndDraw;
		static HWND m_hWndFrame;

		//std::vector<CWnd*> btns;
		//static void AddButton(int index, const char* labelText, int x, int y, int cx, int cy);
		//static void EnableButton(int index, bool flag);
	public:
		static void AddButton(int index, LPCTSTR labelText, int x, int y, int cx, int cy);
		static void EnableButton(int index, bool flag);
		static void SetButtonText(int index, LPCTSTR txt);
		static void ClearButtons(void);
	public:
		// 坐标UIAPI，可以用来添加坐标
		static void AddCoor(int index, LPCTSTR labelText, int y, P3D point = toP(0.0, 0.0, 0.0)); // 位置
		static P3D GetCoor(int index); // 获取坐标值
		static void SetCoor(int index, P3D p); // 设置坐标值
		static void SetCoor(int index, double x, double y, double z); // 设置坐标值
	};

	// Opengl画图帮助常量类
	class DllExport Util
	{
	private:
		static float ambient[4];
		static float diffuse[4];
		static float specular[4];
		static float emission[4];
		static float shinness[1];
		static int face;
		static void SetupMat();
	public:
		// 设备材质属性（以0-1.0间的值设置RGB）
		static void SetAmbient(float r, float g, float b, float w = 1.0f);
		static void SetDiffuse(float r, float g, float b, float w = 1.0f);
		static void SetSpecular(float r, float g, float b, float w = 1.0f);
		static void SetEmission(float r, float g, float b, float w = 1.0f);

		// 以RGB设置
		static void SetAmbient(int r, int g, int b, float w = 1.0f);
		static void SetDiffuse(int r, int g, int b, float w = 1.0f);
		static void SetSpecular(int r, int g, int b, float w = 1.0f);
		static void SetEmission(int r, int g, int b, float w = 1.0f);

		// 以ZTRGB结构设备
		static void SetAmbient(ZTRGB rgb, float w = 1.0f);
		static void SetDiffuse(ZTRGB rgb, float w = 1.0f);
		static void SetSpecular(ZTRGB rgb, float w = 1.0f);
		static void SetEmission(ZTRGB rgb, float w = 1.0f);

		//
		static void SetShinness(float v = 100.0f);
		static void SetFace(int f = 0x0404);
		// 设置百分比颜色, flag - 表示是ambient,diffuse,specular or emission, 0 - 4, rate - 设置为红色的百分之rate，表示按所设颜色的rate%来设置当前指定光质的颜色
		static void SetRedRate(float rate = 100.0f, int flag = 0);
		static void SetBlueRate(float rate = 100.0f, int flag = 0);
		static void SetGreenRate(float rate = 100.0f, int flag = 0);
		static void SetWhiteRate(float rate = 100.0f, int flag = 0);
		static void SetRGBRate(int r, int g, int b, float rate = 100.f, int flag = 0);
		//祖母绿，纯绿柱石
		static void SetEmerald();
		//银色
		static void SetSilver();
		//金
		static void SetGold();
		//铜
		static void SetCopper();
		//
		static void SetBrone();
		// 白色
		static void SetWhiteMetal();
		// 黑色
		static void SetBlackMetal();
		// 黄色
		static void SetYellowPaint();
		// 蓝色
		static void SetBlue();
		// 红色
		static void SetRed();
		// 绿色
		static void SetGreenPaint();
		// 重置为所有默认值
		static void Reset();
	public:
		// 常用颜色表
		// 红色255, 0, 0
		static ZTRGB RED;
		// 绿色0, 255, 0
		static ZTRGB GREEN;
		// 蓝色0, 0, 255
		static ZTRGB BLUE;
		// 灰色128, 128, 128
		static ZTRGB GRAY;
		// 亮灰色192, 192, 192
		static ZTRGB LIGHT_GRAY;
		// 深灰色64, 64, 64
		static ZTRGB DARK_GRAY;
		// 黑色0,0,0
		static ZTRGB BLACK;
		// 粉红255, 175, 175
		static ZTRGB PINK;
		// 橙色255, 200, 0
		static ZTRGB ORANGE;
		// 黄色255,255,0
		static ZTRGB YELLOW;
		// MAGENTA255, 0, 255
		static ZTRGB MAGENTA;
		// CYAN 0, 255, 255
		static ZTRGB CYAN;
		// LIGHT_BLUE 40,100,255
		static ZTRGB LIGHT_BLUE;
		// WHITE 255,255,255
		static ZTRGB WHITE;
		// LIGHT_MAGENTA 128,0,255
		static ZTRGB LIGHT_MAGENTA;

		// 常用坐标
		// 原点0,0,0
        static P3D ORI_POINT;
		// 常用材质定义
		// 无材质
		static GLfloat NO_MAT[4];
		// 70%灰度
		static GLfloat MAT_70[4];
		// 红色
		static GLfloat MAT_RED[4];
		// 绿色
		static GLfloat MAT_GREEN[4];
		// 蓝色
		static GLfloat MAT_BLUE[4];
		// 粉红
		static GLfloat MAT_PINK[4];
		// 橙色
		static GLfloat MAT_ORANGE[4];
		// MAGENTA255, 0, 255
		static GLfloat MAT_MAGENTA[4];
		//// CYAN 0, 255, 255
		static GLfloat MAT_CYAN[4];
		// // WHITE 255,255,255
		static GLfloat MAT_WHITE[4];
	};
	// 3DS-supports -
	class OBJ3DS
	{
	private:
	public:
		static OBJ3DS* GetInstance(void); // 获取加载3DS的实例
		void AddIDMap(char *strFile, int rid); // 添加资源到文件名和ID映射（用于从资源ID中加载3DS时，也从资源中加载纹理），主要是3DS中使用的位图必须进行映射，否则纹理将无法进行加载
		void Init3DS(void);  // 初始化3DS内存，所有函数必须在此函数调用后才可以调用
		void Destroy3DS(void); // 删除3DS内存，在模型结束后必须调用此函数，

		void Load3DSFromRes(HINSTANCE hinst, int rid, int index);   // 从资源中加载3DS（资源类型必须为OBJ3DS），把模型加载到index所表示的模型中
		void Load3DSFromFile(char *strFile, int index); // 从文件中加载3DS，把模型加载到index所表示的模型中

		void Draw3DSObject(int objindex, P3D p, DIRECTION d, float size = 0.2); //显示3ds模型
	};
}

// =======================End Of the Core Programe Util Libs================

#ifdef __cplusplus
}
#endif


/*
	导出的函数
*/
extern "C"
{
	/*实现此接口，用于作图*/
	_declspec(dllexport) void ZTDraw(ZTOpenGLConfig *config);
	/*初始化参数*/
	_declspec(dllexport) void ZTInitParams(PZTParamTable params, int *count, PZTDrawConfig sysConfig);
	/*初始化参数-扩展*/
	_declspec(dllexport) void ZTInitParamsEx(PZTParamTable params, int *count, PZTDrawConfig sysConfig, PExDrawConfig exconfig);

	// 配置应用程序环境的HWND
	_declspec(dllexport) void ConfigWindowsHandles(HWND mainFrameHandle, HWND drawViewHandle, HWND paramHandle)
	{
		DW::UI::m_hWndParam = paramHandle;
		DW::UI::m_hWndDraw = drawViewHandle;
		DW::UI::m_hWndFrame = mainFrameHandle;
	}
	//新增Window消息
	_declspec(dllexport) void RawWindowProc(int winId, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, int ctlId, LPARAM reserved1 = 0, LPARAM reserved2 = 0);
	// 模型关闭
	_declspec(dllexport) void RawDestroy(HWND hwnd);


	_declspec(dllexport) void beginGL(HWND hwnd)
	{
		HDC hdc = ::GetDC(hwnd);
		DW::OpenGL::DW_BeginGL(hdc); // 启动Open GL
		DW::OpenGL::DW_InitGL(); // 初始化OpenGL
		
		/*
		RECT rect;
		GetClientRect(hwnd, &rect);
		int sw = rect.right - rect.left;
		int sh = rect.bottom - rect.top;
		ZT::OpenGL::ZT_GLSetting(sw, sh); // 设置视图*/
	}
	_declspec(dllexport) void beginGLDC(HDC hdc)
	{
		DW::OpenGL::DW_BeginGL(hdc); // 启动Open GL
		DW::OpenGL::DW_InitGL(); // 初始化OpenGL
	}

	_declspec(dllexport) void endGL()
	{
		DW::OpenGL::DW_EndGL();
	}

	_declspec(dllexport) void setView(int w, int h, double angle = 45.0, double fnear = 0.01, double ffar = 10000.0)
	{
		DW::OpenGL::DW_GLSetting(w,h,angle,fnear,ffar,GL_MODELVIEW);
	}

	_declspec(dllexport) HGLRC GetHRC()
	{
		return DW::OpenGL::GetCurrentLRC();
	}


}

#endif // _ZT_OPEN_GL_LIB





