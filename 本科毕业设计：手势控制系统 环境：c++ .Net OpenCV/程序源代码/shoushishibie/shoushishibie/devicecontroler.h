//__declspec(dllimport) Void mouse_event(int dwFlags,int dx,int dy,int dwData,unsigned long *dwExtraInfo);
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Input;
using namespace System::Drawing;
using namespace System;
using namespace System::Diagnostics;
struct POINTAPI
{
	long x,y;
};
typedef POINTAPI *LPPOINT;
ref struct RECT
{
public:
	int Left;
    int Top;
    int Right;
    int Bottom;
};
ref class Devicecontroler
{
	static const int MOUSEEVENTF_MOVE = 0x0001;
    static const int MOUSEEVENTF_LEFTDOWN = 0x0002;
    static const int MOUSEEVENTF_LEFTUP = 0x0004;
    static const int MOUSEEVENTF_RIGHTDOWN = 0x0008;
    static const int MOUSEEVENTF_RIGHTUP = 0x0010;
    static const int MOUSEEVENTF_MIDDLEDOWN = 0x0020;
    static const int MOUSEEVENTF_MIDDLEUP = 0x0040;
    static const int MOUSEEVENTF_ABSOLUTE = 0x8000;
	static const unsigned int OCR_NORMAL = 32512;
	static const unsigned int OCR_IBEAM = 32513;
	static const int APPCOMMAND_VOLUME_MUTE = 0x80000;
	static const int APPCOMMAND_VOLUME_UP = 0x0a0000;
	static const int APPCOMMAND_VOLUME_DOWN = 0x090000;
	static const int WM_APPCOMMAND = 0x319;
	static const int KEYEVENTF_KEYUP = 0x2;
	IntPtr oldcursor; 
	Process ^proc;

public:
	[DllImport("user32.dll")]
	static int SetCursorPos(int x, int y);
	[DllImport("user32.dll")]
	static bool GetCursorPos(LPPOINT lpPoint);
	[DllImport("user32.dll")]
	static int mouse_event(int dwFlags, int dx, int dy, int cButtons, int dwExtraInfo);
	[DllImport("User32.DLL")]
	static bool SetSystemCursor(IntPtr hcur, unsigned int id);
	[DllImport("User32.DLL")]
	static IntPtr GetCursor();
	[DllImport("User32.DLL")]
	static IntPtr LoadCursor(IntPtr hInstance, unsigned int cursor);
	[DllImport("User32.DLL")]
	static IntPtr CopyCursor(IntPtr pcur);
	[DllImport("user32.dll")]
	static IntPtr GetDC(IntPtr hwnd);
	[DllImport("user32.dll")]
	static int RedrawWindow(IntPtr hWnd, IntPtr lprcUpdate, IntPtr hrgnUpdate, int flags);
	[DllImport("user32.dll")]
	static void keybd_event(char bVk,char bScan,int dwFlags,int dwExtraInfo); 
	[DllImport("user32.dll")]
	static IntPtr SendMessageW(IntPtr hWnd, int Msg, IntPtr wParam, IntPtr lParam);
	Devicecontroler()
	{
		oldcursor=System::Windows::Forms::Cursors::Arrow->CopyHandle();
		proc = Process::GetCurrentProcess();
	}
	static void cursormove(int x,int y)
	{
		POINTAPI curpos;
		GetCursorPos(&curpos);
		SetCursorPos(curpos.x+x,curpos.y+y);
	}
	static void lclick()
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
	static void rclick()
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	}
	static void setcursor(String ^s)
	{
		System::Windows::Forms::Cursor ^c=gcnew System::Windows::Forms::Cursor(s);
		SetSystemCursor(c->CopyHandle(),OCR_NORMAL);
	}
	void resetcursor()
	{
		SetSystemCursor(oldcursor,OCR_NORMAL);
		oldcursor=System::Windows::Forms::Cursors::Arrow->CopyHandle();
	}
	static Graphics ^getscreen()
	{
		return Graphics::FromHdc(GetDC((IntPtr)0));
	};
	static void refreshscreen()
	{
		RedrawWindow(IntPtr::Zero,IntPtr::Zero,IntPtr::Zero,0x85);
	}
	static void keyclick(int no)
	{
		keybd_event(no,0,0,0);
		if (no==93) keybd_event(no, 0, KEYEVENTF_KEYUP,0);
	}
	void addvol(int x)
	{
		for (int i = 0; i < x; i++) 
		{
			SendMessageW(proc->Handle, WM_APPCOMMAND,proc->Handle, (IntPtr)APPCOMMAND_VOLUME_UP);
		}
	}
	void subvol(int x)
	{
		for (int i = 0; i < x; i++) 
		{
			SendMessageW(proc->Handle, WM_APPCOMMAND,proc->Handle, (IntPtr)APPCOMMAND_VOLUME_DOWN);
		}
	}
	void changevol(int x)
	{
		if (x>0) addvol(x);
		else if (x<0) subvol(-x);
	}
};