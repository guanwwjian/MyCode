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

public partial class register : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
    }
    protected void subbtn_Click(object sender, EventArgs e)
    {
        
        string strCon = db.getconnstr();
        SqlConnection Conn = new SqlConnection(strCon);
        Conn.Open();
        string sql = "select count(*) from users where  uname='" + unametxt.Text + "'";
        SqlCommand cmd = new SqlCommand(sql, Conn);

        int count1 = (int)cmd.ExecuteScalar();
        Conn.Close();
        if (count1 >0)
        {
            this.Response.Write("<script>alert('用户名已存在!请重新输入。');</script>");
            return;
        }
        if (unametxt.Text == "")
        {
            this.Response.Write("<script>alert('用户名不能为空！');</script>");
            return;
        }
        if (sfcdtxt.Text == "")
        {
            this.Response.Write("<script>alert('安全码不能为空！');</script>");
            return;
        }
        if (cfsfcdtxt.Text != sfcdtxt.Text)
        {
            this.Response.Write("<script>alert('两次安全码输入不一致！');</script>");
            return;
        }
        if (pwdtxt.Text == "")
        {
            this.Response.Write("<script>alert('密码不能为空！');</script>");
            return;
        }
        if (cfpwdtxt.Text != pwdtxt.Text)
       
            this.Response.Write("<script>alert('两次密码输入不一致！');</script>");

         else
            if (Session["checkcode"].ToString() == checktxt.Text)
            {
                Conn.Open();
                cmd.CommandText = ("insert into users ( uname,password,safecode,email)values ('" + unametxt.Text + "','" + Method.MD5(pwdtxt.Text) + "','" + Method.MD5(sfcdtxt.Text )+"','"+emailtxt.Text+ "')");
                int count2 = (int)cmd.ExecuteNonQuery();
                Conn.Close();
                if (count2 > 0)
                {
                    this.Response.Write("<script>alert('注册成功！');</script>");
                    chfpage("onsales.aspx");
                }
                else
                {
                    this.Response.Write("<script>alert('注册失败！');</script>");
                };
            }
            else this.Response.Write("<script>alert('验证码错误！');</script>");
    }
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        ImageButton1.ImageUrl = "checkcode.aspx";
    }
    
}