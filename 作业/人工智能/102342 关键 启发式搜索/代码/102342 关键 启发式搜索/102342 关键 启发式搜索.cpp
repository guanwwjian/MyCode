// 102342 关键 启发式搜索.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<functional>
#include<queue>
#include<cmath>
using namespace std;
int loc[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int goal[3][3]={{1,2,3},{8,0,4},{7,6,5}};
int xx[9]={1,0,0,0,1,2,2,2,1};
int yy[9]={1,0,1,2,2,2,1,0,0};
int time=0,t1=0;;
bool fit(int x,int y,int l[2])
{
	return ((0<=x+l[0])&&(x+l[0]<=2)&&(0<=y+l[1])&&(y+l[1]<=2));
}
class Node
{
public:
	int o[3][3];
	int g,zx,zy,hh,c;
	Node(int a[3][3])
	{
		g=0;hh=-1;
		int i,j;
		for (i=0;i<=2;i++)
			for (j=0;j<=2;j++)
			{
				o[i][j]=a[i][j];
				if (a[i][j]==0)
				{
					zx=i;
					zy=j;
				}
			}
		c=cantor();
		hh=h();
	}
	Node(Node *old,int l[2])
	{
		if (fit(old->zx,old->zy,l))
		{
			int i,j;
			for (i=0;i<=2;i++)
				for (j=0;j<=2;j++)
				{
					o[i][j]=old->o[i][j];
				}
			zx=old->zx+l[0];
			zy=old->zy+l[1];
			o[zx][zy]=old->o[old->zx][old->zy];
			o[old->zx][old->zy]=old->o[zx][zy];
			g=old->g+1;
			hh=-1;
			c=cantor();
			hh=h();
		}
		else 
		{
			cout<<"发生错误！"<<endl;
			exit(1);
		}
	}

	int h()
	{
		int ans=0;
		int i,j;
		for (i=0;i<=2;i++)
			for (j=0;j<=2;j++)
				ans=ans+abs(xx[o[i][j]]-i)+abs(yy[o[i][j]]-j);
		return ans;
	}
	int f()
	{
		return g+hh;
	}
	bool isans()
	{
		int i,j;
		for (i=0;i<=2;i++)
			for (j=0;j<=2;j++)
				if (o[i][j]!=goal[i][j]) return false;
		return true;

	}
	int oo(int x)
	{
		return o[x/3][x%3];
	}
	int cantor()
	{
		int i,j,ans=0;;
		int jie[9];
		jie[0]=1;
		for (i=1;i<=8;i++)
			jie[i]=jie[i-1]*i;
		for (i=0;i<=8;i++)
			for (j=i+1;j<=8;j++)
			{
				if (oo(i)>oo(j)) ans+=jie[8-i];
			}
		return ans;
	}
	int ni()
	{
		int i,j,ans=0;;
		for (i=0;i<=8;i++)
			for (j=i+1;j<=8;j++)
			if ((oo(i)!=0)&&(oo(j)!=0))
			{
				if (oo(i)>oo(j)) ans++;
			}
		return ans;
	}
	/*bool operator <(Node &x)
	{
		return this->f<x.f
	}
	bool operator >(Node &x)
	{
		return this->f>x.f
	}
	bool operator ==(Node &x)
	{
		return this->f==x.f
	}
	bool operator <=(Node &x)
	{
		return this->f<=x.f
	}
	bool operator >=(Node &x)
	{
		return this->f>=x.f
	}*/
};
struct cmp
{
	bool operator ()(Node *a,Node *b)
	{
		return (a->f()>b->f());
	}
};
int abfs(int a[3][3])
{
	int i,j,k;
	priority_queue<Node*,vector<Node*>,cmp> pq;
	Node *p=new Node(a),*t;
	if (p->ni()%2==0)
	{
		delete p;
		return -1;
	}
	pq.push(p);
	bool vis[370000]={false};
	while (!(pq.empty()))
	{
		time++;
		t=pq.top();
		pq.pop();
		if (t->isans())
		{
			int ans=t->f();
			delete t;
			while (!(pq.empty())) 
			{
				delete pq.top();
				pq.pop();
			}
			return ans;
		}
		for (i=0;i<=3;i++)
		{
			if (fit(t->zx,t->zy,loc[i]))
			{
				p=new Node(t,loc[i]);
				if (!vis[p->c])
				{
					vis[p->c]=true;
					pq.push(p);
				}
				else delete p;

			}
		}
		delete t;
	}
	return -1;
}
int b[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
void test(int d)
{
	if (d>8)
	{
		int a[3][3],i;
		for (i=0;i<=8;i++)
			a[b[i]/3][b[i]%3]=i;
		abfs(a);
		t1++;
		if (t1%1000==0) cout<<"前"<<t1<<"组 共搜索"<<time<<"次"<<" 平均每组"<<time/t1<<"次"<<endl;
	}
	else 
	{
		int i;
		for (i=0;i<=8;i++)
			if (b[i]<0) 
			{
				b[i]=d;
				test(d+1);
				b[i]=-1;
			}
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	
	
	int a[3][3],i,j,n;
	while (true)
	{
		cout<<"0.算法说明\n1.算法功能测试\n2.算法性能测试\n其余整数退出\n请输入编号：";
		cin>>n;
		if (n==1)
		{
			cout<<"请输入3行3列的8数码问题状态(0表示空格,数字为0-8且不重复)"<<endl;
			for (i=0;i<=2;i++)
				for(j=0;j<=2;j++)
				{
					cin>>a[i][j];
				}
			int ans=abfs(a);
			if(ans>=0)cout<<"有解，最少步数："<<ans<<endl;
			else cout<<"无解"<<endl;
		}
		else if (n==2)
		{
			time=0;t1=0;
			test(0);
			cout<<"共"<<t1<<"组 共搜索"<<time<<"次 平均每组"<<time/t1<<"次"<<endl;
		}
		else if (n==0)
		{
			cout<<"本程序用A*算法计算8数码问题的最小步数，估价函数h(x)采用各数字到其正确位置的距离，利用康拓展开实现了防止同一状态多次访问的优化。性能估计部分计算0-8的全排列各初始状态的总搜索次数。\n目标状态：\n1 2 3\n8 0 4\n7 6 5"<<endl;
		}
		else
		{
			break;
		}
		cout<<endl;
	}
	return 0;
}

