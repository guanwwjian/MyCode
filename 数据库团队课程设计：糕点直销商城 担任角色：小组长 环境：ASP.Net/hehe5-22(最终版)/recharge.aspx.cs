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

public partial class _recharge : Mypage
{
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getuid() < 0) chfpage("login.aspx");
    }
    protected void btnAdd_Click(object sender, EventArgs e)
    {
        int uid1 = getuid();
        string sqltest = "select * from recharge where rcode='" + txtcode.Text + "'";
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
        SqlDataReader read = sqlcom.ExecuteReader();
        read.Read();
        if (read.HasRows == false)
        {
            Response.Write("<script language='javascript'>alert('充值卡不存在');location='recharge.aspx';</script>");
        }
        else
        {
            if (this.txtpassword.Text.Trim() != read["password"].ToString().Trim())
            {
                Response.Write("<script language='javascript'>alert('充值卡密码不正确');location='recharge.aspx';</script>");
            }
            else
            {
                int c = IsNumer(txtmoney.Text);
                if (c == 0)
                {
                    Response.Write("<script language='javascript'>alert('输入格式错误，充值金额只能为整数');location='recharge.aspx';</script>");
                }
                else
                {
                    int a = Int32.Parse(this.txtmoney.Text.Trim());
                    int b = Int32.Parse(read["money"].ToString().Trim());
                    if (a > b)
                    {
                        Response.Write("<script language='javascript'>alert('充值卡金额不够');location='recharge.aspx';</script>");
                    }
                    if ((this.txtcode.Text.Trim() == read["rcode"].ToString().Trim()) && (this.txtpassword.Text.Trim() == read["password"].ToString().Trim()) && (a <= b))
                    {
                        sqlconn.Close();
                        string sqlstr1 = "update users set money=money+'" + txtmoney.Text + "'where uid=" + uid1.ToString();
                        sqloperate.DataCom(sqlstr1);
                        if (a < b)
                        {
                            string sqlstr = "update recharge set money=money-'" + txtmoney.Text + "'where rcode='" + txtcode.Text + "'";
                            sqloperate.DataCom(sqlstr);
                        }
                        if (a == b)
                        {
                            string sqlstr = "delete from recharge where rcode='" + txtcode.Text + "'";
                            sqloperate.DataCom(sqlstr);
                        }
                        Response.Write("<script language='javascript'>alert('充值成功');location='recharge.aspx';</script>");
                    }
                }
            }
        }
    }
    protected void btnBack_Click(object sender, EventArgs e)
    {
        chfpage("onsales.aspx");
    }
    protected int IsNumer(string str)
    {
        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] < 48 || str[i] > 57) return 0;
        }
        return 1;
    }
}