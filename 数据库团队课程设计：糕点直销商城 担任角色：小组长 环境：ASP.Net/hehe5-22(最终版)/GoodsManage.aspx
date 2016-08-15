<%@ Page Language="C#" AutoEventWireup="true" CodeFile="GoodsManage.aspx.cs" Inherits="AdminManage_GoodsManage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>无标题页</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table style="width: 539px; font-size: 9pt; background-image: url('../Image/后台页.jpg');" 
            cellpadding="0" cellspacing="0" align="center" height="339">
            
            <tr>

                <td colspan="3" style="text-align: left">
                    <asp:Label ID="Label2" runat="server" Text="查询条件："></asp:Label>
                    <asp:DropDownList ID="ddlCondition" runat="server">
                        <asp:ListItem Value="pid">商品ID</asp:ListItem>
                        <asp:ListItem Value="pname">商品名称</asp:ListItem>
                        <asp:ListItem Value="tid">商品类别</asp:ListItem>
                        <asp:ListItem Value="stock">商品库存</asp:ListItem>
                        <asp:ListItem Value="price">商品价格</asp:ListItem>
                        <asp:ListItem Value="bought">商品销售额</asp:ListItem>
                    </asp:DropDownList>
                    
                    <asp:Label ID="Label1" runat="server" Text="关键字："></asp:Label>
                    <asp:TextBox ID="txtKey" runat="server"></asp:TextBox>
                    <asp:Button ID="btnSel" runat="server" Text="查询" Height="30px" Width="58px" OnClick="btnSel_Click" />
                    &nbsp;
                &nbsp;</td>
            </tr>
            <tr>
                <td colspan="3" style="height: 181px; text-align: center; vertical-align: top;">
                    <br />
                    <asp:GridView ID="gvGoodsInfo" runat="server" CellPadding="4" ForeColor="#333333" GridLines="None" AutoGenerateColumns="False" OnRowDataBound="gvGoodsInfo_RowDataBound" OnRowDeleting="gvGoodsInfo_RowDeleting" AllowPaging="True" PageSize="8" OnPageIndexChanging="gvGoodsInfo_PageIndexChanging" Font-Size="9pt" Width="477px" Height="83px">
                        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
                        <EditRowStyle BackColor="#999999" />
                        <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
                        <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
                        <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
                        <Columns>
                            <asp:BoundField DataField="pid" HeaderText="商品ID" />
                            <asp:BoundField DataField="pname" HeaderText="商品名称" />
                            <asp:BoundField DataField="tid" HeaderText="商品类别" />
                            <asp:BoundField DataField="price" HeaderText="商品价格" />
                            <asp:BoundField DataField="stock" HeaderText="商品库存" />
                            <asp:BoundField DataField="bought" HeaderText="商品销售额" />
                            <asp:CommandField ButtonType="Button" HeaderText="删除" ShowDeleteButton="True">
                                <ControlStyle Font-Underline="False" ForeColor="Black" />
                            </asp:CommandField>
                    <asp:TemplateField HeaderText="更新">
                    <ItemTemplate>
                    <asp:Button id="btnChangeDetails" runat="server" onclick="btnChangeDetails_OnClick" Text="修改"></asp:Button>
                    </ItemTemplate></asp:TemplateField>
                        </Columns>
                        <SortedAscendingCellStyle BackColor="#E9E7E2" />
                        <SortedAscendingHeaderStyle BackColor="#506C8C" />
                        <SortedDescendingCellStyle BackColor="#FFFDF8" />
                        <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
                    </asp:GridView>
                </td>
            </tr>
            <tr><td>                
            <asp:Button ID="Button1" runat="server" Text="添加商品" Height="30px" OnClick="ADD_Click"/>
                    </td></tr>
        </table>
    </div>
    </form>
</body>
</html>
