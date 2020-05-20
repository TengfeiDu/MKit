#!/bin/sh
#############################################################
#根据二进制程序查找本地动态库并拷贝到当前目录
#示例：sh ./mFindLibs.sh ./serialTool
#保存库文件夹：./mFindLibs/
#提示：部分库文件需要手动拷贝
#############################################################
cpath="`dirname $0`"
cd "$cpath"
#############################################################
binFile="$1"
if [ ! -f "${binFile}" ];then
	echo "程序文件：[${binFile}]不存在..."
	exit 1
fi
#############################################################
outDir="`basename "$0" .sh`"
if [ ! -d "./$outDir" ];then
	mkdir "./$outDir"
	if [ $? != 0 ];then
		echo "创建输出文件夹：[./${outDit}]失败..."
		exit 1
	fi
fi
#############################################################
cd ./"$outDir"
rm -rf ./*
cd ..
#############################################################
#创建临时文件
tmpFile="`basename "$0" .sh`.tmp"
#存放未识别的ldd结果
tmpFile2="${tmpFile}2"
rm -rf "./${tmpFile}"
rm -rf "./${tmpFile2}"
touch "./${tmpFile2}"
touch "./${tmpFile}"
#############################################################
#跟踪链接文件，返回真实文件路径，全路径
mGetRealPath()
{
	local lianJieFile="$1"
	if [ -f "$lianJieFile" ];then
		if [ -L "$lianJieFile" ];then
			local tmp=`ls -l "$lianJieFile"|sed -E "s/^.*\ ->\ //g"|sed -E "s/\ *$//g"`
			tmp=`echo "$lianJieFile"|sed -E "s/\/[^/]*$//g"`/${tmp}
			if [ -L "$tmp" ];then
				mGetRealPath "$tmp"
			fi
			echo "${tmp}"
		else
			echo "$lianJieFile"
		fi
	fi
}
#############################################################
ldd "${binFile}">"./${tmpFile}"
while read line;do
	echo "${line}"|grep -E "\(0x.*\)"|grep -E "\ =>\ /">/dev/null
	if [ $? = 0 ];then
		#程序文件依赖的文件名
		realName=`echo "${line}"|sed "s/\ =>.*$//g"|sed "s/^\ *//g"`
		#库文件全路径
		tarGetPath=`echo "${line}"|sed "s/^.*\ =>\ //g"|sed -E "s/\ +.*$//g"`
		tarGetPath=`mGetRealPath "${tarGetPath}"`
		#跟踪失败
		if [ ! -f "${tarGetPath}" ];then
			echo "${line}">>"./${tmpFile2}"
			continue
		fi 
		tarGetFileName=`echo "${tarGetPath}"|sed "s/^.*\///g"`
		#拷贝并更改动态库的文件名
		cp -rf "${tarGetPath}" "./${outDir}/${realName}"
		continue
	fi
	echo "$line"|grep -E "^/.*"|grep -E "\(0x.*\)$">/dev/null
	if [ $? = 0 ];then
		realName=`echo "$line"|sed -E "s/\ .*$//g"|sed -E "s/^.*\///g"`
		tarGetPath=`echo "$line"|sed -E "s/\ .*$//g"|sed -E "s/^\ *//g"`
		tarGetPath=`mGetRealPath "${tarGetPath}"`
		#跟踪失败
		if [ ! -f "${tarGetPath}" ];then
			echo "${line}">>"./${tmpFile2}"
			continue
		fi 
		cp -rf "${tarGetPath}" "./${outDir}/${realName}"
		continue
	fi
	echo "${line}">>"./${tmpFile2}"
	continue
done < "./${tmpFile}"
#############################################################
echo "\033[31m剩余项：\033[0m"
cat "./${tmpFile2}"
echo "\033[31m输出文件夹：[`pwd`/${outDir}]\033[0m"
rm -rf "./${tmpFile2}"
rm -rf "./${tmpFile}"
#############################################################



