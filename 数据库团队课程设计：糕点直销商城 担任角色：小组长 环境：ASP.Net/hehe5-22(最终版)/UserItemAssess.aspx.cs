using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

public partial class UserItemAssess : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
        if (!IsPostBack)
        {
            if (Request.QueryString["oid"] != null)
            {
                string oid = Request.QueryString["oid"];
                string connStr = db.getconnstr();//连接数据库字符串
                SqlConnection conn = new SqlConnection(connStr);//conn
                conn.Open();
                string sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计,evalution as 评价,grade as 评分 from orders join product on orders.pid=product.pid where oid='" + oid + "'";
                SqlCommand cmd = new SqlCommand(sql, conn);
                SqlDataAdapter da = new SqlDataAdapter(sql, conn);
                DataSet ds = new DataSet();
                da.Fill(ds, "UserItemAssess");

                dlUserItemAssess.DataSource = ds.Tables["UserItemAssess"].DefaultView;
                dlUserItemAssess.DataBind();
                if (conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
            }
        }
        //BindDataList();
    }
    private void BindDataList()
    {
        //if (!IsPostBack)
        //{
        string oid = Request.QueryString["oid"];
        db = new Mydb();
        string connStr = db.getconnstr();//连接数据库字符串
        SqlConnection conn = new SqlConnection(connStr);//conn
        conn.Open();
        //执行的sql语句
        string sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计,evalution as 评价,grade as 评分 from orders join product on orders.pid=product.pid where oid='" + oid + "'";
        SqlCommand cmd = new SqlCommand(sql, conn);//cmd
        SqlDataAdapter ad = new SqlDataAdapter(sql, conn);//ad
        DataSet ds = new DataSet();//ds
        ad.Fill(ds, "table1");
        //this.dlShoppingCart.DataSource = ds.Tables["table1"].DefaultView;
        //this.dlShoppingCart.DataBind();

        this.dlUserItemAssess.DataSource = ds.Tables["table1"].DefaultView;
        this.dlUserItemAssess.DataKeyField = "订单编号";
        this.dlUserItemAssess.DataBind();
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
        //}
    }
    protected void dlUserItemAssess_ItemCommand(object source, DataListCommandEventArgs e)
    {
        if (e.CommandName == "linktoProduct")
        {
            int pid1 = Int32.Parse(((Label)e.Item.FindControl("lblPid")).Text.Trim());
            //int pid1 = Int32.Parse(dlShoppingCart.DataKeys[e.Item.ItemIndex].ToString());
            chfpage("product.aspx?pid=" + pid1.ToString());
        }
        if (e.CommandName == "imgbtnLinktoProduct")
        {
            int pid1 = Int32.Parse(((Label)e.Item.FindControl("lblPid")).Text.Trim());
            chfpage("product.aspx?pid=" + pid1.ToString());
        }
        if(e.CommandName=="btnAssess")
        {
            
            db = new Mydb();
            string connStr = db.getconnstr();//连接数据库字符串
            SqlConnection conn = new SqlConnection(connStr);//conn
            conn.Open();
            //取得评价语句
            string evalution = ((TextBox)e.Item.FindControl("tbUserItemAssess")).Text.Trim().ToString();
            evalution = evalution.Replace('\n', ' ');
            evalution = evalution.Replace('\r', ' ');
            if (evalution == "")
            {
                Response.Write("<script>alert('评价不能为空0.0')</script>");
                return;
                
            }
            //sql语句
            string sql = "update orders set evalution='"+evalution+"' ,status=4 where oid= '"+Request.QueryString["oid"]+"'";
            SqlCommand cmd = new SqlCommand(sql, conn);
            if (cmd.ExecuteNonQuery() > 0)
            {
                if (conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
                Response.Write("<script>alert('评价成功！')</script>");
                chfpage("orderlist.aspx");
            }
            else
            {
                if (conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
                Response.Write("<script>alert('评价失败,请重试0.0')</script>");
            }
        }
    }
}