// shoushishibie.cpp: ����Ŀ�ļ���
#pragma once
#include "stdafx.h"
#include "Form1.h"

using namespace shoushishibie;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Form1 ^form1=gcnew Form1();
	Application::Run(form1);
	return 0;
}
