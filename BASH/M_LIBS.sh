#!/bin/bash
#@author:tf.du
#@date:2017-06-16
#############################################################
M_GET_TIME()
{ #獲取時間戳 2016-01-01 01:01:01.000
	#獲得納秒級別的數值
	local ms=`date "+%N"`
	#得到毫秒數
	#ms=$(( $ms / 1000000 ))
	local ms=`echo "$ms"|cut -c 1-3`
	#組裝當前時間
	local time=`date "+%Y-%m-%d %H:%M:%S"."$ms"`
	echo "$time"
}
#############################################################
M_GET_TIME_NS()
{
	local timeold_s=`date "+%s"`
	local timeold=`echo  "${timeold_s} * 1000000000"|bc -l`
	local timeold_ns=`date "+%N"`
	local timeold=`echo  "$timeold + $timeold_ns"|bc -l`
	echo "$timeold"
}
#############################################################
M_GET_VALUE()
{
	if test "$#" != 1;then 
		echo "0"
		return
	fi
	local str="$1"
	echo `echo "$str"|bc -l`
}
#############################################################
M_LOG()
{  
	#./XXX/2016-01-01/shell_2016-01-01.log
	#log "dir" "fileNamePrefix" "content"
	#log "./log" "shell" "系统异常..."
	if [ $# != 3 ];then
		return
	fi
	local dirName="$1"
	local fileNamePrefix="$2"
	local content="$3"
	local nowTime=`date "+%Y-%m-%d"`
        local currentTime=`M_GET_TIME`
	local logFileDir="$dirName/$nowTime"
	local logFilePath="$logFileDir/${fileNamePrefix}_${nowTime}.log"
	if [ ! -d "${logFileDir}" ];then
		mkdir -p "$logFileDir"
		if [ $? -gt 0 ];then
			return 
		fi
	fi
	local content="$currentTime $content"
	echo "$content" >> "$logFilePath"
}
#############################################################
M_GET_RAM()
{       #獲取當前系統RAM使用情況 99.999999%
	local strMeminfo=`cat /proc/meminfo`
	
	local MemFree=`echo "$strMeminfo" |grep -E "^MemFree:"|sed "s/^.*:  *//g"|sed "s/  *.*$//g"`
	local MemTotal=`echo "$strMeminfo" |grep -E "^MemTotal:"|sed "s/^.*:  *//g"|sed "s/  *.*$//g"`
	local Buffers=`echo "$strMeminfo" |grep -E "^Buffers:"|sed "s/^.*:  *//g"|sed "s/  *.*$//g"`
	local Cached=`echo "$strMeminfo" |grep -E "^Cached:"|sed "s/^.*:  *//g"|sed "s/  *.*$//g"`

        local MemUsed=`M_GET_VALUE "$MemTotal - $MemFree - $Buffers - $Cached "`
	#scale針對除法才有效
        local rate=`M_GET_VALUE "scale=6;($MemUsed / $MemTotal)*100"`
        local totalRam=`M_GET_VALUE "scale=3;${MemTotal}/1024/1024"`
	if test `expr "$totalRam" : "^\.[0-9]*"` != "0";then
		local totalRam=0"$totalRam"
	fi
	echo  "RAM: ${rate}% ${totalRam}GB"
}
#############################################################
M_GET_NET_SPEED()
{
	#請傳入一個參數  網卡名  例如  eth0
	local devName="$1"
	if test `expr "$devName" : "^[a-zA-Z0-9]*$"` = "0";then
		local devName="eth0"
	fi
	local strNet=`cat /proc/net/dev|grep "$devName"`
	local recv=`echo "$strNet"|sed "s/^ *[a-zA-Z]*[0-9]*: *//g"|sed "s/  *..*//g"`
	local send=`echo "$strNet"|sed "s/^ *[a-zA-Z]*[0-9]*: *//g"|\
	sed "s/^[0-9][0-9]*  *[0-9][0-9]*  *[0-9][0-9]*  *[0-9][0-9]*  *[0-9][0-9]*  *[0-9][0-9]*  *[0-9][0-9]*  *[0-9][0-9]*  *//g"|\
	sed "s/  *..*$//g"`
	#我操上面寫了一大堆  請看下面一句話搞定
	#awk  截取字符串
	#cat /proc/net/dev|grep "eth0"|awk -F ':' '{print $2}'|awk -F " " '{print $1" "$9}'
	#用這個更爽
	#cat /proc/net/dev|awk '/eth0:/{print $2" "$10}'
	if test `expr "$recv" : "^[0-9]*$"` = "0";then
		local recv="?"
	fi
	if test `expr "$send" : "^[0-9]*$"` = "0";then
		local send="?"
	fi
	echo "${recv} ${send}"
}
#############################################################
M_GET_INTERFACE_INFO()
{
	#請傳入一個參數  網卡名  例如  eth0
	local interface="$1"
	echo "$interface"|grep -E "^[a-zA-Z][a-zA-Z]*[0-9]*$" >/dev/null 2>&1
	if [ "$?" != "0" ];then
		local interface="eth0"
	fi
	ifconfig "$interface">/dev/null 2>&1
	if test "$?" != "0";then
		echo "?"
		return
	fi
	local str=`ifconfig "$interface"`
	#中文系统英文系统尼吗出来的结果不同
	echo "$str"|grep "硬件地址">/dev/null 2>&1
	if test "$?" = "0";then
		local HWaddr=`echo "$str"|grep -E "硬件地址"|sed "s/^.*硬件地址  *//g"|sed "s/ *$//g"`
		local addr=`echo "$str"|grep -E "inet 地址"|sed "s/^.*inet 地址: *//g"|sed "s/  *.*$//g"`
		local Bcast=`echo "$str"|grep -E "广播"|sed "s/^.*广播: *//g"|sed "s/  *.*$//g"`
		local Mask=`echo "$str"|grep -E "掩码"|sed "s/^.*掩码: *//g"|sed "s/  *.*$//g"`
	else
		local HWaddr=`echo "$str"|grep -E "HWaddr"|sed "s/^.*HWaddr  *//g"|sed "s/ *$//g"`
		local addr=`echo "$str"|grep -E "inet addr"|sed "s/^.*inet addr: *//g"|sed "s/  *.*$//g"`
		local Bcast=`echo "$str"|grep -E "Bcast"|sed "s/^.*Bcast: *//g"|sed "s/  *.*$//g"`
		local Mask=`echo "$str"|grep -E "Mask"|sed "s/^.*Mask: *//g"|sed "s/  *.*$//g"`
	fi
	
	echo "$HWaddr"|grep -E "^([a-zA-Z0-9]{2}:){5}[a-zA-Z0-9]{2}$">/dev/null 2>&1
	if test "$?" != "0";then
		local HWaddr="?"
	fi
	echo "$addr"|grep -E "^([0-9][0-9]*\.){3}[0-9][0-9]*$">/dev/null 2>&1
	if test "$?" != "0";then
		local addr="?"
	fi
	echo "$Bcast"|grep -E "^([0-9][0-9]*\.){3}[0-9][0-9]*$">/dev/null 2>&1
	if test "$?" != "0";then
		local Bcast="?"
	fi
	echo "$Mask"|grep -E "^([0-9][0-9]*\.){3}[0-9][0-9]*$">/dev/null 2>&1
	if test "$?" != "0";then
		local Mask="?"
	fi
	echo "$HWaddr" "$addr" "$Bcast" "$Mask"
}
#############################################################
M_GET_CPU_RATE()
{
	#cat /proc/stat | grep 'cpu ' 
	#1-(兩次4 5 6 7參數之差)/(兩次1 2 3 4 5 6 7之差)
	local canshu="`cat /proc/stat | grep -E 'cpu '|awk '//{print $2" "$3" "$4" "$5" "$6" "$7" "$8}'`"
	local canshu1=`echo "$canshu"|awk '//{print $1}'`
	local canshu2=`echo "$canshu"|awk '//{print $2}'`
	local canshu3=`echo "$canshu"|awk '//{print $3}'`
	local canshu4=`echo "$canshu"|awk '//{print $4}'`
	local canshu5=`echo "$canshu"|awk '//{print $5}'`
	local canshu6=`echo "$canshu"|awk '//{print $6}'`
	local canshu7=`echo "$canshu"|awk '//{print $7}'`
        local canshu=`M_GET_VALUE "$canshu1 + $canshu2 + $canshu3 + $canshu4 + $canshu5 + $canshu6 + $canshu7  "`
        local canshu_4567=`M_GET_VALUE "$canshu4 + $canshu5 + $canshu6 + $canshu7  "`
	echo "$canshu" "$canshu_4567"
}
#############################################################
M_GET_ONLY_ID()
{
	#獲取主機唯一編碼
	local onlyid=`echo "$1"|sudo -S cat /sys/class/dmi/id/product_uuid`
	echo "$onlyid"
}
#############################################################
M_GET_RAND_STR()
{	#M_GET_RAND_STR A length
	#A=  1純數字 2純字母 3數字+字母
	#length>=1
	local type="$1"
	local length=$2
	if test "`expr "$type" : "^[1-3]$"`" = "0";then
		local type="1"
	fi
	if test "`expr "$length" : "^[1-9][0-9]*$"`" = "0";then
		local length="1"
	fi
	if test "$type" = "1";then
		local sourcestr=(0 1 2 3 4 5 6 7 8 9)
	fi
	if test "$type" = "2";then
		local sourcestr=(a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)
	fi
	if test "$type" = "3";then
		local sourcestr=(0 1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)
	fi
		
	local RETSTR=""
	local LENGTH="$length"
	local sourcestrlength="${#sourcestr[*]}"
	while true;do
		#先生成3位數的數字%數組元素個數
		local length="3"
		local retstr=""
		while true;do
			#顯得倒0-9的個位隨機數
			local str=$RANDOM
			
			local str=$(( $str % 100 / 10))
			local retstr="$retstr""$str"

			if [ "${#retstr}" -ge "$length" ] ;then
				break
			fi
		done
		#去掉左邊的‘0’
		local retstr=`echo "$retstr"|sed "s/^[0]*//g"`
		#當全爲“000”時賦“0”
		if [ "${#retstr}" -lt "1" ] ;then
			local retstr="0"
		fi
		#下面計算方式 不能打引號  要計算的數不能從’0‘開頭
		local retstr=$(( ${retstr} % $sourcestrlength ))
	
		local RETSTR="$RETSTR""${sourcestr[$retstr]}"
		if [ "${#RETSTR}" -ge "$LENGTH" ] ;then
			break
		fi
	done
	echo "$RETSTR"
}
#############################################################
M_RECURSION_DEL(){
        #M_RECURSION_DEL "." 3
	#$1 路徑　如： ./log 　　或者：　.
	#$2 超時天數　如：　３
	#遞歸刪除指定文本文件　　./log/XXX/2016-01-01.log
	for file in `ls "$1"`;do
		local dir="$1"/"$file"
		
		if [ -d "$dir" ] && [ ! -L "$dir" ];then
                        M_RECURSION_DEL "$dir" "$2"
		fi
		local totalDays="$2"
		if test -f "$dir" -a ! -L "$dir";then
			#去掉文件路徑　　去掉文件後綴
			local logfilename=`echo "$dir"|sed "s/^.*\///g"|sed "s/\..*$//g"`
			if test `expr "$logfilename" : "^[0-9]*-[0-9]*-[0-9]*$"` -eq 0;then
				continue
			fi
			local logfilename=`date -d "$logfilename" +%s 2>/dev/null`
			#!!!　　如果ｄａｔｅ命令失敗　　這裏不能檢查$?變量是否爲１　　因爲加了ｌｏｃａｌ命令　　
			if test `expr length "$logfilename"` -eq 0;then
                                local logfilename="`M_GET_TIME`"
				local logfilename=`echo "$logfilename"|sed "s/ .*$//g"`
				local logfilename=`date -d "$logfilename" +%s 2>/dev/null`
			fi
                        local nowtime="`M_GET_TIME`"
			local nowtime=`echo "$nowtime"|sed "s/ .*$//g"`
			local nowtime=`date -d "$nowtime" +%s 2>/dev/null`
			local biaodashi="(""$nowtime""-""$logfilename"")/(24*3600)"
                        local subDayS=`M_GET_VALUE "$biaodashi"`
			#去掉小數
			if test `expr "$subDayS" : "^\..*$"` -gt 0;then
				local subDayS=0
			fi
			#去掉尾數
			local subDayS=`echo "$subDayS"|sed "s/\..*$//g"`
			#檢查是否爲整型
			if test `expr "$subDayS" : "^[0-9]*$"` -eq 0;then
				local subDayS=0
			fi
			if test "$subDayS" -ge "$totalDays";then
				rm -rf "$dir"
			fi
		fi
	done	
}
#############################################################
M_CHARACTER_2_HEX_STR(){
        #M_CHARACTER_2_HEX_STR "A"
	#获得一个字符的ascii码的hex
	##不可见字符不好使。。。
	#有些字符也不好使。。。
	local str="$1"
	local tmpstr="00"
	if [ `expr length "$str"` -lt 1 ];then
		echo "$tmpstr"
		return
	fi
	
	local str=`echo -e "$str"|od -x|sed '2,$d'|sed 's/^.*\ ..//g'`
	if [ ${#str} -ne 2 ];then
		echo "$tmpstr"
		return
	fi
	
	echo "$str"
}
#############################################################
M_CHARACTER_STR_2_HEX_STR(){
        #M_CHARACTER_STR_2_HEX_STR "ABC"
	#获得字符串的ascii码的hex
	#不可见字符不好使。。。
	#有些字符也不好使。。。
	local ttt="$1"
	local tttlength=`expr length "$ttt"`
	if [ "$tttlength" -lt 1 ];then
		echo ""
		return
	fi
	
	local i=0
	local ret=""
	for ((i=0;i<${tttlength};i++));do
                local ret=${ret}`M_CHARACTER_2_HEX_STR "${ttt:$i:1}"`
	done
	echo "$ret"
}
#############################################################
M_TOUCH_FILE_NAME()
{
        #M_TOUCH_FILE_NAME ./log "2016-01-01 00:00:00"
	#递归更改文件夹下的文件时间戳
	#第二个参数 可不传即默认为当前系统时间
	for file in `ls "$1"`;do
		local dir="$1"/"$file"
		echo "$dir"
		if [ -d "$dir" ] && [ ! -L "$dir" ];then
                        M_TOUCH_FILE_NAME "$dir" "$2"
		fi
		if [ -f "$dir" ];then
			local notTime="$2"
			if [ `expr length "$2"` -lt 1 ];then
				local notTime="`date "+%F %T"`"
			fi
			touch -amd "$notTime" "$dir"
		fi
	done
}
#############################################################
M_CREATE_AUTO_START_FILE(){
        #M_CREATE_AUTO_START_FILE "MYAPP.desktop" "MYAPPNAME" "/home/ipst/run/start.sh"
	#创建桌面快捷启动方式
	#执行成功返回 0,失败返回 1
	local outFileName="$1"
	local name="$2"
	local execFileNameFull="$3"
	#检查输入参数是否为空
	if test "`expr length "$outFileName"`" -le 0 || test "`expr length "$execFileNameFull"`" -le 0 || test `expr length "$name"` -le 0 ;then
		return 1
	fi
	#清空文件
	echo ""                              > "$outFileName"
	echo "[Desktop Entry]"               >>"$outFileName"
	echo "Type=Application"              >>"$outFileName"
	echo "Exec=${execFileNameFull}"      >>"$outFileName"
	echo "Hidden=false"                  >>"$outFileName"
	echo "NoDisplay=false"               >>"$outFileName"
	echo "X-GNOME-Autostart-enabled=true">>"$outFileName"
	echo "Name[zh_CN]=${name}"           >>"$outFileName"
	echo "Name=${name}"                  >>"$outFileName"
	echo "Comment[zh_CN]=${name}"        >>"$outFileName"
	echo "Comment=${name}"               >>"$outFileName"
	#删除文件中的空行
	sed -E '/^\s*$/d' -i "$outFileName"
	return 0
}
#############################################################
M_SET_NOPASSWD(){
	#M_SET_NOPASSWD "ipst" "ipst"
	local userName="$1"
	local userPasswd="$2"
	local data="${userName} ALL=(ALL) NOPASSWD: /sbin/reboot,/sbin/poweroff"
	local targetFile="/etc/sudoers"
	local tmpFile="/tmp/`basename ${targetFile}`.tmp"

	#检查是否合法用户
	groups "$userName" >/dev/null 2>&1
	if [ $? != 0 ];then
		return 1
	fi
	#判断是否已经设置
	echo "$userPasswd"|sudo -S cat "$targetFile"|grep "${data}" > /dev/null 2>&1
	if [ $? != 0 ];then
		#提取内容
		echo "$userPasswd"|sudo -S cat "$targetFile" > "$tmpFile"
		if [ $? != 0 ];then
			return 1
		fi
		#添加内容
		echo "$data" >> "$tmpFile"
		#覆盖原文件
		echo "$userPasswd"|sudo -S cp -f "$tmpFile" "$targetFile" >/dev/null 2>&1
		local ret="$?"
		#清理垃圾
		rm -f "$tmpFile" >/dev/null 2>&1
		if [ $ret != 0 ];then
			return 1
		fi
	fi
	return 0
}
#############################################################
M_SET_GRUB_TIMEOUT(){
	#M_SET_GRUB_TIMEOUT "0" "ipst"
	local timeout="$1"
	local userPasswd="$2"
	local targetFile="/etc/default/grub"
	local tmpFile="/tmp/`basename "$targetFile"`.tmp"
	local data="GRUB_RECORDFAIL_TIMEOUT=${timeout}"

	if [ "$timeout" -lt 0 ];then
		return 1
	fi
	#删除指定内容
	echo "$userPasswd"|sudo -S sed -i "/^[[:blank:]]*GRUB_RECORDFAIL_TIMEOUT[[:blank:]]*=/d" "$targetFile" >/dev/null 2>&1
	if [ $? != 0 ];then
		return 1
	fi
	#提取内容
	echo "$userPasswd"|sudo -S cat "$targetFile" > "$tmpFile"
	if [ $? != 0 ];then
		return 1
	fi
	#添加内容
	echo "${data}" >> "${tmpFile}"
	#覆盖原文件
	echo "$userPasswd"|sudo -S cp -f "${tmpFile}" "${targetFile}" >/dev/null 2>&1
	local ret="$?"
	#清理垃圾
	rm -f "${tmpFile}" >/dev/null 2>&1
	if [ $ret != 0 ];then
		return 1
	fi
	update-grub >/dev/null 2>&1
	return 0
}
#############################################################











