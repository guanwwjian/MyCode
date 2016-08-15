using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class myorders : Mypage
{
    string connStr;

    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
        connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();

        SqlCommand cmd = new SqlCommand();
        cmd = conn.CreateCommand();
        cmd.CommandText = "select * from orders join product on orders.pid=product.pid where uid='"+getuid().ToString()+"'";

        SqlDataAdapter ad = new SqlDataAdapter();
        ad.SelectCommand = cmd;

        DataSet ds = new DataSet();
        ad.Fill(ds,"table1");

        //DataTable dt = new DataTable();
        //dt = ds.Tables[0];

        //SqlCommand cmd2 = new SqlCommand();
        //cmd2 = conn.CreateCommand();
        //cmd2.CommandText = "select * from users";
        //SqlDataAdapter ad2 = new SqlDataAdapter();
        //ad2.SelectCommand = cmd2;
        //ad2.Fill(ds, "table2");

        //cmd.CommandText = "select * from users";
        //ad.SelectCommand = cmd;
        //ad.Fill(ds, "table2");
        

        //DataView dv = ds.Tables["table1"].DefaultView;
        this.DataList_Orders.DataSource = ds.Tables["table1"].DefaultView;
        this.DataList_Orders.DataBind();

        //this.DataList1.DataSource = ds.Tables["table2"].DefaultView;
        //this.DataList1.DataBind();
        //this.GridView2.DataSource = ds;
        //this.GridView2.DataBind();
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
    }
    protected void GridView2_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void DataList_Orders_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}