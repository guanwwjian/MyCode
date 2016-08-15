<%@ Page Language="C#" AutoEventWireup="true" CodeFile="shoppingcart.aspx.cs" Inherits="shoppingcart" %>

<!DOCTYPE html
PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    </head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
        <div>
       
            <asp:Label ID="lblNoneShoppinglist" runat="server" Visible="False">HeHe~</asp:Label>
            <asp:DataList ID="dlShoppingCart" runat="server" OnItemCommand="dlShoppingCart_ItemCommand"
                 DataKeyField="订单编号" OnDeleteCommand="dlShoppingCart_DeleteCommand"  Caption="我的购物车" 
                 Font-Size="Large" CellPadding="4" ForeColor="#333333" >
                <AlternatingItemStyle BackColor="White" ForeColor="#284775" />
                <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                <ItemStyle BackColor="#F7F6F3" ForeColor="#333333" />
                <ItemTemplate>
                    <table width="100%">
                        <tr style="border-bottom:thick">
                            <td> 订单编号：
                                <asp:Label ID="lblOid" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "订单编号") %>'></asp:Label>
                            </td>
                            <td>&nbsp&nbsp&nbsp&nbsp 产品编号：
                                <asp:Label ID="lblPid" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "产品编号") %>'></asp:Label>
                            </td>     
                        </tr>
                        <tr>
                            <td rowspan="3">
                                <asp:ImageButton id="imgbtnShoppingCart"  runat="server" Width="80px" Height="80"
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
                            <td rowspan="3">
                                <asp:Button ID="btnDelete" runat="server" CommandName="btnDelete"
                                     Text="删除" OnClientClick="return confirm('确认要删除这条订单吗？')" 
                                    />
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
                    </table>
                    <hr/>
                </ItemTemplate>
                <SelectedItemStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            </asp:DataList>
            <br />
            <table>
                <tr>
                    <td>共有</td>
                    <td>
                        <asp:Label ID="lblCount" runat="server"  ></asp:Label>
                    </td>
                    <td>页</td>
                    <td>当前第</td>
                    <td>
                        <asp:Label ID="lblNowPage" runat="server" Text="1"></asp:Label>
                    </td>
                    <td>页</td>
                    <td>
                        <asp:LinkButton ID="lnkbtnFirst" runat="server" OnClick="lnkbtnFirst_Click">首页</asp:LinkButton>
                    </td>
                    <td>
                        <asp:LinkButton ID="lnkbtnFront" runat="server" OnClick="lnkbtnFront_Click" >上一页</asp:LinkButton>
                    </td>
                    <td>
                        <asp:LinkButton ID="lnkbtnNext" runat="server" OnClick="lnkbtnNext_Click" 
                             >下一页</asp:LinkButton>
                    </td>
                    <td>
                        <asp:LinkButton ID="lnkbtnLast" runat="server" OnClick="lnkbtnLast_Click">尾页</asp:LinkButton>
                    </td>
                </tr>
            </table>
            <table>
                <tr>
                    <td>
                         <asp:Button ID="Button1" runat="server"  Text="去商品页看看"
                                Width="120px" Height="30px" OnClick="Button1_Click" Visible="False" />
                    </td>
                </tr>
                <tr>
                    <td>
                         <asp:Button ID="Button2" runat="server"  Text="确认购买" 
                              Width="120px" Height="30px" OnClick="Button2_Click"  
                             BackColor="#ff9999" ToolTip="去结算喽~"
                             OnClientClick="return confirm('您是否确认购买？')"/>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
