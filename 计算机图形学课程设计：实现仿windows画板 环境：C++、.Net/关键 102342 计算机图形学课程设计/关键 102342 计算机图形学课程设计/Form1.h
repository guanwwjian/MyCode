#pragma once


namespace 关键102342计算机图形学课程设计 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStripPanel^  BottomToolStripPanel;
	protected: 
	private: System::Windows::Forms::ToolStripPanel^  TopToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^  RightToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^  LeftToolStripPanel;
	private: System::Windows::Forms::ToolStripContentPanel^  ContentPanel;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  brush;



	private: System::Windows::Forms::ToolStripMenuItem^  文件ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  新建ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  打开ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  保存ToolStripMenuItem;



	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStrip^  toolStrip2;
	private: System::Windows::Forms::ToolStripButton^  circle;

	private: array<Bitmap^> ^b;
	private: Graphics ^gra;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: Bitmap ^pre;
	private: Graphics ^gp;
	private: Pen ^p;
	private: Color ^c1,^c2;
	private: int fx,fy,tx,ty,no,f,t,size;
			 static const int mo=100;
			 bool ld,rd,cv;
			 array<Int32> ^lx,^ly;
	private: System::Windows::Forms::ToolStripMenuItem^  编辑ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  撤销ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  重复ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  sqare;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::PictureBox^  color2;

	private: System::Windows::Forms::PictureBox^  color1;

	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::PictureBox^  pictureBox15;
	private: System::Windows::Forms::PictureBox^  pictureBox16;
	private: System::Windows::Forms::PictureBox^  pictureBox17;
	private: System::Windows::Forms::PictureBox^  pictureBox18;
	private: System::Windows::Forms::PictureBox^  pictureBox19;
	private: System::Windows::Forms::PictureBox^  pictureBox20;
	private: System::Windows::Forms::PictureBox^  pictureBox21;
	private: System::Windows::Forms::PictureBox^  pictureBox22;
	private: System::Windows::Forms::PictureBox^  pictureBox23;
	private: System::Windows::Forms::PictureBox^  pictureBox24;
	private: System::Windows::Forms::PictureBox^  pictureBox25;
	private: System::Windows::Forms::PictureBox^  pictureBox26;
	private: System::Windows::Forms::PictureBox^  pictureBox27;
	private: System::Windows::Forms::PictureBox^  pictureBox28;
	private: System::Windows::Forms::PictureBox^  pictureBox29;
	private: System::Windows::Forms::PictureBox^  pictureBox30;
	private: System::Windows::Forms::PictureBox^  pictureBox31;
	private: System::Windows::Forms::PictureBox^  pictureBox32;
	private: System::Windows::Forms::PictureBox^  pictureBox33;
	private: System::Windows::Forms::PictureBox^  pictureBox34;
	private: System::Windows::Forms::PictureBox^  pictureBox35;
	private: System::Windows::Forms::PictureBox^  pictureBox36;
	private: System::Windows::Forms::PictureBox^  pictureBox37;
	private: System::Windows::Forms::PictureBox^  pictureBox38;
	private: System::Windows::Forms::PictureBox^  pictureBox39;
	private: System::Windows::Forms::PictureBox^  pictureBox40;
	private: System::Windows::Forms::PictureBox^  pictureBox41;
	private: System::Windows::Forms::PictureBox^  pictureBox42;
	private: System::Windows::Forms::PictureBox^  pictureBox43;
	private: System::Windows::Forms::PictureBox^  pictureBox44;
	private: System::Windows::Forms::PictureBox^  pictureBox45;
	private: System::Windows::Forms::PictureBox^  pictureBox46;
private: System::Windows::Forms::ToolStripButton^  pen;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::PictureBox^  pictureBox47;
private: System::Windows::Forms::PictureBox^  pictureBox48;
private: System::Windows::Forms::PictureBox^  pictureBox49;
private: System::Windows::Forms::PictureBox^  pictureBox50;
private: System::Windows::Forms::PictureBox^  pictureBox51;
private: System::Windows::Forms::ToolStripMenuItem^  清除ToolStripMenuItem;
		 ToolStripButton ^mod1,^mod2;
private: System::Windows::Forms::ToolStripButton^  fillin;
private: System::Windows::Forms::ToolStripButton^  line;
private: System::Windows::Forms::ToolStripButton^  erazer;

private: System::Windows::Forms::ToolStripButton^  getcolor;
private: System::Windows::Forms::ToolStripButton^  empty;
private: System::Windows::Forms::ToolStripButton^  ssub;
private: System::Windows::Forms::ToolStripButton^  filled;
private: System::Windows::Forms::ToolStripButton^  sadd;
private: System::Windows::Forms::ToolStripMenuItem^  另存为ToolStripMenuItem;


			 /*			 void nextb();
			 void lastb();
			 int add1(int x);
			 int sub1(int x);*/

	protected: 








	protected: 

	protected: 

	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->BottomToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->TopToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->RightToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->LeftToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->ContentPanel = (gcnew System::Windows::Forms::ToolStripContentPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->文件ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->新建ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->打开ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->保存ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->另存为ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->编辑ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->撤销ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->重复ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->清除ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->brush = (gcnew System::Windows::Forms::ToolStripButton());
			this->sqare = (gcnew System::Windows::Forms::ToolStripButton());
			this->line = (gcnew System::Windows::Forms::ToolStripButton());
			this->erazer = (gcnew System::Windows::Forms::ToolStripButton());
			this->empty = (gcnew System::Windows::Forms::ToolStripButton());
			this->ssub = (gcnew System::Windows::Forms::ToolStripButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->pen = (gcnew System::Windows::Forms::ToolStripButton());
			this->circle = (gcnew System::Windows::Forms::ToolStripButton());
			this->fillin = (gcnew System::Windows::Forms::ToolStripButton());
			this->getcolor = (gcnew System::Windows::Forms::ToolStripButton());
			this->filled = (gcnew System::Windows::Forms::ToolStripButton());
			this->sadd = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->color2 = (gcnew System::Windows::Forms::PictureBox());
			this->color1 = (gcnew System::Windows::Forms::PictureBox());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->toolStrip2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->BeginInit();
			this->SuspendLayout();
			// 
			// BottomToolStripPanel
			// 
			this->BottomToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->BottomToolStripPanel->Name = L"BottomToolStripPanel";
			this->BottomToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->BottomToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->BottomToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// TopToolStripPanel
			// 
			this->TopToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->TopToolStripPanel->Name = L"TopToolStripPanel";
			this->TopToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->TopToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->TopToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// RightToolStripPanel
			// 
			this->RightToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->RightToolStripPanel->Name = L"RightToolStripPanel";
			this->RightToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->RightToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->RightToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// LeftToolStripPanel
			// 
			this->LeftToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->LeftToolStripPanel->Name = L"LeftToolStripPanel";
			this->LeftToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->LeftToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->LeftToolStripPanel->Size = System::Drawing::Size(0, 0);
			this->LeftToolStripPanel->Click += gcnew System::EventHandler(this, &Form1::toolStripContainer1_LeftToolStripPanel_Click);
			// 
			// ContentPanel
			// 
			this->ContentPanel->Size = System::Drawing::Size(150, 175);
			this->ContentPanel->Load += gcnew System::EventHandler(this, &Form1::toolStripContainer1_ContentPanel_Load);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->文件ToolStripMenuItem, 
				this->编辑ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(796, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 文件ToolStripMenuItem
			// 
			this->文件ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->新建ToolStripMenuItem, 
				this->打开ToolStripMenuItem, this->保存ToolStripMenuItem, this->另存为ToolStripMenuItem});
			this->文件ToolStripMenuItem->Name = L"文件ToolStripMenuItem";
			this->文件ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->文件ToolStripMenuItem->Text = L"文件";
			// 
			// 新建ToolStripMenuItem
			// 
			this->新建ToolStripMenuItem->Name = L"新建ToolStripMenuItem";
			this->新建ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->新建ToolStripMenuItem->Text = L"新建";
			this->新建ToolStripMenuItem->Visible = false;
			// 
			// 打开ToolStripMenuItem
			// 
			this->打开ToolStripMenuItem->Name = L"打开ToolStripMenuItem";
			this->打开ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->打开ToolStripMenuItem->Text = L"打开";
			this->打开ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::打开ToolStripMenuItem_Click);
			// 
			// 保存ToolStripMenuItem
			// 
			this->保存ToolStripMenuItem->Name = L"保存ToolStripMenuItem";
			this->保存ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->保存ToolStripMenuItem->Text = L"保存";
			this->保存ToolStripMenuItem->Visible = false;
			// 
			// 另存为ToolStripMenuItem
			// 
			this->另存为ToolStripMenuItem->Name = L"另存为ToolStripMenuItem";
			this->另存为ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->另存为ToolStripMenuItem->Text = L"另存为";
			this->另存为ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::另存为ToolStripMenuItem_Click);
			// 
			// 编辑ToolStripMenuItem
			// 
			this->编辑ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->撤销ToolStripMenuItem, 
				this->重复ToolStripMenuItem, this->清除ToolStripMenuItem});
			this->编辑ToolStripMenuItem->Name = L"编辑ToolStripMenuItem";
			this->编辑ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->编辑ToolStripMenuItem->Text = L"编辑";
			// 
			// 撤销ToolStripMenuItem
			// 
			this->撤销ToolStripMenuItem->Enabled = false;
			this->撤销ToolStripMenuItem->Name = L"撤销ToolStripMenuItem";
			this->撤销ToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->撤销ToolStripMenuItem->Text = L"撤销";
			this->撤销ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::撤销ToolStripMenuItem_Click);
			// 
			// 重复ToolStripMenuItem
			// 
			this->重复ToolStripMenuItem->Enabled = false;
			this->重复ToolStripMenuItem->Name = L"重复ToolStripMenuItem";
			this->重复ToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->重复ToolStripMenuItem->Text = L"重复";
			this->重复ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::重复ToolStripMenuItem_Click);
			// 
			// 清除ToolStripMenuItem
			// 
			this->清除ToolStripMenuItem->Name = L"清除ToolStripMenuItem";
			this->清除ToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->清除ToolStripMenuItem->Text = L"清除";
			this->清除ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::清除ToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Left;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->brush, this->sqare, 
				this->line, this->erazer, this->empty, this->ssub});
			this->toolStrip1->Location = System::Drawing::Point(24, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->toolStrip1->Size = System::Drawing::Size(24, 542);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// brush
			// 
			this->brush->BackColor = System::Drawing::SystemColors::Control;
			this->brush->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->brush->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"brush.Image")));
			this->brush->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->brush->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->brush->Name = L"brush";
			this->brush->Size = System::Drawing::Size(21, 20);
			this->brush->Text = L"toolStripButton1";
			this->brush->ToolTipText = L"刷子";
			this->brush->Click += gcnew System::EventHandler(this, &Form1::brush_Click);
			// 
			// sqare
			// 
			this->sqare->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->sqare->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sqare.Image")));
			this->sqare->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->sqare->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->sqare->Name = L"sqare";
			this->sqare->Size = System::Drawing::Size(21, 20);
			this->sqare->Text = L"toolStripButton3";
			this->sqare->ToolTipText = L"画矩形";
			this->sqare->Click += gcnew System::EventHandler(this, &Form1::sqare_Click);
			// 
			// line
			// 
			this->line->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->line->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"line.Image")));
			this->line->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->line->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->line->Name = L"line";
			this->line->Size = System::Drawing::Size(21, 20);
			this->line->Text = L"toolStripButton1";
			this->line->ToolTipText = L"画线";
			this->line->Click += gcnew System::EventHandler(this, &Form1::line_Click);
			// 
			// erazer
			// 
			this->erazer->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->erazer->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"erazer.Image")));
			this->erazer->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->erazer->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->erazer->Name = L"erazer";
			this->erazer->Size = System::Drawing::Size(21, 20);
			this->erazer->Text = L"toolStripButton2";
			this->erazer->ToolTipText = L"橡皮擦";
			this->erazer->Click += gcnew System::EventHandler(this, &Form1::erazer_Click);
			// 
			// empty
			// 
			this->empty->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->empty->Enabled = false;
			this->empty->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"empty.Image")));
			this->empty->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->empty->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->empty->Name = L"empty";
			this->empty->Size = System::Drawing::Size(21, 20);
			this->empty->Text = L"toolStripButton2";
			this->empty->ToolTipText = L"绘制中空图形";
			this->empty->Click += gcnew System::EventHandler(this, &Form1::empty_Click);
			// 
			// ssub
			// 
			this->ssub->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ssub->Enabled = false;
			this->ssub->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ssub.Image")));
			this->ssub->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ssub->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->ssub->Name = L"ssub";
			this->ssub->Size = System::Drawing::Size(21, 20);
			this->ssub->Text = L"toolStripButton2";
			this->ssub->ToolTipText = L"刷子/橡皮尺寸减小";
			this->ssub->Click += gcnew System::EventHandler(this, &Form1::ssub_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(94, 44);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &Form1::pictureBox1_MouseLeave);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			this->pictureBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::pictureBox1_DragDrop);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &Form1::pictureBox1_MouseEnter);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"BMP|*.BMP|GIF|*.GIF|EXIF|*.EXIF|JPG|*.JPG|PNG|*.PNG|TIFF|*.TIFF|所有文件|*.*";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"BMP|*.BMP|GIF|*.GIF|EXIF|*.EXIF|JPG|*.JPG|PNG|*.PNG|TIFF|*.TIFF|所有文件|*.*";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// toolStrip2
			// 
			this->toolStrip2->Dock = System::Windows::Forms::DockStyle::Left;
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->pen, this->circle, 
				this->fillin, this->getcolor, this->filled, this->sadd});
			this->toolStrip2->Location = System::Drawing::Point(0, 0);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->toolStrip2->Size = System::Drawing::Size(24, 542);
			this->toolStrip2->TabIndex = 3;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// pen
			// 
			this->pen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->pen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pen.Image")));
			this->pen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pen->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->pen->Name = L"pen";
			this->pen->Size = System::Drawing::Size(21, 20);
			this->pen->Text = L"toolStripButton4";
			this->pen->ToolTipText = L"钢笔";
			this->pen->Click += gcnew System::EventHandler(this, &Form1::pen_Click);
			// 
			// circle
			// 
			this->circle->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->circle->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"circle.Image")));
			this->circle->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->circle->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->circle->Name = L"circle";
			this->circle->Size = System::Drawing::Size(21, 20);
			this->circle->Text = L"toolStripButton2";
			this->circle->ToolTipText = L"画圆形";
			this->circle->Click += gcnew System::EventHandler(this, &Form1::circle_Click);
			// 
			// fillin
			// 
			this->fillin->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->fillin->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"fillin.Image")));
			this->fillin->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->fillin->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->fillin->Name = L"fillin";
			this->fillin->Size = System::Drawing::Size(21, 20);
			this->fillin->Text = L"toolStripButton1";
			this->fillin->ToolTipText = L"填充";
			this->fillin->Click += gcnew System::EventHandler(this, &Form1::fillin_Click);
			// 
			// getcolor
			// 
			this->getcolor->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->getcolor->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"getcolor.Image")));
			this->getcolor->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->getcolor->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->getcolor->Name = L"getcolor";
			this->getcolor->Size = System::Drawing::Size(21, 20);
			this->getcolor->Text = L"toolStripButton1";
			this->getcolor->ToolTipText = L"取色器";
			this->getcolor->Click += gcnew System::EventHandler(this, &Form1::getcolor_Click);
			// 
			// filled
			// 
			this->filled->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->filled->Enabled = false;
			this->filled->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"filled.Image")));
			this->filled->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->filled->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->filled->Name = L"filled";
			this->filled->Size = System::Drawing::Size(21, 20);
			this->filled->Text = L"toolStripButton1";
			this->filled->ToolTipText = L"绘制填充图形";
			this->filled->Click += gcnew System::EventHandler(this, &Form1::filled_Click);
			// 
			// sadd
			// 
			this->sadd->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->sadd->Enabled = false;
			this->sadd->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sadd.Image")));
			this->sadd->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->sadd->Margin = System::Windows::Forms::Padding(0, 2, 0, 4);
			this->sadd->Name = L"sadd";
			this->sadd->Size = System::Drawing::Size(21, 20);
			this->sadd->Text = L"toolStripButton1";
			this->sadd->ToolTipText = L"刷子/橡皮尺寸加大";
			this->sadd->Click += gcnew System::EventHandler(this, &Form1::sadd_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(48, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(747, 542);
			this->panel1->TabIndex = 4;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				6)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 6)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(120, 70);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
			this->pictureBox2->Location = System::Drawing::Point(94, 44);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(6, 6);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2_MouseUp);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->flowLayoutPanel1->BackColor = System::Drawing::SystemColors::Control;
			this->flowLayoutPanel1->Controls->Add(this->pictureBox3);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox4);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox5);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox6);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox7);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox8);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox9);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox10);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox11);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox12);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox13);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox14);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox15);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox16);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox17);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox18);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox19);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox20);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox21);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox22);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox23);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox24);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox25);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox26);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox27);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox28);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox29);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox30);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox31);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox32);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox33);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox34);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox35);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox36);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox37);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox38);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox39);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox40);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox41);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox42);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox43);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox44);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox45);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox46);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox47);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox48);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox49);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox50);
			this->flowLayoutPanel1->Location = System::Drawing::Point(61, 5);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(627, 50);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Black;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox3->Location = System::Drawing::Point(1, 1);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(24, 23);
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox3_MouseClick);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox4->Location = System::Drawing::Point(27, 1);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(24, 23);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox4_MouseClick);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Gray;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox5->Location = System::Drawing::Point(53, 1);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(24, 23);
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox5_MouseClick);
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox6->Location = System::Drawing::Point(79, 1);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(24, 23);
			this->pictureBox6->TabIndex = 7;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox6_MouseClick);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Maroon;
			this->pictureBox7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox7->Location = System::Drawing::Point(105, 1);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(24, 23);
			this->pictureBox7->TabIndex = 7;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox7_MouseClick);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox8->Location = System::Drawing::Point(131, 1);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(24, 23);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox8_MouseClick);
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox9->Location = System::Drawing::Point(157, 1);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(24, 23);
			this->pictureBox9->TabIndex = 7;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox9_MouseClick);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox10->Location = System::Drawing::Point(183, 1);
			this->pictureBox10->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(24, 23);
			this->pictureBox10->TabIndex = 7;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox10_MouseClick);
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox11->Location = System::Drawing::Point(209, 1);
			this->pictureBox11->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(24, 23);
			this->pictureBox11->TabIndex = 7;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox11_MouseClick);
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox12->Location = System::Drawing::Point(235, 1);
			this->pictureBox12->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(24, 23);
			this->pictureBox12->TabIndex = 7;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox12_MouseClick);
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::Olive;
			this->pictureBox13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox13->Location = System::Drawing::Point(261, 1);
			this->pictureBox13->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(24, 23);
			this->pictureBox13->TabIndex = 7;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox13_MouseClick);
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox14->Location = System::Drawing::Point(287, 1);
			this->pictureBox14->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(24, 23);
			this->pictureBox14->TabIndex = 7;
			this->pictureBox14->TabStop = false;
			this->pictureBox14->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox14_MouseClick);
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox15->Location = System::Drawing::Point(313, 1);
			this->pictureBox15->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(24, 23);
			this->pictureBox15->TabIndex = 7;
			this->pictureBox15->TabStop = false;
			this->pictureBox15->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox15_MouseClick);
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackColor = System::Drawing::Color::Green;
			this->pictureBox16->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox16->Location = System::Drawing::Point(339, 1);
			this->pictureBox16->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(24, 23);
			this->pictureBox16->TabIndex = 7;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox16_MouseClick);
			// 
			// pictureBox17
			// 
			this->pictureBox17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox17->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox17->Location = System::Drawing::Point(365, 1);
			this->pictureBox17->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(24, 23);
			this->pictureBox17->TabIndex = 7;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox17_MouseClick);
			// 
			// pictureBox18
			// 
			this->pictureBox18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox18->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox18->Location = System::Drawing::Point(391, 1);
			this->pictureBox18->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(24, 23);
			this->pictureBox18->TabIndex = 7;
			this->pictureBox18->TabStop = false;
			this->pictureBox18->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox18_MouseClick);
			// 
			// pictureBox19
			// 
			this->pictureBox19->BackColor = System::Drawing::Color::Teal;
			this->pictureBox19->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox19->Location = System::Drawing::Point(417, 1);
			this->pictureBox19->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(24, 23);
			this->pictureBox19->TabIndex = 7;
			this->pictureBox19->TabStop = false;
			this->pictureBox19->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox19_MouseClick);
			// 
			// pictureBox20
			// 
			this->pictureBox20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox20->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox20->Location = System::Drawing::Point(443, 1);
			this->pictureBox20->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(24, 23);
			this->pictureBox20->TabIndex = 7;
			this->pictureBox20->TabStop = false;
			this->pictureBox20->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox20_MouseClick);
			// 
			// pictureBox21
			// 
			this->pictureBox21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox21->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox21->Location = System::Drawing::Point(469, 1);
			this->pictureBox21->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(24, 23);
			this->pictureBox21->TabIndex = 7;
			this->pictureBox21->TabStop = false;
			this->pictureBox21->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox21_MouseClick);
			// 
			// pictureBox22
			// 
			this->pictureBox22->BackColor = System::Drawing::Color::Navy;
			this->pictureBox22->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox22->Location = System::Drawing::Point(495, 1);
			this->pictureBox22->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(24, 23);
			this->pictureBox22->TabIndex = 7;
			this->pictureBox22->TabStop = false;
			this->pictureBox22->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox22_MouseClick);
			// 
			// pictureBox23
			// 
			this->pictureBox23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox23->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox23->Location = System::Drawing::Point(521, 1);
			this->pictureBox23->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(24, 23);
			this->pictureBox23->TabIndex = 7;
			this->pictureBox23->TabStop = false;
			this->pictureBox23->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox23_MouseClick);
			// 
			// pictureBox24
			// 
			this->pictureBox24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox24->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox24->Location = System::Drawing::Point(547, 1);
			this->pictureBox24->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(24, 23);
			this->pictureBox24->TabIndex = 7;
			this->pictureBox24->TabStop = false;
			this->pictureBox24->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox24_MouseClick);
			// 
			// pictureBox25
			// 
			this->pictureBox25->BackColor = System::Drawing::Color::Purple;
			this->pictureBox25->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox25->Location = System::Drawing::Point(573, 1);
			this->pictureBox25->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(24, 23);
			this->pictureBox25->TabIndex = 7;
			this->pictureBox25->TabStop = false;
			this->pictureBox25->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox25_MouseClick);
			// 
			// pictureBox26
			// 
			this->pictureBox26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox26->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox26->Location = System::Drawing::Point(599, 1);
			this->pictureBox26->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(24, 23);
			this->pictureBox26->TabIndex = 7;
			this->pictureBox26->TabStop = false;
			this->pictureBox26->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox26_MouseClick);
			// 
			// pictureBox27
			// 
			this->pictureBox27->BackColor = System::Drawing::Color::White;
			this->pictureBox27->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox27->Location = System::Drawing::Point(1, 26);
			this->pictureBox27->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(24, 23);
			this->pictureBox27->TabIndex = 7;
			this->pictureBox27->TabStop = false;
			this->pictureBox27->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox27_MouseClick);
			// 
			// pictureBox28
			// 
			this->pictureBox28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox28->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox28->Location = System::Drawing::Point(27, 26);
			this->pictureBox28->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(24, 23);
			this->pictureBox28->TabIndex = 7;
			this->pictureBox28->TabStop = false;
			this->pictureBox28->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox28_MouseClick);
			// 
			// pictureBox29
			// 
			this->pictureBox29->BackColor = System::Drawing::Color::Silver;
			this->pictureBox29->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox29->Location = System::Drawing::Point(53, 26);
			this->pictureBox29->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(24, 23);
			this->pictureBox29->TabIndex = 7;
			this->pictureBox29->TabStop = false;
			this->pictureBox29->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox29_MouseClick);
			// 
			// pictureBox30
			// 
			this->pictureBox30->BackColor = System::Drawing::Color::Red;
			this->pictureBox30->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox30->Location = System::Drawing::Point(79, 26);
			this->pictureBox30->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(24, 23);
			this->pictureBox30->TabIndex = 7;
			this->pictureBox30->TabStop = false;
			this->pictureBox30->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox30_MouseClick);
			// 
			// pictureBox31
			// 
			this->pictureBox31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->pictureBox31->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox31->Location = System::Drawing::Point(105, 26);
			this->pictureBox31->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(24, 23);
			this->pictureBox31->TabIndex = 7;
			this->pictureBox31->TabStop = false;
			this->pictureBox31->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox31_MouseClick);
			// 
			// pictureBox32
			// 
			this->pictureBox32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox32->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox32->Location = System::Drawing::Point(131, 26);
			this->pictureBox32->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(24, 23);
			this->pictureBox32->TabIndex = 7;
			this->pictureBox32->TabStop = false;
			this->pictureBox32->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox32_MouseClick);
			// 
			// pictureBox33
			// 
			this->pictureBox33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox33->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox33->Location = System::Drawing::Point(157, 26);
			this->pictureBox33->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(24, 23);
			this->pictureBox33->TabIndex = 7;
			this->pictureBox33->TabStop = false;
			this->pictureBox33->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox33_MouseClick);
			// 
			// pictureBox34
			// 
			this->pictureBox34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->pictureBox34->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox34->Location = System::Drawing::Point(183, 26);
			this->pictureBox34->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(24, 23);
			this->pictureBox34->TabIndex = 7;
			this->pictureBox34->TabStop = false;
			this->pictureBox34->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox34_MouseClick);
			// 
			// pictureBox35
			// 
			this->pictureBox35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox35->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox35->Location = System::Drawing::Point(209, 26);
			this->pictureBox35->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(24, 23);
			this->pictureBox35->TabIndex = 7;
			this->pictureBox35->TabStop = false;
			this->pictureBox35->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox35_MouseClick);
			// 
			// pictureBox36
			// 
			this->pictureBox36->BackColor = System::Drawing::Color::Yellow;
			this->pictureBox36->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox36->Location = System::Drawing::Point(235, 26);
			this->pictureBox36->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(24, 23);
			this->pictureBox36->TabIndex = 7;
			this->pictureBox36->TabStop = false;
			this->pictureBox36->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox36_MouseClick);
			// 
			// pictureBox37
			// 
			this->pictureBox37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->pictureBox37->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox37->Location = System::Drawing::Point(261, 26);
			this->pictureBox37->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(24, 23);
			this->pictureBox37->TabIndex = 7;
			this->pictureBox37->TabStop = false;
			this->pictureBox37->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox37_MouseClick);
			// 
			// pictureBox38
			// 
			this->pictureBox38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox38->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox38->Location = System::Drawing::Point(287, 26);
			this->pictureBox38->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(24, 23);
			this->pictureBox38->TabIndex = 7;
			this->pictureBox38->TabStop = false;
			this->pictureBox38->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox38_MouseClick);
			// 
			// pictureBox39
			// 
			this->pictureBox39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pictureBox39->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox39->Location = System::Drawing::Point(313, 26);
			this->pictureBox39->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(24, 23);
			this->pictureBox39->TabIndex = 7;
			this->pictureBox39->TabStop = false;
			this->pictureBox39->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox39_MouseClick);
			// 
			// pictureBox40
			// 
			this->pictureBox40->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->pictureBox40->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox40->Location = System::Drawing::Point(339, 26);
			this->pictureBox40->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(24, 23);
			this->pictureBox40->TabIndex = 7;
			this->pictureBox40->TabStop = false;
			this->pictureBox40->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox40_MouseClick);
			// 
			// pictureBox41
			// 
			this->pictureBox41->BackColor = System::Drawing::Color::Lime;
			this->pictureBox41->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox41->Location = System::Drawing::Point(365, 26);
			this->pictureBox41->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(24, 23);
			this->pictureBox41->TabIndex = 7;
			this->pictureBox41->TabStop = false;
			this->pictureBox41->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox41_MouseClick);
			// 
			// pictureBox42
			// 
			this->pictureBox42->BackColor = System::Drawing::Color::Cyan;
			this->pictureBox42->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox42->Location = System::Drawing::Point(391, 26);
			this->pictureBox42->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(24, 23);
			this->pictureBox42->TabIndex = 7;
			this->pictureBox42->TabStop = false;
			this->pictureBox42->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox42_MouseClick);
			// 
			// pictureBox43
			// 
			this->pictureBox43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox43->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox43->Location = System::Drawing::Point(417, 26);
			this->pictureBox43->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(24, 23);
			this->pictureBox43->TabIndex = 7;
			this->pictureBox43->TabStop = false;
			this->pictureBox43->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox43_MouseClick);
			// 
			// pictureBox44
			// 
			this->pictureBox44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox44->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox44->Location = System::Drawing::Point(443, 26);
			this->pictureBox44->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(24, 23);
			this->pictureBox44->TabIndex = 7;
			this->pictureBox44->TabStop = false;
			this->pictureBox44->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox44_MouseClick);
			// 
			// pictureBox45
			// 
			this->pictureBox45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox45->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox45->Location = System::Drawing::Point(469, 26);
			this->pictureBox45->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(24, 23);
			this->pictureBox45->TabIndex = 7;
			this->pictureBox45->TabStop = false;
			this->pictureBox45->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox45_MouseClick);
			// 
			// pictureBox46
			// 
			this->pictureBox46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox46->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox46->Location = System::Drawing::Point(495, 26);
			this->pictureBox46->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(24, 23);
			this->pictureBox46->TabIndex = 7;
			this->pictureBox46->TabStop = false;
			this->pictureBox46->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox46_MouseClick);
			// 
			// pictureBox47
			// 
			this->pictureBox47->BackColor = System::Drawing::Color::Blue;
			this->pictureBox47->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox47->Location = System::Drawing::Point(521, 26);
			this->pictureBox47->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(24, 23);
			this->pictureBox47->TabIndex = 7;
			this->pictureBox47->TabStop = false;
			this->pictureBox47->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox47_MouseClick);
			// 
			// pictureBox48
			// 
			this->pictureBox48->BackColor = System::Drawing::Color::Fuchsia;
			this->pictureBox48->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox48->Location = System::Drawing::Point(547, 26);
			this->pictureBox48->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(24, 23);
			this->pictureBox48->TabIndex = 7;
			this->pictureBox48->TabStop = false;
			this->pictureBox48->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox48_MouseClick);
			// 
			// pictureBox49
			// 
			this->pictureBox49->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox49->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox49->Location = System::Drawing::Point(573, 26);
			this->pictureBox49->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(24, 23);
			this->pictureBox49->TabIndex = 7;
			this->pictureBox49->TabStop = false;
			this->pictureBox49->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox49_MouseClick);
			// 
			// pictureBox50
			// 
			this->pictureBox50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox50->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox50->Location = System::Drawing::Point(599, 26);
			this->pictureBox50->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(24, 23);
			this->pictureBox50->TabIndex = 7;
			this->pictureBox50->TabStop = false;
			this->pictureBox50->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox50_MouseClick);
			// 
			// color2
			// 
			this->color2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->color2->BackColor = System::Drawing::Color::White;
			this->color2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->color2->Location = System::Drawing::Point(20, 16);
			this->color2->Name = L"color2";
			this->color2->Size = System::Drawing::Size(30, 28);
			this->color2->TabIndex = 6;
			this->color2->TabStop = false;
			this->color2->BackColorChanged += gcnew System::EventHandler(this, &Form1::color2_BackColorChanged);
			this->color2->DoubleClick += gcnew System::EventHandler(this, &Form1::color2_DoubleClick);
			// 
			// color1
			// 
			this->color1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->color1->BackColor = System::Drawing::Color::Black;
			this->color1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->color1->Location = System::Drawing::Point(11, 24);
			this->color1->Name = L"color1";
			this->color1->Size = System::Drawing::Size(30, 29);
			this->color1->TabIndex = 7;
			this->color1->TabStop = false;
			this->color1->BackColorChanged += gcnew System::EventHandler(this, &Form1::color1_BackColorChanged);
			this->color1->DoubleClick += gcnew System::EventHandler(this, &Form1::color1_DoubleClick);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->toolStrip1);
			this->panel2->Controls->Add(this->toolStrip2);
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Location = System::Drawing::Point(0, 25);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(796, 542);
			this->panel2->TabIndex = 8;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel3->Controls->Add(this->color1);
			this->panel3->Controls->Add(this->flowLayoutPanel1);
			this->panel3->Controls->Add(this->color2);
			this->panel3->Location = System::Drawing::Point(0, 570);
			this->panel3->Margin = System::Windows::Forms::Padding(0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(693, 61);
			this->panel3->TabIndex = 9;
			// 
			// pictureBox51
			// 
			this->pictureBox51->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->pictureBox51->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox51->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox51.BackgroundImage")));
			this->pictureBox51->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox51->Location = System::Drawing::Point(696, 577);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(46, 47);
			this->pictureBox51->TabIndex = 10;
			this->pictureBox51->TabStop = false;
			this->pictureBox51->Visible = false;
			this->pictureBox51->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox51_MouseClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(796, 631);
			this->Controls->Add(this->pictureBox51);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(812, 669);
			this->Name = L"Form1";
			this->Text = L"我的画图 关键 102342";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void toolStripContainer1_ContentPanel_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void toolStripContainer1_LeftToolStripPanel_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void 保存ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Int32 add1(int x)
		{
			return (x+mo+1)%mo;
		}
private:System::Int32 sub1(int x)
		{
			return (x+mo-1)%mo;		
		}

private:System::Void next()
		{
			if (no!=t) 
			{
				no=add1(no);
				update();
			}
			if (no==t) 重复ToolStripMenuItem->Enabled=false;
		}
private:System::Void last()
		{
			if (no!=f) 
			{
				no=sub1(no);
				update();
				重复ToolStripMenuItem->Enabled=true;
			}
			if (no==f)	撤销ToolStripMenuItem->Enabled=false;
		}
private:System::Void update()
		{
			pictureBox1->Image=b[no];
			gra=Graphics::FromImage(b[no]);

		}
private:System::Void newb()
		{
			int last=no;
			no=add1(no);
			t=no;
			if (no==f) f=add1(f);
			b[no]=(Bitmap^)b[last]->Clone();
			update();
			重复ToolStripMenuItem->Enabled=false;
			撤销ToolStripMenuItem->Enabled=true;
		}
private:System::Void newb(int x,int y)
		{
			int last=no;
			no=add1(no);
			t=no;
			if (no==f) f=add1(f);
			b[no]=gcnew Bitmap(b[last],x,y);
/*			//b[no]=(Bitmap^)b[last]->Clone(Rectangle(0,0,x,y),b[last]->PixelFormat);
			int i,j;
			b[no]=gcnew Bitmap(x,y);
			update();
			gra->Clear(Color::Pink);
			mx=b[last]->Width;
			my=b[last]->Height;
			if mx
			for (i=0;i<=b[last]->Width-1;i++)
				for(j=0;j<=b[last]->Height-1;j++)
					b[no]->SetPixel(i,j,b[last]->GetPixel(i,j));*/
			lx=gcnew array<Int32>(b[no]->Width*b[no]->Height);
			ly=gcnew array<Int32>(b[no]->Width*b[no]->Height);
			update();
			重复ToolStripMenuItem->Enabled=false;
			撤销ToolStripMenuItem->Enabled=true;
		}


private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
			no=0;f=0;t=0;size=10;
			ld=false;
			rd=false;
			cv=true;
			mod1=pen;
			mod1->Checked=true;
			mod2=filled;
			mod2->Checked=true;
			 //bit=gcnew Bitmap(pictureBox1->Size.Width,pictureBox1->Size.Height);
			b=gcnew array<Bitmap^>(mo);
			b[no]=gcnew Bitmap(640,480);
			gra= Graphics::FromImage(b[no]);
			lx=gcnew array<Int32>(b[no]->Width*b[no]->Height);
			ly=gcnew array<Int32>(b[no]->Width*b[no]->Height);
			//b[1]=(Bitmap^)b[0]->Clone();
			//bit=b[1];
			p=gcnew Pen(Color::Black);
			//p->
			gra->Clear(Color::White);
			//gra->FillRegion()
			//gra->
			//gra->DrawEllipse(p,100,100,1,1);
			pictureBox1->Image=b[no];
			this->pictureBox1->Cursor= gcnew System::Windows::Forms::Cursor("pen.cur");

			//Windows::Forms::Cursor::Hide();
			//newb();
//			pre=gcnew Bitmap(bit->Size.Width,bit->Size.Height);
//			gp=Graphics::FromImage(pre);
			


			 
		 }

private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pictureBox1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
		 }

private: System::Void pictureBox2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 newb(b[no]->Size.Width+e->X,b[no]->Size.Height+e->Y);
		 }
private: System::Void 撤销ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 last();
		 }
private: System::Void 重复ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 next();
		 }
private: System::Void setcolor(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=this->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=this->BackColor;
			 }

		 }

private: System::Void pictureBox3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox3->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox3->BackColor;
			 }
		 }

private: System::Void pictureBox4_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox4->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox4->BackColor;
			 }
		 }
private: System::Void pictureBox5_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox5->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox5->BackColor;
			 }
		 }
private: System::Void pictureBox6_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox6->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox6->BackColor;
			 }
		 }
private: System::Void pictureBox7_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox7->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox7->BackColor;
			 }
		 }
private: System::Void pictureBox8_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox8->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox8->BackColor;
			 }
		 }
private: System::Void pictureBox9_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox9->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox9->BackColor;
			 }
		 }
private: System::Void pictureBox10_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox10->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox10->BackColor;
			 }
		 }
private: System::Void pictureBox11_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox11->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox11->BackColor;
			 }
		 }
private: System::Void pictureBox12_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox12->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox12->BackColor;
			 }
		 }
private: System::Void pictureBox13_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox13->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox13->BackColor;
			 }
		 }
private: System::Void pictureBox14_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox14->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox14->BackColor;
			 }
		 }
private: System::Void pictureBox15_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox15->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox15->BackColor;
			 }
		 }
private: System::Void pictureBox16_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox16->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox16->BackColor;
			 }
		 }
private: System::Void pictureBox17_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox17->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox17->BackColor;
			 }
		 }
private: System::Void pictureBox18_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox18->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox18->BackColor;
			 }
		 }
private: System::Void pictureBox19_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox19->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox19->BackColor;
			 }
		 }
private: System::Void pictureBox20_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox20->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox20->BackColor;
			 }
		 }
private: System::Void pictureBox21_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox21->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox21->BackColor;
			 }
		 }
private: System::Void pictureBox22_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox22->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox22->BackColor;
			 }
		 }
private: System::Void pictureBox23_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox23->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox23->BackColor;
			 }
		 }

private: System::Void pictureBox24_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox24->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox24->BackColor;
			 }
		 }
private: System::Void pictureBox25_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox25->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox25->BackColor;
			 }
		 }
private: System::Void pictureBox26_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox26->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox26->BackColor;
			 }
		 }
private: System::Void pictureBox27_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox27->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox27->BackColor;
			 }
		 }

private: System::Void pictureBox28_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox28->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox28->BackColor;
			 }
		 }
private: System::Void pictureBox29_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox29->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox29->BackColor;
			 }
		 }
private: System::Void pictureBox30_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox30->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox30->BackColor;
			 }
		 }
private: System::Void pictureBox31_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox31->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox31->BackColor;
			 }
		 }
private: System::Void pictureBox32_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox32->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox32->BackColor;
			 }
		 }
private: System::Void pictureBox33_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox33->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox33->BackColor;
			 }
		 }
private: System::Void pictureBox34_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox34->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox34->BackColor;
			 }
		 }
private: System::Void pictureBox35_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox35->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox35->BackColor;
			 }
		 }
private: System::Void pictureBox36_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox36->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox36->BackColor;
			 }
		 }
private: System::Void pictureBox37_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox37->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox37->BackColor;
			 }
		 }
private: System::Void pictureBox38_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox38->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox38->BackColor;
			 }
		 }

private: System::Void pictureBox39_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox39->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox39->BackColor;
			 }
		 }
private: System::Void pictureBox40_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox40->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox40->BackColor;
			 }
		 }
private: System::Void pictureBox41_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox41->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox41->BackColor;
			 }
		 }
private: System::Void pictureBox42_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox42->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox42->BackColor;
			 }
		 }
private: System::Void pictureBox43_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox43->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox43->BackColor;
			 }
		 }
private: System::Void pictureBox44_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox44->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox44->BackColor;
			 }
		 }
private: System::Void pictureBox45_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox45->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox45->BackColor;
			 }
		 }
private: System::Void pictureBox46_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox46->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox46->BackColor;
			 }
		 }
private: System::Void pictureBox47_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox47->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox47->BackColor;
			 }
		 }
private: System::Void pictureBox48_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox48->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox48->BackColor;
			 }
		 }
private: System::Void pictureBox49_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox49->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox49->BackColor;
			 }
		 }
private: System::Void pictureBox50_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 color1->BackColor=pictureBox50->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox50->BackColor;
			 }
		 }
private: System::Void color1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 if (colorDialog1->ShowDialog()==Windows::Forms::DialogResult::OK) color1->BackColor=colorDialog1->Color;
		 }
private: System::Void color2_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 if (colorDialog1->ShowDialog()==Windows::Forms::DialogResult::OK) color2->BackColor=colorDialog1->Color;

		 }
private: System::Void pictureBox51_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left)
			 {
				 
				 color1->BackColor=pictureBox51->BackColor;
			 }
			 else if(e->Button==Windows::Forms::MouseButtons::Right)
			 {
				 color2->BackColor=pictureBox51->BackColor;
			 }

		 }
private: System::Void color1_BackColorChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (color1->BackColor==Color::Transparent) color1->BackgroundImage=pictureBox51->BackgroundImage;
			 else color1->BackgroundImage=pictureBox50->BackgroundImage;
		 }
private: System::Void color2_BackColorChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (color2->BackColor==Color::Transparent) color2->
			 BackgroundImage=pictureBox51->BackgroundImage;
			 else color2->BackgroundImage=pictureBox50->BackgroundImage;
		 }
private: System::Void 清除ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 newb();
			 gra->Clear(color2->BackColor);
		 }

private: System::Void pen_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=pen;
			 mod1->Checked=true;
			 filled->Enabled=false;
			 empty->Enabled=false;
			 sadd->Enabled=false;
			 ssub->Enabled=false;
			 cv=true;
			this->pictureBox1->Cursor= gcnew System::Windows::Forms::Cursor("pen.cur");
			 //this->pictureBox1->Cursor=//(cli::safe_cast<System::Windows::Forms::Cursor^  >(resources->GetObject(L"pen.Cursor")));
		 }

private: System::Void brush_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=brush;
			 mod1->Checked=true;
			 filled->Enabled=false;
			 empty->Enabled=false;
			 sadd->Enabled=true;
			 ssub->Enabled=true;
			 cv=false;
			 
		 }
private: System::Void circle_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=circle;
			 mod1->Checked=true;
			 filled->Enabled=true;
			 empty->Enabled=true;
			 sadd->Enabled=false;
			 ssub->Enabled=false;
			 cv=true;
			 this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
		 }
private: System::Void sqare_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=sqare;
			 mod1->Checked=true;
			 filled->Enabled=true;
			 empty->Enabled=true;
			 sadd->Enabled=false;
			 ssub->Enabled=false;
			 cv=true;
			 this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
		 }
private: System::Void fillin_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=fillin;
			 mod1->Checked=true;
			 filled->Enabled=false;
			 empty->Enabled=false;
			 sadd->Enabled=false;
			 ssub->Enabled=false;
			 cv=true;
			 this->pictureBox1->Cursor= gcnew System::Windows::Forms::Cursor("paint.cur");

		 }
private: System::Void line_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=line;
			 mod1->Checked=true;
			 filled->Enabled=false;
			 empty->Enabled=false;
			 sadd->Enabled=false;
			 ssub->Enabled=false;
			 cv=true;
			 this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
		 }
private: System::Void getcolor_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=getcolor;
			 mod1->Checked=true;
			 filled->Enabled=false;
			 empty->Enabled=false;
			 sadd->Enabled=false;
			 ssub->Enabled=false;
			 cv=true;
			 this->pictureBox1->Cursor= gcnew System::Windows::Forms::Cursor("getcolor.cur");

		 }
private: System::Void erazer_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod1->Checked=false;
			 mod1=erazer;
			 mod1->Checked=true;
			 filled->Enabled=false;
			 empty->Enabled=false;
			 sadd->Enabled=true;
			 ssub->Enabled=true;
			 cv=false;

		 }
private: System::Void filled_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod2->Checked=false;
			 mod2=filled;
			 mod2->Checked=true;
		 }
private: System::Void empty_Click(System::Object^  sender, System::EventArgs^  e) {
			 mod2->Checked=false;
			 mod2=empty;
			 mod2->Checked=true;
		 }
private: System::Int32 fitx(int x)
		 {
			if (x>b[no]->Width-1) return b[no]->Width-1;
			if (x<1) return 1;
			return x;
		 }
private: System::Int32 fity(int y)
		 {
			if (y>b[no]->Height-1) return b[no]->Height-1;
			if (y<1) return 1;
			return y;
		 }
private: System::Boolean fit(int x,int y)
		 {
			if (x>b[no]->Width-1) return false;
			if (x<1) return false;
			if (y>b[no]->Height-1) return false;
			if (y<1) return false;
			return true;
		 }
private: System::Void mmove(System::Windows::Forms::MouseEventArgs^  e)
		 {
				if ((mod1==pen)||(mod1==brush)||(mod1==erazer))
				{
					if (ld)
					{
							/*Drawing::Drawing2D::GraphicsPath ^gp= gcnew Drawing::Drawing2D::GraphicsPath();
							float tt=0.0;
							gp->AddEllipse(-tt/2,-tt/2,tt,tt);
							gp->FillMode=Drawing::Drawing2D::FillMode::Alternate;
							p->CustomStartCap=gcnew Drawing::Drawing2D::CustomLineCap(gcnew Drawing::Drawing2D::GraphicsPath(),gp);*/
							
							if (mod1==pen)
							{
								p->Color=color1->BackColor;
								p->Width=1;
								gra->DrawLine(p,fx,fy,(e->X),(e->Y));
							}
							else if (mod1==brush)
							{
								p->Color=color1->BackColor;
								p->Width=size;
								gra->FillEllipse(gcnew SolidBrush(color1->BackColor),fx-size/2,fy-size/2,size,size);
								gra->FillEllipse(gcnew SolidBrush(color1->BackColor),(e->X)-size/2,(e->Y)-size/2,size,size);
								gra->DrawLine(p,fx,fy,(e->X),(e->Y));
							}
							else if (mod1==erazer)
							{
								p->Color=color2->BackColor;
								p->Width=size;
								gra->FillEllipse(gcnew SolidBrush(color2->BackColor),fx-size/2,fy-size/2,size,size);
								gra->FillEllipse(gcnew SolidBrush(color2->BackColor),(e->X)-size/2,(e->Y)-size/2,size,size);
								gra->DrawLine(p,fx,fy,(e->X),(e->Y));
							}
						if (fit(e->X,e->Y))
						{

							if (mod1==pen) b[no]->SetPixel(e->X,e->Y,color1->BackColor);
							else if (mod1==brush) gra->FillEllipse(gcnew SolidBrush(color1->BackColor),e->X-size/2,e->Y-size/2,size,size);
						}
							fx=e->X;
							fy=e->Y;
						
						/*else
						{
							//fx=-1;fy=-1;
						}*/
						//update();
					}
				}
		 }
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 tx=e->X;
			 ty=e->Y;
			// pictureBox1->OnPaint();
			 mmove(e);
			 update();

		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button==Windows::Forms::MouseButtons::Left) 
			 {
				ld=true;
				fx=e->X;
				fy=e->Y;
				if ((mod1==pen)||(mod1==brush)||(mod1==erazer))
				{
					newb();
				}
				else if (mod1==getcolor)
				{
					color1->BackColor=b[no]->GetPixel(e->X,e->Y);
				}
				else if (mod1==fillin)
				{
					newb();
					tchong(e->X,e->Y,color1->BackColor);
				}
				mmove(e);
			 }
			 if (e->Button==Windows::Forms::MouseButtons::Right)
			 {
				rd=true;
				if (mod1==getcolor)
				{
					color2->BackColor=b[no]->GetPixel(e->X,e->Y);
				}
				else if (mod1==fillin)
				{
					newb();
					tchong(e->X,e->Y,color2->BackColor);
				}
			 }
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (e->Button==Windows::Forms::MouseButtons::Left) 
			{
				if (ld)
				{
				if (mod1==line)
				{
					newb();
					p->Color=color1->BackColor;
					p->Width=1;
					gra->DrawLine(p,fx,fy,e->X,e->Y);
				}
				else if (mod1==circle)
				{

					newb();
					int minx=e->X,miny=e->Y,maxx=e->X,maxy=e->Y;
					if (minx>fx) minx=fx;
					if (miny>fy) miny=fy;
					if (maxx<fx) maxx=fx;
					if (maxy<fy) maxy=fy;
					if (mod2==filled) gra->FillEllipse(gcnew SolidBrush(color2->BackColor),minx,miny,maxx-minx,maxy-miny);
					p->Color=color1->BackColor;
					p->Width=1;
					gra->DrawEllipse(p,minx,miny,maxx-minx,maxy-miny);
				}
				else if (mod1==sqare)
				{

					newb();
					int minx=e->X,miny=e->Y,maxx=e->X,maxy=e->Y;
					if (minx>fx) minx=fx;
					if (miny>fy) miny=fy;
					if (maxx<fx) maxx=fx;
					if (maxy<fy) maxy=fy;
					if (mod2==filled) gra->FillRectangle(gcnew SolidBrush(color2->BackColor),minx,miny,maxx-minx,maxy-miny);
					p->Color=color1->BackColor;
					p->Width=1;
					gra->DrawRectangle(p,minx,miny,maxx-minx,maxy-miny);
				}
				}
				ld=false;
			}
			if (e->Button==Windows::Forms::MouseButtons::Right)
			{
				rd=false;
			}
			fx=-1;
			fy=-1;
		 }
private: System::Void pictureBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			if (!cv) Windows::Forms::Cursor::Hide();

		 }
private: System::Void sadd_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (size<10) size+=1;
			 else size+=10;
			 if (size>100) size=100;
			 else if ((size>=10)&&(size<20)) size=10;
		 }
private: System::Void ssub_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (size<=10) size-=1;
			 else size-=10;
			 if (size<1) size=1;
			 else if ((size>=10)&&(size<20)) size=10;
		 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics ^gp=e->Graphics;
			 if (fit(tx,ty))
			 {
				if (mod1==brush) 
				{
					gp->FillEllipse(gcnew SolidBrush(color1->BackColor),tx-size/2,ty-size/2,size,size);
					p->Width=1;
					p->Color=Color::Black;
					gp->DrawEllipse(p,tx-size/2,ty-size/2,size,size);
				}
				else if (mod1==erazer ) 
				{	
					gp->FillEllipse(gcnew SolidBrush(color2->BackColor),tx-size/2,ty-size/2,size,size);
					p->Width=1;
					p->Color=Color::Black;
					gp->DrawEllipse(p,tx-size/2,ty-size/2,size,size);
				}
				else if ((mod1==line)&&(ld))
				{
					p->Color=color1->BackColor;
					p->Width=1;
					gp->DrawLine(p,fx,fy,tx,ty);
				}
				else if ((mod1==circle)&&(ld))
				{

					int minx=tx,miny=ty,maxx=tx,maxy=ty;
					if (minx>fx) minx=fx;
					if (miny>fy) miny=fy;
					if (maxx<fx) maxx=fx;
					if (maxy<fy) maxy=fy;
					if (mod2==filled) gp->FillEllipse(gcnew SolidBrush(color2->BackColor),minx,miny,maxx-minx,maxy-miny);
					p->Color=color1->BackColor;
					p->Width=1;
					gp->DrawEllipse(p,minx,miny,maxx-minx,maxy-miny);
				}
				else if ((mod1==sqare)&&(ld))
				{

					int minx=tx,miny=ty,maxx=tx,maxy=ty;
					if (minx>fx) minx=fx;
					if (miny>fy) miny=fy;
					if (maxx<fx) maxx=fx;
					if (maxy<fy) maxy=fy;
					if (mod2==filled) gp->FillRectangle(gcnew SolidBrush(color2->BackColor),minx,miny,maxx-minx,maxy-miny);
					p->Color=color1->BackColor;
					p->Width=1;
					gp->DrawRectangle(p,minx,miny,maxx-minx,maxy-miny);
				}

			 }
//			 gp->DrawLines(p,ft);

		 }
private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 if (!cv) Windows::Forms::Cursor::Show();
			 tx=-1;ty=-1;
			 update();
		 }

private: System::Void tchong(int ix,int iy,Color c)//模拟画布上的填充函数(4邻域填充)
{

	int lm=b[no]->Width*b[no]->Height;
	Color cc=b[no]->GetPixel(ix,iy);
	if (cc.ToArgb()!=c.ToArgb())
	{
		int l=1,r=2;
		lx[1]=ix;ly[1]=iy;
		int i,j,k;
		int ax[4]={0,0,1,-1};
		int ay[4]={1,-1,0,0};
		
		while (l<r)
		{
			i=lx[l%lm];j=ly[l%lm];
			if (fit(i,j)&&(b[no]->GetPixel(i,j)==cc))
			{
			b[no]->SetPixel(i,j,c);
			int x,y;
			for (k=0;k<=3;k++)
			{
				x=i+ax[k];y=j+ay[k];
				if (fit(x,y)&&(b[no]->GetPixel(x,y)==cc))
				{
					lx[r%lm]=x;ly[r%lm]=y;
					r++;
				}
			}
		

			}
			l++;
		}
	}
}
private: System::Void 打开ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFileDialog1->ShowDialog();
		 }
private: System::Void 另存为ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveFileDialog1->ShowDialog();
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 b[no]=gcnew Bitmap(openFileDialog1->FileName);
			 撤销ToolStripMenuItem->Enabled=false;
			 重复ToolStripMenuItem->Enabled=false;
			 update();
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 b[no]->Save(saveFileDialog1->FileName);
		 }
};
}

