package MyCrawler;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;


public class DBOperator {
	final String name = "com.mysql.jdbc.Driver"; 
	String connstr;   
    String user;  
    String password;
    Connection conn = null;  
    public DBOperator(String ip, String port, String database, String user, String password)
    {
    	connstr="jdbc:mysql://"+ip+":"+port+"/"+database;
    	this.user=user;
    	this.password=password; 
    	openconn();
    }
    public void openconn()
    {
    	     
        try { 
        	Class.forName(name);//指定连接类型  
            conn = DriverManager.getConnection(connstr, user, password);//获取连接  
        } 
        catch(SQLException e) { 
        System.out.println(e.getMessage()); 
        } 
        catch(Exception e) { 
            System.out.println(e.getMessage()); 
        } 
    }
    public void closeconn()
    {
    	try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
    public void doexecute(String sql) 
    {//增删改
    	try 
    	{ 
    	    Statement stm=conn.createStatement(); 
    	    stm.executeUpdate(sql); 
    	    //System.out.println("操作成功");  
    	}    
    	catch(Exception e){    
    		System.out.println(e.getMessage()); 
    	   
    	} 

    } 
    public ResultSet doselect(String sql)
    { //查询  
    	ResultSet rs=null;   
    	try
    	{ 
    	    Statement stm=conn.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE); 
    	    rs=stm.executeQuery(sql); 
    	} 
    	catch(Exception e)
    	{ 
    	    System.out.println(e.getMessage()); 
    	} 
    	return rs; 
    }

}
