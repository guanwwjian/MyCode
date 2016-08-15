#include"102342TreeNode.h"
struct MidCode
{
	int no;
	string d[4];
	MidCode *next,*prev;
	MidCode()
	{
		next=(MidCode*)0;
		prev=(MidCode*)0;
	}
};
class MidCodeManager
{
	MidCode *first,*last;
	int lcount;
public:
	MidCodeManager()
	{
		lcount=10000;
		first=new MidCode();
		last=first;
		first->no=0;
	}
	~MidCodeManager()
	{
		lcount=0;
		MidCode* p;
		while (first->next)
		{
			p=first;
			first=first->next;
			delete p;
		}
		p=first;
		delete p;
	}
	void emit(string s0,string s1,string s2,string s3)
	{
		MidCode* p;
		lcount++;
		p=new MidCode;
		p->no=lcount;
		p->d[0]=s0;
		p->d[1]=s1;
		p->d[2]=s2;
		p->d[3]=s3;
		last->next=p;
		p->prev=last;
		last=p;
	}
	void fout(_TCHAR* file)
	{
		ofstream ofs(file);
		MidCode* p;
		p=first;
		while (p->next)
		{
			p=p->next;
			ofs<<p->no<<":"<<"("<<p->d[0].c_str()<<","<<p->d[1].c_str()<<","<<p->d[2].c_str()<<","<<p->d[3].c_str()<<")"<<endl;
		}
		ofs.close();
	}
	MidCode* find(int x)
	{
		MidCode* p;
		p=first;
		if (p->no==x) return p;
		while (p->next)
		{
			p=p->next;
			if (p->no==x) return p;
		}
		return (MidCode*)0;
	}
	int nextquad()
	{
		return lcount+1;
	}
	string itostr(int x)
	{
		string ans;
		stringstream s;
		s<<x;
		s>>ans;
		return ans;
	}
	bool backpatch(List *list,int x)
	{
		ListNode *pp;
		pp=list->first;
		while (pp->next)
		{
			pp=pp->next;
			MidCode* p=find(pp->val);
			if (!p) return false;
			p->d[3]=itostr(x);
		}
		return true;
	}
	/*int mtoi(string s)
	{
		sstream ss;
		char c;
		int ans;
		ss<<s;
		ss>>c;
		ss>>ans;
		return ans;
	}*/
	string memi(string s)
	{
		if (s[0]=='[') return "word ptr MEM"+s;
		else return s;
	}
	void masmcseg(ofstream &ofs)
	{
		ofs<<"CSEG SEGMENT\n	ASSUME DS:DSEG, CS:CSEG\nMAIN PROC FAR\n	MOV AX,DSEG\n	MOV DS,AX\n";
		MidCode *p;
		p=first;
		while (p->next)
		{
			p=p->next;
			ofs<<"l"<<p->no<<":";
			if (p->d[0]=="j") ofs<<"	JMP l"<<p->d[3]<<endl;
			else if (p->d[0]==":=")
			{
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[1][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[1]<<endl;
					ofs<<"	MOV word ptr MEM"<<p->d[3]<<",BX"<<endl;
				}
				else ofs<<"	MOV word ptr MEM"<<p->d[3]<<","<<p->d[1]<<endl;
			}
			else if (p->d[0]=="j=")
			{
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[2][0]=='[') ofs<<"	CMP "<<memi(p->d[1])<<",BX"<<endl;
				else ofs<<"	CMP "<<memi(p->d[1])<<","<<p->d[2]<<endl;
				ofs<<"	JE l"<<p->d[3]<<endl;
				
			}
			else if (p->d[0]=="j<>")
			{
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[2][0]=='[') ofs<<"	CMP "<<memi(p->d[1])<<",BX"<<endl;
				else ofs<<"	CMP "<<memi(p->d[1])<<","<<p->d[2]<<endl;
				ofs<<"	JNE l"<<p->d[3]<<endl;
			}
			else if (p->d[0]=="j>")
			{
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[2][0]=='[') ofs<<"	CMP "<<memi(p->d[1])<<",BX"<<endl;
				else ofs<<"	CMP "<<memi(p->d[1])<<","<<p->d[2]<<endl;
				ofs<<"	JG l"<<p->d[3]<<endl;
			}
			else if (p->d[0]=="j>=")
			{	
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[2][0]=='[') ofs<<"	CMP "<<memi(p->d[1])<<",BX"<<endl;
				else ofs<<"	CMP "<<memi(p->d[1])<<","<<p->d[2]<<endl;
				ofs<<"	JGE l"<<p->d[3]<<endl;
			}
			else if (p->d[0]=="j<")
			{
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[2][0]=='[') ofs<<"	CMP "<<memi(p->d[1])<<",BX"<<endl;
				else ofs<<"	CMP "<<memi(p->d[1])<<","<<p->d[2]<<endl;
				ofs<<"	JL l"<<p->d[3]<<endl;
			}
			else if (p->d[0]=="j<=")
			{
				if (p->d[2][0]=='[')
				{
					ofs<<"	MOV BX,word ptr MEM"<<p->d[2]<<endl;
				}
				if (p->d[2][0]=='[') ofs<<"	CMP "<<memi(p->d[1])<<",BX"<<endl;
				else ofs<<"	CMP "<<memi(p->d[1])<<","<<p->d[2]<<endl;
				ofs<<"	JLE l"<<p->d[3]<<endl;
			}	
			else if (p->d[0]=="+")
			{
				ofs<<"	MOV AX,"<<memi(p->d[1])<<endl;
				ofs<<"	MOV BX,"<<memi(p->d[2])<<endl;
				ofs<<"	ADD AX,BX"<<endl;
				ofs<<"	MOV word ptr MEM"<<p->d[3]<<",AX"<<endl;

			}
			else if (p->d[0]=="-")
			{
				ofs<<"	MOV AX,"<<memi(p->d[1])<<endl;
				ofs<<"	MOV BX,"<<memi(p->d[2])<<endl;
				ofs<<"	SUB AX,BX"<<endl;
				ofs<<"	MOV word ptr MEM"<<p->d[3]<<",AX"<<endl;

			}
			else if (p->d[0]=="*")
			{
				ofs<<"	MOV AX,"<<memi(p->d[1])<<endl;
				ofs<<"	MOV BX,"<<memi(p->d[2])<<endl;
				ofs<<"	IMUL BX"<<endl;
				ofs<<"	MOV word ptr MEM"<<p->d[3]<<",AX"<<endl;

			}
			else if (p->d[0]=="/")
			{
				ofs<<"	MOV AX,"<<memi(p->d[1])<<endl;
				ofs<<"	MOV BX,"<<memi(p->d[2])<<endl;
				ofs<<"	CWD"<<endl;
				ofs<<"	IDIV BX"<<endl;
				ofs<<"	MOV word ptr MEM"<<p->d[3]<<",AX"<<endl;

			}
		
		}
		ofs<<"l"<<nextquad()<<":	MOV AH,4CH\n	INT 21H\nMAIN ENDP\nCSEG ENDS\nEND MAIN";
	}
};