package MyCrawler;

public interface Customsaveactivity {
	public void customsave(String url, String page, MyCrawler mc);
	public boolean fittosave(String url, String page);
	public boolean fittocrawl(String page);
}
