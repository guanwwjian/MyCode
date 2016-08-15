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


public partial class productlist : Mypage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        /*db = new Mydb();
        //if (!IsPostBack)
        //{
            if (Request.QueryString["pid"] != null)
            {
                string pid = Request.QueryString["pid"];
                SqlConnection conn = new SqlConnection(db.getconnstr());
                conn.Open();
                SqlDataAdapter ad = new SqlDataAdapter("select * from product where pid=" + pid, conn);
                DataSet ds = new DataSet();

                ad.Fill(ds);
                this.DataList1.DataSource = ds;
                this.DataList1.DataBind();

                SqlDataAdapter ad2 = new SqlDataAdapter("select * from orders,users where orders.uid=users.uid and pid=" + pid, conn);
                DataSet ds2 = new DataSet();
                ad2.Fill(ds2);
                this.DataList2.DataSource = ds2;
                this.DataList2.DataBind();

                if (conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
            }
            else
            {
                chfpage("productlist.aspx");
            }
       // }*/
        if (!IsPostBack) dlBind();
    }
    protected void Button1_Click(object sender, EventArgs e)
    {

    }
    protected void DataList1_ItemCommand(object source, DataListCommandEventArgs e)
    {
        SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
        if (e.CommandName == "add1")
        {
            if (getuid() >= 0)
            {
                int pid1 = Int32.Parse(DataList1.DataKeys[e.Item.ItemIndex].ToString());
                int count1 = Int32.Parse(((TextBox)e.Item.FindControl("TextBox1")).Text);


                string sqltest = "select product.stock from product where product.pid=" + pid1.ToString();
                sqlconn.Open();
                SqlCommand sqlcom = new SqlCommand(sqltest, sqlconn);
                SqlDataReader read = sqlcom.ExecuteReader();
                if (read.Read())
                {
                    int b = Int32.Parse(read["stock"].ToString().Trim());
                    if (count1 >= b)
                    {
                        Response.Write("<script language='javascript'>alert('库存不够！');localtion='product.aspx'</script>");
                    }
                    else
                    {

                        read.Close();
                        string sqlstr = "insert into orders(orders.pid,orders.uid,orders.count,orders.status) values (" + pid1.ToString() + "," + getuid().ToString() + "," + count1.ToString() + ",0)";
                        sqlcom.CommandText = sqlstr;
                        sqlcom.ExecuteNonQuery();
                       
                        Response.Write("<script language='javascript'>alert('加入购物车成功！');localtion='product.aspx'</script>");
                    }
                }
                sqlconn.Close();
            }
            else Response.Write("<script language='javascript'>alert('请登录后再操作！');localtion='login.aspx'</script>");
        }
    }



    public void dlBind()
    {


        //if (!IsPostBack)
        //{
        if (Request.QueryString["pid"] != null)
        {
            Mydb db = new Mydb();
            string pid = Request.QueryString["pid"];
            SqlConnection conn = new SqlConnection(db.getconnstr());
            conn.Open();
            SqlDataAdapter ad = new SqlDataAdapter("select * from product where pid=" + pid, conn);
            DataSet ds = new DataSet();

            ad.Fill(ds);
            this.DataList1.DataSource = ds;
            this.DataList1.DataBind();
            if (Label16.Text == "Label") Label16.Text = "1";
            int pagenum = Convert.ToInt32(Label16.Text);
            SqlDataAdapter ad2 = new SqlDataAdapter("select * from orders,users where orders.uid=users.uid and status=4 and pid=" + pid, conn);
            DataSet ds2 = new DataSet();
            ad2.Fill(ds2, "product");
            PagedDataSource ps = new PagedDataSource();
            ps.DataSource = ds2.Tables["product"].DefaultView;
            ps.AllowPaging = true;
            ps.PageSize = 10;
            ps.CurrentPageIndex = pagenum - 1;
            InkbtnFirst1.Enabled = true;
            InkbtnFront1.Enabled = true;
            InkbtnNext1.Enabled = true;
            InkbtnLast1.Enabled = true;
            if (pagenum == 1)
            {
                InkbtnFirst1.Enabled = false;
                InkbtnFront1.Enabled = false;
            }
            if (pagenum == ps.PageCount)
            {
                InkbtnNext1.Enabled = false;
                InkbtnLast1.Enabled = false;
            }
            this.DataList2.DataSource = ps;
            this.DataList2.DataBind();
            this.Label15.Text = ps.PageCount.ToString();
            this.Label16.Text = pagenum.ToString();
            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }

        }
        else
        {
            chfpage("productlist.aspx");
        }
        /*Mydb db = new Mydb();
        if (Label16.Text == "Label") Label16.Text = "1";
        int pagenum = Convert.ToInt32(Label16.Text);
        SqlConnection conn = new SqlConnection(db.getconnstr());
        conn.Open();
        SqlDataAdapter ad;
        if (Request.QueryString["word"] == null) ad = new SqlDataAdapter("select * from product ", conn);
        else ad = ad = new SqlDataAdapter("select * from product where " + Request.QueryString["word"], conn);
        DataSet ds = new DataSet();
        ad.Fill(ds, "product");
        
        PagedDataSource ps = new PagedDataSource();
        ps.DataSource = ds.Tables["product"].DefaultView;
        ps.AllowPaging = true;
        ps.PageSize = 5;
        ps.CurrentPageIndex = pagenum - 1;
        InkbtnFirst1.Enabled = true;
        InkbtnFront1.Enabled = true;
        InkbtnNext1.Enabled = true;
        InkbtnLast1.Enabled = true;
        if (pagenum == 1)
        {
            InkbtnFirst1.Enabled = false;
            InkbtnFront1.Enabled = false;
        }
        if (pagenum == ps.PageCount)
        {
            InkbtnNext1.Enabled = false;
            InkbtnLast1.Enabled = false;
        }

        this.DataList1.DataSource = ps;
        this.DataList1.DataBind();
        this.Label15.Text = ps.PageCount.ToString();
        this.Label16.Text = pagenum.ToString();
        if (conn.State == ConnectionState.Open)
        {
            conn.Close();
        }*/
        // }
    }





    protected void InkbtnFirst1_Click(object sender, EventArgs e)
    {
        Label16.Text = "1";
        dlBind();
    }
    protected void InkbtnFront1_Click(object sender, EventArgs e)
    {
        Label16.Text = (Convert.ToInt32(Label16.Text) - 1).ToString();
        dlBind();

    }
    protected void InkbtnNext1_Click(object sender, EventArgs e)
    {
        Label16.Text = (Convert.ToInt32(Label16.Text) + 1).ToString();
        dlBind();
    }
    protected void InkbtnLast1_Click(object sender, EventArgs e)
    {
        Label16.Text = Label15.Text;
        dlBind();
    }
}