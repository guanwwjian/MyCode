using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Drawing;
public partial class login : Mypage
{
    
    protected void Page_Load(object sender, EventArgs e)
    {
       
        int gt = getuid();
        if (gt > 0)// chfpage("onsales.aspx");
        {
            form1.Visible = false;
            form2.Visible = true;
        }
        else
        {
            form1.Visible = true;
            form2.Visible = false;
        }
        //把创建的位图保存到指定的路径
        //string st = Server.MapPath("safecode") + "\\RandomImg.gif";
        //newBitmap.Save(Server.MapPath("safecode") + "\\RandomImg.gif");
       // string tt = Response.ContentType;
        /*Response.ContentType = "Image/Gif";
        newBitmap.Save(Response.OutputStream, System.Drawing.Imaging.ImageFormat.Gif);
        Response.ContentType = tt;*/

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        if (Session["checkcode"].ToString() == checktxt.Text)
        {
            db = new Mydb();
            db.Open();
            db.ExecuteReader("Select ban,uid from users where uname='" + st(TextBox1.Text) + "'and password='" + st(Method.MD5(TextBox2.Text)) + "'");
            if (db.rd.Read())
            {
                if (db.rd.GetBoolean(0))
                {
                    Label3.Text = "账户被封请与管理员联系。";
                }
                else
                {
                    int tt = db.rd.GetInt32(1);
                    Response.Cookies["userinfo"]["uid"] = tt.ToString();
                    //Response.Cookies["userinfo"].Expires = DateTime.Now.AddDays(1);
                    chfpage("onsales.aspx");
                }
            }
            else Label3.Text = "密码错误或用户名不存在！";
            db.Close();
        }
        else Label3.Text = "验证码错误！";
       
    }
   
    protected void Menu1_MenuItemClick(object sender, MenuEventArgs e)
    {

    }
    protected void TextBox1_TextChanged(object sender, EventArgs e)
    {

    }
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        ImageButton1.ImageUrl = "checkcode.aspx";
    }


    protected void Button3_Click(object sender, EventArgs e)
    {

    }
}