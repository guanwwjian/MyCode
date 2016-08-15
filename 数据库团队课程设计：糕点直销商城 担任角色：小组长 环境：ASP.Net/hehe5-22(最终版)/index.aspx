<%@ Page Language="C#" AutoEventWireup="true" CodeFile="index.aspx.cs" Inherits="index" %>

&nbsp;

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title></title>
   <script type="text/javascript" language="javascript">
       function iFrameHeight() {
           var ifm = document.getElementById("iframepage");
           var subWeb = document.frames ? document.frames["iframepage"].document : ifm.contentDocument;
           if (ifm != null && subWeb != null) {
               ifm.height = subWeb.body.scrollHeight;
           }
       } 
</script> 
<link href="19.css" rel="stylesheet" type="text/css">
  
      <style>
      <!--
             a:link{
                        color:#7a3013;
                        text-decoration:none;
                        }
             a:visited{
                        color:#7a3013;
                        text-decoration:none;
                        }
                        
             a:hover{
                        color:#c28225;
                        text-decoration:underline;
                        }
-->
  </style>

</head>
<body style="Width: 960px; Height: auto; margin:0 auto;text-align:center;background-color:#7a3013;">
    <form id="form1" runat="server" style="height: auto">
    <div style="height: auto; width: 960px;">
 
    
        <table style="padding: 0px; margin: 0px; border-width: 0px; border-style: none; width: 960px; height: auto; font-family: 黑体; font-size: large; font-weight: bolder; color: #FCF7D1;">
            
                    <div class="style1" align="center" id="loader"></div>
<script type="text/javascript">
			// <![CDATA[
    var so = new SWFObject("viewer.swf", "sotester", "1000", "650", "9", "#000000");
    so.addParam("flashvars", "&xmlLocation=data.xml");
    so.write("loader");
			// ]]>	
			</script>
                    <img alt="" src="Image/newicon/Title.jpg" />&nbsp;<br />
        
                

        <div id="globallink" style="height: 30px;align:right">
		<ul style="clip: rect(auto, auto, auto, 240px); height: 50px; margin-left: 520px; margin-bottom: 0px; margin-top: 15px;" >
			<li><a target="iframepage" href="onsales.aspx"  >首页</a></li>
			<li><a target="iframepage" href="productlist.aspx">商品列表</a></li>
			<li><a target="iframepage" href="About us.aspx">关于我们</a></li>
			<li><a target="iframepage" href="Contact us.aspx">联系我们</a></li>
		</ul>
		
	</div>

            <tr>
                <td class="style1" 
                    style="padding: 0px; margin: 0px; border-style: none; width: 25%; height: 300px; background-repeat: no-repeat; overflow: hidden; background-image: url('Image/newicon/loginbg3.jpg');">
           
                    <iframe id="login" runat="server" name="login"  frameborder="0" scrolling="no" 
                        src="login.aspx"  
                        style="padding: 0px; margin: 0px; width: 100%; height: 100%; overflow: hidden;"></iframe>&nbsp;</td>
                  
                <td class="style1" colspan="2" rowspan="3" 
                    
                    
                    
                    
                    
                    
                    
                    
                    style="border-style: none; width: 80%; height:auto; vertical-align:top; background-image: url('Image/newicon/MainBg.jpg'); background-repeat: no-repeat; overflow: hidden;">
                             
                    <div style="vertical-align:top">
                    
                    <iframe id="iframepage" name="iframepage"  frameborder="0" scrolling="no" 
                        src="<%=GetUrl()%>"  style="width: 100%;overflow: hidden; margin-top: 0px;" 
                            onLoad="iFrameHeight()" > 
                        </iframe>&nbsp;</td>
                        </div>
            </tr>

            <tr>
                <td class="style1" 
                    style="border-style: none; width: 20%; height: 30%; color: #FFFFFF; font-family: 宋体; font-size: large; background-repeat: no-repeat; overflow: hidden; background-image: url('Image/newicon/SelectBg.jpg');" 
                    align="left" valign="top">
                    
                    <table style="width: 100%; height: 100%;">
                        <tr>
                            <td>
                                &nbsp;</td>
                        </tr>
                        <tr>
                            <td>
                                &nbsp;</td>
                        </tr>
             
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                                &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                                <a target="iframepage" href="productlist.aspx?word=tid=10000">奶油蛋糕</a>&nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                               &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                               <a target="iframepage" href="productlist.aspx?word=tid=10001">卡通蛋糕</a> &nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                               &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                               <a target="iframepage" href="productlist.aspx?word=tid=10002">水果蛋糕</a>&nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                                &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                                <a target="iframepage" href="productlist.aspx?word=tid=10003">巧克力蛋糕</a>&nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                                &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                                <a target="iframepage" href="productlist.aspx?word=tid=10004">芝士蛋糕</a>&nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                                &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                                <a target="iframepage" href="productlist.aspx?word=tid=10005">慕丝蛋糕</a>&nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                                &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                                <a target="iframepage" href="productlist.aspx?word=tid=10006">巧克力</a>&nbsp;</td>
                        </tr>
                        <tr>
                            <td style="border-color: #7A3013; border-bottom-style: dotted; font-family: 华文琥珀; color: #7A3013; text-decoration: none;">
                                &nbsp;&nbsp;
                                <img alt="" src="Image/newicon/little%20cake.jpg" />&nbsp;
                                <a target="iframepage" href="productlist.aspx?word=tid=100010">饼干</a>&nbsp;</td>
                        </tr>
                    </table>
                    
                </td>
            </tr>

            <tr>
                <td class="style1" 
                    
                    style="width: 20%; height: auto; padding-left: 3px; background-image: url('Image/newicon/else.jpg'); background-repeat: repeat-y; overflow: hidden;">
                    &nbsp;</td>
            </tr>
        </table>
    
      
    
    </div>
     <div>
         <br 
            class="style1" />
        <span class="style1">&nbsp;</span></div>
    </form>
</body>
</html>
