using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class adlogout : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        Response.Cookies["admininfo"].Expires=DateTime.Now.AddDays(-1);
        chbpage("adlogin.aspx");
    }
}