using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Configuration;

public partial class shoppingcart : Mypage
{
    //string connStr ;
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            db = new Mydb();
            string connStr = db.getconnstr();//连接数据库字符串
            SqlConnection conn = new SqlConnection(connStr);//conn
            conn.Open();
            //执行的sql语句
            string sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status=0";
            SqlCommand cmd = new SqlCommand(sql, conn);//cmd
            SqlDataAdapter ad = new SqlDataAdapter(sql, conn);//ad
            DataSet ds = new DataSet();//ds
            ad.Fill(ds, "table1");
            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }
            //购物车为空 转至 商品列表
            if (ds.Tables["table1"] == null || ds.Tables["table1"].Rows.Count == 0)
            {
                Button1.Visible = true;//显示 转至商品列表按钮
                Button2.Visible = false;//隐藏支付按钮
                this.lblNoneShoppinglist.Visible = true;
                this.lblNoneShoppinglist.Text = "您还没有选购任何商品！";
                this.lblNoneShoppinglist.ForeColor = Color.Red;
                this.lblCount.Text = "0";
                lnkbtnFirst.Enabled = false;
                lnkbtnFront.Enabled = false;
                lnkbtnLast.Enabled = false;
                lnkbtnNext.Enabled = false;
                return;
            }
            //显示购物车中的商品
            else
            {
                BindDataList();
                this.lblNoneShoppinglist.Visible = false;
            }
        }
    }
    protected void Button1_Click(object sender, EventArgs e)//跳转至商品列表页面
    {
        //Response.Write("<script>window.alert('恭喜，购物车更新成功！);window.location=PlaceAnOrder.aspx;</script>");
        Response.Redirect("productlist.aspx");
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Response.Redirect("PlaceAnOrder.aspx");
    }


    protected void dlShoppingCart_ItemCommand(object source, DataListCommandEventArgs e)
    {
        db = new Mydb();
        string connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);

        if (e.CommandName == "linktoProduct")
        {
            int pid1 = Int32.Parse(((Label)e.Item.FindControl("lblPid")).Text.Trim());
            //int pid1 = Int32.Parse(dlShoppingCart.DataKeys[e.Item.ItemIndex].ToString());
            chfpage("product.aspx?pid=" + pid1.ToString());
        }
        if (e.CommandName == "btnDelete")
        {
            int oid = int.Parse(dlShoppingCart.DataKeys[e.Item.ItemIndex].ToString());
            string strDelete = "delete from orders where oid='" + oid + "'";
            conn.Open();
            SqlCommand cmd = new SqlCommand(strDelete, conn);
            if (Convert.ToInt32(cmd.ExecuteNonQuery()) > 0)
            {
                BindDataList();
                Response.Write("<script>alert('删除成功！')</script>");
                chfpage("shoppingcart.aspx");
                //Response.Redirect("shoppingcart.aspx");
            }
            else
            {
                Response.Write("<script>alert('删除失败！')</script>");
            }
            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }
        }
        if (e.CommandName == "imgbtnLinktoProduct")
        {
            int pid1 = Int32.Parse(((Label)e.Item.FindControl("lblPid")).Text.Trim());
            chfpage("product.aspx?pid=" + pid1.ToString());
        }
    }
    //函数 绑定datalist
    private void BindDataList()
    {
        //if (!IsPostBack)
       //{
            db = new Mydb();
            string connStr = db.getconnstr();//连接数据库字符串
            SqlConnection conn = new SqlConnection(connStr);//conn
            conn.Open();
            //执行的sql语句
            string sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status=0";
            SqlCommand cmd = new SqlCommand(sql, conn);//cmd
            SqlDataAdapter ad = new SqlDataAdapter(sql, conn);//ad
            DataSet ds = new DataSet();//ds
            ad.Fill(ds, "table1");
            //this.dlShoppingCart.DataSource = ds.Tables["table1"].DefaultView;
            //this.dlShoppingCart.DataBind();
            //if (ds.Tables["table1"].Rows.Count == 0)
            //{
            //    this.lblCount.Text = "0";
            //    lnkbtnFirst.Enabled = false;
            //    lnkbtnFront.Enabled = false;
            //    lnkbtnLast.Enabled = false;
            //    lnkbtnNext.Enabled = false;
            //    return;
            //}

            int CurrentPage = Convert.ToInt32(lblNowPage.Text);
            PagedDataSource objPds = new PagedDataSource();
            objPds.DataSource = ds.Tables["table1"].DefaultView;
            objPds.AllowPaging = true;
            objPds.PageSize = 5;
            objPds.CurrentPageIndex = CurrentPage - 1;
            lnkbtnFirst.Enabled = true;
            lnkbtnFront.Enabled = true;
            lnkbtnLast.Enabled = true;
            lnkbtnNext.Enabled = true;
            if (CurrentPage == 1)
            {
                lnkbtnFirst.Enabled = false;
                lnkbtnFront.Enabled = false;
            }
            if (CurrentPage == objPds.PageCount)
            {
                lnkbtnLast.Enabled = false;
                lnkbtnNext.Enabled = false;
            }
            this.lblCount.Text = Convert.ToString(objPds.PageCount);
            this.dlShoppingCart.DataSource = objPds;
            this.dlShoppingCart.DataKeyField = "订单编号";
            this.dlShoppingCart.DataBind();
            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }
        //}
    }
    protected void dlShoppingCart_DeleteCommand(object source, DataListCommandEventArgs e)
    {
        
    }
    protected void lnkbtnFirst_Click(object sender, EventArgs e)
    {
        this.lblNowPage.Text = "1";
        this.BindDataList();
    }
    protected void lnkbtnFront_Click(object sender, EventArgs e)
    {
        this.lblNowPage.Text = Convert.ToString(Convert.ToInt32(this.lblNowPage.Text) - 1);
        this.BindDataList();
    }
    protected void lnkbtnNext_Click(object sender, EventArgs e)
    {
        this.lblNowPage.Text = Convert.ToString(Convert.ToInt32(this.lblNowPage.Text) + 1);
        this.BindDataList();
    }
    protected void lnkbtnLast_Click(object sender, EventArgs e)
    {
        this.lblNowPage.Text = this.lblCount.Text;
        this.BindDataList();
    }
}