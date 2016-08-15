<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Editadjustment.aspx.cs" Inherits="Editadjustment"  Debug="true"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>无标题页</title>
    <style type="text/css">
        .auto-style3
        {
            width: 74px;
            height: 51px;
        }
        .auto-style4
        {
            width: 173px;
            height: 51px;
        }
        .auto-style5
        {
            width: 74px;
            height: 48px;
        }
        .auto-style6
        {
            width: 173px;
            height: 48px;
        }
        .auto-style15
        {
            width: 74px;
            height: 43px;
        }
        .auto-style16
        {
            width: 173px;
            height: 43px;
        }
        .auto-style17
        {
            width: 74px;
            height: 45px;
        }
        .auto-style18
        {
            width: 173px;
            height: 45px;
        }
        .auto-style19
        {
            width: 173px;
        }
        .style1
        {
            width: 160px;
            height: 48px;
        }
        .style2
        {
            width: 160px;
            height: 51px;
        }
        .style3
        {
            width: 160px;
            height: 43px;
        }
        .style4
        {
            width: 160px;
            height: 45px;
        }
        .style5
        {
            width: 160px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table style="font-size: 9pt; background-image: url(../Image/后台页.jpg);" cellpadding="0" cellspacing="0" align="center" height="339" width="515">
            <tr>
                <td style="text-align: center" colspan="3">
                    <table style="height: 282px; font-size: 9pt; width: 243px;"  cellpadding="0" 
                        cellspacing="0">
                        <tr>
                            <td class="style1">
                                广告名：</td>
                            <td class="auto-style6">
                                <asp:TextBox ID="txtname" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td class="style2">
                                广告地址：</td>
                            <td class="auto-style4">
                                <asp:TextBox ID="txturl" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td class="style3">
                                宽：</td>
                            <td class="auto-style16">
                                <asp:TextBox ID="txtwidth" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td class="style4">
                                高：</td>
                            <td class="auto-style18">
                                <asp:TextBox ID="txtheight" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td class="style2">
                                x坐标：</td>
                            <td class="auto-style4">
                                <asp:TextBox ID="txtx" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td class="style5">
                                y坐标：</td>
                            <td class="auto-style19">
                                <asp:TextBox ID="txty" runat="server" style="margin-top: 0px"></asp:TextBox></td>
                        </tr>
                    </table><br />
                    <asp:Button ID="btnAddadv" runat="server" Text="添加" OnClick="btnAdd_Click" />
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
