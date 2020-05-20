DEFINES += M_ENABLE_LIBCRC

INCLUDEPATH  += $$PWD

HEADERS +=$$PWD/checksum.h

SOURCES += $$PWD/crc8.c \
    $$PWD/crc16.c \
    $$PWD/crc32.c \
    $$PWD/crcccitt.c \
    $$PWD/crcdnp.c \
    $$PWD/crckrmit.c \
    $$PWD/crcsick.c \
    $$PWD/nmea-chk.c
