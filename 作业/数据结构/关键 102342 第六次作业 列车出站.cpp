#include<iostream>
#include<string>
using namespace std;
class station
{
public:
	int n,a[256],b[256],sum;
	char s[256];
	void dfs(int x,int y)
	{
		if (x<=n) 
		{
			int o=a[y+1];
			a[y+1]=x;
			dfs(x+1,y+1);
			a[y+1]=o;
		}
		if (y>0)
		{
			b[x-y]=a[y];
			dfs(x,y-1);
		}
		if ((y<=0)&&(x>n))
		{
			int i;
			for (i=1;i<=n;i++)
			{
				cout<<s[b[i]-1];
			}
			cout<<endl;
			sum++;
		}
	}
};
void main()
{
	cout<<"������һ���ַ���(�������ո�)��ʾ��ջ����:"<<endl;
	station st;
	cin>>st.s;
	st.sum=0;
	st.n=strlen(st.s);
	cout<<"��ջ�����У�"<<endl;
	st.dfs(1,0);
	cout<<"����Ϊ��"<<st.sum<<endl;
}