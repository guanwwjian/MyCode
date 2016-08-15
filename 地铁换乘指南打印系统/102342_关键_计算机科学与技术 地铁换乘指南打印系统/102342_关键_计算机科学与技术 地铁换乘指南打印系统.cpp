// 102342_关键_计算机科学与技术 地铁换乘指南打印系统.cpp: 主项目文件。

#include "stdafx.h"
#include "Form1.h"
#include "Form2.h"

using namespace My102342;

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
 /*System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				Form2 ^f2= gcnew Form2();
				f2->ShowDialog();
			 }*/
