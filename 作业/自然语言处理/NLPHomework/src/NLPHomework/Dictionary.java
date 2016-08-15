package NLPHomework;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;


class Voice
{
	public String spell;
	public int tone=0;
	Voice(String v)
	{
		spell=v.substring(0, v.length()-1);
		tone=v.charAt(v.length()-1)-'0';
	}
	boolean equals(Voice v)
	{
		return ((spell.equals(v.spell))&&(tone==v.tone));
	}
}

public class Dictionary
{
	AbstractMap<String,List<Voice>> charamap = new MapType<String,List<Voice>>();
	AbstractMap<String,List<String>> voicemap = new MapType<String,List<String>>();
	public void add(String c,String v)
	{
		Voice vt=new Voice(v);
		addtocharamap(c,vt);
		addtovoicemap(vt.spell,c);
	}
	public List<Voice> ctov(String c)
	{
		return charamap.get(c);
	}
	public List<String> vtoc(String v)
	{
		return voicemap.get(v);
	}
	public void addfromfile(String filename) throws IOException
	{
		File f = new File(filename);
		BufferedReader r= new BufferedReader(new FileReader(f)); 
		List<String> ls= new ArrayList<String>();
		String line;
		while ((line=r.readLine()) != null)
		{
			ls.add(line);
		}
		for (String l : ls)
		{
			String charas;
			String words[]=l.split(" ");
			if (words[0].charAt(0)==65279) charas=words[0].substring(1);
			else charas=words[0];
			for (int i=0;i<charas.length();i++)
			{
				add(charas.substring(i, i+1),words[i+1]);
			}
		}
	}
	void addtocharamap(String c,Voice v)
	{
		if (charamap.containsKey(c))
		{
			for (Voice vt : charamap.get(c))
			{
				if (v.equals(vt)) return;			
			}
			charamap.get(c).add(v);
		}
		else 
		{
			List<Voice> lv=new ArrayList<Voice>();
			lv.add(v);
			charamap.put(c, lv);
		}
	}
	void addtovoicemap(String v,String c)
	{
		if (voicemap.containsKey(v))
		{
			for (String ct : voicemap.get(v))
			{
				if (c.equals(ct)) return;			
			}
			voicemap.get(v).add(c);
		}
		else 
		{
			List<String> lc=new ArrayList<String>();
			lc.add(c);
			voicemap.put(v, lc);
		}
	}
}
