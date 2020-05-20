DEFINES += M_ENABLE_CURL_7670

INCLUDEPATH  += $$PWD             \
             $$PWD/include        \
             $$PWD/include/curl
win32 {
    LIBS += $$PWD/bin/libcurl.dll       \
            $$PWD/bin/libcrypto-1_1.dll \
            $$PWD/bin/libssl-1_1.dll
}

HEADERS +=                              \
    $$PWD/include/curl/curl.h           \
    $$PWD/include/curl/curlver.h        \
    $$PWD/include/curl/easy.h           \
    $$PWD/include/curl/mprintf.h        \
    $$PWD/include/curl/multi.h          \
    $$PWD/include/curl/stdcheaders.h    \
    $$PWD/include/curl/system.h         \
    $$PWD/include/curl/typecheck-gcc.h  \
    $$PWD/include/curl/urlapi.h


DISTFILES += $$PWD/EXAMPLE.cpp


