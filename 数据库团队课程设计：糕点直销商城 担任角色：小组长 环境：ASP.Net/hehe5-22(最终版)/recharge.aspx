﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="recharge.aspx.cs" Inherits="_recharge" 
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>无标题页</title>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
    <div>
        <table style="font-size: 9pt; background-image: url(../Image/后台页.jpg);" cellpadding="0" cellspacing="0" align="center" height="339" width="515">
            <tr>
                <td style="text-align: center" rowspan="4" colspan="3">
                    <table style="height: 112px; font-size: 9pt;"  cellpadding="0" cellspacing="0">
                        <tr>
                            <td style="width: 74px">
                                充值卡号码：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtcode" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td style="width: 74px">
                    充值卡密码：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtpassword" runat="server" TextMode="Password"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td style="width: 74px">
                                充值卡金额：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtmoney" runat="server"></asp:TextBox></td>
                        </tr>
                    </table><br />
                    <asp:Button ID="btnAdd" runat="server" Text="充值" OnClick="btnAdd_Click" />
                    &nbsp;&nbsp;
                    <asp:Button ID="btnBack" runat="server" OnClick="btnBack_Click" Text="返回" /></td>
            </tr>
             <tr>
            </tr>
            <tr>
            </tr>
             <tr>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
