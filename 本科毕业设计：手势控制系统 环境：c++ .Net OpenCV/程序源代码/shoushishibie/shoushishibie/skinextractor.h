#pragma once
	const int savecount=4;//保存的帧数
	const int lastcount=2;//肤色适应过程中判定为肤色的连续帧数
	const int difmincount=mincount;
	const int maxpcount=2000;//阈值设定状态下取得差值点的个数
	const double changerate=50;//动态阈值变化率
	const int initcount=5;//初始化帧数
	const int initdif3=500;//初始化差值法中的差别阈值^3
	const double initupdaterate=0.05;//初始化差值法的更新速率
	const int initnoupdatedis=1;//初始化差值法中不更新方形范围大小
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Threading;
	using namespace Emgu::CV;
	using namespace Emgu::CV::Structure;
	using namespace Emgu::Util;
	using namespace System::Collections::Generic;
ref class SkinExtractor
{
	int mode;//0:通常状态 1：阈值设定状态 2:自动阈值适应状态
	int outmode;//0:静态阈值分割 1：差值 2：动态阈值分割 3：静态阈值分割后动态阈值分割
	int initmode;//0:不使用初始化差值法 1：使用初始化差值法 2：使用带更新的初始化差值法
	int initrest;//初始化剩余帧数 -1为未初始化
	List<array<array<int>^>^> ^data;//分割点阵列表
	array<array<int>^> ^dif; //差点阵
	array<array<double>^> ^r,^g,^b;//初始化图像分量矩阵
	shoushishibie::Form1 ^f;
	double maxr,maxg,maxb,minr,ming,minb;
	int pcount;
public:
	SkinExtractor(shoushishibie::Form1 ^ff)
	{
		data=gcnew List<array<array<int>^>^>;
		f=ff;
		outmode=0;
		initmode=0;
		initrest=-1;
		r=gcnew array<array<double>^>(camheight);
		g=gcnew array<array<double>^>(camheight);
		b=gcnew array<array<double>^>(camheight);
		for (int j=0;j<camheight;j++)
		{
			r[j]=gcnew array<double>(camwidth);
			g[j]=gcnew array<double>(camwidth);
			b[j]=gcnew array<double>(camwidth);
		}
	}
	void modeone()
	{
		pcount=0;
		mode=1;
		maxr=0;
		maxg=0;
		maxb=0;
		minr=255;
		ming=255;
		minb=255;
	}
	void modeoneend()
	{
		mode=0;
		outmode=3;
	}
	void modetwo()
	{
		mode=2;
		outmode=3;
		maxr=0;
		maxg=0;
		maxb=0;
		minr=255;
		ming=255;
		minb=255;
	}
	void getmap(Emgu::CV::Image<Emgu::CV::Structure::Bgr, Byte> ^frame,int ans[][camwidth])
	{
		Emgu::CV::Image<Ycc, Byte> ^frame1=frame->Convert<Ycc,Byte>();
		Emgu::CV::Structure::Ycc tt,b1(0,128,128);
		array<array<int>^> ^a=gcnew array<array<int>^>(camheight);
		while (initrest>0)
		{
			for (int j=0;j<camheight;j++)
				for (int i=0;i<camwidth;i++)
				{
					r[j][i]=(r[j][i]*(initcount-initrest)+frame[j,i].Red)/(initcount-initrest+1);
					g[j][i]=(g[j][i]*(initcount-initrest)+frame[j,i].Green)/(initcount-initrest+1);
					b[j][i]=(b[j][i]*(initcount-initrest)+frame[j,i].Blue)/(initcount-initrest+1);
				}
			initrest--;
			if (initrest==0)
			{
				initmode=2;
			}
		}
		int tty=frame->Height;
		int ttx=frame->Width;
		for (int j=0;j<camheight;j++)
		{
			a[j]=gcnew array<int>(camwidth);
			for (int i=0;i<camwidth;i++)
			{
				tt=frame1[j,i];
				tt.Y=0;
				frame1[j,i]=tt;
				a[j][i]=0;
				if (!((frame1[j,i].Cb>=Decimal::ToDouble(f->numericUpDown2->Value))&&(frame1[j,i].Cb<=Decimal::ToDouble(f->numericUpDown3->Value))&&(frame1[j,i].Cr>=Decimal::ToDouble(f->numericUpDown4->Value))&&(frame1[j,i].Cr<=Decimal::ToDouble(f->numericUpDown5->Value))))
				{	
					a[j][i]=-1;
				}		
			}
		}
		if ((initmode==1)||(initmode==2))
		{
			for (int j=0;j<camheight;j++)
				for (int i=0;i<camwidth;i++)
				{
					double dr=r[j][i]-frame[j,i].Red;
					double dg=g[j][i]-frame[j,i].Green;
					double db=b[j][i]-frame[j,i].Blue;
					if (dr*dr+dg*dg+db*db<initdif3) a[j][i]=-1;
				}
		}
		data->Add(a);
				while (data->Count>savecount) data->RemoveAt(0);
		dif=gcnew array<array<int>^>(camheight);
		for (int j=0;j<camheight;j++)
		{
			dif[j]=gcnew array<int>(camwidth);
			for (int i=0;i<camwidth;i++)
			{
				dif[j][i]=0;
				for (int k=0;k<data->Count-lastcount;k++)
					if 	(data[k][j][i]==0)	
						dif[j][i]=-1;
				for (int k=data->Count-lastcount;(k>=0&&k<data->Count);k++)
					if 	(data[k][j][i]==-1)	
						dif[j][i]=-1;
				
			}

		}
		ignore(dif);
		double tmaxr=0,tmaxg=0,tmaxb=0,tminr=255,tming=255,tminb=255;
		int n;
		for (int j=0;j<camheight;j++)
			for (int i=0;i<camwidth;i++)
				if (dif[j][i]==0)
				{
					int dx[]={-1,-1,-1,1,1,1,0,0};
					int dy[]={-1,0,1,-1,0,1,-1,1};
					bool flag=true;
					for (int k=0;k<8;k++)
					{
						if (((0<=i+dx[k])&&(i+dx[k]<camwidth)&&(0<=j+dy[k])&&(j+dy[k]<camheight))&&(dif[j+dy[k]][i+dx[k]])) flag=false;
					}
					if (flag)
					{
						if (tminr>frame[j,i].Red) tminr=frame[j,i].Red;
						if (tming>frame[j,i].Green) tming=frame[j,i].Green;
						if (tminb>frame[j,i].Blue) tminb=frame[j,i].Blue;
						if (tmaxr<frame[j,i].Red) tmaxr=frame[j,i].Red;
						if (tmaxg<frame[j,i].Green) tmaxg=frame[j,i].Green;
						if (tmaxb<frame[j,i].Blue) tmaxb=frame[j,i].Blue;
						n++;
					}
				}
		if (mode==1)
		{
			double k=changerate/camheight/camwidth*n;
			maxr=maxr*(1-k)+tmaxr*k;
			maxg=maxg*(1-k)+tmaxg*k;
			maxb=maxb*(1-k)+tmaxb*k;
			minr=minr*(1-k)+tminr*k;
			ming=ming*(1-k)+tming*k;
			minb=minb*(1-k)+tminb*k;
			pcount+=n;
			if (pcount>=maxpcount) modeoneend();
		}
		else if (mode==2)
		{
			double k=changerate/camheight/camwidth*n;
			maxr=maxr*(1-k)+tmaxr*k;
			maxg=maxg*(1-k)+tmaxg*k;
			maxb=maxb*(1-k)+tmaxb*k;
			minr=minr*(1-k)+tminr*k;
			ming=ming*(1-k)+tming*k;
			minb=minb*(1-k)+tminb*k;
		}
		for (int j=0;j<camheight;j++)
		{
			for (int i=0;i<camwidth;i++)
			{
				if (outmode==1)	ans[j][i]=dif[j][i];
				else if (outmode==2) ans[j][i]=check(frame[j,i]);
				else if (outmode==3)
				{
					ans[j][i]=check(frame[j,i]);
					if (data[data->Count-1][j][i]==-1) ans[j][i]=-1;
				}
				else ans[j][i]=data[data->Count-1][j][i]; 
				
				
			}

		}
		if (initmode==2)
		{
			for (int j=0;j<camheight;j++)
			{
				for (int i=0;i<camwidth;i++)
				{
					if (ans[j][i]==-1)
					{
						bool flag=true;
						for (int y=j-initnoupdatedis;(y<=j+initnoupdatedis)&&(flag);y++)
							if ((0<=y)&&(y<camheight))
								for  (int x=i-initnoupdatedis;(x<=i+initnoupdatedis)&&(flag);x++)
									if ((0<=x)&&(x<camwidth))
										if (ans[j][i]==0) flag=false;
						if (flag)
						{
							r[j][i]=r[j][i]*(1-initupdaterate)+frame[j,i].Red*initupdaterate;
							g[j][i]=g[j][i]*(1-initupdaterate)+frame[j,i].Green*initupdaterate;
							b[j][i]=b[j][i]*(1-initupdaterate)+frame[j,i].Blue*initupdaterate;
						}

					}
				}
			}
		}

	}
	int check(Bgr c)
	{
		if (minr>c.Red) return -1;
		if (ming>c.Green) return -1;
		if (minb>c.Blue) return -1;
		if (maxr<c.Red) return -1;
		if (maxg<c.Green) return -1;
		if (maxb<c.Blue) return -1;
		return 0;
	}
	void bfs(int pp,int xx, int yy, array<array<int>^> ^c)
	{
		int dx[]={-1,-1,-1,1,1,1,0,0};
		int dy[]={-1,0,1,-1,0,1,-1,1};
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
				for (int i=0;i<8;i++)
				{
					x->Enqueue(tx+dx[i]);
					y->Enqueue(ty+dy[i]);
				}
			}
		}

	}
	void ignore(array<array<int>^> ^c)//忽略较小差矩阵块
	{
		int p=0;
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]==0)
				{
					p++;
					bfs(p,i,j,c);
				}
		array<int> ^count=gcnew array<int>(p+1);
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0)
					count[c[j][i]]++;
		for (int i=0;i<camwidth;i++)
			for (int j=0;j<camheight;j++)
				if (c[j][i]>0) 
				{
					if (count[c[j][i]]<difmincount) c[j][i]=-1;
					else c[j][i]=0;
				}
	}
	void initstart()
	{
		initrest=initcount;

	}
	void reset()
	{
		outmode=0;
		initrest=-1;
		initmode=0;
	}
};