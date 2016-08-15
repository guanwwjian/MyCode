<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AddAdmin.aspx.cs" Inherits="AdminManage_EditAdmin" Debug="true" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

    protected void Page_Load(object sender, EventArgs e)
    {

    }
</script>


<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>无标题页</title>
    <style type="text/css">
        .auto-style4
        {
            width: 313px;
            height: 36px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div style="margin-left: 75px">
            <table style="width: 68%; overflow: auto; margin-left: 0px; margin-top: 0px;">
                <caption >
                    添加管理员
                </caption>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="username" runat="server" Text="管理员姓名："></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtAName" runat="server"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="oldpwdlbl" runat="server" Text="管理员密码：" ></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtAPwd" runat="server" TextMode="Password"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Label ID="newpwdlbl" runat="server" Text="管理员级别："></asp:Label>
                    </td>
                    <td>
                        <asp:TextBox ID="txtARank" runat="server"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style4" colspan="4">
                        <asp:Button ID="btnAdd" runat="server" Text="添加" OnClick="btnAdd_Click"
                            Font-Names="宋体" Height="29px" Width="100px" />
                    </td>
                    <td class="auto-style4" colspan="4">
                        <asp:Button ID="btnBack" runat="server" OnClick="btnBack_Click" Text="返回" 
                            Font-Names="宋体" Height="29px" Width="100px"/>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
