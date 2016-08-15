using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class adordersmanage : Mypage
{
    String connStr ;
    String UidChosen;
    String OidChosen;
    String StatusChosen;
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            if (getaid() < 0) chbpage("adlogin.aspx");
            db = new Mydb();
            connStr = db.getconnstr();
            SqlConnection conn = new SqlConnection(connStr);
            conn.Open();
            SqlCommand cmd = new SqlCommand();
            cmd = conn.CreateCommand();
            SqlDataAdapter ad = new SqlDataAdapter();
            //ad.SelectCommand = cmd;
            DataSet ds = new DataSet();
            
            //绑定orders表中的uid 至dropdownlist中
            ListItem item = new ListItem("全部","全部");
            this.DropDownList1.Items.Add(item);
            this.DropDownList1.SelectedIndex = 1;
            for (int x = 0; x < Method.adorderstatus.Count(); x++)
            {
                item = new ListItem(Method.adorderstatus[x], x.ToString());
                this.DropDownList1.Items.Add(item);
            }
            //this.DropDownList1.DataTextField = "date";
            this.DropDownList1.DataBind();
            //显示所有status为1的订单
            cmd.CommandText = "select oid as 订单编号,uid as 用户ID,product.pid as 产品编号,pname as 产品名称,price as 单价, count as 数量,price*count as 总价,status as 订单状态 from orders join product on orders.pid=product.pid";
            ad.SelectCommand = cmd;
            ad.Fill(ds, "Orders");
            DataBind(ds);
            DefineBtn(ds);
            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }
            //DataTable dt = new DataTable();
            //dt.Columns.Add("订单编号");
            //dt.Columns.Add("用户ID");
            //dt.Columns.Add("产品编号");
            //dt.Columns.Add("产品名称");
            //dt.Columns.Add("单价");
            //dt.Columns.Add("数量");
            //dt.Columns.Add("总价");
            //dt.Columns.Add("订单状态");

            //foreach (DataRow dr in ds.Tables["Orders"].Rows)
            //{
            //    DataRow item = dt.NewRow();
            //    item[0] = dr[0];
            //    item[1] = dr[1];
            //    item[2] = dr[2];
            //    item[3] = dr[3];
            //    item[4] = dr[4];
            //    item[5] = dr[5];
            //    item[6] = dr[6];
            //    item[7] = Method.adorderstatus[int.Parse(dr[7].ToString())];
            //    dt.Rows.Add(item);
            //    //item["订单编号"] = dr[0];
            //    //item["用户ID"] = dr[1];
            //    //item["产品编号"] = dr[2];
            //    //item["产品名称"] = dr[3];
            //    //item["单价"] = dr[4];
            //    //item["数量"] = dr[5];
            //    //item["总价"] = dr[6];

            //    //item["订单状态"] = Method.adorderstatus[int.Parse(dr[7].ToString())];
            //    //dt.Rows.Add(item);
            //}
            //if (dt.Rows.Count == 0)
            //{  
            //}
            //this.GridView_UserOrders.DataSource = dt.DefaultView;
            //this.GridView_UserOrders.DataBind();
        }
    }
    protected void DefineBtn(DataSet ds)
    {
        for (int x = 0; x < ds.Tables["Orders"].Rows.Count; x++)
        {
            if (ds.Tables["Orders"].Rows[x][7].ToString() != "1" && ds.Tables["Orders"].Rows[x][7].ToString() != "2")
            {
                Button btn = ((Button)this.GridView_UserOrders.Rows[x].FindControl("btnChangeStatus"));
                btn.Text = Method.adorderstatus[int.Parse(ds.Tables["Orders"].Rows[x][7].ToString())];
                btn.Enabled = false;
            }
            else if(ds.Tables["Orders"].Rows[x][7].ToString() == "1")
            {
                Button btn = ((Button)this.GridView_UserOrders.Rows[x].FindControl("btnChangeStatus"));
                btn.Text = "发货";
            }
            else if (ds.Tables["Orders"].Rows[x][7].ToString() == "2")
            {
                Button btn = ((Button)this.GridView_UserOrders.Rows[x].FindControl("btnChangeStatus"));
                btn.Text = "取消发货";
            }
        }
        this.Label1.Text = "共找到" + ds.Tables["Orders"].Rows.Count.ToString()+ "条记录";
    }
    protected void DataBind(DataSet ds)
    {
        DataTable dt = new DataTable();
        dt.Columns.Add("订单状态");
        dt.Columns.Add("订单编号");
        dt.Columns.Add("用户ID");
        dt.Columns.Add("产品编号");
        dt.Columns.Add("产品名称");
        dt.Columns.Add("单价");
        dt.Columns.Add("数量");
        dt.Columns.Add("总价");

        if (ds.Tables["Orders"].Rows.Count != 0)
        {
            for (int x = 0;x < ds.Tables["Orders"].Rows.Count; x++)
            {
                        DataRow item = dt.NewRow();
                        item["订单编号"] = ds.Tables["Orders"].Rows[x][0];
                        item["用户ID"] = ds.Tables["Orders"].Rows[x][1];
                        item["产品编号"] = ds.Tables["Orders"].Rows[x][2];
                        item["产品名称"] = ds.Tables["Orders"].Rows[x][3];
                        item["单价"] = ds.Tables["Orders"].Rows[x][4];
                        item["数量"] = ds.Tables["Orders"].Rows[x][5];
                        item["总价"] = ds.Tables["Orders"].Rows[x][6];

                        item["订单状态"] = Method.adorderstatus[int.Parse(ds.Tables["Orders"].Rows[x][7].ToString())];
                        dt.Rows.Add(item);
            }

        }
        this.GridView_UserOrders.DataSource = dt.DefaultView;
        this.GridView_UserOrders.DataBind();
   
    }
    protected void GridView_UserOrders_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        db = new Mydb();
        connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand cmd = new SqlCommand();
        cmd = conn.CreateCommand();

        GridView_UserOrders.DataKeyNames = new string[] { "订单编号" };
        //int strTemp = Convert.ToInt32(GridView_UserOrders.Rows[e.RowIndex].Cells[2].Text.Trim());
        //取订单编号
        int strTemp = Convert.ToInt32(GridView_UserOrders.Rows[e.RowIndex].Cells[3].Text.ToString().Trim());
        cmd.CommandText = "delete from orders where oid='" + strTemp + "'";
        SqlDataAdapter ad = new SqlDataAdapter();
        ad.DeleteCommand = cmd;
        int iValue = cmd.ExecuteNonQuery();
        if (iValue > 0)
        {
            Response.Write("<script language:javascript>javascript:window:alert('删除成功');</script>");
            chbpage("adordersmanage.aspx");
            //Response.Redirect("adordersmanage.aspx");
            //重新显示gridview1中的内容
            //txtUidInput.Text = txtUidInput.Text;
            //btnConfirmUid_Click(sender, e);
        }
        else
        {
            Response.Write("<script language:javascript>javascript:window:alert('删除失败');</script>");
        }
    }
    protected void GridView_UserOrders_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {
           //((LinkButton)(e.Row.Cells[0].Controls[0])).Attributes.Add("onclick", "return confirm('确定要删除吗？')");
        }
    }
    protected void btnChangeStatus_OnClick(object sender, EventArgs e)
    {
        int row = ((GridViewRow)((Button)sender).NamingContainer).RowIndex;
        db = new Mydb();
        connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand cmd = new SqlCommand();
        cmd = conn.CreateCommand();
        GridView_UserOrders.DataKeyNames = new string[] { "oid" };
        int strTemp = int.Parse(GridView_UserOrders.Rows[row].Cells[3].Text.Trim());
        if (GridView_UserOrders.Rows[row].Cells[2].Text == Method.adorderstatus[1])
        {
            cmd.CommandText = "update orders set status=2 where oid='" + strTemp + "'and status=1";
        }
        else if (GridView_UserOrders.Rows[row].Cells[2].Text == Method.adorderstatus[2])
        {
            cmd.CommandText = "update orders set status=1 where oid='" + strTemp + "'and status=2";
        }
        SqlDataAdapter ad = new SqlDataAdapter();
        ad.DeleteCommand = cmd;
        int iValue = cmd.ExecuteNonQuery();
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
        if (iValue > 0)
        {
            Response.Write("<script language:javascript>javascript:window:alert('修改成功');</script>");
            Response.Redirect("adordersmanage.aspx");
            //重新显示gridview1中的内容
            //txtUidInput.Text = txtUidInput.Text;
            //btnConfirmUid_Click(sender, e);
        }
        else
        {
            Response.Write("<script language:javascript>javascript:window:alert('修改失败');</script>");
        }

    }
    protected void btnSelectRecords_Click(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        db = new Mydb();
        connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand cmd = new SqlCommand();
        cmd = conn.CreateCommand();
        cmd.CommandText = "select oid as 订单编号,uid as 用户ID,product.pid as 产品编号,pname as 产品名称,price as 单价, count as 数量,price*count as 总价,status as 订单状态 from orders join product on orders.pid=product.pid";
        SqlDataAdapter ad = new SqlDataAdapter();
        ad.SelectCommand = cmd;
        DataSet ds = new DataSet();
        ad.Fill(ds, "Orders");
        if(!String.IsNullOrEmpty(txtInput.Text))
        {
            if (ds.Tables["Orders"].Rows.Count != 0)
            {
                for (int x = 0; x < ds.Tables["Orders"].Rows.Count; x++)
                {
                    if (ds.Tables["Orders"].Rows[x]["订单编号"].ToString().Contains(txtInput.Text) == false && ds.Tables["Orders"].Rows[x]["用户ID"].ToString().Contains(txtInput.Text) == false && ds.Tables["Orders"].Rows[x]["产品编号"].ToString().Contains(txtInput.Text) == false)
                    {
                        ds.Tables["Orders"].Rows.RemoveAt(x);
                        x--;
                    }
                }
            }
        }
        if(this.DropDownList1.SelectedValue!="全部")
        {
            if (ds.Tables["Orders"].Rows.Count != 0)
            {
                for(int x = 0;x<ds.Tables["Orders"].Rows.Count;x++)
                {
                    if (ds.Tables["Orders"].Rows[x]["订单状态"].ToString() != this.DropDownList1.SelectedValue)
                    {
                        ds.Tables["Orders"].Rows.RemoveAt(x);
                        x--;
                    }
                }
            }
        }
        DataBind(ds);
        DefineBtn(ds);
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
    }
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        db = new Mydb();
        connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand cmd = new SqlCommand();
        cmd = conn.CreateCommand();
        cmd.CommandText = "select oid as 订单编号,uid as 用户ID,product.pid as 产品编号,pname as 产品名称,price as 单价, count as 数量,price*count as 总价,status as 订单状态 from orders join product on orders.pid=product.pid";
        SqlDataAdapter ad = new SqlDataAdapter();
        ad.SelectCommand = cmd;
        DataSet ds = new DataSet();
        ad.Fill(ds, "Orders");
        if (!String.IsNullOrEmpty(txtInput.Text))
        {
            if (ds.Tables["Orders"].Rows.Count != 0)
            {
                for (int x = 0; x < ds.Tables["Orders"].Rows.Count; x++)
                {
                    if (ds.Tables["Orders"].Rows[x]["订单编号"].ToString().Contains(txtInput.Text) == false && ds.Tables["Orders"].Rows[x]["用户ID"].ToString().Contains(txtInput.Text) == false && ds.Tables["Orders"].Rows[x]["产品编号"].ToString().Contains(txtInput.Text) == false)
                    {
                        ds.Tables["Orders"].Rows.RemoveAt(x);
                        x--;
                    }
                }
            }
        }
        if (this.DropDownList1.SelectedValue != "全部")
        {
            if (ds.Tables["Orders"].Rows.Count != 0)
            {
                for (int x = 0; x < ds.Tables["Orders"].Rows.Count; x++)
                {
                    if (ds.Tables["Orders"].Rows[x]["订单状态"].ToString() != this.DropDownList1.SelectedValue)
                    {
                        ds.Tables["Orders"].Rows.RemoveAt(x);
                        x--;
                    }
                }
            }
        }
        DataBind(ds);
        DefineBtn(ds);
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
    }
}