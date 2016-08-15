<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Editrecharge.aspx.cs" Inherits="AdminManage_Editrecharge" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
   <form id="form1" runat="server">
    <div>
        <table style="font-size: 9pt; background-image: url(../Image/后台页.jpg);" cellpadding="0" cellspacing="0" align="center" height="339" width="515">
            <tr>
                <td style="text-align: center" rowspan="4" colspan="3">
                    <table style="height: 112px; font-size: 9pt;"  cellpadding="0" cellspacing="0">
                        <tr>
                            <td style="width: 74px">
                                金额：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtMoney" runat="server"></asp:TextBox></td>
                        </tr>
                        <tr>
                            <td style="width: 74px">
                                数量：</td>
                            <td style="width: 162px">
                                <asp:TextBox ID="txtNum" runat="server"></asp:TextBox></td>
                        </tr>
                    </table><br />
                    <asp:Button ID="btnAdd" runat="server" Text="添加" OnClick="btnAdd_Click" />
                    &nbsp;&nbsp;
                    &nbsp;&nbsp;
                    <asp:Button ID="btnBack" runat="server" OnClick="btnBack_Click" Text="返回" /></td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
