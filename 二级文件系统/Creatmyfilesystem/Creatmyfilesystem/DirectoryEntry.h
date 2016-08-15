class DirectoryEntry
{
	/* static members */
public:
	static const int DIRSIZ = 28;	/* Ŀ¼����·�����ֵ�����ַ������� */
	static const int size=DIRSIZ+4;
	/* Functions */
public:
	/* Constructors */
	//DirectoryEntry();
	/* Destructors */
	//~DirectoryEntry();

	/* Members */
public:
	int m_ino;		/* Ŀ¼����Inode��Ų��� */
	char m_name[DIRSIZ];	/* Ŀ¼����·�������� */
	DirectoryEntry::DirectoryEntry()
	{
		int i;
		m_ino = -1;
		for (i=0;i<=DIRSIZ-1;i++) m_name[i] = '\0';
	}
};