@ECHO ON

REM We set our user and password to log in to jira
SET USER=conde
SET PASSWORD=123456@

REM We set the time when we want to trigger this script
SET HOUR=15
SET MINUTE=34

REM We call javascript file
cscript jira.js %USER% %PASSWORD% %HOUR% %MINUTE%
pause