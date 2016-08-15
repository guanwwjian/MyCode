// mycmd.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include"MyFileSystem.h"
using namespace std;
#define maxlen 2048
#define diskname "myDisk.img"
MyFileSystem f(diskname);
string route(string dir,string file)
{
		string td;
		if (file[0]=='/') td=file;
		else if (file==".") td=dir;
		else if (file=="..")
		{
			if (dir=="/") td=dir;
			else
			{
				
				td=dir.substr(0,dir.find_last_of("/"));
				if (td=="") td="/";
			}
		}
		else 
		{	if (dir=="/") td=dir+file;
			else td=dir+"/"+file;
		}
		return td;
}
bool fin(const char *c1,const char *c2)
{
	fstream fs(c2,ios::in|ios::binary);
	//fs.open(c2,ios::in);
	if (!fs.is_open()) return false;
	if (f.fopen(c1,f.om_out|f.om_trunc)<0) f.fcreat(c1,0,f.om_out|f.om_trunc);
	char tt[256],ch;
	int i=-1;
	fs.seekg(0,ios::beg);
	fs.read((char*)&ch,sizeof(ch));
	while (!fs.eof())
	{
		i++;
		tt[i%256]=ch;
		if (i%256==255)
		{
			f.fwrite(tt,sizeof(tt));
		}
		fs.read((char*)&ch,sizeof(ch));
	}
	if (i%256!=255)
	{
		f.fwrite(tt,i%256+1);
	}
	fs.close();
	f.fclose();
	return true;
}
bool fout(const char *c1,const char *c2)
{
	if (f.fopen(c1,f.om_in)<0) return false;
	if (f.myi.i_isdir) return false;
	fstream fs;
	fs.open(c2,ios::out|ios::trunc|ios::binary);
	char tt[256],ch;
	int i=-1,rest,size;
	f.seekg(0);
	while (!f.eof())
	{
		rest=f.myi.i_size-f.get;
		size=sizeof(tt);
		if (rest<sizeof(tt)) size=rest; 
		f.fread(tt,size);
		fs.write(tt,size);
	}
	fs.close();
	f.fclose();
	return true;

}
int _tmain(int argc, _TCHAR* argv[])
{
	string dir,com[256],file,td,st;
	char c[maxlen];
	int p,i,j,k;
	dir="/";
	do
	{
		cout<<dir<<" $:";
		p=-1;
		while ((cin.peek()!='\n')||(p==-1))
		{
			p++;
			cin>>com[p];
		}
		

		if (com[0]=="cd") 
		{
			if (p==1)
			{
				td=route(dir,com[1]);
				//strcpy(c,td.c_str());
				f.fopen(td.c_str());
				if (f.myi.i_isdir) dir=td;
				else cout<<"找不到指定文件或指定文件不是文件夹。"<<endl;
			}
			else cout<<"参数错误。"<<endl;
		}
		else if (com[0]=="ls")
		{
			if (p==0)
			{
				f.fopen(dir.c_str());
				DirectoryEntry di;
				int n=(f.myi.i_size/sizeof(di)-1);
				for (i=0;i<=n;i++)
				{
					f.iread((char*)&di,sizeof(di),i*sizeof(di));
					cout<<di.m_name<<endl;
				}
			}
			else cout<<"参数错误。"<<endl;
		}
		else if (com[0]=="in")
		{
			if (p==1)
			{
				td=route(dir,com[1].c_str());
				if (fin(td.c_str(),com[1].c_str())) cout<<"执行成功。"<<endl;
				else cout<<"执行失败。"<<endl;
			}
			else if (p==2)
			{
				td=route(dir,com[2].c_str());
				if (fin(td.c_str(),com[1].c_str())) cout<<"执行成功。"<<endl;
				else cout<<"执行失败。"<<endl;
			}
			else cout<<"参数错误。"<<endl;
		}
		else if (com[0]=="out")
		{
			if (p==1)
			{
				td=route(dir,com[1].c_str());
				if (fout(td.c_str(),com[1].c_str())) cout<<"执行成功。"<<endl;
				else cout<<"执行失败。"<<endl;
			}
			else if (p==2)
			{
				td=route(dir,com[1].c_str());
				if (fout(td.c_str(),com[2].c_str())) cout<<"执行成功。"<<endl;
				else cout<<"执行失败。"<<endl;
			}
			else cout<<"参数错误。"<<endl;

		}
		else if (com[0]=="md")
		{
			td=route(dir,com[1]);
			f.fcreat(td.c_str(),1);
			f.myi.i_isdir=1;
			f.fclose();
		}
		else if (com[0]=="del")
		{
			td=route(dir,com[1]);
			f.fdelete(td.c_str());
		}
		else if ((com[0]!="exit")&&(p>=0))
		{
			/*file=dir+"\\"+com[0];
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory( &pi, sizeof(pi) );
			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			if(CreateProcess(file.c_str(), "", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
			 {
				 CloseHandle( pi.hProcess );
				 CloseHandle( pi.hThread );
			}
			else 
			{
				HANDLE hProcess = GetCurrentProcess();
				TerminateProcess(hProcess,0);
			}*/
			system("md mytemp");
			td=route(dir,com[1].c_str());
			st="mytemp\\"+com[1];
			if (fout(td.c_str(),st.c_str())) system(st.c_str());
			else cout<<"执行失败。"<<endl;
			system("rd /s/q mytemp");
		}
		f.close();
		f.open(diskname);
	}
	while (com[0]!="exit");
	f.close();
	
	return 0;
}

