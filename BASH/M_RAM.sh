#!/bin/bash
cp="`dirname "$0"`"
cd "$cp"

libFile="M_LIBS.sh"
if [ ! -f ./"$libFile" ];then
	echo "FILE:[`pwd`/$libFile] LOST..."
	exit 1
fi
. ./$libFile

netcardname="wlan0"
ret=`M_GET_INTERFACE_INFO $netcardname`
echo "$ret"|grep -E "\?">/dev/null 2>&1
if test "$?" = "0";then
	netcardname="eth1"
fi


while true;do

	
	
        currentTime=`M_GET_TIME`
	currentTime=`echo "$currentTime"|cut -c 1-10`
	#echo "$tt" `cat ./log/default/$currentTime.log |wc -l` `cat ./log/default/$currentTime.log |wc -c` 
	
        net=`M_GET_NET_SPEED "$netcardname"`
	recvold=`echo $net|sed "s/ .*$//g"`
	sendold=`echo $net|sed "s/^[0-9]* *//g"`
        timeold=`M_GET_TIME_NS`
	
        str=`M_GET_CPU_RATE`
	zongshu1=`echo "$str"|awk '//{print $1}'`
	weishu1=`echo "$str"|awk '//{print $2}'`
	sleep 1
        str=`M_GET_CPU_RATE`
	zongshu2=`echo "$str"|awk '//{print $1}'`
	weishu2=`echo "$str"|awk '//{print $2}'`
	
        rate=`M_GET_VALUE "(1-($weishu2-$weishu1)/($zongshu2-$zongshu1))*100"`

	echo "$rate"|grep -E "^\.[0-9]*">/dev/null 2>&1
	if [ "$?" = "0" ];then
		rate=0"$rate"
	fi
	dotindex=`echo "$rate"|awk '//{print index($0,".")}'`
	rate=`echo "$rate"|cut -c 1-$dotindex``echo "$rate"|cut -c $dotindex-|cut -c 2-7`%
	
        net=`M_GET_NET_SPEED "$netcardname"`
	recv=`echo $net|sed "s/ .*//g"`
	send=`echo $net|sed "s/^[0-9]* *//g"`
        time=`M_GET_TIME_NS`
	
	
	#得到時間差  高精度
        time=`M_GET_VALUE "($time - $timeold)/1000000000"`
	#得到這段時間的流量  Byte
	recv=$(($recv - $recvold))
	send=$(($send - $sendold))
	
        recv=`M_GET_VALUE "scale=3;$recv /($time)/1024"`
        send=`M_GET_VALUE "scale=3;$send /($time)/1024"`
	

	if test `expr $recv : "^\.[0-9]*"` != "0";then
		recv=0${recv}
	fi
	if test `expr $send : "^\.[0-9]*"` != "0";then
		send=0${send}
	fi
	if test $recv = "0";then
		recv=0.000
	fi
	if test $send = "0";then
		send=0.000
	fi
	recv=$recv"K/s"
	send=$send"K/s"
        str=`M_GET_INTERFACE_INFO "$netcardname"`
        tt="`M_GET_RAM`"
	logstr=$str" "$tt" CPU: "$rate" IN: "${recv}" OUT: "${send}
	#log "$netcardname $logstr"
        M_LOG "./log" "shell" "$netcardname $logstr"
	echo -e "\033[46m${netcardname} ${str}\033[0m"
	echo -e "$tt" "\t" CPU: "$rate" "\t" IN: ${recv} "\t\t" OUT: ${send}
done
exit
