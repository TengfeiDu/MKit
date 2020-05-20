#!/bin/sh
#@author:DuTengfei
#@date:2017-06-16
########################################
#生成.run格式安装包
#采用zip压缩源文件
#生成的安装包文件名可配置
#输出文件到当前路径
#先修改安装脚本，然后运行本脚本即可生成安装包
########################################
cd "`dirname "$0"`"
cp="`pwd`"
##############################################################################################
#                                               常量区                                       #
##############################################################################################
#在这里更改要生成的安装包文件名!!!
#在这里更改要生成的安装包文件名!!!
#在这里更改要生成的安装包文件名!!!
outFileName="serialTool_`date "+%F"`.run"
#在这里更改要 安装的 文件夹名称!!!
#在这里更改要 安装的 文件夹名称!!!
#在这里更改要 安装的 文件夹名称!!!
INSTALL_FOLDER_NAME="serialTool"
#在这里更改 安装时 要执行的脚本文件名!!!
#在这里更改 安装时 要执行的脚本文件名!!!
#在这里更改 安装时 要执行的脚本文件名!!!
APP_INSTALL_SCRIPT="install.sh"
##############################################################################################
#                                               常量区                                       #
##############################################################################################
#后面的不需更改
#后面的不需更改
#后面的不需更改
inDir="IN"
outDir="OUT"
installScript="INSTALL_SCRIPT"
########################################
if [ ! -d ./"$inDir" ];then
        echo "文件:[$cp/$inDir]不存在..."
	exit
fi
if [ ! -d ./"$outDir" ];then
        mkdir -p ./"$outDir" >/dev/null 2>&1
	if [ $? != 0 ];then
                echo "输出目录:[$cp/$outDir]创建失败..."
		exit
	fi
fi
########################################
#创建安装脚本
cat ./"`basename "$0"`" | sed -n -r '/^INSTALL_SCRIPT_START/,/^INSTALL_SCRIPT_END/p' > ./"$installScript"
sed -r '/^INSTALL_SCRIPT_START/d' -i ./"$installScript"
sed -r '/^INSTALL_SCRIPT_END/d' -i ./"$installScript"
sed -r '/./,$!d' -i ./"$installScript"
sed -e :a -e '/^\n*$/{$d;N;ba' -e'}' -i ./"$installScript"
########################################
#智能匹配文件后缀
outFileName="`echo "${outFileName}"|sed -r "s/^ *//g"|sed -r "s/ *$//g"|sed -r "s/(\.[Rr][Uu][Nn])*$//g"`"
outFileName="${outFileName}.run"
########################################
#自动修改安装脚本配置
installScriptLines=`cat ./"${installScript}"|wc -l`
installScriptLines=`expr $installScriptLines + 1`
sed -r "0,/^INSTALL_FOLDER_NAME=.*$/s//INSTALL_FOLDER_NAME=\"${INSTALL_FOLDER_NAME}\"/" -i ./${installScript}
sed -r "0,/^APP_INSTALL_SCRIPT=.*$/s//APP_INSTALL_SCRIPT=\"${APP_INSTALL_SCRIPT}\"/" -i ./${installScript}
sed -r "s/^LINES=.*$/LINES=${installScriptLines}/g" -i ./${installScript}
########################################
#压缩文件
outFileNameBase="`basename "$outFileName" .run`.zip"
cd ./$inDir
rm -rf ./*~
zip ./${outFileNameBase} ./* -ry 
mv ./${outFileNameBase} ..
cd ..
########################################
#生成安装包、删除zip
cat ./$installScript ./$outFileNameBase >./$outDir/$outFileName
rm -rf ./${outFileNameBase}
rm -rf ./"${installScript}"
rm -rf ./*~
echo "\033[31mjob done!\033[0m"
echo "\033[31mjob done!\033[0m"
echo "\033[31mjob done!\033[0m"
echo "\033[31m输出文件：［`pwd`/$outDir/${outFileName}］\033[0m"
exit 0
########################################

####################################################################################################################################################################
INSTALL_SCRIPT_START
#!/bin/sh
#@author:DuTengfei
#@date:2017-06-16
###############################################
#先修改要安装的:文件夹名称、文件夹所在路径、以及安装包运行时需要执行的脚本文件名
#支持安装时可修改默认安装路径
#支持安装时可运行脚本
###############################################
cd "`dirname "$0"`"
cp="`pwd`"
##############################################################################################
#                                               常量区                                       #
##############################################################################################
#在这里更改要 安装的 文件夹名称!!!
#在这里更改要 安装的 文件夹名称!!!
#在这里更改要 安装的 文件夹名称!!!
INSTALL_FOLDER_NAME="serialTool"
#在这里更改要 安装的 路径!!!
#在这里更改要 安装的 路径!!!
#在这里更改要 安装的 路径!!!
INSTALL_PATH_FULL="$HOME"
#在这里更改 安装时 要执行的脚本文件名!!!
#在这里更改 安装时 要执行的脚本文件名!!!
#在这里更改 安装时 要执行的脚本文件名!!!
APP_INSTALL_SCRIPT="install.sh"
##############################################################################################
#                                               常量区                                       #
##############################################################################################
#后面的不需更改
#后面的不需更改
#后面的不需更改
###############################################
#允许 安装时 更改 默认安装路径
#不需要 对话框时，请将该变量置 0
needDialog=1
if [ $needDialog -eq 1 ];then
	installPathTmp="`zenity --file-selection --directory --filename="$INSTALL_PATH_FULL" --title="选择安装路径:"`"
	#installPathTmp="`zenity --entry --text="安装路径:" --entry-text="$INSTALL_PATH_FULL" --title=""  --width="500"`"
	ret="$?"
	if [ $ret -eq 0 ];then
		installPathTmp="`echo "$installPathTmp"|sed -r "s/(\/)*$//g"`"
		if [ ! -d "$installPathTmp" ];then
			mkdir -p "$installPathTmp"
			if [ $? != 0 ];then
				echo "创建路径：［$installPathTmp］失败！"
				exit
			fi
		fi
		INSTALL_PATH_FULL="$installPathTmp"
	fi
	if [ $ret -eq 1 ];then
		echo "取消安装！"
		exit
	fi
fi
###############################################
#智能去除安装文件夹名称中的首尾空格
INSTALL_FOLDER_NAME="`echo "$INSTALL_FOLDER_NAME"|sed -r "s/^ *//g"|sed -r "s/ *$//g"`"
###############################################
#应用程序所在路径 该行可不用修改
appFilePath=$INSTALL_PATH_FULL/$INSTALL_FOLDER_NAME
###############################################
#当前脚本 的行数
#已在打包脚本:[./make_install_pkg.sh]中实现自动修改
#修改本脚本后 不需要手动修改
LINES=98
###############################################
#提取、解压、拷贝文件
zipTmpFile="${INSTALL_FOLDER_NAME}.zip"
more +$LINES ./"`basename $0`">/tmp/"$zipTmpFile"
cd /tmp/
unzip ./"$zipTmpFile" -d ./"$INSTALL_FOLDER_NAME"
cp -rf ./"$INSTALL_FOLDER_NAME" "$INSTALL_PATH_FULL"
###############################################
#删除临时文件
rm -rf ./"$INSTALL_FOLDER_NAME"
rm -rf ./"$zipTmpFile"
cd "$cp"
###############################################
#执行 安装时 需要运行的脚本
APP_INSTALL_SCRIPT="${appFilePath}/${APP_INSTALL_SCRIPT}"
if [ -f "${APP_INSTALL_SCRIPT}" ];then
	cd "${appFilePath}"
        bash ./"`basename "${APP_INSTALL_SCRIPT}"`"
	cd "$cp"
fi
###############################################
#安装成功
echo "\033[31m安装位置:［${INSTALL_PATH_FULL}/${INSTALL_FOLDER_NAME}］\033[0m"
echo "\033[31m安装位置:［${INSTALL_PATH_FULL}/${INSTALL_FOLDER_NAME}］\033[0m"
echo "\033[31m安装位置:［${INSTALL_PATH_FULL}/${INSTALL_FOLDER_NAME}］\033[0m"
exit 0
###############################################
#本文件结尾 不能 出现任何空行
#本文件结尾 不能 出现任何空行
#本文件结尾 不能 出现任何空行
###############################################
INSTALL_SCRIPT_END
####################################################################################################################################################################
