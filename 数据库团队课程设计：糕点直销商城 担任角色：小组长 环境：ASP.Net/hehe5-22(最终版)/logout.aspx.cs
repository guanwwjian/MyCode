using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class logout : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        Response.Cookies["userinfo"].Expires=DateTime.Now.AddDays(-1);
        chfpage("onsales.aspx");
    }
}