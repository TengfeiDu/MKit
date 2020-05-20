
DEFINES += M_ENABLE_LIBXLSXWRITER_0_9_4

INCLUDEPATH  += $$PWD
 
HEADERS += \ 
    $$PWD/xlsxwriter/third_party/ioapi.h \ 
    $$PWD/xlsxwriter/third_party/md5.h \ 
    $$PWD/xlsxwriter/third_party/queue.h \ 
    $$PWD/xlsxwriter/third_party/tmpfileplus.h \ 
    $$PWD/xlsxwriter/third_party/tree.h \ 
    $$PWD/xlsxwriter/third_party/zip.h \ 
    $$PWD/xlsxwriter/app.h \ 
    $$PWD/xlsxwriter/chart.h \ 
    $$PWD/xlsxwriter/chartsheet.h \ 
    $$PWD/xlsxwriter/comment.h \ 
    $$PWD/xlsxwriter/common.h \ 
    $$PWD/xlsxwriter/content_types.h \ 
    $$PWD/xlsxwriter/core.h \ 
    $$PWD/xlsxwriter/custom.h \ 
    $$PWD/xlsxwriter/drawing.h \ 
    $$PWD/xlsxwriter/format.h \ 
    $$PWD/xlsxwriter/hash_table.h \ 
    $$PWD/xlsxwriter/packager.h \ 
    $$PWD/xlsxwriter/relationships.h \ 
    $$PWD/xlsxwriter/shared_strings.h \ 
    $$PWD/xlsxwriter/styles.h \ 
    $$PWD/xlsxwriter/theme.h \ 
    $$PWD/xlsxwriter/utility.h \ 
    $$PWD/xlsxwriter/vml.h \ 
    $$PWD/xlsxwriter/workbook.h \ 
    $$PWD/xlsxwriter/worksheet.h \ 
    $$PWD/xlsxwriter/xmlwriter.h \ 
    $$PWD/xlsxwriter.h \ 
    $$PWD/zconf.h \ 
    $$PWD/zlib.h \ 
 
SOURCES += \ 
 
LIBS += $$PWD/lib/libxlsxwriter.dll \
        $$PWD/lib/libzlib.dll
