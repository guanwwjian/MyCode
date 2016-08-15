using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

public partial class UserInfo : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
        string connStr = db.getconnstr();//连接数据库字符串
        SqlConnection conn = new SqlConnection(connStr);//conn
        conn.Open();
        string sql = "select * from users where uid='" + getuid().ToString() + "'";//sql语句
        SqlCommand cmd=new SqlCommand(sql,conn);
        SqlDataAdapter da = new SqlDataAdapter(sql, conn);//da
        DataSet ds = new DataSet();//ds
        da.Fill(ds, "Users");

        //this.dlUserInfo.DataSource = ds.Tables["Users"].DefaultView;
        //this.dlUserInfo.DataBind();

        string UserName = ds.Tables["Users"].Rows[0][1].ToString();//用户名称
        lblUserName.Text = UserName;
        string UserMoney = ds.Tables["Users"].Rows[0][4].ToString();//用户账户余额
        lblUserMoney.Text = UserMoney;
        string UserAccountStatus = ds.Tables["Users"].Rows[0][6].ToString();//用户状态
        if (UserAccountStatus == "True")
        {
            lblAccountStatus.Text = "正常";
        }
        if (UserAccountStatus == "False")
        {
            lblAccountStatus.Text = "被禁用";
        }
        //lblAccountStatus.Text = UserAccountStatus;
        //点击我的订单 转至orderlist.aspx
        //lnkbtnUserCenter.PostBackUrl = "orderlist.aspx";
    }
    protected void lnkbtnUserCenter_Click(object sender, EventArgs e)
    {
        chfpage("orderlist.aspx");
    }
    protected void lnkbtnShoppingCart_Click(object sender, EventArgs e)
    {
        chfpage("shoppingcart.aspx");
    }
    protected void lnkbtnRecharge_Click(object sender, EventArgs e)
    {
        chfpage("recharge.aspx");
    }
    protected void lnkbtnChangePassword_Click(object sender, EventArgs e)
    {
        chfpage("PassWordChange.aspx");
    }
    protected void lnkbtnLogout_Click(object sender, EventArgs e)
    {
        Response.Cookies["userinfo"].Expires = DateTime.Now.AddDays(-1);
        Response.Write("<script>alert('注销成功^^')</script>");
        chfpage("onsales.aspx");
    }
}