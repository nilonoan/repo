/*
 * Created by Ranorex
 * User: conde
 * Date: 7/19/2016
 * Time: 9:14 AM
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.Drawing;
using System.Threading;
using WinForms = System.Windows.Forms;

using Ranorex;
using Ranorex.Core;
using Ranorex.Core.Testing;

namespace AlertingUI
{
    /// <summary>
    /// Description of DBOracle.
    /// </summary>
    [TestModule("51787FF1-A8AD-4212-B60D-B30081745045", ModuleType.UserCode, 1)]
    public class DBOracle : ITestModule
    {
    	private string user = "";
    	private string password = "";
    	private string server = "";
    	private string sid = "";
    	private string dbname = "";
    	private string port = "";
    	    	
        public string User { get { return user; } set { user = value; } }
        public string Password { get { return password; } set { password = value; } }
        public string Server { get { return server; } set { server = value; } }
        public string SId { get { return sid; } set { sid = value; } }
        public string DbName { get { return dbname; } set { dbname = value; } }
        public string Port { get { return port; } set { port = value; } }
            	
    	/// <summary>
        /// Constructs a new instance.
        /// </summary>
        public DBOracle()
        {
            // Do not delete - a parameterless constructor is required!
        }

        public string GetConnectionString(string databasename = "")
        {
        	switch(databasename)
        	{
        		case "LOTOSDB":
        			user = "LOTOSDB";
        			password = "LOTOSDB";
        			server = "10.71.142.246";
        			sid = "L10FAT";
					port = "1521";					
        			break;
        		case "LOTOSAUTH":
        			user = "LOTOSAUTH";
        			password = "LOTOSAUTH";
        			server = "10.71.142.246";
        			sid = "L10FAT";
					port = "1521";
        			break;
				default:
					databasename = "unknown";
					break;
        	}

        	dbname = databasename;
        	
            string oradb = "Data Source=(DESCRIPTION="
			+ "(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)(HOST=%%HOST%%)(PORT=%%PORT%%)))"
			+ "(CONNECT_DATA=(SID=%%SID%%)));"
			+ "User Id=%%USERID%%;Password=%%PASSWORD%%;";
            
            oradb = oradb.Replace("%%USERID%%", user)
            	.Replace("%%PASSWORD%%", password)
            	.Replace("%%HOST%%", server)
            	.Replace("%%SID%%", sid)
            	.Replace("%%PORT%%", port);
            
            return oradb;
        }
        
        /// <summary>
        /// Performs the playback of actions in this module.
        /// </summary>
        /// <remarks>You should not call this method directly, instead pass the module
        /// instance to the <see cref="TestModuleRunner.Run(ITestModule)"/> method
        /// that will in turn invoke this method.</remarks>
        void ITestModule.Run()
        {
			// TODO
        }
    }
}
