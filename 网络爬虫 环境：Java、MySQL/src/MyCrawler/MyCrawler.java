package MyCrawler;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.MalformedURLException;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

import org.apache.http.conn.HttpHostConnectException;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import com.gargoylesoftware.htmlunit.FailingHttpStatusCodeException;
import com.gargoylesoftware.htmlunit.NicelyResynchronizingAjaxController;
import com.gargoylesoftware.htmlunit.ScriptResult;
import com.gargoylesoftware.htmlunit.WebClient;
import com.gargoylesoftware.htmlunit.html.HtmlOption;
import com.gargoylesoftware.htmlunit.html.HtmlPage;
import com.gargoylesoftware.htmlunit.html.HtmlSelect;
import com.gargoylesoftware.htmlunit.BrowserVersion;
import com.sun.org.apache.xalan.internal.xsltc.runtime.Hashtable;
import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader.Array;
import java.util.regex.Pattern;


class Urlinfo
{
	public String url;
	public int urlid;
	public Urlinfo(int urlid,String url)
	{
		this.urlid=urlid;
		this.url=url;
	}
}
public class MyCrawler extends CrawlerwithDBO{
	List<String> urlmodes;
	List<String> linktextmodes;
	WebClient webClient;
	public MyCrawler(String fproperty,String site,String task,WebClient webClient)
	{
		super(fproperty,site,task);
		init(fproperty,site,task,webClient);
	}
	public MyCrawler(String fproperty,String site,String task,WebClient webClient,DBOperator dbo,Customsaveactivity csa)
	{
		super(fproperty,site,task,dbo,csa);
		init(fproperty,site,task,webClient);
	}
	public void init(String fproperty,String site,String task,WebClient webClient)
	{
		
		this.webClient=webClient;
		urlmodes=new ArrayList<String>();
		linktextmodes=new ArrayList<String>();
		addurlmodes();
		addlinkmodes();
		
	}
	
	public void addurlmodes()
	{
		ResultSet rs=dbo.doselect("select mode from "+tablemodes+" where type='urlmodes' and taskid="+taskid+" or taskid="+siteid);
		try 
		{
			while (rs.next())
			{
				urlmodes.add(rs.getString(1));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void addlinkmodes()
	{
		ResultSet rs=dbo.doselect("select mode from "+tablemodes+" where type='linktextmodes' and taskid="+taskid+" or taskid="+siteid);
		try {
			while (rs.next())
			{
				linktextmodes.add(rs.getString(1));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public String gettime()
	{
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		return df.format(new Date());
	}
	public Urlinfo geturl()
	{
		Urlinfo urlinfo=null;
		try 
		{
			dbo.doexecute("lock tables "+tablelog+" write");
			ResultSet rs=dbo.doselect("SELECT urlid,url FROM " + tablelog + " WHERE HasCrawled=0 and taskid="+taskid+" LIMIT 0,1");
			if (rs.next())
			{
				urlinfo=new Urlinfo(rs.getInt(1),rs.getString(2));
				if (urlinfo.url!=null) dbo.doexecute("UPDATE " + tablelog + " SET HasCrawled=1, CrawlTime='"+gettime()+"', PC_NO='"+hostname+"' WHERE urlid="+Integer.toString(urlinfo.urlid));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			dbo.doexecute("unlock tables");
		}
		return urlinfo;
	}
	public boolean isempty()
	{
		ResultSet rs=dbo.doselect("Select * from "+tablelog+" where taskid="+taskid);
		try {
			return !rs.next();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return true;
		
	}
	public void initdb()
	{
		
		if (isempty())
		{
			if (seed.indexOf("|")>=0)
			{
				String s[]=seed.split("|");
				for (int i=0;i<s.length;i++)
				{
					inserturl(s[i]);
				}
			}
			else inserturl(seed);
			
		}
	}
	public boolean fittocrawl(String page)
	{
		if (csa==null) return true;
		return csa.fittocrawl(page);
	}
	public boolean doCrawl()
	{
		Urlinfo urlinfo=geturl();
		if (urlinfo==null) return false;
		try 
		{
			System.out.println(site+":"+task+":开始："+urlinfo.url);
			String page=Crawl(urlinfo.url);
			if ((page==null) ||(!fittocrawl(page)))
			{
				dbo.doexecute("UPDATE " + tablelog + " SET HasCrawled=-1, CrawlTime='"+gettime()+"', PC_NO='"+hostname+"' WHERE urlid="+urlinfo.urlid);
				System.out.println("错误："+urlinfo.url);
			}
			else 
			{
				addurls(urlinfo.url,page);
				savepage(urlinfo,page);
				System.out.println(site+":"+task+":完成："+urlinfo.url);
			}
			
		}
		catch (Exception e)
		{
			e.printStackTrace();
			dbo.doexecute("UPDATE " + tablelog + " SET HasCrawled=-1, CrawlTime='"+gettime()+"', PC_NO='"+hostname+"' WHERE urlid="+urlinfo.urlid);
		}
		return true;
	}
	public void CrawlProcess()
	{
		Random random=new Random();
		
		initdb();
		boolean flag=true;
		while (flag)
		{
			flag=doCrawl();
			int delay=Integer.parseInt(mindelay)*1000+Math.abs(random.nextInt()%((Integer.parseInt(maxdelay)-Integer.parseInt(mindelay))*1000));
			try {
				Thread.currentThread();
				Thread.sleep(delay);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	public boolean savepage(Urlinfo urlinfo,String page)
	{
		if (!fittosave(urlinfo.url,page))
		{
			dbo.doexecute("UPDATE " + tablelog + " SET HasCrawled=3, CrawlTime='"+gettime()+"', PC_NO='"+hostname+"' WHERE urlid="+urlinfo.urlid);
			return false;
		}
		if (defaultsaveon=="1")
		{
			defaultsave(urlinfo.url,page);
		}
		if (customsaveon=="1")
		{
			customsave(urlinfo.url,page,dbo);
		}
		dbo.doexecute("UPDATE " + tablelog + " SET HasCrawled=2, CrawlTime='"+gettime()+"', PC_NO='"+hostname+"' WHERE urlid="+urlinfo.urlid);
		return true;
	}
	public void customsave(String url, String page, DBOperator dbo)
	{
		if (csa!=null) csa.customsave(url, page, this);
	}
	public boolean fittosave(String url, String page)
	{
		if (csa==null) return true;
		return csa.fittosave(url, page);
	}
	public void defaultsave(String url, String page)
	{
		
		String filename=(url.replaceAll("http://", "").replaceAll("https://", "").replaceAll("/", "#").replace('?', '@'))+".html";
		String taskdir=defaultsavedir+"\\"+task;
		File dsavedir=new File(defaultsavedir);
		if (!dsavedir.exists()) 
			dsavedir.mkdir();
		File tsavedir=new File(taskdir);
		if (!tsavedir.exists()) 
			tsavedir.mkdir();
		int count=tsavedir.list().length;
		int part;
		if (count==0) part=0;
		else part=count-1;
		File f1=new File(taskdir+"\\"+Integer.toString(part));
		if (!f1.exists()) f1.mkdir();
		if (f1.list().length>=10000)
		{
			part++;
			File f2=new File(taskdir+"\\"+Integer.toString(part));
			if (!f2.exists()) f2.mkdir();
		}
		File ofile=new File(taskdir+"\\"+Integer.toString(part)+"\\"+filename);
		BufferedWriter writer = null;
        try 
        {
            writer = new BufferedWriter(new FileWriter(ofile));
            writer.write(page);          	
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (writer != null) {
                try {
                    writer.close();
                } catch (IOException e1) {
                	e1.printStackTrace();
                }
            }
        }
		
	}
	
	public String Crawl(String url)
	{
		
        HtmlPage rootPage=null;
		try {
			rootPage= webClient.getPage(url);
			return rootPage.asXml();
		} catch (FailingHttpStatusCodeException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
		
	}
	/*public void addurls(String url, String page)
	{
		try {
			Parser par=Parser.createParser(page,"UTF-8");
			NodeFilter nf=new NodeFilter()
			{
 
				@Override  
                public boolean accept(Node node) 
				{  
					TagNode tag=new TagNode();
					//if (!(node instanceof LinkTag)) 
					//	return false;
					//tag=(TagNode)node;
					tag.setText(node.toHtml());
					if ((tag.getTagName()=="a")&&(tag.getAttribute("href")!=null)) return true;
					else return false;
                 }  

			};	
			NodeList ln=par.extractAllNodesThatMatch(nf);
			for (int i=0;i<ln.size();i++)
			{
				TagNode tagi=(TagNode)ln.elementAt(i);
				System.out.println(tagi.getAttribute("href"));
			}
			
		} catch (ParserException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}*/
	public void addurls(String url, String page)
	{
		String tt[]=url.split("/");
		String host=tt[0]+"//"+tt[2];
		String pageurl;
		if (url.indexOf("?")>=0)
		{
			String tt1[]=url.split("\\?");
			pageurl=tt1[0];
		}
		else
		{
			pageurl=url;
		}
		Document doc = Jsoup.parse(page);
		Elements links=doc.getElementsByAttribute("href");
		for (int i=0;i<links.size();i++)
		{
			Element link=links.get(i);
			if ((link.hasAttr("href")&&(link.tagName()=="a")))
			{
				String linktext=link.text();
				String linkurl=completeurl(host,pageurl,link.attr("href"));
				if ((fiturl(linkurl))&&(fittext(linktext)))
				{
					inserturl(linkurl);
				}
			}
		}
	}
	public boolean fiturl(String url)
	{
		if (urlmodes.size()==0) return true;
		for (int i=0;i<urlmodes.size();i++)
		{
			if (Pattern.compile(urlmodes.get(i)).matcher(url).matches()) return true;
		}
		return false;
	}
	public boolean fittext(String text)
	{
		if (linktextmodes.size()==0) return true;
		for (int i=0;i<linktextmodes.size();i++)
		{
			if (Pattern.compile(linktextmodes.get(i)).matcher(text).matches()) return true;
		}
		return false;
	}
	public boolean urlexist(String url)
	{
		ResultSet rs=dbo.doselect("SELECT url FROM " + tablelog + " WHERE url='"+url+"' LIMIT 0,1");
		try {
			return rs.next();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	public void inserturl(String url)
	{
		if (!urlexist(url))
		{
			dbo.doexecute("INSERT INTO " + tablelog + "(url, HasCrawled, add_time, taskid) VALUES ('"+url+"', '0', '"+gettime()+"',"+taskid+") ");
		}
	}
	public String completeurl(String host, String pageurl, String linkurl)
	{
		
		if ((linkurl.startsWith("http://"))||(linkurl.startsWith("https://"))) return linkurl;
		if (linkurl.startsWith("?")) return pageurl+linkurl;
		return host+linkurl;
		
	}
	
	public static void main(String[] args)  throws FailingHttpStatusCodeException, MalformedURLException, IOException 
	{
		
		/*MyCrawler mc=new MyCrawler("Config.cfg","sousou","sousou_Java");
		//String url="http://www.oschina.net/search?scope=bbs&catalog=0&q=java&p=1";
		//String page=mc.Crawl(url);
		//mc.addurls(url, page);
		mc.CrawlProcess();*/
	
	}
}
