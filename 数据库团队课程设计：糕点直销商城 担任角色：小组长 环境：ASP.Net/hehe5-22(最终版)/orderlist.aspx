<%@ Page Language="C#" AutoEventWireup="true" CodeFile="orderlist.aspx.cs" Inherits="UserCenter_orderlist" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body style="background-color:transparent">
    <form id="orderlist" runat="server">
    <div>
    <asp:Label ID="lblUserInput" runat="server" Text="订单筛选:"></asp:Label>
        <asp:DropDownList ID="DropDownList1" runat="server" style="margin-left: 2px" AutoPostBack="True" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
        </asp:DropDownList>
        <br />
        <br />
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<%--<asp:Button ID="btnSelectRecords" runat="server" 
            Text="搜索" onclick="btnSelectRecords_Click" Width="66px" />--%>
        <br />
    <asp:Label ID="lblNoneShoppinglist" runat="server" Visible="False">标签 为空时提示</asp:Label>
    <asp:DataList ID="dlShoppingCart" runat="server"
                 DataKeyField="订单编号" Caption="订单列表"
                 Font-Size="Large" CellPadding="4" ForeColor="#333333" 
            onitemcommand="dlShoppingCart_ItemCommand" onitemdatabound="dlShoppingCart_ItemDataBound"
                 >
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
                            <td>&nbsp&nbsp 产品编号：
                                <asp:Label ID="lblPid" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "产品编号") %>'></asp:Label>
                            </td>
                                                        <td>&nbsp&nbsp 订单状态：
                                <asp:Label ID="Label1" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "订单状态") %>'></asp:Label>
                            </td>
                                                        
                        </tr>
                        
                        <tr>
                            <td rowspan="3">
                                <asp:Image ID="imgShoppingCart" runat="server"
                                     Width="80px" Height="80px"
                                    ImageUrl='<%# DataBinder.Eval(Container.DataItem, "产品图片") %>' />
                            </td>
                            <td rowspan="2">
                                <asp:LinkButton ID="lbtnProduct" runat="server"
                                    CommandName="linktoProduct"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "产品名称") %>'></asp:LinkButton>

                            </td>
                            
                            <td>单价： 

                                <asp:Label ID="lblPrice" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "单价") %>'></asp:Label>
                            </td>

                        </tr>
                        <tr>
                            <td>数量：

                                <asp:Label ID="lblCount" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "数量") %>'></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td></td>
                            <td >小计：

                                <asp:Label ID="lblTotal" runat="server"
                                    Text='<%# DataBinder.Eval(Container.DataItem, "小计") %>'></asp:Label>
                            </td>
                            <td style="width:50px;">
                                <asp:Button ID="btnOperate" runat="server" CommandName="btnOperate" 
                                    Text='<%# DataBinder.Eval(Container.DataItem, "按钮") %>'
                                     />
                            </td>
                        </tr>
                    </table>
                    <hr/>
                </ItemTemplate>
                <SelectedItemStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            </asp:DataList>
            <br />
            <table >
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
                        <asp:LinkButton ID="lnkbtnNext" runat="server" OnClick="lnkbtnNext_Click">下一页</asp:LinkButton>
                    </td>
                    <td>
                        <asp:LinkButton ID="lnkbtnLast" runat="server" OnClick="lnkbtnLast_Click">尾页</asp:LinkButton>
                    </td>
                </tr>
            </table>
    </div>

    </form>
</body>
</html>
