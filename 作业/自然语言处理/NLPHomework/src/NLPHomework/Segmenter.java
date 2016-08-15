package NLPHomework;

import java.util.List;


public interface Segmenter {
	
	public List<String> toWords(String content);
	public List<Word> toWordsEx(String content);
	
}
