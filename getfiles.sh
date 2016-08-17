#!/bin/bash
excludeDir=$(echo "build-IMTSProject-Desktop_Qt_5_3_GCC_32bit-Debug;build-IMTSProjectCH-Desktop_Qt_5_3_GCC_32bit-Debug")

fileHash=$(echo "00091.tmp")
fileList=$(echo "00092.tmp")
fileFilterList=$(echo "00093.tmp")
fileFinalList=$(echo "$2")

numLine=0

[ -f "$fileList" ] && rm "$fileList"
[ -f "$fileFilterList" ] && rm "$fileFilterList"

git log --pretty=format:"[ %h ] | [ %s ]" | grep -i "$1" > "$fileHash"

while IFS='' read -r line || [[ -n "$line" ]]; do
	numLine=$[numLine + 1]	
	hash=$(echo "$line" | cut -c3-9)
	git show --name-only --pretty="" $hash >> "$fileList"	
done < "$fileHash"

while IFS='' read -r line || [[ -n "$line" ]]; do	
	count=0
	while IFS=";" read -ra ADDR; do
		for i in "${ADDR[@]}"; do
			if test "${line#*$i}" != "$line"
			then
				count=$[count + 1]
			fi	
		done
	done <<< "$excludeDir"
	
	if [ $count -eq 0 ] && [ -f "${PWD}/$line" ] && ! (( $(grep -i "auto-generated" "${PWD}/$line") ))
	then	
		echo $line >> "$fileFilterList"	
	fi
done < "$fileList"

sort -u "$fileFilterList" > "$fileFinalList"

echo "Done"

[ -f "$fileHash" ] && rm "$fileHash"
[ -f "$fileList" ] && rm "$fileList"
[ -f "$fileFilterList" ] && rm "$fileFilterList"

