<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AdchangePassword.cs" Inherits="AdchangePassword" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>管理员密码修改</title>
    <style type="text/css">
        .auto-style4
        {
            width: 313px;
            height: 36px;
        }
        .auto-style5
        {
            height: 48px;
            width: 313px;
        }
        .auto-style1
        {
            height: 48px;
            width: 120px;
        }
        .auto-style6
        {
            height: 49px;
            width: 313px;
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
        .style1
        {
            width: 313px;
            height: 38px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div style="margin-left: 75px">
            <table style="width: 68%; overflow: auto; margin-left: 0px; margin-top: 0px;">
                <caption >
                    管理员密码修改
                </caption>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="username" runat="server" Text="请输入您的名字:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="anametxt" runat="server" Style="margin-left: 16px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="oldpwdlbl" runat="server" Text="请输入原密码:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="oldpwdtxt" runat="server" TextMode="Password"
                            Style="margin-left: 16px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="newpwdlbl" runat="server" Text="请输入新密码:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="newpwdtxt" runat="server" TextMode="Password"
                            Style="margin-left: 16px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="cnewpwdlbl" runat="server" Text="请确认新密码:"></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="cnewpwdtxt" runat="server" TextMode="Password"
                            Style="margin-left: 16px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Button ID="subbtn" runat="server" OnClick="subbtn_Click" Text="提交"
                               Font-Names="宋体" Height="29px" Width="115px"  />
                    </td>
                </tr>
            </table>
        </div>
        <p style="margin-left: 280px">
            
        </p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 440px">
            &nbsp;</p>
    </form>
</body>
</html>
