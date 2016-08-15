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

public partial class PassWordChange : Mypage
{




    protected void Page_Load(object sender, EventArgs e)
    {
        if (getuid() < 0) chfpage("login.aspx");
        db = new Mydb();
    }
    protected void subbtn_Click(object sender, EventArgs e)
    {
       
       
        string oldpwdtxt = this.oldpwdtxt.Text;//原密码
        string newpwdtxt = this.newpwdtxt.Text;//新密码框
        string cnewpwdtxt = this.cnewpwdtxt.Text;//确认新密码框
       
        string strCon = db.getconnstr();//"Integrated Security=SSPI;Initial Catalog='hehedata';Data Source='SUSON-PC\\SQLEXPRESS';User ID='sa';Password='12345';Connect Timeout=30";
        SqlConnection Conn = new SqlConnection(strCon);
        Conn.Open();
        string sql = "select count(*) from users where  uid='" + getuid().ToString() + "'";
        SqlCommand cmd = new SqlCommand(sql,Conn);
       
        
        if (oldpwdtxt == "")
        {
            this.Response.Write("<script>alert('原密码不能为空!');</script>");

            return;
        }
       
        cmd.CommandText = "select count(*) from users where password ='" + Method.MD5(oldpwdtxt) + "'and uid='" + getuid().ToString() + "'";
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

            cmd.CommandText = "update users set password='" + Method.MD5(newpwdtxt) + "' where uid= '" + getuid().ToString() + "'";
           Conn.Open();
            int count3 = cmd.ExecuteNonQuery();
           Conn.Close();
            if (count3 > 0)
            {
                this.Response.Write("<script>alert('密码修改成功！')</script>");
                chfpage("onsales.aspx");

            }
            else
            {
                this.Response.Write("<script>alert('密码修改失败！')</script>");
            }
           

        }


    }

    
}
