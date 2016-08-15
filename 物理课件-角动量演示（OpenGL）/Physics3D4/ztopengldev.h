#ifndef _DW_OPEN_GL_LIB
#define _DW_OPEN_GL_LIB

//#ifdef  __cplusplus
//extern "C" {
//#endif

#define DllExport   __declspec( dllexport )



#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ���
#include <windows.h>
//#include <afxwin.h>         // MFC ���ĺͱ�׼���
//#include <vector>

#include <math.h>

#include <gl/gl.h>
#include <gl/glu.h>
#include "gl/glaux.h"



// C ����ʱͷ�ļ�
//#include <stdlib.h>
//#include <stdio.h>


#pragma comment(lib, "opengl32.lib")							// ����ʱʹ��OpenGL32.lib
#pragma comment(lib, "glu32.lib")								// ����ʱʹ��GLu32.lib 
#pragma comment(lib, "glaux.lib")								// ����ʱʹ��GLaux.lib
#pragma comment(lib, "PubOpenglLib.lib")


#ifdef __cplusplus
extern "C" {
#endif


// ��Ϣ����
// ��ť�����
#ifndef D3_WM_BUTTON_CLICK
#define D3_WM_BUTTON_CLICK (WM_USER + 5501)
#endif



// �����ı�
#ifndef D3_WM_PARAMS_CHANGE
#define D3_WM_PARAMS_CHANGE (WM_USER + 5503)
#endif

// ��ͣ/���ű���
#ifndef D3_WM_PAUSE_ACTION
#define D3_WM_PAUSE_ACTION (WM_USER + 5504)
#endif

// ����ģ�͵���Ϣ
#ifndef D3_WM_RESET_MODULE
#define D3_WM_RESET_MODULE (WM_USER + 5505)
#endif

// ����ģ�͵���Ϣ
#ifndef D3_WM_BGCOLOR_CHANGE
#define D3_WM_BGCOLOR_CHANGE (WM_USER + 5506)
#endif

// ��ͼ���򱻵��
#ifndef D3_WM_DRAW_AREA_CLICK
#define D3_WM_DRAW_AREA_CLICK (WM_USER + 5507)
#endif

// ��ͼ����˫��
#ifndef D3_WM_DRAW_AREA_DBCLICK
#define D3_WM_DRAW_AREA_DBCLICK (WM_USER + 5508)
#endif

// ��ͼ���򰴼�
#ifndef D3_WM_DRAW_AREA_KEYUP
#define D3_WM_DRAW_AREA_KEYUP (WM_USER + 5509)
#endif

// ��ͼ���򰴼�����
#ifndef D3_WM_DRAW_AREA_KEYDOWN
#define D3_WM_DRAW_AREA_KEYDOWN (WM_USER + 5510)
#endif



#define X 0
#define Y 1
#define Z 2

/*
 *
 * �˽ṹ��ZHETAO��ͼ������û�����ı�׼�ӿ�
 *
 */
typedef struct ZTOpenGLConfig
{
	HWND hwnd;  // ��ͼ����DC
	double rx; // X������ת
	double ry; // Y������ת
	double rz; // Z������ת

	double tx; // X�����ƶ�
	double ty; // Y�����ƶ�
	double tz; // Z�����ƶ�

	int rm; // ת��ģʽ x,y,z,all
	int tm; // �ƶ�ģʽ x,y,z,all

	int curModule; // ��ǰģ��

	bool switchs[50]; // ���ر�����ֵ

	int paramCount; // ��������

	
	float scale; // �Ŵ���С

	double reserved[10]; // 10��double�͵ı�����Ϣ
	long reservedlong[10]; // 10��long�ͱ�������Ϣ

	double *paramValueList; // ��˳��ÿһ��������ǰ��ֵ
}ZTOpenGLConfig, *PZTOpenGLConfig;

/*
 * ������
 */
typedef struct ZTParamTable
{
	int index;
	char name[150];
	char unit[100];
	double defaultValue; // Ĭ��ֵ
	int type; // ��������, 0 - �ı����룬1-�������룬 2 - ����ѡ��
	double minv; // ���ֵ
	double maxv; // ��Сֵ
	int tics; // �ڻ����а�minv��maxv֮������ȷֶ��ٷݣ����˲���Ӱ������ı�ľ���
	double curValue; // ��ǰ����ֵ
	struct ZTParamTable *next;
}ZTParamTable, *PZTParamTable;

/*
 * ��ͼ��������
 *
 * double a = 45.0, double fNear = 0.01, double fFar = 10000.0
 *
 */
typedef struct ZTDrawConfig
{
	int loop;     // ��ѭ������, 0��ʾ��Զ�����û���Ļ�ͼ����
	long interval; // ��ѭ�����ʱ��
	bool useDefaultDraw; // �Ƿ�ʹ��Ĭ�ϵĻ�ͼ����

	float zdepth;       // Z����Ĭ�����,Z���ʼ�ƶ�
	float xtrans;  //X���ʼ�ƶ�
	float ytrans;  //Y���ʼ�ƶ�
	float initRotx;  // X���ʼת���Ƕ�
	float initRoty;  // Y���ʼת���Ƕ�
	float initRotz;  // Z���ʼת���Ƕ�


	double angle; // �Ƕ�,Ĭ����45��
	double fnear;  // ���õ�,Ĭ��Ϊ0.01
	double ffar;   // Զ�õ�,Ĭ��Ϊ10000


	char name[200]; // ����
	char description[2048]; // ����
	char author[100]; // ����
	char url[255]; // ��ַ
	int subModuleCount; // ��ģ�͸���
	char subModules[50][100]; // ���������50����ģ��

	// ���ر���
	int switchCount; // ���õĿ�������
	char switchNames[50][100]; // ���ص�����
	bool switchDefaults[50]; // ���ص�Ĭ��ֵ

	float scale; // �Ŵ���С

	int viewType; // ��ͼ���ͣ�0 - gluPerspective, 1 - glOrtho

	bool allowRotate; // �Ƿ����ת��,  Ĭ��true
	bool allowScale; // �Ƿ����Ŵ���С�� Ĭ��true
	bool allowTrans; // �Ƿ�����ƶ�, Ĭ��true

	int leftRightType;  // �����ƶ��ᣬĬ��X, 0 - X, 1 - Y, 2 - Z
	int topBottomType;  // �����ƶ���, Ĭ��Y, 0 - X, 1 - Y, 2 - Z

	double reserved[10]; // 10��double�͵ı�����Ϣ
	long reservedlong[10]; // 10��long�ͱ�������Ϣ

}ZTDrawConfig, *PZTDrawConfig;


/*
 * �˽ṹ����ģ�͵������Ϣ��·����
 * �������ڱ�������ʱʹ�ã��������п��Զ����ϴ���Ӧ����Դ��
 */
typedef struct ExDrawConfig
{
	char appPath[255];         // ����ģ��·��   ------ IN
	char modulePath[255];      // ģ������·��   ------ IN
	char videoPath[255];       // ģ����Ƶ·��   ------ OUT
	char audioPath[255];       // ģ����Ƶ·��   ------ OUT
	char docPath[255];         // ģ������ĵ�·�� ---- OUT
}ExDrawConfig, *PExDrawConfig;
// ����OPENGL�⿪ʼ
// �ṹ
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

// ����double ����
typedef struct IndexValue
{
	int index;
	int y;
	double cx;
	double cy;
	double cz;
	char text[128];
}INDEXVALUE;

// ��ͷ����
typedef enum ARRAY_TYPE
{
	DW_ARRAY_SOLID,  // ʵ��
	DW_ARRAY_OPEN,   // ���ŵ���
	DW_ARRAY_FILL,   // ���
	DW_ARRAY_UP,     // �ϱ�
	DW_ARRAY_DOWN    // �±�   
}ARRAY_TYPE;

typedef struct FONTS// ����������������
{
	DWORD val;// ������ʾ���ֵ(�����Ƚ�)
	GLuint listName;// ������ʾ�������
	GLfloat zex;  // Z�����������
	GLYPHMETRICSFLOAT gmf;// �����������ϸ��Ϣ
	FONTS *next;// ��һ�����������ָ��
}FONTS;

// PI
#define PI 3.1415926535897932354626
// �Ƕ�ת�ɻ���
#define A2R(x) ((x) * 0.017453292519943295769236907684886)
// ����ת�ɽǶ�
#define R2A(x) ((x) * 57.295779513082320876798154814105)
// ƽ��
#define PAN_ANGLE 180.0
// ֱ��
#define DIR_ANGLE 90.0
// ��ѧ�еĳ���
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
	// ��ѧ����
	double DIS(P3D a, P3D b);
			// ת��
	//P3D toP(float x, float y, float z);
	//DIRECTION toD(float alpha, float beta, float sita);
	ZTRGB toC(int r, int g, int b);
	//ZTRGB toCF(float r, float g, float b);

	P3D toP(double x, double y, double z);
	DIRECTION toD(double alpha, double beta, double sita);
	ZTRGB toCF(double r, double g, double b);
	// ͨ�ú���
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
		static HDC hdc; // ��ǰ�豸�����ļ�
		static HGLRC hRc; // ��ǰOpengl�����ļ�
	public:
		static PZTParamTable GetParam(int i); // ���ز�����ֵ
		static void SetParamMinMax(int i, double m_min, double m_max); // ���ò��������ֵ����Сֵ
		static void SetPauseOnStart(PZTDrawConfig config, bool bPause = false);  // �趨ģ��������ʱ�Ƿ���ͣ���������ڳ�ʼ�����е���
		static bool IsAllowIncrease(ZTOpenGLConfig* config); // �ж�Ŀǰ�Ƿ�����������
	private:
		static FONTS *begin;
		static FONTS *end;// ָ���һ�������һ�����������ָ��
		static FONTS *AddFont(DWORD dwChar, float zex);

		static PZTParamTable CurrentParamTable; // ��ǰ�Ĳ�����
		static int CurrentParamCount;
	public:
		// ������Ϣ����
		// ͼͼ��
		static float m_ScreenWidth;
		// ��ͼ��
		static float m_ScreenHeight;

		static float m_fOrigin[3]; // =   {0.0f, 2.0f, 15.0f};
		//m_fOrigin[1] =   2.0f;
		//m_fOrigin[2] =  15.0f;
		static float m_fRotation[3];

		// ģ�ݱ�
		static float m_fAspect;

		//m_fRotation[0] = -75.0f;
		//m_fRotation[1] =   0.0f;
		//m_fRotation[2] = -15.0f;
		// ���±���������Orth����ϵģʽ��ʹ�ã����Բ��ó�ʼ��
		static GLfloat			m_fLeft;
		static GLfloat			m_fRight;
		static GLfloat			m_fBottom;
		static GLfloat			m_fTop;

		static float m_fFovY; // = 45.0f;
		
		static float m_fNear; // =    1.0f;
		static float m_fFar; //  = 5000.0f;

		static double m_dModelViewMatrix[16];

		static int viewType; // ����ϵģʽ
		static float m_fScale;
	private:
		static void KillFonts(void); // ɾ��
	public:
		// �ַ�����
		static void FontSelect(int size = 20, const char *fontName = "����", int fontType = GB2312_CHARSET, bool bold = false, bool itl = false, bool underline = false, bool deleteline = false);
		// ��XY�����ַ�����ע��˻����岻��ת����������ȫ��2DЧ����������2D��ͼ����
		static void DrawFont2D(const char *str, double x = 0, double y = 0, ZTRGB c = toC(0, 0, 0));
		//
	public:
		// ������ģ��
		static void SetSubModule(PZTDrawConfig drawConfig, int index, const char *name);

		// �����Ӿ�����
		static void SetDrawSence(PZTDrawConfig drawConfig, double angle = 45.0, double fnear = 0.01, double ffar = 10000.0);

		// ���ó�ʼת�����ƶ������ƶ�����ת����
		static void SetDefaultRotAndTrans(PZTDrawConfig drawConfig, float tx = 0, float ty = 0, float tz = -30, float rx = 0, float ry = -45.0, float rz = 0);

		// ��������ϵ��ʾ����
		static void SetViewType(PZTDrawConfig drawConfig, int viewType);

		// �������ر�������ʹ��
		static void AddSwitchName(PZTDrawConfig drawConfig, int index, const char *name, bool defStatus = false);

		// �жϵ�index�������Ƿ�Ϊ�棬index >= 0 && index < 50
		static bool IsTrue(ZTOpenGLConfig *config, int index);

		// ����ģ�ͻ�����Ϣ
		static void ConfigModule(PZTDrawConfig drawConfig, int interval = 50, int zdepth = -30, int subModuleCounter = 1, const char *mname = 0, const char *author = 0, const char* url = 0, const char *mdesc = 0);
		
		// ���滭ͼ״̬��Ϣ
		static void SaveDraw(ZTOpenGLConfig *config);

		// ���ñ任, allowR - �Ƿ����ת����allowT - �Ƿ�����ƶ��� allowS - �Ƿ����Ŵ�/��С
		static void ConfigAllow(PZTDrawConfig drawConfig, bool allowR = true, bool allowT = true, bool allowS = true);
	public:
		// GL list����
		static GLuint CreateDrawList(int range);
		static void BeginDrawList(GLuint gllist);
		static void EndDrawList();
		static void DeleteList(GLuint gllist, int range);
		static void DrawList(GLuint gllist, int range = 0);
		static void DrawLists(int n, GLenum type, GLvoid* lists);
	public:
		// �ṹ����
		static void P(P3D &p, float x, float y, float z);
		static void C(ZTRGB &c, float r, float g, float b);
		static void D(DIRECTION &d, float al, float bt, float st);
		static P3D MID(P3D a, P3D b); // ������е�
	public: // ��������
		// �������Σ�ÿ������ָ����ɫ
		static void DrawTri(P3D p1, P3D p2, P3D p3, ZTRGB c1, ZTRGB c2, ZTRGB c3, bool fill = true);
		// ʹ������һ�������Σ�����ͼ�����¶Խ������β�����Ϊ�����˷������ر�����������һ����������Ĺ��̵��ú�Ҫ���´�����
		static void DrawTri(P3D p1, P3D p2, P3D p3, int texIndex = 0);
		// ���ı���
		static void DrawQuad(P3D p1, P3D p2, P3D p3, P3D p4, ZTRGB c1, ZTRGB c2, ZTRGB c3, ZTRGB c4, bool fill = true, int alpha = 100);
		// ���ı���
		static void DrawQuad(P3D p1, P3D p2, P3D p3, P3D p4, ZTRGB c1, bool fill = true, int alpha = 100);
		// ������������ı���,�˷������ر�����������һ����������Ĺ��̵��ú�Ҫ���´�����
		static void DrawQuad(P3D p1, P3D p2, P3D p3, P3D p4, ZTRGB c1, int texIndex);
		// ��N����
		static void DrawNBlock(P3D *p, int pCount, ZTRGB *c, bool fill = true, int alpha = 100);
		// ��Բ����
		static void DrawEllipse(P3D pos, float radius, ZTRGB c, float start = 0.0f, float end = 360.0f, float step = 1.0f, bool closed = false, bool slice = false, DIRECTION d = toD(0,0,0));
		// ������Բ
		static void DrawEllipseFill(P3D pos, float radius, ZTRGB c, float start = 0.0f, float end = 360.0f, float step = 1.0f, DIRECTION d = toD(0,0,0));
		// ����͸������ɫ
		static void SetColor(ZTRGB c, int alpha = 100);
		// ���浱ǰ����״̬
		static void SaveState();
		// ʹ�����һ�ξ���״̬
		static void UseLastState();
		// ʹ��͸��
		static void EnableBlend();
		// ʹ��͸����ɫ
		static void EnableBlendAlpha(ZTRGB c = toC(255,255,255), int alpha = 50);
		// ʹ��͸����ɫr,g,b(0-255)
		static void EnableBlendAlphai(int r = 255, int g = 255, int b = 255, int alpha = 50);
		// ʹ��GL����ONE͸��
		static void EnableBlendGLONE();
		// �ر�͸��
		static void CloseBlend();
		// ������Ȳ���
		static void EnableDepth();
		// �ر���Ȳ���
		static void CloseDepth();

		static void Color(ZTRGB &color, int r, int g, int b);
		static void Color(ZTRGB &color, float r, float g, float b);
		static void Point(P3D &p, float x, float y, float z);
		static void Direct(DIRECTION &p, float a, float b, float s);
		static void Vector(VECTOR &p, float a, float b, float c);
		// ��ʼ������ʽ����
		static void Param(PZTParamTable param, int index, const char *name, double curValue, double minValue, double maxValue, int ticks, const char *unit = NULL, int type = 0);
		// ��ȡ��index������
		static double pv(ZTOpenGLConfig *config, int index = 0);
		// ��ʼ��ͼ
		static void BeginDraw(ZTOpenGLConfig *config);

		// �۲��
		static void LookAt(double eyex, double eyey, double eyez, double cx, double cy, double cz, double upx = 0, double upy = 1, double upz = 0);

		// ����任��vE[a,b], ����v����ӳ�䵽[c,d]�е�ֵ
		static double CH(double v, double a, double b, double c, double d);

		// �ռ��a,b֮��ľ���
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
		// ������API
		// ������
		static void OpenTexture2D();
		// �ر�����
		static void CloseTexture2D();
		
		// ��������FILTER�����º�����Ϊglԭʼ����
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
		// ���������S/T�����Զ����ɣ���Ҫ�ǶԲ��������״��
		static void EnableOrDisableTextureST(bool s = false, bool t = false, GLint s_mode = GL_OBJECT_LINEAR, GLint t_mode = GL_OBJECT_LINEAR, GLfloat *s_coeff = 0, GLfloat *t_coeff = 0);
		static void EnableOrDisableTextureS(bool s = false, GLint s_mode = GL_OBJECT_LINEAR, GLfloat *s_coeff = 0);
		static void EnableOrDisableTextureT(bool t = false, GLint t_mode = GL_OBJECT_LINEAR, GLfloat *t_coeff = 0);

	private:
		// ����洢
		static GLuint texture[50]; // ���50������
	public:
		// �ӽ�λͼΪ����
		static AUX_RGBImageRec *LoadBMP(char *Filename);
		// ��������ָ���Ĵ洢�ռ䣬index 0 - 50, filename - λͼ��һ��Ҫ��λͼ
		static int LoadGLTextures(int index, char *Filename);

		static void LoadGLTexturesFromRES(int index, int RID); // ����ԴID�м�������

		static void LoadGLTexturesFromRES(HINSTANCE hinst, int index, int RID); // ����ԴID�м�������ָ��ģ��ʵ�����

		// ʹ�õ�index�ŷ���, 0 - 50������Ҫ���������صķ����������
		static void UseTexture(int index);
		// ��2D�����ܣ�����index������
		static void OpenAndUseTexture(int index);
		// ���ص�index������
		static GLuint GetTexture(int index);
	public:
		static GLUquadricObj *quobj;
		// ������ɫ
		static void DW_SetColor(ZTRGB c);
		// ��ʼ����Opengl��ͼ
		static void DW_GLSetting(int w, int h, double a = 45.0, double fNear = 0.01, double fFar = 10000.0, GLenum vm = GL_MODELVIEW);
		// ��ʼ��GL
		static void DW_InitGL(void);
		// ��ʼ��GLʹ�ñ���
		static void DW_InitGLWithBG(ZTRGB c);
		// ��ʼopengl
		static void DW_BeginGL(HDC hdc);
		// ����OpenGL
		static void DW_EndGL(void);
		// ��ȡ��ǰ��ͼ��������
		static HGLRC GetCurrentLRC(void);
		static HDC GetCurrentDC(void);
		// �������������ڻ�ͼǰ���е���
		static void DW_DrawBackground(ZTRGB c1 = toC(255, 0, 0), ZTRGB c2 = toC(0, 0, 0), ZTRGB c3 = toC(255,255, 0), ZTRGB c4 = toC(255, 0, 255));
		// �������������ڻ�ͼǰ���е���
		static void DW_DrawColorBackground(ZTRGB c1 = toC(0, 0, 0));
		// ��ʼ�任
		static void DW_Translate(VECTOR v);
		// ����GL�ڴ���WINDOWS GUIͼ�ν��棬ʹ����ͼ��Ч
		static void DW_GLValid(void);
		// ��X��Y��Z�����ƶ�x,y,z
		static void DW_Translatef(float x, float y, float z);
		// ��ת
		static void DW_Rotate(float angle);
		static void DW_RotateD(DIRECTION d);
		static void DW_RotateX(float angle);
		static void DW_RotateY(float angle);
		static void DW_RotateZ(float angle);
		// �������
		static void DW_SetStart(P3D p, DIRECTION d);
		// ���û�ͼ�Ŀ��
		static void DW_SetDrawWidth(float width);
		// ���û�����
		static void DW_SetPointSize(float width);
		// ���տ���
		static void DW_OpenLighting(void);
		// �رչ���
		static void DW_CloseLighting(void);
		// �򿪹��գ����ҿ���index��
		static void OpenLight(int index);
		// �رչ��գ����ر�index��
		static void CloseLight(int index);
		// ����ɫ���ʿ���
		static void OpenColor();
		// �ر���ɫ���ʿ���
		static void CloseColor();
		//static void ConfigColor();
		// ��Դ����(��index�ƣ�ע�ⲻ�������չ���)
		static void DW_OpenLight(int index);
		// ��Դ���أ��ر�index�ƣ�ע�ⲻ�رչ��չ���
		static void DW_CloseLight(int index);
		// ��Դ����
		static void DW_SetupLight(int index, float *position = 0, float *ambient = 0, float *diffuse = 0, float *specular = 0);
		static void DW_SetupLight(int index, P3D *position = 0, ZTRGB *ambient = 0, ZTRGB *diffuse = 0, ZTRGB *specular = 0);

		static void ConfigColor(GLFACE face, COLOR_TYPE type);

		static void ClearColor(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);

		static void DW_SetupLightEx(int index, float *spotDirection = 0 /*SPOT_DIRECTION*/, float *spotExponent = 0/*SPOT_EXPONENT*/, float *spotCutoff = 0/*SPOT_CUTOFF*/, float *constantAttenuation = 0/*CONSTANT_ATTENUATION*/, float *linerAttenuation = 0/*LINER_ATTENUATION*/, float *quadraticAttenuation = 0/*QUADRATIC_ATTENUATION*/);
		// ��������
		static void DW_SetupMat(int face, float *ambient = 0, float *diffuse = 0, float *specular = 0, float *emission = 0, float shiness = 0);

		static void DW_SetupMat(int face, ZTRGB *ambient = 0, ZTRGB *diffuse = 0, ZTRGB *specular = 0, ZTRGB *emission = 0, float shiness = 0.0f);

		static void DW_SetupMatEx(int face, float *ambientAndDiffuse = 0/*AMBIENT_AND_DIFFUSE*/, float *shiness = 0/*GL_SHINESS*/, float *colorIndexes = 0/*GL_COLOR_INDEXES*/);
		// ����
		static void DW_Reset(void);
		// ��ʼ����
		static void DW_BeginLineStrip(void);
		static void DW_BeginLines(void);
		static void DW_BeginLineLoop(void);
		static void DW_LineTo(P3D p);
		static void DW_LineToC(P3D p, ZTRGB c);
		static void DW_EndDraw(void);
		// ��ͼ����
		static void DW_DrawLine(P3D p1, P3D p2, ZTRGB color); // ����
		static void DW_DrawLine(P3D p1, P3D p2); // ����
		static void DW_DrawLineC(P3D p1, P3D p2, ZTRGB c1, ZTRGB c2);
		static void DW_DrawLines(P3D *p, int pCount, ZTRGB color);
		static void DW_DrawLines(P3D *p, int pCount);
		static void DW_DrawLinesC(P3D *p, int pCount, ZTRGB *color);
		static void DW_DrawTraiangle(P3D a, P3D b, P3D c, ZTRGB cc, bool fill); //GL_TRIANGLES
		static void DW_DrawTraiangleTex(P3D a, P3D b, P3D c, ZTRGB cc, int texIndex); //GL_TRIANGLES
		static void DW_DrawArrow(P3D s, P3D e, ZTRGB c, float al, float d = 10, ARRAY_TYPE fill = DW_ARRAY_FILL); // ����ͷ�� al ��ͷ���ȣ�d - �Ƕ�

		static void DW_DrawArrowEx(P3D s, P3D e, float radius = 0.1, float al = 1, float d = 15); // ����ͷ�� al ��ͷ���ȣ�d - �Ƕ�, radiusΪ�뾶

		static void DW_DrawPoints(P3D *p, int pCount, float size = 1.0f, ZTRGB c = toC(255,0,0));
		static void DW_DrawPoint(P3D p, float size = 1.0f, ZTRGB c = toC(255,0,0));

		static int sign(double v);


		static void DW_DrawArrowDouble(P3D s, P3D e, ZTRGB c, float al, float d = 10, ARRAY_TYPE fill = DW_ARRAY_FILL); // ���˻���ͷ
		static void DW_DrawCurve(P3D *p, int pCount, ZTRGB color, int level = 5);
		static void DW_DrawCurveC(P3D *p, int pCount, ZTRGB *color, int level = 5);
		static void DW_DrawBall(P3D p, double r, ZTRGB c, DIRECTION v = toD(0, 0, 0)); // v Ϊ��ͬ�ķ���ת���ĽǶ�
		// ��Բ����ɫ���ⲿ����
		static void DW_DrawBall(P3D p, double r, DIRECTION v = toD(0, 0, 0));

		// ��������
		static void DW_CreateFont(char *fontName = "����", bool bold = true, bool underline = false, bool its = false, bool delline = false, int width = 0, int height = 0, int angle = 0);

		// ���ַ�����zs: ��ʾ�ַ��ĺ�ȣ�Ĭ��Ϊƽ���ַ���fcx,fcy,fczΪX��Y��Z���������, start��ʾ��ʼλ��
		static void DW_DrawString(char *text, P3D start, ZTRGB c, float zs = 0.0f, float fcx = 1.0f, float fcy = 1.0f, float fcz = 1.0f); // ���ַ���
		static void DW_DrawString(char *text, P3D start, float zs = 0.0f, float fcx = 1.0f, float fcy = 1.0f, float fcz = 1.0f); // ���ַ���
		// �����з���ѡ����ַ�
		static void DW_DrawString(char *text, P3D start, ZTRGB c, DIRECTION v, float zs = 0.0f, float fcx = 1.0f, float fcy = 1.0f, float fcz = 1.0f); // ���ַ���
		// ����ײ㻭�ַ���(ƽ���ַ�)
		static void DW_DrawString(char *text, ZTRGB c = toC(0, 0, 0), double x = 0.0, double y = 0.0, float zs = 0.0f, float fcx = 0.1f, float fcy = 0.1f, float fcz = 0.1f); // ���ַ���

		static void GLDrawSurface(P3D *p,ZTRGB *c,int row,int col,bool autoz, double radius = 2, int slice = 1, int stack = 1);
		static void GLDrawSurface(P3D *p,ZTRGB *c,int row,int col,bool autoz,int ii,int ji);
		// ��Nurbs����
		static void GLDrawNursSurface(P3D *p, int sstride, int tstride, bool fill = true, float *sknot = NULL, int sknot_count = 0, 
			float *tknot = 0, int tknot_count = 0, int sOrder = 4, int tOrder = 4, GLenum type = GL_MAP2_VERTEX_3, float glutolerange = 50.0f);
		// ��Nurbs����
		static void GLDrawNursSurface(const float *p, int sstride, int tstride, bool fill = true, float *sknot = NULL, int sknot_count = 0, 
			float *tknot = 0, int tknot_count = 0, int sOrder = 4, int tOrder = 4, GLenum type = GL_MAP2_VERTEX_3, float glutolerange = 50.0f);

		// �ָ�����ΪĬ��ֵ
		static void RestorMaterial(void);

		
		// ���豭,size - ��С��pos�������꣬d����,c��ɫ
		static void DW_DrawTeapot(double size, P3D pos, ZTRGB c, DIRECTION d = toD(0,0,0));
		// ���豭����������ɫ, size - ��С��pos�������꣬d����
		static void DW_DrawTeapot(double size, P3D pos, DIRECTION d = toD(0,0,0));

		// �����ɣ�size��ϸ��rd-�뾶,nc-���ϰ뾶��dis-��Ȧ֮��ľ���,c-��ɫ��ע���򵽻������Ӱ��, start - ��һȦ���ɵ�Բ�ģ� d - �����ɷ���, step - 360�ĵȷּ��
		static void DW_DrawSpring(double size, double rd, int nc, double dis, ZTRGB c = toC(255,255,255), P3D start = toP(0,0,0), DIRECTION d = toD(0,0,0), double step = 5);

		// �����ɣ�size��ϸ��rd-�뾶,nc-���ϰ뾶��dis-��Ȧ֮��ľ���, start - ��һȦ���ɵ�Բ�ģ� d - �����ɷ���, step - 360�ĵȷּ��
		static void DW_DrawSpringNoColor(double size, double rd, int nc, double dis, P3D start = toP(0,0,0), DIRECTION d = toD(0,0,0), double step = 5);
		// �����ɣ�size��ϸ��rd-�뾶,nc-���ϰ뾶��dis-��Ȧ֮��ľ���, start - ��һȦ���ɵ�Բ�ģ� d - �����ɷ���, step - 360�ĵȷּ��, alen - ���˵ĳ���(has=trueʱ�Ż�)
		static void DW_DrawSpringEx(double size, double rd, int nc, double dis, P3D start = toP(0,0,0), DIRECTION d = toD(0,0,0), double step = 5, bool hasa = false, double alen = 0.2);

		// ��Բ��/׶, bradius�ײ�Բ�뾶��tradius����Բ�뾶��Ϊ0��ʾԲ׶��height:�߶�,bcp �ײ�Բ��λ��, d ����, slice/stack��/γϸ��
		static void DW_DrawCylinder(double bradius, double tradius, double height, bool fill = false, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), int slice = 32, int stack = 32);

		static void DW_DrawAuxCylinder(double radius, double height, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);
		static void DW_DrawAuxCone(double radius, double height, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// ������
		static void DW_DrawDisk(double inradius, double outradius, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), int slice = 32, int loops = 32);

		// ����
		static void DW_DrawSphere(double radius, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// ����
		static void DW_DrawTorus(GLdouble innerRadius,GLdouble outerRadius, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// ��������
		static void DW_DrawCube(double width, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);
		// ��������
		static void DW_DrawBox(double width, double height, double depth, P3D bcp = toP(0,0,0), DIRECTION d = toD(0,0,0), bool wire = false);

		// ��������
		static void DW_DrawCoor(double length, bool is3d = false, double radius = 0.2, P3D drawPos = toP(0,0,0), DIRECTION d = toD(0,0,0));

		
		// ��������
		static void DW_DrawCoorEx(double length, double linesize = 0.2, double radius = 0.3, float alen = 1, P3D drawPos = toP(0,0,0), DIRECTION d = toD(0,0,0));

		// ������
		static void DW_DrawGear(float inner_radius, float outter_radius, float width, int teeth, float tooth_depth);

		static void DW_DrawGear(P3D point, float inner_radius, float outer_radius, float width, int teeth, float tooth_depth, DIRECTION d = toD(0,0,0));

		//������
		static void DrawSurface(P3D *p, ZTRGB *c, int row,int col, bool fill = true);
		// �����棬��ɫ����Ҫʹ��OpenColor()����ɫ����
		static void DrawSurface(P3D *p, int row, int col, ZTRGB c, bool fill = true);

		// �ָ�����ΪĬ��ֵ
		static void RestLight(int index = 0);
		// �򿪾�����ɫ�Ĺ�Դ��Ĭ��Ϊ��ɫ
		static void OpenColorLight(int index = 0, ZTRGB c = toC(255,255,255), P3D pos = toP(0,0,1));

		// �ü�ƽ��
		// �򿪲ü�ƽ��index
		static void OpenClip(int index = 0);
		// �رղü�ƽ���index
		static void CloseClip(int index = 0);
		// �����ü�ƽ��ķ��̣�ax+by+cz+d=0
		static void SetupClip(int index, double a, double b, double c, double d = 0);

		// ����ת��
		static void GetWorldCoord(int ix, int iy, float fz, P3D &p);
		static void GetWindowMousePos(HWND hwnd, P3D &p);
		static void Get3DMousePos(HWND hwnd, P3D &p);

		// �������߻�ͼʹ������
		static void EnableQuadricTexture(GLUquadricObj *qobj = 0);
		// ��ʹ������
		static void DisableQuadricTexture(GLUquadricObj *qobj = 0);

	private:
		static void drawBez(P3D *p, int pCount, ZTRGB c, int level);
	public:
		// ����2D��ͼ
		static void Draw2DAix(int flag = 0, const char* aixName = "X", double dstart = -15, double dend = 15, int ec = 15, 
			  double factStart = -15, double factEnd = 15, 
			  int numFormat = 0, ZTRGB lineColor = toC(0, 0, 0), ZTRGB tColor = toC(0, 0, 0), ZTRGB lblColor = toC(0, 0, 0), 
			  double offRuler = 0.07, double offY = 0.2, double offYText = 0.25);
		static void Draw2DXAix(const char* aixName = "X Aix", double dstart = -15, double dend = 15, int equalCount = 15, double dstartf = -15, double dendf = 15, int numFormat = 0, ZTRGB lineColor = toC(0, 0, 0), ZTRGB tColor = toC(0, 0, 0), ZTRGB lblColor = toC(0, 0, 0));
		static void Draw2DYAix(const char* aixName = "Y Aix", double dstart = -8, double dend = 8, int equalCount = 8, double dstartf = -8, double dendf = 8, int numFormat = 0, ZTRGB lineColor = toC(0, 0, 0), ZTRGB tColor = toC(0, 0, 0), ZTRGB lblColor = toC(0, 0, 0));
		// ����������
		static void Draw2DAixGrid(double x, double y, double cx, double cy, int xsplit = 10, int ysplit = 10, ZTRGB borderColor = toC(0, 0, 0), ZTRGB bgColor = toC(200, 200, 200), ZTRGB gridLineColor = toC(220, 220, 220));
	public:
		// ���亯��
		// ������һ������Ϊx,y,z
		static void LineTo(double x = 0, double y = 0, double z = 0);
		// ����RGB��ɫ
		static void SetColor(int r = 255, int g = 255, int b = 255);
		// ����RGB��ɫ
		static void SetColor(int r, int g, int b, int alpha);
		// �����߿�
		static void SetDrawWidth(GLfloat width = 1.0f);
		// ���õ��
		static void SetPointSize(GLfloat size = 1.0f);
		// �Զ����÷�������, p1,p2,p3�����ƽ��
		static void SetNormal(P3D p1, P3D p2, P3D p3);
		// ������INIT��ʹ�ã���������ʹ�ã�������Ч��fogColor[ZTRGB]-����ɫ��fogDensity-��Ũ�ȣ�ֵԽ��ԽŨ��,fogStart/fogEnd(������ĻԶ��), fogMode[GL_EXP, GL_EXP2, GL_LINEAR]-��ģʽ��hint-ȷ���������Ⱦ��ʽ[GL_NICEST,GL_FASTEST,GL_DONT_CARE]
		static void EnableFog(ZTRGB fogColor = toCF(0.5, 0.5, 0.5), float fogDensity = 0.02, float fogStart = -20, float fogEnd = -10.0, GLenum fogMode = GL_EXP, GLenum hint = GL_DONT_CARE);
		// ������INIT��ʹ�ã���������ʹ�ã�������Ч��fogColor[float*v����Ԫ��, 0-1֮��]-����ɫ��fogDensity-��Ũ�ȣ�ֵԽ��ԽŨ��,fogStart/fogEnd(������ĻԶ��), fogMode[GL_EXP, GL_EXP2, GL_LINEAR]-��ģʽ��hint-ȷ���������Ⱦ��ʽ[GL_NICEST,GL_FASTEST,GL_DONT_CARE]
		static void EnableFogv(float *fogColor = 0, float fogDessity = 0.02, float fogStart = -20, float fogEnd = -10.0, GLenum fogMode = GL_DONT_CARE, GLenum hint = GL_DONT_CARE);
		// �ر���
		static void CloseFog();
		// ������
		static void OpenFog();
		// ������Ȼ����д, GL_TRUE - ֻ����GL_FALSE - ��д���˹��ܽ����ڶ������汾���͸������֮��������͸��һ��Ҫ�رգ�����������������Ȳ��Խ���������
		static void SetDepthReadOnly(GLboolean action = GL_TRUE);
		// ��3D������غ���
		static double DISv(double *p1, double *p2); //������
		// �����������꣬���뾶Ϊr��Բ��(startPoint, endPointΪdouble�͵���Ԫ��), qObj - Ϊ�����������û���
		static void DrawCylinderByEndPoint(GLUquadricObj*qObj, double* startPoint, double* endPoint, double r);
		// �����ɵ�һȦ innerRadius - ��ϸ�뾶��midLineRadius - ���߰뾶, slices,rings - �ֿ��С, v - ���������ٶȣ���Ȧ���ͳ��ȿ��Լ��������
		static void DrawOnCircleSpringPiece(GLfloat innerRadius, GLfloat midLineRadius, GLint slices, GLint rings, float v);
		// ��Բ��(����Ԫ��ģ)innerRadius - ��ϸ�뾶��midRadius- ���߰뾶��ori - ����Բ�ģ�����ڳ������꣩, d - ��X��Y��Z˳��ת���ĽǶ�, slices, rings - ���ȣ��ֿ飩
		static void DrawTuros(GLfloat innerRadius, GLfloat midRadius, P3D ori = toP(0, 0, 0), DIRECTION d = toD(0, 0, 0), GLint slices = 50, GLint rings = 50);
		// circleCount - Ȧ��, len - ���ɳ��ȣ�ע�⣺���������˵ı����൱����������λ�ã�, midLineRadius - ���߰뾶��innerRadius - ��ϸ�뾶��ori - ����������꣨����ڳ������꣩, d - ���ɰ�X��Y��Z��˳��ת�ĽǶ�, drawstartpoint - �Ƿ���ʼ�˵ı���drawendpoint - �Ƿ�δ�˱���endlen - ������
		static void DrawSpring3D(int circleCount, double len, double midLineRadius, double innerRadius, P3D ori = toP(0, 0, 0), DIRECTION d = toD(0, 0, 0), bool drawstartpoint = false, bool drawendpoint = false, double endlen = 0.8, int slices = 50, int rings = 50);

	public: // 2009-10-17���亯��
		// ������, �Զ����㷨������ע�����ֻ��ΪX/Y���棬ZΪ���
		static void DrawCommonFace(P3D *p, ZTRGB *c, int row,int col, bool fill = true);
		// �����棬�Զ����㷨������ע�����ֻ��ΪX/Y���棬ZΪ���
		static void DrawCommonFace(P3D *p, int row,int col, bool fill = true);
		// ��һ������
		static void normalize(double *v); // ��һ��һ�������ڲ�����
		// �Զ��豸������
		static void SetCommonNormal(P3D *p, int i, int j, int row, int col); // һ�������ڲ�����
	public: // 2010-01-27��������
		// p - һά���б�����p��row��*col�У�˳��洢, row - ������col - ����, fill - �Ƿ����, c - ���ָ���������p������ͬ�Ĵ�С
		static void DrawSurfaceExtends(P3D *p, int row, int col, bool fill = true, ZTRGB *c = 0);
		// ����ת����
		// ���sita�պ� sita =0 - 360, ��option_sita=true; 
		// ���Ϊ���պ϶��� option_r=0, �պϹ⻬����option_r=1, �պϼⶥ��option_r=2 
		static void DrawSurfaceCircle(P3D *p, int maxsita, int maxr, bool option_sita, int option_r);
	};
	
	// MFC Supports
	class DllExport UI{
	public:
		UI(void);
		~UI(void);
	public:
		static HWND m_hWndParam; // �������HWND
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
		// ����UIAPI�����������������
		static void AddCoor(int index, LPCTSTR labelText, int y, P3D point = toP(0.0, 0.0, 0.0)); // λ��
		static P3D GetCoor(int index); // ��ȡ����ֵ
		static void SetCoor(int index, P3D p); // ��������ֵ
		static void SetCoor(int index, double x, double y, double z); // ��������ֵ
	};

	// Opengl��ͼ����������
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
		// �豸�������ԣ���0-1.0���ֵ����RGB��
		static void SetAmbient(float r, float g, float b, float w = 1.0f);
		static void SetDiffuse(float r, float g, float b, float w = 1.0f);
		static void SetSpecular(float r, float g, float b, float w = 1.0f);
		static void SetEmission(float r, float g, float b, float w = 1.0f);

		// ��RGB����
		static void SetAmbient(int r, int g, int b, float w = 1.0f);
		static void SetDiffuse(int r, int g, int b, float w = 1.0f);
		static void SetSpecular(int r, int g, int b, float w = 1.0f);
		static void SetEmission(int r, int g, int b, float w = 1.0f);

		// ��ZTRGB�ṹ�豸
		static void SetAmbient(ZTRGB rgb, float w = 1.0f);
		static void SetDiffuse(ZTRGB rgb, float w = 1.0f);
		static void SetSpecular(ZTRGB rgb, float w = 1.0f);
		static void SetEmission(ZTRGB rgb, float w = 1.0f);

		//
		static void SetShinness(float v = 100.0f);
		static void SetFace(int f = 0x0404);
		// ���ðٷֱ���ɫ, flag - ��ʾ��ambient,diffuse,specular or emission, 0 - 4, rate - ����Ϊ��ɫ�İٷ�֮rate����ʾ��������ɫ��rate%�����õ�ǰָ�����ʵ���ɫ
		static void SetRedRate(float rate = 100.0f, int flag = 0);
		static void SetBlueRate(float rate = 100.0f, int flag = 0);
		static void SetGreenRate(float rate = 100.0f, int flag = 0);
		static void SetWhiteRate(float rate = 100.0f, int flag = 0);
		static void SetRGBRate(int r, int g, int b, float rate = 100.f, int flag = 0);
		//��ĸ�̣�������ʯ
		static void SetEmerald();
		//��ɫ
		static void SetSilver();
		//��
		static void SetGold();
		//ͭ
		static void SetCopper();
		//
		static void SetBrone();
		// ��ɫ
		static void SetWhiteMetal();
		// ��ɫ
		static void SetBlackMetal();
		// ��ɫ
		static void SetYellowPaint();
		// ��ɫ
		static void SetBlue();
		// ��ɫ
		static void SetRed();
		// ��ɫ
		static void SetGreenPaint();
		// ����Ϊ����Ĭ��ֵ
		static void Reset();
	public:
		// ������ɫ��
		// ��ɫ255, 0, 0
		static ZTRGB RED;
		// ��ɫ0, 255, 0
		static ZTRGB GREEN;
		// ��ɫ0, 0, 255
		static ZTRGB BLUE;
		// ��ɫ128, 128, 128
		static ZTRGB GRAY;
		// ����ɫ192, 192, 192
		static ZTRGB LIGHT_GRAY;
		// ���ɫ64, 64, 64
		static ZTRGB DARK_GRAY;
		// ��ɫ0,0,0
		static ZTRGB BLACK;
		// �ۺ�255, 175, 175
		static ZTRGB PINK;
		// ��ɫ255, 200, 0
		static ZTRGB ORANGE;
		// ��ɫ255,255,0
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

		// ��������
		// ԭ��0,0,0
        static P3D ORI_POINT;
		// ���ò��ʶ���
		// �޲���
		static GLfloat NO_MAT[4];
		// 70%�Ҷ�
		static GLfloat MAT_70[4];
		// ��ɫ
		static GLfloat MAT_RED[4];
		// ��ɫ
		static GLfloat MAT_GREEN[4];
		// ��ɫ
		static GLfloat MAT_BLUE[4];
		// �ۺ�
		static GLfloat MAT_PINK[4];
		// ��ɫ
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
		static OBJ3DS* GetInstance(void); // ��ȡ����3DS��ʵ��
		void AddIDMap(char *strFile, int rid); // �����Դ���ļ�����IDӳ�䣨���ڴ���ԴID�м���3DSʱ��Ҳ����Դ�м�����������Ҫ��3DS��ʹ�õ�λͼ�������ӳ�䣬���������޷����м���
		void Init3DS(void);  // ��ʼ��3DS�ڴ棬���к��������ڴ˺������ú�ſ��Ե���
		void Destroy3DS(void); // ɾ��3DS�ڴ棬��ģ�ͽ����������ô˺�����

		void Load3DSFromRes(HINSTANCE hinst, int rid, int index);   // ����Դ�м���3DS����Դ���ͱ���ΪOBJ3DS������ģ�ͼ��ص�index����ʾ��ģ����
		void Load3DSFromFile(char *strFile, int index); // ���ļ��м���3DS����ģ�ͼ��ص�index����ʾ��ģ����

		void Draw3DSObject(int objindex, P3D p, DIRECTION d, float size = 0.2); //��ʾ3dsģ��
	};
}

// =======================End Of the Core Programe Util Libs================

#ifdef __cplusplus
}
#endif


/*
	�����ĺ���
*/
extern "C"
{
	/*ʵ�ִ˽ӿڣ�������ͼ*/
	_declspec(dllexport) void ZTDraw(ZTOpenGLConfig *config);
	/*��ʼ������*/
	_declspec(dllexport) void ZTInitParams(PZTParamTable params, int *count, PZTDrawConfig sysConfig);
	/*��ʼ������-��չ*/
	_declspec(dllexport) void ZTInitParamsEx(PZTParamTable params, int *count, PZTDrawConfig sysConfig, PExDrawConfig exconfig);

	// ����Ӧ�ó��򻷾���HWND
	_declspec(dllexport) void ConfigWindowsHandles(HWND mainFrameHandle, HWND drawViewHandle, HWND paramHandle)
	{
		DW::UI::m_hWndParam = paramHandle;
		DW::UI::m_hWndDraw = drawViewHandle;
		DW::UI::m_hWndFrame = mainFrameHandle;
	}
	//����Window��Ϣ
	_declspec(dllexport) void RawWindowProc(int winId, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, int ctlId, LPARAM reserved1 = 0, LPARAM reserved2 = 0);
	// ģ�͹ر�
	_declspec(dllexport) void RawDestroy(HWND hwnd);


	_declspec(dllexport) void beginGL(HWND hwnd)
	{
		HDC hdc = ::GetDC(hwnd);
		DW::OpenGL::DW_BeginGL(hdc); // ����Open GL
		DW::OpenGL::DW_InitGL(); // ��ʼ��OpenGL
		
		/*
		RECT rect;
		GetClientRect(hwnd, &rect);
		int sw = rect.right - rect.left;
		int sh = rect.bottom - rect.top;
		ZT::OpenGL::ZT_GLSetting(sw, sh); // ������ͼ*/
	}
	_declspec(dllexport) void beginGLDC(HDC hdc)
	{
		DW::OpenGL::DW_BeginGL(hdc); // ����Open GL
		DW::OpenGL::DW_InitGL(); // ��ʼ��OpenGL
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





