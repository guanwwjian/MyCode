package NLPHomework;
import java.io.*;
public class NLPHomework {
	java.io.FileReader fin;
	
	static public void main(String args[]) throws Exception
	{
		/*Data dataset=new Data();
		dataset.additems("inputs\\CSC_book_train");
		Dictionary dic=new Dictionary();
		dic.addfromfile("inputs\\charavoice.txt");*/
		SentimentsJudger sj=new SentimentsJudger("inputs\\CSC_all_test","inputs\\CSC_all_train","all_ans.txt");
		sj.test();
		sj.run();
		SentimentsJudger sj1=new SentimentsJudger("inputs\\CSC_book_test","inputs\\CSC_book_train","book_ans.txt");
		sj1.test();
		sj1.run();
		SentimentsJudger sj2=new SentimentsJudger("inputs\\CSC_dvd_test","inputs\\CSC_dvd_train","dvd_ans.txt");
		sj2.test();
		sj2.run();
		SentimentsJudger sj3=new SentimentsJudger("inputs\\CSC_music_test","inputs\\CSC_music_train","music_ans.txt");
		sj3.test();
		sj3.run();
		//int tt=0;
		
	}
}
