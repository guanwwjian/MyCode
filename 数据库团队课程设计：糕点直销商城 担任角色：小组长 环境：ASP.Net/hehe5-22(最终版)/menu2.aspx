<%@ Page Language="C#" AutoEventWireup="true" CodeFile="menu2.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1
        {
            font-size: large;
            font-family: 楷体;
        }
        .style1
        {
            width: 79px;
        }
        .style2
        {
            width: 77px;
        }
        .style3
        {
            font-size: medium;
            font-family: 楷体;
        }
        .style4
        {
            font-size: small;
        }
    </style>
    </head>
<body style="font-size: small">
    <form id="form1" runat="server">
    <div>

                    <table style="width:640px; height: 50px; ">
                        <tr>                           
                            <td style="text-align: center; width: 80px; background-image: url('Image/bannericon/redicon.jpg');">
                                <a href="onsales.aspx" target="main">首页</a></td>
                            <td style="width: 80px; text-align: center; background-image: url('Image/bannericon/yellowicon.jpg');">
                                <a href="productlist.aspx" target="main">商品列表</a></td>
                            <td style="text-align: center; background-image: url('Image/bannericon/greenicon.jpg');" 
                                class="style1"><a href="shoppingcart.aspx" target="main">购物车</a></td>
                            <td style="text-align: center; background-image: url('Image/bannericon/blueicon.jpg');" 
                                class="style2">
                            <a href="recharge.aspx" target="main">充值</a></td>
                            <td style="text-align: right;">
                                <span class="style3">呵呵欢迎您！</span>
                                <span class="style4">[</span><a href="PassWordChange.aspx" target="main"><span 
                                    class="style4">修改密码</span></a><span class="style4">]
                                [</span><a href="logout.aspx" target="main"><span class="style4">注销</span></a>]</td>
                        </tr>
                        
                    </table>

    </div>
    </form>
   
</body>
</html>
