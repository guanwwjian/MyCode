using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MyIE
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        public void xianshi(string doc,string doc1)
        {
            this.richTextBox1.Text = doc;
            this.richTextBox2.Text = doc1;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
       
    }
}