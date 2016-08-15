using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Web;
using System.Threading;
using System.IO;
using System.Net;

namespace MyIE
{
    public partial class Form1 : Form
    {
      /*  System.Windows.Forms.WebBrowser[] webNew = new WebBrowser();*/
        List<WebBrowser> webNew = new List<WebBrowser>();
        private String ur1;
        public Form1()
        {
            InitializeComponent();
            this.HomePage();//主页
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            try
            {
                webNew[tabControl1.SelectedIndex].Stop();//停止
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }
        }
        //输入网址，并执行过程
        private void toolStripButton9_Click(object sender, EventArgs e)
        {
            KeyEventArgs ev = new KeyEventArgs(Keys.Enter);
            toolcmbHype_KeyDown(sender, ev);
        }
        private void toolcmbHype_KeyDown(object sender, KeyEventArgs e)
        {
         try{
             if (e.KeyCode == Keys.Enter)
             {
                 this.ur1 = this.toolStripComboBox1.Text.Trim();
                 if (ur1.StartsWith("www.") || ur1.StartsWith("WWW."))
                     ur1 = "http://" + ur1 + @"/";
                 if (ur1.StartsWith("http://") || ur1.StartsWith("ftp://"))
                     this.toolStripComboBox1.Text = ur1;                
                 
                 
                 if (this.tabControl1.TabPages.Count == 0)
                 {
                     this.webNew.Add(new WebBrowser());
                     this.tabControl1.TabPages.Add("", "正在载入……", 0);
                     this.tabControl1.TabPages[0].Controls.Add(webNew[tabControl1.SelectedIndex]);
                     this.webNew[tabControl1.SelectedIndex].Navigated += new System.Windows.Forms.WebBrowserNavigatedEventHandler(this.webNew_Navigated);
                     this.webNew[tabControl1.SelectedIndex].NewWindow += new System.ComponentModel.CancelEventHandler(this.webNew_NewWindow);
                     this.webNew[tabControl1.SelectedIndex].ProgressChanged += new System.Windows.Forms.WebBrowserProgressChangedEventHandler(this.webNew_ProgressChanged);
                     this.webNew[tabControl1.SelectedIndex].Navigating += new System.Windows.Forms.WebBrowserNavigatingEventHandler(this.webNew_Navigating);
                     this.webNew[tabControl1.SelectedIndex].DocumentCompleted += new System.Windows.Forms.WebBrowserDocumentCompletedEventHandler(this.webNew_DocumentCompleted);
                 }
                 this.tabControl1.TabPages[tabControl1.SelectedIndex].Text ="正在载入……";
                 if(this.menuStrip1.Visible == true)
                 this.progressBar1.Visible = true;
                 webNew[tabControl1.SelectedIndex].Dock = DockStyle.Fill;
                 this.webNew[tabControl1.SelectedIndex].Navigate(ur1);
                 this.toolStripButton10.Enabled = true;
                 this.toolStripButton8.Enabled = true;

                 bool IsAdd = false;
                 for (int i = 0; i < toolStripComboBox1.Items.Count; i++)
                 {
                     if (this.ur1.Equals((String)toolStripComboBox1.Items[i]))
                     { IsAdd = true; break; }
                 }
                 if (!IsAdd)
                 {
                     toolStripComboBox1.Items.Add(this.ur1);
                 }
             }
        }
        catch (Exception ee) { MessageBox.Show(ee.Message); }
        }

        private void webNew_NewWindow(object sender, CancelEventArgs e)
        {
            try
            {
                e.Cancel = true;
                this.tabControl1.TabPages.Add("", "正在载入……", 0);
                this.tabControl1.SelectedIndex = this.tabControl1.TabPages.Count - 1;
                this.webNew.Add(new WebBrowser());
                this.tabControl1.TabPages[this.tabControl1.TabPages.Count - 1].Controls.Add(webNew[tabControl1.SelectedIndex]);
                webNew[tabControl1.SelectedIndex].Dock = DockStyle.Fill;
                if (this.menuStrip1.Visible == true)
                this.progressBar1.Visible = true;
                WebBrowser srcBrowser = (WebBrowser)sender;
                string newUrl = srcBrowser.StatusText;
                this.toolStripComboBox1.Text = newUrl;               
                webNew[tabControl1.SelectedIndex].Navigate(newUrl);
               // this.toolStripButton10.Enabled = true;
               // this.toolStripButton8.Enabled = true;
                this.webNew[tabControl1.SelectedIndex].Navigated += new System.Windows.Forms.WebBrowserNavigatedEventHandler(this.webNew_Navigated);
                this.webNew[tabControl1.SelectedIndex].NewWindow += new System.ComponentModel.CancelEventHandler(this.webNew_NewWindow);
                this.webNew[tabControl1.SelectedIndex].ProgressChanged += new System.Windows.Forms.WebBrowserProgressChangedEventHandler(this.webNew_ProgressChanged);
                this.webNew[tabControl1.SelectedIndex].Navigating += new System.Windows.Forms.WebBrowserNavigatingEventHandler(this.webNew_Navigating);
                this.webNew[tabControl1.SelectedIndex].DocumentCompleted += new System.Windows.Forms.WebBrowserDocumentCompletedEventHandler(this.webNew_DocumentCompleted);                
            
            }  
            catch (Exception ee) { MessageBox.Show(ee.Message); }
        }
        private void webNew_ProgressChanged(object sender, WebBrowserProgressChangedEventArgs e)
        {
            progressBar1.Maximum = (int)e.MaximumProgress;
            progressBar1.Value = (int)e.CurrentProgress;
        }
        private void webNew_Navigated(object sender, WebBrowserNavigatedEventArgs e)
        {

        }
        private void webNew_Navigating(object sender, WebBrowserNavigatingEventArgs e)
        {
            toolStripStatusLabel2.Text = e.Url.ToString();
        }
        private void Form1_Resize(object sender, EventArgs e)
        {
            this.toolStripComboBox1.Width = this.statusStrip1.Width - 200;
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            this.HomePage();
        }
        private void HomePage()
        {
            try
            {
                KeyEventArgs ev = new KeyEventArgs(Keys.Enter);
                object sender = new object();
                toolcmbHype_KeyDown(sender, ev);
                webNew[tabControl1.SelectedIndex].Navigate("http://www.baidu.com/");
                this.toolStripComboBox1.Text = "http://www.baidu.com/";
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }
        }
        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            try
            {
                webNew[tabControl1.SelectedIndex].Refresh();
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }
        }

        private void tabControl1_Click(object sender, EventArgs e)
        {
            this.toolStripComboBox1.Text = this.webNew[tabControl1.SelectedIndex].Url.ToString();
            string a = this.webNew[tabControl1.SelectedIndex].DocumentTitle + ("…………………………");
            this.tabControl1.TabPages[tabControl1.SelectedIndex].Text = a.Substring(0, 6);
            PanDuan();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            try
            {
                this.webNew[tabControl1.SelectedIndex].GoBack();
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            try
            {
                this.webNew[tabControl1.SelectedIndex].GoForward();
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }
        }

        private void toolStripButton8_Click(object sender, EventArgs e)
        {
            try
            {
                if (this.tabControl1.TabCount > 0)
                {
                    webNew.Clear();
                    tabControl1.TabPages.Clear();
                    this.toolStripComboBox1.Text = "";
                    this.toolStripButton1.Enabled = false;
                    this.toolStripButton2.Enabled = false;
                    this.向后BToolStripMenuItem.Enabled = false;
                    this.向前FToolStripMenuItem.Enabled = false;
                    this.toolStripButton10.Enabled = false;
                    this.toolStripButton8.Enabled = false;
                    this.toolStripStatusLabel2.Text = "";
                }
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }
            
        }

        private void toolStripButton10_Click(object sender, EventArgs e)
        {
            try
            {
                this.webNew[tabControl1.SelectedIndex].Dispose();
                this.webNew.Remove(this.webNew[tabControl1.SelectedIndex]);
                tabControl1.TabPages[tabControl1.SelectedIndex].Dispose();
                if (tabControl1.SelectedIndex >= 0)
                    PanDuan();
                else 
                {
                    this.toolStripComboBox1.Text = "";
                    this.toolStripStatusLabel2.Text = "";
                    this.toolStripButton1.Enabled = false;
                    this.向前FToolStripMenuItem.Enabled = false;
                    this.toolStripButton2.Enabled = false;
                    this.向后BToolStripMenuItem.Enabled = false;
                    this.toolStripButton10.Enabled = false;
                    this.toolStripButton8.Enabled = false;
                }
            }
            catch (Exception ee) { MessageBox.Show(ee.Message); }          
        }
        
        private void webNew_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {
            string a = this.webNew[tabControl1.SelectedIndex].DocumentTitle + ("……………………");
            this.tabControl1.TabPages[tabControl1.SelectedIndex].Text = a.Substring(0, 6);
            this.toolStripComboBox1.Text = this.webNew[tabControl1.SelectedIndex].Url.ToString();
            PanDuan();
            this.progressBar1.Visible = false;
       //   this.tabControl1.Size = new Size();
        }
        private void PanDuan()
        {
                if (this.webNew[tabControl1.SelectedIndex].CanGoBack)
            {
                this.toolStripButton1.Enabled = true;
                this.向前FToolStripMenuItem.Enabled = true;
            }
            else
            {
                this.toolStripButton1.Enabled = false;
                this.向前FToolStripMenuItem.Enabled = false;
            }
            if (this.webNew[tabControl1.SelectedIndex].CanGoForward)
            {
                this.toolStripButton2.Enabled = true;
                this.向后BToolStripMenuItem.Enabled = true;
            }
            else
            {
                this.toolStripButton2.Enabled = false;
                this.向后BToolStripMenuItem.Enabled = false;
            }
            
    }
        private void 关于MyIEToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutMyIE a = new AboutMyIE();
            a.Show();
        }

        private void 打开文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.openFileDialog1.ShowDialog();
            string StrFileName = this.openFileDialog1.FileName;

            try
            {
                this.webNew[tabControl1.SelectedIndex].Navigate(StrFileName);
            }
            catch (Exception Error)
            {
                MessageBox.Show(Error.Message);
            }
        }

        private void 新建ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.tabControl1.TabPages.Add("              ");
            this.webNew.Add(new WebBrowser());
            this.tabControl1.SelectedIndex = this.tabControl1.TabPages.Count - 1;
            this.tabControl1.TabPages[this.tabControl1.TabPages.Count - 1].Controls.Add(webNew[tabControl1.SelectedIndex]);
            webNew[tabControl1.SelectedIndex].Dock = DockStyle.Fill;            
            webNew[tabControl1.SelectedIndex].Navigate("");
            this.toolStripComboBox1.Text = "about:blank";
        }

        private void 打印预览ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.webNew[tabControl1.SelectedIndex].ShowPrintPreviewDialog();
        }

        private void 页面设置ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.webNew[tabControl1.SelectedIndex].ShowPageSetupDialog();
        }

        private void 打印PToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.webNew[tabControl1.SelectedIndex].ShowPrintDialog();
        }

        private void 添加到收藏夹ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 另存为sToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.webNew[tabControl1.SelectedIndex].ShowSaveAsDialog();
        }

        private void toolStripButton7_Click(object sender, EventArgs e)
        {
            this.webNew[tabControl1.SelectedIndex].ShowPrintDialog();
        }

        private void 关闭ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 工具栏ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.工具栏ToolStripMenuItem.Checked)
            {
                this.工具栏ToolStripMenuItem.Checked = false;
                this.toolStrip1.Hide();
            }
            else
            {
                this.工具栏ToolStripMenuItem.Checked = true;
                this.toolStrip1.Show();
            }
        }

        private void 状态栏ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.状态栏ToolStripMenuItem.Checked)
            {
                this.状态栏ToolStripMenuItem.Checked = false;
                this.statusStrip1.Hide();
            }
            else
            {
                this.状态栏ToolStripMenuItem.Checked = true;
                this.statusStrip1.Show();
            }
        }

        private void 页面源代码ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            HttpWebRequest oRequest = (HttpWebRequest)WebRequest.Create(webNew[tabControl1.SelectedIndex].Url);
            HttpWebResponse oResponse = (HttpWebResponse)oRequest.GetResponse();
            StreamReader sr = new StreamReader(oResponse.GetResponseStream(), System.Text.Encoding.GetEncoding("GB2312"));
            string sResultContents = sr.ReadToEnd();
            oResponse.Close();
            Form2 a = new Form2();
            a.xianshi(sResultContents);
            a.Show();
        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            this.webNew[tabControl1.SelectedIndex].Stop();
        }

        private void 查找ToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            this.toolStripButton5_Click(null,null);
        }

        private void 向后BToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.toolStripButton2_Click(null,null);
        }

        private void 向前FToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.toolStripButton1_Click(null,null);
        }

        private void tabControl1_Selected(object sender, TabControlEventArgs e)
        {

        }

        private void 属性ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            webNew[tabControl1.SelectedIndex].ShowPropertiesDialog();
        }

        private void 全屏显示FToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.TopMost = true;
            this.toolStrip1.Hide();
            this.menuStrip1.Hide();
            this.statusStrip1.Hide();
            this.FormBorderStyle = FormBorderStyle.None;
            this.WindowState = FormWindowState.Maximized;           
            this.toolStripButton11.Visible = true;
            this.progressBar1.Visible = false;
            this.toolStripComboBox1.Width = this.statusStrip1.Width - 200;
        }

        private void toolStripButton11_Click(object sender, EventArgs e)
        {
            this.FormBorderStyle = FormBorderStyle.Sizable;
            this.TopMost = false;
            this.toolStrip1.Show();
            this.menuStrip1.Show();
            this.statusStrip1.Show();
            this.toolStripButton11.Visible = false;            
        }

    }
}