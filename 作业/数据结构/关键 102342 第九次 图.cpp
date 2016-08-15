#include<iostream>
using namespace std;
/*struct szlbnode;
typedef szlbnode* szlb;
struct szlbnode
{
	int d,x,y;
	szlb t,b,l,r;
};
class matrix
{
		
};*/
class pic
{
	int n,a[10001];
 	int ma[101][101];
	int ta[101][101],tb[101][101];
public:
	void creat()
	{
		n=0;
		int m=0,f,t,l;
		int i,j;
		for (i=0;i<=100;i++)
			for (j=0;j<=100;j++)
			{
				ma[i][j]=0;
				ta[i][j]=0;
				tb[i][j]=0;
			}
		cout<<"请输入节点个数n(0----100):";
		cin>>n;
		cout<<"请输入边的条数m(0----n*(n-1))";
		cin>>m;
		for (i=1;i<=m;i++)
		{
			cout<<"请输入3个整数f t l分别表示第"<<i<<"条边的弧尾、弧头和长度：";
			cin>>f>>t>>l;
			ma[f][t]=l;
			ta[f][0]++;
			ta[f][ta[f][0]]=t;
			tb[f][ta[f][0]]=l;
		}
	}
	pic()
	{
		creat();
	}
	void showma()
	{
		cout<<"邻接矩阵为："<<endl;
		int i,j;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				cout<<ma[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void showta()
	{
		cout<<"邻接表为："<<endl;
		int i,j;
		for (i=1;i<=n;i++)
		{
			cout<<i;
			for (j=1;j<=ta[i][0];j++)
			{
				cout<<"-->"<<ta[i][j]<<"("<<tb[i][j]<<")";
			}
			cout<<endl;
		}
	}
	void dtt(int x)
	{
		bool vis[101];
		int l=1,tt,i;
		for (i=1;i<=n;i++)
		{
			vis[i]=false;
		}
		a[1]=x;
		while (l>0)
		{
			tt=a[l];
			l--;
			if (!vis[tt])
			{
				vis[tt]=true;
				cout<<tt<<" ";
				for (i=1;i<=ta[tt][0];i++)
				{
					l++;
					a[l]=ta[tt][i];
				}
			}
		}
		cout<<endl;
	}
	void btt(int x)
	{
		bool vis[101];
		int l=1,r=2,tt,i;
		for (i=1;i<=n;i++)
		{
			vis[i]=false;
		}
		a[1]=x;
		while (l<r)
		{
			tt=a[l];
			l++;
			if (!vis[tt])
			{
				vis[tt]=true;
				cout<<tt<<" ";
				for (i=1;i<=ta[tt][0];i++)
				{
					r++;
					a[r]=ta[tt][i];
				}
			}
		}
		cout<<endl;
	}
};
void main()
{
	pic a;
	int x;
	cout<<"请输入遍历起始节点x(1-n)：";
	cin>>x;
	a.showta();
	a.showma();
	cout<<"深度优先遍历序列为："<<endl;
	a.dtt(x);
	cout<<"广度有限遍历序列为："<<endl;
	a.btt(x);
}