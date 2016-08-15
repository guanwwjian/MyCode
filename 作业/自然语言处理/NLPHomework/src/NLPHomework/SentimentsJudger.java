package NLPHomework;

import java.util.*;
import java.io.*;
public class SentimentsJudger {
	Data test = new Data();
	Data train = new Data();
	Sentiments senti = new Sentiments();
	String ofile;
	/*public void inputfromfiles() throws Exception {
		test.additems("inputs\\CSC_book_test");
		test.additems("inputs\\CSC_dvd_test");
		test.additems("inputs\\CSC_music_test");
		train.additems("inputs\\CSC_book_train");
		train.additems("inputs\\CSC_dvd_train");
		train.additems("inputs\\CSC_music_train");
		senti.addfromfile("inputs\\1.1.txt", 1, 5);
		senti.addfromfile("inputs\\1.2.txt", 1, 3);
		senti.addfromfile("inputs\\1.3.txt", 1, 2);
		senti.addfromfile("inputs\\1.4.txt", 1, 0.5);
		senti.addfromfile("inputs\\1.5.txt", 1, 0.3);
		senti.addfromfile("inputs\\1.6.txt", 1, -1);
		senti.addfromfile("inputs\\2.txt", 2, -1);
		senti.addfromfile("inputs\\3.txt", 3, -1);
		senti.addfromfile("inputs\\4.txt", 4, 1);
		senti.addfromfile("inputs\\5.txt", 5, 1);
		senti.addfromdata(train);
	}*/
	public SentimentsJudger(String testfile, String trainfile, String outputfile) throws Exception {
		test.additems(testfile);
		train.additems(trainfile);
		ofile=outputfile;
		senti.addfromfile("inputs\\1.1.txt", 1, 5);
		senti.addfromfile("inputs\\1.2.txt", 1, 3);
		senti.addfromfile("inputs\\1.3.txt", 1, 2);
		senti.addfromfile("inputs\\1.4.txt", 1, 0.5);
		senti.addfromfile("inputs\\1.5.txt", 1, 0.3);
		senti.addfromfile("inputs\\1.6.txt", 1, -1);
		senti.addfromfile("inputs\\2.txt", 2, -1);
		senti.addfromfile("inputs\\3.txt", 3, -1);
		senti.addfromfile("inputs\\4.txt", 4, 1);
		senti.addfromfile("inputs\\5.txt", 5, 1);
		senti.addfromdata(train);
	}

	public double calvalue2(List<List<String>> s) {
		final double step=1;
		final double bayesw=1;
		List<Double> values = new ArrayList<Double>();
		for (List<String> p : s) {
			values.add(calbybayes(p)*bayesw+(1-bayesw)*calbysd(p));
		}
		double w=1-step,sum=0,ans=0;;
		for (int i=0;i<values.size();i++)
		{
			w+=step;
			ans+=w*values.get(i);
			sum+=w;
		}
		ans/=sum;
		return ans;
	}
	public double calvalue(List<String> s) {
		
		final double bayesw=0.8;
		double ans;
		ans=calbybayes(s)*bayesw+(1-bayesw)*calbysd(s);
		return ans;
	}
	public double calbysd(List<String> s)
	{
		//double vt = 0;
		double ov = 1; 
		double p=0.00001,n=0.00001;
		
		int age=0;
		for (String w : s) {
			Emotionword tt;
			if ((tt = senti.get(w)) != null) {
				if (tt.cla == 1) 
				{
					ov=tt.value;
					age=0;
				}
				else if (tt.cla!=0)
				{
					//vt+=ov*tt.value;
					double val=ov*tt.value;
					if (val>0) p+=val;
					else n-=val;
					ov=1;
				}
			}
			else 
			{
				age++;
				if (age>3) ov=1;
			}
			
		}
		return p/(p+n);
	}
	public double calbybayes(List<String> s)
	{
		double pp=Emotionword.probpa(),pn=Emotionword.probna();
		for (String i:s)
		{
			Emotionword ew;
			if (((ew = senti.get(i)) != null)&&(ew.fromdata))
			{
				pp*=(ew.probp()+0.000001);
				pn*=(ew.probn()+0.000001);
			}
			
		}
		return pp/(pp+pn);
	}
	public String judge(Item t)
	{
		final double neg=0.3;
		final double pos=1-neg;
		final double psum=2;
		double ssummary=calvalue(t.summary.getst1());
		double stext=calvalue(t.text.getst1());
		double s=(psum*ssummary+stext)/(1+psum);
		if (ssummary>pos) return "P";
		else if (ssummary<neg) return "N";
		else if (s>=0.5) return "P";
		else return "N";
	}
	public void test()
	{
		double count=train.its.size();
		double right=0;
		for (Item it : train.its)
		{
			if (judge(it).equals(it.polarity))right++;
			else
			{
				System.out.println(it.summary.getst0()+" "+it.text.getst0()+" "+it.polarity);
			}
		}
		System.out.println(right/count);
	}
	public void run() throws IOException
	{
		double count=test.its.size();
		double right=0;
		BufferedWriter out= new BufferedWriter(new FileWriter(new File(ofile)));
		for (Item it : test.its)
		{
			String p=judge(it);
			out.write(it.category+"	"+it.id+" "+p);
			out.newLine();
			
		}
		out.flush();
	}
}
