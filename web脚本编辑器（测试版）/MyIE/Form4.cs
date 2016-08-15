using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
namespace MyIE

{
    struct opretor
    {
        public int ty, id, wt,no,d,h,m,s;
        public string url, name, txt;
    }
    struct nm
    {
        public int n, m;
        public Form1 f1;
    }
    public partial class Form4 : Form
    {
        Form1 f1;
        HtmlDocument doc;
        HtmlElement[] ele;
        ArrayList op=new ArrayList();
        WebBrowser wb;
        int no = 0;
        int lastindex = -1;
        bool wait=false;
        public Form4(Form1 f)
        {
            InitializeComponent();
            f1 = f;
        }
        private string rq(string s)
        {
            return s.Remove(s.LastIndexOf("?"));
        }
        private void menumain_Click(object sender, EventArgs e)
        {
            f1.Visible = (!f1.Visible);
        }
         
        private void Form4_Load(object sender, EventArgs e)
        {
            uplist();
            Control.CheckForIllegalCrossThreadCalls = false;
            bgw2.RunWorkerAsync();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.Text = listBox1.SelectedItem.ToString();
            txturl.Text = wb.Url.ToString();
            numericUpDown9.Value = listBox1.SelectedIndex;
            numericUpDown5.Value = 0;
            numericUpDown6.Value = 0;
            numericUpDown7.Value = 0;
            numericUpDown8.Value = 0;
            if ((doc.All[listBox1.SelectedIndex].TagName.ToLower().Equals("a")) && (doc.All[listBox1.SelectedIndex].OuterHtml.ToLower().Contains("href=")))
            {
                comboBox1.SelectedIndex = 4;
            }
            else if (doc.All[listBox1.SelectedIndex].TagName.ToLower().Equals("input") && (doc.All[listBox1.SelectedIndex].OuterHtml.ToLower().Contains("type=submit")))
            {
                comboBox1.SelectedIndex = 3;
            }
            else if (doc.All[listBox1.SelectedIndex].TagName.ToLower().Equals("input"))
            {
                comboBox1.SelectedIndex = 2;
            }
            else
            {
                comboBox1.SelectedIndex = 0;
            }
        }
        private void waitstart(object sender, EventArgs e)
        {
            wait = true;
        }
        private void waitend(object sender, EventArgs e)
        {
            wait = false;
        }
        public void uplist()
        {
            if (wb != null)
            { 
                wb.Navigating -= waitstart;
                wb.Navigated -= waitend;
            }
            wb = f1.webNew[f1.tabControl1.SelectedIndex];
            wb.Navigating += waitstart;
            wb.Navigated += waitend;
            doc = wb.Document;
            txturl.Text = wb.Url.ToString();
            ele=new HtmlElement[doc.All.Count];
            listBox1.Items.Clear();
            for (int i = 0; i < doc.All.Count; i++)
            {
                ele[i] = doc.All[i];
                listBox1.Items.Add("id=" + i.ToString() + "|TagName=" + doc.All[i].TagName + "|Name=" + doc.All[i].Name + "|InnerHtml=" + doc.All[i].InnerHtml + "|OutterHtml=" + doc.All[i].OuterHtml + "|Innertext=" + doc.All[i].InnerText + "|Outtertext=" + doc.All[i].OuterText);
                
            }
            comboBox1.SelectedIndex = 0;
        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }
        private void add()
        {
            int id = (int)numericUpDown9.Value;
            opretor tt = new opretor();

            int d = (int)numericUpDown5.Value, h = (int)numericUpDown6.Value, m = (int)numericUpDown7.Value, s = (int)numericUpDown8.Value, t;
            
            t = d;
            t = t * 24 + h;
            t = t * 60 + m;
            t = t * 60 + s;
            tt.no = no;
            tt.d = d;
            tt.h = h;
            tt.m = m;
            tt.s = s;
            tt.wt = t;
            tt.id = id;
            tt.ty = comboBox1.SelectedIndex;
            tt.name = doc.All[id].Name;
            tt.url = txturl.Text;
            tt.txt = textBox3.Text;
            op.Add(tt);
            switch (comboBox1.SelectedIndex)
            {
                
                case 0:
                    checkedListBox1.Items.Add(no.ToString()+"|操作类型=" + comboBox1.SelectedItem.ToString() + "|等待时间="+d+"天"+h+"时"+m+"分"+s+"秒|共计"+t+"秒" ,true);
                    break;
                case 1:
                    checkedListBox1.Items.Add(no.ToString() + "|操作类型=" + comboBox1.SelectedItem.ToString() + "|跳转目标=" + textBox3.Text + "|等待时间=" + d + "天" + h + "时" + m + "分" + s + "秒|共计" + t + "秒", true);
                    break;
                case 2:
                    checkedListBox1.Items.Add(no.ToString() + "|操作类型=" + comboBox1.SelectedItem.ToString() + "|地址=" + txturl.Text + "|对象id=" + id.ToString() + "|名称=" + doc.All[id].Name + "|内容=" + textBox3.Text + "|等待时间=" + d + "天" + h + "时" + m + "分" + s + "秒|共计" + t + "秒", true);
                    break;
                case 3:
                    checkedListBox1.Items.Add(no.ToString() + "|操作类型=" + comboBox1.SelectedItem.ToString() + "|地址=" + txturl.Text + "|对象id=" + id.ToString() + "|名称=" + doc.All[id].Name + "|等待时间=" + d + "天" + h + "时" + m + "分" + s + "秒|共计" + t + "秒", true);
                    break;
                case 4:
                    checkedListBox1.Items.Add(no.ToString() + "|操作类型=" + comboBox1.SelectedItem.ToString() + "|地址=" + txturl.Text + "|对象id=" + id.ToString() + "|名称=" + doc.All[id].Name + "|等待时间=" + d + "天" + h + "时" + m + "分" + s + "秒|共计" + t + "秒", true);
                    break;
            }
            no++;
        }

        private void Form4_FormClosing(object sender, FormClosingEventArgs e)
        {
            f1.Visible = true;
            e.Cancel = false;
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int n = checkedListBox1.SelectedIndex;
            if (n >= 0)
            {
                textBox1.Text = checkedListBox1.Items[n].ToString();
                comboBox1.SelectedIndex = ((opretor)op[n]).ty;
                if (((opretor)op[n]).ty >= 2)
                {
                    numericUpDown9.Value = ((opretor)op[n]).id;
                    numericUpDown5.Value = ((opretor)op[n]).d;
                    numericUpDown6.Value = ((opretor)op[n]).h;
                    numericUpDown7.Value = ((opretor)op[n]).m;
                    numericUpDown8.Value = ((opretor)op[n]).s;
                    txturl.Text = ((opretor)op[n]).url;
                }
            }
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_DoubleClick(object sender, EventArgs e)
        {
            add();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int n=checkedListBox1.SelectedIndex;
            
            if (n > 0)
            {
                checkedListBox1.SelectedIndex =n-1;
                object obt;
                object opt;
                obt = checkedListBox1.Items[n]; checkedListBox1.Items[n] = checkedListBox1.Items[n - 1]; checkedListBox1.Items[n - 1] = obt;
                opt = op[n]; op[n] = op[n - 1]; op[n - 1] = opt;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int n = checkedListBox1.SelectedIndex;
            
            if (n < checkedListBox1.Items.Count-1)
            {
                checkedListBox1.SelectedIndex = n + 1;
                object obt;
                object opt;
                obt = checkedListBox1.Items[n]; checkedListBox1.Items[n] = checkedListBox1.Items[n + 1]; checkedListBox1.Items[n + 1] = obt;
                opt = op[n]; op[n] = op[n + 1]; op[n + 1] = opt;
            }
        }

       
        private void button2_Click(object sender, EventArgs e)
        {
             int m = checkedListBox1.SelectedIndex;
            /* object obt;
             object opt;
             obt = checkedListBox1.Items[m];
             opt = op[m];
             for (int i = m+1; i < n; i++)
             {
                 checkedListBox1.Items[i - 1] = checkedListBox1.Items[i];
                 op[i - 1] = op[i];
             }
             checkedListBox1.Items.Remove(checkedListBox1.Items[n]);
             op.Remove(op[n]);*/
             if ((m >= 0)&&(m<checkedListBox1.Items.Count))
             {
                 checkedListBox1.Items.Remove(checkedListBox1.Items[m]);
                 op.Remove(op[m]);
                 if (checkedListBox1.Items.Count > m) checkedListBox1.SelectedIndex = m;
                 else checkedListBox1.SelectedIndex = checkedListBox1.Items.Count - 1;
             }
        }

        private void button1_Click(object sender, EventArgs e)
        {
                add();
                int n = checkedListBox1.Items.Count-1,m=checkedListBox1.SelectedIndex;
                if (m >= 0)
                {
                    object obt;
                    object opt;
                    obt = checkedListBox1.Items[n];
                    opt = op[n];
                    for (int i = n - 1; i >= m; i--)
                    {
                        checkedListBox1.Items[i + 1] = checkedListBox1.Items[i];
                        op[i + 1] = op[i];
                    }
                    checkedListBox1.Items[m] = obt;
                    op[m] = opt;
                    checkedListBox1.SelectedIndex++;
                }
                
            
        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            add();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 1) { label18.Text = "跳转目标"; label18.Visible = true; textBox3.Visible = true; }
            else if (comboBox1.SelectedIndex == 2) { label18.Text = "填写内容"; label18.Visible = true; textBox3.Visible = true; }
            else { label18.Visible = false; textBox3.Visible = false; }
        }

        private void button6_Click(object sender, EventArgs e) 
        {
            
            if (!bgw.IsBusy)
            {
                if (op.Count > 0)
                {
                    int t, d = (int)numericUpDown1.Value, h = (int)numericUpDown2.Value, m = (int)numericUpDown3.Value, s = (int)numericUpDown4.Value;
                    t = d;
                    t = t * 24 + h;
                    t = t * 60 + m;
                    t = t * 60 + s;
                    if (t > 0)
                    {
                        int rest;
                        nm tt = new nm();
                        if (checkBox1.Checked) rest = -1;
                        else rest = (int)numericUpDown10.Value;
                        tt.m = t * 1000;
                        tt.n = rest;
                        tt.f1 = f1;
                        button6.Text = "停止执行";
                        bgw.RunWorkerAsync(tt);

                    }
                }
            }
            else { bgw.CancelAsync(); button6.Text = "开始执行"; }
        }
        private int checkwait()
        {
            int w = 0;
            while (wait) { Thread.Sleep(1); w++; }
            return w;
        }
        private void running(int n,int m,Form1 f1)
        {
            /*WebBrowser wb;
            HtmlDocument doc;
            wb = f1.webNew[f1.tabControl1.SelectedIndex];
            doc = wb.Document;*/
            int rest = n;
            while ((rest > 0) || (rest == -1))
            {
                if (rest > 0) { toolStripStatusLabel1.Text = "还剩" + rest + "遍要执行"; ;rest--; }
                else if (rest == -1) toolStripStatusLabel1.Text = "无重复执行次数限制";
                for (int i = 0; i < checkedListBox1.Items.Count; i++)
                {
                    checkedListBox1.SelectedIndex = i;
                    if (checkedListBox1.GetItemChecked(i))
                    {
                        int w = 0;
                       // bool b = wb.IsBusy;
                        switch (((opretor)op[i]).ty)
                        {
                            case 0:
                                break;
                            case 1:
                                wb.Navigate(((opretor)op[i]).txt);
                                break;
                            case 2:
                               // while (wb.IsBusy) { Thread.Sleep(1); w++; }
                                w += checkwait();
                                if (!wb.Url.ToString().ToLower().Equals(((opretor)op[i]).url.ToLower()))
                                { wb.Navigate(((opretor)op[i]).url); }
                               //while (wb.IsBusy) { Thread.Sleep(1);w++;}
                                w += checkwait();
                                doc.All[((opretor)op[i]).id].InnerText = ((opretor)op[i]).txt;
                                break;
                            case 3:
                               // while (wb.IsBusy) { Thread.Sleep(1); w++; }
                                w += checkwait();
                                if (!wb.Url.ToString().ToLower().Equals(((opretor)op[i]).url.ToLower()))
                                { wb.Navigate(((opretor)op[i]).url);}
                                //while (wb.IsBusy) { Thread.Sleep(1); w++; }
                                w += checkwait();
                                doc.All[((opretor)op[i]).id].InvokeMember("click");
                                break;
                            case 4:
                                //while (wb.IsBusy) { Thread.Sleep(1); w++; }
                                w += checkwait();
                                if (!wb.Url.ToString().ToLower().Equals(((opretor)op[i]).url.ToLower()))
                                { wb.Navigate(((opretor)op[i]).url);}
                                //while (wb.IsBusy) { Thread.Sleep(1); w++; }
                                w += checkwait();
                                doc.All[((opretor)op[i]).id].InvokeMember("click");
                                break;
                        }
                        if (((opretor)op[i]).wt * 1000-w>0 )  Thread.Sleep(((opretor)op[i]).wt * 1000);
                    }
                }
                if (rest == 0) { toolStripStatusLabel1.Text = "执行完毕"; button6.Text = "开始执行"; checkedListBox1.SelectedIndex = -1; }
                else Thread.Sleep(m * 1000);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            numericUpDown10.ReadOnly = checkBox1.Checked;
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            
        }


        private void bgw_DoWork(object sender, DoWorkEventArgs e)
        {
            running(((nm)e.Argument).n, ((nm)e.Argument).m, ((nm)e.Argument).f1);
        }

        private void bgw2_DoWork(object sender, DoWorkEventArgs e)
        {
                   }
        private void serch()
        {
            string s = textBox2.Text;
            if (s != "")
            {
                int i;
                if (listBox1.SelectedIndex >= 0)
                {
                    for (i = 1; (i < listBox1.Items.Count) && (!listBox1.Items[(listBox1.SelectedIndex + i) % listBox1.Items.Count].ToString().Contains(s)); i++) { }
                    listBox1.SelectedIndex = (listBox1.SelectedIndex + i) % listBox1.Items.Count;
                }
                else
                {
                    for (i = 0; i < listBox1.Items.Count; i++)
                    {
                        if (listBox1.Items[i].ToString().Contains(s))
                        {
                            listBox1.SelectedIndex = i;
                            break;
                        }
                    }
                }
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r')
            {
                serch();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            serch();
        }



       
    }
}
