package MyCrawler;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class CrawlerwithDBO {
	String fproperty;
	String user;
	String hostname;
	String port;
	String database;
	String tablelog;
	String tablemodes;
	String ip;
	String password;
	String defaultsaveon;
	String defaultsavedir;
	String customsaveon;
	String customsavelocation;
	String tableproperties;
	String seed;
	String mindelay;
	String maxdelay;
	String tabletaskproperties;
	String tabletasks;
	String searchurl;
	PropertyManager pm=new PropertyManager();
	DBOperator dbo;
	String site;
	String task;
	int taskid;
	int siteid;
	Customsaveactivity csa;
	public CrawlerwithDBO(String fproperty,String site,String task)
	{
		this(fproperty,site,task,(DBOperator)null);
	}
	public CrawlerwithDBO(String fproperty,String site,String task,DBOperator dbo)
	{
		this(fproperty,site,task,dbo,(Customsaveactivity)null);
	}
	public CrawlerwithDBO(String fproperty,String site,String task,Customsaveactivity csa)
	{
		this(fproperty,site,task,(DBOperator)null,csa);
	}
	public CrawlerwithDBO(String fproperty,String site,String task,DBOperator dbo,Customsaveactivity csa)
	{
		init(fproperty,site,task,dbo);
		setcsa(csa);
	}
	public void init(String fproperty,String site,String task,DBOperator dbo)
	{
		this.dbo=dbo;
		ip="127.0.0.1";
		port="3306";
		hostname="localhost";
		database="MyCrawler";
		tablelog="Crawler_log";
		tablemodes="Crawler_modes";
		tableproperties="Crawler_properties";
		user="root";
		password="root";
		defaultsaveon="1";
		defaultsavedir=".\\HTMLPages";
		customsaveon="1";
		customsavelocation=".\\customsave.out";
		tabletaskproperties="Crawler_taskproperties";
		tabletasks="Crawler_tasks";
		seed="";
		searchurl="";
		mindelay="5";
		maxdelay="15";
		this.fproperty=fproperty;
		this.task=task;
		this.site=site;
		if (fproperty!=null) loadfromfile(fproperty);
		if (dbo==null) initdbconnector();
		loadfromdb();

	}
	public void setcsa(Customsaveactivity csa)
	{
		this.csa=csa;
	}
	public int getsiteidfromdb(String site)
	{
		int ans=-1;
		if (site!=null)
		{
			ResultSet rs1=dbo.doselect("select taskid from "+tabletasks+" where taskname='"+site+"' and type=1");
			try {
				if (rs1.next())
				{
					ans=rs1.getInt(1);
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return ans;
	}
	public void loadsiteid()
	{
		siteid=getsiteidfromdb(site);
	}
	public int gettaskidfromdb(String task)
	{
		int ans=-1;
		if (task!=null)
		{
			ResultSet rs2=dbo.doselect("select taskid from "+tabletasks+" where taskname='"+task+"' and type=2");
			try {
				if (rs2.next())
				{
					ans=rs2.getInt(1);
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return ans;
	}
	public void loadtaskid()
	{
		taskid=gettaskidfromdb(task);
	}
	public void loadsiteandtaskid()
	{
		loadsiteid();
		loadtaskid();
	}
	public void loadfromdb()
	{
		loadsiteandtaskid();
		pm.loadfromdb(tableproperties,tabletaskproperties,siteid,taskid,dbo);
		updateproperties();
	}
	public void updateproperties()
	{
		if (pm.get("ip") != null) ip=pm.get("ip");
		if (pm.get("port") != null) port=pm.get("port");
		if (pm.get("hostname") != null) hostname=pm.get("hostname");
		if (pm.get("database") != null) ip=pm.get("database");
		if (pm.get("tablelog") != null) tablelog=pm.get("tablelog");
		if (pm.get("tablemodes") != null) tablemodes=pm.get("tablemodes");
		if (pm.get("user") != null) user=pm.get("user");
		if (pm.get("password") != null) password=pm.get("password");
		if (pm.get("defaultsaveon") != null) defaultsaveon=pm.get("defaultsaveon");
		if (pm.get("defaultsavedir") != null) defaultsavedir=pm.get("defaultsavedir");
		if (pm.get("customsaveon") != null) customsaveon=pm.get("customsaveon");
		if (pm.get("customsavelocation") != null) customsavelocation=pm.get("customsavelocation");
		if (pm.get("tableproperties") != null) tableproperties=pm.get("tableproperties");
		if (pm.get("seed") != null) seed=pm.get("seed");
		if (pm.get("mindelay") != null) mindelay=pm.get("mindelay");
		if (pm.get("maxdelay") != null) maxdelay=pm.get("maxdelay");
		if (pm.get("tabletaskproperties") != null) tabletaskproperties=pm.get("tabletaskproperties");
		if (pm.get("tabletabletasks") != null) tabletasks=pm.get("tabletasks");
		if (pm.get("searchurl") != null) searchurl=pm.get("searchurl");
	}
	public void loadfromfile(String fname)
	{
		pm.loadfromfile(fname);
		updateproperties();
	}
	
	public void initdbconnector()
	{
		dbo=new DBOperator(ip,port,database,user,password);
	}
	public int getsiteid()
	{
		return siteid;
	}
	public int gettaskid()
	{
		return taskid;
		
	}
	public String gettask()
	{
		return task;
	}
	public String getp(String pname)
	{
		return pm.get(pname);
	}
}
