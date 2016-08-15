#include<cmath>
#include<fstream>
using namespace System;
using namespace std;
ref class Bpnet
{
array<array<double>^> ^o;
array<array<array<double>^>^> ^wt;
int depth;
array<int> ^width;
double a,e;
Random ^rand;
public:
	Void init(array<int> ^width)
	{
		init(width,0.5,0.01);
	}
	Void init(array<int> ^width, double a ,double e)
	{
		rand=gcnew Random(DateTime::Now.Millisecond);
		this->depth=width->Length;
		this->width=gcnew array<int>(width->Length);
		for (int i=0;i<=width->Length-1;i++)
		{
			this->width[i]=width[i];
		}
		this->a=a;
		this->e=e;
		o=gcnew array<array<double>^>(depth);
		for (int i=0;i<=depth-1;i++)
		{
			o[i]=gcnew array<double>(width[i]);
			for (int j=0;j<=width[i]-1;j++)
			{
				o[i][j]=0;
			}
		}
		wt=gcnew array<array<array<double>^>^>(depth-1);
		for (int i=0;i<=depth-2;i++)
		{
			wt[i]=gcnew array<array<double>^>(width[i]);
			for (int j=0;j<=width[i]-1;j++)
			{
				wt[i][j]=gcnew array<double>(width[i+1]);
				for (int k=0;k<=width[i+1]-1;k++)
				{
					wt[i][j][k]=random();
				}

			}
		}
	}

	Void train(array<array<double>^> ^x,array<array<double>^> ^y,int count)
	{	
		array<array<double>^> ^dwt=gcnew array<array<double>^>(depth);
		for (int i=0;i<=depth-1;i++)
		{
			dwt[i]=gcnew array<double>(width[i]);
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
					double tt=o[depth-1][j];
					E=E+(y[i][j]-o[depth-1][j])*(y[i][j]-o[depth-1][j]);
				}
				for (int j=0;j<=width[depth-1]-1;j++)
				{
					dwt[depth-1][j]=o[depth-1][j]*(1-o[depth-1][j])*(y[i][j]-o[depth-1][j]);
				}
				for (int j=depth-2;j>=0;j--)
				{
					for (int k=0;k<=width[j]-1;k++)
					{
						double z=0;
						for (int l=0;l<=width[j+1]-1;l++)
							z=z+dwt[j+1][l]*wt[j][k][l];
						dwt[j][k]=z*o[j][k]*(1-o[j][k]);
					}
				}
				for (int l=depth-2;l>=0;l--)
				{
						for (int j=0;j<=width[l]-1;j++)
						{
							for (int k=0;k<=width[l+1]-1;k++)
							{
								wt[l][j][k]=wt[l][j][k]+a*o[l][j]*dwt[l+1][k];
							}
						}
				}

			}
			E=E/count/width[depth-1];
		}
	}
	array<double>  ^identify(array<double> ^x)
	{
		for (int i=0;i<=width[0]-1;i++)
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
					net=net+o[i-1][k]*wt[i-1][k][j]/width[i-1];

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
	double func(double x)
	{
		return func(x,1);
	}
	double func(double x,int y)
	{
		return (1/(1+exp(-x))); 
	}
	void save()
	{
		ofstream ofs("bpnetdata.data");
		ofs<<a<<" "<<e<<" "<<depth;
		for (int i=0;i<=depth-1;i++)
			ofs<<" "<<width[i];
		for (int i=0;i<=depth-2;i++)
			for (int j=0;j<=width[i]-1;j++)
				for (int k=0;k<=width[i+1]-1;k++)
				{
					ofs<<" "<<wt[i][j][k];
				}
		ofs.close();
	}
	void load()
	{
		ifstream ifs("bpnetdata.data");
		int tint;
		double tdouble;
		ifs>>tdouble;
		a=tdouble;
		ifs>>tdouble;
		e=tdouble;
		ifs>>tint;
		depth=tint;
		array<int> ^width=gcnew array<int>(depth);
		for (int i=0;i<=depth-1;i++)
		{
			ifs>>tint;
			width[i]=tint;
		}
		init(width,a,e);
		for (int i=0;i<=depth-2;i++)
			for (int j=0;j<=width[i]-1;j++)
				for (int k=0;k<=width[i+1]-1;k++)
				{

					ifs>>tdouble;
					wt[i][j][k]=tdouble;
				}
		ifs.close();
	}
	int countx()
	{
		return width[0];
	}
	int county()
	{
		return width[depth-1];
	}
};