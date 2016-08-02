select date,hour,auditlevel,appname, dateof(time), action, actiontype from auditing.user_configuration_change
where 
date = '2016.07.27' 
and hour in (0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23) 
and auditlevel in ('Low','Medium', 'High')

allow filtering;

