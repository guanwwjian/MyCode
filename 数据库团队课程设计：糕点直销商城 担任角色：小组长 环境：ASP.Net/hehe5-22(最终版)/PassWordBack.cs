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


public partial class PassWordBack : Mypage
{




    protected void Page_Load(object sender, EventArgs e)
    {
        //if (getuid() < 0) chfpage("login.aspx");
        db = new Mydb();
    }
    //protected void subbtn_Click(object sender, EventArgs e)
    //{

    //    string unametxt = this.unametxt.Text;//用户名 
    //    string sfcdtxt = this.sfcdtxt.Text;//安全码
    //    string newpwdtxt = this.newpwdtxt.Text;//新密码框
    //    string cnewpwdtxt = this.cnewpwdtxt.Text;//确认新密码框
       
    //    string strCon = db.getconnstr();//"Integrated Security=SSPI;Initial Catalog='hehedata';Data Source='SUSON-PC\\SQLEXPRESS';User ID='sa';Password='12345';Connect Timeout=30";
    //    SqlConnection Conn = new SqlConnection(strCon);
        
        
    //        Conn.Open();
    //        string sql = "select count(*) from users where  uname='" + unametxt + "'";
    //        SqlCommand cmd = new SqlCommand(sql, Conn);

    //        if (unametxt == "")
    //        {
    //            Label.Text = "用户名不能为空!";
    //        }
    //        cmd.CommandText = "select count(*) from users where uname='" + unametxt + "'";
    //        int count2 = (int)cmd.ExecuteScalar();
    //        if (count2 == 0)
    //        {
    //            Label.Text = "用户名不存在!";
    //            return;
    //        }
    //        if (sfcdtxt == "")
    //        {
    //            Label.Text = "安全码不能为空!";

    //            return;
    //        }
        

    //   // Conn.Open();

    //    cmd.CommandText = "select count(*) from users where safecode ='" + Method.MD5(sfcdtxt) + "'and uname='" + unametxt + "'";
    //  int  count3 = (int)cmd.ExecuteScalar();
    //  Conn.Close();
    //    if (count3 == 0)
    //    {
    //        Label.Text = "安全码错误!";
    //        return;
    //    }
        
    //    if (newpwdtxt != cnewpwdtxt)
    //    {
    //        Label.Text = "两次输入的密码不一致!";
           
    //        return;
    //    }
    //    if (newpwdtxt.Length < 3)

    //        Label.Text = "密码不能少于三位！";
    //    if (Session["checkcode"].ToString() != checktxt.Text)
    //    {
    //        Label.Text = "验证码错误！";
    //    }
    //    else
    //    {

    //        cmd.CommandText = "update users set password='" + Method.MD5(newpwdtxt) + "' where uname='" + unametxt + "'";
    //        Conn.Open();
    //        int count4 = cmd.ExecuteNonQuery();
    //        Conn.Close();
    //        if (count4 > 0)
    //        {
    //            this.Response.Write("<script>alert('密码修改成功！')</script>");
    //        }
    //        else
    //        {
    //            this.Response.Write("<script>alert('密码修改失败！')</script>");
    //        }

    //    }
           
            

    //}
    //protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    //{
    //    ImageButton1.ImageUrl = "checkcode.aspx";
    //}

    //邮箱找回
    protected void emailbtn_Click(object sender, EventArgs e)
    {
        string unametxt = this.unametxt.Text;//用户名 
        string strCon = db.getconnstr();//"Integrated Security=SSPI;Initial Catalog='hehedata';Data Source='SUSON-PC\\SQLEXPRESS';User ID='sa';Password='12345';Connect Timeout=30";
        SqlConnection Conn = new SqlConnection(strCon);
        Conn.Open();
        string sql = "select count(*) from users where  uname='" + unametxt + "'";
        SqlCommand cmd = new SqlCommand(sql, Conn);

        if (unametxt == "")
        {
            Label.Text = "用户名不能为空！";
            return;
        }
        cmd.CommandText = "select count(*) from users where uname='" + unametxt + "'";
        int count2 = (int)cmd.ExecuteScalar();
        if (count2 == 0)
        {
            Label.Text = "用户名不存在!";
            return;
        }
        if (emailtxt.Text == "")
        {
            Label.Text = "邮箱不能为空!";
            return;
        }
        cmd.CommandText = "select count(*) from users where email='" + emailtxt.Text + "' and uname='" + unametxt + "'";
        int count5 = (int)cmd.ExecuteScalar();
        if (count5 == 0)
        {
             Label.Text ="邮箱不正确!";
            return;
        }
        if (Session["checkcode"].ToString() != checktxt.Text)
        {
            Label.Text = "验证码不正确！";
            return;
        }
       
        String pwd = Method.getRandomNum();
        String message;
        //try
        //{
            Method.FindPassword(emailtxt.Text, unametxt, pwd, out message);
            Response.Write("<script>alert('邮件已发至您的邮箱，请注意查收!')</script>");
            chfpage("onsales.aspx");
        //}
        //catch
        //{
        //    return;
        //}
    }
     protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        ImageButton1.ImageUrl = "checkcode.aspx";
    }
}
