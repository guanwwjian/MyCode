<%@ Page Language="C#" AutoEventWireup="true" CodeFile="register.aspx.cs" Inherits="register" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">

        .auto-style6
        {
            height: 49px;
            width: 313px;
        }
        .auto-style4
        {
            width: 313px;
            height: 36px;
        }
        .auto-style7
        {
            width: 313px;
            height: 38px;
        }
        .auto-style8
        {
            width: 313px;
            height: 37px;
        }
        .auto-style5
        {
            height: 48px;
            width: 313px;
        }
        .auto-style9
        {
            width: 313px;
            height: 11px;
        }
        .auto-style10
        {
            height: 48px;
        }
        .auto-style11
        {
            height: 48px;
            width: 236px;
        }
        .style1
        {
            height: 48px;
            width: 203px;
        }
        .style2
        {
            width: 313px;
            height: 16px;
        }
        .style3
        {
            width: 313px;
            height: 41px;
        }
    </style>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
    <div>
    
    </div>
            <table style="width: 68%; overflow: auto; margin-left: 120px; margin-top: 0px;">
                <caption style="width: 210px">
                    新用户注册<br />
&nbsp;&nbsp;&nbsp;
                </caption>
                <tr>
                    <td class="auto-style6" colspan="2">
            <asp:Label ID="username" runat="server" Text="请输入用户名:"></asp:Label>
                    </td>
                    <td class="auto-style6" colspan="3">
            <asp:TextBox ID="unametxt" runat="server" Width="148px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style6" colspan="2">
                        <asp:Label ID="Label2" runat="server" Text="请输入邮箱："></asp:Label>
                    </td>
                    <td class="auto-style6" colspan="3">
                        <asp:TextBox ID="emailtxt" runat="server"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="style3" colspan="2">
            <asp:Label ID="oldpwdlbl" runat="server" Text="请输入安全码:"></asp:Label>
                    </td>
                    <td class="auto-style4" colspan="3" rowspan="2">
            <asp:TextBox ID="sfcdtxt" runat="server" Width="148px" TextMode="Password" 
                style="margin-left: 1px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="style2" colspan="2">
                        <asp:Label ID="Label1" runat="server" Text="(用于找回密码）"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style7" colspan="2">
                        <asp:Label ID="cfsfcdlbl" runat="server" Text="请确认安全码："></asp:Label>
                    </td>
                    <td class="auto-style7" colspan="3">
                        <asp:TextBox ID="cfsfcdtxt" runat="server" TextMode="Password"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style7" colspan="2">
            <asp:Label ID="newpwdlbl" runat="server" Text="请输入密码:"></asp:Label>
                    </td>
                    <td class="auto-style7" colspan="3">
            <asp:TextBox ID="pwdtxt" runat="server" Width="148px" TextMode="Password" 
                style="margin-left: 0px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style8" colspan="2">
            <asp:Label ID="cnewpwdlbl" runat="server" Text="请确认密码:"></asp:Label>
                    </td>
                    <td class="auto-style8" colspan="3">
            <asp:TextBox ID="cfpwdtxt" runat="server" Width="148px" TextMode="Password" 
                style="margin-left: 1px" Height="16px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style8" colspan="2">
                        <asp:Label ID="Label3" runat="server" Text="请输入验证码："></asp:Label>
                    </td>
                    <td class="auto-style8" colspan="3">
                        <asp:TextBox ID="checktxt" runat="server"></asp:TextBox>
                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="checkcode.aspx" OnClick="ImageButton1_Click" />

                    </td>
                </tr>
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="style1">
                        &nbsp;</td>
                    <td class="auto-style5">
            <asp:Button ID="regbtn" runat="server" OnClick="subbtn_Click" Text="注册" 
                Width="81px" Font-Bold="False" Font-Italic="False" Font-Names="宋体" 
                ForeColor="Blue" />
                    </td>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style11">&nbsp;</td>
                </tr>
            </table>
    </form>
</body>
</html>
