// Creatmyfilesystem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyFileSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x=2048;
	cout<<"�����������������̵��̿�����";
	cin>>x;
	MyFileSystem fs;
	fs.CreatMyDisk("myDisk.img",x);
	fs.close();
	return 0;
}

