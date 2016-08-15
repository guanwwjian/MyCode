using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Drawing;
public partial class checkcode : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        //建立位图对象
        Bitmap newBitmap = new Bitmap(36, 16, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        //根据上面创建的位图对象创建绘图层
        Graphics g = Graphics.FromImage(newBitmap);
        //以指定的颜色填宠矩形区
        g.FillRectangle(new SolidBrush(Color.White), new Rectangle(0, 0, 36, 16));
        //创建字体对象
        Font textFont = new Font("Times new Roman", 10);
        //创建RectangleF结构指定一个区域
        RectangleF rectangle = new RectangleF(0, 0, 36, 16);
        //创建随机数对象
        Random rd = new Random();
        //取得随机数
        int valationNo = 1000 + rd.Next(8999);
        //使用指定的颜色填充上面的RectangleF结构指定的矩形区域
        g.FillRectangle(new SolidBrush(Color.BurlyWood), rectangle);
        //在上面填充的矩形区域中填充上面生成的随机数
        g.DrawString(valationNo.ToString(), textFont, new SolidBrush(Color.Blue), rectangle);
        Response.ContentType = "Image/Gif";
        newBitmap.Save(Response.OutputStream, System.Drawing.Imaging.ImageFormat.Gif);
        Session.Add("checkcode",valationNo);
    }
}