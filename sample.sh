#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
cont=0
for f in $(find . ./chile -type f \( -name '*.h' -or -name '*.c' -or -name '*.cpp' -or -name '*.html' -or -name '*.htm' -or -name '*.qml' -or -name '*.js' -or -name '*.json' -or -name '*.txt' -or -name '*.css' \))
do
	(( cont += 1 ))
	datetime=$(stat -c %y "$f")
		
	date=$(echo "$datetime"| cut -c1-10 | sed 's/^0*//')
	hour=$(echo "$datetime"| cut -c12-13 | sed 's/^0*//')
	minute=$(echo "$datetime"| cut -c15-16 | sed 's/^0*//')
	
	hourvalue=$(echo "14")
	minutevalue=$(echo "45")

	hourvalue2=$(echo "15")
	minutevalue2=$(echo "0")

	if [[ ( $date == "2016-08-03" ) ]] && ( ( (( hour >= hourvalue )) && (( minute >= minutevalue )) ) || ( (( hour >= hourvalue2 )) && (( minute >= minutevalue2 )) ) )
	then
		echo "$f"
	fi	
done
IFS=$SAVEIFS 