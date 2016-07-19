/*
 * Created by Ranorex
 * User: conde
 * Date: 7/19/2016
 * Time: 9:15 AM
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
    /// Description of DBOraclePlSql.
    /// </summary>
    [TestModule("37D9425E-9631-45BA-9769-D28AEA9B931D", ModuleType.UserCode, 1)]
    public class DBOraclePlSql : ITestModule
    {
    	private string script = "";
    	private OracleConnection connection = null;
    	
    	public string Script { get { return script; } set { script = value; } }
    	public OracleConnection Connection { get { return connection; } set { connection = value; } }
    	
        /// <summary>
        /// Constructs a new instance.
        /// </summary>
        public DBOraclePlSql()
        {
            // Do not delete - a parameterless constructor is required!
        }
		
        public bool Execute()
        {
            string result;
            bool ret;
            
        	OracleCommand command = connection.CreateCommand();
            command.Connection = connection;
            command.CommandText = script;
            
            try
            {
            	command.ExecuteNonQuery();
            	ret = true;
            } 
            catch(OracleException ex)
            {
            	ret = false;
            }
            
			return ret;
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
