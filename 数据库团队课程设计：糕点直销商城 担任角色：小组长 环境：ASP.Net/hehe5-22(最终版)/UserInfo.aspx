<%@ Page Language="C#" AutoEventWireup="true" CodeFile="UserInfo.aspx.cs" Inherits="UserInfo" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div style="height: 65px">
    
    </div>
    <div>
        <table style="margin:1px,1px,1px,1px;padding:4px,7px,2px,4px;width:240px;height:200px">
            <tr>
                <td>欢迎您！^^</td>
                <td>
                    <asp:Label ID="lblUserName" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>
                    您的账户余额：
                </td>
                <td>
                    <asp:Label ID="lblUserMoney" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>
                    您的账户状态：
                </td>
                <td>
                    <asp:Label ID="lblAccountStatus" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td></td>
            </tr>
            <tr>
                <td>
                    <asp:LinkButton ID="lnkbtnShoppingCart" runat="server" Text="我的购物车" OnClick="lnkbtnShoppingCart_Click"></asp:LinkButton>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:LinkButton ID="lnkbtnUserCenter" runat="server" Text="我的订单" OnClick="lnkbtnUserCenter_Click" ></asp:LinkButton>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:LinkButton ID="lnkbtnRecharge" runat="server" Text="我要充值" OnClick="lnkbtnRecharge_Click"></asp:LinkButton>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:LinkButton ID="lnkbtnChangePassword" runat="server" Text="修改密码" OnClick="lnkbtnChangePassword_Click"></asp:LinkButton>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:LinkButton ID="lnkbtnLogout" runat="server" Text="注销" OnClick="lnkbtnLogout_Click"
                         OnClientClick="return confirm('确认注销吗？')"></asp:LinkButton>
                </td>
            </tr>
                <%--<asp:DataList ID="dlUserInfo" runat="server">
                    <ItemTemplate>
                        <table>
                            <tr>
                                <td>欢迎您！</td>
                                <td>
                                    <asp:Label ID="lblUserName" runat="server"
                                        Text='<%# DataBinder.Eval(Container.DataItem, "uname") %>'></asp:Label>
                                </td>
                            </tr>
                            <tr>
                                <td>您的账户余额：
                                </td>
                                <td>
                                    <asp:Label ID="lblUserMoney" runat="server"
                                        Text='<%# DataBinder.Eval(Container.DataItem, "money") %>'></asp:Label>
                                </td>
                            </tr>
                            <tr>
                                <td>您的账户状态：
                                </td>
                                <td>
                                    <asp:Label ID="lblAccountStatus" runat="server"
                                        Text='<%# DataBinder.Eval(Container.DataItem, "enable") %>'></asp:Label>
                                </td>
                            </tr>
                            <tr>
                                <td>上次登录IP：
                                </td>
                                <td>
                                    <asp:Label ID="lblLastIP" runat="server"
                                        Text='<%# DataBinder.Eval(Container.DataItem, "lastip") %>'></asp:Label>
                                </td>
                            </tr>
                        </table>
                    </ItemTemplate>
                </asp:DataList>--%>
        </table>
    </div>
    </form>
</body>
</html>
