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

public partial class Editadjustment:Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    protected void Page_Load(object sender, EventArgs e)
    {

        if (getaid()< 0) chbpage("adlogin.aspx");
        if (!IsPostBack)
        {
            if (Request.Params["advid"] != null)
            {
                sqlconn.Open();
                txtname.Text = Request["advid"].ToString();
                string sqlstr = "select * from advertisement where advid='" + Request["advid"].ToString() + "'";
                SqlDataAdapter myApter = new SqlDataAdapter(sqlstr, sqlconn);
                DataSet myDS = new DataSet();
                myApter.Fill(myDS, "advertisement");
                DataRowView rowView = myDS.Tables["advertisement"].DefaultView[0];
                txtname.Text = Convert.ToString(rowView["advname"]);
                txturl.Text = Convert.ToString(rowView["advurl"]);
                txtwidth.Text = Convert.ToString(rowView["width"]);
                txtheight.Text = Convert.ToString(rowView["height"]);
                txtx.Text = Convert.ToString(rowView["x"]);
                txty.Text = Convert.ToString(rowView["y"]);
                sqlconn.Close();
            }
        }
    }
    protected void btnAdd_Click(object sender, EventArgs e)
    {
        string sqltest = "select * from advertisement where advname='" + txtname.Text + "'";
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
        SqlDataReader read = sqlcom.ExecuteReader();
        read.Read();
        if (read.HasRows)
        {
            if (this.txtname.Text.Trim() == read["advname"].ToString().Trim())
            {
                Response.Write("<script language='javascript'>alert('该广告已经存在');localtion='EditMember.aspx'</script>");
                return;
            }
        }
        else
        {
            string sqlstr = "insert into advertisement(advname,advurl,width,height,x,y)"
                + " values('" + txtname.Text.Trim() + "','" + txturl.Text.Trim() + "','" + txtwidth.Text.Trim() + "','" + txtheight.Text.Trim() + "','" + txtx.Text.Trim() + "','" + txty.Text.Trim() + "')";
            sqloperate.DataCom(sqlstr);
            Response.Write("<script>alert('添加成功');location='Editadjustment.aspx';</script>");
        }
    }
    protected void btnModify_Click(object sender, EventArgs e)
    {
        string sqltest = "select * from advertisement where advname='" + txtname.Text + "'";
        sqlconn.Open();
        SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
        SqlDataReader read = sqlcom.ExecuteReader();
        read.Read();
        if (read.HasRows==false)
        {
            Response.Write("<script language='javascript'>alert('所要修改的广告不存在');localtion='Editadjustment.aspx'</script>");
        }
        if (read.HasRows)
        {
            string sqlstr = "update advertisement set advurl='" + txturl.Text
                 + "',width='" + txtwidth.Text + "',height='" + txtheight.Text + "',x='" + txtx.Text + "',y='" + txty.Text + "' where advid = '" + txtname.Text + "'";
            sqloperate.DataCom(sqlstr);
            Response.Write("<script lanuage=javascript>alert('修改成功');location='Editadjustment.aspx'</script>");
        }
    }
    protected void btnCancel_Click(object sender, EventArgs e)
    {
        chbpage("adadjustmentmanage.aspx");
    }
}
