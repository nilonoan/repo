@ECHO OFF

REM We set our user and password to log in to jira
SET USER=conde
SET PASSWORD=123456q@

REM We set the time when we want to trigger this script
SET HOUR=18
SET MINUTE=16

REM We call javascript file
cscript jira.js "%USER%" "%PASSWORD%" "%HOUR%" "%MINUTE%"
pause