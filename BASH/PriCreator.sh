#!/bin/bash
#author tf.du
#date 2019.01.01
#Create .pri file from target dir recursively which include *.h & *.cpp & *.c.

PATH_SOURCE="$1"
if [ ! -d "$PATH_SOURCE" ];then
	echo "`basename "$0"` [dir]"
	exit 1
fi
#提取绝对路径
PATH_SOURCE_FULL=`cd $PATH_SOURCE && pwd`
echo "目标路径 [$PATH_SOURCE_FULL]..."
if test ! -d $PATH_SOURCE_FULL; then
	echo "路径错误..."
	exit 1
fi
#提取目录名
TARGET_DIR_NAME=`basename $PATH_SOURCE_FULL`
#.pri
PRI_FILE_NAME=${TARGET_DIR_NAME}.pri
#切换到路径
cd $PATH_SOURCE_FULL
if [ $? != 0 ];then
	echo "路径切换失败..."
	exit 1
fi

#提取目录列表
tmpfile=`uuidgen`
tmpfile_h=`uuidgen`
tmpfile_cpp_c=`uuidgen`
touch $tmpfile
touch $tmpfile_h
touch $tmpfile_cpp_c
du . | awk '{print $2}' > $tmpfile
if [ $? != 0 ];then
	echo "目录提取失败..."
	test -f "$tmpfile" && rm -f $tmpfile
	test -f "$tmpfile_h" && rm -f $tmpfile_h
	test -f "$tmpfile_cpp_c" && rm -f $tmpfile_cpp_c
	exit 1
fi

#遍历目录
while read line; do
	echo "找到目录 [$line]..."
	for file in `ls $line`; do
                if test `basename "$file" .h` != $file || test `basename "$file" .hpp` != $file ; then
			echo $line/$file >> $tmpfile_h
		fi
		if test `basename "$file" .cpp` != $file || test `basename "$file" .c` != $file ; then
			echo $line/$file >> $tmpfile_cpp_c
		fi
	done
done < $tmpfile
#生成.pri文件
echo "INCLUDEPATH  += \$\$PWD" > $PRI_FILE_NAME
echo " "                      >> $PRI_FILE_NAME

echo "HEADERS += \\ "         >> $PRI_FILE_NAME
while read line; do
	#去掉"./"
	line=`echo "$line" |sed -r 's/^\.\///'`
	echo "    \$\$PWD/${line} \\ " >> $PRI_FILE_NAME
done < $tmpfile_h
echo " "                           >> $PRI_FILE_NAME

echo "SOURCES += \\ "              >> $PRI_FILE_NAME
while read line; do
	#去掉"./"
	line=`echo "$line" |sed -r 's/^\.\///'`
	echo "    \$\$PWD/${line} \\ " >> $PRI_FILE_NAME
done < $tmpfile_cpp_c
echo " "                               >> $PRI_FILE_NAME
#job done
test -f "$tmpfile" && rm -f $tmpfile
test -f "$tmpfile_h" && rm -f $tmpfile_h
test -f "$tmpfile_cpp_c" && rm -f $tmpfile_cpp_c
echo "输出文件 [$PATH_SOURCE_FULL/$PRI_FILE_NAME]..."

