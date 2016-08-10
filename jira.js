var ForReading = 1;
var ForWriting = 2;

var WebPage = "jira.html";

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
	content = f.ReadAll();
	f.Close();
	f = null

	f = oFso.OpenTextFile(WebPage, ForWriting, true);
	f.Write(content.replace(/\[\[OS_USERNAME\]\]/g, oArgs(UserParam)).replace(/\[\[OS_PASSWORD\]\]/g, oArgs(PwdParam)));
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
		WScript.Echo("run doTask()");
		doTask();
		WScript.Sleep(SleepWholeProcess * 2);
	}
	
	WScript.Echo(oTime["hours"]);
	WScript.Echo(oTime["minutes"]);
	
	WScript.Sleep(SleepWholeProcess);
	oDate = null;
}