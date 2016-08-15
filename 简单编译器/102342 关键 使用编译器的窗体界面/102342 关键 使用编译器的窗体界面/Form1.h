#pragma once


namespace My102342关键使用编译器的窗体界面 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveFileDialog3 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(118, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(298, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"resource.res";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(118, 86);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(298, 21);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"masmcode.asm";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(118, 113);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(298, 21);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"midcode.mid";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(118, 140);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(298, 21);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"message.mes";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 12);
			this->label1->TabIndex = 4;
			this->label1->Text = L"源文件路径：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"目标文件路径：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"中间文件路径：";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 12);
			this->label4->TabIndex = 4;
			this->label4->Text = L"消息文件路径：";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(422, 57);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"浏览";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(422, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"浏览";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(422, 111);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"浏览";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(422, 138);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"浏览";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(217, 193);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"执行编译";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(118, 32);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(298, 21);
			this->textBox5->TabIndex = 0;
			this->textBox5->Text = L"102342 关键 编译原理课程设计：编译器.exe";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 35);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 12);
			this->label5->TabIndex = 4;
			this->label5->Text = L"编译器路径：";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(422, 30);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"浏览";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"102342 关键 编译原理课程设计：编译器.exe";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog2_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// saveFileDialog2
			// 
			this->saveFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog2_FileOk);
			// 
			// saveFileDialog3
			// 
			this->saveFileDialog3->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog3_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(525, 261);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(541, 299);
			this->MinimumSize = System::Drawing::Size(541, 299);
			this->Name = L"Form1";
			this->Text = L"102342 关键 使用编译器的窗体界面";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 openFileDialog1->ShowDialog();
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
			openFileDialog2->ShowDialog();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			
			saveFileDialog1->ShowDialog();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			
			saveFileDialog2->ShowDialog();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			
			saveFileDialog3->ShowDialog();
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox5->Text=openFileDialog1->FileName;
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->InitialDirectory=IO::Directory::GetCurrentDirectory();
			openFileDialog1->FileName="102342 关键 编译原理课程设计：编译器.exe";
			textBox5->Text="102342 关键 编译原理课程设计：编译器.exe";
			openFileDialog2->InitialDirectory=IO::Directory::GetCurrentDirectory();
			openFileDialog2->FileName="源代码.res";
			textBox1->Text="源代码.res";
			saveFileDialog1->InitialDirectory=IO::Directory::GetCurrentDirectory();
			saveFileDialog1->FileName="汇编代码.asm";
			textBox2->Text="汇编代码.asm";
			saveFileDialog2->InitialDirectory=IO::Directory::GetCurrentDirectory();
			saveFileDialog2->FileName="中间代码.mid";
			textBox3->Text="中间代码.mid";
			saveFileDialog3->InitialDirectory=IO::Directory::GetCurrentDirectory();
			saveFileDialog3->FileName="规约过程.mes";
			textBox4->Text="规约过程.mes";
		 }
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox1->Text=openFileDialog2->FileName;
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox2->Text=saveFileDialog1->FileName;
		 }
private: System::Void saveFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox3->Text=saveFileDialog2->FileName;
		 }
private: System::Void saveFileDialog3_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox4->Text=saveFileDialog3->FileName;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			Process ^p = gcnew Process();
			p->StartInfo->FileName="\""+textBox5->Text+"\"";
			p->StartInfo->Arguments = "\""+textBox1->Text+"\" \""+textBox2->Text+"\" \""+textBox3->Text+"\" \""+textBox4->Text+"\""; 
			p->StartInfo->WorkingDirectory = IO::Directory::GetCurrentDirectory();
            p->StartInfo->UseShellExecute = false;        
            p->StartInfo->CreateNoWindow = true;          
            p->Start();
			p->WaitForExit();
            p->Close();
			Windows::Forms::MessageBox::Show("执行完毕！","执行完毕！");
		 }
};

}
