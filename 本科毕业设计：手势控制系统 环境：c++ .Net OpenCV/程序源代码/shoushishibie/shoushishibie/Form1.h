#pragma once
#include <fstream>
#include "bpnet.h"
const int xcount=36;
const int camwidth=160,camheight=120;
const double pi=3.141592654;
#include "dataset.h"
#include "commandposter.h"
#include "devicecontroler.h"
ref class  SkinExtractor;
namespace shoushishibie {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Threading;
	using namespace Emgu::CV;
	using namespace Emgu::CV::Structure;
	using namespace Emgu::Util;
	using namespace System::Collections::Generic;
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

	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	public: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	public: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	public: System::Windows::Forms::NumericUpDown^  numericUpDown5;
	private: Emgu::CV::Capture ^cam;
	private: Dataset ^data;
	private: Commandposter ^cp;
	private: Bitmap ^bit,^bit1,^bit2;
	private: Bpnet ^bp;
			 Devicecontroler ^dc;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button12;
			 List<String^> ^curfiles;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
			 bool exit,firstflag;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::GroupBox^  groupBox4;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(125, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"添加样例";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(14, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(125, 70);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 25);
			this->button4->TabIndex = 5;
			this->button4->Text = L"训练";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(14, 70);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 25);
			this->button5->TabIndex = 6;
			this->button5->Text = L"清空训练数据";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Black;
			this->pictureBox2->Location = System::Drawing::Point(262, 577);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(252, 135);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(73, 43);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(41, 21);
			this->numericUpDown1->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(836, 643);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 32);
			this->button2->TabIndex = 9;
			this->button2->Text = L"判断";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 42, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(57, 591);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 56);
			this->label1->TabIndex = 10;
			this->label1->Text = L"\?";
			this->label1->Visible = false;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(16, 30);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(72, 21);
			this->numericUpDown2->TabIndex = 11;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {77, 0, 0, 0});
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(149, 30);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(78, 21);
			this->numericUpDown3->TabIndex = 11;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {133, 0, 0, 0});
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(16, 74);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(72, 21);
			this->numericUpDown4->TabIndex = 11;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {140, 0, 0, 0});
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown4_ValueChanged);
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(149, 74);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(78, 21);
			this->numericUpDown5->TabIndex = 11;
			this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {173, 0, 0, 0});
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(125, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 25);
			this->button3->TabIndex = 12;
			this->button3->Text = L"音量控制模式";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(715, 588);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 13;
			this->textBox1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(94, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 21);
			this->label2->TabIndex = 14;
			this->label2->Text = L"<Cb<";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(94, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 21);
			this->label3->TabIndex = 14;
			this->label3->Text = L"<Cr<";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->numericUpDown5);
			this->groupBox1->Controls->Add(this->numericUpDown4);
			this->groupBox1->Controls->Add(this->numericUpDown3);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Location = System::Drawing::Point(673, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(243, 124);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"基础阈值调整";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->numericUpDown1);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Location = System::Drawing::Point(673, 247);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(243, 126);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"样例与神经网络";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 45);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 12);
			this->label4->TabIndex = 9;
			this->label4->Text = L"样例类别";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button11);
			this->groupBox3->Controls->Add(this->button10);
			this->groupBox3->Controls->Add(this->button8);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(673, 379);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(243, 115);
			this->groupBox3->TabIndex = 17;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"工作模式";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(14, 65);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(100, 25);
			this->button11->TabIndex = 18;
			this->button11->Text = L"PPT控制模式";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(14, 34);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(100, 25);
			this->button10->TabIndex = 17;
			this->button10->Text = L"模式选择模式";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(125, 34);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(100, 25);
			this->button8->TabIndex = 15;
			this->button8->Text = L"鼠标控制模式";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(14, 56);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(100, 25);
			this->button12->TabIndex = 19;
			this->button12->Text = L"初始化差值";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(125, 56);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(100, 25);
			this->button9->TabIndex = 16;
			this->button9->Text = L"肤色分割重置";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(14, 25);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(100, 25);
			this->button7->TabIndex = 14;
			this->button7->Text = L"半自动适应";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(125, 25);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 25);
			this->button6->TabIndex = 13;
			this->button6->Text = L"全自动适应";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(941, 548);
			this->tabControl1->TabIndex = 18;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(933, 522);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"参数配置与模式控制";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button12);
			this->groupBox4->Controls->Add(this->button7);
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Controls->Add(this->button9);
			this->groupBox4->Location = System::Drawing::Point(673, 141);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(243, 100);
			this->groupBox4->TabIndex = 18;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"肤色分割增强";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Black;
			this->tabPage2->Controls->Add(this->pictureBox4);
			this->tabPage2->Controls->Add(this->pictureBox3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(933, 522);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"处理前后图像";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Black;
			this->pictureBox4->Location = System::Drawing::Point(467, 63);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(466, 355);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Black;
			this->pictureBox3->Location = System::Drawing::Point(0, 63);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(466, 355);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"PowerPoint放映|*.ppsx";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"102342 关键 毕业设计：基于视频的手势识别系统";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->DoubleClick += gcnew System::EventHandler(this, &Form1::notifyIcon1_DoubleClick);
			this->notifyIcon1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::notifyIcon1_MouseClick);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem1, 
				this->toolStripMenuItem2});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(135, 48);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(134, 22);
			this->toolStripMenuItem1->Text = L"显示主界面";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(134, 22);
			this->toolStripMenuItem2->Text = L"退出";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(965, 572);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(981, 611);
			this->MinimumSize = System::Drawing::Size(981, 611);
			this->Name = L"Form1";
			this->ShowInTaskbar = false;
			this->Text = L"102342 关键 毕业设计：基于视频的手势识别系统";
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: array<double>^todata()
		{
			array<double> ^ans=gcnew array<double>(xcount);
			bool d[camwidth][camheight];
			double td[xcount],mul=xcount/2;
			int x[xcount],y[xcount],c[xcount];
			int midx=0,midy=0,count=0;
			for (int i=0;i<=camwidth-1;i++)
				for(int j=0;j<=camheight-1;j++)
				{
					d[i][j]=((bit2->GetPixel(i,j).R>0)||(bit2->GetPixel(i,j).G>0)||(bit2->GetPixel(i,j).B>0));
				}
			Bitmap ^b2=gcnew Bitmap(camwidth,camheight);
			for (int i=0;i<=camwidth-1;i++)
				for (int j=0;j<=camheight-1;j++)
				{
					if (d[i][j]) 
					{
						b2->SetPixel(i,j,Color::White);
						count++;
						midx+=i;
						midy+=j;
					}
					else b2->SetPixel(i,j,Color::Black);
				}
			midx/=count;
			midy/=count;
			b2->SetPixel(midx,midy,Color::Red);
			
			double dalta=mul/count;
			for (int i=0;i<=xcount-1;i++)
			{
				td[i]=0;
				x[i]=0;
				y[i]=0;
				c[i]=0;
			}
			for (int i=0;i<=camwidth-1;i++)
				for (int j=0;j<=camheight-1;j++)
				{
					int tt=0;
					if (i<midx) tt=18;
					if (d[i][j])
					{
						int tno=((int)Math::Floor(Math::Atan2(j-midy,i-midx)/(Math::PI*2/xcount)+18))%36;
						td[tno]+=dalta;
						x[tno]+=i;
						y[tno]+=j;
						c[tno]++;
						if (x[0]<0)
							x[0]=x[0];
					}
				}
			for (int i=0;i<=xcount-1;i++)
			{
				if (c[i])
				{
					x[i]/=c[i];
					y[i]/=c[i];
					b2->SetPixel(x[i],y[i],Color::Green);
					td[i]=(x[i]-midx)*(x[i]-midx)+(y[i]-midy)*(y[i]-midy);
				}
			}
			pictureBox2->Image=b2;
			double max=0;
			int mn=0;
			for (int i=0;i<=xcount-1;i++)
			{
				if (td[i]>max) 
				{
					max=td[i];
					mn=i;
				}
			}
			for (int i=0;i<=xcount-1;i++)
			{
				ans[i]=td[(i+mn)%xcount]/max;
			}
			return ans;
		}
	private: Void addtdata(int cla)
		{			
			ofstream ofs("traindata.data",ios_base::out|ios_base::app);
			array<double> ^ans=todata();
			ofs<<endl<<cla;
			for (int i=0;i<=xcount-1;i++)
			{
				ofs<<" "<<ans[i];
			}
			ofs.close();

		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 addtdata(Decimal::ToInt32(numericUpDown1->Value));
			 }
	private: private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 emgucapture();
				 runcom();
;			 }
	private: Void runcom()
	{
		textBox1->Text="0";
		cp->calcommand();
		for (int i=0;i<cp->getcomcount();i++)
		{
			array<int> ^com=cp->getcommand(i);
			if (com[0]==1)
			{
				dc->cursormove(com[1],com[2]);
			}
			else if (com[0]==2)
			{
				dc->lclick();
			}
			else if (com[0]==3)
			{
				if (com[1]>=0)	dc->setcursor(curfiles[com[1]]);
				else if (com[1]==-1) dc->resetcursor();
			}
			else if (com[0]==4)
			{
				dc->keyclick(com[1]);
				textBox1->Text=com[1].ToString();
			}
			else if (com[0]==5)
			{
				openFileDialog1->ShowDialog();
			}
			else if (com[0]==6)
			{
				dc->changevol(com[1]);
			}
			else if (com[0]==7)
			{
				ontop();
			}
		}
	}
			 
			 SkinExtractor ^se;
	private: Void emgucapture();
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 ofstream ofs("traindata.data");
				 ofs.close();
			 }
	private: void trainnet()
	{
		ifstream ifs("traindata.data");
		int count=0,tt,maxcls=0;
		double tdouble;
		ifs>>tt;
		while (!ifs.eof())
		{
			count++;
			if (tt>maxcls) maxcls=tt;
			for (int i=0;i<=xcount-1;i++)
			{
				ifs>>tdouble;
			}
			ifs>>tt;
		}		
		ifs.clear();
		ifs.seekg(0,ios::beg);
		array<array<double>^> ^x,^y;
		x=gcnew array<array<double>^>(count);
		y=gcnew array<array<double>^>(count);
		for (int i=0;i<=count-1;i++)
		{
			x[i]=gcnew array<double>(xcount);
			y[i]=gcnew array<double>(maxcls+1);
			ifs>>tt;
			for (int j=0;j<=maxcls+1-1;j++)
			{
				if (j==tt) y[i][j]=1;
				else y[i][j]=0;
			}
			for (int j=0;j<=xcount-1;j++)
			{
				ifs>>tdouble;
				x[i][j]=tdouble;
			}
		}
		array<int> ^width=gcnew array<int>(4);
		width[0]=xcount;
		width[1]=128;
		width[2]=128;
		width[3]=maxcls+1;
		bp->init(width);
		bp->train(x,y,count);
		ifs.close();
		bp->save();
		MessageBox::Show(gcnew String("训练成功！"));
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				trainnet();

		 }
	private: int identify()
		 {
			array<double> ^x,^y;
			x=todata();
			y=bp->identify(x);
			double max=0;
			int ans=0;
			for (int i=0;i<=y->Length-1;i++)
			{
				if (y[i]>max)
				{
					max=y[i];
					ans=i;
				}
			}
			return ans;
		 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 label1->Text=identify().ToString();
		 }
	private: System::Void numericUpDown4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			  cp->changemode(5);
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 data->ignore();
			 cp->changemode(2);
		 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 dc->resetcursor();
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 cp->changemode(0);
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->ShowDialog();
			
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 
			 System::Diagnostics::Process::Start(openFileDialog1->FileName);
			 data->ignore();
			 cp->changemode(3);
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) ;
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void notifyIcon1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 ontop();
		 }
private: System::Void notifyIcon1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 e->Cancel=!exit;
			 if (!exit) WindowState=FormWindowState::Minimized;
		 }
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			ontop();
		 }
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 exitdo();
		 }
		 System::Void exitdo()
		 {
			 exit=true;
			 this->Close();
		 }
		 System::Void ontop()
		 {
			 WindowState=FormWindowState::Minimized;
			 WindowState=FormWindowState::Normal;
		 }
};

}
#include "skinextractor.h"
