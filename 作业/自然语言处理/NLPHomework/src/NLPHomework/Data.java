package NLPHomework;

import java.io.*;
import java.util.*;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;

class Sentenceword {
	static IKSegmenter segmenter = new IKSegmenter();
	private String a0;
	private List<String> a1 = new ArrayList<String>();
	private List<List<String>> a2 = new ArrayList<List<String>>();
	private int cw=0;
	public void setst(String st) {
		a0 = new String(st);
		a1 = segmenter.toWords(st);
		cw=a1.size();
		String tt = new String(st);
		tt.replace('。', '，');
		String ts[] = tt.split("，");
		for (int i = 0; i < ts.length; i++) {
			a2.add(segmenter.toWords(ts[i]));
		}
	}
	
	public String getst0() {
		return a0;
	}

	public List<String> getst1() {
		return a1;
	}

	public List<List<String>> getst2() {
		return a2;
	}
	public int getcw()
	{
		return cw;
	}
}

class Item {
	public Sentenceword summary=new Sentenceword();
	public Sentenceword	text=new Sentenceword();
	public String category, polarity;
	public String id;
	public int getcw()
	{
		return summary.getcw()+text.getcw();
	}
}

public class Data {
	public List<Item> its = new ArrayList<Item>();
	//public int cw=0,cs=0,pw=0,ps=0,nw=0,ns=0;
	public void additems(String filename) throws Exception {
		SAXBuilder builder = new SAXBuilder();
		Document doc = builder.build(new File(filename));
		Element element = doc.getRootElement();
		List<Element> list_h = element.getChildren();
		for (Element a : list_h) {
			List<Element> list_child = a.getChildren();
			Item it= new Item();
			for (Element e : list_child) {
				if (e.getName() == "summary") {
					it.summary.setst(e.getText());
				} else if (e.getName() == "text") {
					it.text.setst(e.getText());
				} else if (e.getName() == "category") {
					it.category = e.getText();
				} else if (e.getName() == "polarity") {
					it.polarity = e.getText();
				} else if (e.getName() == "review_id") {
					it.id = e.getText();
				}
				/*cs++;
				cw+=it.getcw();
				if (it.polarity.equals("P")) 
				{
					ps++;
					pw+=it.getcw();
				}
				else if (it.polarity.equals("N")) 
				{
					ns++;
					nw+=it.getcw();
				}*/
			}
			its.add(it);
		}
	}
	
}
