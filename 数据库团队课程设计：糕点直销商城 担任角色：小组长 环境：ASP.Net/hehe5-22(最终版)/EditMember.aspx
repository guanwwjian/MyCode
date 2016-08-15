<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EditMember.aspx.cs" Inherits="AdminManage_EditMember"  Debug="true"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>无标题页</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table style="font-size: 9pt; background-image: url(../Image/后台页.jpg);" cellpadding="0" cellspacing="0" align="center" height="339" width="515">
            <tr>
                <td style="text-align: center" colspan="3">
                    <table style="height: 112px; font-size: 9pt; width: 246px;"  cellpadding="0" 
                        cellspacing="0">
                        <tr>
                            <td style="width: 74px">
                                会员登录名：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtLoginName" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td style="width: 74px">
                                会员密码：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtPwd" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td style="width: 74px">
                                会员安全码：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtQuePwd" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td style="width: 74px">
                                会员余额：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtMoney" runat="server"></asp:TextBox></td>
                        </tr>
                    </table><br />
                    <asp:Button ID="btnAddM" runat="server" Text="添加" OnClick="btnAdd_Click" />
                    &nbsp;&nbsp;
                    <asp:Button ID="btnModify" runat="server" Text="修改" OnClick="btnModify_Click" />
                    &nbsp;&nbsp;
                    <asp:Button ID="btnCancel" runat="server" OnClick="btnCancel_Click" Text="返回" /></td>
            </tr>
            </table>
    
    </div>
    </form>
</body>
</html>
