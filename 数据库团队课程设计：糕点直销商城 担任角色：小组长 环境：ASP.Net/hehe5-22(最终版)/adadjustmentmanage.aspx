<%@ Page Language="C#" AutoEventWireup="true" CodeFile="adadjustmentmanage.aspx.cs" Inherits="adadjustmentmanage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table style="font-size: 9pt; background-image: url(../Image/后台页.jpg);" cellpadding="0" cellspacing="0" align="center" height="339" width="500">
            <tr>
                <td colspan="3" style="text-align: right">
                    <asp:Label ID="Label2" runat="server" Text="查询条件："></asp:Label>
                    <asp:DropDownList ID="ddlCondition" runat="server">
                        <asp:ListItem Value="advid">广告ID</asp:ListItem>
                        <asp:ListItem Value="advname">广告名</asp:ListItem>
                    </asp:DropDownList>
                    &nbsp;
                    <asp:Label ID="Label1" runat="server" Text="ID："></asp:Label>
                    <asp:TextBox ID="txtKey" runat="server"></asp:TextBox>
                    <asp:Button ID="btnSel" runat="server" Text="查询" Height="30px" Width="58px" OnClick="btnSel_Click" />
                    &nbsp;
                    <asp:Button ID="Button1" runat="server" Text="修改和添加" Height="30px" OnClick="ADD_Click"/>
                </td>
            </tr>
            <tr>
                <td colspan="3" style="height: 181px; text-align: center; vertical-align: top;">
                    <asp:GridView ID="gvMemberInfo" runat="server" CellPadding="4" 
                        ForeColor="#333333" GridLines="None" AutoGenerateColumns="False" 
                        OnRowDataBound="gvMemberInfo_RowDataBound" 
                        OnRowDeleting="gvMemberInfo_RowDeleting" AllowPaging="True" PageSize="8" 
                        OnPageIndexChanging="gvMemberInfo_PageIndexChanging" Font-Size="9pt" 
                        Width="500px" >
                        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
                        <EditRowStyle BackColor="#999999" />
                        <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
                        <PagerStyle BackColor="#CBCF7A" ForeColor="Black" HorizontalAlign="Right" />
                        <HeaderStyle BackColor="#CBCF7A" Font-Bold="True" ForeColor="White" />
                        <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
                        <Columns>
                            <asp:BoundField DataField="advid" HeaderText="广告ID" />
                            <asp:BoundField DataField="advname" HeaderText="广告名" />
                            <asp:BoundField DataField="advurl" HeaderText="广告地址" />
                            <asp:BoundField DataField="width" HeaderText="宽" />
                            <asp:BoundField DataField="height" HeaderText="高" />
                            <asp:BoundField DataField="x" HeaderText="X坐标" />
                            <asp:BoundField DataField="y" HeaderText="Y坐标" />
                            <asp:CommandField HeaderText="删除" ShowDeleteButton="True">
                                <ControlStyle Font-Underline="False" ForeColor="Black" />
                            </asp:CommandField>
                        </Columns>
                    </asp:GridView>
         
                </td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
