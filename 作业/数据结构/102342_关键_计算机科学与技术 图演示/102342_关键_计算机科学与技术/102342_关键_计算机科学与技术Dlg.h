// 102342_�ؼ�_�������ѧ�뼼��Dlg.h : ͷ�ļ�
//

#pragma once


// CMy102342_�ؼ�_�������ѧ�뼼��Dlg �Ի���
class CMy102342_�ؼ�_�������ѧ�뼼��Dlg : public CDialog
{
// ����
public:
	CMy102342_�ؼ�_�������ѧ�뼼��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY102342___DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
#define maxno 0x7fffffff

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton4();
	CButton *b1,*b2,*b3,*b4,*b5,*b6,*b7,*b8;
	CEdit *t1,*t2,*t3,*t4,*t5,*t6,*t7,*t8;
	CSpinButtonCtrl *s1,*s2,*s3,*s4,*s6;
	CStatic *l11;
	//CScrollBar *csb;
	CClientDC *dc;
	afx_msg void OnNMThemeChangedSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	void DrawPic();
	void UpDate();
	afx_msg void OnBnClickedButton2();
	int a[256][256],c[256][256],d[256][256],ln[256],n,inl[256],outl[256],p,m,px[256],py[256];
	bool b[256][256];
	afx_msg void OnNMThemeChangedSpin4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit8();
	void dfs(int x,CString &st);
	void dfsl(int x,CString &st);
	void bfs(int x,CString &st);
	void add(int x,int y,int z);
	void arrow(int fx1,int fy1, int tx1, int ty1,int len);
	void line(int fx,int fy,int len,double r);
	CPen *pen;
	CBrush *brush;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult);
};
