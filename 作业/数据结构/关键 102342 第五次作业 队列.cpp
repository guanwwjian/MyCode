#include<iostream>
using namespace std;
typedef int ele;
void read(ele& tt)
{
		cin>>tt;
}
void write(ele x)
{
		cout<<x;
}
void writeln(ele x)
{
	write(x);
	cout<<endl;
}
class sortstruct
{
public:
	virtual int len() =0;
	virtual void changel(int x) =0;
	virtual void insert(ele x,int y) =0;
	virtual void addl(ele x) =0;
	virtual void addr(ele x) =0;
	virtual void creat(int n)=0;
	virtual void del(int x) =0;
	virtual ele data(int x) =0;
	virtual void destroy() =0;
	virtual void show() =0;
	virtual void chd(ele x,int y) =0;
};
class table:sortstruct
{
protected:
	ele *elem;
	int length;
	int listsize;
public:
	int len()
	{
		return length;
	}
	void changel(int x)
	{
		ele *tt;
		int i,ol=length;
		length=x;
		if (length>listsize) listsize*=2;
		else if (length<(listsize/2)) listsize=(listsize)/2;
		else return;
		if (length==0) listsize=1;
		tt=(ele*)realloc(elem,listsize*sizeof(ele));
		if (!tt) 
		{
			listsize=x;
			tt=(ele*)realloc(elem,listsize*sizeof(ele));
		}
		if (!tt) 
		{
			cout<<"对不起内存空间不足";
			system("pause");
			exit(-1);
		}
		elem=tt;
		for (i=ol;i<=listsize-1;i++) elem[i]=0;
		 
	}
	void insert(ele x,int y)
	{
		int i,pl=length;
		changel(length+1);
		for(i=pl;i>=y;i--)
		{
			elem[i+1-1]=elem[i-1];
		}
		elem[y-1]=x;
	}
	void addl(ele x)
	{
		insert(x,1);
	}
	void addr(ele x)
	{
		insert(x,length+1);
	}

	void creat(int n)
	{
		int i;
		ele tt;
		for (i=1;i<=n;i++)
		{
			read(tt);
			addr(tt);
		}
	}
	table()
	{
		length=0;
		listsize=1;
		elem=(ele*)malloc(listsize*sizeof(ele));
		elem[0]=0;

	}
	table(int n)
	{
		length=n;
		listsize=n;
		elem=(ele*)malloc(listsize*sizeof(ele));
		elem[0]=0;
		//creat(n);
	}
	void del(int x)
	{
		int i;
		for (i=x;i<=length-1;i++)
		{
			elem[i-1]=elem[i+1-1];
		}
		changel(length-1);
	}
	ele data(int x)
	{
		if ((1<=x)&&(x<=length)) return elem[x-1];
		return 0;
	}

	void destroy()
	{
		changel(0);
	}
	void  show()
	{
		int i;
		write(elem[0]);
		for (i=2;i<=length;i++)
		{
			cout<<" ";
			write(elem[i-1]);
		}
		cout<<endl;
	}
	void chd(ele x,int y)
	{
		if (y>length) changel(y);
		elem[y-1]=x;
	}
	void raint()
	{
		char c;
		changel(1);
		cin>>c;
		while (c!='/n')
		{
			if (c!=' ') chd(data(len())*10+(int)(c-'0'),len());
			else changel(len()+1);
			cin>>c;
		}
	}
};
struct linkele
{
	ele d;
	linkele *l,*r;
};
class linker:sortstruct
{
protected:
	linkele *head;
	int length;
public:
	linker()
	{
		head=new linkele;
		if (!head) exit(-1);
		head->r=head;
		head->l=head;
		length=0;
	}
	int len()
	{
		return length;
	}
	linkele *findx(int x)
	{
		linkele *ans=head;
		int i;
		if (x<=length/2)
		{
			for (i=1;i<=x;i++) 	ans=ans->r;
		}
		else 
		{
			for (i=length;i>=x;i--) ans=ans->l;
		}
		return ans;
	}
	void insert(ele x,int y)
	{
		linkele *p=findx(y);
		linkele *n=new linkele;
		n->d=x;
		n->l=p->l;n->r=p;n->l->r=n;p->l=n;
		length++;
	}
	void addl(ele x)
	{
		insert(x,1);
	}
	void addr(ele x)
	{
		insert(x,length+1);
	}
	void del(int x)
	{
		linkele *p=findx(x);
		p->l->r=p->r;p->r->l=p->l;
		delete p;
		length--;
	}
	void changel(int x)
	{
		while (x>length) addr(0);
		while (x<length) del(length);
	}
	void destroy()
	{
		changel(0);
	}
	void creat(int n)
	{
		int i;
		ele tt;
		destroy();
		for (i=1;i<=n;i++)
		{
			read(tt);
			addr(tt);
		}
	}
	linker(int n)
	{
		head=new linkele;
		if (!head) exit(-1);
		head->r=head;
		head->l=head;
		length=0;
		creat(n);		
	}
	ele data(int x)
	{
		return findx(x)->d;
	}
	void show()
	{
		linkele *p=head->r;
		bool first=true;
		while (p!=head)
		{
			if (first) first=false;
			else cout<<"<->";
			write(p->d);
		}
		
	}
	void chd(ele x,int y)
	{
		if (y>length) changel(y);
		findx(y)->d=x;
	}
	void raint()
	{
		char c;
		changel(1);
		cin>>c;
		while (c!='/n')
		{
			if (c!=' ') chd(data(len())*10+(int)(c-'0'),len());
			else changel(len()+1);
			cin>>c;
		}
	}
};
class xdui:table
{
	int l,r;
public:
	xdui(int n):table(n)
	{
		l=0;r=0;
	}
	int mlr(int x)
	{
		int ll=len();
		return (x+ll)%ll;
	}
	int nlr(int &x)
	{
		x=mlr(x+1);
		return x;
	}
	void enterx(ele x)
	{
		if (mlr(r+1)!=mlr(l))
		{
			chd(x,mlr(r)+1);
			nlr(r);
		}
		else
		{
			cout<<"队列已满"<<endl;
			exit(-1);
		}
	}
	bool ept()
	{
		return mlr(l)==mlr(r);
	}
	ele quitd()
	{
		if (!ept())
		{
			ele ans=data(mlr(l)+1);
			nlr(l);
			return ans;
		}
		else 
		{
			cout<<"队列已空"<<endl;
			exit(-2);
		}
	}

};
class ldui:linker
{
public:
	ldui():linker(){}
	bool ept()
	{
		return length==0;
	}
	void enterx(ele x)
	{
		addl(x);
	}
	ele quitd()
	{
		if (!ept())
		{
			ele ans=data(len());
			del(len());
			return ans;
		}
		else 
		{
			cout<<"队列已空"<<endl;
			exit(-2);
		}
	}


};
void main()
{
	cout<<"循环队列：所能容纳的最大元素数n:";
	int n,tt,ta;
	cin>>n;
	xdui a(n+1);
	cout<<"请输入若干个整数表示要入队的数"<<endl;
	char c;
	tt=0;
	c=getchar();
	c=getchar();
	while ((c!='\r')&&(c!='\n'))
	{
		if (c!=' ') tt=tt*10+(int)(c-'0');
		else
		{
			a.enterx(tt);
			tt=0;
		}

		c=getchar();
	}
	a.enterx(tt);
	cout<<"出对序列：";
	while (!a.ept())
	{
		cout<<a.quitd()<<" ";
	}
	cout<<endl;
	cout<<"链队列：请输入若干个整数表示要入队的数"<<endl;
	ldui b;
	tt=0;
	c=getchar();
	while ((c!='\r')&&(c!='\n'))
	{
		if (c!=' ') tt=tt*10+(int)(c-'0');
		else
		{
			b.enterx(tt);
			tt=0;
		}
		c=getchar();
	}
	b.enterx(tt);
	cout<<"出对序列：";
	while (!b.ept())
	{
		cout<<b.quitd()<<" ";
	}
	cout<<endl;


}

