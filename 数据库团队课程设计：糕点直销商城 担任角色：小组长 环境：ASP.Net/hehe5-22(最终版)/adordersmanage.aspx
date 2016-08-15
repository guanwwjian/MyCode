<%@ Page Language="C#" AutoEventWireup="true" CodeFile="adordersmanage.aspx.cs" Inherits="adordersmanage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            width: 252px;
        }
        .auto-style3 {
            width: 252px;
            height: 23px;
        }
        .auto-style4 {
            height: 23px;
        }
        .auto-style5 {
            width: 104px;
        }
        .auto-style6 {
            width: 282px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table class="auto-style1">
            <tr>
                <td class="auto-style5">
                    <asp:DropDownList ID="DropDownList1" runat="server" Style="margin-left: 2px" AutoPostBack="True" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
                    </asp:DropDownList>
                </td>
                <td class="auto-style6">
                    <asp:TextBox ID="txtInput" runat="server" Style="margin-left: 25px"
                        Width="193px"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="btnSelectRecords" runat="server"
                        Text="搜索" OnClick="btnSelectRecords_Click" Width="66px" />
                </td>
            </tr>
        </table>
        &nbsp;&nbsp;&nbsp;&nbsp;<br />
        <br />
        <panel width="100px" height="100px">
        <Scroller width="100%" height="100%">
        <asp:GridView ID="GridView_UserOrders" runat="server"
            CellPadding="4" ForeColor="#333333" GridLines="None" 
            OnRowDeleting="GridView_UserOrders_RowDeleting" 
            OnRowDataBound="GridView_UserOrders_RowDataBound" 
            style="text-align:center"
            >
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:CommandField HeaderText="删除" ShowDeleteButton="True" ButtonType="Button">
                        <ControlStyle Font-Underline="False" ForeColor="Black" />
                    </asp:CommandField>
                    <asp:TemplateField HeaderText="发货">
                    <ItemTemplate>
                    <asp:Button id="btnChangeStatus" runat="server" onclick="btnChangeStatus_OnClick" Text=""></asp:Button>
                    </ItemTemplate></asp:TemplateField>
            </Columns>
            <EditRowStyle BackColor="#999999" />
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#E9E7E2" />
            <SortedAscendingHeaderStyle BackColor="#506C8C" />
            <SortedDescendingCellStyle BackColor="#FFFDF8" />
            <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
        </asp:GridView>
        </Scroller>
        </panel>
    
        <br />
    
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    
        <br />
        <br />
        <br />
    
    </div>
    </form>
</body>
</html>
