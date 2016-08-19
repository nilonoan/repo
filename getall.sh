#!/bin/bash
excludeDir=$(echo "build-IMTSProject-Desktop_Qt_5_3_GCC_32bit-Debug;build-IMTSProjectCH-Desktop_Qt_5_3_GCC_32bit-Debug")

fileList=$(echo "00101.tmp")
fileFilterList=$(echo "00102.tmp")

branch=$(echo "$1")

[ -f "$fileList" ] && rm "$fileList"
[ -f "$fileFilterList" ] && rm "$fileFilterList"

git ls-tree -r --name-only "$branch" > "$fileList"

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
	
	if [ $count -eq 0 ] && [ -f "${PWD}/$line" ] && ! $(grep -iq "auto-generated" "${PWD}/${line}")
	then	
		echo $line >> "$fileFilterList"	
	fi	
done < "$fileList"

[ -f "$fileList" ] && rm "$fileList"

echo "Done"