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
        public void xianshi(string doc)
        {
            this.richTextBox1.Text = doc;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
       
    }
}