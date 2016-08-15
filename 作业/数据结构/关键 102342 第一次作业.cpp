// �ؼ� 102342 ��һ����ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
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
		table();
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
	bool const checksort()
	{
		int i;
		for (i=1;i<=length-1;i++) if (elem[i-1]>elem[i+1-1]) return false;
		return true;
	}
	bool insertsort(ele x)
	{
		if (checksort())
		{
			int i=1;
			while (elem[i-1]<x) i++;
			insert(x,i);
			return true;
		}
		else return false;
	}
	void deln(int n)
	{
		int i;
		for (i=1;i<=length;i++)
		{
			if (elem[i-1]==n) del(i);
			return;
		}
	}
	void delall(int n)
	{
		int i;
		for (i=1;i<=length;i++)
		{
			if (elem[i-1]==n) del(i);
		}
	}
	void ni(table& a)
	{
		int i;
		for (i=length;i>=1;i++) a.add(elem[i-1]);
	}
	void delequal()
	{
		int i,j;
		for (i=1;i<=length;i++)
			for (j=i+1;j<=length;j++)
				if (elem[i-1]==elem[j-1])
				{
					del(j);
					j--;
				}
	}
};
bool bing(table& c,table& a,table& b)
{
	if ((!a.checksort())||(!b.checksort())) return false;
	int la=a.len(),lb=b.len(),i=1,j=1;
	while ((i<=la)||(j<=lb))
	{
		if (i>la) {c.add(b.data(j));j++;}
		else if (j>lb) {c.add(a.data(i));i++;}
		else if (a.data(i)<=b.data(j)) {c.add(a.data(i));i++;}
		else if (b.data(j)<a.data(i)) {c.add(b.data(j));j++;}
	}
	return true;
}
void bi(int x)
{
	int i,j;
	if (x>=1) cout<<"\a";
	for (i=2;i<=x;i++)
	{
	//	for (j=1;j<=50000;j++);
		cout<<"\a";
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"��ӭʹ�ü���˳������ݴ���ϵͳ\n             -------by����:�ؼ� 102342\n";
	bi(3);
	system("pause");
	table a[10001];
	bool quit=false;
	while (!quit)
	{
		int n,x,y,z;
		
		bi(1);
		cout<<"�����б�:"<<endl;
		cout<<"         1.����˳���"<<endl;
		cout<<"         2.�Ե�һ˳�����ʡ�����"<<endl;
		cout<<"         3.�ϲ����������"<<endl;
		cout<<"         4.����˳���"<<endl;
		cout<<"         0.�˳�"<<endl;
		cout<<"�����������ţ�";
	
		cin>>n;

		if (n==1)
		{
			int i,x,y;
			ele tt;
			cout<<"������Ҫ����˳���ı��(0-10000)��";
			cin>>x;
			cout<<"������Ҫ����˳����Ԫ����n��0-100000����";
			cin>>y;
			cout<<"������n��Ԫ�أ��м��ÿո��������";
			a[x].creat(y);
			
		}
		else if (n==2)
		{
			int x,y,z,m;
			cout<<"������Ҫ������˳�����(0-10000)��";
			cin>>m;
			bool re=false;
			while (!re)
			{
				bi(1);
				cout<<"�Ӳ����б�"<<endl;
				cout<<"            1.����Ԫ�ص���x��Ԫ��ǰ"<<endl;
				cout<<"            2.ɾ����x��Ԫ��Ԫ��"<<endl;
				cout<<"            3.��ʾ��x��Ԫ�ص�ֵ"<<endl;
				cout<<"            4.��ʾ˳���������Ԫ��"<<endl;
				cout<<"            5.�������������x��Ԫ��"<<endl;
				cout<<"            6.ɾ����һ������x��Ԫ��"<<endl;
				cout<<"            7.ɾ�����е���x��Ԫ��"<<endl;
				cout<<"            8.��ձ�����˳���"<<endl;
				cout<<"            9.ɾ���ñ��������ظ�Ԫ��"<<endl;
				cout<<"            0.��ֹ�Ե�һ˳������"<<endl;
				cout<<"�����������ţ�";
				cin>>n;
				 if (n==1)
				{
					cout<<"������λ��x����ֵy��";
					cin>>x>>y;
					while ((x<1)||(x>a[m].len()+1))
					{
						cout<<"λ���������"<<endl;
						cout<<"������λ��x����ֵy��";
						cin>>x,y;
					}
					a[m].insert(y,x);
				}
				else if (n==2)
				{
					cout<<"������λ��x��";
					cin>>x;
					while ((x<1)||(x>a[m].len()))
					{
						cout<<"λ���������"<<endl;
						cout<<"������λ��x��";
						cin>>x;
					}
					a[m].del(x);
				}
				else if (n==3)
				{
					cout<<"������λ��x��";
					cin>>x;
					while ((x<1)||(x>a[m].len()))
					{
						cout<<"λ���������"<<endl;
						cout<<"������λ��x��";
						cin>>x;
					}
					write(a[m].data(x));
					cout<<endl;
				}
				else if (n==4)
				{
					a[m].show();
				}
				else if (n==5)
				{
					cout<<"������Ԫ�ص�ֵx��";
					cin>>x;
					if (!a[m].insertsort(x)) cout<<"���������";
				}
				else if (n==6)
				{
					cout<<"������Ԫ�ص�ֵx��";
					cin>>x;
					a[m].deln(x);
				}
				else if (n==7)
				{
					cout<<"������Ԫ�ص�ֵx��";
					cin>>x;
					a[m].delall(x);
				}
				else if (n==8)
				{
					cout<<"������Ԫ�ص�ֵx��";
					cin>>x;
					a[m].destroy();
				}
				else if(n==9)
				{
					a[m].delequal();
				}
				else if (n==0)
				{
					re=true;
				}
				else cout<<"�����ָ��";
			}
		}
		else if (n==3)
		{
			cout<<"�����������������x,y�Լ��ϲ����ű�ı��z��";
			cin>>x>>y>>z;
			if (!bing(a[z],a[x],a[y])) cout<<"���������";
		}
		else if (n==4)
		{
			cout<<"������Ҫ����ı�ı��x�Լ����Ŀ���y��";
			cin>>x>>y;
			a[x].ni(a[y]);
		}
		else if (n==0)
		{
			quit=true;
		}
		else cout<<"�����ָ��";
		cout<<"�������\a"<<endl;
	}
	return 0;
}

