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
};
leaf a[10001];
bool b[10001];

class bitree
{
public:
	leaf t;	
	int dep,le,sum;
	ele tt;
	static void show(leaf p)
	{
		cout<<p->d;		
	}
	void error()
	{
		cout<<"������������"<<endl;
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
				if (ta->r)
				{
					l++;
					a[l]=ta->r;b[l]=true;
				}
				if (ta->l)
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
				if (ta->r)
				{
					l++;
					a[l]=ta->r;b[l]=true;
				}
				l++;
				a[l]=ta;b[l]=false;
				if (ta->l)
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
				if (ta->r)
				{
					l++;
					a[l]=ta->r;b[l]=true;
				}
				if (ta->l)
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
			if (ta->l) 
			{
				a[r]=ta->l;
				r++;
			}
			if (ta->r)
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
		cout<<"������:�����뵱ǰ�ڵ��Ƿ����(0��ʾ������,����������ʾ����):";
		cin>>x;
		if (x)
		{
			p=new leafnode;
			sum++;
			if (de>dep) dep=de;
			if (fa)
			{
				p->f=fa;
				if (left) fa->l=p;
				else fa->r=p;
			}
			else t=p;
			cout<<"�����뵱ǰ�ڵ������ֵ:";
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
				if (left) fa->l=NULL;
				else fa->r=NULL; 
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
};
void main()
{
	bitree a;
	cout<<"�����������Ϊ��";
	a.ftts();
	cout<<endl;
	cout<<"�����������Ϊ��";
	a.mtts();
	cout<<endl;
	cout<<"�����������Ϊ��";
	a.ltts();
	cout<<endl;
	cout<<"��α�������Ϊ��";
	a.btts();
	cout<<endl;
}