<%@ Page Language="C#" AutoEventWireup="true" CodeFile="menu1.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style2
        {
            width: 100px;
        }
        .style1
        {
            width: 77px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
                    <table style="width:100%; height: 50px; ">
                        <tr>                           
                            <td style="text-align: center; background-image: url('Image/bannericon/redicon.jpg');" 
                                class="style1">
                                <a href="onsales.aspx" target="main">首页</a> </td>
                            <td style="text-align: center; background-image: url('Image/bannericon/yellowicon.jpg');" 
                                class="style1">
                                <a href="productlist.aspx" target="main">商品列表</a> </td>
                            <td style="text-align: right; font-size: small;">
                                [<a href="login.aspx" target="main">登陆</a>]
                                [<a href="register.aspx" target="main">注册</a>]</td>
                        </tr>
                        
                    </table>
    
    </div>
    </form>
</body>
</html>
