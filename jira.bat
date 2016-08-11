@ECHO OFF

REM We set our user and password to log in to jira
SET USER=conde
SET PASSWORD=123456q@

REM We set the time when we want to trigger this script
SET HOUR=0
SET MINUTE=5

REM We set the navigator application name to be used to open the log-in we page
SET APP_NAVIGATOR=firefox

REM We call javascript file
cscript jira.js "%USER%" "%PASSWORD%" "%HOUR%" "%MINUTE%" "%APP_NAVIGATOR%"

REM We make a pause
pause