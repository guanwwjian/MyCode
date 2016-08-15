#include<cmath>
using namespace System;
//using namespace System::DateTime;
ref class Bpnet
{
array<double,2> ^o;
array<double,3> ^wt,^dwt;
int depth,width;
int countin,countout;
double a,e;
Random ^rand
public:
	Bpnet(int depth=3,int width=4,int countin=width, int countout=1, double a=0.01 ,double e=0.05)
	{
		rand=gcnew Random(DateTime::Now);
		this->depth=depth;
		this->width=width;
		this->countin=countin;
		this->countout=countout;
		this->a=a;
		this->e=e;
		o=gcnew array<double,2>(depth);
		for (int i=0;i<=depth-1;i++)
		{
			int wi;
			if (i==0) wi=countin;
			else if (i==depth-1) wi=countout;
			else wi=width
			o[i]=gcnew array<double>(wi);
			for (int j=0;j<=wi-1;j++)
			{
				o[i][j]=0;
			}
		}
		wt=gcnew array<double,3>(depth-1);
		dwt=gcnew array<double,3>(depth-1);
		for (int i=0;i<=depth-2;i++)
		{
			int l=width,r=width;
			if (i==0) l=countin;
			if (i==depth-2) r=countout;
			wt[i]=gcnew array<double,2>(l);
			dwt[i]=gcnew array<double,2>(l);
			for (int j=0;j<=l-1;j++)
			{
				wt[i][j]=gcnew array<array>(r);
				dwt[i][j]=gcnew array<array>(r);
				for (int k=0;k<=r-1;k++)
				{
					wt[i][j][k]=random();
					dwt[i][j][k]=0;
				}

			}
		}
	}
	void train(array<double,2> ^x,array<double,2> ^y,int count)
	{	
		for (int i=0;i<=depth-2;i++)
		{
			int l=width,r=width;
			if (i==0) l=countin;
			if (i==depth-2) r=countout;
			for (int j=0;j<=l-1;j++)
			{
				for (int k=0;k<=r-1;k++)
				{
					wt[i][j][k]=random();
					dwt[i][j][k]=0;
				}

			}
		}
	}
	void  identify(array<double> ^x)
	{
		for (int i=0;i<=countin-1;i++)
		{
			o[0][i]=x[i];
		}
		for (int i=1;i<=double)
	}
	double random()
	{
		int x=2000000000;
		return ((double)rand->Next(x+1))/x;
	}
	double func(int x,int y)
	{
		return (1/(1+exp(-o))); 
	}

}