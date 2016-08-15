<%@ Page Language="C#" AutoEventWireup="true" CodeFile="PassWordChange.aspx.cs" Inherits="PassWordChange" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>密码修改</title>
    <style type="text/css">

        .auto-style3
        {
            width: 361px;
        }
        .auto-style4
        {
            height: 47px;
            width: 361px;
        }
        .auto-style5
        {
            height: 42px;
            width: 361px;
        }
        .auto-style7
        {
            width: 201px;
        }
        .auto-style8
        {
            width: 22px;
        }
    </style>
</head>
<body style="margin-left: 3px;style="background-color:transparent">
    <form id="form1" runat="server">
        <div style="margin-left: 75px">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <br />
            <br />
            <br />
            <br />
            <br />
&nbsp;&nbsp;&nbsp;
            <br />
        <table style="width: 97%; height: 192px;">
            <caption style="width: 197px">
                用户密码修改<br />
                <br />
            </caption>
            <tr>
                <td class="auto-style4" colspan="4">
            <asp:Label ID="oldpwdlbl" runat="server" Text="请输入原密码:"></asp:Label>
            <asp:TextBox ID="oldpwdtxt" runat="server" Width="150px" TextMode="Password"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style3" colspan="4">
            <asp:Label ID="newpwdlbl" runat="server" Text="请输入新密码:"></asp:Label>
            <asp:TextBox ID="newpwdtxt" runat="server" Width="148px" TextMode="Password"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style5" colspan="4">
            <asp:Label ID="cnewpwdlbl" runat="server" Text="请确认新密码:"></asp:Label>
            <asp:TextBox ID="cnewpwdtxt" runat="server" Width="148px" TextMode="Password"></asp:TextBox>
                    <br />
                    <br />
                </td>
            </tr>
            <tr>
                <td class="auto-style7">&nbsp;</td>
                <td class="auto-style8">
            <asp:Button ID="subbtn" runat="server" OnClick="subbtn_Click" Text="修改" 
                Width="81px" Font-Bold="False" Font-Italic="False" Font-Names="宋体" 
                ForeColor="Black" style="margin-left: 0px" />
                </td>
                <td>
                    &nbsp;</td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td colspan="4">
                    &nbsp;</td>
            </tr>
        </table>
            <br />
            <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </div>
        <p style="margin-left: 286px">
            &nbsp;</p>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 280px">
            &nbsp;</p>
        <p style="margin-left: 480px">
            &nbsp;</p>
    </form>
</body>
</html>
