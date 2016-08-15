// 102342_关键_计算机科学与技术.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMy102342_关键_计算机科学与技术App:
// 有关此类的实现，请参阅 102342_关键_计算机科学与技术.cpp
//

class CMy102342_关键_计算机科学与技术App : public CWinApp
{
public:
	CMy102342_关键_计算机科学与技术App();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy102342_关键_计算机科学与技术App theApp;