using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class adlogin : Mypage
{
    
    protected void Page_Load(object sender, EventArgs e)
    {
        int gt = getaid();
        if (gt > 0) Response.Redirect("addefault.aspx");
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
         if (Session["checkcode"].ToString() == TextBox3.Text)
        {
            db = new Mydb();
            db.Open();
            db.ExecuteReader("Select aid from admin where aname='" + st(TextBox1.Text) + "'and password='" + st(Method.MD5(TextBox2.Text)) + "'");
            if (db.rd.Read())
            {
                    int tt = db.rd.GetInt32(0);
                    Response.Cookies["admininfo"]["aid"] = tt.ToString();
                    //Response.Cookies["userinfo"].Expires = DateTime.Now.AddDays(1);
                    chbpage("addefault.aspx");
            }
            else Label3.Text = "密码错误或用户名不存在";
            db.Close();
        }
         else Label3.Text = "验证码错误！";
    }
    protected void Menu1_MenuItemClick(object sender, MenuEventArgs e)
    {

    }
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        ImageButton1.ImageUrl = "checkcode.aspx";
    }
}