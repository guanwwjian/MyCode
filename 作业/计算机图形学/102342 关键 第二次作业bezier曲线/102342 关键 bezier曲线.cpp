// 102342 关键 bezier曲线.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
int wx=400,wy=300,n=0,px=100,py=100;//wx,wy:窗口大小
int x[10000]={0};//各点位置
int y[10000]={0};
double jie[10001]={1};

void dline(int x1,int y1,int x2,int y2)
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
		for (i=x1;i<=x2;i++) 
		{
			//b[i][y1]=true;
			glVertex2i(i,y1);	
		}
	}
	else if (dx==0)
	{
		if (y1>y2){tt=y1;y1=y2;y2=tt;}
		for (i=y1;i<=y2;i++) 
		{
			//b[x1][i]=true;
			glVertex2i(x1,i);	
		}
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
		//b[x1][y1]=true;
		glVertex2i(x1,y1);
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
			{
				glVertex2i(x1+tx,y1+ty);	
				//b[x1+tx][y1+ty]=true;
			}
				
			
		}

	}

}

void dbx()
{
	if (n==1)
	{
		glColor3f(0,0,0);
		glVertex2i(x[0],y[0]);
	}
	else if (n>=2)
	{
		int i;
		glColor3f(1.0,0,0);
		dline(x[n-1],y[n-1],x[0],y[0]);
		glColor3f(0,0,0);
		for (i=1;i<=n-1;i++) 
		{
			dline(x[i-1],y[i-1],x[i],y[i]);
		}
	}
}
void bezier()
{
	double qx,qy,u,bni;
	int i;
	for (u=0;u<=1;u+=0.001/n)
	{
		qx=0;
		qy=0;
		for (i=0;i<=n-1;i++)
		{
			bni=jie[n-1]/jie[i]/jie[n-1-i]*pow(u,i)*pow(1-u,n-1-i);
			qx+=bni*x[i];
			qy+=bni*y[i];
		}
		glColor3f(0,0,0);
		glVertex2i(qx,qy);

	}
}
int om,dis=3;

void mouse(int button,int state,int xx,int yy)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
			if (state==GLUT_DOWN)
			{
				int i;
				om=-1;
				for (i=0;i<=n-1;i++)
					if ((abs(x[i]-xx)<=dis)&&(abs(y[i]-(wy-1-yy))<=dis))
					{
						om=i;
						break;
					}
				if (om<0)
				{
					x[n]=xx;
					y[n]=wy-1-yy;
					n++;
					jie[n]=jie[n-1]*n;
					om=n-1;
				}
			}
			break;
	case GLUT_RIGHT_BUTTON:
			if ((state==GLUT_DOWN)&&(n>0))	n--;
			break;
	}
	glutPostRedisplay();
}
void motion(int xx,int yy)
{
	x[om]=xx;
	y[om]=wy-1-yy;
	glutPostRedisplay();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	int i,j,k;
	/*for (i=0;i<=wx;i++)
		for (j=0;j<=wy;j++)
			if (b3[i][j])
			{
				glColor4i(0,0,0,0);
				glVertex2i(i,j);
			}*/
	for (k=0;k<=n-1;k++)
	{
		for (i=-dis;i<=dis;i++)
			for (j=-dis;j<=dis;j++)
			{
					glColor3f(0,0,0);
					glVertex2i(x[k]+i,y[k]+j);	
			}
	}
	dbx();
	bezier();
	glEnd();
	glFlush();

}

void main(int argc, char* argv[])
{

	n=0;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(wx,wy);
	glutInitWindowPosition(px,py);
	glutCreateWindow("关键 102342 bezier曲线");
	glClearColor(1.0,1.0,1.0,0.0);
	gluOrtho2D(0.0,double(wx),0.0,double(wy));
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutMainLoop();

}



