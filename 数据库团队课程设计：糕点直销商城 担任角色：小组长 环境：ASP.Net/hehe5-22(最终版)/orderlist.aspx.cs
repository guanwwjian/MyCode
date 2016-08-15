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

public partial class UserCenter_orderlist : Mypage
{
    DataTable dt2 = new DataTable();
    DataSet ds = new DataSet();

    private void BindDataList()
    {
        db = new Mydb();
        string connStr = db.getconnstr();//连接数据库字符串
        SqlConnection conn = new SqlConnection(connStr);//conn
        conn.Open();
        String sql;
        //执行的sql语句
        SqlCommand cmd;
        SqlDataAdapter ad;
        if(String.IsNullOrEmpty(Request.QueryString["status"]))
        {
        sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计,status as 状态 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "'";
        }
        else
        {
            this.DropDownList1.SelectedIndex = int.Parse(Request.QueryString["status"]) + 1;
            sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计,status as 状态 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status='" + Request.QueryString["status"] + "'";
        }
        cmd = new SqlCommand(sql, conn);//cmd
        ad = new SqlDataAdapter(sql, conn);//ad
        ad.Fill(ds, "table0");
        dt2.Columns.Add("订单编号");
        dt2.Columns.Add("产品编号");
        dt2.Columns.Add("产品名称");
        dt2.Columns.Add("产品图片");
        dt2.Columns.Add("单价");
        dt2.Columns.Add("数量");
        dt2.Columns.Add("小计");
        dt2.Columns.Add("订单状态");
        dt2.Columns.Add("按钮");
        dt2.Columns.Add("可用");

        if (ds.Tables["table0"]!=null&&ds.Tables["table0"].Rows.Count != 0)
        {
            for (int x = 0; x < ds.Tables["table0"].Rows.Count; x++)
            {
                DataRow item = dt2.NewRow();
                item[0] = ds.Tables["table0"].Rows[x][0];
                item[1] = ds.Tables["table0"].Rows[x][1];
                item[2] = ds.Tables["table0"].Rows[x][2];
                item[3] = ds.Tables["table0"].Rows[x][3];
                item[4] = ds.Tables["table0"].Rows[x][4];
                item[5] = ds.Tables["table0"].Rows[x][5];
                item[6] = ds.Tables["table0"].Rows[x][6];
                item["订单状态"] = Method.orderstatus[int.Parse(ds.Tables["table0"].Rows[x]["状态"].ToString())];
                item["按钮"] = Method.orderStatusChangeOperations[int.Parse(ds.Tables["table0"].Rows[x]["状态"].ToString())];
                item["可用"] = (int.Parse(ds.Tables["table0"].Rows[x]["状态"].ToString()) == 1 || int.Parse(ds.Tables["table0"].Rows[x]["状态"].ToString()) == 2);
                dt2.Rows.Add(item);
            }

        }
        int CurrentPage = Convert.ToInt32(lblNowPage.Text);
        PagedDataSource objPds = new PagedDataSource();
        objPds.DataSource = dt2.DefaultView;
        objPds.AllowPaging = true;
        objPds.PageSize = 5;
        objPds.CurrentPageIndex = CurrentPage - 1;
        lnkbtnFirst.Enabled = true;
        lnkbtnFront.Enabled = true;
        lnkbtnLast.Enabled = true;
        lnkbtnNext.Enabled = true;
        //DropDownList1.Enabled = true;
        //btnSelectRecords.Enabled = true;
        //lblUserInput.Enabled = true;
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
        //}
    }
    private int getStatus(int oid)
    {
        db = new Mydb();
        string connStr = db.getconnstr();//连接数据库字符串
        SqlConnection conn = new SqlConnection(connStr);//conn
        conn.Open();
        //执行的sql语句
        string sql;
        SqlCommand cmd;
        SqlDataAdapter ad;
        sql = "select status as 状态 from orders where oid='" + oid + "'";
        cmd = new SqlCommand(sql, conn);//cmd
        ad = new SqlDataAdapter(sql, conn);//ad
        ad.Fill(ds, "table0");
        return int.Parse(ds.Tables[0].Rows[0][0].ToString());
    }
    protected void Page_Load(object sender, EventArgs e)
    {

        if (!IsPostBack)
        {
            ListItem item = new ListItem("全部", "全部");
            this.DropDownList1.Items.Add(item);
            this.DropDownList1.SelectedIndex = 1;
            for (int x = 0; x < Method.orderstatus.Count(); x++)
            {
                item = new ListItem(Method.orderstatus[x], x.ToString());
                this.DropDownList1.Items.Add(item);
            }
            //DataSet ds = new DataSet();
            DataSet ds = new DataSet();
            db = new Mydb();
            string connStr = db.getconnstr();//连接数据库字符串
            SqlConnection conn = new SqlConnection(connStr);//conn
            conn.Open();
            //执行的sql语句
            string sql;
            SqlCommand cmd;
            SqlDataAdapter ad;
            sql = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,picurl as 产品图片,price as 单价, count as 数量,price*count as 小计,status as 状态 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "'";
            cmd = new SqlCommand(sql, conn);//cmd
            ad = new SqlDataAdapter(sql, conn);//ad
            ad.Fill(ds, "table0");
            //购物车为空 转至 商品列表
            if (ds.Tables["table0"].Rows.Count == 0)
            {
                this.lblNoneShoppinglist.Visible = true;
                this.lblNoneShoppinglist.Text = "您还没有任何订单！";
                this.lblNoneShoppinglist.ForeColor = Color.Red;
                if (ds.Tables["table0"] == null || ds.Tables["table0"].Rows.Count == 0)
                this.lblCount.Text = "0";
                lnkbtnFirst.Enabled = false;
                lnkbtnFront.Enabled = false;
                lnkbtnLast.Enabled = false;
                lnkbtnNext.Enabled = false;
                //DropDownList1.Enabled = false;
                //btnSelectRecords.Enabled = false;
                //lblUserInput.Enabled = false;
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
        if (e.CommandName == "btnOperate")
        {
            int oid = int.Parse(dlShoppingCart.DataKeys[e.Item.ItemIndex].ToString());
            int status = getStatus(oid)+1;
            string strUpdate = "update orders set status="+status+"where oid='" + oid + "'";
            conn.Open();
            SqlCommand cmd = new SqlCommand(strUpdate, conn);
            //在原status=3 确认收货状态下 转至评价页面
            if (status == 4)
            {
                chfpage("UserItemAssess.aspx?oid=" + oid);
                return;
            }
            if (Convert.ToInt32(cmd.ExecuteNonQuery()) > 0)
            {
                
                Response.Write("<script>alert('"+Method.orderStatusChangeSuccess[status-1] +"')</script>");
                chfpage("orderlist.aspx");
            }
            else
            {
                Response.Write("<script>alert('操作失败！')</script>");
            }
            conn.Close();
        }
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
    protected void dlShoppingCart_ItemDataBound(object sender, DataListItemEventArgs e)
    {
        Button btn = ((Button)e.Item.FindControl("btnOperate"));
        if (btn.Text == Method.orderStatusChangeOperations[0]||btn.Text == Method.orderStatusChangeOperations[1] || btn.Text == Method.orderStatusChangeOperations[4])
        {
            btn.Visible = false;
        }
    }
    //protected void btnSelectRecords_Click(object sender, EventArgs e)
    //{
    //    if (getaid() < 0) chbpage("adlogin.aspx");
    //    if (this.DropDownList1.SelectedValue != "全部")
    //    {
    //        Response.Redirect("orderlist.aspx?status=" + (this.DropDownList1.SelectedIndex-1));
    //    }
    //    else
    //    {
    //        Response.Redirect("orderlist.aspx");
    //    }
    //}
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        if (this.DropDownList1.SelectedValue != "全部")
        {
            Response.Redirect("orderlist.aspx?status=" + (this.DropDownList1.SelectedIndex - 1));
        }
        else
        {
            Response.Redirect("orderlist.aspx");
        }
    }
}