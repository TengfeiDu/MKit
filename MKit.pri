################################################################################################

DEFINES += M_ENABLE_MKIT

#library buiding, ONLY one can be define
#DEFINES += M_CLASS_COMPILE_LIBRARY
#DEFINES += M_CLASS_USE_LIBRARY

#QtSoap
#include($$PWD/3rdPartyAPI/Src/qtsoap/src/qtsoap.pri)

#CRC
#include($$PWD/3rdPartyAPI/Src/libcrc-2.0/src/libcrc-2.0.pri)

#2d-code generate
#include($$PWD/3rdPartyAPI/Src/qrencode343/qrencode343.pri)

#2d-code analysis
#include($$PWD/3rdPartyAPI/Src/qzxing/QZXing.pri)

#.xlsx QT_VERSION <= 5.4.2
#include($$PWD/3rdPartyAPI/Src/QtXlsxWriter-master/src/xlsx/qtxlsx.pri)

#.xlsx libxlsxwriter 0.9.4 win32
include($$PWD/3rdPartyAPI/Src/libxlsxwriter/libxlsxwriter.pri)

#modbus
#include($$PWD/3rdPartyAPI/Src/modbus/modbus.pri)

#QCustomPlot 2.0.1
#include($$PWD/3rdPartyAPI/Src/qcustomplot/QCustomPlot.pri)

#tinyxml 2.6.2
include($$PWD/3rdPartyAPI/Src/tinyxml_2_6_2/tinyxml_2_6_2.pri)

#mongo-c-driver 1.14.0 win32
include($$PWD/3rdPartyAPI/Src/mongo-c-driver/mongo-c-driver.pri)

#opencv3.1.0 win32
#include($$PWD/3rdPartyAPI/Src/opencv310/opencv310.pri)

#QtWebApp 1.7.4
include($$PWD/3rdPartyAPI/Src/QtWebApp/QtWebApp/httpserver/httpserver.pri)
#include($$PWD/3rdPartyAPI/Src/QtWebApp/QtWebApp/logging/logging.pri)
#include($$PWD/3rdPartyAPI/Src/QtWebApp/QtWebApp/qtservice/qtservice.pri)
#include($$PWD/3rdPartyAPI/Src/QtWebApp/QtWebApp/templateengine/templateengine.pri)

#curl 7.67.0 win32
include($$PWD/3rdPartyAPI/Src/curl-7.67.0-win32-mingw/curl-7.67.0-win32-mingw.pri)

#MemoryPool
#include($$PWD/3rdPartyAPI/Src/MemoryPool-Master/MemoryPool-master.pri)

#QMqttClient need c++11
include ($$PWD/3rdPartyAPI/Src/qtmqtt-dev/src/mqtt/mqtt.pri)

#qamqp AMQP 0.9.1
include($$PWD/3rdPartyAPI/Src/qamqp-master/qamqp-master.pri)

#rabbitmq AMQP 0.11.0 win32
include($$PWD/3rdPartyAPI/Src/rabbitmq-c/rabbitmq-c.pri)

#zmq zmqpp-4.2.0 AND zeromq-4.3.2 win32
include($$PWD/3rdPartyAPI/Src/zmq/zmq.pri)

#ffmpeg-3.2.4
#DEFINES += M_ENABLE_FFMPEG

#opencv-3.1.0
#DEFINES += M_ENABLE_OPENCV

################################################################################################
QT += multimedia multimediawidgets network core sql uitools xml

!greaterThan(QT_VERSION,5.4.2){
    win32 {
        LIBS += -liconv
    }
}

INCLUDEPATH  += $$PWD

HEADERS += \   
    $$PWD/MKit.h

SOURCES += \   
    $$PWD/MKit.cpp

################################################################################################
RESOURCES += $$PWD/MKit.qrc

DISTFILES += $$PWD/DOC/*  \
             $$PWD/*.txt  \
             $$PWD/BASH/* \
             $$PWD/PYTHON/* \
             $$PWD/BAT/*

