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

public partial class AdminManage_MManage : Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        if (!IsPostBack)
        {
            string sqlstr = "select * from users";
            gvMemberInfo.DataKeyNames = new string[] { "uid" };
            sqloperate.gvDataBind(gvMemberInfo, sqlstr);
        }
    }
    protected void btnSel_Click(object sender, EventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        if (txtKey.Text == "")
        {
            string sqlstr = "select * from users";
            sqloperate.gvDataBind(gvMemberInfo, sqlstr);
        }
        else
        {
            string sqlstr = "select * from users where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
            sqlconn.Open();
            SqlCommand sqlcom = new SqlCommand(sqlstr, sqlconn);
            SqlDataReader read = sqlcom.ExecuteReader();
            read.Read();
            if (read.HasRows == false)
            {
                Response.Write("<script language='javascript'>alert('您所要查询的用户不存在');location='MManage.aspx';</script>");
                return;
            }
            else
            sqloperate.gvDataBind(gvMemberInfo, sqlstr);
        }
    }
    protected void gvMemberInfo_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        //if (e.Row.RowType == DataControlRowType.DataRow)
        //{
        //    ((Button)(e.Row.Cells[5].Controls[0])).Attributes.Add("onclick", "return confirm('确定要删除吗？')");
        //}
    }
    protected void gvMemberInfo_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        string sqlstr = "delete from users where uid='"+gvMemberInfo.DataKeys[e.RowIndex].Value+"'";
        sqloperate.DataCom(sqlstr);
        chbpage("MManage.aspx");
    }
    protected void gvMemberInfo_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvMemberInfo.PageIndex = e.NewPageIndex;
        string sqlstr = "select * from users where " + ddlCondition.SelectedValue + " like '%" + txtKey.Text.Trim() + "%'";
        sqloperate.gvDataBind(gvMemberInfo, sqlstr);
    }
    protected void ADD_Click(object sender, EventArgs e)
    {
        chbpage("EditMember.aspx");
    }
    protected void btnBanUser_Click(object sender, EventArgs e)
    {
        db = new Mydb();
        string connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        gvMemberInfo.DataKeyNames = new string[] { "uid" };
        //取当前行索引
        int row = ((GridViewRow)((Button)sender).NamingContainer).RowIndex;
        string uid = gvMemberInfo.Rows[row].Cells[0].Text.ToString().Trim();
        //string sql = "update users set ban='true' where uid='" + uid + "'";
        string sqlBanUser = "update users set ban='true' where uid='" + uid + "'";
        string sqlEnableUser = "update users set ban='false' where uid='" + uid + "'";
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        string strTemp = ((Button)sender).Text;
        if (strTemp=="禁用")
        {
            cmd.CommandText = sqlBanUser;
            int ivalue1 = cmd.ExecuteNonQuery();
            if (ivalue1 > 0)
            {
                Response.Write("<script language:javascript>javascript:window:alert('已禁用该用户');</script>");
                chbpage("MManage.aspx");
            }
            else
            {
                Response.Write("<script language:javascript>javascript:window:alert('禁用失败0.0');</script>");
            }
        }
        if (strTemp=="启用")
        {
            cmd.CommandText = sqlEnableUser;
            int ivalue2 = cmd.ExecuteNonQuery();
            if (ivalue2 > 0)
            {
                Response.Write("<script language:javascript>javascript:window:alert('已启用该用户');</script>");
                chbpage("MManage.aspx");
            }
            else
            {
                Response.Write("<script language:javascript>javascript:window:alert('启用失败0.0');</script>");
            }
        }
        //Button btn = ((Button)this.gvMemberInfo.Rows[row].FindControl("btnBanUser"));
        //btn.Text = "已禁用";
        //btn.Enabled = false;
        //Bind();
        //Response.Write("<script language:javascript>javascript:window:alert('" + uid + "');</script>");
        
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
    }
    protected void gvMemberInfo_RowEditing(object sender, GridViewEditEventArgs e)
    {
        gvMemberInfo.EditIndex = e.NewEditIndex; //编辑的行设置为鼠标作用的当前行
        //((TextBox)gvMemberInfo.Rows[e.NewEditIndex].Cells[0].Controls[0]).ReadOnly = true;
        //((TextBox)gvMemberInfo.Rows[e.NewEditIndex].Cells[1].Controls[e.NewEditIndex]).ReadOnly = true;
        //((TextBox)gvMemberInfo.Rows[e.NewEditIndex].Cells[3].Controls[e.NewEditIndex]).ReadOnly = true;
        Bind(); //进行绑定
    }

    protected void Bind()
    {
        db = new Mydb();
        string connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        string sql = "select * from users";
        SqlCommand cmd = new SqlCommand(sql, conn);
        SqlDataAdapter da = new SqlDataAdapter(sql, conn);
        DataSet ds = new DataSet();
        da.Fill(ds, "Users");
        this.gvMemberInfo.DataSource = ds.Tables["Users"].DefaultView;
        this.gvMemberInfo.DataBind();
    }
    protected void gvMemberInfo_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
    {
        gvMemberInfo.EditIndex = -1;
        Bind(); //最后还要重新绑定,否则还是呈现"更新"和"取消"
    }
    protected void gvMemberInfo_RowUpdating(object sender, GridViewUpdateEventArgs e)
    {
        int row = Convert.ToInt32(gvMemberInfo.DataKeys[e.RowIndex].Value);
        //((TextBox)gvMemberInfo.Rows[e.RowIndex].Cells[0].Controls[0]).Visible = false;
        
        string money = ((TextBox)(gvMemberInfo.Rows[e.RowIndex].Cells[2].Controls[0])).Text; //关键代码:取编辑框中产品名(改过后的名称),Rows[e.RowIndex].Cells[0].Controls[0]表示当前行,第一列(cell[0])第一个控件(control[0])
        //string ban = ((TextBox)(gvMemberInfo.Rows[e.RowIndex].Cells[2].Controls[0])).Text;
        
        foreach (char ch in money)
        {
            if (ch < '0' || ch > '9')
            {
                Response.Write("<script>alert('请输入合法数字0.0')</script>");
                return;
            }
        }
        db = new Mydb();
        string connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        string strSQL = "update users set money='" + money + "' where uid='" + row + "'";
        SqlCommand cmd = new SqlCommand(strSQL, conn);
        int h = cmd.ExecuteNonQuery();
        if (h > 0)
        {
            Response.Write("<script>alert('更新成功！')</script>");
            gvMemberInfo.EditIndex = -1; //一定要设置,否则还处于编辑状态
        }
        else
            Response.Write("<script>alert('更新失败！')</script>");
        Bind();
    }
    protected void gvMemberInfo_RowCommand(object sender, GridViewCommandEventArgs e)
    {
        //if (e.CommandName == "btnTest")
        //{
        //    Response.Write("<script>alert('当前行号为： + '"+e.CommandArgument+"'')</script>");
        //    //Response.Write("当前行号为：" + e.CommandArgument);
        //}
    }
}
