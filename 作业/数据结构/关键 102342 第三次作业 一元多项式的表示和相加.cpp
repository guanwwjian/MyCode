
#include "stdlib.h"
#include <iostream>

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
class table{
protected:
	ele *elem;
	ele length;
	ele listsize;
public:
	int len()
	{
		return length;
	}
	void changel(int x)
	{
		ele *tt;
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
//		free(elem);
		elem=tt;
		 
	}
	void insert(ele x,ele y)
	{
		int i,pl=length;
		changel(length+1);
		for(i=pl;i>=y;i--)
		{
			elem[i+1-1]=elem[i-1];
		}
		elem[y-1]=x;
	}
	void add(ele x)
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
			add(tt);
		}
	}
	table()
	{
		length=0;
		listsize=1;
		elem=(ele*)malloc(listsize*sizeof(ele));

	}
	table(int n)
	{
		length=0;
		listsize=1;
		elem=(ele*)malloc(listsize*sizeof(ele));
		creat(n);
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
	ele const data(int x)
	{
		if ((1<=x)&&(x<=length)) return elem[x-1];
		return 0;
	}

	void destroy()
	{
		changel(0);
	}
	void const show()
	{
		int i;
		for (i=1;i<=length;i++)
		{
			write(elem[i-1]);
			cout<<endl;
		}
	}
	void modi(int x,int y)
	{
		if ((1<=y)&&(y<=length)) elem[y-1]=x;
	}

};
class shi:public table
{
public:
	shi():table(){}
	shi(int n):table(n){}
	void const show()
	{
		int i;
		bool first=true;
		for (i=1;i<=length;i++)
		{
			if (elem[i-1]>0)
			{
				if (!first) cout<<"+";
				write(elem[i-1]);
				cout<<"x^"<<i-1;
				first=false;
			}
			else if (elem[i-1]<0)
			{
				cout<<"-";
				write(-elem[i-1]);
				cout<<"x^"<<i-1;	
				first=false;
			}
		}
		cout<<endl;
		if (first) cout<<0;
	}
	int val(int x)
	{
		int ans=0;
		int i;
		for (i=length;i>=1;i--)
		{
			ans=ans*x+elem[i-1];
		}
		return ans;
	}
};
void addab(shi &a,shi &b,shi &c)
{
	c.destroy();
	int la,lb,lm;
	la=a.len();
	lb=b.len();
	lm=la;
	if (lb<lm) lm=lb;
	int i;
	for (i=1;i<=lm;i++) c.add(a.data(i)+b.data(i));
	for (i=lm+1;i<=la;i++) c.add(a.data(i));
	for (i=lm+1;i<=lb;i++) c.add(b.data(i));
}
void subab(shi &a,shi &b,shi &c)
{
	c.destroy();
	int la,lb,lm;
	la=a.len();
	lb=b.len();
	lm=la;
	if (lb<lm) lm=lb;
	int i;
	for (i=1;i<=lm;i++) c.add(a.data(i)-b.data(i));
	for (i=lm+1;i<=la;i++) c.add(a.data(i));
	for (i=lm+1;i<=lb;i++) c.add(-b.data(i));

}

void main()
{
	int m,n,x;
	cout<<"建立多项式a:请输入x最高次数n"<<endl;
	cin>>n;
	cout<<"请依次输入n+1个整数表示x从0次到n次项的系数"<<endl;
	shi a(n+1);
	cout<<"建立多项式b:请输入x最高次数m"<<endl;
	cin>>m;
	cout<<"请依次输入m+1个整数表示x从0次到m次项的系数"<<endl;
	shi b(m+1);
	cout<<"多项式a为："<<endl;
	a.show();
	cout<<"多项式b为："<<endl;
	b.show();
	shi c;
	cout<<"多项式a+b为："<<endl;
	addab(a,b,c);
	c.show();
	cout<<"多项式a-b为："<<endl;
	subab(a,b,c);
	c.show();
	cout<<"情输入x的值："<<endl;
	cin>>x;
	cout<<"多项式a的值为"<<a.val(x)<<endl;
	cout<<"多项式a的值为"<<b.val(x)<<endl;

}	
