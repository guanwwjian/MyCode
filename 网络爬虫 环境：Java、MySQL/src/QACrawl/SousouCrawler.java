package QACrawl;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.regex.Pattern;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import MyCrawler.Customsaveactivity;
import MyCrawler.DBOperator;
import MyCrawler.MyCrawler;
import MyCrawler.MyMultitaskCrawler;

public class SousouCrawler implements Customsaveactivity {
	public void customsave(String url, String page, MyCrawler mc)
	{
		DBOperator dbo1=new DBOperator("127.0.0.1","3306","myknowledgebase","root","root");
		Document doc = Jsoup.parse(page);
		Elements qtitletag=doc.getElementsByAttributeValue("class", "question-tit");
		if (qtitletag.size()!=1) return;
		String qtitle=qtitletag.get(0).text();
		Elements qcontenttag=doc.getElementsByAttributeValue("class", "question-con");
		String qcontent;
		if (qtitletag.size()>0) qcontent=qcontenttag.text();
		else qcontent="";
		dbo1.doexecute("lock tables questions write");
		dbo1.doexecute("insert into questions (title,content,fromurl,fromtask) values ('"+qtitle+"','"+qcontent+"','"+url+"','"+mc.gettask()+"')");
		int qid=-1;
		ResultSet rs=dbo1.doselect("select max(qid) from questions");
		try {
			if (rs.next())
			{
				qid=rs.getInt(1);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		dbo1.doexecute("unlock tables");
		///Elements bestanswertag=doc.getElementsByAttributeValue("class", "satisfaction-answer");
		Elements bestanswertag=doc.select("div.question-main.satisfaction-answer");
		for  (int i=0;i<bestanswertag.size();i++)
		{
			Element answerconele=bestanswertag.get(i);
			Elements answercontag=answerconele.getElementsByAttributeValue("class", "answer-con");
			String answercon;
			if (answercontag.size()>0)
			{
				Elements replenish=answercontag.get(0).getElementsByAttributeValueContaining("class", "replenish");
				for (int j=0;j<replenish.size();j++)
				{		
					replenish.get(j).empty();
				}
				answercon=answercontag.get(0).text();
				dbo1.doexecute("insert into answers (content,qid,type) values ('"+answercon+"',"+qid+",2)");
			}
			
		}
		//Elements jinghuaanswertag=doc.getElementsByAttributeValue("class", "jinghua-answer-hashead");
		Elements jinghuaanswertag=doc.select("div.question-main.jinghua-answer-hashead");
		for  (int i=0;i<jinghuaanswertag.size();i++)
		{
			Element answerconele=jinghuaanswertag.get(i);
			Elements answercontag=answerconele.getElementsByAttributeValue("class", "answer-con");
			String answercon;
			if (answercontag.size()>0)
			{
				Elements replenish=answercontag.get(0).getElementsByAttributeValueContaining("class", "replenish");
				for (int j=0;j<replenish.size();j++)
				{		
					replenish.get(j).empty();
				}
				answercon=answercontag.get(0).text();
				dbo1.doexecute("insert into answers (content,qid,type) values ('"+answercon+"',"+qid+",3)");
			}
			
		}
		Elements otheranswertag=doc.getElementsByAttributeValue("class", "answer-wrap");
		for  (int i=0;i<otheranswertag.size();i++)
		{
			Element answerconele=otheranswertag.get(i);
			Elements answercontag=answerconele.getElementsByAttributeValue("class", "answer-con");
			String answercon;
			if (answercontag.size()>0)
			{
				Elements replenish=answercontag.get(0).getElementsByAttributeValueContaining("class", "replenish");
				for (int j=0;j<replenish.size();j++)
				{		
					replenish.get(j).empty();
				}
				answercon=answercontag.get(0).text();
				dbo1.doexecute("insert into answers (content,qid,type) values ('"+answercon+"',"+qid+",1)");
			}
			
		}
		
	}
	public boolean fittosave(String url, String page)
	{
		if (Pattern.compile("http://wenwen.sogou.com/z/.*").matcher(url).matches())	return true;
		else return false;
	}
	public boolean fittocrawl(String page)
	{
		Document doc = Jsoup.parse(page);
		Elements titletags=doc.getElementsByTag("title");
		for (int i=0;i<titletags.size();i++)
		{
			if (titletags.get(i).text().equals("校园网认证系统"))
				return false;
		}
		return true;
	}
	public static void main(String args[])
	{
		SousouCrawler ssc=new SousouCrawler();
		MyMultitaskCrawler mmc=new MyMultitaskCrawler("Config.cfg","sousou",(DBOperator)null,ssc);
		mmc.CrawlerProcess();

	}
}
