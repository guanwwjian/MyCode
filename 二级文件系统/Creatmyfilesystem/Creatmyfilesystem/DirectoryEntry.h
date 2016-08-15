class DirectoryEntry
{
	/* static members */
public:
	static const int DIRSIZ = 28;	/* 目录项中路径部分的最大字符串长度 */
	static const int size=DIRSIZ+4;
	/* Functions */
public:
	/* Constructors */
	//DirectoryEntry();
	/* Destructors */
	//~DirectoryEntry();

	/* Members */
public:
	int m_ino;		/* 目录项中Inode编号部分 */
	char m_name[DIRSIZ];	/* 目录项中路径名部分 */
	DirectoryEntry::DirectoryEntry()
	{
		int i;
		m_ino = -1;
		for (i=0;i<=DIRSIZ-1;i++) m_name[i] = '\0';
	}
};