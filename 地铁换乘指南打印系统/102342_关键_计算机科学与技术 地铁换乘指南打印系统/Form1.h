#pragma once
//#include"Form2.h"
#include "Station.h"
namespace My102342 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Form1 ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	ref class Form2;
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��ӡToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���ٴ�ӡToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Panel^  panel3;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::ComboBox^  comboBox1;
	public:	Da ^d;
	private: Form2 ^f2;
			Bitmap ^bit;
			Graphics ^gra;
			Pen ^p;
			Brush ^b;
			Drawing::Font ^f;
			StringFormat ^sf;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;

	protected: 

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ӡToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ٴ�ӡToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->����ToolStripMenuItem, 
				this->����ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(833, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->����ToolStripMenuItem, 
				this->��ӡToolStripMenuItem, this->���ٴ�ӡToolStripMenuItem});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->����ToolStripMenuItem->Text = L"����/վ�����ô���";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����ToolStripMenuItem_Click);
			// 
			// ��ӡToolStripMenuItem
			// 
			this->��ӡToolStripMenuItem->Name = L"��ӡToolStripMenuItem";
			this->��ӡToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->��ӡToolStripMenuItem->Text = L"��ӡ...";
			this->��ӡToolStripMenuItem->Visible = false;
			// 
			// ���ٴ�ӡToolStripMenuItem
			// 
			this->���ٴ�ӡToolStripMenuItem->Name = L"���ٴ�ӡToolStripMenuItem";
			this->���ٴ�ӡToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->���ٴ�ӡToolStripMenuItem->Text = L" ���ٴ�ӡ";
			this->���ٴ�ӡToolStripMenuItem->Visible = false;
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->����ToolStripMenuItem, 
				this->����ToolStripMenuItem});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(44, 21);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Visible = false;
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(805, 475);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(805, 475);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->numericUpDown1);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->comboBox2);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Location = System::Drawing::Point(0, 481);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(805, 100);
			this->panel2->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(778, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 12);
			this->label4->TabIndex = 6;
			this->label4->Text = L"��";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(686, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 5;
			this->label3->Text = L"�ȳ�ʱ��";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(745, 18);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2000000000, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(33, 21);
			this->numericUpDown1->TabIndex = 4;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(688, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 26);
			this->button1->TabIndex = 3;
			this->button1->Text = L"��ѯ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(482, 55);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(200, 20);
			this->comboBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(459, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"��";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(482, 17);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(200, 20);
			this->comboBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(459, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"��";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Margin = System::Windows::Forms::Padding(100);
			this->textBox1->MaxLength = 2000000000;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(452, 100);
			this->textBox1->TabIndex = 0;
			this->textBox1->WordWrap = false;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->Controls->Add(this->panel1);
			this->panel3->Controls->Add(this->panel2);
			this->panel3->Location = System::Drawing::Point(12, 40);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(805, 581);
			this->panel3->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(833, 637);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"102342 �ؼ� ��������ָ�ϴ�ӡϵͳ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				d=gcnew Da();
				//d->mydata();
				 p=gcnew Pen(Color::Black,10);
				 sf=gcnew StringFormat();
				 sf->Alignment=StringAlignment::Center;
				 //f=gcnew Drawing::Font("����",10);
				 updatepac();


			 }
					
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 if ((comboBox1->SelectedIndex!=-1)&&(comboBox2->SelectedIndex!=-1))
				 {
					d->searchroute(comboBox1->SelectedItem,comboBox2->SelectedItem,Decimal::ToInt32(numericUpDown1->Value));
					textBox1->Text=d->st;
					updatep();
				}
			 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		 System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
public:	Void updatec()
		{
			int i;
			comboBox1->Items->Clear();
			comboBox1->Text="";
			 comboBox2->Items->Clear();
			 comboBox2->Text="";

			 for (i=0;i<=d->sta->Count-1;i++)
			{
				
				comboBox1->Items->Add(d->sta[i]);
				comboBox2->Items->Add(d->sta[i]);
			}
		}
public:	Void updatep()
		 {
			 int i,j,maxx=-2000000001,minx=2000000001,maxy=-2000000001,miny=2000000001,dx,dy;
			 if (d->sta->Count>0)
			 {
			 for (i=0;i<=d->sta->Count-1;i++)
			{
				
				if (maxx<((Station^)(d->sta[i]))->x) maxx=((Station^)(d->sta[i]))->x;
				if (minx>((Station^)(d->sta[i]))->x) minx=((Station^)(d->sta[i]))->x;
				if (maxy<((Station^)(d->sta[i]))->y) maxy=((Station^)(d->sta[i]))->y;
				if (miny>((Station^)(d->sta[i]))->y) miny=((Station^)(d->sta[i]))->y;
			}
			 dx=maxx-minx;
			 dy=maxy-miny;
			 maxx=(int)(maxx+dx*0.3);
			 minx=(int)(minx-dx*0.3);
			 maxy=(int)(maxy+dy*0.3);
			 miny=(int)(miny-dy*0.3);
			 bit=gcnew Bitmap(maxx-minx, maxy-miny);
			 gra=Graphics::FromImage(bit);
			 gra->Clear(Color::White);
			 p->Width=10;
			 b=gcnew SolidBrush(Color::Black);
			 f=gcnew Drawing::Font("����",5);
			 for (i=0;i<=d->tra->Count-1;i++)
			 {
				 String ^name=d->tra[i]->ToString();
				 p->Color=((Train^)(d->tra[i]))->c;
				 for (j=1;j<=((Train^)(d->tra[i]))->sa->Count-1;j++)
				 {
					int fx=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j-1]))->s))->x-minx;
					int fy=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j-1]))->s))->y-miny;
					int tx=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j]))->s))->x-minx;
					int ty=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j]))->s))->y-miny;
					//int tt=((Starrive^)(((Train^)(d->tra[i]))->sa[j]))->wt-((Starrive^)(((Train^)(d->tra[i]))->sa[j-1]))->wt;
					gra->DrawLine(p,fx,fy,tx,ty);
					
					//gra->DrawString(name+"("+tt.ToString()+"��)",f,b,(fx+tx)/2,(fy+ty)/2,sf);

				 }
			 }
			 p->Color=Color::Red;
			 if (d->route)
			 {
				for (i=1;i<=d->route->Count-1;i++)
				{
					 int fx=((Station^)(d->route[i-1]))->x-minx;
					 int fy=((Station^)(d->route[i-1]))->y-miny;
					 int tx=((Station^)(d->route[i]))->x-minx;
					 int ty=((Station^)(d->route[i]))->y-miny;
					 gra->DrawLine(p,fx,fy,tx,ty);	

				}
			 }
			for (i=0;i<=d->tra->Count-1;i++)
			 {
				 String ^name=d->tra[i]->ToString();
				 p->Color=((Train^)(d->tra[i]))->c;
				 for (j=1;j<=((Train^)(d->tra[i]))->sa->Count-1;j++)
				 {
					int fx=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j-1]))->s))->x-minx;
					int fy=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j-1]))->s))->y-miny;
					int tx=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j]))->s))->x-minx;
					int ty=((Station^)(((Starrive^)(((Train^)(d->tra[i]))->sa[j]))->s))->y-miny;
					int tt=((Starrive^)(((Train^)(d->tra[i]))->sa[j]))->wt-((Starrive^)(((Train^)(d->tra[i]))->sa[j-1]))->wt;
					//gra->DrawLine(p,fx,fy,tx,ty);
					
					gra->DrawString(name+"("+tt.ToString()+"��)",f,b,(fx+tx)/2,(fy+ty)/2,sf);

				 }
			 }
			 p->Color=Color::Black;
			 p->Width=1;
			 f=gcnew Drawing::Font("����",7);


			 for (i=0;i<=d->sta->Count-1;i++)
			 {
				 int cx=((Station^)(d->sta[i]))->x-minx;
				 int cy=((Station^)(d->sta[i]))->y-miny;
				 String ^name=((Station^)(d->sta[i]))->name;
				 int r=20;
				 gra->FillEllipse(gcnew SolidBrush(Color::White),cx-r,cy-r,2*r,2*r);
				 gra->DrawEllipse(p,cx-r,cy-r,2*r,2*r);
				 gra->DrawString(name,f,gcnew SolidBrush(Color::Black),cx,cy-5,sf);
		
			 }
			 pictureBox1->Image=bit;
			 }

		 }
	public:	Void updatepac()
			{
				updatep();
				updatec();
			}
	public:	Void updatepc()
			{
				textBox1->Text="";
				d->route->Clear();
				updatep();
				updatec();

			}

};
}
