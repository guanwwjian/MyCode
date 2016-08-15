using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Net.Mail;
using System.Text;
using System.Net;

/// <summary>
///Method 的摘要说明
/// </summary>
public class Method
{
    public static String[] orderstatus={"购物车","已付款","已发货","已收货","已评论"};
    public static String[] orderStatusChangeSuccess = { "已成功付款", "已发货", "收货完成", "评论成功","" };
    public static String[] orderStatusChangeOperations = { "付款", "发货", "收货", "评论","" };
    public static String[] adorderstatus = { "购物车中", "买家已付款", "已发货", "买家已收货", "买家已评论" };
    public static String[] adorderStatusChangeSuccess = { "已成功付款", "已发货", "收货完成", "评论成功", "" };
    public static String[] adorderStatusChangeOperations = { "付款", "发货", "确认收货", "评论", "" };

    /// <summary>
    /// 产生长度为length的随机数
    /// </summary>
    /// <param name="length">随机数的长度</param>
    /// <returns>长为length且只有数字的string</returns>
    public static String getRandomNum(int length = 10,int seed=1)
    {
        String rtn="";
        Random ra = new Random(unchecked((int)DateTime.Now.Ticks)*seed);
        int max = 1;
        for (int x = 0; x < length; x++)
        {
            max = max * 10;
        }
        rtn = ra.Next(max).ToString().PadLeft(length,'0');
        return rtn;
    }
    /// <summary>
    /// 产生在最小值最大值之间的随机数
    /// </summary>
    /// <param name="minValue">最小值</param>
    /// <param name="maxValue">最大值</param>
    /// <param name="length">随机数的位数 不足用0填充</param>
    /// <returns></returns>
    public static String getRandomNum(int minValue, int maxValue,int length=0)
    {
        String rtn = "";
        Random ra = new Random(unchecked((int)DateTime.Now.Ticks));
        if (length <= 0)
        {
            rtn = ra.Next(minValue, maxValue).ToString();
        }
        else
        {
            rtn = ra.Next(minValue, maxValue).ToString().PadLeft(length, '0');
        }
        return rtn;
    }
    ///  <summary> 
    /// MD5加密算法 
    ///  </summary> 
    ///  <param name="str">字符串 </param> 
    ///  <returns>生成的密码32位</returns> 
    public static string MD5(string str)
    {
            return System.Web.Security.FormsAuthentication.HashPasswordForStoringInConfigFile(str, "MD5").ToUpper();
    }
    /// <summary>
    /// 想用户发送当前的密码
    /// </summary>
    /// <param name="useremail">用户登记的邮箱</param>
    /// <param name="username">用户名</param>
    /// <param name="psw">用户当前的密码</param>
    /// <param name="message">NULL则发送成功，否则为错误信息</param>
	public static void FindPassword(String useremail,String username,String psw,out String message)
	{
        String from = "carrotwang@hotmail.com";
        String to = useremail;
        String subject = "找回密码";
        String msg = String.Format("用户{0}你好：\n\t您的新密码为{1}。\n\t祝好！\n\t呵呵网上商城\n\t{2}",username,psw,DateTime.Now.ToShortDateString());
        message = SendEMail(from, to, subject, msg);

	}
    /// <summary>
    /// 发送用于找回密码的邮件
    /// </summary>
    /// <param name="from">发送者的邮箱地址@hotmail.com</param>
    /// <param name="to">用户者的邮箱地址</param>
    /// <param name="subject">标题</param>
    /// <param name="msg">内容</param>
    /// <returns>成功返回null 否则返回异常信息</returns>
    private static String SendEMail(String from,String to,String subject,String msg)
    {
        var smtp = new SmtpClient();
        var mail = new MailMessage(from,to);

        ////标题和内容，注意设置编码，因为默认编码是ASCII

        mail.Subject = subject;

        mail.SubjectEncoding = Encoding.UTF8;

        //HTML内容

        mail.Body = msg;

        mail.BodyEncoding = Encoding.UTF8;



        //指示改电子邮件内容是HTML格式

        mail.IsBodyHtml = false;



        //SMTP设置（根据邮箱类型设置，这里是Live Mail的SMTP服务器地址）

        smtp.Host = "smtp.live.com";

        smtp.UseDefaultCredentials = false;

        //某些SMTP服务器可能不支持SSL，会抛出异常

        smtp.EnableSsl = true;

        smtp.Credentials = new NetworkCredential("carrotwang@hotmail.com", "iwillbetheone");

        smtp.DeliveryMethod = SmtpDeliveryMethod.Network;

        smtp.Port = 25;
        //smtp.Port = 587;

        //发送

        try
        {
            smtp.Send(mail);
            return null;
        }
        catch (Exception e)
        {
            return e.ToString();//失败返回异常信息
        }
    }
}