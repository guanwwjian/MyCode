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

public partial class AdminManage_EditAdmin : Mypage
{
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    SqlOperate sqloperate = new SqlOperate();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
    }
    protected void btnAdd_Click(object sender, EventArgs e)
    {
        if (txtARank.Text != "1" && txtARank.Text != "2" && txtARank.Text != "3" && txtARank.Text != "4")
        {
            Response.Write("<script language='javascript'>alert('级别输入错误，用户级别只能为1,2,3,4这4个等级');location='EditAdmin.aspx';</script>");
            return;
        }
        else
        {
            int aid1 = getaid();
            string sqltest1 = "select * from admin where aid=" + aid1.ToString();
            sqlconn.Open();
            SqlCommand sqlcom1 = new SqlCommand(sqltest1, sqlconn);
            SqlDataReader read1 = sqlcom1.ExecuteReader();
            read1.Read();
            int a = Int32.Parse(read1["alevel"].ToString());
            if (a <= 3)
            {
                sqlconn.Close();
                string sqltest = "select * from admin where aname='" + st(txtAName.Text) + "'";
                sqlconn.Open();
                SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
                SqlDataReader read = sqlcom.ExecuteReader();
                read.Read();
                if (read.HasRows)
                {
                    if (this.txtAName.Text.Trim() == read["aname"].ToString().Trim())
                    {
                        Response.Write("<script language='javascript'>alert('该管理员已经存在');location='EditAdmin.aspx';</script>");
                        return;
                    }
                }
                if (Int32.Parse(this.txtARank.Text.Trim()) >= a)
                {
                    string sqlstr = "insert into admin(aname,password,alevel)"
                        + " values('" + st(txtAName.Text.Trim()) + "','" + st(Method.MD5( txtAPwd.Text.Trim())) + "','" + st(txtARank.Text.Trim()) + "')";
                    sqloperate.DataCom(sqlstr);
                    Response.Write("<script>alert('添加成功');location='AdminManage.aspx';</script>");
                }
                else
                {
                    Response.Write("<script>alert('不能添加比自己权限高的管理员');location='EditAdmin.aspx';</script>");
                }
            }
            else
            {
                Response.Write("<script>alert('您的权限不足已添加用户');location='AdminManage.aspx';</script>");
            }
        }
    }
    protected void btnEdit_Click(object sender, EventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        string sqltest1 = "select * from admin where aname='" + st(txtAName.Text) + "'";
        sqlconn.Open();
        SqlCommand sqlcom1 = new SqlCommand(sqltest1, sqlconn);
        SqlDataReader read1 = sqlcom1.ExecuteReader();
        read1.Read();
        if (read1.HasRows == false)
        {
            Response.Write("<script language='javascript'>alert('所要修改的管理员不存在');location='EditAdmin.aspx';</script>");
        }
        else
        {
            if (txtARank.Text != "1" && txtARank.Text != "2" && txtARank.Text != "3" && txtARank.Text != "4")
            {
                Response.Write("<script language='javascript'>alert('级别输入错误，用户级别只能为1,2,3,4这4个等级');location='EditAdmin.aspx';</script>");
                return;
            }
            else
            {
                int aid1 = getaid();
                sqlconn.Close();
                string sqltest = "select * from admin where aid=" + aid1.ToString();
                sqlconn.Open();
                SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
                SqlDataReader read = sqlcom.ExecuteReader();
                read.Read();
                if (Int32.Parse(read["alevel"].ToString()) == 1)
                {
                    string sqlstr = "update admin set password='" + st(Method.MD5( txtAPwd.Text.Trim())) + "',alevel='" + st(txtARank.Text.Trim()) + "'where aname='" + st(txtAName.Text) + "'";
                    sqloperate.DataCom(sqlstr);
                    Response.Write("<script>alert('修改成功');location='AdminManage.aspx';</script>");
                }
                if (Int32.Parse(read["alevel"].ToString()) == 2)
                {
                    string sqlstr = "update admin set password='" + st(Method.MD5( txtAPwd.Text.Trim())) + "'where aname='" + st(txtAName.Text) + "'";
                    sqloperate.DataCom(sqlstr);
                    Response.Write("<script>alert('您的权限因只能修改密码，不能修改级别，密码修改成功');location='AdminManage.aspx';</script>");
                }
                if (Int32.Parse(read["alevel"].ToString()) > 2)
                {
                    Response.Write("<script>alert('您的权限不能修改');location='EditAdmin.aspx';</script>");
                }
            }
        }
    }
    protected void btnBack_Click(object sender, EventArgs e)
    {
        chbpage("AdminManage.aspx");
    }
}
