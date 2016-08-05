#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
cont=0
for f in $(find . test -name '*.*' -type f)
do
	(( cont += 1 ))
	datetime=$(stat -c %y "$f")
		
	date=$(echo "$datetime"| cut -c1-10 | sed 's/^0*//')
	hour=$(echo "$datetime"| cut -c12-13 | sed 's/^0*//')
	minute=$(echo "$datetime"| cut -c15-16 | sed 's/^0*//')
	second=$(echo "$datetime"| cut -c18-19 | sed 's/^0*//')
	
	hourvalue=$(echo "17")
	minutevalue=$(echo "22")
	secondvalue=$(echo "0")

	if [[ ( $date == "2016-08-05" ) ]] && (( hour >= hourvalue )) && (( minute >= minutevalue )) && (( second >= secondvalue ))
	then
		echo "$f"
	fi	

done
IFS=$SAVEIFS 