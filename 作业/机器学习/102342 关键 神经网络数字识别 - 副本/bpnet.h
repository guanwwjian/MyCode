#include<cmath>
using namespace System;
//using namespace System::DateTime;
ref class Bpnet
{
array<double,2> ^o;
array<double,3> ^wt;//,^dwt;
int depth;
array<int> ^width;
double a,e;
Random ^rand
public:
	Bpnet(array<int> ^width, double a=0.01 ,double e=0.05)
	{
		rand=gcnew Random(DateTime::Now);
		this->depth=width->Length;
		this->width=width->Clone();
		this->a=a;
		this->e=e;
		o=gcnew array<double,2>(depth);
		for (int i=0;i<=depth-1;i++)
		{
			o[i]=gcnew array<double>(width[i]);
			for (int j=0;j<=width[i]-1;j++)
			{
				o[i][j]=0;
			}
		}
		wt=gcnew array<double,3>(depth-1);
		dwt=gcnew array<double,3>(depth-1);
		for (int i=0;i<=depth-2;i++)
		{
			wt[i]=gcnew array<double,2>(width[i]);
			//dwt[i]=gcnew array<double,2>(width[i]);
			for (int j=0;j<=width[i]-1;j++)
			{
				wt[i][j]=gcnew array<array>(width[i+1]);
				//dwt[i][j]=gcnew array<array>(width[i+1]);
				for (int k=0;k<=width[i+1]-1;k++)
				{
					wt[i][j][k]=random();
					//dwt[i][j][k]=0;
				}

			}
		}
	}

	void train(array<double,2> ^x,array<double,2> ^y,int count)
	{	
		array<double,2> ^dwt=gcnew array<double,2>(depth);
		for (int i=0;i<=depth-1;i++)
		{
			dwt[i]=array<double>(width[i]);
		}
		for (int i=0;i<=depth-2;i++)
		{
			for (int j=0;j<=width[i]-1;j++)
			{
				for (int k=0;k<=width[i+1]-1;k++)
				{
					wt[i][j][k]=random();
				}

			}
		}
		double E=e+1;
		while (E>e)
		{
			E=0;
			for (int i=0;i<=count-1;i++)
			{
				identify(x[i]);
				for (int j=0;j<=width[depth-1]-1;j++)
				{
					E=E+(y[i][j]-o[depth-1][j])*(y[i][j]-o[depth-1][j]);
				}
				for (int j=0;j<=width[depth-1]-1;j++)
				{
					dwt[depth-1][j]=o[depth-1][j]*(1-o[depth-1][j])*(y[i][j]-o[depth-1][j]);
				}
				for (int j=depth-2;j>=0;j++)
				{
					for (int k=0;k<=width[j]-1;k++)
					{
						int z=0;
						for (int l=0;l<=width[j+1]-1;l++)
							z=z+dwt[j+1][l]*wt[j][k][l];
						dwt[j][k]=z*o[j][k]*(1-o[j][k]);
					}
				}
				for (int l=depth-2;l>=0;l++)
				{
						for (int j=0;j<=width[depth-2]-1;j++)
						{
							for (int k=0;k<=width[depth-1]-1;k++)
							{
								wt[l][j][k]=wt[l][j][k]+a*o[l][j]*dwt[l][k];
							}
						}
				}

			}
		}
	}
	array<double>  ^identify(array<double> ^x)
	{
		for (int i=0;i<=width[0];i++)
		{
			o[0][i]=x[i];
		}
		for (int i=1;i<=depth-1;i++)
		{
			for (int j=0;j<=width[i]-1;j++)
			{
				o[i][j]=0;
				double net=0;
				for (int k=0;k<=width[i-1]-1;k++)
				{
					net=net+o[i-1]*wt[i-1][k][j];

				}
				o[i][j]=func(net);
			}
		}
		return o[depth-1];
	}
	double random()
	{
		int x=2000000000;
		return ((double)rand->Next(x+1))/x;
	}
	double func(int x,int y=0;)
	{
		return (1/(1+exp(-o))); 
	}

}