<%@ Page Language="C#" AutoEventWireup="true" CodeFile="PassWordBack.cs" Inherits="PassWordBack" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>密码找回</title>
    <style type="text/css">
        .auto-style9 {
            width: 60%;
            height: 147px;
        }
        .auto-style16 {
            width: 153px;
        }
        .auto-style17 {
            height: 20px;
            width: 153px;
        }
        .auto-style18 {
            width: 138px;
        }
        .auto-style20 {
            width: 145px;
        }
        .auto-style21 {
            height: 20px;
            width: 145px;
        }
        .auto-style22 {
            width: 153px;
            height: 25px;
        }
        .auto-style23 {
            width: 138px;
            height: 25px;
        }
    </style>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
        <p style="margin-left: 200px; width: 111px;">
            <asp:Label ID="Label1" runat="server" Text="用户密码找回"></asp:Label>
        </p>
        <table class="auto-style9">
            <tr>
                <td class="auto-style21">
                    <asp:Label ID="Label4" runat="server" Text="请输入用户名："></asp:Label>
                </td>
                <td class="auto-style16"><asp:TextBox ID="unametxt" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style21">
            <asp:Label ID="Label3" runat="server" Text="注册时所用邮箱："></asp:Label>
                </td>
                <td class="auto-style16">
                    <asp:TextBox ID="emailtxt" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style21">

                    <asp:Label ID="Label5" runat="server" Text="请输入验证码："></asp:Label>

                </td>
                <td class="auto-style16">

                    <asp:TextBox ID="checktxt" runat="server"></asp:TextBox>

                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="checkcode.aspx" OnClick="ImageButton1_Click" />
                </td>
            </tr>
            <tr>
                <td class="auto-style21">
            <asp:Button ID="emailbtn" runat="server" OnClick="emailbtn_Click" Text="使用邮箱找回" Width="118px" />
                </td>
                <td class="auto-style16">
                    <asp:Label ID="Label" runat="server" ForeColor="Red"></asp:Label>
                </td>
            </tr>
            
        </table>
    </form>
</body>
</html>
