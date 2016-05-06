#!/bin/bash
: '
***********************************************************************************
example about how to call this bash file:

./gitdiff.sh /p/Users/conde/git/chile diff.loto3.txt -options="text:auto-generated|folder:build-IMTSProject-Desktop_Qt_5_3_GCC_32bit-Debug,build-IMTSProjectCH-Desktop_Qt_5_3_GCC_32bit-Debug|ext:json~,pri~,docx,db,png,jpg,pro.user,pro.user.b1d8dfe,qmlproject.user,pri,dat|pathname:NVRAM/data_img1,IMTSScriptTools/CreateDBusAdaptorAndInterfaceClasses" > loto3.clean.txt

***********************************************************************************
'

op_path=$(echo $1)
op_path=$op_path"/"

op_diff_file=$(echo $2)

substring=$(echo $3| cut -c10-)
op_text=$(echo $substring| cut -d':' -f2)
op_text=$(echo $op_text| cut -d'|' -f1)

op_folder=$(echo $substring| cut -d':' -f3)
op_folder=$(echo $op_folder| cut -d'|' -f1)

op_ext=$(echo $substring| cut -d':' -f4)
op_ext=$(echo $op_ext| cut -d'|' -f1)

op_pathname=$(echo $substring| cut -d':' -f5)

#-e=exclude (default) | -i=include
op_type=$(echo $4| cut -c2-)
if [ -z "$op_type" ]
then
	op_type="e"
fi

while IFS='' read -r line || [[ -n "$line" ]]; do
	fullpath=$op_path$line

	IFS=',' read -r -a array_text <<< "$op_text"

	flag_text=0
	for element in "${array_text[@]}"
	do
		if [ -f "${fullpath}" ] && grep -iq $(echo $element| sed -r 's/[-]+/\-/g') "${fullpath}"
		then
			flag_text=1
			break
		fi
	done

	IFS=',' read -r -a array_folder <<< "$op_folder"

	flag_folder=0
	for element in "${array_folder[@]}"
	do
		if [[ $line == *"/$element/"* ]]
		then
			flag_folder=1
			break
		fi
	done

	IFS=',' read -r -a array_ext <<< "$op_ext"

	flag_ext=0
	for element in "${array_ext[@]}"
	do
		if [[ $line == *".$element"* ]]
		then
			flag_ext=1
			break
		fi
	done

	IFS=',' read -r -a array_pathname <<< "$op_pathname"

	flag_pathname=0
	for element in "${array_pathname[@]}"
	do
		if [[ $line == *"$element"* ]]
		then
			flag_pathname=1
			break
		fi
	done

	if [[ ( $op_type == "e" ) && ( $flag_text -eq 0 && $flag_folder -eq 0 && $flag_ext -eq 0 && $flag_pathname -eq 0 ) ]]
	then
		echo $line
	fi

	if [[ ( $op_type == "i" ) && ( $flag_text -eq 1 || $flag_folder -eq 1 || $flag_ext -eq 1 || $flag_pathname -eq 1 ) ]]
	then
		echo $line
	fi
done < "$op_diff_file"
