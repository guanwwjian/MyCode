// 关键 102342 斜线填充.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
const int mx=2001,my=2001,lm=1000001;//数组上界
bool b1[mx][my]={0},b2[mx][my]={0},b3[mx][my]={0};//模拟画布
int wx=400,wy=300,n=5,ix=61,iy=61,dis=10,px=100,py=100;//wx,wy:窗口大小,n:多边形边数,ix,iy:多边形内任意一点,dis:斜线间隔,q:q=wy/k,其中k为斜线斜率
double k=1.0;
int x[256]={60,20,200,350,300};//各点位置
int y[256]={60,150,250,150,80};
int ax[4]={1,-1,0,0};
int ay[4]={0,0,1,-1};
int lx[lm],ly[lm];//队列空间
void dline(int x1,int y1,int x2,int y2,bool b[mx][my])//模拟画布上的画线函数(Breswnham)
{
	int tt,i,j,k;
	bool b1=false,b2=false;
	if (x1>x2)
	{
		tt=x1;x1=x2;x2=tt;
		tt=y1;y1=y2;y2=tt;
	}
	int dx=x2-x1,dy=y2-y1;
	if (dy==0)
	{
		for (i=x1;i<=x2;i++) b[i][y1]=true;
	}
	else if (dx==0)
	{
		if (y1>y2){tt=y1;y1=y2;y2=tt;}
		for (i=y1;i<=y2;i++) b[x1][i]=true;
	}
	else
	{
		if ((dy)<0)
		{
			b1=true;
			dy=-dy;
		}
		if (dy>dx)
		{
			b2=true;
			tt=dx;dx=dy;dy=tt;
		}
		int dt=2*(dy-dx),ds=2*dy,d=2*dy-dx,tx,ty;
		b[x1][y1]=true;
		j=0;
		for (i=1;i<=dx;i++)
		{
			if (d<0) 
			{
				d=d+ds;
			}
			else
			{
				j++;
				d=d+dt;
			}
			tx=i;ty=j;
			if (b2)
			{
				tt=tx;tx=ty;ty=tt;
			}
			if (b1)
			{
				ty=-ty;
			}
			if ((0<=x1+tx)&&(x1+tx<=wx)&&(0<=y1+ty)&&(y1+ty<=wy))
				b[x1+tx][y1+ty]=true;
				
			
		}

	}

}
void tchong(bool b[mx][my],int ix,int iy)//模拟画布上的填充函数(4邻域填充)
{
	int l=1,r=2;
	lx[1]=ix;ly[1]=iy;
	int i,j,k;
	while (l<r)
	{
		i=lx[l%lm];j=ly[l%lm];
		if ((0<=i)&&(i<=wx)&&(0<=j)&&(j<=wy)&&(!b[i][j]))
		{
		b[i][j]=true;
		int x,y;
		for (k=0;k<=3;k++)
		{
			x=i+ax[k];y=j+ay[k];
			if ((0<=x)&&(x<=wx)&&(0<=y)&&(y<=wy)&&(!b[x][y]))
			{
				lx[r%lm]=x;ly[r%lm]=y;
				r++;
			}
		}


		}
		l++;
	}
}
void display()//根据处理好的画布绘图
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	int i,j,k;
	for (i=0;i<=wx;i++)
		for (j=0;j<=wy;j++)
			if (b3[i][j])
			{
				glColor4i(0,0,0,0);
				glVertex2i(i,j);
			}
	glEnd();
	glFlush();

}

void main(int argc, char* argv[])
{
	int i,j,a;
	cout<<"wx，wy:窗口的长、宽 n:多边形的边数 dis:影线的间隔 k:影线的斜率 ix,iy:多边形内某一点的坐标 x[],y[]:多边形各顶点坐标"<<endl;
	cout<<"1.采用默认设置(wx=400,wy=300,n=5,dis=10,k=1.0,ix=61,iy=61\nx[]={60,20,200,350,300}\ny[]={60,150,250,150,80};)\n2.自定义设置\n请选择：";
	cin>>a;
	if (a>1)
	{
		cout<<"输入wx,wy,dis,k,n其中k为浮点数,其余为整数"<<endl;
		cin>>wx>>wy>>dis>>k>>n;
		cout<<"请输入n行，第i行2个整数表示多边形定点坐标x[i],y[i]"<<endl;
		for (i=0;i<=n-1;i++)
		{
			cin>>x[i]>>y[i];
		}
		cout<<"输入两个整数ix,iy（不包括边界，为了适用种子填充法）"<<endl;
		cin>>ix>>iy;
	}
	dline(x[n-1],y[n-1],x[0],y[0],b1);//画布1:多边形边框
	dline(x[n-1],y[n-1],x[0],y[0],b2);//画布2:多边形填充区域
	for (i=1;i<=n-1;i++) 
	{
		dline(x[i-1],y[i-1],x[i],y[i],b1);
		dline(x[i-1],y[i-1],x[i],y[i],b2);
	}
	//dline(70,54,54,70,b2);
	tchong(b2,ix,iy);
	bool f1=false,f2=false;
	if (k<0) 
	{
		k=-k;
		f1=true;
	}
	if (k<1)
	{
		k=1/k;
		f2=true;
	}
	int mxy=wx;
	if (mxy<wy) mxy=wy;
	int q=(int)(mxy/k);
	int tt,tt1,tt2,tt3,tt4;
	for (i=-q;i<=wx;i+=dis)
	{
		tt1=i;tt2=0;tt3=i+q;tt4=mxy;
		if (f1) 
		{
			tt=tt2;tt2=tt4;tt4=tt;		
		}
		if (f2)
		{
			tt=tt1;tt1=tt2;tt2=tt;
			tt=tt3;tt3=tt4;tt4=tt;
		}
		dline(tt1,tt2,tt3,tt4,b3);	//画布3:整屏的斜线	
	}
	for (i=0;i<=wx;i++)
		for (j=0;j<=wy;j++)
			b3[i][j]=b2[i][j]&&b3[i][j]||b1[i][j];//画布3':目标结果
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(wx,wy);
	glutInitWindowPosition(px,py);
	glutCreateWindow("关键 102342 斜线填充");
	glClearColor(1.0,1.0,1.0,0.0);
	gluOrtho2D(0.0,double(wx),0.0,double(wy));
	glutDisplayFunc(display);
	glutMainLoop();

}

