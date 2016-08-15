using System;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;
using System.Data;
using System.Data.Sql;
using System.Security.Cryptography;

public partial class AdchangePassword : Mypage
{




    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        db = new Mydb();
    }
    protected void subbtn_Click(object sender, EventArgs e)
    {
       
        string anametxt = this.anametxt.Text;//管理员名
        string oldpwdtxt = this.oldpwdtxt.Text;//原密码
        string newpwdtxt = this.newpwdtxt.Text;//新密码框
        string cnewpwdtxt = this.cnewpwdtxt.Text;//确认新密码框
       /* if (anametxt == "")
        {
            this.Response.Write("<script>alert('用户名不能为空!');</script>");
            return;
        }*/
        string strCon = db.getconnstr();// "Integrated Security=SSPI;Initial Catalog='hehedata';Data Source='SUSON-PC\\SQLEXPRESS';User ID='sa';Password='12345';Connect Timeout=30";
        SqlConnection Conn = new SqlConnection(strCon);
        Conn.Open();
        string sql = "select count(*) from admin where  aid='" + getaid().ToString()+ "'";
        SqlCommand cmd = new SqlCommand(sql,Conn);
       
        int count1 = (int)cmd.ExecuteScalar();
        Conn.Close();
        if (count1 == 0)
        {
            this.Response.Write("<script>alert('该管理员不存在!');</script>");
            return;
        }
        if (oldpwdtxt == "")
        {
            this.Response.Write("<script>alert('原密码不能为空!');</script>");

            return;
        }
       
        Conn.Open();
        cmd.CommandText = "select count(*) from admin where password ='" + oldpwdtxt + "'and aid='" + getaid().ToString() + "'";
      int  count2 = (int)cmd.ExecuteScalar();
      Conn.Close();
        if (count2 == 0)
        {
            this.Response.Write("<script>alert('原密码错误!');</script>");
            return;
        }
        if (newpwdtxt == oldpwdtxt)
        {
            this.Response.Write("<script>alert('新密码与原密码一致了!');</script>");

            return;
        }
        
        if (newpwdtxt != cnewpwdtxt)
        {
            this.Response.Write("<script>alert('两次输入的密码不一致!');</script>");

            return;
        }
        if (newpwdtxt.Length < 3)
       
            this.Response.Write("<script>alert('密码不能少于三位！')</script>");
            
        
        else
        {
            
           Conn.Open();
           cmd.CommandText = "update admin set password='" + newpwdtxt + "' where aid='" + getaid().ToString() + "'";
            int count3 = cmd.ExecuteNonQuery();
           Conn.Close();
            if (count3 > 0)
            {
                this.Response.Write("<script>alert('密码修改成功！')</script>");
            }
            else
            {
                this.Response.Write("<script>alert('密码修改失败！')</script>");
            }
           

        }


    }
}
