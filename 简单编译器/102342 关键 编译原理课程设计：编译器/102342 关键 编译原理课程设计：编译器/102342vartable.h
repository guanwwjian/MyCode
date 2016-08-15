struct VarTableNode
{
	VarTableNode *next;
	string name;
	int group;//1:常量 2：变量 3：临时量
	int val,offset;
	VarTableNode()
	{
		next=(VarTableNode*)0;
	}

};
class VarTable
{
public:
	VarTableNode *first,*last;
	int length,lasttemp,lengthofint,countoftemp;
	
		VarTable()
		{
			first = new VarTableNode;
			last = first;
			//first->next=(VarTableNode *)0;
			lasttemp=0;
			lengthofint=2;
			countoftemp=2048;
			length=lengthofint*countoftemp;
		}
		~VarTable()
		{
			VarTableNode *p;
			while (first->next)
			{
				p=first;
				first=first->next;
				delete p;
			}
			p=first;
			delete p;
		}
		void insertconst(string name,int val)
		{
			VarTableNode *p;
			p = new VarTableNode;
			p->name.assign(name);
			p->group=1;
			p->val=val;
			//p->next=(VarTableNode *)0;
			last->next=p;
			last=p;
		}
		int insertvar(string name)
		{
			VarTableNode *p;
			p = new VarTableNode;
			p->name.assign(name);
			p->group=2; 
			p->offset=length;
			length+=lengthofint;
			//p->next=(VarTableNode *)0;
			last->next=p;
			last=p;
			return p->offset;
		}
		int inserttemp()
		{
			int ans;
			if (lasttemp>=countoftemp*lengthofint) return -1;
			ans=lasttemp;
			lasttemp+=lengthofint;
			return ans;
		}
		string addtemp()
		{
			int ans;
			if (lasttemp>=countoftemp*lengthofint) return "";
			ans=lasttemp;
			lasttemp+=lengthofint;
			return "["+itostr(ans)+"]";
		}
		void cleartemp()
		{
			lasttemp=0;

		}
		int check(string name)
		{
				string na(name);
				VarTableNode *p;
				p=first;
				while (p->next)
				{
					p=p->next;
					if (!(p->name.compare(na)))
					{
						return p->group;
					}
				}
				return 0;
		}
		VarTableNode *lookup(string name)
		{
				VarTableNode *p;
				p=first;
				while (p->next)
				{
					p=p->next;
					if (!(p->name.compare(name)))
					{
						return p;
					}
				}
				return (VarTableNode *)0;
		}
		string itostr(int x)
		{
			string ans;
			stringstream s;
			s<<x;
			s>>ans;
			return ans;
		}
		/*string stroffset(string name)
		{
			VarTableNode *p=lookup(name);
			if (p->group>=2)
			{
				return "["+itostr(p->offset)+"]";
			}
			return "";
		}*/
		string getplace(string name)
		{
			VarTableNode *p=lookup(name);
			if (!p) return "";
			if (p->group==1) return itostr(p->val);
			else return "["+itostr(p->offset)+"]";
			
		}
		void masmdseg(ofstream &ofs)
		{
			ofs<<"DSEG SEGMENT\n	MEM DB "<<length<<" DUP(0)\nDSEG ENDS\n";
		}
};