#include "SuperBlock.h"
#include "MyINode.h"
#include "MyDisk.h"
#include "DirectoryEntry.h"
#include <iostream>
#include <fstream>
using namespace std;
class MyFileSystem;
class SList
{
public:
	int no;
	int a[64];
	int b[64];
	MyFileSystem *fs;
	void clear()
	{
		int i;
		for (i=0;i<=63;i++)
		{
			a[i]=-1;
			b[i]=-1;
		}

	}
	SList()
	{
		clear();

	}
	void linkfs(MyFileSystem *mfs);
	void save()
	{
		saveto(no);
	}
	void open(int bno);
	void saveto(int bno);


};
class MyFileSystem
{
public:	
	static const int lsu=1;//超级块起始块编号
	static const int lbi=lsu+2;//第0块inode块编号
	static const int iel=8;//一块几个i节点
	static const int rootino=0;
	//static const int small=6;
	static const int sa=4;
	static const int mo=bsize/sa/2;
	static const int om_opened=1;
	static const int om_in=2;
	static const int om_out=4;
	static const int om_trunc=8;
	static const int om_app=16;
	char *name;
	MyDisk d;
	unsigned int put,get,omode; 
	MyINode myi;
	int myin;
	bool op;
	//bool ichanged;
	SuperBlock su;

	MyFileSystem()
	{
		init();
	}
	~MyFileSystem()
	{
		close();
	}
	void init()
	{
		op=false;
	}
	void close()
	{
		if (op)
		{
			op=false;
			updatei();
			d.write((char*)&su,sizeof(su),lsu*bsize);
			d.close();
		}
	}

	void open(char *c)
	{	
		//strcpy_s(name,c);
		myin=-1;
		//ichanged=false;
		op=true;
		name=c;
		d.open(name);
		d.read((char*)&su,sizeof(su),lsu*bsize);

	}
	MyFileSystem(char *c)
	{
		init();
		open(c);
	}
	unsigned int bloc(unsigned int bno)
	{
		return (lbi+su.s_isize+bno)*bsize;
	}
	bool freeb(int bno)
	{
		if (bno<0) return false;
		if (su.s_nfree==99)
		{
			unsigned int loc=bloc(bno);
			int size=sizeof(su.s_nfree);
			d.write((char*)&su.s_nfree,size,loc);
			d.write((char*)&su.s_free,sizeof(su.s_free),loc+size);
			su.s_nfree=0;
		}
		else su.s_nfree++;
		su.s_free[su.s_nfree]=bno;
		su.s_bcount++;
		return true;
	}
	int allocb()
	{
		if (su.s_bcount)
		{
			su.s_bcount--;
			int bno=su.s_free[su.s_nfree];
			if (bno<0) return -1;
			if (su.s_nfree==0)
			{
				unsigned int loc=bloc(bno);
				int size=sizeof(su.s_nfree);
				d.read((char*)&su.s_nfree,size,loc);
				d.read((char*)&su.s_free,sizeof(su.s_free),loc+size);
			}
			else su.s_nfree--;
			return bno;
		}
		else return -1;
	}
	unsigned int iloc(unsigned int ino)
	{
		return (lbi*bsize+ino*sizeof(myi));
	}
	bool freei(int ino)
	{
		int omyin=myin;
		openi(ino);
		setisize(0);
		openi(myin);
		if (ino<0) return false;
		if (su.s_ninode==99)
		{
			int nextb=allocb();
			unsigned int loc=bloc(nextb);
			int size=sizeof(su.s_ninode);
			d.write((char*)&su.s_ninode,size,loc);
			d.write((char*)&su.s_inode,sizeof(su.s_inode),loc+size);
			su.s_ninode=0;
			su.s_inode[0]=nextb;
		}
		else
		{
			su.s_ninode++;
			su.s_inode[su.s_ninode]=ino;
		}
		su.s_icount++;
		return true;
	}
	int alloci()
	{
		if (su.s_icount)
		{
			su.s_icount--;
			int ino=su.s_free[su.s_nfree];
			if (ino<0) return -1;
			if (su.s_ninode==0)
			{
				int nextb=ino;
				unsigned int loc=bloc(nextb);
				int size=sizeof(su.s_ninode);
				d.read((char*)&su.s_ninode,size,loc);
				d.read((char*)&su.s_inode,sizeof(su.s_inode),loc+size);
				return alloci();
			}
			else
			{
				su.s_nfree--;
				return ino;
			}
		}
		else return -1;
	}
	void openi(int ino,int mode=om_in|om_out)
	{
		if (ino>=0)
		{
			omode=mode;
			if (ino!=myin) updatei();
			myin=ino;
			d.read((char*)&myi,sizeof(myi),iloc(myin));
			get=0;
			if (omode&om_trunc)
			{
				setisize(0);
			}
			if (omode&om_app)
			{
				put=0;
			}
			else
			{
				put=myi.i_size;
			}
		}
	}
	void creati(int ino,int mode=om_in|om_out)
	{
		omode=mode;
		updatei();
		myin=ino;
		myi.clear();
		get=0;
		if (omode&om_trunc)
		{
			setisize(0);
		}
		if (omode&om_app)
		{
			put=0;
		}
		else
		{
			put=myi.i_size;
		}
		
	}
	void updatei()
	{
		if (myin>=0)
		{
			d.write((char*)&myi,sizeof(myi),iloc(myin));
		}
	}
	void closei()
	{
		updatei();
		myin=-1;
	}
	/*unsigned int bmap(int bno)
	{
		unsigned int i,n,tt,m[10],num[10],a[10],ans[10];
		m[0]=0;
		num[0]=5;
		n=0;tt=bno;
		while (m[n]<=bno)
		{
			i++;
			num[n]=num[n-1]*nbm/2;
			m[n]=m[n-1]+num[n-1];
		}
		tt=bno
		for (i=n;i>=0;i--)
		{
			a[i]=(tt-min[i])%(nbm);
			if (i>0) tt=(tt-min[i])/nbm+num[i-1];
		}
		ans[0]=myi.i_addr[a[0]]]
		int sa=sizeof(ans[0]);
		for (i=1;i<=n;i++)
		{
			d.read((char*)&ans[i],sa,bloc(ans[i-1])+sa*a[i]);
		}
		return ans[n];
	}

	void addb(int bno);
	{
		int n,a[10];
		bmap(bno,n,a);
		if (n==0) myi.i_addr[a[0]]=allocb();
		else tt=myi.i_addr[a[0]];
		int newb;
		for (i=1;i<=n;i++)
		{
			if (tt<0)
			{
				newb=allocb();
				int t=-1;
				for (i=0;j<=nbm-1;j++) d.write((char*)&t,sizeof(t),bloc(newb)+sizeof(t)*j);
				d.write((char*)&newb,sizeof(newb),bloc(tt)+sizeof(newb)*a[i]);
				tt=newb;

			}
			else d.read((char*)&tt,sizeof(tt),bloc(tt)+sizeof(tt)*a[i-1]);
		}
		newb=allocb();
		d.write((char*)&newb,sizeof(newb),bloc(tt)+sizeof(tt)*a[n]);
		myi.i_size+=bsize;
	}
	void remb(int bno)
	{
		int n,a[10];
		bmap(bno,n,a);
		int tt,ot;
		tt=myi.i_addr[a[0]];
		ot=-1;
	
	}*/
	unsigned int bmap(int bno)
	{
		if (bno<=8) return myi.i_addr[bno];
		else 
		{
			int tt=bno-8;
			int inmo[10],n=-1;
			while (tt>0)
			{
				n++;
				inmo[n]=tt % mo;
				tt=tt/mo;
				
			}

			int i,ans=myi.i_addr[9];
			int sa=sizeof(ans);
			for (i=0;i<=n-1;i++)
			{
				d.read((char*)&ans,sa,bloc(ans)+sa*(inmo[i]+mo));
			}
			d.read((char*)&ans,sa,bloc(ans)+sa*(inmo[i]));
			return ans;
		}

	}
	void addb(int bno)
	{
		
		if (bno>8)
		{
			int tt=bno-8;
			int inmo[10],n=-1;
			while (tt>0)
			{
				n++;
				inmo[n]=tt % mo;
				tt=tt/mo;
			}
			int i,newb;
			SList tar[10];
			for (i=0;i<=9;i++)
			{
				tar[i].linkfs(this);
			}			
			if (bno==9)
			{
				myi.i_addr[9]=allocb();
				tar[0].open(myi.i_addr[9]);
				tar[0].clear();
				tar[0].save();
			}
			else tar[0].open(myi.i_addr[9]);
			for (i=0;i<=n-1;i++)
			{
				if (tar[i].b[inmo[i]]<0) 
				{
					tar[i].a[0]++;
					tar[i].b[inmo[i]]=allocb();
					tar[i].save();
					tar[i+1].open(tar[i].b[inmo[i]]);
					tar[i+1].clear();
					tar[i+1].save();
				}
				else tar[i+1].open(tar[i].b[inmo[i]]);
			}
			tar[n].a[inmo[n]]=allocb();
			tar[n].a[0]++;
			tar[n].save();
		}
		else 
		{
			myi.i_addr[bno]=allocb();
		}

	}
	void remb(int bno)
	{
		if (bno>8)
		{
			int tt=bno-8;
			int inmo[10],n=-1;
			while (tt>0)
			{
				n++;
				inmo[n]=tt % mo;
				tt=tt/mo;
			}
			int i,newb;
			SList tar[10];
			for (i=0;i<=9;i++)
			{
				tar[i].linkfs(this);
			}			
			tar[0].open(myi.i_addr[9]);
			for (i=0;i<=n-1;i++)
			{
				tar[i+1].open(tar[i].b[inmo[i]]);
				
			}
			freeb(tar[n].a[inmo[n]]);
			tar[n].a[inmo[n]]=-1;
			tar[n].a[0]--;
			tar[n].save();
			for (i=n;i>=1;i--)
			{
				if (tar[i].a[0]<0) 
				{
					freeb(tar[i-1].b[inmo[i-1]]);
					tar[i-1].b[inmo[i-1]]=-1;
					tar[i-1].a[0]--;
					tar[i-1].save();
				}
			}
			if (tar[0].a[0]<0)
			{
				freeb(myi.i_addr[9]);
				myi.i_addr[9]=-1;
			}
		}
		else 
		{
			freeb(myi.i_addr[bno]);
			myi.i_addr[bno]=-1;
		}
	}
	void setisize(unsigned int newsize)
	{
		int i,nbn=(newsize+bsize-1)/bsize-1,bn=(myi.i_size+bsize-1)/bsize-1;
		if (nbn<bn)
		{
			for (i=bn;i>nbn;i--)
			{
				remb(i);
			}
		}
		else if (bn<nbn)
		{
			for (i=bn+1;i<=nbn;i++)
			{
				addb(i);
			}
		}
		myi.i_size=newsize;
	}
	void iread(char* c,unsigned int size,int loc)
	{
		if (omode&om_in)
		{
			unsigned int i,l;
			int bm,lb=-1;
			for (i=0;i<=size-1;i++)
			{
				l=loc+i;
				if (l/bsize!=lb)
				{
					lb=l/bsize;
					bm=bmap(l/bsize);
				}
				c[i]=d.readchar(bloc(bm)+l%bsize);
			}
		}

	}
	void iwrite(char* c,unsigned int size,unsigned int loc)
	{
		if (omode&om_out)
		{
			unsigned int i,l;
			int bm,lb=-1;
			if (loc+size>myi.i_size) setisize(loc+size);
			for (i=0;i<=size-1;i++)
			{
				l=loc+i;
				if (l/bsize!=lb)
				{
					lb=l/bsize;
					bm=bmap(l/bsize);
				}
				d.writechar(c[i],bloc(bm)+l%bsize);
			}
		}

	}
	void fread(char* c,unsigned int size)
	{

		if (omode&om_in)
		{
			unsigned int i;
			int bm,lb=-1;
			for (i=0;i<=size-1;i++)
			{
				if (get/bsize!=lb)
				{
					lb=get/bsize;
					bm=bmap(get/bsize);
				}
				c[i]=d.readchar(bloc(bm)+get%bsize);
				get++;
			}
		}

	}
	void fwrite(const char* c,unsigned int size)
	{
		if (omode&om_out)
		{
			unsigned int i;
			int bm,lb=-1;
			if (put+size>myi.i_size) setisize(put+size);
			for (i=0;i<=size-1;i++)
			{
				if (put/bsize!=lb)
				{
					lb=put/bsize;
					bm=bmap(put/bsize);
				}
				d.writechar(c[i],bloc(bm)+put%bsize);
				put++;
			}
		}

	}
	void seekp(int loc)
	{
		put=loc;
	}
	void seekg(int loc)
	{
		get=loc;
	}
	int openfileat(const char *c)
	{
		int i=1,last=0,j,n;
		DirectoryEntry di;
		char name[DirectoryEntry::DIRSIZ];
		openi(su.s_rootino);
		if (c[0]!='/') return -1;
		if (c[1]=='\0') return su.s_rootino;
		while (c[i-1]!='\0')
		{
			
			if (c[i]=='/')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						openi(di.m_ino);
						break;
					}
				}
				if (j>n)
				{
					return -1;
				}
				last=i;

			}
			else if (c[i]=='\0')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						openi(di.m_ino);
						return di.m_ino;
					}
				}
				if (j>n)
				{
					return -1;
				}

			}
			i++;
		}
	}
	void creatfile(const char *c,unsigned int isdir=0)
	{
		if (myi.i_isdir)
		{
			int newi=alloci(),omyin=myin;
			DirectoryEntry di;
			strcpy(di.m_name,c);
			di.m_ino=newi;
			iwrite((char*)&di,sizeof(di),myi.i_size);
			openi(newi);
			myi.i_isdir=isdir;
			myi.i_nlink++;
			if (isdir)
			{
				di.m_ino=newi;
				strcpy(di.m_name,".");
				iwrite((char*)&di,sizeof(di),0);
				di.m_ino=omyin;
				strcpy(di.m_name,"..");
				iwrite((char*)&di,sizeof(di),sizeof(di));
			}

		}
		
	}
	void creatname(const char *c,int ino)
	{	
			DirectoryEntry di;
			strcpy(di.m_name,c);
			di.m_ino=ino;
			iwrite((char*)&di,sizeof(di),myi.i_size);
			openi(ino);
			myi.i_nlink++;
		
	}
	void creatnameat(const char *c)
	{
		int i=1,last=0,j,omyin=myin,n;
		DirectoryEntry di;
		char name[DirectoryEntry::DIRSIZ];
		openi(su.s_rootino);
		if (c[0]!='/') return;
		if (c[1]=='\0') return;
		while (c[i-1]!='\0')
		{
			
			if (c[i]=='/')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						openi(di.m_ino);
						break;
					}
				}
				if (j>n)
				{
					creatfile(name,1);
				}

				last=i;
			}
			else if (c[i]=='\0')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						return;
					}
				}
				if (j>n)
				{
					creatname(name,omyin);
					return;
				}

			}
			i++;
		}
	}
	void creatfileat(const char *c,unsigned int isdir)
	{
		int i=1,last=0,j,omyin=myin,n;
		DirectoryEntry di;
		char name[DirectoryEntry::DIRSIZ];
		openi(su.s_rootino);
		if (c[0]!='/') return;
		if (c[1]=='\0') return;
		while (c[i-1]!='\0')
		{
			
			if (c[i]=='/')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						openi(di.m_ino);
						break;
					}
				}
				if (j>n)
				{
					creatfile(name,1);
				}

				last=i;
			}
			else if (c[i]=='\0')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						return;
					}
				}
				if (j>n)
				{
					creatfile(name,isdir);
					return;
				}

			}
			i++;
		}
	}
	void deletei(int ino)
	{
		DirectoryEntry di;
		openi(ino);
		if (myi.i_isdir)
		{
			int j;
			for (j=2;j<=myi.i_size/sizeof(di)-1;j++)
			{
				iread((char*)&di,sizeof(di),j*sizeof(di));
				openi(di.m_ino);
				myi.i_nlink--;
				deletei(di.m_ino);
				openi(ino);
			}
		}
		freei(ino);
		
	}
	int deletenameat(const char *c)
	{
		int i=1,last=0,j,omyin=myin,n;
		DirectoryEntry di;
		char name[DirectoryEntry::DIRSIZ];
		openi(su.s_rootino);
		if (c[0]!='/') return -1;
		if (c[1]=='\0') return -1;
		while (c[i-1]!='\0')
		{
			
			if (c[i]=='/')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						openi(di.m_ino);
						break;
					}
				}
				if (j>n)
				{
					return -1;
				}
				last=i;

			}
			else if (c[i]=='\0')
			{
				for (j=0;j<=i-last-2;j++)
				{
					name[j]=c[last+j+1];
				}
				name[i-last-1]='\0';
				//seekg(0);
				n=myi.i_size/sizeof(di)-1;
				for (j=0;j<=n;j++)
				{
					iread((char*)&di,sizeof(di),j*sizeof(di));
					if (!strcmp(name,di.m_name))
					{
						int ino=di.m_ino;
						iread((char*)&di,sizeof(di),(myi.i_size/sizeof(di)-1)*sizeof(di));
						iwrite((char*)&di,sizeof(di),j*sizeof(di));
						setisize(myi.i_size-sizeof(di));
						openi(ino);
						myi.i_nlink--;
						if (!myi.i_nlink)
						{	
							deletei(ino);
						}
						return ino;
					}
				}
				if (j>n)
				{
					return -1;
				}

			}
			i++;
		}
	}
	void fcreat(const char *c,unsigned int isdir=0,int mode=om_in|om_out)
	{
		//int newi=alloci();
		//creati(newi);
		creatfileat(c,isdir);
		openi(myin,mode);
	}
	int fopen(const char *c,int mode=om_in|om_out)
	{
		int ino=openfileat(c);
		openi(ino,mode);
		return ino;
	}
	void fclose()
	{
		closei();
	}
	void fdelete(const char *c)
	{
		deletenameat(c);
		myin=-1;
	}
	bool eof()
	{
		return (get>=myi.i_size);
	}
	void CreatMyDisk(char *c,int ln)
	{
		name=c;
		int i;
		int iln=(ln-lbi)/(iel+1);
		d.open(name,ios::out|ios::in|ios::trunc|ios::binary);
		char f[bsize]={0};
		for (i=0;i<=lsu-1;i++) d.write(f,sizeof(f),i*bsize);
		su.s_rootino=rootino;
		su.s_fsize=ln;
		su.s_isize=iln;

		su.s_nfree=0;
		su.s_free[0]=-1;
		su.s_ninode=0;
		su.s_inode[0]=-1;
		d.write((char*)&su,sizeof(su),lsu*bsize);
		MyINode ti[iel];
		for (i=lbi;i<=lbi+iln-1;i++)
		{
			d.write((char*)&ti,sizeof(ti),i*bsize);
		}
		for (i=lbi+iln;i<=ln-1;i++)
		{
			d.write(f,sizeof(f),i*bsize);
		}
		open(name);
		for (i=0;i<=ln-lbi-iln-1;i++)
		{
			freeb(i);
		}
		for (i=0;i<=iln-1;i++)
			if (i!=rootino+lbi)
			{
				freei(i);
			}
		creati(rootino);
		myi.i_isdir=1;
		myi.i_nlink=1;
		DirectoryEntry de;
		de.m_ino=rootino;
		strcpy(de.m_name,".");
		iwrite((char*)&de,sizeof(de),0);
		strcpy(de.m_name,"..");
		iwrite((char*)&de,sizeof(de),sizeof(de));
		/*fcreat("/root/aser/qwe");
		int a=321654987,b;
		iwrite((char*)&a,sizeof(a),30000);
		fclose();
		fopen("/root/aser/qwe");
		iread((char*)&b,sizeof(b),30000);
		fclose();*/


	}

};
void SList::linkfs(MyFileSystem *mfs)
{
	fs=mfs;
}
void SList::open(int bno)
{
	no=bno;
	int loc=fs->bloc(no);
	fs->d.read((char*)&a,sizeof(a),loc);
	fs->d.read((char*)b,sizeof(b),loc+sizeof(a));
}
void SList::saveto(int bno)
{
	no=bno;
	int loc=fs->bloc(no);
	fs->d.write((char*)a,sizeof(a),loc);
	fs->d.write((char*)b,sizeof(b),loc+sizeof(a));
	
}