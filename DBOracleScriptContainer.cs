/*
 * Created by Ranorex
 * User: conde
 * Date: 7/19/2016
 * Time: 4:24 PM
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
    /// Description of DBOracleScriptContainer.
    /// </summary>
    [TestModule("92BBC631-6D6E-411F-A62A-D920543D4B8A", ModuleType.UserCode, 1)]
    public class DBOracleScriptContainer : ITestModule
    {    	
    	private Dictionary<String, String> cleanupScripts = new Dictionary<String, String>();
    	
        /// <summary>
        /// Constructs a new instance.
        /// </summary>
        public DBOracleScriptContainer()
        {
            // Do not delete - a parameterless constructor is required!
            populateCleanUpScripts();
        }
		
        private void populateCleanUpScripts()
        {
        	cleanupScripts["ALT_QUERY"] = @"
				DECLARE 
				  V_DESCR ALT_QUERY.DESCR%TYPE := 'Automation purposes';
				  V_NAME ALT_QUERY.NAME%TYPE := 'Automation_Test';
				  V_QUERY ALT_QUERY.QUERY%TYPE := 'Test';
				  V_CATEGORY_FK ALT_QUERY.CATEGORY_FK%TYPE := 121;
				  V_EXISTS NUMBER(1) := 0;
				  V_AFFECTED_ROWS NUMBER(3) := -1;
				BEGIN
				  SELECT CASE WHEN EXISTS(
				          SELECT 1 FROM ALT_QUERY
				          WHERE 
				            DESCR = V_DESCR 
				            AND NAME = V_NAME 
				            AND QUERY = V_QUERY 
				            AND CATEGORY_FK = V_CATEGORY_FK
				          )
				          THEN 1 
				          ELSE 0    
				        END INTO V_EXISTS
				  FROM DUAL;
				  
				  IF V_EXISTS = 1 THEN   
				    DELETE FROM ALT_RULE     
				    WHERE 
				      ALT_QUERY_FK IN (
				                        SELECT ID FROM ALT_QUERY                                
				                        WHERE
				                          DESCR = V_DESCR 
				                          AND NAME = V_NAME 
				                          AND QUERY = V_QUERY
				                          AND CATEGORY_FK = V_CATEGORY_FK                        
				                      );
				    
				    V_AFFECTED_ROWS := SQL%ROWCOUNT;
				    
				    DELETE FROM ALT_QUERY      
				    WHERE
				      DESCR = V_DESCR 
				      AND NAME = V_NAME 
				      AND QUERY = V_QUERY
				      AND CATEGORY_FK = V_CATEGORY_FK;
				    
				    V_AFFECTED_ROWS := V_AFFECTED_ROWS + SQL%ROWCOUNT;  
				    
				    ROLLBACK;
				  END IF;		
				END; 
				";  
        }
        
        public string getCleanUp(string keyname)
        {
        	return cleanupScripts[keyname];
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
