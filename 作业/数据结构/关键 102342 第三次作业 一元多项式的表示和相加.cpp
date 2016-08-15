
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
			cout<<"�Բ����ڴ�ռ䲻��";
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
	cout<<"��������ʽa:������x��ߴ���n"<<endl;
	cin>>n;
	cout<<"����������n+1��������ʾx��0�ε�n�����ϵ��"<<endl;
	shi a(n+1);
	cout<<"��������ʽb:������x��ߴ���m"<<endl;
	cin>>m;
	cout<<"����������m+1��������ʾx��0�ε�m�����ϵ��"<<endl;
	shi b(m+1);
	cout<<"����ʽaΪ��"<<endl;
	a.show();
	cout<<"����ʽbΪ��"<<endl;
	b.show();
	shi c;
	cout<<"����ʽa+bΪ��"<<endl;
	addab(a,b,c);
	c.show();
	cout<<"����ʽa-bΪ��"<<endl;
	subab(a,b,c);
	c.show();
	cout<<"������x��ֵ��"<<endl;
	cin>>x;
	cout<<"����ʽa��ֵΪ"<<a.val(x)<<endl;
	cout<<"����ʽa��ֵΪ"<<b.val(x)<<endl;

}	
