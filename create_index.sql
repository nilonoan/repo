CREATE INDEX IF NOT EXISTS remarks_index ON auditing.system_configuration_change (remarks);
SELECT * FROM auditing.system_configuration_change WHERE remarks = 'logged in user: AlertUser';
DROP INDEX auditing.remarks_index;
