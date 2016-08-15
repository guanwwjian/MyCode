#define isize 64;
class MyINode
{
	/* Functions */
public:
	/* Constructors */
	//MyDiskInode();
	/* Destructors */
	//~MyDiskInode();

	/* Members */
public:
	unsigned int i_isdir;	/* 状态的标志位，定义见enum INodeFlag */
	int		i_nlink;		/* 文件联结计数，即该文件在目录树中不同路径名的数量 */
	
	short	i_uid;			/* 文件所有者的用户标识数 */
	short	i_gid;			/* 文件所有者的组标识数 */
	
	int		i_size;			/* 文件大小，字节为单位 */
	int		i_addr[10];		/* 用于文件逻辑块好和物理块好转换的基本索引表 */
	
	int		i_atime;		/* 最后访问时间 */
	int		i_mtime;		/* 最后修改时间 */
	MyINode()
	{
		/* 
		* 如果MyDiskInode没有构造函数，会发生如下较难察觉的错误：
		 * MyDiskInode作为局部变量占据函数Stack Frame中的内存空间，但是
		 * 这段空间没有被正确初始化，仍旧保留着先前栈内容，由于并不是
		 * MyDiskInode所有字段都会被更新，将MyDiskInode写回到磁盘上时，可能
		 * 将先前栈内容一同写回，导致写回结果出现莫名其妙的数据。
		 */
		this->i_isdir = 0;
		this->i_nlink = 0;
		this->i_uid = -1;
		this->i_gid = -1;
		this->i_size = 0;
		for(int i = 0; i < 10; i++)
		{
			this->i_addr[i] = -1;
		}
		this->i_atime = 0;
		this->i_mtime = 0;
	}
	void clear()
	{
		this->i_isdir = 0;
		this->i_nlink = 0;
		this->i_uid = -1;
		this->i_gid = -1;
		this->i_size = 0;
		for(int i = 0; i < 10; i++)
		{
			this->i_addr[i] = -1;
		}
		this->i_atime = 0;
		this->i_mtime = 0;
	}

};