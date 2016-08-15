#include<iostream>
#include<string>
using namespace std;
typedef int ele;
struct leafnode;
typedef leafnode *leaf;
struct leafnode
{
	ele d;
	leaf f,l,r;
	bool ltag,rtag;
};
leaf a[10001];
bool b[10001];



class bitree
{
public:
	leaf t;	
	static leaf last;
	int dep,le,sum;
	ele tt;

	static void show(leaf p)
	{
		cout<<p->d;		
	}
	static void xsh(leaf p)
	{
		if (last)
		{
			if (last->rtag) last->r=p;
			if (p->ltag) p->l=last;
		}
		last=p;
	}
	void error()
	{
		cout<<"您的输入有误"<<endl;
		exit(-1);
	}

	leaf root()
	{
		return t;
	}
	leaf fa(leaf x)
	{
		return x->f;
	}
	leaf lchild(leaf x)
	{
		leaf p=x;
		while (p->l) p=p->l;
		return p;
	}
	leaf rbrother(leaf x)
	{	
		return x->f->r;
	}
/*	void insertl(ele x,char c[])
	{
		int len=strlen(c),i;
		leaf p=t,q=NULL;
		if ((c[0]!='T')&&(c[0]!='t')) error();
		for (i=1;i<=len-2;i++)
		{
			if !(p) error();
			if ((c[i]=='l')||(c[i]=='L')) p=p->l;
			else if ((c[i]=='r')||(c[i]=='R')) p=p->r;
			else error();
		}
		if (len==1) 
		{
			len()
		}
		else if ((c[len-1]=='l')||(c[len-1]=='L')) 
		{

		}
		else if ((c[len-1]=='r')||(c[len-1]=='R'))
		{

		}
		else error();

	}*/

	void ftt(void (*f)(leaf))
	{
		int l=1;
		leaf ta;
		bool tb;
		a[l]=t;b[l]=true;
		while (l>0)
		{
			ta=a[l];tb=b[l];
			l--;
			if (tb)
			{
				if (!ta->rtag)
				{
					l++;
					a[l]=ta->r;b[l]=true;
				}
				if (!ta->ltag)
				{
					l++;
					a[l]=ta->l;b[l]=true;
				}
				l++;
				a[l]=ta;b[l]=false;
			}
			else
			{
				f(ta);
			}
		}
				
	}
	void mtt(void (*f)(leaf p))
	{
		int l=1;
		leaf ta;
		bool tb;
		a[l]=t;b[l]=true;
		while (l>0)
		{
			ta=a[l];tb=b[l];
			l--;
			if (tb)
			{
				if (!ta->rtag)
				{
					l++;
					a[l]=ta->r;b[l]=true;
				}
				l++;
				a[l]=ta;b[l]=false;
				if (!ta->ltag)
				{
					l++;
					a[l]=ta->l;b[l]=true;
				}

			}
			else
			{
				f(ta);
			}
		}
				
	}
	void ltt(void (*f)(leaf p))
	{
		int l=1;
		leaf ta;
		bool tb;
		a[l]=t;b[l]=true;
		while (l>0)
		{
			ta=a[l];tb=b[l];
			l--;
			if (tb)
			{
				l++;
				a[l]=ta;b[l]=false;
				if (!ta->rtag)
				{
					l++;
					a[l]=ta->r;b[l]=true;
				}
				if (!ta->ltag)
				{
					l++;
					a[l]=ta->l;b[l]=true;
				}
			}
			else
			{
				f(ta);
			}
		}
				
	}

	void btt(void (*f)(leaf p))
	{
		int l=0,r=1,mo=10000;
		a[0]=t;
		leaf ta;
		while (l%mo!=r%mo)
		{
			ta=a[l];
			l=(l+1)%mo;
			if (!ta->ltag) 
			{
				a[r]=ta->l;
				r++;
			}
			if (!ta->rtag)
			{
				a[r]=ta->r;
				r++;
			}
			f(ta);
		}
	}

	void ftts()
	{
		ftt(show);
	}
	void mtts()
	{
		mtt(show);
	}
	void ltts()
	{
		ltt(show);
	}
	void btts()
	{
		btt(show);
	}
	void ctree(leaf p,leaf fa,bool left,int de)
	{
		int x,y;
		cout<<"先序建树:请输入当前节点是否存在(0表示不存在,其他整数表示存在):";
		cin>>x;
		if (x)
		{
			p=new leafnode;
			sum++;
			if (de>dep) dep=de;
			if (fa)
			{
				p->f=fa;
				if (left)
				{
					fa->l=p;
					fa->ltag=false;
				}
				else 
				{
					fa->r=p;
					fa->rtag=false;
				}
			}
			else t=p;
			cout<<"请输入当前节点的数据值:";
			cin>>y;
			p->d=y;
			ctree(p->l,p,true,de+1);
			ctree(p->r,p,false,de+1);
			if ((p->l==NULL)&&(p->r==NULL)) le++;
		}
		else
		{
			if (fa) 
			{
				if (left) 
				{
					fa->l=NULL;
					fa->ltag=true;
				}
				else 
				{
					fa->r=NULL;
					fa->rtag=true;
				}
			}	
		}
	}
	/*void creattree()
	{
		ctree(t,NULL,true,1);
	}*/
	bitree()
	{
		dep=0;le=0;sum=0;
		ctree(t,NULL,true,1);
	}
	int numle()
	{
		return le;
	}
	int numsum()
	{
		return sum;
	}
	int numdep()
	{
		return dep;
	}
	void fxsh()
	{
		ftt(xsh);
	}
	void mxsh()
	{
		mtt(xsh);
	}
	void lxsh()
	{
		ltt(xsh);
	}
	leaf mlchild(leaf p)
	{
		leaf tt=p;
		while (!(tt->ltag)) 
			tt=tt->l;
		return tt;
	}
	void xsmtt(void (*f)(leaf p))
	{
		leaf p=mlchild(t);		
		while (p)
		{
			f(p);
			if (p->rtag) p=p->r;
			else p=mlchild(p->r);
		}
	}
	void xsmtts()
	{
		xsmtt(show);
	}
	void xsltt(void (*f)(leaf p))
	{
		leaf p=mlchild(t);
		while (p)
		{
			f(p);
			if (p==t) p=NULL;
			else if (p->rtag) p=p->r;
			else 
			{
				if ((p==p->f->l)&&(!(p->f->rtag))) p=mlchild(p->f->r);
				else p=p->f;
			}
		}

	}
	void xsltts()
	{
		xsltt(show);
	}
};
leaf bitree::last=NULL;
void main()
{
	bitree a;
	cout<<"先序遍历序列为：";
	a.ftts();
	cout<<endl;
	cout<<"中序遍历序列为：";
	a.mtts();
	cout<<endl;
	cout<<"线索中序遍历序列为：";
	a.mxsh();
	a.xsmtts();
	cout<<endl;
	cout<<"后序遍历序列为：";
	a.ltts();
	cout<<endl;
	cout<<"线索后序遍历序列为：";
	a.lxsh();
	a.xsltts();
	cout<<endl;
	cout<<"层次遍历序列为：";
	a.btts();
	cout<<endl;
}