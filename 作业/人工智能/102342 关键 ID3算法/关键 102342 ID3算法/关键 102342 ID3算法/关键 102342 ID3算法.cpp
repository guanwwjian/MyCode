// �ؼ� 102342 ID3�㷨.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "Form1.h"

using namespace �ؼ�102342ID3�㷨;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew Form1());
	return 0;
}
