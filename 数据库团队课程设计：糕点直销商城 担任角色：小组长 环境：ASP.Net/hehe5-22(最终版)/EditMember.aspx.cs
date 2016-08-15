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

public partial class AdminManage_EditMember : Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
    }
    protected void btnAdd_Click(object sender, EventArgs e)
    {
        string sqltest = "select * from users where uname='" + txtLoginName.Text + "'";
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
        SqlDataReader read = sqlcom.ExecuteReader();
        read.Read();
        if (read.HasRows)
        {
            if (this.txtLoginName.Text.Trim() == read["uname"].ToString().Trim())
            {
                Response.Write("<script language='javascript'>alert('该用户已经存在');location='EditMember.aspx';</script>");
                return;
            }
        }
        else
        {
            int b = IsNumer(txtMoney.Text);
            if (b == 0)
            {
                Response.Write("<script language='javascript'>alert('输入格式错误，会员余额只能为整数');location='EditMember.aspx'</script>");
            }
            else
            {
                string sqlstr = "insert into users(uname,password,safecode,money)"
                    + " values('" + txtLoginName.Text.Trim() + "','" + txtPwd.Text.Trim() + "','" + txtQuePwd.Text.Trim() + "','" + txtMoney.Text.Trim() + "')";
                sqloperate.DataCom(sqlstr);
                Response.Write("<script>alert('添加成功');location='MManage.aspx';</script>");
            }
        }
    }
    protected void btnModify_Click(object sender, EventArgs e)
    {
        string sqltest = "select * from users where uname='" + txtLoginName.Text + "'";
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
        SqlDataReader read = sqlcom.ExecuteReader();
        read.Read();
        if (read.HasRows == false)
        {
            Response.Write("<script language='javascript'>alert('所要修改的会员不存在');location='EditMember.aspx';</script>");
        }
        if (read.HasRows)
        {
            int b = IsNumer(txtMoney.Text);
            if (b == 0)
            {
                Response.Write("<script language='javascript'>alert('输入格式错误，会员余额只能为整数');location='EditMember.aspx';</script>");
            }
            else
            {
                string sqlstr = "update users set password='" + txtPwd.Text
                     + "',safecode='" + txtQuePwd.Text + "',money='" + txtMoney.Text + "' where uname = '" + txtLoginName.Text + "'";
                sqloperate.DataCom(sqlstr);
                Response.Write("<script lanuage=javascript>alert('修改成功');location='MManage.aspx';</script>");
            }
        }
    }
    protected void btnCancel_Click(object sender, EventArgs e)
    {
        chbpage("MManage.aspx");
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
