#include "Handmenu.h"
using namespace System::Collections::Generic;
const int clickstart=8;//
const int clickend=clickstart+24;//������ʱ
const int click2start=clickend+8;//˫����ʱ��ʼ
const int click2end=click2start+24;//˫����ʱ����
const int cusorcount=4;//�����ĸ���
const int cusordelay=(clickend-clickstart)/cusorcount;
const int cusordelay2=(click2end-click2start)/cusorcount;
const int mousemovdis=10;//���������
const int limit2=64;//����ƶ�����^2
const int itemsavecount=2;//savecount��Ĭ��ֵ
const int pptlimit2=5;//�ڿ���ppt�������ж������Ƿ��ƶ�����ֵ
const int pptxlimit=2;//�ڿ���ppt�������ж������Ƿ������ƶ�����ֵ
const int pptscount=5;//�ڿ���ppt������������Ҫͣ����ʱ��
const int pptxcount=3;//�ڿ���ppt������������Ҫ�ƶ���ʱ��
const int menudelay=10;//����˵����������֡��
const int menuzero2=100;//�˵�����ѡ�������ƶ������ƽ��
const int maxvolchange2=4;//ÿһ֡���������仯ֵ^2
ref class Commandposter
{
	List<array<int>^> ^com;//����������ֶ� ���1��ʾָ��� ���2��com[i][0]Ϊ��������: 0�������� 1���ƶ���com[i][1]��x��com[i][2]��y�� 2������������� 3�����Ĺ��ͼ����com[i][1]:������(-1��ʾ����Ĭ�Ϲ��) 4:������̰���(com[i][1]:�������) 5:��ʾpptѡ��� 6:�ı�ϵͳ������com[i][1]: �仯ֵ��7:��ʵ�����棩
	int mode;//0��Ĭ�� 1��������1 2��������2 3:ppt���� 4���˵� 5:��������;
	int oldmode;
	bool menuenabled;// f���˵�ͣ�� t���˵�����
	int menumode;//��ǰģʽ����Ĳ˵����
	int modebeforemenu;//����˵�ǰ��ģʽ
	double menustartx,menustarty;//��¼�˵�����ʱָ�����������
	Dataset ^data;//����Dataset���ȡ������Ϣ
	List<circle^> ^items;//�洢��֡������������Ϣ�����µ�֡������
	circle ^comitem;
	int savecount;//�洢��������ĸ���
	int flag,clano;//flag��ʾ����ǰ֡��ǰ�Ѿ���������֡��������������clano
	int lcount,rcount,scount;//lcount��������֡��,rcount��������֡��,scount��ֹ����֡��
	bool lflag,rflag,click2enabled;//lflag�󷭱�־,rflag�ҷ���־
	int comitemmode;//ѡȡָ������ķ��� 0����С��ţ����ȳ��֣� 1:���Ļ�¶� 2�������Ļ�¶�
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
		menu->addmenufromstring(gcnew String("����,������,ppt,��ʾ������,ϵͳ��������"));
		menu->addmenufromstring(gcnew String("����,�򿪿�ݲ˵�,�˳�������"));
		menu->addmenufromstring(gcnew String("����,�뿪ppt,��һ��,��һ��"));
		menu->addmenufromstring(gcnew String("����,����,����+10,�뿪��������,����-10"));
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
			//�����Ǿ�ģʽ����β����
			oldmode=mode;
			//��������ģʽ�ĳ�ʼ������
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