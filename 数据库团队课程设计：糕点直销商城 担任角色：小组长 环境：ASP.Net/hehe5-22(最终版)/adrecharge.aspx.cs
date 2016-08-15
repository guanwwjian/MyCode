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

public partial class AdminManage_adrecharge : Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        if (!IsPostBack)
        {
            string sqlstr = "select * from recharge";
            gvAdminInfo.DataKeyNames = new string[] { "rid" };
            sqloperate.gvDataBind(gvAdminInfo, sqlstr);
        }
    }
    protected void btnSel_Click(object sender, EventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        if (txtKey.Text == "")
        {
            string sqlstr = "select * from recharge";
            sqloperate.gvDataBind(gvAdminInfo, sqlstr);
        }
        else
        {
            string sqlstr = "select * from recharge where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
            sqlconn.Open();
            SqlCommand sqlcom = new SqlCommand(sqlstr, sqlconn);
            SqlDataReader read = sqlcom.ExecuteReader();
            read.Read();
            if (read.HasRows == false)
            {
                Response.Write("<script language='javascript'>alert('您所要查询的充值卡不存在');location='adrecharge.aspx';</script>");
                return;
            }
            else
            sqloperate.gvDataBind(gvAdminInfo, sqlstr);
        }
    }
    protected void gvAdminInfo_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {
            ((LinkButton)(e.Row.Cells[4].Controls[0])).Attributes.Add("onclick", "return confirm('确定要删除吗？')");
        }
    }
    protected void gvAdminInfo_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        string sqlstr = "delete from recharge where rid='"
            + gvAdminInfo.DataKeys[e.RowIndex].Value + "'";
        sqloperate.DataCom(sqlstr);
        Response.Redirect("adrecharge.aspx");
    }
    protected void gvAdminInfo_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvAdminInfo.PageIndex = e.NewPageIndex;
        string sqlstr = "select * from recharge where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
        sqloperate.gvDataBind(gvAdminInfo, sqlstr);
    }
    protected void ADD_Click(object sender, EventArgs e)
    {
        chbpage("Editrecharge.aspx");
    }
}
