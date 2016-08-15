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

public partial class AdminManage_EditGoods : Mypage
{
    SqlOperate sqloperate = new SqlOperate();
    SqlConnection sqlconn = new SqlConnection(ConfigurationManager.AppSettings["ConnectionString"]);
    protected void Page_Load(object sender, EventArgs e)
    {
        if (getaid() < 0) chbpage("adlogin.aspx");
        if (!IsPostBack)
        {
                sqlconn.Open();
                
                
                string sqlstr = "select tname,tid from type";
                sqloperate.ddlDataBind(ddlGType, sqlstr, "tname", "tid");
                if (!String.IsNullOrEmpty(Request.QueryString["pid"]))
                {
                    string sqlstrshow = "select * from product where pid='" + Request.QueryString["pid"] + "'";
                    SqlDataAdapter myapter = new SqlDataAdapter(sqlstrshow, sqlconn);
                    DataSet mydset = new DataSet();
                    myapter.Fill(mydset, "product");//pname,price,stock,introduce,bought,tid,picurl
                    DataRowView mydrview = mydset.Tables["product"].DefaultView[0];
                    if (mydset.Tables["product"].Rows.Count == 0)
                    {
                        //pid不存在
                        Response.Write("<script language='javascript'>alert('要修改的商品不存在');location='EditGoods.aspx';</script>");
                        chbpage("GoodsManage.aspx");
                    }
                    else
                    {
                        txtGName.Text = mydrview["pname"].ToString();
                        txtGPrice.Text = mydrview["price"].ToString();
                        txtstock.Text = mydrview["stock"].ToString();
                        txtbought.Text = mydrview["bought"].ToString();
                        txtGIntroduce.Text = mydrview["introduce"].ToString();
                        imgPhoto.ImageUrl = mydrview["picurl"].ToString();
                        ddlGType.SelectedValue = mydrview["tid"].ToString();
                    }
                }
            }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        //判断用户是否选择了要上传的文件
        if (FileUpload1.PostedFile.FileName == string.Empty)
        {
            //如果没有选择则提示用户选择文件
            Response.Write("<script language=javascript>alert('请选择要上传的图片！')</script>");
        }
        else
        {
            //获取FileUpload1控件中的文件路径
            string filepath = FileUpload1.PostedFile.FileName;
            //获取文件名
            string filename = filepath.Substring(filepath.LastIndexOf("\\") + 1);
            string filename1 = "~/Image/" + filename;
            string savepath = Server.MapPath("Image");
            //保存文件
            FileUpload1.PostedFile.SaveAs(savepath + "\\" + filename);
            try//捕获异常
            {
                imgPhoto.ImageUrl = filename1.ToString();
            }
            catch (System.Exception ee)
            {
                Response.Write(ee.ToString());
            }
            finally
            {
                sqlconn.Close();
            }

        }
    }
    protected void btnBack_Click(object sender, EventArgs e)
    {
        chbpage("GoodsManage.aspx");
    }

    protected int IsNumer(string str)
    {
       for(int i=0;i<str.Length;i++)
       {
           if (str[i] < 48 || str[i] > 57) return 0;
       }
        return 1;
    }

    protected void btnSave_Click(object sender, EventArgs e)
    {
        if (String.IsNullOrEmpty(Request.QueryString["pid"]))
        {
            
                int b = IsNumer(txtGPrice.Text);
                int c = IsNumer(txtstock.Text);
                int d = IsNumer(txtbought.Text);
                if (b == 0 || c == 0 || d == 0)
                {
                    Response.Write("<script language='javascript'>alert('输入格式不正确，商品价格、库存、销售额只能为整数。');location='EditGoods.aspx';</script>");
                }
                else
                {
                    sqlconn.Close();
                    string sqlstr1 = "select * from type where tid='" + ddlGType.SelectedValue + "'";
                    sqlconn.Open();
                    SqlCommand sqlcom1 = new SqlCommand(sqlstr1, sqlconn);
                    SqlDataReader read1 = sqlcom1.ExecuteReader();
                    read1.Read();
                    int a = Int32.Parse(read1["tid"].ToString());
                    string sqlstr = "insert into product"
                            + "(pname,price,stock,introduce,bought,tid,picurl) "
                            + "values('" + txtGName.Text.Trim() + "','" + txtGPrice.Text.Trim()
                            + "','" + txtstock.Text.Trim() + "','" + txtGIntroduce.Text.Trim() + "','" + txtbought.Text.Trim() + "','" + a + "','" + imgPhoto.ImageUrl + "')";
                    sqloperate.DataCom(sqlstr);
                    Response.Write("<script>alert('添加成功');</script>");
                    chbpage("GoodsManage.aspx");
                }
        }
        else
        {
                int b = IsNumer(txtGPrice.Text);
                int c = IsNumer(txtstock.Text);
                int d = IsNumer(txtbought.Text);
                if (b == 0 || c == 0 || d == 0)
                {
                    Response.Write("<script language='javascript'>alert('输入格式不正确，商品价格、库存、销售额只能为整数。');</script>");
                }
                else
                {
                    sqlconn.Close();
                    string sqlstr1 = "select * from type where tid='" + ddlGType.SelectedValue + "'";
                    sqlconn.Open();
                    SqlCommand sqlcom1 = new SqlCommand(sqlstr1, sqlconn);
                    SqlDataReader read1 = sqlcom1.ExecuteReader();
                    read1.Read();
                    int a = Int32.Parse(read1["tid"].ToString());
                    string sqlstr = "update product set stock='" + txtstock.Text.Trim() + "',tid='" + a + "',bought='" + txtbought.Text.Trim() + "',picurl='" + imgPhoto.ImageUrl + "',price='" + txtGPrice.Text.Trim() + "',introduce='"
                        + txtGIntroduce.Text.Trim() + "'where pid='" + Request.QueryString["pid"] + "'";
                    sqloperate.DataCom(sqlstr);
                    Response.Write("<script lanuage=javascript>alert('修改成功');</script>");
                    chbpage("GoodsManage.aspx");
                }

        }

    }
}
