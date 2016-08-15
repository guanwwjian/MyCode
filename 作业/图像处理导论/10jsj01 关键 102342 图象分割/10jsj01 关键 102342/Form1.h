#pragma once
#include<cmath>

namespace My10jsj01关键102342 {

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
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  button5;
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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				18.05556F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				81.94444F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				110)));
			this->tableLayoutPanel1->Controls->Add(this->button1, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->button2, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(30, 28);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45.13274F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 54.86726F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 128)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(609, 227);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tableLayoutPanel1_Paint);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(508, 10);
			this->button1->Margin = System::Windows::Forms::Padding(10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"浏览";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(100, 10);
			this->textBox1->Margin = System::Windows::Forms::Padding(10);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(388, 21);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 10);
			this->label1->Margin = System::Windows::Forms::Padding(10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"输入文件：";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 54);
			this->label2->Margin = System::Windows::Forms::Padding(10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"输出文件：";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(100, 54);
			this->textBox2->Margin = System::Windows::Forms::Padding(10);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(388, 21);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(508, 54);
			this->button2->Margin = System::Windows::Forms::Padding(10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"浏览";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->button3, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->button5, 1, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(93, 101);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45.23809F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 54.76191F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(402, 123);
			this->tableLayoutPanel2->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(50, 48);
			this->button3->Margin = System::Windows::Forms::Padding(50, 10, 50, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 26);
			this->button3->TabIndex = 6;
			this->button3->Text = L"图像放大";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(251, 48);
			this->button5->Margin = System::Windows::Forms::Padding(50, 10, 50, 10);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(101, 26);
			this->button5->TabIndex = 7;
			this->button5->Text = L"图像阈值分割";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"BMP|*.BMP|GIF|*.GIF|EXIF|*.EXIF|JPG|*.JPG|PNG|*.PNG|TIFF|*.TIFF";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"BMP|*.BMP|GIF|*.GIF|EXIF|*.EXIF|JPG|*.JPG|PNG|*.PNG|TIFF|*.TIFF";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 285);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MinimumSize = System::Drawing::Size(681, 323);
			this->Name = L"Form1";
			this->Text = L"图像放大与分割";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 openFileDialog1 -> ShowDialog();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				saveFileDialog1 -> ShowDialog();
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
				textBox1->Text = openFileDialog1->FileName;
				if ((textBox1->Text=="")||(textBox2->Text=="")) 
				{
					button3->Enabled=false;
					button5->Enabled=false;
				}
				else 
				{
					button3->Enabled=true;
					button5->Enabled=true;
				}
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
				textBox2->Text = saveFileDialog1->FileName;
				if ((textBox1->Text=="")||(textBox2->Text=="")) 
				{
					button3->Enabled=false;
					button5->Enabled=false;
				}
				else 
				{
					button3->Enabled=true;
					button5->Enabled=true;
				}
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				Bitmap ^obm = gcnew Bitmap(textBox1->Text);
				int oh,ow,sh,sw,i,j,x,y;
				oh=obm->Size.Height;
				ow=obm->Size.Width;
				sh=oh*4;
				sw=ow*4;
				Bitmap ^sbm = gcnew Bitmap(sw,sh);
				for (i=0;i<=ow-1;i++)
					for (j=0;j<=oh-1;j++)
						for (x=0;x<=3;x++)
							for (y=0;y<=3;y++)
								sbm->SetPixel(i*4+x,j*4+y,obm->GetPixel(i,j));
				sbm->Save(textBox2->Text);

		 }

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 	Bitmap ^obm = gcnew Bitmap(textBox1->Text);
				int oh,ow,sh,sw,i,j,t;
				int a[256],b[256];
				oh=obm->Size.Height;
				ow=obm->Size.Width;
				for (i=0;i<=ow-1;i++)
					for (j=0;j<=oh-1;j++)
						a[obm->GetPixel(i,j).R]++;
				double mb,d=0.4;
				mb=abs(a[0]-oh*ow*d);
				t=0;
				b[0]=a[0];

				for (i=1;i<=255;i++) 
				{
					b[i]=b[i-1]+a[i];
					if (abs(b[i]-oh*ow*d)<mb)
					{
						mb=abs(b[i]-oh*ow*d);
						t=i;
					}
					
				}
				Bitmap ^sbm=gcnew Bitmap(ow,oh);
				for (i=0;i<=ow-1;i++)
					for (j=0;j<=oh-1;j++)
					{
						if (obm->GetPixel(i,j).R<t) sbm->SetPixel(i,j,Color::Black);
						else sbm->SetPixel(i,j,Color::White);
					}
				sbm->Save(textBox2->Text);




		 }
};
}

