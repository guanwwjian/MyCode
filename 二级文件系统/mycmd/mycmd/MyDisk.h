#include<fstream>
#include<string>
using namespace std;
#define bsize 512
int cr=0,cw=0;
class MyDisk
{	
private:
	fstream fs;
	bool op,changed;
	char buf[bsize];
	int bno;
	unsigned int fansize;
public:
	void init()
	{
		int i;
		op=false;
		changed=false;
		bno=-1;
		for (i=0;i<=bsize;i++) buf[i]=0;
	}
	MyDisk()
	{
		init();
	}
	bool Opened()
	{
		return op;
	}
	void close()
	{
		updatefan();
		init();
		fs.close();
	}
	void open(char* filename,int mode=ios::out|ios::in|ios::binary)
	{
		if (op) close();
		fs.open(filename,mode);
		op=true;
	}
	unsigned int ftol(unsigned int fno,unsigned int off)
	{
		return (fno*bsize+off);
	}
	void updatefan()
	{
		if (changed)
		{
			changed=false;
			writefan(bno);	
		}
	}
	void readfan(unsigned int fno)
	{
		if (fno!=bno)
		{
			cr++;
			updatefan();
			fs.seekp(fno*bsize,ios::beg);
			fs.seekg(fno*bsize,ios::beg);
			if (fs.eof()) memset(buf,0,sizeof(buf));
			else fs.read(buf,sizeof(buf));
			bno=fno;
		}
	}
	void writefan(unsigned int fno)
	{
		cw++;
		updatefan();
		fs.seekp(fno*bsize,ios::beg);
		fs.seekg(fno*bsize,ios::beg);
		fs.write(buf,sizeof(buf));
		bno=fno;
	}
	char readchar(unsigned int loc)
	{
		if (bno!=loc/bsize) readfan(loc/bsize);
		return buf[loc%bsize];
	}
	void writechar(char c,unsigned int loc)
	{
		if (bno!=loc/bsize) readfan(loc/bsize);
		changed=true;
		buf[loc%bsize]=c;

	}
	void read(char *c,unsigned int size,unsigned int loc)
	{
		unsigned int i;
		for (i=0;i<=size-1;i++)
		{
			unsigned int now=loc+i;
			c[i]=readchar(now);
		}
	}
	void write(char *c,unsigned int size,unsigned int loc)
	{
		unsigned int i;
		for (i=0;i<=size-1;i++)
		{
			unsigned int now=loc+i;
			writechar(c[i],now);
		}
	}
	void setbuf(char c,int x)
	{
		buf[x]=c;
		changed=true;
	}
	char getbuf(int x)
	{
		return buf[x];
	}
	MyDisk(char* filename,int mode=ios::out|ios::in|ios::binary)
	{
		init();
		open(filename,mode);
	}
	~MyDisk()
	{
		if (op) close();
	}
	
};