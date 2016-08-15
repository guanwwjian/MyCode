using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Data.Sql;

public partial class assess1 : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
    }

    protected void subbtn_Click(object sender, EventArgs e)
    {
        if (assesstxt.Text == "")
        {
            alertlbl.Text = "评价不能为空！";
            return;
        }

        string strCon = db.getconnstr();// "Integrated Security=SSPI;Initial Catalog='hehedata';Data Source='SUSON-PC\\SQLEXPRESS';User ID='sa';Password='12345';Connect Timeout=30";
        SqlConnection Conn= new SqlConnection(strCon);
        Conn.Open();
        //string sql1 = "select evalution from orders where oid=10000 and evalution is null";
        string sql = "select evalution from orders where oid=' "+Request.QueryString["oid"]+"' and evalution is null";
        SqlCommand cmd = new SqlCommand(sql, Conn);
        

        SqlDataReader rd = cmd.ExecuteReader();
        if (getaid() < 0)
        {
            this.Response.Write("<script>alert('您还未登录!');location.href='index.aspx?page=login.aspx';</script>");
            

        }
        else 
            if (!rd.Read())
                {
            alertlbl.Text = "您已经提交过评价！";
            return;
                }
            else
        {
           
            Conn.Open();
           
            cmd.CommandText = "update orders set evalution='" + assesstxt.Text + "'";
            int count = (int)cmd.ExecuteNonQuery();
            Conn.Close();
            if (count != 0)
            {
                alertlbl.Text = "评价成功！";
               Response.Redirect("orders.aspx");
            }
            else
            {
                alertlbl.Text = "评价失败！请重新输入。";
                
                Response.Redirect("assess1.aspx");
            }


        }
        Conn.Close();
    }
}