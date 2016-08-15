<%@ Page Language="C#" AutoEventWireup="true" CodeFile="productlist.aspx.cs" EnableEventValidation="true" Inherits="productlist" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<script src="jquery.js" type="text/javascript"></script>
<script src="main.js" type="text/javascript"></script>
<link href="main.css" rel="stylesheet" type="text/css" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1
        {
            width: 100%;
            height: 42px;
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
        .auto-style15
        {
            width: 81px;
        }
        .auto-style16
        {
            width: 81px;
            height: 20px;
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
        }
        .auto-style21
        {
            width: 81px;
            height: 26px;
        }
        .auto-style23
        {
            width: 89px;
            height: 26px;
        }
        .style1
        {
            width: 75px;
        }
        .style2
        {
            width: 75px;
            height: 20px;
        }
        .style3
        {
            width: 75px;
            height: 26px;
        }
        #form1
        {
            height: 708px;
        }
    </style>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
    <div>
   
    <asp:Label ID="Label2" runat="server" Text="商品类别："></asp:Label>
        <asp:DropDownList ID="ddlCondition1" runat="server" DataTextField="tname" DataValueField="tname">
        </asp:DropDownList>
                     <asp:Label ID="Label1" runat="server" Text="价格区间："></asp:Label>
                    <asp:TextBox ID="txtprice1" runat="server" Width="40px"></asp:TextBox>
                    <asp:Label ID="Label4" runat="server" Text="到"></asp:Label>
                    <asp:TextBox ID="txtprice2" runat="server" Width="40px"></asp:TextBox>
                    <asp:Label ID="Label6" runat="server" Text="关键字："></asp:Label>
                    <asp:TextBox ID="txtKey" runat="server" Width="60px"></asp:TextBox>
    <asp:Button ID="search" runat="server" Text="搜索" Height="30px" Width="58px" padding-left="10px" OnClick="search_Click" />
        <br />
        <asp:Label ID="Label9" runat="server" Text="排列方式："></asp:Label>
        <asp:DropDownList ID="rangetype" runat="server">
            <asp:ListItem Value="按价格升序排列"></asp:ListItem>
            <asp:ListItem Value="按价格降序排列"></asp:ListItem>
            <asp:ListItem Value="按购买量升序排列"></asp:ListItem>
            <asp:ListItem Value="按购买量降序排列"></asp:ListItem>
            <asp:ListItem Value="&lt;未选择&gt;" Selected="True"></asp:ListItem>
        </asp:DropDownList>
    </div>
        <asp:DataList ID="DataList1" runat="server" BackColor="#DEBA84" 
        BorderColor="#DEBA84" BorderStyle="None" BorderWidth="1px" CellPadding="3" 
        CellSpacing="2" GridLines="Both" DataKeyField="pid" 
        OnItemCommand="DataList1_ItemCommand" Width="600px">
            <FooterStyle BackColor="#F7DFB5" ForeColor="#8C4510" />
            <HeaderStyle BackColor="#A55129" Font-Bold="True" ForeColor="White" />
            <ItemStyle BackColor="#FFF7E7" ForeColor="#8C4510" />
            <ItemTemplate>
                <table class="auto-style1">
                    <tr>
                        <td class="auto-style2">
                            <a runat="server" href='<%# DataBinder.Eval(Container.DataItem,"picurl") %>' class="preview"><asp:Image ID="Image1" runat="server" Height="161px" Width="113px" ImageUrl='<%# DataBinder.Eval(Container.DataItem,"picurl") %>' /></a>
                        </td>
                        <td class="auto-style20">
                            <table class="auto-style4">
                                <tr>
                                    <td class="auto-style15">
                                        <asp:Label ID="Label1" runat="server" Text="商品名称："></asp:Label>
                                    </td>
                                    <td class="style1">
                                        <asp:LinkButton ID="LinkButton1" runat="server" CommandName="link1" 
                                            Text='<%# DataBinder.Eval(Container.DataItem,"pname") %>'></asp:LinkButton>
                                    </td>
                                    <td class="auto-style18">
                                        <asp:Label ID="Label11" runat="server" Text="购买数量："></asp:Label>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="auto-style16">
                                        <asp:Label ID="Label2" runat="server" Text="库存："></asp:Label>
                                    </td>
                                    <td class="style2">
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
                                    <td class="style3">
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
                                    <td class="style1">
                                        <asp:Label ID="Label10" runat="server" Text='<%# DataBinder.Eval(Container.DataItem,"price") %>'></asp:Label>
                                    </td>
                                    <td class="auto-style18">&nbsp;</td>
                                </tr>
                            </table>
                            <br />
                        </td>
                    </tr>
                </table>
            </ItemTemplate>
            <SelectedItemStyle BackColor="#738A9C" Font-Bold="True" ForeColor="White" />
        </asp:DataList>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label14" runat="server" ForeColor="Red" Text="对不起，找不到您所查找的商品。" Visible="False"></asp:Label>
        <br />
        共有<asp:Label ID="Label12" runat="server" Text="Label"></asp:Label>
        页 当前<asp:Label ID="Label13" runat="server" Text="Label"></asp:Label>
        页&nbsp;<asp:LinkButton ID="InkbtnFirst" runat="server" OnClick="LinkButton2_Click">首页</asp:LinkButton>
&nbsp;<asp:LinkButton ID="InkbtnFront" runat="server" OnClick="InkbtnFront_Click">上一页</asp:LinkButton>
&nbsp;<asp:LinkButton ID="InkbtnNext" runat="server" OnClick="InkbtnNext_Click">下一页</asp:LinkButton>
&nbsp;<asp:LinkButton ID="InkbtnLast" runat="server" OnClick="InkbtnLast_Click">尾页</asp:LinkButton>
    </form>
</body>
</html>
