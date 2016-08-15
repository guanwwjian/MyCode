using System;
using System.Data;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Text;

public partial class index : Mypage
{
    public string GetUrl()
    {
        if (Request.QueryString["page"] != null)
        {
            return Request.QueryString["page"];
        }
        else
        {
            return "onsales.aspx";
        }

    }
 

    protected void Page_Load(object sender, EventArgs e)
    {
        if (getuid() < 0)
        {
            login.Attributes.Add("src", "login.aspx");
        }
        else
        {
            login.Attributes.Add("src", "UserInfo.aspx");

        }
        //Response.Write("<SCRIPT LANGUAGE=\"VBScript\">\r<!--\rCreateObject(\"SAPI.SpVoice\").Speak \"成了\"\r-->\r</SCRIPT>");

    }
}