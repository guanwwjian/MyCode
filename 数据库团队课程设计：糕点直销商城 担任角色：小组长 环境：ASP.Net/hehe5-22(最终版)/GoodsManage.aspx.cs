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

public partial class AdminManage_GoodsManage : Mypage
{
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        if (!IsPostBack)
        {
            string sqlstr = "select * from product";
            gvGoodsInfo.DataKeyNames = new string[] { "pid" };
            sqloperate.gvDataBind(gvGoodsInfo, sqlstr);
        }
    }
    protected void btnSel_Click(object sender, EventArgs e)
    {
        if (txtKey.Text == "")
        {
            string sqlstr = "select * from product";
            sqloperate.gvDataBind(gvGoodsInfo, sqlstr);
        }
        else
        {
            string sqlstr = "select * from product where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
            sqlconn.Open();
            SqlCommand sqlcom = new SqlCommand(sqlstr, sqlconn);
            SqlDataReader read = sqlcom.ExecuteReader();
            read.Read();
            if (read.HasRows == false)
            {
                Response.Write("<script language='javascript'>alert('您所要查询的商品不存在');location='GoodsManage.aspx';</script>");
                return;
            }
            else
            sqloperate.gvDataBind(gvGoodsInfo, sqlstr);
        }
    }
    protected void gvGoodsInfo_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {
            ((Button)(e.Row.Cells[6].Controls[0])).Attributes.Add("onclick", "return confirm('确定要删除吗？')");
        }
    }
    protected void gvGoodsInfo_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        string sqlstr = "delete from product where pid='" + gvGoodsInfo.DataKeys[e.RowIndex].Value + "'";
        sqloperate.DataCom(sqlstr);
        Response.Redirect("GoodsManage.aspx");
    }
    protected void gvGoodsInfo_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvGoodsInfo.PageIndex = e.NewPageIndex;
        string sqlstr = "select * from product where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
        sqloperate.gvDataBind(gvGoodsInfo, sqlstr);
    }
     protected void ADD_Click(object sender, EventArgs e)
    {
        chbpage("EditGoods.aspx");
    }
     protected void btnChangeDetails_OnClick(object sender, EventArgs e)
     {
         int row = ((GridViewRow)((Button)sender).NamingContainer).RowIndex;
         db = new Mydb();
         SqlConnection conn = new SqlConnection(db.getconnstr());
         conn.Open();
         SqlCommand cmd = new SqlCommand();
         cmd = conn.CreateCommand();
         gvGoodsInfo.DataKeyNames = new string[] { "pid" };
         int strTemp = int.Parse(gvGoodsInfo.Rows[row].Cells[0].Text.Trim());
         chbpage("EditGoods.aspx?pid="+strTemp.ToString());

     }
}
