@ECHO OFF

REM We set our user and password to log in to jira
SET USER=conde
SET PASSWORD=123456q@

REM We set the time when we want to trigger this script
SET HOUR=8
SET MINUTE=22

REM We set the navigator application name to be used to open the log-in web page
REM Eihter "firefox" or "chrome" value are possible
SET APP_NAVIGATOR=chrome

REM We call javascript file
cscript jira.js "%USER%" "%PASSWORD%" "%HOUR%" "%MINUTE%" "%APP_NAVIGATOR%"

REM We make a pause
pause