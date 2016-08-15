// shoushishibie.cpp: 主项目文件。
#pragma once
#include "stdafx.h"
#include "Form1.h"

using namespace shoushishibie;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 创建主窗口并运行它
	Form1 ^form1=gcnew Form1();
	Application::Run(form1);
	return 0;
}
