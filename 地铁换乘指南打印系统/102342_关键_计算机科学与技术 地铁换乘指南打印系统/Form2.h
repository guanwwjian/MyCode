#pragma once

#include"Form1.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//using namespace My102342;


namespace My102342 {

	/// <summary>
	/// Form2 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	private:
		Form1 ^f1;
	public:
		Form2(Form1 ^fa)
		{
			f1=fa;
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
			 Da ^d,^od;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
			 /*private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox1;*/
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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(9, 27);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(199, 220);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form2::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 12;
			this->listBox2->Location = System::Drawing::Point(22, 27);
			this->listBox2->Name = L"listBox2";
			this->listBox2->ScrollAlwaysVisible = true;
			this->listBox2->Size = System::Drawing::Size(199, 220);
			this->listBox2->TabIndex = 0;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form2::listBox2_SelectedIndexChanged);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->HorizontalScrollbar = true;
			this->listBox3->ItemHeight = 12;
			this->listBox3->Location = System::Drawing::Point(13, 27);
			this->listBox3->Name = L"listBox3";
			this->listBox3->ScrollAlwaysVisible = true;
			this->listBox3->Size = System::Drawing::Size(274, 220);
			this->listBox3->TabIndex = 0;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form2::listBox3_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(55, 271);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 21);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"添加";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(54, 271);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(59, 21);
			this->textBox2->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(120, 306);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"修改";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(38, 306);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"添加";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(145, 335);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"修改";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(46, 306);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 2;
			this->button5->Text = L"添加";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form2::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(182, 306);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 4;
			this->button6->Text = L"修改";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form2::button6_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(182, 271);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(46, 21);
			this->numericUpDown1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 274);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 6;
			this->label1->Text = L"线路名称";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 274);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 12);
			this->label2->TabIndex = 7;
			this->label2->Text = L"车站名";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(51, 274);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 12);
			this->label3->TabIndex = 8;
			this->label3->Text = L"始发站至该站运行时间";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Location = System::Drawing::Point(18, 17);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(216, 372);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"线路";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(73, 335);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 2;
			this->button9->Text = L"删除";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form2::button9_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->numericUpDown3);
			this->groupBox2->Controls->Add(this->numericUpDown2);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->button10);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->listBox2);
			this->groupBox2->Location = System::Drawing::Point(233, 17);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(238, 372);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"车站";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(155, 306);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(11, 12);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(119, 274);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 12);
			this->label5->TabIndex = 8;
			this->label5->Text = L"坐标：X";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(172, 304);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, 0});
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, System::Int32::MinValue});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(46, 21);
			this->numericUpDown3->TabIndex = 5;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(172, 272);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, System::Int32::MinValue});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(46, 21);
			this->numericUpDown2->TabIndex = 5;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(38, 335);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 2;
			this->button10->Text = L"删除";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form2::button10_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->numericUpDown1);
			this->groupBox3->Controls->Add(this->button11);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->listBox3);
			this->groupBox3->Location = System::Drawing::Point(470, 17);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(293, 371);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"指定线路到达车站及时间";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(234, 274);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 12);
			this->label4->TabIndex = 9;
			this->label4->Text = L"分";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(115, 335);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 2;
			this->button11->Text = L"删除";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form2::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(159, 417);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 2;
			this->button12->Text = L"确定";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			this->button12->Click += gcnew System::EventHandler(this, &Form2::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(470, 417);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 23);
			this->button13->TabIndex = 2;
			this->button13->Text = L"取消";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Visible = false;
			this->button13->Click += gcnew System::EventHandler(this, &Form2::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(324, 417);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 23);
			this->button14->TabIndex = 2;
			this->button14->Text = L"测试数据";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form2::button14_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(775, 467);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(791, 505);
			this->MinimumSize = System::Drawing::Size(791, 505);
			this->Name = L"Form2";
			this->Text = L"车次/站点设置窗口";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {				 
				 d=f1->d;
//			 od=gcnew Da(d);
				button14->Enabled=!d->myd;

				 updatelist();	
			 }
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
				//save	
				 this->Close();
			 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			// f1->d=gcnew Da(od);
			 this->Close();

		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 /*int x=(int)listBox1->SelectedIndex;
			 //String ^st=listBox1->SelectedValue->ToString();
			 //String ^st2=gcnew String(listBox1->SelectedIndex.ToString);
			 listBox1->Items->Add(gcnew Station("123"));*/
			 //updatelist();
			 if (listBox1->SelectedIndex!=-1) textBox1->Text=listBox1->SelectedItem->ToString();
			 else textBox1->Text="";
			 updatelist3();

		 }
private: Void updatelist()
		 {
			int i;
			listBox1->Items->Clear();
			for (i=0;i<=d->tra->Count-1;i++)
			{
				listBox1->Items->Add(d->tra[i]);
			}
			listBox2->Items->Clear();
			for (i=0;i<=d->sta->Count-1;i++)
			{
				listBox2->Items->Add(d->sta[i]);
			}
			listBox3->Items->Clear();
			if (listBox1->SelectedIndex!=-1)
			for (i=0;i<=(((Train^)(listBox1->SelectedItem))->sa->Count-1);i++)
			{
				listBox3->Items->Add(((Train^)(listBox1->SelectedItem))->sa[i]);
			}
		 }
private: Void updatelist3()
		 {
			int i;
			listBox3->Items->Clear();
			if (listBox1->SelectedIndex!=-1)
			for (i=0;i<=(((Train^)(listBox1->SelectedItem))->sa->Count-1);i++)
			{
				listBox3->Items->Add(((Train^)(listBox1->SelectedItem))->sa[i]);
			}
		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 d->addtra(textBox1->Text);
			 listBox1->Items->Add(d->tra[d->tra->Count-1]);
			 listBox1->SelectedIndex=listBox1->Items->Count-1;
			 //updatelist();
			 f1->updatepc();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listBox1->SelectedIndex!=-1) 
			 {
				 d->moditra(listBox1->SelectedItem,textBox1->Text);
				listBox1->Items[listBox1->SelectedIndex]=listBox1->Items[listBox1->SelectedIndex];
				f1->updatepc();

			 }
			 //updatelist();

		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listBox1->SelectedIndex!=-1)
			 {
				 int old=listBox1->SelectedIndex;
				 d->remtra(listBox1->SelectedItem);
				 listBox1->Items->Remove(listBox1->SelectedItem);
				 if (old<listBox1->Items->Count-1) listBox1->SelectedIndex=old;
				 f1->updatepc();

			 }
			 //updatelist();


		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 d->addsta(textBox2->Text,Decimal::ToInt32(numericUpDown2->Value),Decimal::ToInt32(numericUpDown3->Value));
			 listBox2->Items->Add(d->sta[d->sta->Count-1]);
			 listBox2->SelectedIndex=listBox2->Items->Count-1;
			 f1->updatepc();

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listBox2->SelectedIndex!=-1) 
			 {
				 d->modista(listBox2->SelectedItem,textBox2->Text,Decimal::ToInt32(numericUpDown2->Value),Decimal::ToInt32(numericUpDown3->Value));
				listBox2->Items[listBox2->SelectedIndex]=listBox2->Items[listBox2->SelectedIndex];
				f1->updatepc();
				 updatelist3();

			 }
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listBox2->SelectedIndex!=-1)
			 {
				 int old=listBox2->SelectedIndex;
				 d->remsta(listBox2->SelectedItem);
				 listBox2->Items->Remove(listBox2->SelectedItem);
				 if (old<listBox2->Items->Count-1) listBox2->SelectedIndex=old;
				 updatelist3();
				f1->updatepc();

			 }
			 //updatelist();


		 }

private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (listBox2->SelectedIndex!=-1)
			 {
				textBox2->Text=((Station^)(listBox2->SelectedItem))->name;
				numericUpDown2->Value=Decimal(((Station^)(listBox2->SelectedItem))->x);
				numericUpDown3->Value=Decimal(((Station^)(listBox2->SelectedItem))->y);
			 }

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 if ((listBox1->SelectedIndex!=-1)&&(listBox2->SelectedIndex!=-1))
			 {
				 d->addsa(listBox1->SelectedItem,listBox2->SelectedItem,Decimal::ToInt32(numericUpDown1->Value));
				 f1->updatepc();
				updatelist3();
			 }
			 
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listBox3->SelectedIndex!=-1)
			 {
				 d->remsa(listBox3->SelectedItem);
				f1->updatepc();
				updatelist3();
			 }
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			if (listBox3->SelectedIndex!=-1)
			{
				d->modisa(listBox3->SelectedItem,Decimal::ToInt32(numericUpDown1->Value));
				 f1->updatepc();
				updatelist3();
			}
		 }

private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 d->mydata();
			updatelist();
			f1->updatepc();
			button14->Enabled=!d->myd;
		 }
private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (listBox3->SelectedIndex!=-1) numericUpDown1->Value=((Starrive^)(listBox3->SelectedItem))->wt;
		 }
};
	
}