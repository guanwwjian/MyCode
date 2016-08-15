<%@ Page Language="C#" AutoEventWireup="true" CodeFile="product.aspx.cs" EnableEventValidation="true" Inherits="productlist" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1
        {
            width: 100%;
            height: 222px;
        }
        .auto-style2
        {
            width: 118px;
            height: 131px;
        }
        .auto-style4
        {
            width: 99%;
        }
        .auto-style11
        {
            width: 43px;
            height: 20px;
        }
        .auto-style15
        {
            width: 81px;
        }
        .auto-style16
        {
            width: 81px;
            height: 20px;
        }
        .auto-style17
        {
            width: 43px;
        }
        .auto-style18
        {
            width: 89px;
        }
        .auto-style19
        {
            width: 89px;
            height: 20px;
        }
        .auto-style20
        {
            height: 131px;
            width: 234px;
        }
        .auto-style21
        {
            width: 81px;
            height: 26px;
        }
        .auto-style22
        {
            width: 43px;
            height: 26px;
        }
        .auto-style23
        {
            width: 89px;
            height: 26px;
        }
        .style1
        {
            width: 88px;
        }
        .style2
        {
            width: 88px;
            height: 20px;
        }
        .style3
        {
            width: 88px;
            height: 26px;
        }
        #form1
        {
            height: 1777px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
        <asp:DataList ID="DataList1" runat="server" BackColor="#DEBA84" BorderColor="#DEBA84" BorderStyle="None" BorderWidth="1px" CellPadding="3" CellSpacing="2" GridLines="Both" DataKeyField="pid" OnItemCommand="DataList1_ItemCommand">
            <FooterStyle BackColor="#F7DFB5" ForeColor="#8C4510" />
            <HeaderStyle BackColor="#A55129" Font-Bold="True" ForeColor="White" />
            <ItemStyle BackColor="#FFF7E7" ForeColor="#8C4510" />
            <ItemTemplate>
                <table class="auto-style1">
                    <tr>
                        <td class="auto-style2">
                            <asp:Image ID="Image1" runat="server" Height="227px" Width="172px" 
                                ImageUrl='<%# DataBinder.Eval(Container.DataItem,"picurl") %>' />
                        </td>
                        <td class="auto-style20">
                            <table class="auto-style4">
                                <tr>
                                    <td class="auto-style15">
                                        <asp:Label ID="Label1" runat="server" Text="商品名称："></asp:Label>
                                    </td>
                                    <td class="auto-style17">
                                        <asp:Label ID="Label6" runat="server" Text='<%# DataBinder.Eval(Container.DataItem,"pname") %>'></asp:Label>
                                    </td>
                                    <td class="auto-style18">
                                        <asp:Label ID="Label11" runat="server" Text="购买数量："></asp:Label>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="auto-style16">
                                        <asp:Label ID="Label2" runat="server" Text="库存："></asp:Label>
                                    </td>
                                    <td class="auto-style11">
                                        <asp:Label ID="Label7" runat="server" Text='<%# DataBinder.Eval(Container.DataItem,"stock") %>'></asp:Label>
                                    </td>
                                    <td class="auto-style19">
                                        <asp:TextBox ID="TextBox1" runat="server" Height="16px" Width="74px">1</asp:TextBox>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="auto-style21">
                                        <asp:Label ID="Label3" runat="server" Text="已售出："></asp:Label>
                                    </td>
                                    <td class="auto-style22">
                                        <asp:Label ID="Label8" runat="server" Text='<%# DataBinder.Eval(Container.DataItem,"bought") %>'></asp:Label>
                                    </td>
                                    <td class="auto-style23">
                                        <asp:Button ID="Button1" runat="server" Height="23px" OnClick="Button1_Click" Text="加入购物车" Width="92px" CommandName="add1" />
                                    </td>
                                </tr>
                                <tr>
                                    <td class="auto-style15">
                                        <asp:Label ID="Label5" runat="server" Text="价格："></asp:Label>
                                    </td>
                                    <td class="auto-style17">
                                        <asp:Label ID="Label10" runat="server" Text='<%# DataBinder.Eval(Container.DataItem,"price") %>'></asp:Label>
                                    </td>
                                    <td class="auto-style18">&nbsp;</td>
                                </tr>
                            </table>
                            <asp:Label ID="Label12" runat="server" Text="商品介绍:"></asp:Label>
                            <br />
                            <asp:Label ID="Label13" runat="server" Text='<%# DataBinder.Eval(Container.DataItem,"introduce") %>'></asp:Label>
                        </td>
                    </tr>
                </table>
            </ItemTemplate>
            <SelectedItemStyle BackColor="#738A9C" Font-Bold="True" ForeColor="White" />
        </asp:DataList>
        <asp:Label ID="Label14" runat="server" Text="评论："></asp:Label>
        <br />
        <asp:DataList ID="DataList2" runat="server" BackColor="#DEBA84" 
        BorderColor="#DEBA84" BorderStyle="None" BorderWidth="1px" CellPadding="3" 
        CellSpacing="2" GridLines="Both" Width="410px">
            <FooterStyle BackColor="#F7DFB5" ForeColor="#8C4510" />
            <HeaderStyle BackColor="#A55129" Font-Bold="True" ForeColor="White" />
            <ItemStyle BackColor="#FFF7E7" ForeColor="#8C4510" />
            <ItemTemplate>
                <p>
                   <%# DataBinder.Eval(Container.DataItem,"uname") %> ：<%# DataBinder.Eval(Container.DataItem,"evalution") %></p>
            </ItemTemplate>
            <SelectedItemStyle BackColor="#738A9C" Font-Bold="True" ForeColor="White" />
        </asp:DataList>
        <p>
            共有<asp:Label ID="Label15" runat="server" Text="Label"></asp:Label>
            页 当前<asp:Label ID="Label16" runat="server" Text="Label"></asp:Label>
            页 
            <asp:LinkButton ID="InkbtnFirst1" runat="server" OnClick="InkbtnFirst1_Click">首页</asp:LinkButton>
&nbsp;<asp:LinkButton ID="InkbtnFront1" runat="server" OnClick="InkbtnFront1_Click">上一页</asp:LinkButton>
&nbsp;<asp:LinkButton ID="InkbtnNext1" runat="server" OnClick="InkbtnNext1_Click">下一页</asp:LinkButton>
&nbsp;<asp:LinkButton ID="InkbtnLast1" runat="server" OnClick="InkbtnLast1_Click">尾页</asp:LinkButton>
        </p>
    </form>
</body>
</html>
