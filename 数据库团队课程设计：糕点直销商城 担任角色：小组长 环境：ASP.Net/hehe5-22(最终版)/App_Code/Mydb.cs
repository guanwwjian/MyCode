using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Configuration;
//using System.Net.Http;
//using System.Web.Http;
using System.Data.SqlClient;

public class Mydb
{
    SqlConnection cn;
    SqlCommand cmd;
    public SqlDataReader rd;
    public string connstr;
    public Mydb()
    {
        connstr = ConfigurationManager.AppSettings["ConnectionString"];
        cn = new SqlConnection();
        cmd = new SqlCommand();
    }
    public Mydb(string st)
    {
        connstr = st;
        cn=new SqlConnection();
        cmd = new SqlCommand();
    }
    public void Open()
    {
        cn.ConnectionString = connstr;
        cn.Open();
        cmd.Connection = cn;
    }
    public SqlDataReader ExecuteReader(string com)
    {
        cmd.CommandText = com;
        rd = cmd.ExecuteReader();
        return rd;
    }
    public int ExecuteNoQuary(string com)
    {
        cmd.CommandText = com;
        return cmd.ExecuteNonQuery();
    }
    public void Close()
    {
        if (rd!=null) rd.Close();
        cn.Close();
    }
    public string getconnstr()
    {
        return connstr;
    }
    public SqlDataAdapter getada(string s)
    {
        return new SqlDataAdapter(s, cn);
    }
    // GET api/<controller>
    
}
