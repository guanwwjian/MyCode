// 102342_关键_计算机科学与技术Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include <cmath>
#include "102342_关键_计算机科学与技术.h"
#include "102342_关键_计算机科学与技术Dlg.h"
#define pi 3.141592654
#define PI 3.141592654

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy102342_关键_计算机科学与技术Dlg 对话框


	/*int CMy102342_关键_计算机科学与技术Dlg::a[256][256];
	int CMy102342_关键_计算机科学与技术Dlg::c[256][256];
	int CMy102342_关键_计算机科学与技术Dlg::d[256][256];
	int CMy102342_关键_计算机科学与技术Dlg::l[256];
    int	CMy102342_关键_计算机科学与技术Dlg::n;
	bool CMy102342_关键_计算机科学与技术Dlg::b[256][256];*/

CMy102342_关键_计算机科学与技术Dlg::CMy102342_关键_计算机科学与技术Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy102342_关键_计算机科学与技术Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy102342_关键_计算机科学与技术Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy102342_关键_计算机科学与技术Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton4)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SPIN1, &CMy102342_关键_计算机科学与技术Dlg::OnNMThemeChangedSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, &CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, &CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin4)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CMy102342_关键_计算机科学与技术Dlg::OnNMThemeChangedScrollbar1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton2)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SPIN4, &CMy102342_关键_计算机科学与技术Dlg::OnNMThemeChangedSpin4)
	ON_EN_CHANGE(IDC_EDIT7, &CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT4, &CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT8, &CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit8)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, &CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin6)
END_MESSAGE_MAP()


// CMy102342_关键_计算机科学与技术Dlg 消息处理程序

BOOL CMy102342_关键_计算机科学与技术Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	b1=(CButton*)GetDlgItem(IDC_BUTTON1);
	b2=(CButton*)GetDlgItem(IDC_BUTTON2);
	b3=(CButton*)GetDlgItem(IDC_BUTTON3);
	b4=(CButton*)GetDlgItem(IDC_BUTTON4);
	b5=(CButton*)GetDlgItem(IDC_BUTTON5);
	b6=(CButton*)GetDlgItem(IDC_BUTTON6);
	b7=(CButton*)GetDlgItem(IDC_BUTTON7);
	b8=(CButton*)GetDlgItem(IDC_BUTTON8);
	t1=(CEdit*)GetDlgItem(IDC_EDIT1);
	t2=(CEdit*)GetDlgItem(IDC_EDIT2);
	t3=(CEdit*)GetDlgItem(IDC_EDIT3);
	t4=(CEdit*)GetDlgItem(IDC_EDIT4);
	t5=(CEdit*)GetDlgItem(IDC_EDIT5);
	t6=(CEdit*)GetDlgItem(IDC_EDIT6);
	t7=(CEdit*)GetDlgItem(IDC_EDIT7);
	t8=(CEdit*)GetDlgItem(IDC_EDIT7);
	s1=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
	s2=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN2);
	s3=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN3);
	s4=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN4);
	s6=(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN6);
	l11=(CStatic*)GetDlgItem(IDC_STATIC11);
	s4->SetRange(0,255);s4->SetPos(0);
	s1->SetPos(1);s1->SetRange(1,1);
	s2->SetPos(1);s2->SetRange(1,1);
	s1->EnableWindow(false);
	s2->EnableWindow(false);
	s3->SetRange32(-2000000000,2000000000);s3->SetPos(1);
	s6->SetRange(0,0);s6->SetPos(0);
	s6->EnableWindow(false);

	n=0;
	int i,j;
	for (i=1;i<=255;i++)
	{
		inl[i]=1;
		outl[i]=1;
	}
	for (i=0;i<=255;i++)
		for (j=0;j<=255;j++)
		{
			a[i][j]=maxno;
			b[i][j]=false;
			c[i][j]=0;
			d[i][j]=maxno;
		}

	//csb=(CScrollBar*)GetDlgItem(IDC_SCROLLBAR1);
	dc=new CClientDC(GetDlgItem(IDC_STATIC));
	pen=new CPen();
	brush=new CBrush();
	dc->SelectObject(pen);
	dc->SelectObject(brush);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy102342_关键_计算机科学与技术Dlg::OnPaint()
{

	if (IsIconic())
	{
		 // 用于绘制的设备上下文
		// 使图标在工作区矩形中居中
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{	//dc->FillSolidRect(0,0,300,300,RGB(255,255,255));
		CDialog::OnPaint();
		//CClientDC dc(this);
		//dc.TextOutW(100,100,CString("12345678911111111111111111111111111111111111111111"));

	}
	DrawPic();

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy102342_关键_计算机科学与技术Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton1()
{
	//GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T("123123\r\n4123123132"));
	//dc->FillSolidRect(0,0,300,300,RGB(255,255,255));

}

void CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMy102342_关键_计算机科学与技术Dlg::OnNMThemeChangedSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	//t4->SetWindowTextW(CString("1"));
	*pResult = 0;
}

void CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//t4->SetWindowTextW(CString("1"));

	*pResult = 0;
}

void CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	*pResult = 0;
}

void CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//csb->EnableWindow(0);
//	csb->set

	*pResult = 0;
}

void CMy102342_关键_计算机科学与技术Dlg::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	//csb->SetScrollPos(50);
	/*int nTemp1 = 0;
	int nTemp2 = 0;
	int nMax=0,nMin=0;
	csb->GetScrollRange(nMin,nMax);
	nTemp1 = csb->GetScrollPos();
	switch (nSBCode)
	{
	case SB_THUMBPOSITION:
		csb->SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		nTemp2 = (nMax - nMin) / 10;
		if ( (nTemp1-nTemp2) > nMin)
		{
			nTemp1 -= nTemp2;
		}
		else
		{
			nTemp1 = nMin;
		}
		csb->SetScrollPos(nTemp1);
		break;
	case SB_LINERIGHT:
		nTemp2 = (nMax - nMin) / 10;
		if ( (nTemp1+nTemp2) > nMax)
		{
			nTemp1 = nMax;
		}
		else
		{
			nTemp1 += nTemp2;
		}
		csb->SetScrollPos(nTemp1);
		break;
	}*/

	*pResult = 0;
}
void CMy102342_关键_计算机科学与技术Dlg::add(int x,int y,int z)
{
	if (!b[x][y])
	{
		c[x][0]++;
		c[x][c[x][0]]=y;
		d[x][c[x][0]]=z;
	}
	a[x][y]=z;
	b[x][y]=true;
}
void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int x=s1->GetPos(),y=s2->GetPos(),z=s3->GetPos();
	add(x,y,z);
	UpDate();

}

void CMy102342_关键_计算机科学与技术Dlg::OnNMThemeChangedSpin4(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}

void CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	s6->SetRange(0,0);
	s6->SetPos(0);
	s6->EnableWindow(false);
	n=s4->GetPos32();
	/*int max,min;
	s4->GetRange(min,max);
	if (n>max) 
	{
		n=max;
		s4->SetPos(max);
	}
	else if (n<min)
	{
		n=min;
		s4->SetPos(min);
	}*/
	if (n)
	{
		b2->EnableWindow(true);
		b5->EnableWindow(true);
		b8->EnableWindow(true);
		b7->EnableWindow(true);
		b6->EnableWindow(true);
		b3->EnableWindow(true);
		s1->SetRange(1,n);s1->SetPos(1);
		s2->SetRange(1,n);s2->SetPos(1);
		if (n<=1)
		{
			s1->EnableWindow(false);
			s2->EnableWindow(false);


		}
		else 
		{
			s1->EnableWindow(true);
			s2->EnableWindow(true);


		}

	}
	else
	{
		b2->EnableWindow(false);
		b5->EnableWindow(false);
		b8->EnableWindow(false);
		b7->EnableWindow(false);
		b6->EnableWindow(false);
		b3->EnableWindow(false);

	}
	int i,cen=125,r=100;
	double q=0;
	for (i=1;i<=n;i++)
	{
		px[i]=cen+cos(q)*r;
		py[i]=cen+sin(q)*r;
		q+=2*PI/n;
		
	}
	UpDate();
	// TODO:  在此添加控件通知处理程序代码
}


void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int x=s1->GetPos(),y=s2->GetPos(),z=s3->GetPos();
	a[x][y]=maxno;
	b[x][y]=false;
	int i;
	for (i=1;i<=c[x][0];i++)
	{
		if (c[x][i]==y)
		{
			c[x][i]=c[x][c[x][0]];c[x][c[x][0]]=0;
			d[x][i]=d[x][c[x][0]];d[x][c[x][0]]=maxno;
			c[x][0]--;
			break;
		}
	}
	UpDate();
}
void CMy102342_关键_计算机科学与技术Dlg::UpDate()
{
	CString c1("");
	CString c2("");
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			if (b[i][j]) c1.Format(_T("%s%d "),CString(c1),a[i][j]);
			else c1+="# ";
		c1+="\r\n";
	}
	for (i=1;i<=n;i++)
	{
		c2.Format(_T("%s第%d结点: "),CString(c2),i);
		for (j=1;j<=c[i][0];j++)
		{
			c2.Format(_T("%s%d"),CString(c2),c[i][j]);
			c2.Format(_T("%s(%d) "),CString(c2),d[i][j]);
		}
		c2+="\r\n";
	}
	t1->SetWindowTextW(c1);
	t2->SetWindowTextW(c2);
	DrawPic();
}


void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	int i,j;
	for (i=0;i<=n;i++)
		for (j=0;j<=n;j++)
		{
			a[i][j]=maxno;
			b[i][j]=false;
			c[i][j]=0;
			d[i][j]=maxno;
		}
	UpDate();
}

void CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}

void CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}

void CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
		/*int max,min;
	s3->GetRange(min,max);
	if (n>max) 
	{
		n=max;
		s3->SetPos(max);
	}
	else if (n<min)
	{
		n=min;
		s3->SetPos(min);
	}*/

}

void CMy102342_关键_计算机科学与技术Dlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	/*int max,min;
	s6->GetRange(min,max);
	if (n>max) 
	{
		n=max;
		s6->SetPos(max);
	}
	else if (n<min)
	{
		n=min;
		s6->SetPos(min);
	}*/
	DrawPic();

}
void CMy102342_关键_计算机科学与技术Dlg::dfs(int x,CString &st)
{
	if (inl[x]<=0)
	{
		m++;
		inl[x]=m;
		st.Format(_T("%s%d "),CString(st),x);
		int i;
		for (i=1;i<=n;i++)
			if (b[x][i])
			{
				dfs(i,st);
			}
		m++;
		outl[x]=m;
			
	}
}
void CMy102342_关键_计算机科学与技术Dlg::dfsl(int x,CString &st)
{
		int l=1,tt,i;
		ln[1]=x;
		m++;
		inl[x]=m;
		while (l>0)
		{
			
			tt=ln[l];
			l--;
			m++;
			outl[tt]=m;
			st.Format(_T("%s%d "),CString(st),tt);
			for (i=n;i>=1;i--)
				if ((b[tt][i])&&(inl[i]<=0))
			{
					l++;
					ln[l]=i;
					m++;
					inl[i]=m;
			}
		}
}
void CMy102342_关键_计算机科学与技术Dlg::bfs(int x,CString &st)
{
		int l=1,r=2,tt,i;
		ln[1]=x;
		m++;
		inl[x]=m;
		while (l<r)
		{
			tt=ln[l];
			l++;
			m++;
			outl[tt]=m;
			st.Format(_T("%s%d "),CString(st),tt);
			for (i=1;i<=n;i++)
				if ((b[tt][i])&&(inl[i]<=0))
				{
					ln[r]=i;
					r++;
					m++;
					inl[i]=m;
				}
		}
}
void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton6()
{
	int i;
	m=0;
	for (i=1;i<=n;i++)
	{
		inl[i]=-1;
		outl[i]=-1;
	}
	CString st("");
	for (i=1;i<=n;i++)
		if (inl[i]<=0)
			dfs(i,st);
	t3->SetWindowTextW(st);
	s6->SetRange32(0,m+1);
	s6->SetPos32(0);
	s6->EnableWindow(true);
	CString st1;
	st1.Format(_T("%d"),m+1);
	l11->SetWindowTextW(st1);

}
void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton7()
{
		int i;
	m=0;
	for (i=1;i<=n;i++)
	{
		inl[i]=-1;
		outl[i]=-1;
	}
	CString st("");
	for (i=1;i<=n;i++)
		if (inl[i]<=0)
			dfsl(i,st);
	t3->SetWindowTextW(st);
	s6->SetRange32(0,m+1);
	s6->SetPos32(0);
	s6->EnableWindow(true);
	CString st1;
	st1.Format(_T("%d"),m+1);
	l11->SetWindowTextW(st1);
}
void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton3()
{
	int i;
	m=0;
	for (i=1;i<=n;i++)
	{
		inl[i]=-1;
		outl[i]=-1;
	}
	CString st("");
	for (i=1;i<=n;i++)
		if (inl[i]<=0)
			bfs(i,st);
	t3->SetWindowTextW(st);
	s6->SetRange32(0,m+1);
	s6->SetPos32(0);
	s6->EnableWindow(true);
	CString st1;
	st1.Format(_T("%d"),m+1);
	l11->SetWindowTextW(st1);
}
void CMy102342_关键_计算机科学与技术Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	s4->SetPos(9);
	add(1,2,1);
	add(1,3,1);
	add(2,4,1);
	add(2,5,1);
	add(3,5,1);
	add(3,6,1);
	add(7,8,1);
	add(8,9,1);
	add(9,7,1);
	UpDate();
}


void CMy102342_关键_计算机科学与技术Dlg::line(int fx,int fy,int len,double r)
{
	dc->MoveTo(fx,fy);
	int x,y;
	while (r>PI) r-=2*PI;
	while (r<=-PI) r+=2*PI;
	x=int(cos(r)*len+0.5);
	y=int(sin(r)*len+0.5);
	dc->LineTo(fx+x,fy+y);
}
void CMy102342_关键_计算机科学与技术Dlg::arrow(int fx1,int fy1, int tx1, int ty1,int len)
{
	double dl=17,l,dx=fx1-tx1,dy=fy1-ty1;
	l=sqrt(dx*dx+dy*dy);
	double fx,fy,tx,ty;
	fx=(l-dl)/l*fx1+dl/l*tx1;
	fy=(l-dl)/l*fy1+dl/l*ty1;
	tx=(l-dl)/l*tx1+dl/l*fx1;
	ty=(l-dl)/l*ty1+dl/l*fy1;
	dc->MoveTo(tx,ty);
	dc->LineTo(fx,fy);
	CString st;
	st.Format(_T("%d"),len);
	dc->TextOutW((3*fx+2*tx)/5-5,(3*fy+2*ty)/5-9,st);
	double r=atan2((double)fy-ty,(double)fx-tx);
	line(tx,ty,10,r+PI/5);
	line(tx,ty,10,r-PI/5);
}
void CMy102342_关键_计算机科学与技术Dlg::DrawPic()
{
	dc->FillSolidRect(0,0,500,500,RGB(255,255,255));
	/*COLORREF co;
	brush->CreateSolidBrush(RGB(0,255,0));
	dc->SelectObject(brush);
	pen->CreatePen(PS_SOLID,2,RGB(0,0,255));
	dc->SelectObject(pen);
	dc->Ellipse(10,10,100,100);
	arrow(100,100,250,250,100);*/
	int i,j,r=15,now;
	now=s6->GetPos32();
	//pen->CreatePen(PS_SOLID,2,RGB(0,0,0));
	dc->SelectObject(GetStockObject(NULL_PEN));
	int lev[256];
	//dc->SelectObject(brush);
	for (i=1;i<=n;i++)
	{
		if (now<inl[i]) 
		{
			lev[i]=0;
			delete brush;
			brush= new CBrush(RGB(100,100,255));
			//brush->CreateSolidBrush(RGB(100,100,255));
			dc->SelectObject(brush);
		}
		else if ((inl[i]<=now)&&(now<=outl[i]))
		{
			lev[i]=1;
			delete brush;
			brush= new CBrush(RGB(100,255,100));
			dc->SelectObject(brush);

		}
		else if (outl[i]<now)
		{
			lev[i]=2;
			delete brush;
			brush= new CBrush(RGB(255,100,100));
			dc->SelectObject(brush);

		}
		dc->Ellipse(px[i]-r,py[i]-r,px[i]+r,py[i]+r);
		CString st;
		st.Format(_T("%d"),i);
		dc->TextOutW(px[i]-5,py[i]-9,st);
	}
	//dc->SelectObject(pen);
	for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			if ((b[i][j])||(b[j][i]))
			{
				int rr=0,gg=0,bb=0;
				if ((lev[i]==2)||(lev[j]==2))
				{
					rr+=200;
				}
				if ((lev[i]==1)||(lev[j]==1))
				{
					gg+=200;
				}
				if ((lev[i]==0)||(lev[j]==0))
				{
					bb+=200;
				}
				delete pen;
				pen=new CPen(PS_SOLID,2,RGB(rr,gg,bb));
				//pen->CreatePen(PS_SOLID,2,RGB(rr,gg,bb));
				dc->SelectObject(pen);
				if (b[i][j])
				{
					int dx,dy;
					dx=r/2*cos(atan2((double)py[i]-py[j],(double)px[i]-px[j])+pi/2);
					dy=r/2*sin(atan2((double)py[i]-py[j],(double)px[i]-px[j])+pi/2);
					arrow(px[i]+dx,py[i]+dy,px[j]+dx,py[j]+dy,a[i][j]);
				}

				if (b[j][i])
				{
					int dx,dy;
					dx=r/2*cos(atan2((double)py[i]-py[j],(double)px[i]-px[j])+pi/2);
					dy=r/2*sin(atan2((double)py[i]-py[j],(double)px[i]-px[j])+pi/2);
					arrow(px[j]-dx,py[j]-dy,px[i]-dx,py[i]-dy,a[j][i]);
				}

			}

}


void CMy102342_关键_计算机科学与技术Dlg::OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	DrawPic();
	*pResult = 0;
}
