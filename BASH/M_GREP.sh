#!/bin/sh
#############################################################
#支持递归搜索目录内的文本文件的关键字，支持部分正则表达式，保存当前搜索记录到当前路径
#支持统计目录下的文本文件的行数
#############################################################
cpath="`dirname $0`"
cd "$cpath"
#############################################################
LINES="l"
CHECH="c"
SEARCH="s"
TIME="t"
ICONV="i"
#############################################################
count(){
	for file in `ls $1`;do
		dir=$1"/""$file"
		if [ -d $dir ] && [ ! -L $dir ];then #//注意此处之间一定要加上空格，否则会报错
        		count "$dir"
        	elif test -f $dir;then
        		file $dir|grep "text">/dev/null
        		if [ "$?" = "0" ];then
        			tmp=`cat $dir|wc -l`
        			echo "$tmp ""\033[31m $dir \033[0m"
        			ct=`expr $ct + $tmp`
        		fi
        	fi
        done
}
#############################################################
translateDir(){
	#command targetDir from to .h,.c,.cpp,
	for file in `ls "$1"`;do			#//in 後面跟列表  並以‘ ’作爲間隔符
		dir="$1""/""$file"
        	if [ -d $dir ] && [ ! -L $dir ];then #//注意此处之间一定要加上空格，否则会报错
        		translateDir "$dir" "$2" "$3" "$4"
        	elif test ! -d $dir;then
        		file "$dir"|grep "text">/dev/null
        		if [ "$?" = "0" ];then
				#检查文件格式
				local tmpfile=`uuidgen`
				local filetype=`basename "$dir"`
				filetype=`echo $filetype |sed -r "s/^.+\././g"`
				echo "$4" |grep "${filetype}," > /dev/null
				if [ "$?" = "0" ]; then
					echo "\033[31m FILE:$dir \033[0m"
					iconv -f "$2" -t "$3" "$dir" > "$tmpfile"
					if [ $? = 0 ]; then
						cat "$tmpfile" > "$dir"
					fi
					rm -f "$tmpfile"
				fi
        		fi
        	fi
	done
}
#############################################################
read_dir(){
	for file in `ls "$1"`;do			#//in 後面跟列表  並以‘ ’作爲間隔符
		dir="$1""/""$file"
        	if [ -d $dir ] && [ ! -L $dir ];then #//注意此处之间一定要加上空格，否则会报错
        		read_dir "$dir"
        	elif test ! -d $dir;then
        		file "$dir"|grep "text">/dev/null
        		if [ "$?" = "0" ];then
        			#file $dir|grep "broken">/dev/null  #增加此判断将严重影响搜索速度！！！
        			#if [ "$?" != "0" ];then
        			echo "\033[31m $dir \033[0m"
				cat $dir -n|grep -E "$keytogrep" >>$outfile
				if [  "$?" = "0" ];then
					echo "FILE:$dir">>$outfile
				fi
        			#fi
        		fi
        	fi
	done
}
#############################################################
search(){
	if [ "$1" = "" ];then
		echo "\033[31m >>>no dir to grep...033[0m"
		return
	fi
	if [ "$2" = "" ];then
		echo "\033[31m >>>nothing to grep...033[0m"
		return
	fi
	fullpath="$1"
	keytogrep="$2"
	outfile="./`basename $0 .sh`.log"
	rm -f "$outfile"

	read_dir "$fullpath"

	tmpFile="$outfile".tmp	
	cat -n $outfile >"$tmpFile"
	echo "\033[31m >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m"
	while read line;do
		echo "$line"|grep -E "FILE:" >/dev/null 2>&1
		if [ $? = "0" ];then
			echo "\033[31m${line}\033[0m"
		else
			echo "$line"
		fi
	done < "$tmpFile"
	rm -f "$tmpFile"
	echo "\033[31m >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m"
}
#############################################################
flushTime(){
	for file in `ls "$1"`;do
		dir="$1/${file}"
		if [ -d $dir ] && [ ! -L $dir ];then
			flushTime "$dir"
		elif [ ! -d "$dir" ] && [ ! -L "$dir" ];then
			echo "$dir"
			fileName="`basename "$dir"`"
			tarGetFile="${tmpDir}/${fileName}"
			cat "$dir">"$tarGetFile"
			cat "$tarGetFile">"$dir"
			rm -f "$tarGetFile"
		fi
	done
}
#############################################################
checkName(){
	targetDir="$1"
	if [ ! -d "${targetDir}" ];then
		echo "[${targetDir}]不是目录..."
		return
	fi
        ALL_FILES_TMP_______="./`basename "$0" .sh`.log.tmp"
        ALL_DIR_TMP_________="$ALL_FILES_TMP_______".2
        FILE_NAME_IN_DIR_TMP="$ALL_FILES_TMP_______".3
        FILE_NAME_UNIQ______="$ALL_FILES_TMP_______".4
        OUT_FILE____________="$ALL_FILES_TMP_______".5
        rm -f "$ALL_FILES_TMP_______"
        rm -f "$ALL_DIR_TMP_________"
        rm -f "$FILE_NAME_UNIQ______"
        rm -f "$OUT_FILE____________"
        rm -f "$FILE_NAME_IN_DIR_TMP"

        du "$targetDir" -a|awk '{print $2}' > "$ALL_FILES_TMP_______" 2>/dev/null
	#保留目录
	while read line;do
		if [ -d "$line" ] && [ ! -L "$line" ];then
                        echo "$line" >> "$ALL_DIR_TMP_________"
		fi
        done < "$ALL_FILES_TMP_______"
	#遍历目录
        while read DIR ; do
                if [ -d "$DIR" ];then
			#提取目录下的对象
                        ls -A "$DIR" |sort > "$FILE_NAME_IN_DIR_TMP"
                        echo "\033[31m DIR:[$DIR]... \033[0m"
                        if [ `cat "$FILE_NAME_IN_DIR_TMP"|wc -l` -gt 0 ];then
                                #该目录下不为空
                                cat "$FILE_NAME_IN_DIR_TMP"|sort 2>/dev/null
                                #找到相同的名称
                                cat "$FILE_NAME_IN_DIR_TMP"|awk '{print toupper($0)}'|sort|uniq -d > "$FILE_NAME_UNIQ______"
                                if [ `cat "$FILE_NAME_UNIQ______"|wc -l` -gt 0 ];then
                                        #发现有相同的项
                                        #根据相同的项进行遍历
                                        while read UNIQ_NAME ;do
                                                while read SOURCE_NAME;do
                                                        uniq_upper_tmp="`echo "$UNIQ_NAME"|awk '{print toupper($0)}'`"
                                                        source_upper_tmp="`echo "$SOURCE_NAME"|awk '{print toupper($0)}'`"
                                                        if [ "$uniq_upper_tmp" = "$source_upper_tmp" ];then
                                                                realFile="$DIR/$SOURCE_NAME"
                                                                if [ -d "$realFile" ];then
                                                                        realFile="$realFile/"
                                                                fi
                                                                echo "$realFile" >> "$OUT_FILE____________"
                                                        fi
                                                done < "$FILE_NAME_IN_DIR_TMP"
                                        done < "$FILE_NAME_UNIQ______"
                                fi
			fi
                        #echo "................................................">>"$OUT_FILE____________"
		fi
        done < "$ALL_DIR_TMP_________"
	echo "\033[31m >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m"
        cat "$OUT_FILE____________" 2>/dev/null
	echo "\033[31m >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \033[0m"

        rm -f "$ALL_FILES_TMP_______"
        rm -f "$ALL_DIR_TMP_________"
        rm -f "$FILE_NAME_UNIQ______"
        rm -f "$OUT_FILE____________"
        rm -f "$FILE_NAME_IN_DIR_TMP"
}
#############################################################
#入口
#############################################################
#统计文本行数
if [ "$1" = "$LINES" ] && [ "$2" != "" ] && [ "$3" = "" ];then 
	if test -d "$2";then
		echo "$BASH_LINENO""\033[31m counting line... \033[0m"
		ct=0
		count "$2"
		echo "$BASH_LINENO""\033[31m >>>total line is $ct \033[0m"
	else
		echo "$BASH_LINENO""\033[31m $2 must be dir... \033[0m"
		exit 1
	fi
#在dir中搜索key
elif [ "$1" = "$SEARCH" ] && [ -d "$2" ] && [ "$3" != "" ] && [ "$4" = "" ];then     
	echo "$BASH_LINENO""\033[31m searching key... \033[0m"
	echo $*
	search "$2" "$3"
#刷新文件夹内所有文件的时间戳
elif [ "$1" = "$TIME" ] && [ "$2" != "" ] && [ "$3" = "" ];then 
	if [ -d "$2" ];then
		tmpDir="/tmp/NEW"
		if [ ! -d "$tmpDir" ];then
			mkdir -p "$tmpDir">/dev/null
			if [ "$?" != "0" ];then
				echo "创建临时目录:[${tmpDir}]失败..."
				exit 1
			fi
		fi
		flushTime "$2"
	else
		echo "$BASH_LINENO""\033[31m $2 must be dir... \033[0m"
		exit 1
	fi
#检查目录中是否存在相同的文件夹或者文件（windows下不区分大小写！）
elif [ "$1" = "$CHECH" ] && [ -d "$2" ] && [ "$3" = "" ]; then
	checkName "$2"
elif [ "$1" = "$ICONV" ]; then
	echo $#,$*
	translateDir "$2" "$3" "$4" "$5"
#出错处理
else
	echo "$BASH_LINENO""\033[31m sh `basename $0` $LINES [dir] \033[0m"
	echo "$BASH_LINENO""\033[31m sh `basename $0` $SEARCH [dir] [key2grep] \033[0m"
	echo "$BASH_LINENO""\033[31m sh `basename $0` $TIME [dir] \033[0m"
	echo "$BASH_LINENO""\033[31m sh `basename $0` $CHECH [dir] \033[0m"
	echo "$BASH_LINENO""\033[31m sh `basename $0` $ICONV [dir] [from] [to] [.h,.c,.cpp,]\033[0m"
fi
#############################################################
