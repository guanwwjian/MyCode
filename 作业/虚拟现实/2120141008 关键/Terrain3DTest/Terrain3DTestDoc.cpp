// Terrain3DTestDoc.cpp : implementation of the CTerrain3DTestDoc class
// Download by http://www.codefans.net

#include "stdafx.h"
#include "Terrain3DTest.h"

#include "Terrain3DTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestDoc

IMPLEMENT_DYNCREATE(CTerrain3DTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CTerrain3DTestDoc, CDocument)
	//{{AFX_MSG_MAP(CTerrain3DTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestDoc construction/destruction

CTerrain3DTestDoc::CTerrain3DTestDoc()
{
	// TODO: add one-time construction code here

}

CTerrain3DTestDoc::~CTerrain3DTestDoc()
{
}

BOOL CTerrain3DTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestDoc serialization

void CTerrain3DTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestDoc diagnostics

#ifdef _DEBUG
void CTerrain3DTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTerrain3DTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTerrain3DTestDoc commands
