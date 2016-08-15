#pragma once
#include<cmath>
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace std;
using namespace Emgu::CV;
using namespace Emgu::CV::Structure;
using namespace System::Drawing;

const int maxzero=3;
const int maxint=2000000000;
const int mincount=40;
const int maxnhctime=3;
const double maxte=0.4;
struct cl 
	{

		int count,sumx,sumy,sumxy,sumx2,sumy2;
		bool incir;
		cl()
		{

			count=0;
			sumx=0;
			sumy=0;
			sumxy=0;
			incir=false;
			sumx2=0;
			sumy2=0;
		}
	};
ref class circle
	{
	public:
		double x,y,a,b,c,sumxy,sumx,sumy,sumx2,sumy2,min,mt,md,ml,mr,maxclano,vx,vy,ox,oy;
		int count,zero,no;
		int cla,hcla,nhcla,nhctime;
		bool ignored;
		bool covered;
		array<int> ^incla;
		static int p;
		static circle()
		{
			p=0;
		}
		circle()
		{
			sumxy=0;
			sumx=0;
			sumy=0;
			count=0;
			zero=0;
			sumx2=0;
			sumy2=0;
			no=++p;
			hcla=-1;
			ignored=false;
			covered=false;
			mt=INT_MAX;
			md=0;
			ml=INT_MAX;
			mr=0;
		}
		circle(circle^ old)
		{
			x=old->x;
			y=old->y;
			a=old->a;
			b=old->b;
			c=old->c;
			sumxy=old->sumxy;
			sumx=old->sumx;
			sumy=old->sumy;
			sumx2=old->sumx2;
			sumy2=old->sumy2;
			min=old->min;
			count=old->count;
			zero=old->zero;
			no=old->no;
			cla=old->cla;
			hcla=old->hcla;
			nhcla=old->nhcla;
			nhctime=old->nhctime;
			ignored=old->ignored;
			p=old->p;
			mt=old->mt;
			md=old->md;
			ml=old->ml;
			mr=old->mr;
			vx=old->vx;
			vy=old->vy;
			ox=old->ox;
			oy=old->oy;
		}
		void calcir()
		{
			if (count>0)
			{
				zero=0;
				double covxy=sumxy/count-(sumx/count)*(sumy/count);
				double covxx=sumx2/count-(sumx/count)*(sumx/count);
				double covyy=sumy2/count-(sumy/count)*(sumy/count);
				double d=sqrt(pow(covxx-covyy,2)+4*pow(covxy,2));
				double m1=(covxx+covyy+d)/2;
				double m2=(covxx+covyy-d)/2;
				if (!covered)
				{
					if (m1>0) a=2*sqrt(m1);
					else a=0;
					if (m2>0) b=2*sqrt(m2);
					else b=0;
				}
				x=sumx/count;
				y=sumy/count;
				c=atan2(covxy,m1-covyy);

				if (y<mt) mt=y;
				if (y>md) md=y;
				if (x<ml) ml=x;
 				if (x>mr) mr=x;
			}
			else zero++;

		}
		
	};
ref class Dataset
{
	int p,cirp;
	cl *cla;
	List<circle^> ^cir;
	Bpnet ^bp;
	bool border;
	Emgu::CV::Image<Gray, Byte> ^oldframe;
	List<array<int>^> ^flowline;
public:
	Dataset(Bpnet ^net)
	{
		cirp=0;
		cir=gcnew List<circle^>;
		bp=net;
		border=false;
		flowline=gcnew List<array<int>^>;
	}
	int (*c)[camwidth];
	void bfs(int pp,int xx, int yy)
	{
		int dx[]={-1,-1,-1,1,1,1,0,0,2,-2,0,0};
		int dy[]={-1,0,1,-1,0,1,-1,1,0,0,2,-2};
		Queue<int> ^x= gcnew Queue<int>;
		Queue<int> ^y= gcnew Queue<int>;
		x->Enqueue(xx);
		y->Enqueue(yy);
		int tx,ty;
		while (x->Count>0)
		{
			tx=x->Dequeue();
			ty=y->Dequeue();
			if	((0<=tx)&&(tx<camwidth)&&(0<=ty)&&(ty<camheight)&&(c[ty][tx]==0))
			{
				c[ty][tx]=pp;
				for (int i=0;i<12;i++)
				{
					x->Enqueue(tx+dx[i]);
					y->Enqueue(ty+dy[i]);
				}
			}
		}

	}
	List<array<int>^> ^optflow(Emgu::CV::Image<Bgr, Byte> ^frame)
	{
		Emgu::CV::Image<Gray, Byte> ^newframe=frame->Convert<Gray,Byte>();
		flowline->Clear();
		if (oldframe) 
		{
			array<array<System::Drawing::PointF,1>^> ^oldpoints;
			if (cir->Count>0) oldpoints=oldframe->GoodFeaturesToTrack(cir->Count*10,0.01,10,1);
			else return flowline;
			int dis=3;
			int maxdabs=2;
			array<System::Drawing::PointF,1> ^opoints=gcnew array<System::Drawing::PointF,1>(oldpoints[0]->Length+cir->Count*(2*maxdabs+1)*(2*maxdabs+1));
			for (int i=0;i<oldpoints[0]->Length;i++)
				opoints[i]=oldpoints[0][i];
			int tt=oldpoints[0]->Length;
			for (int i=0;i<cir->Count;i++)
			{
				for (int dx=-maxdabs;dx<=maxdabs;dx++)
					for (int dy=-maxdabs;dy<=maxdabs;dy++)
					{
						opoints[tt++]=PointF(cir[i]->x+dx*dis,cir[i]->y+dy*dis);
					}
			}
			array<System::Drawing::PointF,1> ^newpoints;
			array<unsigned char,1> ^status;
			array<float,1> ^te;
			MCvTermCriteria mctc;
			OpticalFlow::PyrLK(oldframe,newframe,opoints,Size(5,5),0,mctc,newpoints,status,te);
			for (int i=0;i<newpoints->Length;i++)
				if ((status[i])&&(te[i]<maxte))
				{
					array<int> ^tline=gcnew array<int>(4);
					tline[0]=opoints[i].X;
					tline[1]=opoints[i].Y;
					tline[2]=newpoints[i].X;
					tline[3]=newpoints[i].Y;
					flowline->Add(tline);
				}
			for (int j=0;j<cir->Count;j++)
			{
				int tcount=0;
				for (int i=0;i<newpoints->Length;i++)
					if ((status[i])&&(distance(opoints[i].X,opoints[i].Y,cir[j])<=1)&&(te[i]<maxte)) tcount++;
				int tt=tt;
				for (int i=0;i<newpoints->Length;i++)
					if ((status[i])&&(distance(opoints[i].X,opoints[i].Y,cir[j])<=1)&&(te[i]<maxte))
					{
						cir[j]->x+=(newpoints[i].X-opoints[i].X)/tcount;
						cir[j]->x+=(newpoints[i].Y-opoints[i].Y)/tcount;
					}
			}
		}
		oldframe=newframe->Copy();
		return flowline;
	}
	List<array<int>^> ^classify(int a[][camwidth],Emgu::CV::Image<Bgr, Byte> ^frame)
	{
		List<array<int>^> ^tt=optflow(frame);
		classify(a);
		return tt;
	}
	void erasesmallcla(int a[][camwidth])
	{
		c=a;
		p=0;
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]==0)
				{
					p++;
					bfs(p,i,j);
				}
		array<int> ^con=gcnew array<int>(p+1);
		for (int i=0;i<p+1;i++)
			con[i]=0;
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0)
					con[c[j][i]]++;
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0) 
				{
					if (con[c[j][i]]<mincount) c[j][i]=-1;
					else c[j][i]=0;
				}
	}
	void classify(int a[][camwidth])
	{
		bool b[camheight][camwidth];
		int d[camheight][camwidth];
		erasesmallcla(a);
		c=a;
		for (int k=0;k<cir->Count;k++)
		{
			cir[k]->sumxy=0;
			cir[k]->sumx=0;
			cir[k]->sumy=0;
			cir[k]->count=0;
			cir[k]->sumx2=0;
			cir[k]->sumy2=0;
		}
		p=0;
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]==0)
				{
					p++;
					bfs(p,i,j);
				}
		if (border)
		{
			for (int i=0;i<camwidth;i++)
				for (int j=0;j<camheight;j++)
				{
					int flag=false;
					for (int dx=-1;dx<=1;dx++)
							for (int dy=-1;dy<=1;dy++)
								if ((0<=j+dy)&&(j+dy<camheight)&&(0<=i+dx)&&(i+dx<camwidth))
								{
									if (c[j][i]!=c[j+dy][i+dx]) flag=true;
								}
								else flag=true;

					if (flag) 
						d[j][i]=c[j][i];
					else
						d[j][i]=-1;
				}
			c=d;
		}
		if (cla) delete cla;
		cla=new cl[p+1];
		
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0)
				{
					cla[c[j][i]].sumx+=i;
					cla[c[j][i]].sumy+=j;
					cla[c[j][i]].sumxy+=i*j;
					cla[c[j][i]].sumx2+=i*i;
					cla[c[j][i]].sumy2+=j*j;
					cla[c[j][i]].count++;
					
				}
		for (int i=0;i<cir->Count;i++)
		{
			cir[i]->cla=-1;
			cir[i]->min=maxint;
			cir[i]->maxclano=-maxint;
			cir[i]->incla=gcnew array<int>(p+1);
			for (int j=0;j<=p;j++)
				cir[i]->incla[j]=0;
		}

		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0)
				{
					for (int k=0;k<cir->Count;k++)
						if ((cir[k]->zero<=maxzero)&&(distance(i,j,cir[k])<=1))
						{
							cir[k]->incla[c[j][i]]++;
						}
				}
		for (int i=0;i<cir->Count;i++)
			for (int j=1;j<=p;j++)
			{
				/*if (cla[j].count>mincount)
				{
					double dis=distance(int(cla[j].sumx/cla[j].count),int(cla[j].sumy/cla[j].count),cir[i]);
					if (cir[i]->min>dis)
					{
						cir[i]->min=dis;
						cir[i]->cla=j;
					}
				}*/
				/*
				上面的代码是一个椭圆内有多个肤色块选中心最近的
				下面的代码是一个椭圆内有多个肤色块选包含像素更多的
				*/
				if (cla[j].count>mincount)
				{
					double dis=distance(int(cla[j].sumx/cla[j].count),int(cla[j].sumy/cla[j].count),cir[i]);
					if (cir[i]->maxclano<cir[i]->incla[j])
					{
						cir[i]->maxclano=cir[i]->incla[j];
						cir[i]->cla=j;
					}
				}
			}
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0)
				{
					for (int k=0;k<cir->Count;k++)
						if (cir[k]->zero<=maxzero)
						{
							b[j][i]=true;
							if ((c[j][i]==cir[k]->cla)&&(distance(i,j,cir[k])<=1))
							{
								b[j][i]=false;
								cir[k]->count++;
								cir[k]->sumx+=i;
								cir[k]->sumy+=j;
								cir[k]->sumx2+=i*i;
								cir[k]->sumy2+=j*j;
								cir[k]->sumxy+=i*j;
								cla[c[j][i]].incir=true;
							}

						}
				}
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if ((c[j][i]>0)&&(b[j][i])&&(cla[c[j][i]].incir))
				{
					double min=maxint;
					int mincir=-1;
					for (int k=0;k<cir->Count;k++)
						if (cir[k]->zero<=maxzero)
						{
							if ((c[j][i]==cir[k]->cla)&&(distance(i,j,cir[k])<min)) 
							{
								min=distance(i,j,cir[k]);
								mincir=k;
							}
						}
					if ((mincir>=0)&&(c[j][i]==cir[mincir]->cla))
					{
						cir[mincir]->count++;
						cir[mincir]->sumx+=i;
						cir[mincir]->sumy+=j;
						cir[mincir]->sumx2+=i*i;
						cir[mincir]->sumy2+=j*j;
						cir[mincir]->sumxy+=i*j;
					}
				}
		for (int i=1;i<=p;i++)
		{
			if (!cla[i].incir)
			{
				cir->Add(gcnew circle);
				cir[cir->Count-1]->sumx=cla[i].sumx;
				cir[cir->Count-1]->sumy=cla[i].sumy;
				cir[cir->Count-1]->sumx2=cla[i].sumx2;
				cir[cir->Count-1]->sumy2=cla[i].sumy2;
				cir[cir->Count-1]->sumxy=cla[i].sumxy;
				cir[cir->Count-1]->count=cla[i].count;
				cir[cir->Count-1]->cla=i;
			}
		}
		for (int k=0;k<cir->Count;k++)
			if (cir[k]->zero<=maxzero)
			{
				cir[k]->calcir();
			}
			else
			{
				cir->RemoveAt(k);
			}
	
		for (int i=0;i<cir->Count;i++)
		{
			bool flag=true;
			for (int j=0;j<cir->Count;j++)
				if ((i!=j)&&(cir[i]->cla==cir[j]->cla)) flag=false;
			if (flag)
			{	
				int tt=identify(cir[i]->cla);
				if (cir[i]->nhcla==tt)
				{
					cir[i]->nhctime++;
				}
				else
				{
					cir[i]->nhcla=tt;
					cir[i]->nhctime=1;
				}
				if (cir[i]->nhctime>=maxnhctime) 
					cir[i]->hcla=cir[i]->nhcla;
			}
		}
		c=a;
	}
	~Dataset()
	{
		if (cla) delete cla;
	}
	int midx(int no)
	{
		return cla[no].sumx/cla[no].count;
	}
	int midy(int no)
	{
		return cla[no].sumy/cla[no].count;
	}
	int count(int no)
	{
		return cla[no].count;
	}
	int getp()
	{
		return p;
	}
	double distance(int xx,int yy, circle ^cc)
	{	
		double t1=(xx-cc->x)*cos(cc->c)+(yy-cc->y)*sin(cc->c);
		double t2=cc->a;
		double t3=(yy-cc->y)*cos(cc->c)-(xx-cc->x)*sin(cc->c);
		double t4=cc->b;
		double ans=t1*t1/t2/t2+t3*t3/t4/t4;
		if (abs(ans-1)<0.1)
			if (abs(xx-cc->x)<1)
				ans=ans;
		if (ans>1)
			ans=ans;
		else 
			ans=ans;
		return ans; 
	}
	int circount()
	{
		return cir->Count;
	}
	circle^ getcir(int x)
	{
		return cir[x];
	}
	/*void calcir()
	{
		int i,j,k;
		
	}*/
	array<double>^todata(int xx)
		{
			array<double> ^ans=gcnew array<double>(xcount);
			double td[xcount],mul=xcount/2;
			int x[xcount],y[xcount],cc[xcount];
			int midx=0,midy=0,count=0;
			for (int i=0;i<camwidth;i++)
				for (int j=0;j<camheight;j++)
				{
					if (c[j][i]==xx) 
					{
						count++;
						midx+=i;
						midy+=j;
					}
				}
			midx/=count;
			midy/=count;	
			double dalta=mul/count;
			for (int i=0;i<xcount;i++)
			{
				td[i]=0;
				x[i]=0;
				y[i]=0;
				cc[i]=0;
			}
			for (int i=0;i<camwidth;i++)
				for (int j=0;j<camheight;j++)
				{
					if (c[j][i]==xx)
					{
						int tno=((int)Math::Floor(Math::Atan2(j-midy,i-midx)/(Math::PI*2/xcount)+18))%36;
						td[tno]+=dalta;
						x[tno]+=i;
						y[tno]+=j;
						cc[tno]++;
						if (x[0]<0)
							x[0]=x[0];
					}
				}
			for (int i=0;i<=xcount-1;i++)
			{
				if (c[i])
				{
					if (cc[i]>0)
					{
						x[i]/=cc[i];		
						y[i]/=cc[i];
						td[i]=(x[i]-midx)*(x[i]-midx)+(y[i]-midy)*(y[i]-midy);
					}
					else td[i]=0;
					
				}
			}
			double max=0;
			int mn=0;
			for (int i=0;i<=xcount-1;i++)
			{
				if (td[i]>max) 
				{
					max=td[i];
					mn=i;
				}
			}
			for (int i=0;i<=xcount-1;i++)
			{
				ans[i]=td[(i+mn)%xcount]/max;
			}
			return ans;
		}
	 int identify(int xx)
		 {
			array<double> ^x,^y;
			x=todata(xx);
			y=bp->identify(x);
			double max=0;
			int ans=0;
			for (int i=0;i<=y->Length-1;i++)
			{
				if (y[i]>max)
				{
					max=y[i];
					ans=i;
				}
			}
			return ans;
		 }
	 void ignore()
	 {
		for (int i=0;i<cir->Count;i++)
		{
			cir[i]->ignored=true;
		}
	 }
};