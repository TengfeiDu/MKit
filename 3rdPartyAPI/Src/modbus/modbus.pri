DEFINES += M_ENABLE_MODBUS

INCLUDEPATH  += $$PWD

HEADERS +=  $$PWD/modbus-private.h\
            $$PWD/modbus-rtu-private.h\
            $$PWD/modbus-tcp-private.h\
            $$PWD/modbus-version.h\
            $$PWD/modbus-rtu.h\
            $$PWD/modbus-tcp.h\
            $$PWD/modbus.h \
            $$PWD/config_modbus.h

SOURCES +=  $$PWD/modbus-data.c\
            $$PWD/modbus-rtu.c\
            $$PWD/modbus-tcp.c\
            $$PWD/modbus.c

win32 {
    LIBS += -L./ -lws2_32
}


####################################################################################
#
# if you get "GL/gl.h:No such file or directory",
# just:
# sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
#
####################################################################################
