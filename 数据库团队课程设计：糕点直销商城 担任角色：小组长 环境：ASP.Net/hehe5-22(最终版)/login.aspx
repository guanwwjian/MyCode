<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="login" %>

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
            width: 206px;
        }
        .auto-style3
        {
            height: 20px;
            width: 206px;
        }
        .auto-style4
        {
            width: 58px;
        }
        .auto-style5
        {
            height: 20px;
            width: 58px;
        }
        .style2
        {
            width: 118px;
        }
        .style4
        {
            width: 25px;
        }
        .style22
        {
            width: 25px;
            height: 27px;
        }
        .style34
        {
            height: 20px;
            width: 162px;
        }
        .style36
        {
            width: 118px;
            height: 27px;
        }
        .style37
        {
            width: 118px;
            height: 25px;
        }
        .style39
        {
            height: 25px;
        }
        .style40
        {
            height: 27px;
        }
        .style41
        {
            height: 20px;
            width: 48px;
        }
        .style42
        {
            height: 20px;
            width: 118px;
        }
        .style43
        {
            width: 162px;
            height: 27px;
        }
    </style>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
    <div style="height: 65px">
    
    </div>
        <table style="width: 240px; margin-bottom: 0px; height: 216px;" id="t1">
            <tr>
                <td class="style36" align="center" style="font-size: small">
                    <asp:Label ID="Label1" runat="server" Text="用户名"></asp:Label>
                </td>
                <td class="style22" colspan="2">
                    <asp:TextBox ID="TextBox1" runat="server" Width="150px" 
                        OnTextChanged="TextBox1_TextChanged"></asp:TextBox>
                </td>
                </td>
            </tr>
            <tr>
                <td class="style37" align="center" style="font-size: small">
                    <asp:Label ID="Label2" runat="server" Text="密码"></asp:Label>
                </td>
                   <td class="style39" colspan="2">
                    <asp:TextBox ID="TextBox2" runat="server" TextMode="Password" Width="150px"></asp:TextBox>
                    </td>
               
            </tr>
            <tr>
                <td class="style36" align="center" style="font-size: small">
                    <asp:Label ID="Label4" runat="server" Text="验证码"></asp:Label>
                    </td>
                <td class="style22">
                    <asp:TextBox ID="checktxt" runat="server" style="margin-left: 4px" Width="68px"></asp:TextBox>
                </td>
                <td class="style43">
                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="checkcode.aspx" OnClick="ImageButton1_Click" />
                    </td>
            </tr>
            <tr>
                <td class="style36" align="center" style="font-size: x-small"></td>
        <td class="style40">[<a href="register.aspx" target="iframepage" style="font-size: x-small">还没注册？</a>]</td>
        <td class="style43">[<a href="PassWordBack.aspx" target="iframepage" 
                        style="font-size: x-small">密码找回</a>]</td>
            </tr>
            <tr>
                <td class="style36" align="center" style="font-size: small">
                    &nbsp;</td>
                <td class="style40" colspan="2">
                    <asp:Label ID="Label3" runat="server" ForeColor="Red"></asp:Label>
                    </td>
            </tr>
            <tr>
                <td class="style42"></td>
                <td class="style41">
                    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="登录" 
                        Height="20px" Width="35px" />
                    </td>
                <td class="style34">
                    <asp:Button ID="Button2" runat="server" Text="重置" Height="20px" Width="35px" />
                    </td>
            </tr>
            <tr>
                <td class="style2">&nbsp;</td>
                <td class="style4" colspan="2">&nbsp;</td>
            </tr>
            <tr>
                <td class="style2">&nbsp;</td>
                <td class="style4" colspan="2">&nbsp;</td>
            </tr>
        </table>
    </form>
    <form id="form2" runat="server">
        <asp:Label ID="Label5" runat="server" Text="aaaaaaaa"></asp:Label>
    </form>
</body>
</html>
