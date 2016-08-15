#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//using namespace System::Math;
namespace My102342
{
	
	ref class Station
	{
	public:
		static int con=-1;
		int x;
		int y;
		String ^name;
		ArrayList ^sa;
		virtual String^ ToString() override
		{
			return name+" 坐标：X="+x.ToString()+" Y="+y.ToString();
		}
		/*Station(String ^st)
		{
			x=0;
			y=0;
			t=gcnew ArrayList();
			name=gcnew String(st);
			
		}*/
		Station(String ^st,int xx,int yy)
		{
			name=gcnew String(st);
			x=xx;
			y=yy;
			sa=gcnew ArrayList();
		}
		Station(Station ^o)
		{
			x=o->x;
			y=o->y;
			sa=gcnew ArrayList(o->sa);
			name=gcnew String(o->name);
			
		}
		void modify(String ^st,int xx,int yy)
		{
			name=gcnew String(st);
			x=xx;
			y=yy;
		}

	
	};
	ref class Starrive
	{
	public:
		int wt;
		Station ^s;
		Object ^t;
		virtual String^ ToString() override
		{
			
			return s->name+" 坐标：X="+s->x.ToString()+" Y="+s->y.ToString()+" 始发到达间隔："+wt.ToString()+"分钟";
		}
		Starrive(Object ^asta,Object ^atra,int tt)
		{
			wt=tt;
			s=(Station^)asta;
			t=atra;
		}
		void modify(int tt)
		{
			wt=tt;
		}
		void modify(Object ^asta,Object ^atra,int tt)
		{
			wt=tt;
			s=(Station^)asta;
			t=atra;
		}
	};
	ref class Train
	{
	public:
		Color c;
		String ^name;
		ArrayList ^sa;
		static Random ^ran;
		virtual String ^ToString() override
		{
			return name;
		}
		static Train()
		{
			ran=gcnew Random();
		}
		Train(String ^st)
		{
			name=gcnew String(st);
			sa=gcnew ArrayList();
//			sta=gcnew ArrayList();
			int r,g,b;
			do
			{
				r=ran->Next(256);
				g=ran->Next(256);
				b=ran->Next(256);
			}
			while ((r>200)&&(g>200)&&(b>200));
			//c=gcnew Color();
			c=Color::FromArgb(r,g,b);
		}
		Train(Train ^o)
		{
			name=gcnew String(o->name);
			sa=gcnew ArrayList(o->sa);
			//c=gcnew Color();
			c=o->c;
		}
		void modify(String ^st)
		{
			name=gcnew String(st);
		}
		void addsa(Object ^o)
		{
			int tt=((Starrive^)o)->wt;
			int l=0,r=sa->Count-1,mid,mid2;
			if ((r<0)||(((Starrive^)sa[r])->wt<=tt)) sa->Add(o);
			else
			{
				while (l<r)
				{
					mid=(l+r)/2;
					mid2=(l+r+1)/2;
					if (((Starrive^)sa[mid2])->wt<tt)
					{
						l=mid2;
					}
					else if (((Starrive^)sa[mid])->wt>tt)
					{
							r=mid;
					}
					else
					{
							l=r=mid2;
					}
				}
				sa->Insert(r,o);
			}
		}
		int dis(Object ^o1,Object ^o2)
		{	int i;
			Object ^sa1,^sa2;
			for (i=0;i<=sa->Count-1;i++)
			{
				if (((Starrive^)sa[i])->s==o1) sa1=sa[i];
				if (((Starrive^)sa[i])->s==o2) sa2=sa[i];

			}
			return Math::Abs(((Starrive^)sa1)->wt-((Starrive^)sa2)->wt);
		}
	};

	ref class Da
	{
	public:
		int tn,sn,wtime,anstime;
		ArrayList ^tra,^sta;
		ArrayList ^ansr,^anst,^r,^t,^route;
		String ^st;
		bool myd;
		//IDictionaryEnumerator ^etra,^esta;
		Da()
		{
			myd=false;
			tn=0;sn=0;
			tra=gcnew ArrayList();
			sta=gcnew ArrayList();
			r=gcnew ArrayList();
			t=gcnew ArrayList();
			route=gcnew ArrayList();
	
		}
		/*Da(const Da ^o)
		{
			//IDictionaryEnumerator ^etr=o->tra->GetEnumerator();
			//IDictionaryEnumerator ^est=o->sta->GetEnumerator();
			int i;
			tn=-1;sn=-1;
			tra=gcnew ArrayList();
			sta=gcnew ArrayList();
			for (i=0;i<=o->tra->Count-1;i++)
				if (tra->Conbyindex(i))
				{
					tra->Add(o->tra->Getkey(i),gcnew Train((Train^)(o->tra[i])));
				}
			for (i=0;i<=o->sta->Count-1;i++)
				if (sta->Conbyindex(i))
				{
					sta->Add(o->sta->Getkey(i),gcnew Station((Station^)(o->sta[i])));
				}
			/*while (etr->MoveNext())
			{
				tra->Add(etr->Key,gcnew Train((Train^)etr->Value));
			}
			while (est->MoveNext())
			{
				sta->Add(est->Key,gcnew Station((Station^)est->Value));
			}
			sta=gcnew Hashtable();
			etra=tra->GetEnumerator();
			esta=sta->GetEnumerator();
		}*/
		public: Void addtra(String ^name)
		 {
			 Train ^tt=gcnew Train(name);
			 tra->Add(tt);
		 }
		public: Void moditra(Object ^o,String ^name)
		 {
			 ((Train^)o)->modify(name);
		 }

		public: Void addsta(String ^name,int x,int y)
		 {
			 Station ^tt=gcnew Station(name,x,y);
			 sta->Add(tt);
		 }
		public: Void modista(Object^ o,String ^name,int x,int y)
		 {
			 ((Station^)o)->modify(name,x,y);
		 }

	public: Void addsa(Object ^t,Object ^s,int time)
		{
			Starrive ^tt=gcnew Starrive(s,t,time); 
			((Train^)t)->addsa(tt);
			((Station^)s)->sa->Add(tt);
		}

	public: Void remsa(Object ^o)
		 {
			 ((Station^)(((Starrive^)o)->s))->sa->Remove(o);
			 ((Train^)(((Starrive^)o)->t))->sa->Remove(o);
		 }
	public: Void modisa(Object ^o,int time)
		{
			((Train^)(((Starrive^)o)->t))->sa->Remove(o);
			((Starrive^)o)->modify(time);
			((Train^)(((Starrive^)o)->t))->addsa(o);

		}
	public: Void remsta(Object ^o)
		 {
			 int i;
			 while (((Station^)o)->sa->Count>0)
			 {
				remsa(((Station^)o)->sa[0]);
			 }
			 sta->Remove(o);

		 }
	public: Void remtra(Object ^o)
		 {
			 int i;
			 while (((Train^)o)->sa->Count>0)
			 {
				remsa(((Train^)o)->sa[0]);
			 }
			 tra->Remove(o);
		 }
	public: Void mydata()
			{
				if (!myd)
				{
					myd=true;
					addtra("一号线");
					addtra("二号线");
					addtra("三号线");
					addsta("站点1",100,200);
					addsta("站点2",200,100);
					addsta("站点3",200,200);
					addsta("站点4",200,300);
					addsta("站点5",300,100);
					addsta("站点6",300,200);
					addsta("站点7",300,300);
					addsta("站点8",400,200);
					addsa(tra[0],sta[0],0);
					addsa(tra[0],sta[1],5);
					addsa(tra[0],sta[2],10);
					addsa(tra[0],sta[3],15);
					addsa(tra[1],sta[7],0);
					addsa(tra[1],sta[4],3);
					addsa(tra[1],sta[5],6);
					addsa(tra[1],sta[6],9);
					addsa(tra[2],sta[1],0);
					addsa(tra[2],sta[5],1);
					addsa(tra[2],sta[3],2);
				}
			}
	public: void dfs(Object ^o1,Object ^o2,int nowt)
			{
				Station ^now=(Station^)o1,^to=(Station^)o2;
				int i,j;
				if (!Object::ReferenceEquals(now,to))
				{
					for (i=0;i<=now->sa->Count-1;i++)
					{
						Train ^tt=((Train^)((Starrive^)(now->sa[i]))->t);
						if (t->LastIndexOf(tt)<0)
						{
							t->Add(tt);
							for (j=0;j<=tt->sa->Count-1;j++)
							{
								Station ^next=((Station^)((Starrive^)(tt->sa[j]))->s);
								if (r->LastIndexOf(next)<0)
								{
									r->Add(next);
									dfs(next,to,nowt+tt->dis(now,next)+wtime);
									r->Remove(next);
								}
							}
							t->Remove(tt);
						}
					}
				}
				else 
				{
					if ((anstime<0)||(anstime>nowt-wtime))
					{
						anstime=nowt-wtime;
						anst=gcnew ArrayList(t);
						ansr=gcnew ArrayList(r);
					}
				}
			}
	public: Void searchroute(Object ^o1,Object ^o2,int time)
			{
				Station ^s1=(Station^)o1,^s2=(Station^)o2;
				anstime=-1;
				wtime=time;
				r->Clear();
				t->Clear();
				r->Add(s1);
				dfs(s1,s2,0);
				r->Remove(s1);
				int i,j;
				if (anstime>=0)
				{
				st=s1->name;
				route->Clear();
				for (i=1;i<=ansr->Count-1;i++)
				{
					if (i==ansr->Count-1)st=st+"->乘坐"+((Train^)anst[i-1])->name+"("+((Train^)anst[i-1])->dis(ansr[i-1],ansr[i]).ToString()+"分)->"+((Station^)ansr[i])->name+"（共"+anstime.ToString()+"分）"; 
					else st=st+"->乘坐"+((Train^)anst[i-1])->name+"("+((Train^)anst[i-1])->dis(ansr[i-1],ansr[i]).ToString()+"分)->"+((Station^)ansr[i])->name+"（等车"+wtime.ToString()+"分）";
					bool flag=false;
					route->Add(ansr[i-1]);
					for (j=0;j<=((Train^)anst[i-1])->sa->Count-1;j++)
					{
						
						if (flag) route->Add(((Starrive^)((Train^)anst[i-1])->sa[j])->s);
						if ((!flag)&&(((Starrive^)((Train^)anst[i-1])->sa[j])->s==ansr[i])) break;
						if (((Starrive^)((Train^)anst[i-1])->sa[j])->s==ansr[i-1]) flag=!flag;
						if (((Starrive^)((Train^)anst[i-1])->sa[j])->s==ansr[i]) flag=!flag;

					}
					for (j=((Train^)anst[i-1])->sa->Count-1;j>=0;j--)
					{
						
						if (flag) route->Add(((Starrive^)((Train^)anst[i-1])->sa[j])->s);
						if ((!flag)&&(((Starrive^)((Train^)anst[i-1])->sa[j])->s==ansr[i])) break;
						if (((Starrive^)((Train^)anst[i-1])->sa[j])->s==ansr[i-1]) flag=!flag;
						if (((Starrive^)((Train^)anst[i-1])->sa[j])->s==ansr[i]) flag=!flag;

					}
					route->Add(ansr[i]);

				}
				}
				else st="不存在路径";

				
				
				
			}

	};


}
