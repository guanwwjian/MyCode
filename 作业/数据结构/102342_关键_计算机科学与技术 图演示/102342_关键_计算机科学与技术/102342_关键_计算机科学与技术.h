// 102342_�ؼ�_�������ѧ�뼼��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy102342_�ؼ�_�������ѧ�뼼��App:
// �йش����ʵ�֣������ 102342_�ؼ�_�������ѧ�뼼��.cpp
//

class CMy102342_�ؼ�_�������ѧ�뼼��App : public CWinApp
{
public:
	CMy102342_�ؼ�_�������ѧ�뼼��App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy102342_�ؼ�_�������ѧ�뼼��App theApp;