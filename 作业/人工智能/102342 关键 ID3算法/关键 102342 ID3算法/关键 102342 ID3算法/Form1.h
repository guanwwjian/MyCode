#pragma once
//#include"PropValue.h"
#include"Samples.h"
namespace 关键102342ID3算法 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	//using namespace std;

	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
//	ref class PropValue;
	
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
	private: System::Windows::Forms::TreeView^  treeView1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	PropValue ^rule;
	Samples ^sample;
	TreeNodeCollection ^tree;
	int time;
	array<int> ^props;

	private: System::ComponentModel::IContainer^  components;
			 //array<array<array<int>^>^> ^p;
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
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(12, 12);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(608, 233);
			this->treeView1->TabIndex = 0;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterSelect);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 293);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(311, 21);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 296);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"样例文件路径：";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(447, 291);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"浏览";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 323);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"测试数据：";
			this->label2->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(272, 320);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"建立决策树";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(130, 320);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(311, 21);
			this->textBox2->TabIndex = 1;
			this->textBox2->Visible = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(447, 318);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"测试";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(130, 266);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(311, 21);
			this->textBox3->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 269);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"属性说明文件路径：";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(447, 264);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"浏览";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog2_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(632, 360);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->treeView1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(648, 398);
			this->MinimumSize = System::Drawing::Size(648, 398);
			this->Name = L"Form1";
			this->Text = L"102342 关键 ID3算法";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
 private:Void creattree(TreeNode ^pnode,Samples ^sam,int height)
		 {
			int i=0,j=0,k=0,maxp=-1;
			int cno=rule->getcno(),countcla=rule->countofcla(),rcount=rule->count();
			int scount=sam->count();
			double max=-1,gain;
			array<int> ^pclass=gcnew array<int>(countcla);
			for (i=0;i<=countcla-1;i++)
			{
				pclass[i]=0;
			}
			array<array<array<int>^>^> ^pp=gcnew array<array<array<int>^>^>(rcount);
			for (i=0;i<=rcount-1;i++)
			{
				pp[i]=gcnew array<array<int>^>(rule->countofp(i));
				for (j=0;j<=rule->countofp(i)-1;j++)
				{
					pp[i][j]=gcnew array<int>(countcla);
					for (k=0;k<=countcla-1;k++)
					{
						pp[i][j][k]=0;
					}
				}
			}

			for (i=0;i<=scount-1;i++)
			{
				pclass[sam->data[i][cno]]++;
				for (j=0;j<=rcount-1;j++)
				{
					pp[j][sam->data[i][j]][0]++;
					pp[j][0][sam->data[i][cno]]++;
					pp[j][sam->data[i][j]][sam->data[i][cno]]++;
				}
			}
			for (i=1;i<=countcla-1;i++)
			{
				if (pclass[i]==scount)
				{
					pnode->Nodes->Add(rule->ntop(cno)+":"+rule->pij(cno,i));
					return;
				}
			}
			for (i=0;i<=rcount-1;i++)
				if (i!=cno)
				{
					gain=0;
					for(j=1;j<=countcla-1;j++)
					{
						double p=(double)pp[i][0][j]/scount;
						if (p>0) gain+=-p*Math::Log(p,2);
					}
					for (j=1;j<=rule->countofp(i)-1;j++)
					{
						double ipn=0;
						for (k=1;k<=countcla-1;k++)
						{
							if (pp[i][j][0]>0)
							{double p=(double)pp[i][j][k]/pp[i][j][0];
							if (p>0) ipn+=-p*Math::Log(p,2);
							}
						}
						gain-=(double)pp[i][j][0]/scount*ipn;
						
					}
					if (gain>max)
					{
						max=gain;
						maxp=i;
					}

				}
				for (i=1;i<=rule->countofp(maxp)-1;i++)
				{
					pnode->Nodes->Add(i.ToString(),rule->ntop(maxp)+":"+rule->pij(maxp,i));
					creattree(pnode->Nodes[i.ToString()],gcnew Samples(sam,maxp,i),height+1);
				}

		 }
		 /*Void pinit()
		 {
			int i,j,k;
			p=gcnew array<array<array<int>^>^>(rule->count());
			for (i=1;i<=rule->count()-1;i++)
			{
				p[i]=gcnew array<array<int>^>(rule->countofp(i));
				for (j=0;j<=rule->countofp(i)-1;j++)
				{
					p[i][j]=gcnew array<int>(rule->coutofp(0));
					for (k=0;k<=countofp(0)-1;i++)
					{
						p[i][j][k]=0
					}
				}
			}
			for (i=1;i<=sample->count()-1;i++)
			{
				for (j=0;j<=sample->data[i]->length-1;j++)
				{
					//p[j][rule->pton(sample->data[i][j])][pton(sample->data[i][j])]
				}
			}

		 }*/
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox3->Text=="")
			 {
				 MessageBox::Show("请选择属性说明文件！");
			 }
			 else if (textBox1->Text=="")
			 {
				 MessageBox::Show("请选择样例文件！");
			 }
			 else 
			 {
				treeView1->Nodes->Clear();
				//time=0;
				//timer1->Enabled=true;
				DateTime begin=DateTime::Now;
				rule=gcnew PropValue(textBox3->Text);
				sample=gcnew Samples(textBox1->Text,rule);
				props=gcnew array<int>(rule->count());
				int i;
				for (i=0;i<=rule->count()-1;i++)
				{
					props[i]=-1;
				}
				//tree=gcnew TreeNodeCollection();
				treeView1->Nodes->Add("root");
				creattree(treeView1->Nodes[0],sample,0);
				//for (int i=0;i<=100000000;i++)
				//timer1->Enabled=false;
				//time=(int)(DateTime::Now.Subtract(begin).TotalMilliseconds);
				MessageBox::Show("决策树建立完成，花费时间"+DateTime::Now.Subtract(begin).TotalMilliseconds+"毫秒。");
			 }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFileDialog1->ShowDialog();
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox3->Text=openFileDialog1->FileName;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFileDialog2->ShowDialog();
		 }
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 textBox1->Text=openFileDialog2->FileName;
		 }
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 time++;
		 }
};
	
}


