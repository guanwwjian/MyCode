<%@ Page Language="C#" AutoEventWireup="true" CodeFile="myorders.aspx.cs" Inherits="myorders" Debug="true"%>
<%@ Import Namespace="System.Data" %>
<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        #form1
        {
            color: #3366FF;
            background-color: #9999FF;
        }
        .auto-style1
        {
            width: 100%;
            height: 74px;
        }
        .auto-style2
        {
            width: 250px;
        }
        </style>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <table class="auto-style1">
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td>
        <asp:DataList ID="DataList_Orders" runat="server" BackColor="White" BorderColor="#999999" BorderStyle="None" BorderWidth="1px" CellPadding="3" GridLines="Both" Height="100px" OnSelectedIndexChanged="DataList_Orders_SelectedIndexChanged">
            <AlternatingItemStyle BackColor="#DCDCDC"></AlternatingItemStyle>

            <FooterStyle BackColor="#CCCCCC" ForeColor="Black"></FooterStyle>

            <HeaderStyle BackColor="#000084" Font-Bold="True" ForeColor="White"></HeaderStyle>

            <ItemStyle BackColor="#EEEEEE" ForeColor="Black"></ItemStyle>

            <SelectedItemStyle BackColor="#008A8C" Font-Bold="True" ForeColor="White"></SelectedItemStyle>
            <ItemTemplate>
                <p>产品编号:<%# DataBinder.Eval(Container.DataItem, "pid")%></p>
                <p>订单编号:<%# DataBinder.Eval(Container.DataItem, "oid")%></p>
                <p>订单日期:<%# DataBinder.Eval(Container.DataItem, "date")%></p>
                <p>购买数量:<%# DataBinder.Eval(Container.DataItem, "count")%></p>
                <p>物品单价:<%# DataBinder.Eval(Container.DataItem,"price") %></p>
                <p>产品:<%# DataBinder.Eval(Container.DataItem,"pname") %></p>
                <p>产品介绍:<%# DataBinder.Eval(Container.DataItem, "introduce")%></p>
                <p>订单状态:<%# DataBinder.Eval(Container.DataItem,"status") %></p>

                
                    <asp:Image id="image1" runat="server" ImageUrl='<%# DataBinder.Eval(Container.DataItem,"picurl") %>' />
                </p>
            </ItemTemplate>
        </asp:DataList>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td>
                    <asp:DataList ID="DataList1" runat="server">
                    </asp:DataList>
                </td>
            </tr>
        </table>
        <br />
        </form>
</body>
</html>
