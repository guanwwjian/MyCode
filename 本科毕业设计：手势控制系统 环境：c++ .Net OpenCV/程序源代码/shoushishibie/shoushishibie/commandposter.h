#include "Handmenu.h"
using namespace System::Collections::Generic;
const int clickstart=8;//
const int clickend=clickstart+24;//单机延时
const int click2start=clickend+8;//双击计时开始
const int click2end=click2start+24;//双击计时结束
const int cusorcount=4;//鼠标光标的个数
const int cusordelay=(clickend-clickstart)/cusorcount;
const int cusordelay2=(click2end-click2start)/cusorcount;
const int mousemovdis=10;//鼠标灵敏度
const int limit2=64;//鼠标移动上限^2
const int itemsavecount=2;//savecount的默认值
const int pptlimit2=5;//在控制ppt过程中判断手势是否移动的阈值
const int pptxlimit=2;//在控制ppt过程中判断手势是否左右移动的阈值
const int pptscount=5;//在控制ppt过程中手势需要停留的时间
const int pptxcount=3;//在控制ppt过程中手势需要移动的时间
const int menudelay=10;//激活菜单所需的连续帧数
const int menuzero2=100;//菜单中心选项的最大移动距离的平方
const int maxvolchange2=4;//每一帧音量的最大变化值^2
ref class Commandposter
{
	List<array<int>^> ^com;//输出的命令字段 标号1表示指令号 标号2：com[i][0]为命令类型: 0：无命令 1：移动（com[i][1]：x，com[i][2]：y） 2：单击左键（） 3：更改光标图案（com[i][1]:光标序号(-1表示返回默认光标) 4:点击键盘按键(com[i][1]:按键编号) 5:显示ppt选择框 6:改变系统音量（com[i][1]: 变化值）7:现实主界面）
	int mode;//0：默认 1：鼠标控制1 2：鼠标控制2 3:ppt控制 4：菜单 5:音量控制;
	int oldmode;
	bool menuenabled;// f：菜单停用 t：菜单启用
	int menumode;//当前模式激活的菜单编号
	int modebeforemenu;//激活菜单前的模式
	double menustartx,menustarty;//记录菜单激活时指令物体的坐标
	Dataset ^data;//外链Dataset类获取物体信息
	List<circle^> ^items;//存储各帧的命令物体信息，最新的帧标号最大
	circle ^comitem;
	int savecount;//存储命令物体的个数
	int flag,clano;//flag表示到当前帧以前已经连续多少帧命令物体的类别是clano
	int lcount,rcount,scount;//lcount左移连续帧数,rcount右移连续帧数,scount静止连续帧数
	bool lflag,rflag,click2enabled;//lflag左翻标志,rflag右翻标志
	int comitemmode;//选取指令物体的方法 0：最小编号（最先出现） 1:最靠屏幕下端 2：曾最靠屏幕下端
	Handmenu ^menu;
	void movemouse()
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(3);
		tcom[0]=1;
		tcom[1]=comitem->x-items[savecount-2]->x;
		tcom[2]=comitem->y-items[savecount-2]->y;
		tcom[1]=-tcom[1]*mousemovdis;
		tcom[2]=tcom[2]*mousemovdis;
		com->Add(tcom);
	}
	void movemousewithlimit()
	{
		int x=comitem->x-items[savecount-2]->x;
		int y=comitem->y-items[savecount-2]->y;
		if (x*x+y*y<limit2) movemouse();

	}
	void clickleft()
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(4);
		tcom[0]=2;
		com->Add(tcom);
	}
	void clicklefttow()
	{
		clickleft();
		clickleft();
	}
	void setcusor(int x)
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(2);
		tcom[0]=3;
		tcom[1]=x;
		com->Add(tcom);
	}
	void clickkey(int x)
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(2);
		tcom[0]=4;
		tcom[1]=x;
		com->Add(tcom);
	}
	void showpptdialog()
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(1);
		tcom[0]=5;
		com->Add(tcom);
	}
	void changevol(int x)
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(2);
		tcom[0]=6;
		tcom[1]=x;
		com->Add(tcom);
	}
	void showmainform()
	{
		array<int> ^tcom;
		tcom=gcnew array<int>(1);
		tcom[0]=7;
		com->Add(tcom);
	}
public:
	Commandposter(Dataset ^d)
	{
		data=d;
		mode=0;
		oldmode=mode;
		items=gcnew List<circle^>;
		com=gcnew List<array<int>^>;
		savecount=itemsavecount;
		clano=-1;
		flag=0;
		lcount=0;
		rcount=0;
		scount=0;
		lflag=false;
		rflag=false;
		comitemmode=2;
		menuenabled=true;
		menumode=0;
		menu=gcnew Handmenu();
		menu->addmenufromstring(gcnew String("返回,鼠标控制,ppt,显示主界面,系统音量调节"));
		menu->addmenufromstring(gcnew String("返回,打开快捷菜单,退出鼠标控制"));
		menu->addmenufromstring(gcnew String("返回,离开ppt,下一步,上一步"));
		menu->addmenufromstring(gcnew String("返回,静音,音量+10,离开音量调节,音量-10"));
		click2enabled=true;
	}
	void changemode(int x)
	{
		mode=x;
	}
	array<int>^ getcommand(int x)
	{
		return com[x];
	}
	int getcomcount()
	{
		return com->Count;
	}
	void menuclose()
	{
		changemode(modebeforemenu);
		menu->menuend();
	}
	void menustart()
	{
		if ((menuenabled)&&(mode!=4))
		{
			modebeforemenu=mode;
			changemode(4);
			menu->menustart(menumode);
			menustartx=comitem->x;
			menustarty=comitem->y;
			
		}
	}
	void calcommand()
	{
		com->Clear();
		modeinit();
		int count=data->circount();
		circle ^nul;
		if (count>0)
		{
			int itemloc=0;
			while (itemloc<count)
			{
				comitem=data->getcir(itemloc);
				if (!comitem->ignored) break;
				itemloc++;
			}
			if (itemloc==count)
			{
				comitem=nul;
				return;
			}
			if (comitemmode==1)
			{
				for (int i=itemloc+1;i<count;i++)
				{
					circle ^tt=data->getcir(i);
					if ((!tt->ignored)&&(tt->y>comitem->y)) comitem=tt;
					
				}
			}
			else if (comitemmode==2)
			{
				for (int i=itemloc+1;i<count;i++)
				{
					circle ^tt=data->getcir(i);
					if ((!tt->ignored)&&(tt->md>comitem->md)) comitem=tt;
					
				}
			}
			else if (comitemmode!=0)
			{
					comitem=nul;
					return;
			}
		}
		else 
		{
			if (mode==4) menuclose();
			comitem=nul;
			return;
		}
		items->Add(gcnew circle(comitem));
		while (items->Count>savecount) items->RemoveAt(0);
		if (items->Count<savecount) return;
		if ((comitem->hcla==2)&&(clano==2)&&(flag==menudelay))
		{
			menustart();
		}
		if (mode==1)
		{
			if ((items[savecount-2]->hcla==0)&&(comitem->hcla==0))
			{
				movemouse();				
			}
			else if ((items[savecount-2]->hcla==0)&&(comitem->hcla==1))
			{
				clickleft();			
			}
		}
		else if (mode==2)
		{
			movemousewithlimit();	
			if ((comitem->hcla==1)&&(clano==1))
			{
				if ((clickstart<=flag)&&(flag<clickend))
				{
					if ((flag-clickstart)%cusordelay==0)
					{
						setcusor((flag-clickstart)/cusordelay+1);
					}
				}
				else if (flag==clickend)
				{
					clickleft();
					setcusor(0);
				}
				else if ((click2start<=flag)&&(flag<click2end))
				{
					if ((flag-click2start)%cusordelay2==0)
					{
						setcusor((flag-click2start)/cusordelay2+1);
					}
				}
				else if (flag==click2end)
				{
					clicklefttow();
					setcusor(0);
				}
			}
			else if (comitem->hcla!=1)
			{
				setcusor(0);
			}
		}
		else if (mode==3)
		{
			int dx=comitem->x-items[savecount-2]->x;
			int dy=comitem->y-items[savecount-2]->y;
			if (dx*dx+dy*dy>=pptlimit2)
			{
				scount=0;
				if (dx>=pptxlimit)
				{
					lcount++;
					if (lcount>=pptxcount) lflag=true;
				}
				else
				{
					lcount=0;
					lflag=false;
				}
				if (dx<=-pptxlimit)
				{
					rcount++;
					if (rcount>=pptxcount) rflag=true;
				}
				else
				{
					rcount=0;
					rflag=false;
				}
			}
			else
			{
				lcount=0;
				rcount=0;
				scount++;
				if ((rflag)&&(scount>=pptscount))
				{
					rflag=false;
					clickkey(34);
				}
				else if ((lflag)&&(scount>=pptscount))
				{
					lflag=false;
					clickkey(33);
				}
			}
		}
		else if (mode==4)
		{
			if (comitem->hcla!=2)
			{
				menuclose();
			}
			else 
			{
				double dx=comitem->x-menustartx;
				double dy=comitem->y-menustarty;
				if (dx*dx+dy*dy<menuzero2)
				{
					menu->changestatus(0);
				}
				else
				{
					double alpha=Math::Atan2(-dy,dx);
					int selc=menu->getselectcount();
					int se=(int)((alpha-Math::PI/2)/(2*Math::PI/(selc-1))+0.5+(selc-1))%(selc-1)+1;
					menu->changestatus(se);
					
				}
				int menucom=menu->updatemenu();
				int menuno=menu->getmenuno();
				if (menucom!=-1)
				{
					int newmode=modebeforemenu;
					if (menuno==0)
					{
						if (menucom==1)
						{
							newmode=2;
						}
						else if (menucom==2)
						{
							newmode=2;
							showpptdialog();
						}
						else if (menucom==3)
						{
							showmainform();
						}
						else if (menucom==4)
						{
							newmode=5;
						}
					}
					else if (menuno==1)
					{
						if (menucom==1)
						{
							clickkey(93);
						}
						else if (menucom==2)
						{
							newmode=0;
						}	
					}
					else if (menuno==2)
					{
						if (menucom==1)
						{
							newmode=0;
							clickkey(27);
						}
						else if (menucom==2)
						{
							clickkey(34);
						}
						else if (menucom==3)
						{
							clickkey(33);
						}
					}
					else if (menuno==3)
					{
						if (menucom==1)
						{
							changevol(-100);
						}
						else if (menucom==2)
						{
							changevol(5);
						}
						else if (menucom==3)
						{
							newmode=0;
						}
						else if (menucom==4)
						{
							changevol(-5);
						}
					}
					changemode(newmode);
				}
			}
		}
		else if (mode==5)
		{
			if (comitem->hcla==1)
			{
				int volchange=items[savecount-2]->y-comitem->y;
				if (volchange*volchange<maxvolchange2)
					changevol(volchange);

			}
		}
		if (comitem->hcla!=clano)
		{
			clano=comitem->hcla;
			flag=0;
		}
		else
		{
			flag++;
			if (comitem->count==0) flag=0;
		}
		
	}
	circle^ getcomitem()
	{
		return comitem;
	}
	void modeinit()
	{
		if (oldmode!=mode)
		{
			if (oldmode==2)
			{
				setcusor(-1);
			}
			//上面是旧模式的收尾工作
			oldmode=mode;
			//下面是新模式的初始化工作
			if (mode==0)
			{
				menumode=0;
			}
			else if (mode==2)
			{
				setcusor(0);
				menumode=1;
			}
			else if (mode==3)
			{
				menumode=2;
			}
			else if (mode==5)
			{
				menumode=3;
			}
		}
	}
};