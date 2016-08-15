// Creatmyfilesystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyFileSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x=2048;
	cout<<"请输入代创建虚拟磁盘的盘块数：";
	cin>>x;
	MyFileSystem fs;
	fs.CreatMyDisk("myDisk.img",x);
	fs.close();
	return 0;
}

