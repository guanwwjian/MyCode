#pragma once


namespace My102342关键语法分析器 {

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
	private: System::Windows::Forms::TextBox^  textBox2;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::Button^  button2;

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->AcceptsReturn = true;
			this->textBox2->AcceptsTab = true;
			this->textBox2->Location = System::Drawing::Point(45, 179);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(230, 103);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"#i*i+i*(i+i^i)#";
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->AcceptsTab = true;
			this->textBox1->Location = System::Drawing::Point(45, 48);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(230, 103);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"S->#E#\r\nE->E+T|T\r\nT->T*F|F\r\nF->P^F|P\r\nP->(E)|i";
			// 
			// textBox3
			// 
			this->textBox3->AcceptsReturn = true;
			this->textBox3->AcceptsTab = true;
			this->textBox3->Location = System::Drawing::Point(550, 48);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox3->Size = System::Drawing::Size(230, 234);
			this->textBox3->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(634, 375);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"提交";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(43, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"文法描述：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(43, 164);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"句型描述：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(548, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"算符优先表：";
			// 
			// textBox4
			// 
			this->textBox4->AcceptsReturn = true;
			this->textBox4->AcceptsTab = true;
			this->textBox4->Location = System::Drawing::Point(303, 179);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox4->Size = System::Drawing::Size(230, 103);
			this->textBox4->TabIndex = 0;
			// 
			// textBox5
			// 
			this->textBox5->AcceptsReturn = true;
			this->textBox5->AcceptsTab = true;
			this->textBox5->Location = System::Drawing::Point(303, 48);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox5->Size = System::Drawing::Size(230, 103);
			this->textBox5->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(301, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 12);
			this->label4->TabIndex = 2;
			this->label4->Text = L"FirstVT：";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(301, 164);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 12);
			this->label5->TabIndex = 2;
			this->label5->Text = L"LastVT：";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4});
			this->listView1->Location = System::Drawing::Point(45, 324);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(488, 225);
			this->listView1->TabIndex = 3;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"步骤";
			this->columnHeader1->Width = 42;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"符号栈";
			this->columnHeader2->Width = 155;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"输入串";
			this->columnHeader3->Width = 115;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"动作";
			this->columnHeader4->Width = 72;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(634, 466);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"退出";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 583);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox2);
			this->MaximumSize = System::Drawing::Size(837, 621);
			this->MinimumSize = System::Drawing::Size(837, 621);
			this->Name = L"Form1";
			this->Text = L"语法分析：算符优先文法  102342 关键";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	array<char> ^vn,^vt;
	int pvn,pvt;
	array<String^> ^l,^r;
	array<array<bool>^> ^firstvt,^lastvt;
	array<array<char>^> ^table;
	String ^stack;
	array<int> ^svn,^svt;
	int sp;
	int findvt(char c)	
	{
		for (int i=0;i<=pvt-1;i++)
			if (vt[i]==c) return i;
		return -1;
	}
	int findvn(char c)
	{
		for (int i=0;i<=pvn-1;i++)
			if (vn[i]==c) return i;
		return -1;
	}
	void insertf(int x,int y)
	{
		if (!firstvt[x][y])
		{
			firstvt[x][y]=true;
			svn[sp]=x;
			svt[sp]=y;
			sp++;
		}

	}
	void insertl(int x,int y)
	{
		if ((x==1)&&(y==2))
			int ttt=0;
		if (!lastvt[x][y])
		{
			lastvt[x][y]=true;
			svn[sp]=x;
			svt[sp]=y;
			sp++;
		}

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^tt;
				 int p=0;
				 l= gcnew array<String^>(1000);
				 r= gcnew array<String^>(1000);
				 vn=gcnew array<char>(256);
				 vt=gcnew array<char>(256);
				 int len=0;
				 while (len!=textBox1->Text->Length)
				 {
					 len=textBox1->Text->Length;
					 textBox1->Text=textBox1->Text->Replace("\r\n\r\n","\r\n");
					 textBox1->Text=textBox1->Text->Replace("||","|");
					 textBox1->Text=textBox1->Text->Replace("|\r\n","\r\n");
					 textBox1->Text=textBox1->Text->Replace("\r\n|","\r\n");
					 if ((textBox1->Text[0]==13)&&(textBox1->Text[1]==10)) textBox1->Text=textBox1->Text->Remove(0,2);
					 if ((textBox1->Text[textBox1->Text->Length-2]==13)&&(textBox1->Text[textBox1->Text->Length-1]==10)) textBox1->Text=textBox1->Text->Remove(textBox1->Text->Length-2);
					 if (textBox1->Text[0]=='|') textBox1->Text=textBox1->Text->Remove(0,1);
					 if (textBox1->Text[textBox1->Text->Length-1]=='|') textBox1->Text=textBox1->Text->Remove(textBox1->Text->Length-1);
				 }
				 tt=gcnew String(textBox1->Text);
				 tt=tt+"\r\n";
				 while (tt->Length>0)
				 {
					 int eoln=tt->IndexOf("\r\n");
					 //String ^tl=gcnew String(tt,0,tt->IndexOf("->"));//,^tr=gcnew String(tt,tt->IndexOf("->")+2,eoln-tt->IndexOf("->")-2);		
					 String ^tl,^tr;
					 if (tt->IndexOf("->")<0||tt->IndexOf("->")>=eoln)
					 {
						 MessageBox::Show("缺少->");
						 return;
					 }
					 tl=gcnew String(tt->ToCharArray(0,tt->IndexOf("->")));
					 tr=gcnew String(tt->ToCharArray(tt->IndexOf("->")+2,eoln-tt->IndexOf("->")-2));
					 tr=tr+"|";
					 tt=tt->Remove(0,eoln+2);
					 while (tr->Length>0)
					 {
						 l[p]=String::Copy(tl);
						 r[p]=gcnew String(tr->ToCharArray(0,tr->IndexOf("|")));
						 tr=tr->Remove(0,tr->IndexOf("|")+1);
						 p++;
					 }
				 }
				 pvn=0;pvt=0;
				 //vt[0]='#';
				 int i,j,k;
				for (i=0;i<=p-1;i++)
				{			
					for (j=0;j<=pvn-1;j++)
						if (vn[j]==l[i][0]) break;
					if (j>pvn-1) 
					{
						vn[pvn]=l[i][0];
						pvn++;
					}
					for (j=0;j<=r[i]->Length-1;j++)
						if ((r[i][j]<'A')||(r[i][j]>'Z'))
						{
							for (k=0;k<=pvt-1;k++)
								if (vt[k]==r[i][j]) break;
							if (k>pvt-1)
							{
								vt[pvt]=r[i][j];
								pvt++;
							}
						}
				}
				firstvt=gcnew array<array<bool>^>(pvn);
				lastvt=gcnew array<array<bool>^>(pvn);
				for (i=0;i<=pvn-1;i++)
				{
					firstvt[i]=gcnew array<bool>(pvt);
					lastvt[i]=gcnew array<bool>(pvt);
					for (j=0;j<=pvt-1;j++)
					{
						firstvt[i][j]=false;
						lastvt[i][j]=false;
					}
				}
				table=gcnew array<array<char>^>(pvt);
				for (i=0;i<=pvt-1;i++)
				{
					table[i]=gcnew array<char>(pvt);
					for (j=0;j<=pvt-1;j++)
					{
						table[i][j]=' ';
					}
				}
				sp=0;
				svn=gcnew array<int>(1000);
				svt=gcnew array<int>(1000);
				for (i=0;i<=p-1;i++)
				{
					for (j=0;j<=r[i]->Length-1;j++)
						if ((r[i][j]<'A')||(r[i][j]>'Z'))
						{
							insertf(findvn(l[i][0]),findvt(r[i][j]));
							break;
						}
				}
				while (sp>0)
				{
					sp--;
					for (i=0;i<=p-1;i++)
						if (findvn(r[i][0])==svn[sp])
							insertf(findvn(l[i][0]),svt[sp]);
				} 
				textBox5->Text=" ";
				for (i=0;i<=pvt-1;i++)
				{
					textBox5->Text=textBox5->Text+"  "+Char::ToString(vt[i]);
				}
				textBox5->Text+="\r\n";
				for (i=0;i<=pvn-1;i++)
				{
					textBox5->Text+=Char::ToString(vn[i]);
					for (j=0;j<=pvt-1;j++)
						if (firstvt[i][j]) textBox5->Text+="  T";
						else textBox5->Text+="  F";
					textBox5->Text+="\r\n";
				}

				sp=0;
				for (i=0;i<=p-1;i++)
				{
					for (j=r[i]->Length-1;j>=0;j--)
						if ((r[i][j]<'A')||(r[i][j]>'Z'))
						{
							insertl(findvn(l[i][0]),findvt(r[i][j]));
							break;
						}
				}
				while (sp>0)
				{
					sp--;
					for (i=0;i<=p-1;i++)
						if (findvn(r[i][r[i]->Length-1])==svn[sp])
							insertl(findvn(l[i][0]),svt[sp]);
				} 
				textBox4->Text=" ";
				for (i=0;i<=pvt-1;i++)
				{
					textBox4->Text=textBox4->Text+"  "+Char::ToString(vt[i]);
				}
				textBox4->Text+="\r\n";
				for (i=0;i<=pvn-1;i++)
				{
					textBox4->Text+=Char::ToString(vn[i]);
					for (j=0;j<=pvt-1;j++)
						if (lastvt[i][j]) textBox4->Text+="  T";
						else textBox4->Text+="  F";
					textBox4->Text+="\r\n";
				}
				for (i=0;i<=p-1;i++)
				{
					for (j=0;j<=r[i]->Length-2;j++)
					{
						
						if (j<=r[i]->Length-2)
						{
							int xx=findvt(r[i][j]),yy=findvt(r[i][j+1]);
							if ((xx>=0)&&(yy>=0))
							{
								if ((table[xx][yy]==' ')||(table[xx][yy]=='=')) table[xx][yy]='=';
								else
								{
									MessageBox::Show("此文法不是算符优先文法");
									return;
								}
							}
						}

						if (j<=r[i]->Length-3)
						{
							int xx=findvt(r[i][j]),yy=findvn(r[i][j+1]),zz=findvt(r[i][j+2]);
							if ((xx>=0)&&(yy>=0)&&(zz>=0))
							{
								if ((table[xx][zz]==' ')||(table[xx][zz]=='=')) table[xx][zz]='=';
								else
								{
									MessageBox::Show("此文法不是算符优先文法");
									return;
								}
							}
						}

						if (j<=r[i]->Length-2)
						{
							int xx=findvt(r[i][j]),yy=findvn(r[i][j+1]);
							if ((xx>=0)&&(yy>=0))
							{
								for (k=0;k<=pvt-1;k++)
									if (firstvt[yy][k])
									{
										if ((table[xx][k]==' ')||(table[xx][k]=='<')) table[xx][k]='<';
										else
										{
											MessageBox::Show("此文法不是算符优先文法");
											return;
										}
									}
							}
						}

						if (j<=r[i]->Length-2)
						{
							int xx=findvn(r[i][j]),yy=findvt(r[i][j+1]);
							if ((xx>=0)&&(yy>=0))
							{
								for (k=0;k<=pvt-1;k++)
									if (lastvt[xx][k])
									{
										if ((table[k][yy]==' ')||(table[k][yy]=='>')) table[k][yy]='>';
										else
										{
											MessageBox::Show("此文法不是算符优先文法");
											return;
										}
									}
							}
						}
					}
				}
				textBox3->Text=" ";
				for (i=0;i<=pvt-1;i++)
					textBox3->Text+=("  "+Char::ToString(vt[i]));
				textBox3->Text+="\r\n";
				for (i=0;i<=pvt-1;i++)
				{	
					textBox3->Text+=Char::ToString(vt[i]);
					for (j=0;j<=pvt-1;j++)
						textBox3->Text+=("  "+Char::ToString(table[i][j]));
					textBox3->Text+="\r\n";

				}

				tt=gcnew String(textBox2->Text->ToCharArray());
				tt->Replace("\r\n","");
				int no=1;
				stack=gcnew String("");
				stack+=Char::ToString(tt[0]);
				tt=tt->Remove(0,1);
				listView1->Items->Clear();
				listView1->Items->Add(gcnew ListViewItem(gcnew array<String^>(4){no.ToString(),stack,tt,L"准备"}));
				int from=0;
				while ((tt->Length>0)||(stack->Length>1))
				{
					int o=stack->Length-1;
					no++;
					while ((stack[o]>='A')&&(stack[o]<='Z')) o--;
					//if (tt->Length>0)
					//{
						if ((tt->Length==0)||(table[findvt(stack[o])][findvt(tt[0])]=='>'))
						{
							/*for (i=0;i<=p-1;i++)
							{
								String ^tl=gcnew String(stack->ToCharArray(from,stack->Length-from));
								if (tl->Equals(r[i]))
								{
									stack=stack->Remove(from,stack->Length-from);
									stack+=l[i];
									listView1->Items->Add(gcnew ListViewItem(gcnew array<String^>(4){no.ToString(),stack,tt,L"规约"}));
									break;
								}
							}*/
							stack=stack->Remove(from,stack->Length-from);
							//if ((stack[stack->Length-1]<='A')&&(stack[stack->Length-1]>='Z')) stack=stack->Remove(stack->Length-1);
							from=stack->Length-1;
							if ((from>0)&&(stack[from-1]>='A')&&(stack[from-1]<='Z')) from=from-1;
							stack+="N";
							if (stack->Length>1) listView1->Items->Add(gcnew ListViewItem(gcnew array<String^>(4){no.ToString(),stack,tt,L"规约"}));
							else 
							{
								listView1->Items->Add(gcnew ListViewItem(gcnew array<String^>(4){no.ToString(),stack,tt,L"接受"}));
								MessageBox::Show("分析成功。");
							}
						}
						else if (table[findvt(stack[o])][findvt(tt[0])]=='<') 
						{
							stack+=Char::ToString(tt[0]);
							tt=tt->Remove(0,1);
							from=stack->Length-1;
							if ((from>0)&&(stack[from-1]>='A')&&(stack[from-1]<='Z')) from=from-1;
							listView1->Items->Add(gcnew ListViewItem(gcnew array<String^>(4){no.ToString(),stack,tt,L"移进"}));
						}
						else if (table[findvt(stack[o])][findvt(tt[0])]=='=')
						{
							stack+=Char::ToString(tt[0]);
							tt=tt->Remove(0,1);
							listView1->Items->Add(gcnew ListViewItem(gcnew array<String^>(4){no.ToString(),stack,tt,L"移进"}));	

						}
						else 
						{
							MessageBox::Show("句子不符合算法优先文法。");
							return;
						}
					//}
					

				}

			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}

