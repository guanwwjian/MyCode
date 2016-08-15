#pragma once
#include "bpnet.h"

namespace My102342关键神经网络数字识别 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	Bpnet ^bp;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(524, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"训练";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(524, 90);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 32);
			this->button2->TabIndex = 0;
			this->button2->Text = L"判断";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(524, 166);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(57, 32);
			this->button3->TabIndex = 0;
			this->button3->Text = L"重置";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(128, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(301, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L".\\learn\\";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(445, 27);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(57, 32);
			this->button4->TabIndex = 0;
			this->button4->Text = L"浏览";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(128, 97);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(301, 21);
			this->textBox2->TabIndex = 1;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(445, 90);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(57, 32);
			this->button5->TabIndex = 0;
			this->button5->Text = L"浏览";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"样本文件目录：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"待判别文件路径：";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(137, 154);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(110, 109);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(291, 166);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 97);
			this->label3->TabIndex = 5;
			this->label3->Text = L"？";
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &Form1::folderBrowserDialog1_HelpRequest);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 308);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"102342 关键 神经网络数字识别";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 folderBrowserDialog1->ShowDialog();
				 //if (folderBrowserDialog1->SelectedPath).
				 textBox1->Text=folderBrowserDialog1->SelectedPath;
			 }
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFileDialog1->ShowDialog();

		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox2->Text=openFileDialog1->FileName;
			 Bitmap ^b= gcnew Bitmap(textBox2->Text);
			 pictureBox1->Image=b;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 array<String^,2> ^file=gcnew array<String^,2>(10);
			 for (int i=0;i<=9;i++)
			 {
				 String ^tt=textBox1->Text+i.ToString()+"\\";
				 DirectoryInfo ^dir=gcnew DirectoryInfo(tt);
				 array<FileInfo^> ^finfo = dir->GetFiles("*.bmp");
				 file[i]=gcnew array<String^>(finfo->Length);
				 for (int j=0;j<=finfo->Length-1;j++)
				 {
					 file[i][j]=finfo[j]->Name;
				 }
			 }
			 


		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 array<int> ^conf={9,10,10};
			 bp=gcnew Bpnet(conf);
		 }
};
}

