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
        if (!IsPostBack)
        {
            Mydb db = new Mydb();
            SqlConnection conn = new SqlConnection(db.getconnstr());
            conn.Open();
            SqlDataAdapter ad1 = new SqlDataAdapter("select tname from type", conn);
            DataSet ds1 = new DataSet();
            ad1.Fill(ds1);
            this.ddlCondition1.DataSource = ds1;
            this.ddlCondition1.DataBind();
            ListItem li = new ListItem();
            li.Text = "<未选择>";
            li.Value = "<未选择>";
            this.ddlCondition1.Items.Add(li);
            this.ddlCondition1.SelectedValue = "<未选择>";
            dlBind();
        }
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
                        Response.Write("<script language='javascript'>alert('库存不够！');localtion='productlist.aspx'</script>");
                    }
                    else
                    {

                        read.Close();
                        string sqlstr = "insert into orders(orders.pid,orders.uid,orders.count,orders.status) values (" + pid1.ToString() + "," + getuid().ToString() + "," + count1.ToString() + ",0)";
                        sqlcom.CommandText = sqlstr;
                        sqlcom.ExecuteNonQuery();
                       
                        Response.Write("<script language='javascript'>alert('加入购物车成功！');localtion='productlist.aspx'</script>");
                    }
                }
                sqlconn.Close();
            }
            else Response.Write("<script language='javascript'>alert('请登录后再操作！');localtion='login.aspx'</script>");
        }
        else if (e.CommandName == "link1")
        {
            int pid1 = Int32.Parse(DataList1.DataKeys[e.Item.ItemIndex].ToString());
            chfpage("product.aspx?pid=" + pid1.ToString());
        }
    }
    protected void link1(object sender, CommandEventArgs e)
    {

    }



      public void dlBind()   
      {
          
          
          //if (!IsPostBack)
          //{
              Mydb db = new Mydb();
              if (Label13.Text == "Label") Label13.Text = "1";
              int pagenum = Convert.ToInt32(Label13.Text);
              SqlConnection conn = new SqlConnection(db.getconnstr());
              conn.Open();
              SqlDataAdapter ad;
              if (Request.QueryString["word"]==null) ad = new SqlDataAdapter("select * from product ", conn);
              else
              {
                  ad = new SqlDataAdapter("select * from product where " + Server.HtmlDecode(Request.QueryString["word"]), conn);
              }
              DataSet ds = new DataSet();
              ad.Fill(ds, "product"); 
              PagedDataSource ps = new PagedDataSource();
              ps.DataSource = ds.Tables["product"].DefaultView;
              ps.AllowPaging = true;
              ps.PageSize = 5;
              ps.CurrentPageIndex = pagenum - 1;
              InkbtnFirst.Enabled = true;
              InkbtnFront.Enabled = true;
              InkbtnNext.Enabled = true;
              InkbtnLast.Enabled = true;
              if (pagenum == 1)
              {
                  InkbtnFirst.Enabled = false;
                  InkbtnFront.Enabled = false;
              }
              if (pagenum == ps.PageCount)
              {
                  InkbtnNext.Enabled = false;
                  InkbtnLast.Enabled = false;
              }
              
              this.DataList1.DataSource = ps;
              this.DataList1.DataBind();
              this.Label12.Text = ps.PageCount.ToString();
              this.Label13.Text = pagenum.ToString();
              if (ps.Count == 0) Label14.Visible = true;
              else Label14.Visible = false;
              if (conn.State == ConnectionState.Open)
              {
                  conn.Close();
              }
         // }
      }





      protected void LinkButton2_Click(object sender, EventArgs e)
      {
          Label13.Text = "1";
          dlBind();

      }
      protected void InkbtnFront_Click(object sender, EventArgs e)
      {
          Label13.Text = (Convert.ToInt32(Label13.Text) - 1).ToString();
          dlBind();
         
      }
      protected void InkbtnNext_Click(object sender, EventArgs e)
      {
          Label13.Text = (Convert.ToInt32(Label13.Text) + 1).ToString();
          dlBind();
      }
      protected void InkbtnLast_Click(object sender, EventArgs e)
      {
          Label13.Text = Label12.Text; 
          dlBind();
      }
      protected void search_Click(object sender, EventArgs e)
      {

          String st = "productlist.aspx?word=";//encodeURI(\"";
          bool flag = false;
          if ((ddlCondition1.SelectedValue != "<未选择>") || (txtprice1.Text != "") || (txtprice2.Text != "") || (txtKey.Text != "") || (rangetype.SelectedValue != "<未选择>"))
          {
              if (!((txtprice1.Text != "") && (txtprice2.Text != "") && (Convert.ToInt32(txtprice1.Text) > Convert.ToInt32(txtprice2.Text))))
              {
                  if (ddlCondition1.SelectedValue != "<未选择>")
                  {
                      Mydb db = new Mydb();
                      db.Open();
                      SqlDataReader rd = db.ExecuteReader("select tid from type where tname='" + ddlCondition1.SelectedValue + "'");
                      int tid;
                      if (rd.Read())
                      {
                          tid = (int)rd.GetSqlInt32(0);
                          if (flag) st = st + " and ";
                          st = st + "tid=" + tid.ToString();
                          flag = true;
                      }
                      db.Close();

                  }
                  if (txtprice1.Text != "")
                  {
                      if (flag) st = st + " and ";
                      st = st + "price >= " + txtprice1.Text;
                      flag = true;
                  }
                  if (txtprice2.Text != "")
                  {
                      if (flag) st = st + " and ";
                      st = st + "price <= " + txtprice2.Text;
                      flag = true;
                  }
                  if (txtKey.Text != "")
                  {
                      if (flag) st = st + " and ";
                      st = st + "pname like '%" + txtKey.Text.Trim() + "%'";
                      flag = true;
                  }
                  if (rangetype.SelectedValue != "<未选择>")
                  {
                      string tt = "";
                      if (!flag) st = st + "1=1 ";
                      if (rangetype.SelectedValue=="按价格升序排列") tt="order by price asc";
                      else if (rangetype.SelectedValue=="按价格降序排列") tt="order by price desc";
                      else if (rangetype.SelectedValue == "按购买量升序排列") tt = "order by bought asc";
                      else if (rangetype.SelectedValue == "按购买量降序排列") tt = "order by bought desc";
                      st = st + tt;
                  }
                  //st = st + "\")";
                  chfpage(Server.UrlEncode(st));
                  
              }
              else
                  Response.Write("<script language='javascript'>alert('您所要输入的价格不正确');location='productlist.aspx';</script>");
          }
          else chfpage("productlist.aspx");


      }
}