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
public partial class adadjustmentmanage : Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        string sqlstr = "select * from advertisement";
        gvMemberInfo.DataKeyNames = new string[] { "advid" };
        sqloperate.gvDataBind(gvMemberInfo, sqlstr);
    }
    protected void btnSel_Click(object sender, EventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        if (txtKey.Text == "")
        {
            string sqlstr = "select * from advertisement";
            sqloperate.gvDataBind(gvMemberInfo, sqlstr);
        }
        else
        {
            string sqlstr = "select * from advertisement where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
            sqlconn.Open();
            SqlCommand sqlcom = new SqlCommand(sqlstr, sqlconn);
            SqlDataReader read = sqlcom.ExecuteReader();
            read.Read();
            if (read.HasRows == false)
            {
                Response.Write("<script language='javascript'>alert('您所要查询的广告不存在');localtion='Editadjustment.aspx'</script>");
                return;
            }
            else
                sqloperate.gvDataBind(gvMemberInfo, sqlstr);
        }
    }
    protected void gvMemberInfo_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {
            ((LinkButton)(e.Row.Cells[7].Controls[0])).Attributes.Add("onclick", "return confirm('确定要删除吗？')");
        }
    }
    protected void gvMemberInfo_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        string sqlstr = "delete from advertisement where advid='" + gvMemberInfo.DataKeys[e.RowIndex].Value + "'";
        sqloperate.DataCom(sqlstr);
        chbpage("adadjustmentmanage.aspx");
    }
    protected void gvMemberInfo_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvMemberInfo.PageIndex = e.NewPageIndex;
        string sqlstr = "select * from advertisement where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
        sqloperate.gvDataBind(gvMemberInfo, sqlstr);
    }
    protected void ADD_Click(object sender, EventArgs e)
    {
        chbpage("Editadjustment.aspx");
    }
}