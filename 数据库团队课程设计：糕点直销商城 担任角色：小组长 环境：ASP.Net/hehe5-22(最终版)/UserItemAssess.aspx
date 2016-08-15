<%@ Page Language="C#" AutoEventWireup="true" CodeFile="UserItemAssess.aspx.cs" Inherits="UserItemAssess" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        #taUserItemAssess {
            height: 125px;
        }
        .auto-style1 {
            height: 36px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table >
            <tr>
                <td style="text-align:center">
                    评价商品
                </td>
            </tr>
            <tr>
                <td>
                    <asp:DataList ID="dlUserItemAssess" runat="server" OnItemCommand="dlUserItemAssess_ItemCommand" 
                        DataKeyField="订单编号" CellPadding="4" ForeColor="#333333">
                        <AlternatingItemStyle BackColor="White" ForeColor="#284775" />
                        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <ItemStyle BackColor="#F7F6F3" ForeColor="#333333" />
                        <ItemTemplate>
                            <table style="width: auto">
                                <tr style="border-bottom: thin">
                                    <td>订单编号：
                                <asp:Label ID="lblOid" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "订单编号") %>'></asp:Label>
                                    </td>
                                    <td>产品编号：
                                <asp:Label ID="lblPid" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "产品编号") %>'></asp:Label>
                                    </td>
                                </tr>
                                <tr>
                                    <td rowspan="3">
                                        <asp:ImageButton ID="imgbtnShoppingCart" runat="server" Width="180px" Height="180"
                                            ImageUrl='<%# DataBinder.Eval(Container.DataItem, "产品图片") %>'
                                            CommandName="imgbtnLinktoProduct" ImageAlign="Left" ToolTip="查看商品详情" />
                                        <%--<asp:Image ID="imgShoppingCart" runat="server"
                                            Width="80px" Height="80px"
                                            ImageUrl='<%# DataBinder.Eval(Container.DataItem, "产品图片") %>' />--%>
                                    </td>
                                    <td rowspan="2">
                                        <asp:LinkButton ID="lbtnProduct" runat="server"
                                            CommandName="linktoProduct"
                                            Text='<%# DataBinder.Eval(Container.DataItem, "产品名称") %>'></asp:LinkButton>
                                    </td>
                                    <td>单价： 
                                    </td>
                                    <td>
                                        <asp:Label ID="lblPrice" runat="server"
                                            Text='<%# DataBinder.Eval(Container.DataItem, "单价") %>'></asp:Label>
                                    </td>


                                </tr>
                                <tr>
                                    <td>数量：
                                    </td>
                                    <td>
                                        <asp:Label ID="lblCount" runat="server"
                                            Text='<%# DataBinder.Eval(Container.DataItem, "数量") %>'></asp:Label>
                                    </td>
                                </tr>
                                <tr>
                                    <td></td>
                                    <td>小计：
                                    </td>
                                    <td>
                                        <asp:Label ID="lblTotal" runat="server"
                                            Text='<%# DataBinder.Eval(Container.DataItem, "小计") %>'></asp:Label>
                                    </td>
                                </tr>
                                <tr>
                                    <td colspan="4">
                                        <asp:TextBox ID="tbUserItemAssess" runat="server" ToolTip="请输入您的评价"
                                            Height="114px" MaxLength="250" TextMode="MultiLine" Width="460px"></asp:TextBox>
                                        &nbsp;</td>
                                    
                                </tr>
                                <%--<tr>
                                    <td>
                                        <asp:RequiredFieldValidator ID="rfvAssess" runat="server"
                                            ControlToValidate="tbUserItemAssess"
                                            ErrorMessage="评价不能为空0.0"></asp:RequiredFieldValidator>
                                    </td>
                                </tr>--%>
                                
                                <tr>
                                    <td>
                                        <asp:Button ID="btnAssess" runat="server" CommandName="btnAssess" Text="提交评价" />
                                    </td>
                                </tr>
                            </table>
                        </ItemTemplate>
                        <SelectedItemStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
                    </asp:DataList>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
