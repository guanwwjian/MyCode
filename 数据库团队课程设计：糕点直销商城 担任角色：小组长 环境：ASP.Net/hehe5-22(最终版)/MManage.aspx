<%@ Page Language="C#" AutoEventWireup="true" CodeFile="MManage.aspx.cs" Inherits="AdminManage_MManage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>无标题页</title>
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
<body style="background-color:transparent">
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td colspan="3" style="text-align: left">
                        <asp:Label ID="Label2" runat="server" Text="查询条件："></asp:Label>
                        <asp:DropDownList ID="ddlCondition" runat="server">
                            <asp:ListItem Value="uid">会员ID</asp:ListItem>
                            <asp:ListItem Value="uname">会员名</asp:ListItem>
                        </asp:DropDownList>
                        <asp:Label ID="Label1" runat="server" Text="关键字："></asp:Label>
                        <asp:TextBox ID="txtKey" runat="server"></asp:TextBox>
                        <asp:Button ID="btnSel" runat="server" Text="查询" Height="30px" Width="58px" OnClick="btnSel_Click" />
                        &nbsp;
                    <%--<asp:Button ID="Button1" runat="server" Text="修改和添加" Height="30px" OnClick="ADD_Click" />--%>
                    </td>
                </tr>
                <tr>
                    <td colspan="3" style="height: 181px; text-align: center; vertical-align: top;">
                        <asp:GridView ID="gvMemberInfo" runat="server" CellPadding="4"
                            ForeColor="#333333" GridLines="None" AutoGenerateColumns="False"
                            OnRowDataBound="gvMemberInfo_RowDataBound"
                            OnRowDeleting="gvMemberInfo_RowDeleting" AllowPaging="True" PageSize="8"
                            OnPageIndexChanging="gvMemberInfo_PageIndexChanging" Font-Size="9pt"
                            Width="500px" DataKeyNames="uid" OnRowCancelingEdit="gvMemberInfo_RowCancelingEdit" OnRowEditing="gvMemberInfo_RowEditing" OnRowUpdating="gvMemberInfo_RowUpdating" OnRowCommand="gvMemberInfo_RowCommand">
                            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
                            <Columns>
                                <asp:BoundField DataField="uid" HeaderText="用户ID" />
                                <asp:BoundField DataField="uname" HeaderText="用户名" />
                                <%--<asp:BoundField DataField="password" HeaderText="密码" />--%>
                                <%--<asp:BoundField DataField="safecode" HeaderText="安全码" />--%>
                                <asp:BoundField DataField="money" HeaderText="用户余额" />
                                <asp:TemplateField HeaderText="是否被禁">
                                    <ItemTemplate>
                                        <asp:Label runat="server" ID="lblBanUser" 
                                            Text='<%#(Boolean) Eval("ban")==false ? "否":"是"%>'></asp:Label>
                                    </ItemTemplate>
                                </asp:TemplateField>
                                <%--<asp:BoundField DataField="Ban" HeaderText="是否被禁" />--%>
                                <asp:CommandField  HeaderText="修改" ShowEditButton="true" ButtonType="Button" />
                                <asp:CommandField HeaderText="删除" ShowDeleteButton="True" ButtonType="Button" />
                                <asp:TemplateField HeaderText="启/禁用户">
                                    <ItemTemplate >
                                        <asp:Button ID="btnBanUser" runat="server" 
                                            Text='<%#(Boolean) Eval("ban")==false ? "禁用":"启用"%>'
                                            OnClientClick="return confirm('确定操作吗？')"
                                            OnClick="btnBanUser_Click" />
                                    </ItemTemplate>
                                </asp:TemplateField>
                                <%--<asp:TemplateField>
                                    <ItemTemplate>
                                        <asp:Button ID="btnTest" runat="server" Text="Test"
                                             CommandArgument='<%# Container.DataItemIndex %>' />
                                    </ItemTemplate>
                                </asp:TemplateField>--%>
                                <%--<ControlStyle Font-Underline="False" ForeColor="Black" />--%>
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
                    </td>
                </tr>
            </table>

        </div>
    </form>
</body>
</html>
