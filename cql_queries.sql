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

select * from auditing.user_configuration_change
where
date in ('2016.07.01','2016.07.02','2016.07.03','2016.07.04','2016.07.05','2016.07.06','2016.07.07','2016.07.08','2016.07.09','2016.07.10','2016.07.11','2016.07.12','2016.07.13','2016.07.14','2016.07.15','2016.07.16','2016.07.17','2016.07.18','2016.07.19','2016.07.20','2016.07.21','2016.07.22','2016.07.23','2016.07.24','2016.07.25','2016.07.26','2016.07.27','2016.07.28','2016.07.29','2016.07.30','2016.07.31') 
and hour in (0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23) 
and auditlevel in ('Low', 'Medium', 'High') limit 100 allow filtering;

find . -name '*.qml' -print | grep -i '' | less


#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
cont=0
for f in $(find . chile -name '*.*')
do
	(( cont += 1 ))
	datetime=$(stat -c %y "$f")
		
	date=$(echo "$datetime"| cut -c1-10)
	hour=$(echo "$datetime"| cut -c12-13)
	minute=$(echo "$datetime"| cut -c15-16)
	
	hourvalue=$(echo "14")
	minutevalue=$(echo "45")

	if [[ ( $date == "2016-08-03" ) ]] && (( hour >= hourvalue )) && (( minute >= minutevalue ))
	then
		echo "$f"
	fi
done
IFS=$SAVEIFS 

