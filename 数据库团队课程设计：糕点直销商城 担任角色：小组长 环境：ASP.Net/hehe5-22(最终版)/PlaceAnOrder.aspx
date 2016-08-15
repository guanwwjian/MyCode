<%@ Page Language="C#" AutoEventWireup="true" CodeFile="PlaceAnOrder.aspx.cs" Inherits="PlaceAnOrder" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <style type="text/css">
        /*列表单元格 样式*/
        .auto-style1 {
            padding-right: 1px;
            border-right-style: solid;
            border-right-width: 1px;
            border-right-color: #C0C0C0;
            border-bottom-style:inset;
            border-bottom-width: 1px;
            border-bottom-color: #C0C0C0;
        }
        /*输入框 样式1*/
        .txt-style1 {
            width: 150px;
            height: 25px;
        }
        /*输入框 样式2*/
        .txt-style2 {
            width: 300px;
            height: 25px;
        }
    </style>
</head>
<body style="background-color:transparent">
    <form id="form1" runat="server">
        <div>
        
            <table style="border: 1px solid #C0C0C0; ">
                <tr>
                    <td class="auto-style1">收货人姓名：</td>
                    <td class="auto-style1">
                        <asp:TextBox ID="txtrealname" runat="server" CssClass="txt-style1"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="rfvRealName" runat="server" ControlToValidate="txtrealname"
                            ErrorMessage="姓名不能为空" ForeColor="#ff0000"></asp:RequiredFieldValidator>
                        
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1">收货人手机号：</td>
                    <td class="auto-style1">
                        <asp:TextBox ID="txtphonenumber" runat="server" CssClass="txt-style1"></asp:TextBox>
                        <asp:RegularExpressionValidator ID="revPhoneNumber" runat="server" ControlToValidate="txtphonenumber" 
                             ValidationExpression="[0-9]{11}" ErrorMessage="手机号输入有误！" ForeColor="#ff0000">
                        </asp:RegularExpressionValidator>
                        <asp:RequiredFieldValidator ID="rfvPhoneNumber" runat="server" ControlToValidate="txtphonenumber"
                             ErrorMessage="手机号不能为空！" ForeColor="#ff0000">
                        </asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1">邮编：</td>
                    <td class="auto-style1">
                        <asp:TextBox ID="txtzipcode" runat="server" CssClass="txt-style1"></asp:TextBox>
                        <asp:RegularExpressionValidator ID="revZipCode" runat="server" ControlToValidate="txtzipcode" 
                             ValidationExpression="[0-9]*" ErrorMessage="邮编不合法！" ForeColor="#ff0000">
                        </asp:RegularExpressionValidator>
                    </td>

                </tr>
                <tr>
                    <td class="auto-style1">收货地址：</td>
                    <td class="auto-style1">
                        <asp:TextBox ID="txtuseraddress" runat="server" CssClass="txt-style2"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="rfvUserAddress" runat="server" ControlToValidate="txtuseraddress"
                            ErrorMessage="收货地址不能为空" ForeColor="#ff0000">
                        </asp:RequiredFieldValidator>
                        
                    </td>

                </tr>

                <tr>
                    <td class="auto-style1">附加留言：</td>
                    <td class="auto-style1">
                        <asp:TextBox ID="txtadditionalmessage" runat="server" CssClass="txt-style2"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1" >
                        <asp:Label ID="lblAfterConfirmOrder" runat="server" Text="确认订单："></asp:Label>
                    </td>
                    <td style="text-align: left" class="auto-style1">
                        <asp:GridView ID="GridView1" runat="server">
                        </asp:GridView>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1" >
                        <asp:Label ID="lblPayStatus" runat="server" Text="您将花费："></asp:Label>
                    </td>
                    <td style="text-align: left" class="auto-style1">
                        <asp:GridView ID="GridView2" runat="server">
                        </asp:GridView>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1">
                        <asp:Label ID="lblAccountBalance" runat="server" Text="账户余额："></asp:Label>
                    </td>
                    <td style="text-align: left" class="auto-style1">
                        <asp:GridView ID="GridView3" runat="server">
                        </asp:GridView>
                    </td>
                </tr>
                <tr>
                    <td>
                        <asp:Label ID="lblNoEnoughMoney" runat="server" Text="您的余额不足哦，请尽快充值^^" Visible="False"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1">
                        <asp:Button ID="Button1" runat="server" Text="确认支付" Height="40px"
                            OnClick="Button1_Click" Width="90px" Style="margin-top: 0px" />
                    </td>
                    <td class="auto-style1">
                        <asp:Button ID="Button2" runat="server" Text="取消" Width="90px"
                            OnClick="Button2_Click" Height="40px" Style="margin-top: 0px"  Visible="false"/>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style1">
                        <asp:Button ID="btnToRecharge" runat="server" OnClick="btnToRecharge_Click" Width="90px" Height="40px" Text="前往充值页面" Visible="False" />
                    </td>
                    <td colspan="3"
                        class="auto-style1" >
                        <asp:Label ID="lblerror" runat="server" Visible="False"></asp:Label>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
