<%@ Page Language="C#" AutoEventWireup="true" CodeFile="adrecharge.aspx.cs" Inherits="AdminManage_adrecharge" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
   <form id="form1" runat="server">
    <div>
    <table style="width: 529px; height: 334px; font-size: 9pt; background-image: url(../Image/后台页.jpg);"  cellpadding="0" cellspacing="0" align="center">
            <tr>
                <td colspan="3" style="text-align: left">
                    <asp:Label ID="Label2" runat="server" Text="查询条件："></asp:Label>
                    <asp:DropDownList ID="ddlCondition" runat="server">
                        <asp:ListItem Value="rid">充值卡ID</asp:ListItem>
                        <asp:ListItem Value="rcode">充值卡号</asp:ListItem>
                    </asp:DropDownList>
                    <asp:Label ID="Label1" runat="server" Text="关键字："></asp:Label>
                    <asp:TextBox ID="txtKey" runat="server"></asp:TextBox>
                    <asp:Button ID="btnSel" runat="server" Text="查询" Height="30px" Width="58px" OnClick="btnSel_Click" />
                    &nbsp;
                    
                </td>
                
                
            </tr>
            <tr>
                <td>
                    <asp:Button ID="Button1" runat="server" Text="新建充值卡" Height="30px" OnClick="ADD_Click" />
                </td>
            </tr>
        <tr>
                <td colspan="3" style="height: 181px; text-align: center; vertical-align: top;">
                    <asp:GridView ID="gvAdminInfo" runat="server" CellPadding="4" 
                        ForeColor="#333333" GridLines="None" AutoGenerateColumns="False" 
                        OnRowDataBound="gvAdminInfo_RowDataBound" 
                        OnRowDeleting="gvAdminInfo_RowDeleting" AllowPaging="True" PageSize="7" 
                        OnPageIndexChanging="gvAdminInfo_PageIndexChanging" Font-Size="9pt" 
                        Width="500px">
                        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
                        <EditRowStyle BackColor="#999999" />
                        <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
                        <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
                        <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
                        <Columns>
                            <asp:BoundField DataField="rid" HeaderText="充值卡ID" />
                            <asp:BoundField DataField="rcode" HeaderText="充值卡号" />
                            <asp:BoundField DataField="password" HeaderText="充值密码" />
                            <asp:BoundField DataField="money" HeaderText="充值金额" />
                            <asp:CommandField HeaderText="删除" ShowDeleteButton="True">
                                <ControlStyle Font-Underline="False"/>
                            </asp:CommandField>
                        </Columns>
                        <SortedAscendingCellStyle BackColor="#E9E7E2" />
                        <SortedAscendingHeaderStyle BackColor="#506C8C" />
                        <SortedDescendingCellStyle BackColor="#FFFDF8" />
                        <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
                    </asp:GridView>
                    <br />
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
