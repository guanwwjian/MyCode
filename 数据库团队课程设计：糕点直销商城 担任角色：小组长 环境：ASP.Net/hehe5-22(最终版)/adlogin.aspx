<%@ Page Language="C#" AutoEventWireup="true" CodeFile="adlogin.aspx.cs" Inherits="adlogin" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1
        {
            height: 20px;
        }
        .auto-style2
        {
            width: 170px;
        }
        .auto-style3
        {
            height: 20px;
            width: 170px;
        }
        .auto-style6
        {
            font-size: small;
        }
        .auto-style7
        {
            height: 20px;
            width: 66px;
        }
        .auto-style8
        {
            width: 66px;
        }
        .auto-style9 {
            height: 20px;
            width: 87px;
        }
        .auto-style10 {
            width: 87px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        请登录：<br />
    
    </div>
        <table style="width: 100%; margin-bottom: 0px;" id="t1">
            <tr>
                <td class="auto-style7"></td>
                <td class="auto-style9">
                    &nbsp;</td>
                <td class="auto-style3">
                    &nbsp;</td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
            </tr>
            <tr>
                <td class="auto-style8">&nbsp;</td>
                <td class="auto-style10">
                    <asp:Label ID="Label1" runat="server" Text="用户名"></asp:Label>
                </td>
                <td class="auto-style2">
                    <asp:TextBox ID="TextBox1" runat="server" Width="186px" style="margin-right: 65px"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style8">&nbsp;</td>
                <td class="auto-style10">
                    <asp:Label ID="Label2" runat="server" Text="密码"></asp:Label>
                </td>
                <td class="auto-style2">
                    <asp:TextBox ID="TextBox2" runat="server" TextMode="Password" Width="186px"></asp:TextBox>
                </td>
                <td class="auto-style6">
                    
                   </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style8">&nbsp;</td>
                <td class="auto-style10">
                    <asp:Label ID="Label4" runat="server" Text="验证码："></asp:Label>
                </td>
                <td class="auto-style2">
                    <asp:TextBox ID="TextBox3" runat="server" style="margin-top: 0px" Width="75px"></asp:TextBox>
                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="checkcode.aspx" OnClick="ImageButton1_Click" />

                </td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style8">&nbsp;</td>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style2">
                    <asp:Label ID="Label3" runat="server" ForeColor="Red"></asp:Label>
                </td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style8">&nbsp;</td>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style2">
                    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="登录" />
&nbsp;&nbsp;&nbsp;
                    <asp:Button ID="Button2" runat="server" Text="重置" />
                </td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
