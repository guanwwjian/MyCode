package MyCrawler;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Random;

import com.gargoylesoftware.htmlunit.BrowserVersion;
import com.gargoylesoftware.htmlunit.NicelyResynchronizingAjaxController;
import com.gargoylesoftware.htmlunit.WebClient;

public class MyMultitaskCrawler extends CrawlerwithDBO{
	WebClient webClient;
	Random random=new Random();
	public MyMultitaskCrawler(String fproperty,String site,DBOperator dbo)
	{
		super(fproperty, site, (String)null,dbo);
		init(fproperty,site);
	}
	public MyMultitaskCrawler(String fproperty,String site,DBOperator dbo,Customsaveactivity csa)
	{
		super(fproperty, site, (String)null,dbo,csa);
		init(fproperty,site);
	}
	public void init(String fproperty,String site)
	{
		webClient = new WebClient(BrowserVersion.CHROME);
		webClient.getOptions().setCssEnabled(true); 
		webClient.setAjaxController(new NicelyResynchronizingAjaxController());
        webClient.getOptions().setJavaScriptEnabled(true);  //需要解析js  
        webClient.getOptions().setThrowExceptionOnScriptError(false);  //解析js出错时是否抛异常  
        webClient.getOptions().setTimeout(30000);  //超时时间  ms  
	}
	public void CrawlerProcess()
	{
		ArrayList<MyCrawler> list=new ArrayList<MyCrawler>();
		ResultSet rs=dbo.doselect("select taskname from "+tabletasks+" where type=2 and status=1 and ftaskid="+siteid);
		WebClient webClient=new WebClient();
		webClient = new WebClient(BrowserVersion.CHROME);
		webClient.getOptions().setCssEnabled(true); 
		webClient.setAjaxController(new NicelyResynchronizingAjaxController());
        webClient.getOptions().setJavaScriptEnabled(true);  //需要解析js  
        webClient.getOptions().setThrowExceptionOnScriptError(false);  //解析js出错时是否抛异常  
        webClient.getOptions().setTimeout(30000);  //超时时间  ms  
		try {
			while (rs.next())
			{
				MyCrawler crawler=new MyCrawler(fproperty,site,rs.getString(1),webClient,dbo,csa);
				crawler.initdb();
				list.add(crawler);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		while (list.size()>0)
		{
			for (int i=0;i<list.size();i++)
			{
				if (!list.get(i).doCrawl())
				{
					MyCrawler crawler=list.get(i);
					list.remove(i);
					i--;
					dbo.doexecute("update "+tabletasks+" SET status=2 WHERE taskid="+crawler.gettaskid());
				}
				delay();
			}
		}
		
	}
	public void delay()
	{
		int delay=Integer.parseInt(mindelay)*1000+Math.abs(random.nextInt()%((Integer.parseInt(maxdelay)-Integer.parseInt(mindelay))*1000));
		try {
			Thread.currentThread();
			Thread.sleep(delay);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void addsite(String site, ArrayList<String> linktextmodes,ArrayList<String> urlmodes, ArrayList<String> pname, ArrayList<String> pvalue)
	{
		this.site=site;	
		dbo.doexecute("INSERT INTO "+tabletasks+" (taskname,type,status) VALUE ('"+site+"',1,1)");
		loadsiteid();
		if (linktextmodes!=null)
		{
			for (int i=0;i<linktextmodes.size();i++)
			{
				dbo.doexecute("INSERT INTO "+tablemodes+" (type,mode,taskid) VALUE ('linktextmodes','"+linktextmodes.get(i)+"',"+siteid+")");
			}
		}
		if (urlmodes!=null)
		{
			for (int i=0;i<urlmodes.size();i++)
			{
				dbo.doexecute("INSERT INTO "+tablemodes+" (type,mode,taskid) VALUE ('urlmodes','"+urlmodes.get(i)+"',"+siteid+")");
			}
		}
		if ((pname!=null)&&(pvalue!=null)&&(pname.size()==pvalue.size()))
		{
			for (int i=0;i<pvalue.size();i++)
			{
				dbo.doexecute("INSERT INTO "+tabletaskproperties+" (pname,taskid,pvalue) VALUE ('"+pname.get(i)+"',"+siteid+",'"+pvalue.get(i)+"')");
			}
			
		}
		loadfromdb();
	}
	public void addtask(String taskname,ArrayList<String> linktextmodes,ArrayList<String> urlmodes, ArrayList<String> pname, ArrayList<String> pvalue)
	{
		dbo.doexecute("INSERT INTO "+tabletasks+" (taskname,type,status,ftaskid) VALUE ('"+taskname+"',2,1,'"+siteid+"')");
		int tid=gettaskidfromdb(taskname);
		if (linktextmodes!=null)
		{
			for (int i=0;i<linktextmodes.size();i++)
			{
				dbo.doexecute("INSERT INTO "+tablemodes+" (type,mode,taskid) VALUE ('linktextmodes','"+linktextmodes.get(i)+"',"+tid+")");
			}
		}
		if (urlmodes!=null)
		{
			for (int i=0;i<urlmodes.size();i++)
			{
				dbo.doexecute("INSERT INTO "+tablemodes+" (type,mode,taskid) VALUE ('urlmodes','"+urlmodes.get(i)+"',"+tid+")");
			}
		}
		if ((pname!=null)&&(pvalue!=null)&&(pname.size()==pvalue.size()))
		{
			for (int i=0;i<pvalue.size();i++)
			{
				dbo.doexecute("INSERT INTO "+tabletaskproperties+" (pname,taskid,pvalue) VALUE ('"+pname.get(i)+"',"+tid+",'"+pvalue.get(i)+"')");
			}
			
		}
	}
	static public void main(String args[])
	{
		//MyMultitaskCrawler mmc=new MyMultitaskCrawler("Config.cfg","sousou",(DBOperator)null);
		//mmc.CrawlerProcess();
	}

}
