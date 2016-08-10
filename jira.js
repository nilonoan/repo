var ForReading = 1;
var ForWriting = 2;

var WebPage = "jira.html";

var sUserNameStartTag = "<!-- START:OS_USERNAME FIELD -->";
var sUserNameEndTag = "<!-- END:OS_USERNAME FIELD -->";
var sPasswordStartTag = "<!-- START:OS_PASSWORD FIELD -->";
var sPasswordEndTag = "<!-- END:OS_PASSWORD FIELD -->";

var sUserNameField = "<input class=\"text medium-field\" id=\"login-form-username\" name=\"os_username\" type=\"text\" value=\"VALUE_HERE\" />";
var	sPasswordField = "<input id=\"login-form-password\" class=\"text medium-field\" name=\"os_password\" type=\"password\" value=\"VALUE_HERE\" />";
	
var SleepProcess = 3000;
var SleepWholeProcess = 30000;

var UserParam = 0;
var PwdParam = 1;
var HourParam = 2;
var MinuteParam = 3;

var oArgs = WScript.Arguments;

function doTask() {
	var oShell = new ActiveXObject("WScript.Shell");
	var oFso = new ActiveXObject("Scripting.FileSystemObject");
	
	var f = oFso.OpenTextFile(WebPage, ForReading);
	var sContent = f.ReadAll();
	f.Close();
	
	f = null

	var nStartStr = sContent.indexOf(sUserNameStartTag);
	var nEndStr = sContent.indexOf(sUserNameEndTag);
	var nLenStartStr = sUserNameStartTag.length;
	var nLen = sContent.indexOf("/>", nStartStr + nLenStartStr) + "/>".length - (nStartStr + nLenStartStr);

	var sUserName = sContent.substring(nStartStr + nLenStartStr, nStartStr + nLenStartStr + nLen);

	nStartStr = sContent.indexOf(sPasswordStartTag);
	nEndStr = sContent.indexOf(sPasswordEndTag);
	nLenStartStr = sPasswordStartTag.length;
	nLen = sContent.indexOf("/>", nStartStr + nLenStartStr) + "/>".length - (nStartStr + nLenStartStr);
	
	var sPassword = sContent.substring(nStartStr + nLenStartStr, nStartStr + nLenStartStr + nLen);	
	
	sContent = sContent.replace(RegExp(sUserName, "g"), sUserNameField.replace(/VALUE_HERE/g, oArgs(UserParam))); 
	sContent = sContent.replace(RegExp(sPassword, "g"), sPasswordField.replace(/VALUE_HERE/g, oArgs(PwdParam)));
	
	f = oFso.OpenTextFile(WebPage, ForWriting, true);
	f.Write(sContent);	
	f.close();
	
	f = null;
	
	oShell.Run("taskkill /im firefox.exe", 0, true);

	WScript.Sleep(SleepProcess);

	var sCurDir = oShell.CurrentDirectory;
	oShell.Run("firefox file:///" + sCurDir.replace(/\\/g, '/') + "/" + WebPage);
}

var oTime = null;
var oDate = null;

while(true) {
	oDate = new Date();
	
	oTime = {
		"hours": oDate.getHours()
	,	"minutes": oDate.getMinutes()
	,	"seconds": oDate.getSeconds()
	};

	if (oTime["hours"] == oArgs(HourParam) && oTime["minutes"] == oArgs(MinuteParam)) {
		doTask();
		WScript.Sleep(SleepWholeProcess * 2);
	}
	
	WScript.Sleep(SleepWholeProcess);
	oDate = null;
}