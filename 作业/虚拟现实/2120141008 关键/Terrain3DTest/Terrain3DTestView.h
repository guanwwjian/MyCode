// Terrain3DTestView.h : interface of the CTerrain3DTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSDOPENGLVIEW_H__75C5AAEC_37B0_4A8B_9132_9A0C663F6DDC__INCLUDED_)
#define AFX_MYSDOPENGLVIEW_H__75C5AAEC_37B0_4A8B_9132_9A0C663F6DDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Texture.h"
#define	MAX_PARTICLES	250		// 需要创建的粒子数目
#define MAX  500
struct vertex
{
	GLfloat x, y, z, light;
};

typedef struct						// 定义一个粒子的结构
{
	bool	active;					// 粒子是否处于激活状态
	GLfloat	life;					// 粒子的寿命
	GLfloat	fade;					// 粒子的淡化速度
	GLfloat	r;						// 粒子的颜色
	GLfloat	g;
	GLfloat	b;
	GLfloat	x;						// 粒子的位置坐标
	GLfloat	y;
	GLfloat	z;
	GLfloat	xi;						// 粒子的方向矢量
	GLfloat	yi;	
	GLfloat	zi;
	GLfloat	xg;						// 粒子加速度值
	GLfloat	yg;	
	GLfloat	zg;	
}
particles;

class Model;
class CTerrain3DTestView : public CView
{
protected: // create from serialization only
	CTerrain3DTestView();
	DECLARE_DYNCREATE(CTerrain3DTestView)

// Attributes
public:
	CTerrain3DTestDoc* GetDocument();

	Model *pModel;
	vertex field[MAX+9][MAX+9];
	particles particle[MAX_PARTICLES];
	Texture m_texture;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerrain3DTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTerrain3DTestView();
/////////////////////////////////////////////////////////////////
//添加成员函数与成员变量
	BOOL RenderScene();
	BOOL SetupPixelFormat(void);
	void SetLogicalPalette(void);
	BOOL InitializeOpenGL(CDC* pDC);

	HGLRC		m_hRC;			//OpenGL绘制描述表
	HPALETTE	m_hPalette;		//OpenGL调色板
	CDC*	    m_pDC;			//OpenGL设备描述表
/////////////////////////////////////////////////////////////////
	bool InitGL(GLvoid);
	bool InitTerrain(GLvoid);
	bool InitSmoke(GLvoid);
	bool DrawWireframe(GLvoid);
	bool DrawTexture(GLvoid);
	bool DrawWater(GLvoid);
	bool DrawSun(GLvoid);
	bool DrawPlane(GLvoid);
	bool DrawTerrain(GLvoid);
	bool DrawSky(GLvoid);
	void Caculate(GLvoid);
	GLfloat Hypot(GLfloat A, GLfloat B);
	GLfloat ABS(GLfloat A);
	void RestoreMyDefaultSettings();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTerrain3DTestView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Terrain3DTestView.cpp
inline CTerrain3DTestDoc* CTerrain3DTestView::GetDocument()
   { return (CTerrain3DTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSDOPENGLVIEW_H__75C5AAEC_37B0_4A8B_9132_9A0C663F6DDC__INCLUDED_)
