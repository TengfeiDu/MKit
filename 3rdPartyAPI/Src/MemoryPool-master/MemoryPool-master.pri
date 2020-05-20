DEFINES += M_ENABLE_MEMORYPOOL_MASTER

INCLUDEPATH  += $$PWD \
                $$PWD/C-98

HEADERS += \
        $$PWD/C-98/MemoryPool.h \
        $$PWD/StackAlloc.h

SOURCES += $$PWD/test.cpp

