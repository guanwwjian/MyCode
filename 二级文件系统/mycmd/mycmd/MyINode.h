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
	unsigned int i_isdir;	/* ״̬�ı�־λ�������enum INodeFlag */
	int		i_nlink;		/* �ļ���������������ļ���Ŀ¼���в�ͬ·���������� */
	
	short	i_uid;			/* �ļ������ߵ��û���ʶ�� */
	short	i_gid;			/* �ļ������ߵ����ʶ�� */
	
	int		i_size;			/* �ļ���С���ֽ�Ϊ��λ */
	int		i_addr[10];		/* �����ļ��߼���ú�������ת���Ļ��������� */
	
	int		i_atime;		/* ������ʱ�� */
	int		i_mtime;		/* ����޸�ʱ�� */
	MyINode()
	{
		/* 
		* ���MyDiskInodeû�й��캯�����ᷢ�����½��Ѳ���Ĵ���
		 * MyDiskInode��Ϊ�ֲ�����ռ�ݺ���Stack Frame�е��ڴ�ռ䣬����
		 * ��οռ�û�б���ȷ��ʼ�����Ծɱ�������ǰջ���ݣ����ڲ�����
		 * MyDiskInode�����ֶζ��ᱻ���£���MyDiskInodeд�ص�������ʱ������
		 * ����ǰջ����һͬд�أ�����д�ؽ������Ī����������ݡ�
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