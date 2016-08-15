package QACrawl;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import MyCrawler.DBOperator;
import MyCrawler.MyMultitaskCrawler;

public class SousouQACrawlerIniter {
	static DBOperator dbo=new DBOperator("127.0.0.1","3306","myknowledgebase","root","root");
	static DBOperator cdbo=new DBOperator("127.0.0.1","3306","MyCrawler","root","root");
	static public void addsousousite()
	{
		MyMultitaskCrawler mmc=new MyMultitaskCrawler("Config.cfg",(String)null,cdbo);
		ArrayList<String> linktextmodes=new ArrayList<String>();
		linktextmodes.add("下一页>");
		ArrayList<String> urlmodes=new ArrayList<String>();
		
		urlmodes.add("http://wenwen.sogou.com/cate/.*");
		urlmodes.add("http://wenwen.sogou.com/z/.*");
		urlmodes.add("http://wenwen.sogou.com/s/.*");
		ArrayList<String> pname=new ArrayList<String>();
		ArrayList<String> pvalue=new ArrayList<String>();
		pname.add("searchurl");
		pvalue.add("http://wenwen.sogou.com/s/?w={searchtext}");
		mmc.addsite("sousou", linktextmodes, urlmodes,pname,pvalue);
	}
	static public void addtopics(String theme,String site)
	{
		ResultSet rs=dbo.doselect("Select tname from topics");
		try {
			while (rs.next())
			{
				addtopic(theme,site,rs.getString(1));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	static public void addtopic(String theme,String site,String topic)
	{
		System.out.println("添加话题："+topic);
		MyMultitaskCrawler mmc=new MyMultitaskCrawler("Config.cfg",site,cdbo);
		String taskname=theme+"_"+site+"_"+topic;
		ArrayList<String> linktextmodes=new ArrayList<String>();
		linktextmodes.add("(?i).*"+theme+".*"+topic+".*");
		linktextmodes.add("(?i).*"+topic+".*"+theme+".*");
		ArrayList<String> pname=new ArrayList<String>();
		ArrayList<String> pvalue=new ArrayList<String>();
		pname.add("seed");
		String searchtext;
		try {
			searchtext = URLEncoder.encode(topic+" "+theme,"utf-8");
			pvalue.add(mmc.getp("searchurl").replaceAll("\\{searchtext\\}", searchtext));
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		mmc.addtask(taskname, linktextmodes, (ArrayList<String>)null,pname,pvalue);
		
	}
	static public void main(String args[])
	{
		/*addsousousite();
		
		addtopics("java","sousou");*/
	}

}
