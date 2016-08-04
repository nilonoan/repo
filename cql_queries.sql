select count(*) from auditing.user_configuration_change
where 
date in ('2016.06.01','2016.06.02','2016.06.03','2016.06.04','2016.06.05','2016.06.06','2016.06.07','2016.06.08','2016.06.09','2016.06.10','2016.06.11','2016.06.12','2016.06.13','2016.06.14','2016.06.15','2016.06.16','2016.06.17','2016.06.18','2016.06.19','2016.06.20','2016.06.21','2016.06.22','2016.06.23','2016.06.24','2016.06.25','2016.06.26','2016.06.27','2016.06.28','2016.06.29','2016.06.30','2016.06.31') 
and hour in (0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23) 
and auditlevel in ('Low', 'Medium', 'High') allow filtering;

drop index if exists auditing.date1_index;
drop index if exists auditing.hour1_index;
drop index if exists auditing.action1_index;
drop index if exists auditing.appname1_index;
drop index if exists auditing.role1_index;

create index if exists date1_index on auditing.user_configuration_change (date);

