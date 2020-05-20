cpath="`dirname $0`"
cd $cpath
pwd
echo "$0"
addr="1"
endaddr="254"
tmpfile="./mytmp.txt"
outfile="./`basename $0`.log"
ipaddr="192.168.0."
count="0"
while [ 1 -eq 1 ]
do 
echo $ipaddr$addr
if [ $addr -gt $endaddr ];then
	echo ">>>THE END OF 'ping'"
	echo ">>>available ip count = $count"
	exit
fi
ping -c 3 $ipaddr$addr |grep "100% packet loss"
if [ $? = "0" ];then
	echo "`date '+%Y-%m-%d %H:%M:%S'` pid = $$ "$ipaddr$addr >>$outfile
	count=`expr $count + 1`
fi
rm -f $tmpfile
#((addr=addr+1))
addr=`expr $addr + 1`
#sleep 1
done
