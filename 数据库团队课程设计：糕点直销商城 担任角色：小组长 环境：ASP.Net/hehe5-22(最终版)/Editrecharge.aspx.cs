using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;

public partial class AdminManage_Editrecharge : Mypage
{
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
    }
    
    protected void btnBack_Click(object sender, EventArgs e)
    {
        chbpage("adrecharge.aspx");
    }
    protected Boolean IsNumer(string str)
    {
        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] < 48 || str[i] > 57) return false;
        }
        return true;
    }
    protected void btnAdd_Click(object sender, EventArgs e)
    {
        if (IsNumer(txtMoney.Text) && IsNumer(txtNum.Text))
        {
            int money = int.Parse(txtMoney.Text);
            int number = int.Parse(txtNum.Text);
            for (int x=0; x < number; x++)
            {
                sqlconn.Open();
                string sqlstr = "insert into recharge"
                        + "(rcode,password,money,enable) "
                        + "values('" + Method.getRandomNum(6,3) + "','" + Method.getRandomNum(6)
                        + "','" +money + "','True')";
                sqloperate.DataCom(sqlstr);
                Response.Write("<script>alert('添加成功');</script>");
                sqlconn.Close();
                chbpage("adrecharge.aspx");
            }
        }
        else
        {
            Response.Write("<script language='javascript'>alert('输入格式不正确，金额和数量只能为整数。');location='Editrecharge.aspx';</script>");
        }
    }
}
