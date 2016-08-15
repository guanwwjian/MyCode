#include<iostream>
using namespace std;
int bifind(int a[],int len,int x)
{
	int l=0,r=len-1;
	while (l<r-1)
	{
		if (a[(l+r)/2]<x) l=(l+r)/2;
		else r=(l+r)/2;
	}
	if (a[l]==x) return l;
	else if (a[r]==x) return r;
	else return -1;
}
struct leafnode;
typedef leafnode *leaf;
struct leafnode
{
	leaf l,r,f;
	int d;
};
class bftree
{
	leaf t;
public:
	bftree()
	{
		t=NULL;
	}
	leaf find(int x)
	{
		leaf p=t;
		while (p)
		{
			if (x<p->d) p=p->l;
			else if (p->d<x) p=p->r;
			else return p;
		}
		return NULL;
	}
	void insert(int x)
	{
		if (t==NULL)
		{
			t=new leafnode;
			t->l=t->r=NULL;
			t->d=x;
			t->f=NULL;
		}
		else
		{
			leaf p=t,f=NULL;
			while (p)
			{
				f=p;
				if (x<p->d) p=p->l;
				else if (p->d<x) p=p->r;
				else
				{
					cout<<"由于重复插入，插入"<<x<<"操作被忽略."<<endl;
					return;
				}
			}
			p=new leafnode;
			p->f=f;
			p->l=p->r=NULL;
			p->d=x;
			if (x<f->d) f->l=p;
			else f->r=p;
		}
	}
	leaf lchild(leaf p)
	{
		leaf tt=p;
		while (tt->l) tt=tt->l;
		return tt;
	}
	void dele(leaf p)
	{

			if ((p->l==NULL)&&(p->r==NULL)) 
			{
				if (p==t) 
				{
					t=NULL;
				}
				else 
				{
					if (p->d<p->f->d) p->f->l=NULL;
					else p->f->r=NULL;
				}
				delete p;
			}
			else if (p->l==NULL)
			{
				if (p==t)
				{
					t=p->r;
				}
				else
				{
					if (p->d<p->f->d) p->f->l=p->r;
					else p->f->r=p->r;
				}
				p->r->f=p->f;
				delete p;
			}
			else if (p->r==NULL)
			{
				if (p==t)
				{
					t=p->l;
				}
				else
				{
					if (p->d<p->f->d) p->f->l=p->l;
					else p->f->r=p->l;
				}
				p->l->f=p->f;
				delete p;
			}
			else
			{
				leaf rlc=lchild(p->r);
				p->d=rlc->d;
				dele(rlc);
			}
	}
	void del(int x)
	{
		leaf p=find(x);
		if (p==NULL) 
		{
			cout<<"节点不存在,删除"<<x<<"失败."<<endl;
			return;
		}
		else
		{
			dele(p);
		}
	}
};
void main()
{
	int a[100001],n,m,x,y,i;
	cout<<"二份查找测试:请输入一个整数n表示待查找序列元素个数:";
	cin>>n;
	cout<<"请按照从小到大的顺序输入n个整数表示待查序列:"<<endl;
	for (i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	cout<<"情输入查找元素的个数m:";
	cin>>m;
	cout<<"请输入m个整数表示查找元素:"<<endl;
	for (i=0;i<=m-1;i++)
	{
		cin>>x;
		cout<<bifind(a,n,x)<<" ";
	}
	cout<<endl;
	bftree b;
	cout<<"查找树测试:请输入操作个数m:";
	cin>>m;
	cout<<"以下m行每行两个整数x,y分别表示操作类型（-1：删除 0：查找 1：插入 其他忽略）和操作数"<<endl;
	for (i=0;i<=m-1;i++)
	{
		cin>>x>>y;
		if (x==-1) b.del(y);
		else if (x==0) 
		{
			if (b.find(y)) cout<<"查找成功."<<endl;
			else cout<<"查找失败."<<endl;
		}
		else if (x==1) b.insert(y);
	}

	

}