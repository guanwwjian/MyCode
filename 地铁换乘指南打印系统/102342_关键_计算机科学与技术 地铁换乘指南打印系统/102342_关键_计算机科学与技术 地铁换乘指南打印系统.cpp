// 102342_�ؼ�_�������ѧ�뼼�� ��������ָ�ϴ�ӡϵͳ.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "Form1.h"
#include "Form2.h"

using namespace My102342;

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
 /*System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				Form2 ^f2= gcnew Form2();
				f2->ShowDialog();
			 }*/
