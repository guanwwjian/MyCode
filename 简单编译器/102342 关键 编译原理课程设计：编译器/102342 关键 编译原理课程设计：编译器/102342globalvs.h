#pragma once
string itostr(int x)
{
	string ans;
	stringstream s;
	s<<x;
	s>>ans;
	return ans;
}
void error()
{
	exit(1);
}
VarTable vt;
MidCodeManager mcm;
ofstream mesout;
void masmcode(_TCHAR* file)
	{
		ofstream ofs(file);
		vt.masmdseg(ofs);
		mcm.masmcseg(ofs);
		ofs.close();
	}