using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Mypage : System.Web.UI.Page
{
    protected Mydb db;
    protected string st(string s)
    {
        return s;
    }
    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
    }
    protected int getuid()
    {
        if (Request.Cookies["userinfo"] != null) return Int32.Parse(Request.Cookies["userinfo"]["uid"]);
        else return -1;
    }
    protected int getaid()
    {
        if (Request.Cookies["admininfo"] != null) return Int32.Parse(Request.Cookies["admininfo"]["aid"]);
        else return -1;
    }
    protected void chfpage(string s)
    {
        Response.Write("<script>parent.location.href='index.aspx?page=" + s + "';</script>");
    }
    protected void chbpage(string s)
    {
        Response.Write("<script>parent.location.href='adindex.aspx?page=" + s + "';</script>");

    }

}