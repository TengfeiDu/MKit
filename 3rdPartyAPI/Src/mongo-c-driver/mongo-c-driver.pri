DEFINES += M_ENABLE_MONGOC1140

INCLUDEPATH  += $$PWD                    \
             $$PWD/include/libbson-1.0   \
             $$PWD/include/libmongoc-1.0
 
win32 {
    LIBS += $$PWD/bin/libbson-1.0.dll \
        $$PWD/bin/libmongoc-1.0.dll   \
        $$PWD/bin/msvcp120.dll        \
        $$PWD/bin/msvcr120.dll
}


HEADERS += \ 
    $$PWD/include/libbson-1.0/bson/bcon.h \ 
    $$PWD/include/libbson-1.0/bson/bson-atomic.h \ 
    $$PWD/include/libbson-1.0/bson/bson-clock.h \ 
    $$PWD/include/libbson-1.0/bson/bson-compat.h \ 
    $$PWD/include/libbson-1.0/bson/bson-config.h \ 
    $$PWD/include/libbson-1.0/bson/bson-context.h \ 
    $$PWD/include/libbson-1.0/bson/bson-decimal128.h \ 
    $$PWD/include/libbson-1.0/bson/bson-endian.h \ 
    $$PWD/include/libbson-1.0/bson/bson-error.h \ 
    $$PWD/include/libbson-1.0/bson/bson.h \ 
    $$PWD/include/libbson-1.0/bson/bson-iter.h \ 
    $$PWD/include/libbson-1.0/bson/bson-json.h \ 
    $$PWD/include/libbson-1.0/bson/bson-keys.h \ 
    $$PWD/include/libbson-1.0/bson/bson-macros.h \ 
    $$PWD/include/libbson-1.0/bson/bson-md5.h \ 
    $$PWD/include/libbson-1.0/bson/bson-memory.h \ 
    $$PWD/include/libbson-1.0/bson/bson-oid.h \ 
    $$PWD/include/libbson-1.0/bson/bson-prelude.h \ 
    $$PWD/include/libbson-1.0/bson/bson-reader.h \ 
    $$PWD/include/libbson-1.0/bson/bson-string.h \ 
    $$PWD/include/libbson-1.0/bson/bson-types.h \ 
    $$PWD/include/libbson-1.0/bson/bson-utf8.h \ 
    $$PWD/include/libbson-1.0/bson/bson-value.h \ 
    $$PWD/include/libbson-1.0/bson/bson-version-functions.h \ 
    $$PWD/include/libbson-1.0/bson/bson-version.h \ 
    $$PWD/include/libbson-1.0/bson/bson-writer.h \ 
    $$PWD/include/libbson-1.0/bson.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-apm.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-bulk-operation.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-change-stream.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-client.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-client-pool.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-client-session.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-collection.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-config.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-cursor.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-database.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-error.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-find-and-modify.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-flags.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-gridfs-bucket.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-gridfs-file.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-gridfs-file-list.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-gridfs-file-page.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-gridfs.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-handshake.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-host-list.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-index.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-init.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-iovec.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-log.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-macros.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-matcher.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-opcode.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-prelude.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-rand.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-read-concern.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-read-prefs.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-server-description.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-socket.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-ssl.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-buffered.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-file.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-gridfs.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-socket.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-tls.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-tls-libressl.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-stream-tls-openssl.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-topology-description.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-uri.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-version-functions.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-version.h \ 
    $$PWD/include/libmongoc-1.0/mongoc/mongoc-write-concern.h \ 
    $$PWD/include/libmongoc-1.0/mongoc.h
 
SOURCES +=
 
