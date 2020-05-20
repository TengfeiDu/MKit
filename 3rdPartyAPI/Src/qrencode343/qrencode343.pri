DEFINES += M_ENABLE_QRENCODE

INCLUDEPATH  += $$PWD

DEFINES += HAVE_CONFIG_H_QREN

HEADERS += $$PWD/bitstream.h \
        $$PWD/mask.h \
        $$PWD/mmask.h \
        $$PWD/mqrspec.h \
        $$PWD/qrencode.h \
        $$PWD/qrencode_inner.h \
        $$PWD/qrinput.h \
        $$PWD/qrspec.h \
        $$PWD/rscode.h \
        $$PWD/split.h \
        $$PWD/config_qrencode.h

SOURCES += $$PWD/bitstream.c \
        $$PWD/mask.c \
        $$PWD/mmask.c \
        $$PWD/mqrspec.c \
        $$PWD/qrenc.c \
        $$PWD/qrencode.c \
        $$PWD/qrinput.c \
        $$PWD/qrspec.c \
        $$PWD/rscode.c \
        $$PWD/split.c
