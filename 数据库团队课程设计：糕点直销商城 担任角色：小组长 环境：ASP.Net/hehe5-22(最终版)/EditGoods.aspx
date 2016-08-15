<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EditGoods.aspx.cs" Inherits="AdminManage_EditGoods" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>无标题页</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table style="font-size: 9pt; background-image: url('../Image/后台页.jpg'); height: 467px;" 
            cellpadding="0" cellspacing="0" align="center" border="1" bordercolor="#cccc66" 
            width="500">
            <tr>
                <td style="width: 143px; vertical-align: top; text-align: center;" rowspan="5">
                    <br />&nbsp;&nbsp;<asp:Image ID="imgPhoto" runat="server" Height="162px" 
                        Width="160px" /><br />
                    <asp:FileUpload ID="FileUpload1" runat="server" Width="200px" />
                    <asp:Button ID="Button1" runat="server" Text="上传" OnClick="Button1_Click" />
                    <br />
                </td>
                <td style=" text-align: center;" >
                    商品名称：</td>
                <td  >
                    <asp:TextBox ID="txtGName" runat="server"></asp:TextBox></td>
            </tr>
            <tr>
                <td style=" text-align: center;" >
                    商品价格：</td>
                <td >
                    <asp:TextBox ID="txtGPrice" runat="server"></asp:TextBox></td>
            </tr>
             <tr>
                <td style=" text-align: center;" >
                    商品库存：</td>
                <td >
                    <asp:TextBox ID="txtstock" runat="server"></asp:TextBox></td>
            </tr>
             <tr>
                <td style=" text-align: center;" >
                    商品销售额：</td>
                <td >
                    <asp:TextBox ID="txtbought" runat="server"></asp:TextBox></td>
            </tr>
             <tr>
                <td style=" text-align: center;" >
                    商品类别：</td>
                <td>
                    <asp:DropDownList ID="ddlGType" runat="server" Height="25px" Width="155px">
                    </asp:DropDownList></td>
            </tr>
            <tr>
                <td style="vertical-align: top; width: 143px; text-align: center; height: 80px;">
                    <br />
                    商品简介：<br /><br /><br /><br /><br />
                    </td>
                <td colspan="2" 
                    style="padding: 0px; margin: 0px; vertical-align: top; text-indent: 8pt; height: 80px;text-align: center;">
                    <asp:TextBox ID="txtGIntroduce" runat="server" Height="150px" Width="310px" 
                        TextMode="MultiLine"></asp:TextBox></td>
            </tr>
             <tr>
                <td style="height: 30px; text-align: right;" rowspan="1" colspan="3">
                    <asp:Button ID="btnAdd" runat="server" Text="保存" OnClick="btnSave_Click" />
                    <asp:Button ID="btnBack" runat="server" OnClick="btnBack_Click" Text="返回" />&nbsp;
                </td>
            </tr>
        </table>
    </div>
    </form>
    
</body>
</html>
