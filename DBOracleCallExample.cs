/*
 * Created by Ranorex
 * User: conde
 * Date: 7/19/2016
 * Time: 3:55 PM
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

using System.Data.OracleClient;

namespace AlertingUI
{
    /// <summary>
    /// Description of DBOracleCallExample.
    /// </summary>
    [TestModule("DBAAE544-C221-416C-9D07-8580FB9A6E1D", ModuleType.UserCode, 1)]
    public class DBOracleCallExample : ITestModule
    {    	
        /// <summary>
        /// Constructs a new instance.
        /// </summary>
        public DBOracleCallExample()
        {
            // Do not delete - a parameterless constructor is required!
        }

        /// <summary>
        /// Performs the playback of actions in this module.
        /// </summary>
        /// <remarks>You should not call this method directly, instead pass the module
        /// instance to the <see cref="TestModuleRunner.Run(ITestModule)"/> method
        /// that will in turn invoke this method.</remarks>
        void ITestModule.Run()
        {
			DBOracle ora = new DBOracle();			

        	OracleConnection connection = new OracleConnection();
        	connection.ConnectionString = ora.GetConnectionString("LOTOSDB");
            connection.Open();
			
            DBOracleScriptContainer script = new DBOracleScriptContainer();
            
            DBOraclePlSql plsql = new DBOraclePlSql();
            plsql.Connection = connection;
            plsql.Script = script.getCleanUp("ALT_QUERY");
            plsql.Execute();
            
            connection.Close();
        }
    }
}
