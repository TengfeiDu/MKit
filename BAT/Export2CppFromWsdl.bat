
::��ǰ�ļ�ȫ·��
echo "%~f0"
::��ǰ�ļ�·��
echo "%~dp0"

::::::::::::::::::::::Change Here::::::::::::::::::::::::::::::::::::::::

set URL=http://www.webxml.com.cn/webservices/qqOnlineWebService.asmx?wsdl
set PATH_GSOAP=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\gsoap-2.8

::::::::::::::::::::::NO need to change the code below:::::::::::::::::::
set OUTDIR=%~dp0%OUT
cd /d %PATH_GSOAP%\gsoap\bin\win32
wsdl2h.exe -o ./1.h -nws -s %URL%
soapcpp2.exe -i -C -x ./1.h -I../../import

::����
del /S /Q %OUTDIR%
if not exist %OUTDIR% md %OUTDIR%
xcopy  /C /H /Y *.h     %OUTDIR%
xcopy  /C /H /Y *.cpp   %OUTDIR%
xcopy  /C /H /Y *.nsmap %OUTDIR%
xcopy  /C /H /Y ..\..\stdsoap2.h   %OUTDIR%
xcopy  /C /H /Y ..\..\stdsoap2.cpp %OUTDIR%
del *.h *.cpp *.nsmap
::�������·��,��������ļ�
cd /d %OUTDIR%
del 1.h
::��ȡ.pri�ļ�����
set PRIFILE=
set PRIFILENAME=
for /R %%i in (*.nsmap) do (
	set PRIFILE=%%~ni.pri
	set PRIFILENAME=%%~ni
)
::����pri
type nul > %PRIFILE%
::�������
echo LIBS +=  -lwsock32   >> %PRIFILE%
echo\                     >> %PRIFILE%
echo INCLUDEPATH += $$PWD >> %PRIFILE%
echo\                     >> %PRIFILE%
echo HEADERS += \         >> %PRIFILE%
for /R %%i in (*.h) do (
	echo $$PWD/%%~ni.h \    >> %PRIFILE%
)
echo\                     >> %PRIFILE%
echo SOURCES += \         >> %PRIFILE%
for /R %%i in (*.cpp) do (
	echo $$PWD/%%~ni.cpp \  >> %PRIFILE%
)
echo $$PWD/%PRIFILENAME%.nsmap.cpp >> %PRIFILE%
rename %PRIFILENAME%.nsmap %PRIFILENAME%.nsmap.cpp
pause
