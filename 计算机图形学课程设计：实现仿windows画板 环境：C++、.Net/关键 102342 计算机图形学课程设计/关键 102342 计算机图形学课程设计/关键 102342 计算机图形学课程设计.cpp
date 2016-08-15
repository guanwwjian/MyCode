// 关键 102342 计算机图形学课程设计.cpp: 主项目文件。

#include "stdafx.h"
#include "Form1.h"

using namespace 关键102342计算机图形学课程设计;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 创建主窗口并运行它
	Application::Run(gcnew Form1());
	return 0;
}
