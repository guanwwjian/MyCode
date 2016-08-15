package MyCrawler;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;

public class PropertyManager
{
	HashMap<String,String> properties;
	public PropertyManager()
	{
		properties=new HashMap<String,String>();
	}
	public PropertyManager(String fname)
	{
		super();
		loadfromfile(fname);
	}
	public void set(String name, String value)
	{
		properties.put(name, value);
	}
	public String get(String name)
	{
		return properties.get(name);
	}
	void loadfromfile(String fname)
	{
		File file = new File(fname);
		BufferedReader reader = null;
        try {
        	if (!file.exists()) file.createNewFile();
            reader = new BufferedReader(new FileReader(file));
            String tempString = null;
            while ((tempString = reader.readLine()) != null) {
            	String st[]=tempString.split(":");
            	properties.put(st[0].toLowerCase(), st[1]);
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                }
            }
        }
	}
	void loadfromdb(String table, DBOperator dbo)
	{
		ResultSet rs=dbo.doselect("select pname,pvalue from " + table);
		try 
		{
			while (rs.next())
			{
				set(rs.getString(1),rs.getString(2));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	void loadfromdb(String tableproperties, String tabletaskproperties, int siteid, int taskid, DBOperator dbo)
	{
		loadfromdb(tableproperties,dbo);
		if (siteid>=0)
		{
			ResultSet rs1=dbo.doselect("select pname,pvalue from " + tabletaskproperties + " where taskid="+siteid);
			try {
				while (rs1.next())
				{
					set(rs1.getString(1),rs1.getString(2));
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		ResultSet rs2=dbo.doselect("select pname,pvalue from " + tabletaskproperties + " where taskid="+taskid);
		if (taskid>=0)
		{
			try {
				while (rs2.next())
				{
					set(rs2.getString(1),rs2.getString(2));
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
