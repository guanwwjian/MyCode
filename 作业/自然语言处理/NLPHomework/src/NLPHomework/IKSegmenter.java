package NLPHomework;

import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;

import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.wltea.analyzer.lucene.IKAnalyzer;


public class IKSegmenter {

	public static IKAnalyzer analyzer = new IKAnalyzer(true);
	


	public List<String> toWords(String content) {
		List<String> results = new ArrayList<String> ();
		StringReader reader = new StringReader(content);
		TokenStream tokenStream = analyzer.tokenStream("text", reader);
		CharTermAttribute charTermAttribute = tokenStream.getAttribute(CharTermAttribute.class);
		try {
			while (tokenStream.incrementToken()) {
				String term = charTermAttribute.toString();
				results.add(term);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		return results;
	}


	
}
