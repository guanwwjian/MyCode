package NLPHomework;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.ws.nlpir.code.NlpirTools;


public class SegWords implements Segmenter {
	public String getWords(String sInput) {
		return getWords(sInput, true);
	}

	public String getWords(String sInput, boolean quto) {
		
		//String nativeStr = NlpirTools.paragraphProcess("2014年3月全国计算机等级考试打印准考证并参加培训的通知", "utf-8");
		String nativeStr = NlpirTools.paragraphProcess(sInput, "utf-8");

		if (quto && nativeStr != null) {
			nativeStr = processQuto(nativeStr);
		}
		return nativeStr;
	}

	private String processQuto(String nativeStr) {
		while (true) {
			int l_index = nativeStr.indexOf("“/");
			int r_index = nativeStr.indexOf("”", l_index);
			if (-1 == l_index || -1 == r_index) {
				break;
			}

			String lStr = nativeStr.substring(0, l_index);
			String tStr = nativeStr.substring(l_index, r_index);
			String rStr = nativeStr.substring(r_index);

			// System.out.println(tStr);
			Pattern pattern = Pattern.compile("/.*? ");
			Matcher matcher = pattern.matcher(tStr);
			if (matcher.find()) {
				// System.out.println(matcher.start() + "~" + matcher.end());
				// System.out.println(tStr.substring(matcher.start(),
				// matcher.end()));
				tStr = matcher.replaceAll("");
			}
			matcher = pattern.matcher(rStr);
			if (matcher.find()) {
				rStr = matcher.replaceFirst("/quto ");
			}
			/*
			 * System.out.println(lStr); System.out.println(tStr);
			 * System.out.println(rStr);
			 */
			nativeStr = lStr + tStr + rStr;
			// break;

		}
		return nativeStr;
	}


	@Override
	public List<String> toWords(String content) {

		return null;
	}

	@Override
	public List<Word> toWordsEx(String content) {
		String words = getWords(content, false);
		if (words == null || "".equals(words)) {
			return null;
		}
		List<Word> result = new ArrayList<Word>();
		String[] wordArr = words.split(" ");
		for (String word : wordArr) {
			int index = word.lastIndexOf("/");
			if (index != -1 && index < word.length() - 1) {
				Word w = new Word();
				w.setText(word.substring(0, index));
				w.setPos(word.substring(index + 1));
				result.add(w);
			}
		}
		return result;
	}
}
