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

public partial class _AdminManage : Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        if (!IsPostBack)
        {
            string sqlstr = "select * from admin";
            gvAdminInfo.DataKeyNames = new string[] { "aid" };
            sqloperate.gvDataBind(gvAdminInfo, sqlstr);
        }
    }
    protected void btnSel_Click(object sender, EventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        if (txtKey.Text == "")
        {
            string sqlstr = "select * from admin";
            sqloperate.gvDataBind(gvAdminInfo, sqlstr);
        }
        else
        {
            string sqlstr = "select * from admin where "
                + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
            sqlconn.Open();
            SqlCommand sqlcom = new SqlCommand(sqlstr, sqlconn);
            SqlDataReader read = sqlcom.ExecuteReader();
            read.Read();
            if (read.HasRows == false)
            {
                Response.Write("<script language='javascript'>alert('您所要查询的管理员不存在');location='AdminManage.aspx';</script>");
                return;
            }
            else
            sqloperate.gvDataBind(gvAdminInfo, sqlstr);
        }
    }
    protected void gvAdminInfo_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        //if (e.Row.RowType == DataControlRowType.DataRow)
        //{
        //    ((Button)(e.Row.Cells[5].Controls[0])).Attributes.Add("onclick", "return confirm('确定要删除吗？')");
        //}
    }
    protected void gvAdminInfo_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        int aid1 = getaid();
        string sqltest = "select alevel from admin where aid="+ aid1.ToString();
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
        SqlDataReader read = sqlcom.ExecuteReader();
        read.Read();
        if (Int32.Parse(read["alevel"].ToString()) <= 2)
        {
            string sqlstr = "delete from admin where aid='"
                + gvAdminInfo.DataKeys[e.RowIndex].Value + "'";
            sqloperate.DataCom(sqlstr);
            Response.Write("<script language:javascript>javascript:window:alert('删除成功^^');</script>");
            chbpage("AdminManage.aspx");
        }
        else
        {
            Response.Write("<script language='javascript'>alert('您当前的权限不足0.0');location='AdminManage.aspx';</script>");
            return;
        }
    }
    protected void gvAdminInfo_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvAdminInfo.PageIndex = e.NewPageIndex;
        string sqlstr = "select * from admin where "
                + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
        sqloperate.gvDataBind(gvAdminInfo, sqlstr);
    }
    protected void ADD_Click(object sender, EventArgs e)
    {
        chbpage("AddAdmin.aspx");
    }
    protected void gvAdminInfo_RowEditing(object sender, GridViewEditEventArgs e)
    {
        gvAdminInfo.EditIndex = e.NewEditIndex;
        Bind();
    }
    protected void Bind()
    {
        db = new Mydb();
        string connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        string sql = "select * from admin";
        SqlCommand cmd = new SqlCommand(sql, conn);
        SqlDataAdapter da = new SqlDataAdapter(sql, conn);
        DataSet ds = new DataSet();
        da.Fill(ds, "Admin");
        this.gvAdminInfo.DataSource = ds.Tables["Admin"].DefaultView;
        this.gvAdminInfo.DataBind();
    }
    protected void gvAdminInfo_RowUpdating(object sender, GridViewUpdateEventArgs e)
    {
        int row = Convert.ToInt32(gvAdminInfo.DataKeys[e.RowIndex].Value);
        string aname = ((TextBox)(gvAdminInfo.Rows[e.RowIndex].Cells[1].Controls[0])).Text;
        string  password= ((TextBox)(gvAdminInfo.Rows[e.RowIndex].Cells[2].Controls[0])).Text;
        string  alevel= ((TextBox)(gvAdminInfo.Rows[e.RowIndex].Cells[3].Controls[0])).Text.Trim();
        //if (alevel.Length != 1)
        //{
        //    Response.Write("<script>alert('输入的级别不合法,只能为1~4')</script>");
        //    return;
        //}

        //if (int.Parse(alevel) != 1 || int.Parse(alevel) != 2 || int.Parse(alevel) != 3 || int.Parse(alevel) != 4)
        //{
        //    Response.Write("<script>alert('输入的级别不合法,只能为1~4')</script>");
        //    return;
        //}
        db = new Mydb();
        string connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        string strSQL = "update admin set aname='" + aname + "' ,password='"+password+"' ,alevel='"+alevel+"' where aid='" + row + "'";
        SqlCommand cmd = new SqlCommand(strSQL, conn);
        int h = cmd.ExecuteNonQuery();
        if (h > 0)
        {
            Response.Write("<script>alert('更新成功！')</script>");
            gvAdminInfo.EditIndex = -1; //一定要设置,否则还处于编辑状态
        }
        else
            Response.Write("<script>alert('更新失败！')</script>");
        Bind();
    }
    protected void gvAdminInfo_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
    {
        gvAdminInfo.EditIndex = -1;
        Bind(); //最后还要重新绑定,否则还是呈现"更新"和"取消"
    }
}
