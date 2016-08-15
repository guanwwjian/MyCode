package NLPHomework;
import java.io.*;
import java.util.*;
class Emotionword
{
	static public int cwa=0,csa=0,pwa=0,psa=0,nwa=0,nsa=0;
	public String word;
	public int cla=0;
	public double value=0;
	public int p=0,n=0;
	public int cw=0,cs=0,pw=0,ps=0,nw=0,ns=0;
	boolean fromdata=false;
	public Emotionword(String w,int c,double v)
	{
		word=new String(w);
		cla=c;
		value=v;
		
	}
	/*public double probp()
	{
		double ans=(double)pw/pwa;
		return ans;
	}
	public double probn()
	{
		double ans=(double)nw/nwa;
		return ans;
	}
	static public double probpa()
	{
		double ans=(double)pwa/cwa;
		return ans;
	}
	static public double probna()
	{
		double ans=(double)nwa/cwa;
		return ans;
	}*/
	public double probp()
	{
		double ans=(double)ps/psa;
		return ans;
	}
	public double probn()
	{
		double ans=(double)ns/nsa;
		return ans;
	}
	static public double probpa()
	{
		double ans=(double)psa/csa;
		return ans;
	}
	static public double probna()
	{
		double ans=(double)nsa/csa;
		return ans;
	}
}
public class Sentiments {
	AbstractMap<String,Emotionword> map = new MapType<String,Emotionword>();
	public void add(String word,int cla,double value)
	{
		Emotionword ew=new Emotionword(word,cla,value);
		map.put(word, ew);
	}
	public void addfromfile(String filename,int cla,double value) throws IOException
	{
		File f = new File(filename);
		BufferedReader r= new BufferedReader(new FileReader(f)); 
		List<String> ls= new ArrayList<String>();
		String line;
		while ((line=r.readLine()) != null)
		{	
			ls.add(line.replace(" ", ""));
		}
		for (String l : ls)
		{
			add(l,cla,value);
		}
	}
	public void addfromdata(Data d)
	{
		for (Item it:d.its)
		{	
			Emotionword.csa++;
			Emotionword.cwa+=it.getcw();	
			if (it.polarity.equals("P")) 
			{
				Emotionword.psa++;
				Emotionword.pwa+=it.getcw();
			}
			else if (it.polarity.equals("N")) 
			{
				Emotionword.nsa++;
				Emotionword.nwa+=it.getcw();
			}
			
			List<List<String>> s=it.summary.getst2();
			List<List<String>> t=it.text.getst2();
			AbstractMap<String,String> tmap=new MapType<String,String>();
			for (List<String> i:s)
				for (String j:i)
				{
					if (it.polarity.equals("P")) 
					{
						Emotionword tew=map.get(j);
						if (tew==null)
						{
							tew=new Emotionword(j,0,0);
							map.put(j,tew);		
							tew=map.get(j);
						}
						tew.fromdata=true;
						tew.cw++;
						tew.pw++;
						if (tmap.get(j)==null)
						{
							tmap.put(j,j);
							tew.cs++;
							tew.ps++;
						}
					}
					else if (it.polarity.equals("N")) 
					{
						Emotionword tew=map.get(j);
						if (tew==null)
						{
							tew=new Emotionword(j,0,0);
							map.put(j,tew);		
							tew=map.get(j);
						}
						tew.fromdata=true;
						tew.cw++;
						tew.nw++;
						if (tmap.get(j)==null)
						{
							tmap.put(j,j);
							tew.cs++;
							tew.ns++;
						}
					}
				}
			for (List<String> i:t)
				for (String j:i)
				{
					if (it.polarity.equals("P")) 
					{
						Emotionword tew=map.get(j);
						if (tew==null)
						{
							tew=new Emotionword(j,0,0);
							map.put(j,tew);		
							tew=map.get(j);
						}
						tew.fromdata=true;
						tew.cw++;
						tew.pw++;
						if (tmap.get(j)==null)
						{
							tmap.put(j,j);
							tew.cs++;
							tew.ps++;
						}
					}
					else if (it.polarity.equals("N")) 
					{
						Emotionword tew=map.get(j);
						if (tew==null)
						{
							tew=new Emotionword(j,0,0);
							map.put(j,tew);		
							tew=map.get(j);
						}
						tew.fromdata=true;
						tew.cw++;
						tew.nw++;
						if (tmap.get(j)==null)
						{
							tmap.put(j,j);
							tew.cs++;
							tew.ns++;
						}
					}
				}
			
			
		}
	}
	public Emotionword get(String w)
	{
		return map.get(w);
	}
}
