<%@ Page Language="C#" AutoEventWireup="true" CodeFile="assess.aspx.cs" Inherits="assess1" %><%@ Register assembly="System.Web.DataVisualization, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35" namespace="System.Web.UI.DataVisualization.Charting" tagprefix="asp" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style3
        {
            width: 168px;
        }
        .auto-style5
        {
            width: 442px;
        }
        .auto-style6
        {
            width: 188px;
        }
        .auto-style7
        {
            width: 188px;
            height: 23px;
        }
        .auto-style8
        {
            width: 168px;
            height: 23px;
        }
        .auto-style9
        {
            width: 442px;
            height: 23px;
        }
    </style>
</head>
<body style="margin-left: 247px">
    <form id="form1" runat="server">
    <div style="margin-left: 0px">
    
        <br />
        <br />
        <br />
        <br />
    
    </div>
        <table style="width: 52%; margin-left: 0px;">
            <caption style="width: 204px">
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 商品评价<br />
                <br />
            </caption>
            <tr>
                <td class="auto-style7">
                    <asp:Label ID="assesslbl" runat="server" Text="请输入您的评价:"></asp:Label>
                </td>
                <td class="auto-style8">
                    <asp:TextBox ID="assesstxt" runat="server" Width="97px"></asp:TextBox>
                </td>
                <td class="auto-style9">
                    <asp:Label ID="alertlbl" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style6">&nbsp;</td>
                <td class="auto-style3">
                    <asp:Button ID="subbtn" runat="server" OnClick="subbtn_Click" 
                        style="margin-left: 68px" Text="提交" />
                </td>
                <td class="auto-style5">&nbsp;</td>
            </tr>
        </table>
        <p>
            &nbsp;</p>
    </form>
</body>
</html>
