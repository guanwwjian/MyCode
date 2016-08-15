using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;

public partial class PlaceAnOrder : Mypage
{
    string connStr ;
    int MoneyToPay1;//此次交易需要付的钱
    protected void Page_Load(object sender, EventArgs e)
    {
        db = new Mydb();
        connStr = db.getconnstr();
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand cmd = new SqlCommand();
        cmd = conn.CreateCommand();
        //显示订单详情
        //！！！  uid=10000
        cmd.CommandText = "select oid as 订单编号,product.pid as 产品编号,pname as 产品名称,price as 单价, count as 数量,price*count as 小计 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status=0";
        SqlDataAdapter ad = new SqlDataAdapter();
        ad.SelectCommand = cmd;
        DataSet ds = new DataSet();
        ad.Fill(ds, "BeforeConfirmOrder");
        //DataTable dt = new DataTable();
        //dt = ds.Tables[0];
        this.GridView1.DataSource = ds.Tables["BeforeConfirmOrder"].DefaultView;
        this.GridView1.DataBind();
        //显示所需付款金额
        cmd.CommandText = "select sum(price*count) as 付款金额 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status=0";
        ad.SelectCommand = cmd;

        object c1 ;
        c1=cmd.ExecuteScalar();

        ad.Fill(ds, "MoneyToPay");
        this.GridView2.DataSource = ds.Tables["MoneyToPay"].DefaultView;
        this.GridView2.DataBind();
        //显示账户余额
        cmd.CommandText = "select money as 余额 from users where uid='" + getuid().ToString() + "'";
        ad.SelectCommand = cmd;

        object c2 ;
        c2=cmd.ExecuteScalar();
        ad.Fill(ds, "AccountBalance");
        this.GridView3.DataSource = ds.Tables["AccountBalance"].DefaultView;
        this.GridView3.DataBind();
        //取 余额、购买所需金额
        //int AccountBalance =Convert.ToInt32( ds.Tables["AccountBalance"].Rows[0][0]);
        //int MoneyToPay = Convert.ToInt32(ds.Tables["MoneyToPay"].Rows[0][0]);
        int AccountBalance, MoneyToPay;
        
        if (c1 != DBNull.Value)
        {
            MoneyToPay1=MoneyToPay = Convert.ToInt32(c1);
        }
        else MoneyToPay = 0;
        if (c2 != null)
        {
            AccountBalance = Convert.ToInt32(c2);
        }
        else AccountBalance =0;
        //关闭数据库连接
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
        //判断 余额是否足够支付
        if (MoneyToPay > AccountBalance)
        {
            Response.Write("<script>window.alert('对不起，您的余额不足，请尽快充值！')</script>");
            btnToRecharge.Visible = true;//显示 前往充值按钮
            Button1.Visible = false;//确认支付按钮 隐藏
            lblNoEnoughMoney.Visible = true;//显示 提示余额不足标签
            lblNoEnoughMoney.ForeColor = Color.Red;
            return;
        }
    }
    protected void Button1_Click(object sender, EventArgs e)//确认支付
    {
        Color myColor1 = Color.Red;
        
        //改库存时使用的数组 临时存放数据
        int[] temp1=new int[100];
        int[] temp2 = new int[100];
        int tempi=0;
        //取值 收货信息
        string useraddress = txtuseraddress.Text;
        string zipcode = txtzipcode.Text;
        string phonenumber = txtphonenumber.Text;
        string realname = txtrealname.Text;
        string additionalmessage = txtadditionalmessage.Text;
        DateTime date1 = new DateTime();//取当前时间,赋给变量date1
        date1 = DateTime.Now;
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand cmd = new SqlCommand();
        DataSet ds1 =new DataSet();
        cmd = conn.CreateCommand();

        //！！！  uid=10000
        //将收货信息添加入数据库
        cmd.CommandText = "update orders set date='" + date1 + "', zipcode='" + zipcode + "',useraddress='" + useraddress + "',phonenumber='" + phonenumber + "',realname='" + realname + "',additionalmessage='" + additionalmessage + "' where uid='" + getuid().ToString() + "' and status=0";
        SqlDataAdapter ad = new SqlDataAdapter();
        ad.UpdateCommand = cmd;
        int iValue = cmd.ExecuteNonQuery();//返回iValue
        //修改库存、出售量

        cmd.CommandText = "select orders.pid,count from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status=0";
        SqlDataReader rd = cmd.ExecuteReader();

        while (rd.Read())
        {
            temp1[tempi] = rd.GetInt32(0);
            temp2[tempi]=rd.GetInt32(1);
            tempi++;
        }
        rd.Close();
        int temps=0;
        while (temps<tempi)
        {

            int pid = temp1[temps];
            int count = temp2[temps];
           
            SqlCommand  cmd1 = new SqlCommand("update product set stock -='" + count + "',bought+='"+count+"' where pid='" + pid + "'",conn);
            //ad.UpdateCommand = cmd1;
            int iUpdateCount = cmd1.ExecuteNonQuery();
            temps++;
            //if (iUpdateCount > 0)
            //{
            //    Response.Write("<script>window.alert('恭喜，已成功修改库存！')</script>");
            //}
        }
        //rd.Close();
        //！！！  uid=10000
        //付款后的订单详情
        cmd.CommandText = "select date as 时间,oid as 订单编号,product.pid as 产品编号,pname as 产品名称, count as 数量,realname as 姓名,phonenumber as 电话号码,useraddress as 收货地址,zipcode as 邮编 from orders join product on orders.pid=product.pid where uid='" + getuid().ToString() + "' and status=0";
        //SqlDataReader dr = cmd.ExecuteReader();
        ad.SelectCommand = cmd;
        ad.Fill(ds1, "AfterConfirmOrder");
       
        //！！！  uid=10000
        //扣款、改状态status=0 为1
        cmd.CommandText = "update users set money-= '" + MoneyToPay1 + "' where uid='" + getuid().ToString() + "';update orders set status=1 where uid='" + getuid().ToString() + "' and status=0;";
        ad.UpdateCommand = cmd;
        int iFuKuan = cmd.ExecuteNonQuery();//返回iFuKuan
        if (iFuKuan > 0)
        {
            Response.Write("<script>window.alert('订单已提交，我们会尽快发货，请耐心等待^^')</script>");
            lblPayStatus.Text = "您已付款：";
            //设置颜色
            lblPayStatus.ForeColor = Color.Red;
        }
        if (iValue > 0)
        {
            //确认后的订单详情
            //！！！  uid=10000
            //Response.Write("<script>window.alert('恭喜，订单已成功提交！')</script>");
            //this.GridView1.Caption = "确认后的订单：";
            //设置颜色
            //this.GridView1.BackColor = Color.Green;
            //this.GridView3.BackColor = Color.Green;
            this.lblAfterConfirmOrder.Text = "确认后的订单：";
            this.lblAfterConfirmOrder.ForeColor = Color.Red;
            //将各输入框设为不可编辑状态
            txtadditionalmessage.Enabled = false;
            txtphonenumber.Enabled = false;
            txtrealname.Enabled = false;
            txtuseraddress.Enabled = false;
            txtzipcode.Enabled = false;
            //this.GridView2.BackColor = Color.Green;
            //Size mySize1 = new Size(12, 12);
            //this.GridView2.Font.Size =Convert.ToInt32( mySize1);
            //绑定确认后的订单并显示
            this.GridView1.DataSource = ds1.Tables["AfterConfirmOrder"].DefaultView;
            this.GridView1.DataBind();
            //绑定付款后 账户余额并显示
            cmd.CommandText = "select money as 余额 from users where uid='" + getuid().ToString() + "'";
            ad.SelectCommand = cmd;
            ad.Fill(ds1, "AfterPayedAccountBalance");
            this.GridView3.DataSource = ds1.Tables["AfterPayedAccountBalance"].DefaultView;
            this.GridView3.DataBind();
        }
        else Response.Write("<script>window.alert('订单提交失败！')</script>");
        Button1.Visible = false;
        Button2.Visible = false;
        //关闭数据库连接
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
    }
    protected void Button2_Click(object sender, EventArgs e)//取消
    {
        //Response.Write("<script>window.close();</script>");
        //Response.Write("<script>window.opener=null;window.close();</script>");
        //Response.Write("<script language=javascript>window.opener=null;window.close();</script>");
        Response.Write("<script language=javascript>alter('您确定要取消订单，返回首页查看其它商品?',history.go(-2));</script>");
    }
    protected void btnToRecharge_Click(object sender, EventArgs e)
    {
        Response.Redirect("recharge.aspx");
    }
}