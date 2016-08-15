using System;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// SqlOperate 的摘要说明
/// </summary>
public class SqlOperate
{
    public SqlOperate()
    {
        //
        // TODO: 在此处添加构造函数逻辑
        //
    }
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    public void DataCom(string sqlstr)
    {
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqlstr,sqlconn);
        sqlcom.ExecuteNonQuery();
        sqlconn.Close();
    }
    public void gvDataBind(GridView gv, string sqlstr)
    {
        sqlconn.Open();
        SqlDataAdapter myda = new SqlDataAdapter(sqlstr, sqlconn);
        DataSet myds = new DataSet();
        myda.Fill(myds);
        gv.DataSource = myds;
        gv.DataBind();
        sqlconn.Close();
    }
    public void dlDataBind(DataList dl, string sqlstr)
    {
        sqlconn.Open();
        SqlDataAdapter myda = new SqlDataAdapter(sqlstr, sqlconn);
        DataSet myds = new DataSet();
        myda.Fill(myds);
        dl.DataSource = myds;
        dl.DataBind();
        sqlconn.Close();
    }
    public void ddlDataBind(DropDownList ddl, string sqlstr, string dvf1, string dvf2)
    {
        sqlconn.Open();
        SqlDataAdapter myda = new SqlDataAdapter(sqlstr, sqlconn);
        DataSet myds = new DataSet();
        myda.Fill(myds);
        ddl.DataSource = myds;
        ddl.DataTextField = dvf1;
        ddl.DataValueField = dvf2.ToString();
        ddl.DataBind();
        sqlconn.Close();
    }
        public void ddlDataBind(DropDownList ddl, string sqlstr, string dvf1)
    {
        sqlconn.Open();
        SqlDataAdapter myda = new SqlDataAdapter(sqlstr, sqlconn);
        DataSet myds = new DataSet();
        myda.Fill(myds);
        ddl.DataSource = myds;
        ddl.DataTextField = dvf1;
        ddl.DataBind();
        sqlconn.Close();
    }
}
