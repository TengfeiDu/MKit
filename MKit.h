/****************************************************************************
**
** Copyright (C) Chengdu Best Postal Equipemnt Manufacturing Co.Ltd.
** Contact: http://www.bestpost888.com
**
** @author   DuTengfei
** @email    tf.du@foxmail.com
** @version  1.0.0.1
** @date     2015.01.01
** @license
**
**---------------------------------------------------------------------------
** Remark         : Description
**---------------------------------------------------------------------------
** Change History :
** <Date>     | <Version> | <Author>       | <Description>
**---------------------------------------------------------------------------
** 2015.01.01 | 1.0.0.1   | DuTengfei      | Create file
**---------------------------------------------------------------------------
**
****************************************************************************/

#ifndef MKIT_H
#define MKIT_H
#include <QString>
#include <QThread>
#include <QDateTime>
#include <QMutex>
#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QStringList>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QPixmap>
#include <QApplication>
#include <QMetaObject>
#include <QMetaEnum>
#include <QMediaPlayer>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QReadWriteLock>
#include <QJsonArray>
#include <QDir>
#include <QSqlDatabase>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QLabel>
#include <QVideoWidget>
#include <QMovie>
#include <QTimer>
#include <QLocalServer>
#include <QLocalSocket>
#include <QPropertyAnimation>
#include <QToolButton>
#include <QKeyEvent>
#include <QPushButton>
#include <QDialog>
#include <QSocketNotifier>
#include <QTextBrowser>
#include <QJsonDocument>
#include <QThreadStorage>
#include <QXmlStreamAttributes>
#include <QHash>
#include <QDomDocument>
#include <QSettings>
#include <QSemaphore>
#include <QTcpServer>

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <typeinfo>

/**
 *  Character Encoding:
 *
 *  QString ddd = QString("中国a");
 *  QByteArray bytearray = QByteArray().append(ddd);
 *  MDG << MTL::get_hex_str_format_from_QByteArray(bytearray) + "\n"
 *      << MTL::get_hex_str_format_from_QByteArray(ddd.toStdString().c_str()) + "\n"
 *      << MTL::get_hex_str_format_from_QByteArray(ddd.toUtf8()) + "\n"
 *      << MTL::get_hex_str_format_from_QByteArray(ddd.toLatin1()) + "\n"
 *      << MTL::get_hex_str_format_from_QByteArray(ddd.toLocal8Bit());
 *
 *  OUT:
 *     0xE4,0xB8,0xAD,0xE5,0x9B,0xBD,0x61  RIGHT
 *     0xE4,0xB8,0xAD,0xE5,0x9B,0xBD,0x61  RIGHT
 *     0xE4,0xB8,0xAD,0xE5,0x9B,0xBD,0x61  RIGHT
 *     0x3F,0x3F,0x61                      ERROR
 *     0xD6,0xD0,0xB9,0xFA,0x61            ERROR
 *
 * */

/********************************************Global Define Start***************************/

#define M_ENABLE_ICONV 1

/********************************************Global Define End*****************************/

#if (QT_VERSION <= QT_VERSION_CHECK(5, 4, 2)) && M_ENABLE_ICONV
#   include <iconv.h>
#endif

/******************************************** MKit:MGlobal ***/

typedef unsigned long long int ullint; //8
typedef long long int          llint;  //8
typedef long double            ld;     //12

//////////////////////////////////////////////////////////////
//compile time-stamp like 20171231235959,NOT unique
#define M_TIME_COMPILE QString("%1%2%3%4")\
    .arg( QString(__DATE__).remove(QRegExp("^.+ ")) )\
    .arg(QString().sprintf("%02d",\
    QString("JanFebMarAprMayJunJulAugSepOctNovDec")\
    .toUpper()\
    .indexOf(QString(__DATE__).remove(QRegExp(" .+$")).toUpper())/3+1\
    ))\
    .arg(QString().sprintf("%02d",\
    QString(__DATE__).remove(QRegExp("^[a-zA-Z]+ ")).remove(QRegExp(" [0-9]+$")).toInt()))\
    .arg(QString().sprintf("%02d%02d%02d",\
    QString(__TIME__).remove(QRegExp(":.+$")).toInt(),\
    QString(__TIME__).remove(QRegExp("^[0-9]+:")).remove(QRegExp(":[0-9]+$")).toInt(),\
    QString(__TIME__).remove(QRegExp("^.+:")).toInt()))

//compile timestamp 20171231
#define M_TIME_COMPILE_DAY QString(M_TIME_COMPILE).mid(0,QString("20171231").length())

/***************************
 *
 * Version Control
 *
 * *************************/
#define M_VERSION(flag) QString("%1.%2").arg(M_TIME_COMPILE_DAY).arg(#flag)


//////////////////////////////////////////////////////////////

#define MDBG              0
#define M_TIME_FORMAT_WITH_MILLISECONDS "yyyy-MM-dd HH:mm:ss.zzz"
#define M_TIME_FORMAT_SECONDS           "yyyy-MM-dd HH:mm:ss"

#define M_TIME_NOW_MILLISECONDS         QDateTime::currentDateTime().toString(M_TIME_FORMAT_WITH_MILLISECONDS)
#define M_TIME_NOW_SECONDS              QDateTime::currentDateTime().toString(M_TIME_FORMAT_SECONDS)
//////////////////////////////////////////////////////////////
//QString
#define M_QSTRING_INFO_LONG(str) QString("[%1][%2][%3][%4][%5][%6][%7][%8]")\
    .arg(M_TIME_NOW_MILLISECONDS)\
    .arg(M_TIME_COMPILE)\
    .arg(__LINE__)\
    .arg(__FILE__)\
    .arg(Q_FUNC_INFO)\
    .arg(QString().sprintf("0x%016llX",(ullint)QThread::currentThread()))\
    .arg(QThread::currentThread()->objectName())\
    .arg(QString(str))

//QString
#define M_QSTRING_INFO(str) QString("[%1][%2][%3][%4]")\
    .arg(__LINE__)\
    .arg(__FILE__)\
    .arg(Q_FUNC_INFO)\
    .arg(QString(str))

#define M_THROW_QSTRING(str)    do{ throw M_QSTRING_INFO_LONG(str);}while(0)
//////////////////////////////////////////////////////////////

#if (QT_VERSION == QT_VERSION_CHECK(5,4,2))
    #define __qDebug qDebug()
#else
    #define __qDebug qDebug().noquote()
#endif

#define MDG            __qDebug\
    << __LINE__\
    << __FILE__\
    << Q_FUNC_INFO\
    << M_TIME_NOW_MILLISECONDS

#define MDG_WARNING    __qDebug\
    << "---WARNING--->" \
    << __LINE__\
    << __FILE__\
    << Q_FUNC_INFO\
    << M_TIME_NOW_MILLISECONDS

/*
 * EXAMPLE:
 *
 *  MDG_QSTRING(s) << "time"
 *                 << "2020.02.01"
 *                 << QJsonObject();
 *
 * Now the variable s is:
 *
 *  "time 2020.02.01 QJsonObject() "
 *
 * This macro can make many objects human-readable using QDebug.operator <<().
 */
#if (QT_VERSION == QT_VERSION_CHECK(5, 4, 2))
    #define MDG_QSTRING(obj) QString obj;QDebug(&obj)
#else
    #define MDG_QSTRING(obj) QString obj;QDebug(&obj).noquote()
#endif
//////////////////////////////////////////////////////////////
//
#define M_CAST_STRING(s) #s
//
#define M_ASSERT(expr) do{typedef void (*crash)();\
    crash f = NULL;\
    if(!(expr)){\
    MDG << M_QSTRING_INFO_LONG(M_CAST_STRING(expr));\
    f();\
    }\
    }while(0)
//////////////////////////////////////////////////////////////

#define M_MAXIMUM(a,b)     ((a) > (b) ? (a) : (b))
#define M_MAXIMUM_3(a,b,c) M_MAXIMUM(M_MAXIMUM(a,b),c)

#define M_MINIMUM(a,b)     ((a) > (b) ? (b) : (a))
#define M_MINIMUM_3(a,b,c) M_MINIMUM(M_MINIMUM(a,b),c)

#define MVOID     ((void)0)

#define M_SIZE_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof((a)[0]))
//////////////////////////////////////////////////////////////
#ifdef Q_OS_LINUX
#define M_DIRECTORY_SYMBOL "/"
#define M_ENTER            "\n"
#else
#define M_DIRECTORY_SYMBOL "\\"
#define M_ENTER            "\r\n"
#endif //Q_OS_LINUX
//////////////////////////////////////////////////////////////
// Declare definitions for shared library compilation/usage:
#if defined(M_CLASS_COMPILE_LIBRARY)
#   define M_CLASS_LIB_DECL Q_DECL_EXPORT
#elif defined(M_CLASS_USE_LIBRARY)
#   define M_CLASS_LIB_DECL Q_DECL_IMPORT
#else
#   define M_CLASS_LIB_DECL
#endif //M_CLASS_COMPILE_LIBRARY
//////////////////////////////////////////////////////////////

#define M_DELETE_TO_NULL(p)       do{delete (p);p = NULL;}while(0)

#define M_DELETE_TO_NULL_ARRAY(p) do{delete[] (p);p = NULL;}while(0)

#define M_FREE_TO_NULL(p)         do{::free(p);p = NULL;}while(0)
//2017-01-01 00:00:00.000
#define M_REGEXP_TIME          "^[0-9]{4}(-[0-9]{2}){2} ([0-9]{2}:){2}[0-9]{2}.[0-9]{3}$"
#define M_REGEXP_NUMBER        "^[0-9]+$"
#define M_REGEXP_TEL_NUMBER    "^1[0-9]{10}$"
#define M_REGEXP_MAC           "^([0-9A-Fa-f]{2}-){5}[0-9A-Fa-f]{2}$"
#define M_REGEXP_IP            "^((([0-9])|([1-9][0-9])|(1[0-9]{2})|(2[0-4][0-9])|(25[0-5]))\\.){3}(([0-9])|([1-9][0-9])|(1[0-9]{2})|(2[0-4][0-9])|(25[0-5]))$"
#define M_REGEXP_PORT          "^([0-9])|([1-9][0-9]{1,3})|([1-5][0-9]{4})|(6[0-4][0-9]{3})|(65[0-4][0-9]{2})|(655[0-2][0-9])|(6553[0-5])$"
#define M_ERROR_UNKNOWN_STRING "ERROR_UNKNOWN"

#define M_EXTERN_C_BEGIN   extern "C" {
#define M_EXTERN_C_END     }

#define M_EXTERN_CPP_BEGIN extern "C++" {
#define M_EXTERN_CPP_END   M_EXTERN_C_END

#define M_NAMESPACE_BEGIN  namespace mkit {
#define M_NAMESPACE_END    }

#define M_DEPRECATED_API
#define M_UNUSED_API

#define M_PAI               3.14159265358979323846
#define M_ANGLE_2_RADIAN(x) ((x) * M_PAI / 180.0)
//////////////////////////////////////////////////////////////
#ifdef Q_OS_WIN32
#include <windows.h>
#include <winuser.h>

/**
 * EXMAPLE:
 *
 *   LRESULT HOOKPROCHOOKPROC(int code,WPARAM wParam,LPARAM lParam)
 *    {
 *       MDG << code
 *           << wParam
 *           << lParam;
 *       KBDLLHOOKSTRUCT *  keyNum = (KBDLLHOOKSTRUCT *)lParam;
 *       MDG << keyNum->vkCode;
 *       if(keyNum == VK_RETURN && wParam == WM_KEYUP){
 *           //...
 *       }
 *       //return S_FALSE to ignore the event in HOOKPROC function!
 *       return S_OK;
 *    }
 *
 *   HHOOK hk = M_GET_HHOOK_KEYBOARD((HOOKPROC)HOOKPROCHOOKPROC);
 *   //...
 *   M_DELETE_TO_NULL_HHOOK(hk);
 */
#define M_GET_HHOOK_KEYBOARD(HOOKPROC)     ::SetWindowsHookEx(WH_KEYBOARD_LL,HOOKPROC,GetModuleHandle(NULL),0)
#define M_GET_HHOOK_MOUSE(HOOKPROC)        ::SetWindowsHookEx(WH_MOUSE_LL,HOOKPROC,GetModuleHandle(NULL),0)
#define M_DELETE_TO_NULL_HHOOK(HHOOK)      do{if(HHOOK){::UnhookWindowsHookEx(HHOOK); HHOOK = NULL;}}while(0)

//need C++11
#if __cplusplus >= 201103L
#define M_GET_TEXT_BY_HWND(id) [](HWND handle) -> std::string {    \
    if(handle){                                                    \
    int length = ::SendMessageA(handle,WM_GETTEXTLENGTH,0,0);  \
    if(length > 0){                                            \
    char *p = new char[length + 1]();                \
    int length_text = ::SendMessageA(handle,WM_GETTEXT,length + 1,(long)p); \
    std::string ret(p,length_text);                                     \
    delete[] p;                                                         \
    return ret;                                                         \
    }                                                                       \
    }                                                                            \
    return std::string();                                                        \
    }(id)
#endif //__cplusplus

#define M_SET_TEXT_BY_HWND(id,text_p)           ::SendMessageA(id,WM_SETTEXT,0,(long)text_p)
#define M_BUTTON_CLICKED_BY_HWND(id)            ::SendMessage(id, BM_CLICK, 0, 0)
#define M_BUTTON_CLICKED_BY_HWND_NONE_BLOCK(id) ::PostMessage(id, BM_CLICK, 0, 0)

#define M_MOUSE_BUTTON_DOWN_LEFT(x,y)        do{::mouse_event(MOUSEEVENTF_LEFTDOWN,x, y, 0, 0);}while(0)
#define M_MOUSE_BUTTON_UP_LEFT(x,y)          do{::mouse_event(MOUSEEVENTF_LEFTUP,x, y, 0, 0);}while(0)
#define M_MOUSE_BUTTON_DOWN_AND_UP_LEFT(x,y) do{M_MOUSE_BUTTON_DOWN_LEFT(x,y);M_MOUSE_BUTTON_UP_LEFT(x,y);}while(0)

#define M_KEYBOARD_DOWN(c)            do{::keybd_event((c),0,0,0);}while(0)
#define M_KEYBOARD_UP(c)              do{::keybd_event((c),0,KEYEVENTF_KEYUP,0);}while(0)
#define M_KEYBOARD_DOWN_AND_UP(c)     do{M_KEYBOARD_DOWN((c));M_KEYBOARD_UP((c));}while(0)
#define M_KEYBOARD_DOWN_AND_UP_ENTER  do{M_KEYBOARD_DOWN_AND_UP(VK_RETURN);}while(0)
#define M_KEYBOARD_DOWN_AND_UP_DELETE do{M_KEYBOARD_DOWN_AND_UP(VK_DELETE);}while(0)

#define M_KEYBOARD_SELECT_ALL     do{M_KEYBOARD_DOWN(VK_CONTROL);M_KEYBOARD_DOWN('A');M_KEYBOARD_UP(VK_CONTROL);M_KEYBOARD_UP('A');}while(0)
#define M_KEYBOARD_COPY           do{M_KEYBOARD_DOWN(VK_CONTROL);M_KEYBOARD_DOWN('C');M_KEYBOARD_UP(VK_CONTROL);M_KEYBOARD_UP('C');}while(0)
#define M_KEYBOARD_PASTE          do{M_KEYBOARD_DOWN(VK_CONTROL);M_KEYBOARD_DOWN('V');M_KEYBOARD_UP(VK_CONTROL);M_KEYBOARD_UP('V');}while(0)
#endif //Q_OS_WIN32

#define M_CURRENT_THREAD_OBJECT             QThread::currentThread()
#define M_SENDER_QOBJECT                    QObject::sender()
#define M_SENDER_DYNAMIC_CAST(type)         ((type*)dynamic_cast<type*>(M_SENDER_QOBJECT))
#define M_CONNECTION_TYPE_QUEUED_AND_UNIQUE ((Qt::ConnectionType)(Qt::QueuedConnection|Qt::UniqueConnection))
#define M_APP_DIR_PATH_NO_ENDING_SLASH              QApplication::applicationDirPath()
#define M_SET_CURRENT_PATH_2_APPLICATION_DIR_PATH   QDir::setCurrent(M_APP_DIR_PATH_NO_ENDING_SLASH)

#define M_CLOSE_DATABASE(connectionName) {QSqlDatabase db = QSqlDatabase::database(connectionName);db.close();}



//////////////////////////////////////////////////////////////
/******************************************** MKit:MTL ***/
#ifdef Q_OS_LINUX
#include <time.h>
#include <sys/select.h>
#include <sys/statfs.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <sys/fcntl.h>
#include <linux/serial.h>
#endif //Q_OS_LINUX

#ifdef M_ENABLE_QRENCODE
#include "qrencode.h"
#endif // M_ENABLE_QRENCODE

#ifdef M_ENABLE_FFMPEG
#if 1
#ifdef __cplusplus
#define __STDC_CONSTANT_MACROS
#ifdef _STDINT_H
#undef _STDINT_H
#endif //_STDINT_H
# include <stdint.h>
#endif //__cplusplus
#ifndef   UINT64_C
#define   UINT64_C(value) __CONCAT(value,ULL)
#endif //UINT64_C
#define PRId64 "ld"
#endif //1

#ifdef __cplusplus
M_EXTERN_C_BEGIN
#endif //__cplusplus
#include <libavutil/avassert.h>
#include <libavutil/channel_layout.h>
#include <libavutil/opt.h>
#include <libavutil/mathematics.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include <libavutil/imgutils.h>
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libavutil/file.h>
#include <libavformat/avio.h>
#ifdef __cplusplus
M_EXTERN_C_END
#endif //__cplusplus
#endif // M_ENABLE_FFMPEG

#ifdef M_ENABLE_OPENCV
#include"opencv2/opencv.hpp"
using namespace cv;
#endif // M_ENABLE_OPENCV

/*****************************************************************************************/
/**
 * @brief The mTools class
 * useage:
 *      mTools::mgetobj()->muchar2bit(0xAA);
 *      qDebug()<<__LINE__<<__FILE__<<"";
 */
/*****************************************************************************************/
class M_CLASS_LIB_DECL MTL
{

public:
    /*****************************************************************************************/
    enum RandType{
        Number,
        Character,
        NumberAndCharacter
    };
    enum TimeType{
        Normal,           //2016-01-01 08:00:00.000
        Plain             //20160101080000000
    };
    enum WriteType{
        ClearAndWrite,
        FromBegin,
        Append
    };
    enum SortAlgorithm{Bubbing,Select,Shell,Insert};
    enum SortOrder{Asc,Desc};
    enum CodeType{UTF8_2_GBK,GBK_2_UTF8};

    MTL();
    MTL(const MTL &);
    MTL & operator =(const MTL &);
    virtual ~MTL();

#ifdef Q_OS_WIN32
    static void keyboard_clicked_str(const QString &data);
#endif //Q_OS_WIN32

    /*****************************************************************************************/
#ifdef Q_OS_LINUX
    /**
     * @brief mSleep
     * @param second
     * @param nanoSecond
     * total time = second + nanoSecond / 1000,000,000
     * UASAGE:
     *      //1.001s
     *      mTools::mgetobj()->mSleep(1,1000000);
     */
    static void mSleep(long int second = 0,long int nanoSecond = 0);
#endif //Q_OS_LINUX

    static void delete_all_items_by_recursion(QTreeWidget* tree);
#ifdef Q_OS_LINUX

    static M_DEPRECATED_API quint64 mGetFreeDisk(const QString &path);
#endif //Q_OS_LINUX
    /*****************************************************************************************/

    static void set_mask(QWidget* w,int yuanJiaoBanJin_x = 10,int yuanJiaoBanJin_y = 10);
    //
    static void set_ellipse_mask(QWidget *w);

    //for case like  : on_XXX_clicked()
    static void connect_signal_and_slot(QWidget* uiWidget,QObject* slotObj);

    static QWidget *load_ui_from_file(const QString& uiFileName,QWidget* parent = 0);

    //for array
    template <class T>
    static void sort(register T *addr,
                     register int length,
                     register SortOrder order = Asc,
                     SortAlgorithm type = Bubbing)
    {
        if(addr && length > 0){
            switch(type){
            case MTL::Bubbing:
                for(register int i = 0; i < length; i++){
                    for(register int j = 0; j < length - 1 - i; j++){   //1 2 3 4 5 6 7 8 9 10 11 12 13
                        if(order == MTL::Asc ? addr[j] > addr[j + 1] : addr[j] < addr[j + 1]){
                            T tmp;
                            tmp = addr[j];
                            addr[j] = addr[j + 1];
                            addr[j + 1] = tmp;
                        }
                    }
                }
                break;
            case MTL::Select:
                for(register int i = 0; i < length; i++) {
                    for(register int j = i + 1; j < length; j++){   //1 2 3 4 5 6 7 8 9 10 11 12 13
                        if(order == MTL::Asc ? addr[i] > addr[j] : addr[i] < addr[j]){
                            T tmp;
                            tmp = addr[i];
                            addr[i] = addr[j];
                            addr[j] = tmp;
                        }
                    }
                }
                break;
            case MTL::Shell:
                for(register int div = length / 2; div >= 1; div = div / 2){
                    for(register int i = div; i < length; ++i){
                        register int k = i;
                        T tmp = addr[k];
                        while(k >= div && (order == MTL::Asc ? addr[k - div] > tmp : addr[k - div] < tmp) ){
                            addr[k] = addr[k - div];
                            k -= div;
                        }
                        addr[k] = tmp;
                    }
                }
                break;
            case MTL::Insert:
                for(register int i = 0; i < length; i++){
                    register int j = i;
                    T tmp = addr[j];
                    while(j >= 1 && (order == MTL::Asc ? addr[j - 1] > tmp : addr[j - 1] < tmp)){
                        addr[j] = addr[j - 1];
                        j--;
                    }
                    addr[j] = tmp;
                }
                break;
            default:
                break;
            }
        }
    }
    /*****************************************************************************************/

    //thread-safe,IniFormat
    static QVariant get_config(const QString &f,
                               const QString &key);
    //thread-safe,IniFormat
    static QMap<QString, QVariant> get_config(const QString & file);
    //thread-safe,IniFormat
    static void set_config(const QString& f,
                           const QString& key,
                           const QVariant& value);
    //thread-safe,IniFormat
    static void set_config(const QString & file,const QMap<QString, QVariant> & map);

    /*****************************************************************************************/

    /*
     * 500MB file is good to read.
     *
     * Tested platform:
     *  Qt5.4.2 mingw-32 compiler,win7 64bit 8GB RAM.
     *
     * return "", if not exist.
     * */
    static QByteArray get_data_from_file(const QString & file);

    static bool set_data_2_file(const QString &file,const QByteArray &data,WriteType t = MTL::ClearAndWrite);

    static void set_center(QWidget* widget);

    //primary screen
    static QPixmap get_picture_of_desktop();
    /*****************************************************************************************/

    static QString get_time_now(TimeType type = MTL::Normal,
                                bool hasMillisecond = true);
#ifdef Q_OS_LINUX

    //return "xxx.xxx" for second
    static QString mGetHighPrecisionTime();

#endif //Q_OS_LINUX

    static QString get_rand_str(RandType type,int length);
    /*****************************************************************************************/

    //0x88->"10001000"
    static QString get_bit_str_from_uchar_length_8(uchar number,
                                                   bool reverseOrder = false);
    static QString get_bit_str_from_uint_length_32(uint number);

    static QString get_hex_str_from_uchar_upper(uchar number);
    static QString get_hex_str_from_uint_length_8_upper(uint number);
    static QString get_hex_str_from_ulonglong_length_16_upper(ullint number);


    //"12345678"->305419896
    static uint get_uint_from_hex_str(const QString & hexStr);
    /*****************************************************************************************/


    static QString get_str_from_QJsonObject(const QJsonObject &json,
                                            QJsonDocument::JsonFormat format = QJsonDocument::Compact);
    static QString get_str_from_QJsonArray(const QJsonArray &array,
                                           QJsonDocument::JsonFormat format = QJsonDocument::Compact);

    static QJsonObject get_json_obj_from_QString(const QString &str);

    static QString get_str_json_array_from_QListQPair(const QList<QPair<QByteArray,QByteArray> > &l,
                                                      QJsonDocument::JsonFormat format = QJsonDocument::Compact);

    static QJsonObject get_mac();
    /*****************************************************************************************/

#ifdef M_ENABLE_QRENCODE
    static QImage get_2d_code(const QString & str,
                              int size = 300,
                              int version = 4,
                              QRecLevel level = QR_ECLEVEL_L,
                              QRencodeMode hint = QR_MODE_8,
                              int casesensitive = 1);
#endif //M_ENABLE_QRENCODE

    //delete the uchar in source array for each
    static void kill_character(uchar *source,
                               int sourceLength,
                               uchar uchar);


    static QString kill_last_character(const QString& str,const QString & kill);
    /*****************************************************************************************/

    static QString get_md5_from_data(const QByteArray &bData);

    static QString get_md5_from_file(const QString &file);

    static QString get_hex_str_from_uchar_array_upper(const char *array,
                                                      int length,
                                                      bool autoAddPrefix = false,
                                                      bool autoAddSpace = false);
    static QString get_hex_str_from_uchar_array_upper(const QByteArray &data,
                                                      bool autoAddPrefix = false,
                                                      bool autoAddSpace = false);

    static QString get_hex_str_format_from_QByteArray(const QByteArray &data,const QString &separator = ",",int indent = 100);
    static QJsonArray get_hex_str_json_formart_from_QByteArray(const QByteArray &data,const QString &sep = ",",int indent = 10);
    /**
     * The compressionLevel parameter specifies how much compression should be used.
     * Valid values are between 0 and 9,with 9 corresponding to the greatest compression (i.e. smaller compressed data)
     * at the cost of using a slower algorithm.
     * Smaller values (8, 7, ..., 1) provide successively less compression at slightly faster speeds.
     * The value 0 corresponds to no compression at all.
     * The default value is -1, which specifies zlib's default compression.
     * */
    static bool compress_data_from_file_2_file_by_qCompress(const QString &inFile,const QString &outFile,QByteArray &outData,int compressionLevel = -1);
    static bool uncompress_data_2_file_by_qUncompress(const QString &outFile,QByteArray &outData,const uchar *array,int length);

    static QString get_bit_str_from_uchar_array(const uchar *array,int length);
    static QString get_bit_str_from_uchar_array(const QByteArray &d);
    /**
     * @brief get_binary_data_from_hex_str "FFFF" -> data[] = {255,255}
     * @param array
     * @param length                       Condition : length % 2 == 0
     * @param out
     * @return
     */
    static bool get_binary_data_from_hex_str(const uchar *hexStr,
                                             int length,
                                             QByteArray &out);
    /*****************************************************************************************/
    template<class T>
    static QString get_str_from_enum_value(const QString& enumName,int enumNumber)
    {
        QMetaObject mo = T::staticMetaObject;
        int index = mo.indexOfEnumerator(enumName.toStdString().c_str());
        QMetaEnum enumm = mo.enumerator(index);
        return QString(enumm.valueToKey(enumNumber));
    }
    template<class T>
    //ONLY support the slots methods;
    static void set(QWidget* p,
                    bool enable,
                    const QStringList& objName,
                    const QString& method = "setEnabled")
    {
        if(p){
            foreach (const QString &it, objName) {
                T *tmp = p->findChild<T*>(it);
                if(tmp){
                    bool ret = QMetaObject::invokeMethod(tmp,
                                                         method.toStdString().c_str(),
                                                         Qt::QueuedConnection,
                                                         Q_ARG(bool, enable));
                    tmp = NULL;
                    (void)ret;
                }
            }
        }
    }

    static bool is_big_endian();
    static QString get_data_type_size();

    //encode for first call,decode for secend call
    static uchar encode_and_decode(uchar A);
    /*****************************************************************************************/

#if (QT_VERSION <= QT_VERSION_CHECK(5, 4, 2)) && M_ENABLE_ICONV

    static QByteArray iconvt(const uchar *src,
                             uint length_src,
                             const char *from = "gbk",
                             const char *to = "utf-8",
                             uint length_tmp_how_many_times_than_length_src = 2);
#endif

    static QByteArray iconvt(const QByteArray &data,CodeType type = GBK_2_UTF8);

    static QByteArray iconvt_QTextCodec(const QByteArray &data,CodeType type = GBK_2_UTF8);

#ifdef Q_OS_WIN32

    static QByteArray iconvt_WCHAR(const QByteArray &data,CodeType type = GBK_2_UTF8);

#endif //Q_OS_WIN32
    /**
     * @brief mTime2Time
     * @param from
     * @param to
     * @return
     *      "2017-01-01 08:08:08.000" - "2017-01-01 08:08:08.001"
     *      mimisecond of two time-stamp
     * NOTE:
     *      "from" < "to" return >0
     *      "from" < "to" return >0
     *      "from" < "to" return >0
     */
    static llint time_2_time(const QString &from,const QString &to);
    /*****************************************************************************************/
    //2000-2099
    static QString get_canlendar();
#ifdef Q_OS_LINUX

    static M_DEPRECATED_API QString mGetHardDiskSerialNumber();

    static bool mIsValidSerial8250(const QString &systemLocation);

    static QString mGetUUID();
#endif //Q_OS_LINUX

    static M_DEPRECATED_API bool is_stable(ld newData,
                                           int times = 5,
                                           ld range = 500);

    template <class T>
    static T get_variance(const QList<T> &list)
    {
        T ret = 0;
        if(list.length() > 0){
            T avg = 0;
            foreach (T i, list) {
                avg += i;
            }
            avg = avg / list.length();
            T sum = 0;
            foreach (T i, list) {
                sum += ::pow(::qAbs(i - avg),2);
            }
            ret = sum / list.length();
        }
        return ret;
    }
    //2017-01-01 01:00:00.000
    static QString add_msecond(const QString& time,qint64 ms);
#ifdef M_ENABLE_FFMPEG

    //yuv420p ---> rgb24
    static QImage mYuv420p2rgb24(const uchar* const data[4],
    const int linesize[4],
    int width,
    int height,
    AVPixelFormat fmt = AV_PIX_FMT_YUV420P);

#endif //M_ENABLE_FFMPEG
#ifdef M_ENABLE_OPENCV

    //opencv matrix ---> QImage
    static QImage mCvMat2QImage(const cv::Mat& mat);

#endif //M_ENABLE_OPENCV
    /*************************************************************
     * ...111A222A333 = 222
     * 222A333        = 222
     * 111222333      = ""
     * ***********************************************************/
    static QString get_last_cut_str(const QString& data,const QString& flag);

    static QString get_str_json_array_from_QStringList(const QStringList & l,
                                                       QJsonDocument::JsonFormat format = QJsonDocument::Compact);
    static QString get_str_json_array_from_QList_QString(const QList<QString> & l,
                                                         QJsonDocument::JsonFormat format = QJsonDocument::Compact);

    static QString get_str_json_array_from_QXmlStreamAttributes(const QXmlStreamAttributes & attr,
                                                                QJsonDocument::JsonFormat format = QJsonDocument::Compact);

    /**
     * Add a unique symbol in data,
     * Default split symbol: '#'
     * Encode rule:
     *   * -> *1
     *   # -> *2
     * Decode rule:
     *   *2 -> #
     *   *1 -> *
     */
    static QByteArray translate_data(const QByteArray &data,bool encode = true);
    /**
     * INPUT OUTPUT   | INPUT OUTPUT
     * 20 QSize(5, 4) | 30 QSize(6, 5)
     * 21 QSize(5, 5) | 31 QSize(6, 6)
     * 22 QSize(5, 5) | 32 QSize(6, 6)
     * 23 QSize(5, 5) | 33 QSize(6, 6)
     * 24 QSize(6, 4) | 34 QSize(6, 6)
     * 25 QSize(5, 5) | 35 QSize(7, 5)
     * 26 QSize(6, 5) | 36 QSize(6, 6)
     * 27 QSize(6, 5) | 37 QSize(7, 6)
     * 28 QSize(6, 5) | 38 QSize(7, 6)
     * 29 QSize(6, 5) | 39 QSize(7, 6)
     * */
    static QSize get_QSize_from_int(int n);

    /**
     *  If sep does not match anywhere in the byte array,
     *  split() returns a single-element list containing this byte array.
     *
     *  The last empty element(at sep`s right side) will not be added into list.
     *
     *  Example:
     *      QByteArray dd(",1,,2,3465,");
     *      MDG << MTL::split(dd,",")
     *          << MTL::split(dd,",,,")
     *          << MTL::split(dd,",,");
     *
     *  Output is:
     *     ("", "1", "", "2", "3465") (",1,,2,3465,") (",1", "2,3465,")
     */
    static QList<QByteArray> split(const QByteArray &data,const QByteArray &sep);

    /*
     * Return true in these cases:
     *
     *  1.container.isEmpty() == true, item.isEmpty() == true.
     *  2.container.isEmpty() != true, item.isEmpty() == true.
     *  3.container >= item.
     * */
    static bool contains(const QJsonObject &container,const QJsonObject &item);

    static QString get_str_from_QJsonValue(const QJsonValue &value);

    /*
     * json2`s value will cover json1 if they have a same key.
     * */
    static QJsonObject add(const QJsonObject &json1,const QJsonObject &json2);

    template <class T>
    static QList<QList<T> > split(const QList<T> &list,int size )
    {
        QList<QList<T> > ret;
        for(int i = 0; i < (list.length() / size + 1); i++){
            QList<T> row;
            for(int j = 0; ((j < size) && ( (i * size + j) < list.length() )); j++){
                row << list.at(i * size + j);
            }
            if(row.length() > 0)
                ret << row;
        }
        return ret;
    }

    static QByteArray hash_hmac(const QByteArray &key, const QByteArray &baseString);

protected:
    static QString get_rand_str_private(int length);
    static QString get_number_str_private(int length);
    static QString get_character_str_private(int length);
    static void delete_all_items_by_recursion_private(QTreeWidgetItem *it);

    static QReadWriteLock lock_setting_file;
    static QMap<ullint, QList<ld>* > map_data;
};
/***************************************************** MKit:MError ***/

/*
 * If u want to mark data with something, just use this.
 * */

//convenient MACRO
#define MMARKEDINFO MMarkedInfo(QDateTime::currentDateTime(),\
    QString("%1").arg(__LINE__),\
    QString("%1").arg(__FILE__),\
    Q_FUNC_INFO,\
    M_TIME_COMPILE,\
    QThread::currentThread(),\
    QThread::currentThread()->objectName())

class MMarkedInfo
{
public:
    MMarkedInfo();
    MMarkedInfo(const QDateTime &time,
                const QString &line,
                const QString &file,
                const QString &func,
                const QString &compileTime,
                const QThread *threadPointer,
                const QString &threadName);
    MMarkedInfo(const MMarkedInfo &other);
    virtual ~MMarkedInfo();

    MMarkedInfo &operator =(const MMarkedInfo &other);

    //the order of the returned string depends on QJsonDocument
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;
    QJsonObject toJsonObject() const;

    void clear();

    QDateTime time;
    QString line;
    QString file;
    QString func;
    QString compileTime;
    const QThread *threadPointer;
    QString threadName;
};

/*
 * nested example:
 *
 *      MMarkedData d;
 *      MMarkedData d2;
 *      d2 = MMARKEDDATA(d.toJsonObject());
 *
 *      MDG << d2.toJsonString(QJsonDocument::Indented);
 * */
//convenient MACRO
#define MMARKEDDATA(jsonValue) MMarkedData(jsonValue,MMARKEDINFO)

class MMarkedData{
public:
    MMarkedData(const QJsonValue &data = "",const MMarkedInfo &info = MMarkedInfo());
    MMarkedData(const MMarkedData &other);
    virtual ~MMarkedData();

    MMarkedData &operator =(const MMarkedData &other);

    //the order of the returned string depends on QJsonDocument
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;
    QJsonObject toJsonObject() const;

    void clear();

    QJsonValue data;
    MMarkedInfo info;
};

typedef MMarkedData MExpection2;
/*
 * Example:
 *
 *      try{
 *          throw MEXPECTION2("system error...");
 *      }catch(MExpection2 e){
 *          MDG << e.toJsonObject();
 *      }
 * */
#define MEXPECTION2(qstring) MMARKEDDATA(qstring)

class MError
{
public:
    MError();
    MError(const MError &other);
    virtual ~MError();

    MError &operator =(const MError &other);

    virtual MMarkedData getError() const;

protected:
    /*
     * Clear error if v == true, and return v,
     * if u want to clear error when function goes to return true.
     * */
    bool clearError(bool v);
    /*
     * Human-readable error description,
     * if any error happens,just set here.
     * */
    MMarkedData errorData;
};
/***************************************************** MKit:MQmlTool ***/
class M_CLASS_LIB_DECL MQmlTool : public QObject
{
    Q_OBJECT

public:
    explicit MQmlTool(QObject *parent = 0);

    Q_INVOKABLE static QString getTime();

    Q_INVOKABLE static QByteArray get_data_from_file(const QString &file);

    Q_INVOKABLE static QVariant get_config(const QString &f, const QString &key);


public slots:
    static void log(const QString &lg,const QString &type);

    static void set_config(const QString& f,const QString& key,const QVariant& value);

    static void set_data_2_file(const QString &file,const QByteArray &data,int type = 0);

private:
    Q_DISABLE_COPY(MQmlTool)
};

/***************************************************** MKit:MKeyBoard ***/

/*************************************************************
 * default ui widget:  QToolButton  QLineEdit
 * requirement:
 *          the text() of the button must be : "^[a-zA-Z0-9_-]{1}$"
 *          total : 26+1+2+10+1

 * button name like:
 * QRegExp rg("^toolButton_([0-9a-zA-Z_]{1}|(cap)|(del)|(__))$");
 *************************************************************/
class M_DEPRECATED_API M_CLASS_LIB_DECL MKeyBoard : public QObject
{
    Q_OBJECT
public:
    explicit MKeyBoard(const QStringList& buttonObjName,//all buttons
                       QWidget *UIwidget,               //where the button at
                       const QString& toolButtonName_cap = "toolButton_cap",
                       const QString& toolButtonName_del = "toolButton_del",
                       QObject *parent = 0);
    ~MKeyBoard();

protected slots:
    virtual void clicked_slot();

protected:
    QStringList list_buttonName;
    QWidget *UIwidget;
    bool uper;
    QString button_cap;
    QString button_del;

private:
    Q_DISABLE_COPY(MKeyBoard)
};
/***************************************************** MKit:MDigitVirtualKeyboard ***/

class M_CLASS_LIB_DECL MDigitVirtualKeyboard : public QWidget
{
    Q_OBJECT
public:
    MDigitVirtualKeyboard(QWidget *parent = 0);
    ~MDigitVirtualKeyboard();

protected slots:
    virtual void clicked_slot(bool);

protected:
    QGridLayout *layout_grid;
    QString prefixName;
    QList<QToolButton *> list_button;

private:
    Q_DISABLE_COPY(MDigitVirtualKeyboard)
};
/***************************************************** MKit:MVirtualKeyboard ***/

class M_CLASS_LIB_DECL MVirtualKeyboard : public QWidget
{
    Q_OBJECT
public:
    MVirtualKeyboard(QWidget *parent = 0);
    ~MVirtualKeyboard();

protected slots:
    virtual void clicked_slot(bool);

protected:
    QHBoxLayout *layout_h_1;
    QHBoxLayout *layout_h_2;
    QHBoxLayout *layout_h_3;
    QHBoxLayout *layout_h_4;
    QVBoxLayout *layout_v;

    QSpacerItem *spacer_1;
    QSpacerItem *spacer_2;
    QSpacerItem *spacer_3;

    MDigitVirtualKeyboard *keyboard_digit;
    QHBoxLayout *layout_h_main;

    QList<QToolButton *> list_button;

    bool upper;
    QString prefixName;

private:
    Q_DISABLE_COPY(MVirtualKeyboard)
};

/***************************************************** MKit:MQmlKeyboardInputDialog ***/

class M_CLASS_LIB_DECL MQmlKeyboardInputDialog : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible)
    Q_PROPERTY(QString styleSheet READ styleSheet WRITE setStyleSheet)

public:
    explicit MQmlKeyboardInputDialog(QObject *parent = 0);
    ~MQmlKeyboardInputDialog();

    Q_INVOKABLE QString text() const;
    Q_INVOKABLE bool isVisible() const;
    Q_INVOKABLE QString styleSheet() const;

signals:
    void ok();
    void cancel();

public slots:
    void show();
    void hide();
    void setVisible(bool v = true);
    void setText(const QString &data);
    void setStyleSheet(const QString &sheet);

private slots:
    void timeout();
    void clicked_slot_ok(bool);
    void clicked_slot_cancel(bool);

private:
    QWidget *widget_main;
    QVBoxLayout *layout_v;
    QHBoxLayout *layout_h;

    QLineEdit *edit;
    QWidget *kb;
    QLabel *label_time;
    QSpacerItem *spacer;
    QToolButton *button_ok;
    QToolButton *button_cancel;

    QTimer timer;
    int time_left_second;
};
/***************************************************** MKit:MLogger ***/
/** ./log/2017-01-01/erro_2017-01-01.log **/
#define M_LOG_DIR_DEFAULT              "./log"
#define M_LOG_FILE_NAME_PREFIX_DEFAULT "DEFAULT"
#define M_LOG_FILE_NAME_PREFIX_ERROR   "ERROR"
#define M_LOG_FILE_NAME_PREFIX_WARNING "WARNING"

#define M_LOG_FILE_NAME_PREFIX_THREAD   "THREAD"
#define M_LOG_FILE_NAME_PREFIX_HARDWARE "HARDWARE"
#define M_LOG_FILE_NAME_PREFIX_DATABASE "DATABASE"
#define M_LOG_FILE_NAME_PREFIX_NETWORK  "NETWORK"

#define M_LOG_FILE_NAME_PREFIX_DEBUG    "DEBUG"

/** option 1 **/
#define HITLOG3(content,filePrefix,path) \
    do{MLogger::log(QString(M_QSTRING_INFO_LONG(content) + M_ENTER),\
    (QString(filePrefix).length() > 0) ? filePrefix : M_LOG_FILE_NAME_PREFIX_DEFAULT,\
    (QString(path).length() > 0) ? path : M_LOG_DIR_DEFAULT);}while(0)

#define HITLOG2(content,filePrefix) \
    do{MLogger::log(QString(M_QSTRING_INFO_LONG(content) + M_ENTER),\
    (QString(filePrefix).length() > 0) ? filePrefix : M_LOG_FILE_NAME_PREFIX_DEFAULT);}while(0)

#define HITLOG2_GET_MACRO(_1,_2,_3,NAME,...) NAME
//only for gcc,mingw
#define HITLOG(...) HITLOG2_GET_MACRO(__VA_ARGS__, HITLOG3, HITLOG2)(__VA_ARGS__)

/** option 2 **/
#define HITLOG3_JSON_FORMAT(content,filePrefix,path) \
    do{MLogger::log(MMARKEDDATA(content).toJsonString(QJsonDocument::Indented),\
    (QString(filePrefix).length() > 0) ? filePrefix : M_LOG_FILE_NAME_PREFIX_DEFAULT,\
    (QString(path).length() > 0) ? path : M_LOG_DIR_DEFAULT);}while(0)

#define HITLOG2_JSON_FORMAT(content,filePrefix) \
    do{MLogger::log(MMARKEDDATA(content).toJsonString(QJsonDocument::Indented),\
    (QString(filePrefix).length() > 0) ? filePrefix : M_LOG_FILE_NAME_PREFIX_DEFAULT);}while(0)

#define HITLOG2_GET_MACRO_JSON_FORMAT(_1,_2,_3,NAME,...) NAME
//only for gcc,mingw
#define HITLOG_JSON_FORMAT(...) HITLOG2_GET_MACRO_JSON_FORMAT(__VA_ARGS__, HITLOG3_JSON_FORMAT, HITLOG2_JSON_FORMAT)(__VA_ARGS__)

class M_CLASS_LIB_DECL MLogger
{
public:
    MLogger();
    MLogger(const MLogger &other);
    MLogger &operator =(const MLogger &other);

    virtual ~MLogger();
    //thread-safe
    static void log(const QString& content,
                    const QString& fileNamePrefix = M_LOG_FILE_NAME_PREFIX_DEFAULT,
                    const QString& path = M_LOG_DIR_DEFAULT );
protected:
    static QMutex mutex;
};
/** option 1 **/
#define HITLOG2THREAD(str,filePrefix) \
    do { \
    QMetaObject::invokeMethod(MQThreadLogger::getObj(),\
    "log",\
    Qt::QueuedConnection,\
    Q_ARG(QString,M_QSTRING_INFO_LONG(str) + M_ENTER),\
    Q_ARG(QString,filePrefix));   \
    }while(0)
/** option 2 **/
#define HITLOG2THREAD_JSON_FORMAT(jsonValue,filePrefix) \
    do { \
    QMetaObject::invokeMethod(MQThreadLogger::getObj(),\
    "log",\
    Qt::QueuedConnection,\
    Q_ARG(QString,MMARKEDDATA(jsonValue).toJsonString(QJsonDocument::Indented)),\
    Q_ARG(QString,filePrefix));   \
    }while(0)

class MQThreadLogger : public QThread
{
    Q_OBJECT
public:
    static MQThreadLogger *getObj();
    static void destroyObj();

public slots:
    void log(const QString &data,const QString &filename_prefix);

protected:
    virtual void run();

private:
    static MQThreadLogger *obj;

    explicit MQThreadLogger(QObject *parent = 0);
    Q_DISABLE_COPY(MQThreadLogger)
};
/***************************************************** MKit:MDatabase ***/
class M_CLASS_LIB_DECL M_DEPRECATED_API MDatabase
{
public:
    MDatabase();
    MDatabase(const MDatabase &);
    virtual ~MDatabase();
    MDatabase & operator =(const MDatabase &);
    /**
     * Upgraded method,
     * Do NOT change QThread's objectName.
     **/
    static QSqlDatabase getDatabase(const QString &databaseName,
                                    const QString &type = QString("QSQLITE"),
                                    const QString &hostName = "",
                                    int port = 0,
                                    const QString &userName = "",
                                    const QString &passwd = "");
protected:
    static QMutex mutex;

    static QMap<QString,          //thread name
    QMap<QString,                 //threadName_connectionName
    QJsonObject                   //database object
    > > map_threadName_connection_json;

    static QMap<QString,    //threadName_connectionName
    QSqlDatabase            //db
    > map_connection_QSqlDatabase;

    static M_UNUSED_API QThreadStorage<QPair<QJsonObject,QSqlDatabase>* > buffer;

};
/***************************************************** MKit:MDatabaseConnectionPool ***/
class M_CLASS_LIB_DECL MDatabaseInfo{
public:
    MDatabaseInfo(const QString &databaseName = "main.db3",
                  const QString &type = "QSQLITE",
                  const QString &userName = "",
                  const QString &passwd = "",
                  const QString &hostName = "",
                  int port = 0);
    MDatabaseInfo(const MDatabaseInfo &info);
    virtual ~MDatabaseInfo();

    MDatabaseInfo &operator =(const MDatabaseInfo &info);
    bool operator !=(const MDatabaseInfo& o) const;
    bool operator ==(const MDatabaseInfo& o) const;
    QString toString() const;

    /** the order of the returned string depends on QJsonDocument **/
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;
    QJsonObject toJsonObject() const;

    QString name;
    QString type;
    QString hostName;
    int port;
    QString user;
    QString passwd;
};

class M_CLASS_LIB_DECL MDatabaseInfoWithTimestamp{
public:
    MDatabaseInfoWithTimestamp(const MDatabaseInfo &info = MDatabaseInfo());
    MDatabaseInfoWithTimestamp(const MDatabaseInfoWithTimestamp &o);
    virtual ~MDatabaseInfoWithTimestamp();
    MDatabaseInfoWithTimestamp &operator = (const MDatabaseInfoWithTimestamp &o);
    QString toString() const;

    /** the order of the returned string depends on QJsonDocument **/
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;
    QJsonObject toJsonObject() const;

    MDatabaseInfo info;
    QString time_last_access;
};

/**********************************************************
 * Option One
 * ********************************************************/
typedef QMap<QString,MDatabaseInfoWithTimestamp> ConnectionMap;
/*
 * Create ONE instance for EACH thread is the best way to use.
 * */
class M_CLASS_LIB_DECL MDatabaseConnectionPool : public QObject
{
    Q_OBJECT
public:
    MDatabaseConnectionPool(QObject * p = 0);
    /*
     * Do not send void removed(...) signal.
     * */
    virtual ~MDatabaseConnectionPool();

    //the database returned can ONLY be used in thread which this function was called
    QSqlDatabase getDatabase(const MDatabaseInfo &id);
    ConnectionMap getPool() const;

public slots:
    void removeConnection(int timeout_ms = 1000 * 60 * 5,bool sendSignal = true);
    void removeConnection(const MDatabaseInfo &info,bool sendSignal = true);
    void removeAll(bool sendSignal = true);

    /*
     * Default disabled.
     * */
    void enableConnectionWatcher(bool yes = true,int time_unused_ms = 1000 * 60 * 5);

signals:
    /*
     * Beter to use Qt::QueuedConnection
     *
     * If you need to hold the QSqlDatabase for long time by calling getDatabase(const MDatabaseInfo &info),
     * connect this signal to refresh database connection.
     * */
    void removed(const QString &connectionName,const MDatabaseInfoWithTimestamp &info);

protected slots:
    void unused_check_slot();

protected:
    void sendRemovedSignal(const QList<QPair<QString ,MDatabaseInfoWithTimestamp> > &s);
    /*
     * One database id for one connection name,
     * connection name is uuid.
     * */
    ConnectionMap pool;
    static QMutex *mutex;
    QTimer timer;

private:
    Q_DISABLE_COPY(MDatabaseConnectionPool)
};

/**********************************************************
 * Option Two
 * ********************************************************/
typedef QMap<QThread *,ConnectionMap> ConnectionMap2;

/*
 *  normally, this class bellow is the good option to choose.
 * */

//ONE instance for whole application is enough
class M_CLASS_LIB_DECL MApplicationDatabaseConnectionPool : public QObject
{
    Q_OBJECT
public:
    MApplicationDatabaseConnectionPool(QObject *p = 0);
    /*
     * Do not send void removed(...) signal.
     * */
    ~MApplicationDatabaseConnectionPool();

    //Thread-safe
    QSqlDatabase getDatabase(const MDatabaseInfo &info);
    const ConnectionMap2 &getPool() const;
    //the order of the returned string depends on QJsonDocument
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Indented) const;
    QJsonObject toJsonObject() const;

public slots:
    void removeConnection(const QThread *thread,bool sendSignal = true);
    void removeConnection(const MDatabaseInfo &info,bool sendSignal = true);
    void removeConnection(int time_unused_ms = 1000 * 60 * 5,bool sendSignal = true);
    void removeAll(bool sendSignal = true);

    /*
     * do NOT call this in multi thread,
     * cause QTimer can NOT be started or stopped in different thread.
     *
     * default disabled.
     * */
    void enableConnectionWatcher(bool yes = true,int time_unused_ms = 1000 * 60 * 5);

signals:
    /*
     * Beter to use Qt::QueuedConnection
     *
     * If you need to hold the QSqlDatabase for long time by calling getDatabase(const MDatabaseInfo &info),
     * connect this signal to refresh database connection.
     * */
    void removed(const QThread *t,const MDatabaseInfoWithTimestamp &info);

protected slots:
    void destroyed_slot(QObject * obj);

    void timeout_timer_unused_check_slot();

protected:
    void sendRemovedSignal(const QList<QPair<QThread *,MDatabaseInfoWithTimestamp> > &r);

    void clearEmptyItem();

    QMutex mutable *mutex;
    /*
     * Structure :
     *
     *     QPointer<QThread> *   -------> ConnectionName1,MDatabaseInfoWithTimestamp1
     *                           |
     *                           |
     *                           |------> ConnectionName2,MDatabaseInfoWithTimestamp2
     *                           |
     *                           |
     *                           |
     * */
    ConnectionMap2 pool;
    //remove connection which is long time no used
    QTimer timer_unused_check;

private:
    Q_DISABLE_COPY(MApplicationDatabaseConnectionPool)
};

/**********************************************************
  Option Three

  Example :

       MDatabaseInfo info("demo.db3");
       MScopedDatabase db(info);
       {
           QSqlDatabase d = db.getDatabase();
           MTran tran(&d);
           QSqlQuery q(d);
           ...
           tran.commit();
       }

 **********************************************************/
class MScopedDatabase{
public:
    MScopedDatabase(const MDatabaseInfo &info);
    /*
     * Auto release resources and remove current connection.
     */
    virtual ~MScopedDatabase();

    QSqlDatabase getDatabase() const;

    MDatabaseInfo getDatabaseInfo() const;

protected:
    static QMutex *mutex;
    QString connectionName;

    MDatabaseInfo dbInfo;

private:
    Q_DISABLE_COPY(MScopedDatabase)
};
/***************************************************** MKit:MTran ***/
class MTran{
public:
    /*
     * Auto begin().
     * If u NOT call commit(),your change will be dropped.
     * */
    explicit MTran(QSqlDatabase *d);
    /*
     * Auto rollback() if necessary.
     * */
    virtual ~MTran();

    void begin();
    /*
     * Call commit() manually.
     * */
    void commit();
    void rollback();

protected:
    Q_DISABLE_COPY(MTran)

    bool transform;
    QSqlDatabase *db;
};

/***************************************************** MKit:MExpection ***/

M_DEPRECATED_API
//use MExpection2 instead.

class M_CLASS_LIB_DECL MExpection
{
public:
    MExpection();
    MExpection(const QString & time,
               const QString & compiletime,
               const QString & line,
               const QString & file,
               const QString & func,
               const QString & threadId,
               const QString & threadName,
               const QString & str);
    MExpection(const MExpection & other);
    virtual ~MExpection();
    MExpection & operator=(const MExpection & other);

    QString toString() const;
    //the order of the returned string depends on QJsonDocument
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;
    QString getAddr() const;
    QString getText() const;

    QString time;
    QString compileTime;
    QString line;
    QString file;
    QString func;
    QString threadId;
    QString threadName;
    QString text;
};

#define M_THROW_MEXPECTION(str) do{throw MExpection(M_TIME_NOW_MILLISECONDS,\
    M_TIME_COMPILE,\
    QString(__LINE__),\
    __FILE__,\
    Q_FUNC_INFO,\
    QString().sprintf("0x%016llX",(ullint)QThread::currentThread()),\
    QThread::currentThread()->objectName(),\
    str);}while(0)

#define M_CATCH_IGNORE catch(...){}

/******************************************************** MKit:MList ***/

/**
    EXAMPLE:

    MList *list = MList_create();
    int count = 10;
    //append
    for(int i = 0; i < count; i++){
        MNode *node = MNode_create();
        node->data = new QString(QString::number(i));
        MList_append(list,node);
    }
    MDG << list->length
        << *(QString *)list->last->data;
    //remove
    for(int i = 0; i < count; i++){
        MDG << *(QString *)MList_takeAt(list,count - i - 1)->data;
    }
    MDG << list->length;
  **/

typedef struct MNode{
    MNode *next;
    /*
     * Point to ANY data,it is user`s business to malloc/free.
     * */
    void *data;
}MNode,*MPNode;

MNode *MNode_create();
void MNode_destroy(MNode *node);

typedef struct MList{
    /*
     * Point to first node.
     * */
    MNode *head;
    /*
     * Point to last node,for fast append item.
     * */
    MNode *last;
    /*
     * Length of list.
     * */
    int length;
}MList,*MPList;

MList *MList_create();
/*
 * list is NOT valid after this call,use MList_create() to create new one.
 * */
void MList_destroy(MList *list);
/*
 * ONLY clear items,list can be reused later.
 * */
void MList_clear(MList *list);
/*
 * Fast append item,const time.
 * */
void MList_append(MList *list,const MNode *node);
/*
 * Returns 0 if fail.
 * */
MNode *MList_takeFirst(MList *list);
/*
 * Returns 0 if fail.
 * */
MNode *MList_takeLast(MList *list);
/*
 * Returns 0 if fail.
 * */
MNode *MList_takeAt(MList *list,int index);
/*
 * Returns 0 if fail.
 * */
MNode *MList_at(MList *list,int index);
/***************************************************** MKit:MVector ***/
/**
    EXAMPLE:

    MVector * vv = MVector_create(1);
    //push
    for(int i = 0; i < 1 * 10; i++){
        MVector_push_back(vv,  new QString(QString::number(i)));
    }
    //read
    for(int i = 0 ; i  < vv->used; i++){
        MDG << *(QString *)vv->data[i];
    }
    int used = vv->used;
    //pop
    for(int i = 0 ; i < used; i++){
        QString *item = (QString *)MVector_pop_front(vv);
        MDG << *item;
        delete item;
    }
    //clear
    MVector_clear(vv);
    MVector_push_back(vv,new QString("hello world"));
    MDG << vv->used
        << vv->length;
    //read
    for(int i = 0; i < vv->used; i++){
        MDG << *(QString *)vv->data[i];
    }
    //delete items
    for(int i = 0 ; i < vv->used; i++){
        delete vv->data[i];
    }
    //destory vector
    MVector_destroy(vv);
  */
typedef struct MVector{
    /*
     * A pointer array, point to ANY data,it is user`s business to destroy items one by one.
     *
     * Total memory is: sizeof(void *) * length.
     * */
    void **data;
    /*
     * Current used items of vector.
     * */
    int used;
    /*
     * Total items of the vector.
     * */
    int length;
}MVector;

MVector *MVector_create(int length);
/*
 * v is NOT valid after this call,use MVector_create() to create new one.
 * */
void MVector_destroy(MVector *v);
/*
 * ONLY clear items,v can be reused later.
 * */
void MVector_clear(MVector *v);

void MVector_add(MVector *v,int length);
void MVector_push_back(MVector *v,void *item);
void* MVector_pop_back(MVector *v);
void* MVector_pop_front(MVector *v);

/******************************************************** MKit:MCString ***/
/**
  EXAMPLE:

    MCString *MCString_ = MCString_create();
    for(int i = 0; i < 3; i++){
         MCString_append(MCString_,"123",3);
    }
    char *str = MCString_c_str(MCString_);
    MDG << MCString_->length
        << str;

    free(str);
    MCString_destroy(MCString_);

  */
typedef struct MCString{
    /*
     * NOT ending with a '\0'.
     */
    char *str;
    /*
     * length of total bytes.
     */
    int length;
}MCString;

MCString *MCString_create();
/*
 * use MCString_create() to create a new one after this call.
 */
void MCString_destroy(MCString *MCString_);

void MCString_clear(MCString *MCString_);

void MCString_append(MCString *MCString_,const char *str,int length);
/*
 * call MCString_destroy() when you are done with it.
 */
MCString *MCString_mid(const MCString *MCString_,int index, int length);

/*
 * returns -1 if not exist.
 */
int MCString_indexOf(const MCString *MCString_,const char *str, int length);

/*
 * returns -1 if not exist.
 */
int MCString_lastIndexOf(const MCString *MCString_, const char *str, int length);

/*
 * call MCString_destroy() when you are done with it.
 */
MCString *MCString_clone(const MCString *MCString_);

/*
 * Convert to c-string ending with a '\0'.
 * Call free() when you are done with it.
 */
char *MCString_c_str(const MCString *MCString_);

/***************************************************** MKit:MLinkList ***/

template <typename T>
class MLinkList{
    typedef struct node{
        node* pre;
        node* next;
        T data;
    }node,*pnode;
public:
    MLinkList() {
        head = new node;
        head->pre = head;
        head->next = head;
        length = new int(0);
        count_ref = new size_t(1);
    }
    MLinkList(const MLinkList<T> & other){
        length = other.length;
        head = other.head;
        count_ref = other.count_ref;
        (*count_ref)++;
    }
    virtual ~MLinkList(){ release();}
    void clear(){
        //check if shared
        if(*count_ref == 1){
            pnode cnode = NULL;
            pnode tmp = NULL;
            for(cnode = head->next; cnode != head; ){
                tmp = cnode;
                cnode = cnode->next;
                delete tmp;
            }
        }else{
            (*count_ref)--;
            count_ref = new size_t(1);
            head = new node;
            length = new int(0);
        }
        head->next = head;
        head->pre =  head;
        *length = 0;
    }
    bool isEmpty() const        {  return head->next == head ;}
    int size() const            {  return *length; }
    void append(const T & value){  *this << value; }

    void append(const MLinkList<T> & other){
        checkCopy();
        MLinkList<T>::ConstItorater it;
        for(it = other.constBegin(); it != other.constEnd(); it++){
            *this << it.value();
        }
    }
    bool contains(const T & value) const {
        MLinkList<T>::ConstItorater it;
        for(it = constBegin(); it != constEnd(); it++){
            if(it.value() == value){
                return true;
            }
        }
        return false;
    }
    /***********************************************
     * return the first element's index which == value
     * return -1 ,if value do not exist
     * ********************************************/
    int indexOf(const T & value) const {
        int i = -1;
        MLinkList<T>::ConstItorater it;
        for(it = constBegin(); it != constEnd(); it++){
            i++;
            if(it.value() == value){
                return i;
            }
        }
        return -1;
    }
    /***********************************************
     * return the last element's index which == value
     * return -1 ,if value do not exist
     * ********************************************/
    int lastIndexOf(const T & value) const {
        int i = -1;
        //from the end
        pnode cnode = NULL;
        pnode tmp = NULL;
        for(cnode = head->pre; cnode != head; ){
            tmp = cnode;
            cnode = cnode->pre;
            i++;
            if(tmp->data == value){
                return *length - i - 1;
            }
        }
        return -1;
    }
    //list's size must > 0
    T & last(){
        checkCopy();
        return head->pre->data;
    }
    //list's size must > 0
    T & first(){
        checkCopy();
        return head->next->data;
    }
    //list's size must > 0
    T takeFirst(){
        checkCopy();
        pnode first = head->next;
        pnode second = first->next;
        head->next = second;
        second->pre = head;
        T t = first->data;
        delete first;
        (*length)--;
        return t;
    }
    //list's size must > 0
    T takeLast(){
        checkCopy();
        pnode first = head->pre;
        pnode second = first->pre;
        second->next = head;
        head->pre = second;
        T t = first->data;
        delete first;
        (*length)--;
        return t;
    }
    /******************************************
     * index >= size, append;
     * index < 0, insert into first;
     * ***************************************/
    void insert(int index,const T & value){
        if(index < 0)index=0;
        if(index >= *length){
            *this << value;
            return ;
        }
        checkCopy();
        //count=5 index=2
        //locate the node of index=2, 0 1 2 3 4
        pnode tmp = head;
        if(index > (*length >> 1)){
            int max = *length - index;
            for(int i = 0; i < max; i++){
                tmp = tmp->pre;
            }
        }
        else{
            for(int i = 0; i <= index; i++){
                tmp = tmp->next;
            }
        }
        //index=1
        tmp = tmp->pre;
        pnode node1 = tmp;
        pnode node2 = tmp->next;
        //fill data
        pnode newNode = new node;
        newNode->data = value;
        newNode->next = node2;
        newNode->pre = node1;
        node1->next = newNode;
        node2->pre = newNode;
        (*length)++;
    }
    //this function does nothing if index do not exist
    void removeAt(int index){
        if(index >= 0 && index < *length){
            checkCopy();
            pnode tmp = head;
            if(index > (*length >> 1)){
                int max = *length - index;
                for(int i = 0; i < max; i++){
                    tmp = tmp->pre;
                }
            }
            else{
                for(int i = 0; i <= index; i++){
                    tmp = tmp->next;
                }
            }
            //0 1 2 3 4
            pnode node1 = tmp->pre;
            pnode node2 = tmp->next;
            node1->next = node2;
            node2->pre = node1;
            delete tmp;
            (*length)--;
        }
    }
    //return the number of items removed
    int removeAll(const T & value){
        checkCopy();
        int i = 0;
        pnode cnode = NULL;
        pnode tmp = NULL;
        for(cnode = head->next; cnode != head; ){
            tmp = cnode;
            cnode = cnode->next;
            if(tmp->data == value){
                //delete current node
                pnode node1 = tmp->pre;
                pnode node2 = tmp->next;
                delete tmp;
                node1->next = node2;
                node2->pre = node1;
                i++;
                (*length)--;
            }
        }
        return i;
    }
    bool removeFirstOne(const T & value){
        checkCopy();
        pnode cnode = NULL;
        pnode tmp = NULL;
        for(cnode = head->next; cnode != head; ){
            tmp = cnode;
            cnode = cnode->next;
            if(tmp->data == value){
                //delete current node
                pnode node1 = tmp->pre;
                pnode node2 = tmp->next;
                delete tmp;
                node1->next = node2;
                node2->pre = node1;
                (*length)--;
                return true;
            }
        }
        return false;
    }
    bool removeLastOne(const T & value){
        this->checkCopy();
        pnode cnode = NULL;
        pnode tmp = NULL;
        for(cnode = head->pre; cnode != head; ){
            tmp = cnode;
            cnode = cnode->pre;
            if(tmp->data == value){
                pnode node1 = tmp->pre;
                pnode node2 = tmp->next;
                delete tmp;
                node1->next = node2;
                node2->pre = node1;
                (*length)--;
                return true;
            }
        }
        return false;
    }
    int countOf(const T & value) const {
        int c = 0;
        MLinkList<T>::ConstItorater it;
        for(it = constBegin();it != constEnd(); it++){
            if(it.value() == value){
                c++;
            }
        }
        return c;
    }
    QSet<T> toQSet() const {
        QSet<T> s;
        MLinkList<T>::ConstItorater it;
        for(it = constBegin(); it != constEnd(); it++){
            s.insert(it.value());
        }
        return s;
    }
    QList<T> toQList() const {
        QList<T> l;
        MLinkList<T>::ConstItorater it;
        for(it = constBegin(); it != constEnd(); it++){
            l.append(it.value());
        }
        return l;
    }
    MLinkList<T> invert() const {
        MLinkList<T> tmp;
        MLinkList<T>::ConstItorater it;
        for(it = constBegin(); it != constEnd(); it++){
            tmp.insert(0,it.value());
        }
        return tmp;
    }
    //cut
    //0 1 2 3 4 5
    // index == 1 ,length == 100
    //if index is not valid, begin from index=0
    MLinkList<T> mid(int index,int length = -1) const {
        if(index < 0 || index >= *this->length){
            index = 0;
        }
        if(length <= 0 || (index + length) >= *this->length ) {
            length = *this->length - index;
        }
        //locate the beginning index
        pnode tmp = head;
        if(index > (*this->length >> 1)){
            int max = *this->length - index;
            for(int i = 0; i < max; i++){
                tmp = tmp->pre;
            }
        }else{
            for(int i = 0; i <= index; i++){
                tmp = tmp->next;
            }
        }
        MLinkList<T> ret;
        for(int i = 0; i < length; i++){
            ret << tmp->data;
            tmp = tmp->next;
        }
        return ret;
    }
    //index must be valid
    const T & at(int index) const {
        //count=5 index=3
        pnode tmp = head;
        if(index > (*length >> 1)){
            int max = *length - index;
            for(int i = 0; i < max; i++){
                tmp = tmp->pre;
            }
        } else {
            for(int i = 0; i <= index; i++){
                tmp = tmp->next;
            }
        }
        return tmp->data;
    }
    //index must be valid
    T & operator[](int index){
        checkCopy();
        //count=5 index=3
        pnode tmp = head;
        if(index > (*length >> 1)){
            //inverted sequence
            int max = *length - index;
            for(int i = 0; i < max; i++){
                tmp = tmp->pre;
            }
        } else {
            //positive sequence
            for(int i = 0; i <= index; i++){
                tmp = tmp->next;
            }
        }
        return tmp->data;
    }
    MLinkList<T> & operator << (const T & value){
        checkCopy();
        pnode tmp = new node;
        tmp->data = value;
        tmp->next = head;
        tmp->pre = head->pre;
        head->pre->next = tmp;
        head->pre = tmp;
        (*length)++;
        return *this;
    }
    MLinkList<T> & operator = (const MLinkList<T> & other){
        if(this == &other)return *this;
        release();
        head = other.head;
        length = other.length;
        count_ref = other.count_ref;
        (*count_ref)++;
        return *this;
    }
    class itorater{
    public:
        itorater() : i(NULL){}
        itorater(node *n) : i(n){}
        itorater(const itorater & other) : i(other.i){}
        ~itorater(){ }

        itorater & operator = (const itorater &it)
        {
            if(this == &it)return *this;
            i = it.i;
            return *this;
        }
        bool operator != (const itorater &it)
        {
            return i != it.i;
        }
        itorater & operator ++(int)
        {
            i = i->next;
            return *this;
        }
        T & value()
        {
            return this->i->data;
        }
    protected:
        node *i;
    };
    itorater begin()
    {
        checkCopy();
        return itorater(head->next);
    }
    itorater end()
    {
        return itorater(head);
    }
    class ConstItorater{
    public:
        ConstItorater() : i(NULL){}
        ConstItorater(node *n) : i(n){}
        ConstItorater(const ConstItorater & other) : i(other.i){}
        ~ConstItorater() {}

        ConstItorater & operator = (const ConstItorater &it)
        {
            if(&it != this){
                i = it.i;
            }
            return *this;
        }
        bool operator != (const ConstItorater &it)
        {
            return i != it.i;
        }
        ConstItorater & operator ++(int)
        {
            i = i->next;
            return *this;
        }
        const T & value() const
        {
            return i->data;
        }
    protected:
        node *i;
    };
    ConstItorater constBegin() const
    {
        return ConstItorater(head->next);
    }
    ConstItorater constEnd() const
    {
        return ConstItorater(head);
    }
protected:
    void release(){
        //check if need delete
        if(0 >= --*count_ref){
            pnode cnode = NULL;
            pnode tmp = NULL;
            for(cnode = head->next; cnode != head; ){
                tmp = cnode;
                cnode = cnode->next;
                delete tmp;
            }
            delete head;
            delete length;
            delete count_ref;
        }
    }
    //return the count of node
    int copy(pnode from,pnode to){
        int i = 0;
        pnode cnode = NULL;
        pnode tmp = NULL;
        for(cnode = from->next; cnode != from; ){
            tmp = cnode;
            cnode = cnode->next;
            pnode tmp2 = new node;
            tmp2->data = tmp->data;
            tmp2->next = to;
            tmp2->pre = to->pre;
            to->pre->next = tmp2;
            to->pre = tmp2;
            i++;
        }
        return i;
    }
    void checkCopy(){
        //check if shared
        if(*count_ref > 1){
            (*count_ref)--;
            count_ref = new size_t(1);
            //copy
            pnode old = head;
            pnode newNode = new node;
            newNode->next = newNode;
            newNode->pre = newNode;
            length = new int(0);
            *length = copy(old,newNode);
            head = newNode;
        }
    }
    pnode head;
    int * length;
    size_t * count_ref;
};

/***************************************************** MKit:MLoad ***/

//for POST
class M_CLASS_LIB_DECL MLoad : public QObject
{
    Q_OBJECT
public:
    explicit MLoad(QObject *parent = 0);
    ~MLoad();
    /*************************************************
    * append data to file
    * ************************************************/
    bool mLoad(const QString& url,
               const QByteArray& data,
               const QString& filePathFull);
    bool mReLoad();
    bool mIsTimerRunning();
    bool mIsDownloading();
    QByteArray mGetPostedData();
    QString mGetDownloadingFile();
    QString mGetPostedUrl();
public slots:
    //abort, drop the data
    void mAbort();
    //timeout interval for mimisecond, enable for next time
    void mSetTimerInterval(int i);
    void mSetTimerEnabled(bool enable);
signals:
    /***********************************
     * NOTE:
     *      data load finished when timeout == false && error ==0,
     *      u need to call it again if the connection is dead on error
     * ********************************/
    void mFinished(const QUrl & url,
                   const QList<QPair<QByteArray,QByteArray> > & header,
                   bool timeout ,
                   QNetworkReply::NetworkError error,
                   const QString & file,
                   quint64 fileSize);
protected slots:
    void readyRead_slot();
    void finished_slot();
    virtual void timerEvent(QTimerEvent *);
protected:
    int timerid;
    int interval;
    bool timerEnabled;
    bool timeout;

    QByteArray data;
    QString url;
    QString filePathFull;
    QNetworkAccessManager manager;
    QNetworkReply* reply;

private:
    Q_DISABLE_COPY(MLoad)
};
/***************************************************** MKit:MMedia ***/

class M_CLASS_LIB_DECL MMedia : public QObject
{
    Q_OBJECT
public:
    static MMedia* getObj();
    ~MMedia();
    bool play(const QStringList& sound_file,bool newWarning = false);

    void stop();
    void pause();
    void resume();

private:
    explicit MMedia(QObject *parent = 0);
    Q_DISABLE_COPY(MMedia)

    static MMedia* obj;
    QMediaPlaylist* playList;
    QMediaPlayer* player  ;
    QVideoWidget* videoWidget  ;
    QStringList list_current_playing_file;
    volatile bool isWarning;
};
/***************************************************** MKit:MMultiMediaWidget ***/

class M_CLASS_LIB_DECL MMultiMediaWidget : public QWidget
{
    Q_OBJECT
public:
    enum MediaType
    {
        Animation,
        Video
    };
    //default  MediaType::Animation
    explicit MMultiMediaWidget(QWidget *parent = 0,
                               MediaType t = MMultiMediaWidget::Animation);
    ~MMultiMediaWidget();

    MediaType mediaType();
    void setMediaType(MediaType t);

    QVBoxLayout *vboxLayout();
    //gif,picture
    QLabel *label();
    QMovie *movie();

    QVideoWidget *videoWidget();
    QMediaPlayer *mediaPlayer();
    QMediaPlaylist *mediaPlaylist();

signals:
    void mouseReleased();

protected:
    virtual void mouseReleaseEvent(QMouseEvent *e);
    void chooseType(MediaType t);

protected:
    QLabel *label_pic;
    QMovie *movie_pic;
    MediaType type;
    QVBoxLayout *layOut;

    QMediaPlayer *player;
    QVideoWidget *VideoWidget;
    QMediaPlaylist *playList;

private:
    Q_DISABLE_COPY(MMultiMediaWidget)
};
/***************************************************** MKit:MPictureWidget ***/

class M_CLASS_LIB_DECL MPictureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MPictureWidget(QWidget *parent = 0);
    const QImage & picture() const;
    Qt::AspectRatioMode aspectRatioMode() const;

signals:
    void aspectRatioModeChanged(Qt::AspectRatioMode s);
    void pictureChanged(QImage p);
    void doubleClicked();

public slots:
    void setAspectRatioMode(Qt::AspectRatioMode s);
    void setPicture(const QImage& p);

protected:
    virtual void paintEvent(QPaintEvent* e);
    virtual void mouseDoubleClickEvent(QMouseEvent *e);

private:
    Q_DISABLE_COPY(MPictureWidget)

    QImage image_pic;
    Qt::AspectRatioMode model;
};
/***************************************************** MKit:MPointer ***/

template <class T>
class M_CLASS_LIB_DECL MScopedPointer
{
public:
    enum PointerType{ NormalPointer,ArrayPointer };

    explicit MScopedPointer(T* p = 0,PointerType t = NormalPointer) :
        pointer(p),
        counter(new size_t),
        type(t){
        *counter = 1;
    }
    virtual ~MScopedPointer(){
        release();
    }
    MScopedPointer(const MScopedPointer & p){
        counter = p.counter;
        pointer = p.pointer;
        type = p.type;
        (*counter)++;
    }
    /*
     * Will delete the pointer.
     * */
    MScopedPointer & operator=(const MScopedPointer & p){
        if(this != &p){
            release();
            counter = p.counter;
            pointer = p.pointer;
            type = p.type;
            ++*counter;
        }
        return *this;
    }
    inline operator bool() const{ return pointer; }
    inline bool operator!() const{return !pointer;}
    inline T *operator->() const{ return pointer; }
    inline T &operator*() const{  return *pointer; }
    inline bool isNull() const{   return pointer == 0;}
    inline T *data() const{       return pointer; }
    inline T &ref() const{        return *pointer;}
    inline PointerType getType(){ return type;}

    /*
     * just take the pointer and reset to NULL,
     *
     * this function do NOT delete the pointer even it is the last reference,
     * it's caller's responsible to delete T*.
     * */
    inline T *take(){
        if(0 >= --*counter){
            delete counter;
        }
        counter = new size_t(1);
        T* tmp = pointer;
        pointer = NULL;
        type = NormalPointer;
        return tmp;
    }
    /*
     * Will delete the pointer and reset to new.
     * */
    inline void reset(T *newPointer = 0,PointerType t = NormalPointer){
        release();
        counter = new size_t(1);
        pointer = newPointer;
        type = t;
    }

protected:
    void release(){
        /*
         * When *counter == 1, means this is the last reference,
         * then need to delete the pointer and counter.
         * */
        if(0 >= --*counter){
            switch(type){
            case NormalPointer:
                M_DELETE_TO_NULL(pointer);
                break;
            case ArrayPointer:
                M_DELETE_TO_NULL_ARRAY(pointer);
                break;
            default:
                break;
            }
            M_DELETE_TO_NULL(counter);
        }
    }

    T* pointer;
    size_t* counter;
    PointerType type;
};

/******************************************************** MKit:MScopedCaller ***/
/**
    EXAMPLE:

    void test(void **data)
    {
        MainWindow *win = (MainWindow *)data[0];
        QString *s      = (QString *)data[1];
        MDG << win
            << s
            << *s;
    }

    QString dd = M_TIME_NOW_MILLISECONDS;
    void *data[2] = {(void *)this,(void *)&dd};
    MSCOPEDCALLER_NORMAL(p,test,data);

    bson_t *bs = bson_new();
    MSCOPEDCALLER_DESTROY_SAFE(pp,bson_destroy,&bs);
 */

typedef void (*MCallback)(void *);

#define MSCOPEDCALLER_DESTROY_SAFE(obj,func,secondPointer) \
    MScopedCaller obj##_((MCallback)func,(void *)secondPointer,MScopedCaller::Destroy);(void)obj##_;

#define MSCOPEDCALLER_NORMAL3(obj,func,normalPointer) \
    MScopedCaller obj##_((MCallback)func,(void *)normalPointer,MScopedCaller::Normal);(void)obj##_;

#define MSCOPEDCALLER_NORMAL2(obj,func) \
    MScopedCaller obj##_((MCallback)func,0,MScopedCaller::Normal);(void)obj##_;

#define MSCOPEDCALLER__(_1,_2,_3,NAME,...) NAME

//only for gcc,mingw
#define MSCOPEDCALLER_NORMAL(...) MSCOPEDCALLER__(__VA_ARGS__, MSCOPEDCALLER_NORMAL3, MSCOPEDCALLER_NORMAL2)(__VA_ARGS__)

class MScopedCaller
{
public:
    enum CallerType{
        /*
         * The callback function will NOT be excuted when it`s argument is 0.
         * */
        Destroy = 0,
        /*
         * The callback function will be excuted no matter what the argument is.
         * */
        Normal = 1
    };
    /*
     * Give param a void ** when t == CallerType::Destroy.
     * */
    MScopedCaller(MCallback fun,void *param,CallerType t = MScopedCaller::Destroy);
    virtual ~MScopedCaller();

private:
    Q_DISABLE_COPY(MScopedCaller)
    MCallback fun;
    void *param;
    CallerType type;
};

/***************************************************** MKit:MPost ***/

class M_CLASS_LIB_DECL MHttp : public QObject
{
    Q_OBJECT
public:
    explicit MHttp(QObject *parent = 0);
    ~MHttp();
    void setTimeout(int interval = 1000 * 10);
    bool isFinished() const;

    bool post(const QString & url,const QByteArray & data);
    bool post(const QNetworkRequest & r,const QByteArray & data);

    bool get(const QNetworkRequest & r);

    QNetworkRequest lastRequest() const;
    //Only for POST
    QByteArray lastPostedData() const;

public slots:
    void abort();

signals:
    void finished(const QUrl & url,
                  const QList<QPair<QByteArray,QByteArray> > &headers,
                  const QByteArray & data,
                  bool timeout,
                  QNetworkReply::NetworkError error);

protected slots:
    void finished_slot(QNetworkReply *);

protected:
    void timerEvent(QTimerEvent *);

    void killTimer();
    void startTimer(int interval);

    QByteArray data;
    QNetworkRequest req;

    bool timeout;
    int timerid;
    int interval;
    QNetworkReply *reply;
    QNetworkAccessManager manager;

private:
    Q_DISABLE_COPY(MHttp)
};
/***************************************************** MKit:MHttpHandler ***/

class M_CLASS_LIB_DECL MHttpRequestData{
public:
    MHttpRequestData();
    MHttpRequestData(const MHttpRequestData &other);
    MHttpRequestData &operator =(const MHttpRequestData &other);

    virtual ~MHttpRequestData();

    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;

    QJsonObject toJsonObject() const;

    QNetworkRequest req;
    QByteArray data;
    QString uuid;
    QString createTime;
    int timeout;
    QNetworkAccessManager::Operation operation;

    friend class MHttpHandler;

protected:
    QTimer *timer;
};

typedef QList<QPair<QByteArray,QByteArray> > ListPairByteArray;

typedef struct MHttpDataPackage{
    MHttpRequestData req;
    ListPairByteArray replyHeaders;
    QByteArray inData;
    QNetworkReply::NetworkError error;

    QJsonObject toJsonObject() const;
    QString toJsonStr(QJsonDocument::JsonFormat format = QJsonDocument::Indented) const;
}MHttpDataPackage;

/*
 * Designed for situation such as:
 *   you have multi connections at sametime,
 *   you must know which request match the current reply,
 *   you need a timer to auto close for each different connection.
 *
 * if you want download a file or something big data,
 * just make a short request at once so that the finished(...) slot can come soon.
 *
 * if you download a big data at once,and the data has not been read by user,
 * the data is just cached in memery.
 * */
class M_CLASS_LIB_DECL MHttpHandler : public QObject
{
    Q_OBJECT
public:
    explicit MHttpHandler(QNetworkAccessManager *m = new QNetworkAccessManager,QObject *parent = 0);
    virtual ~MHttpHandler();

    /*
     * There is no timer if timeout_ms is 0.
     * */
    virtual bool post(const QNetworkRequest &req,const QByteArray &data = "",int timeout_ms = 0);

    virtual bool get(const QNetworkRequest &req,int timeout_ms = 0);
    /*
      Designed for this case like:

      Example:
            MHttpHandler *http = new MHttpHandler;
            connect(http,&MHttpHandler::finished, [http](){
                HttpDataPackage res = http->getLastResponse();
                MDG << res.error
                    << res.inData
                    << res.replyHeaders
                    << res.req.toJsonString(QJsonDocument::Indented);
                http->deleteLater();});
     * */
    MHttpDataPackage getLastResponse() const;

signals:
    /*
     * @brief finished
     * @param req          contains the url,header,data which has been sent to server.
     * @param replyHeaders the headers which server sent to me.
     * @param inData       the data from server.
     * @param error
     */
    void finished(const MHttpRequestData &req,
                  const ListPairByteArray &replyHeaders,
                  const QByteArray &inData,
                  QNetworkReply::NetworkError error);

    void finished2(const MHttpDataPackage &response);

    void finished3();

protected slots:
    void finished_slot(QNetworkReply *reply);
    void timeout_slot();

protected:
    bool createReply(const QNetworkRequest &req,
                     const QByteArray &data,
                     int timeout_ms = 0,
                     QNetworkAccessManager::Operation = QNetworkAccessManager::PostOperation);

    QNetworkAccessManager *manager;
    QMap<QNetworkReply *,MHttpRequestData *> map;

    MHttpDataPackage lastResponse;

private:
    Q_DISABLE_COPY(MHttpHandler)
};
/***************************************************** MKit:MQlabel ***/

class M_CLASS_LIB_DECL MRollingLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MRollingLabel(QWidget *parent = 0);
    ~MRollingLabel();
    void setText(const QString& str);
    QString text();
    // 0<,,,<1
    void setBackGroundColor(double X1 = 0.0,
                            double Y1 = 0.0,
                            double X2 = 1.0,
                            double Y2 = 0.0,
                            const QMap<double,QColor> & map = QMap<double,QColor>());
    void backGroundColor(double & X1,
                         double & Y1,
                         double & X2,
                         double & Y2,
                         QMap<double,QColor> & map);
    void setTextColor(const QColor& color);
    QColor textColor();

    void setTextFont(const QFont& font);
    QFont textFont();

    int textWidth();
    int textHeight();

    void setSpeedInterval(int interval);
    int speedInterval();

signals:
    void mouseReleased();

protected:
    //void speed_slot();
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *);

    QString text_str;
    QTimer timer;
    QLinearGradient linear;
    QColor color_pen;
    QFont font_text;
    int interval_speed;
    int width_text;
    int height_text;
    //0 < x1,y1,x2,y2 < 1
    double x1,y1,x2,y2;
    QMap<double,QColor> map_color;
    //
    int ii;

private:
    Q_DISABLE_COPY(MRollingLabel)
};
/***************************************************** MKit:MSingleApp ***/

class M_CLASS_LIB_DECL MSingleApp
{
public:
    MSingleApp();
    virtual ~MSingleApp();

    bool isSingle(const QString & singleKey);

protected:
    QLocalServer* localServer;
    QLocalSocket* localSocket;

private:
    Q_DISABLE_COPY(MSingleApp)
};
/***************************************************** MKit:MTimeLabel ***/

/**
 * Do NOT call this NOT in main thread !
 */
#define M_GET_OBJECT_MTIMELABEL MTimeLabel::getObj()
class M_CLASS_LIB_DECL MTimeLabel : public QObject
{
    Q_OBJECT
public:
    static MTimeLabel *getObj();
    void add(QLabel *l);
    void remove(QLabel *l);
    /**
     * This class do not auto remove NULL pointer,
     * call this function for manual remove.
     */
    void removeNullPointer();
    QList<QPointer<QLabel> > & list();

protected:
    virtual void timerEvent(QTimerEvent *);

private:
    Q_DISABLE_COPY(MTimeLabel)
    explicit MTimeLabel(QObject *parent = 0);

    static MTimeLabel* obj;
    int timer_2_flush_id;
    QList<QPointer<QLabel> > list_label;
};
/***************************************************** MKit:MTimeQLabel ***/

class MTimeQLabel : public QLabel
{
    Q_OBJECT
public:
    MTimeQLabel(QWidget *p = NULL);
    ~MTimeQLabel();

protected slots:
    void timeout_slot();

protected:
    QTimer timer;

private:
    Q_DISABLE_COPY(MTimeQLabel)
};
/***************************************************** MKit:MUi ***/

#define M_TIME_DEFAULT_WINDOW_SECOND_MUI           99

class M_CLASS_LIB_DECL MUi : public QObject
{
    Q_OBJECT
public:
    enum ExitType{
        TimeOut = 0,
        Ok,
        Fail,
        Back,
        BackToBeginning,
        Cancel,
        UnknowType
    };
    explicit MUi(const QString& name_ui_file,
                 const QString& name_time_label = "",
                 QWidget *parent_ui = 0,
                 QObject *parent_this = 0);
    ~MUi();
    void enableCountingDownTimer(bool,bool resetWindowTime = false);
    bool isCountingDownTimerRunning() const;

public slots:
    void show();
    void hide();
    void raise();
    void showFullScreen();

protected:
    virtual void timerEvent(QTimerEvent*);
    virtual void resetCountingDownTime(int time = M_TIME_DEFAULT_WINDOW_SECOND_MUI);
    //Call this in child object
    void connectSignalAndSlot(QObject* obj);

    int timer_id_close_window;
    int time_left_current_window;
    QString name_label_time;

    QWidget *ui;
    QEventLoop loop;

    int interval_count_down_default_ms;
    int code_exit_default;

private:
    Q_DISABLE_COPY(MUi)
};

/***************************************************** MKit:MWaitForm ***/

namespace MKit_P{
class waitLabel : public QLabel
{
    Q_OBJECT
public:
    explicit waitLabel(QWidget *parent = 0):QLabel(parent)
    {
        connect(&this->QTimer1, SIGNAL(timeout()), this, SLOT(update()));
        this->QTimer1.start(100 / 10);
    }
protected:
    void paintEvent(QPaintEvent*e)
    {
        (void)e;
        uint banjin = M_MINIMUM(width(), height());
        banjin = banjin / 2;
        uint dotBanjin = banjin / 5;
        static uint rotate = 0;
        if(rotate >= 360){
            rotate %= 360;
        }
        rotate += 1;

        QColor dot(0, 0, 0);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.save();
        painter.rotate(rotate);
        painter.translate(0,banjin - 1 * dotBanjin);
        painter.setPen(Qt::NoPen);
        painter.setBrush(dot);
        painter.drawEllipse(QPoint(0,0),dotBanjin,dotBanjin);
        painter.restore();
    }
private:
    Q_DISABLE_COPY(waitLabel)

    QTimer QTimer1;
};
}
class M_CLASS_LIB_DECL MWaitForm : public QWidget
{
    Q_OBJECT
public:
    explicit MWaitForm(QWidget *parent = 0);
    ~MWaitForm();

    //block forever when time = 0
    Q_INVOKABLE void showExec(uint time = 0);

public slots:
    void exit();

protected slots:
    void timeout_slot();

protected:
    virtual void resizeEvent(QResizeEvent *e);

    QTimer timer;
    QEventLoop loop;
    QHBoxLayout *lyout;
    MKit_P::waitLabel *label;

private:
    Q_DISABLE_COPY(MWaitForm)
};
/***************************************************** MKit:MLoginForm ***/

#define M_PLACE_HOLDER_ACCOUNT "Account"
#define M_PLACE_HOLDER_PASSWD  "Passwd"
class M_CLASS_LIB_DECL MLoginDialog : public QWidget
{
    Q_OBJECT
public:
    class UserInfo{
    public:
        UserInfo(){}
        UserInfo(const UserInfo &o){
            account = o.account;
            passwd = o.passwd;
        }
        UserInfo &operator =(const UserInfo &o){
            if(this != &o){
                account = o.account;
                passwd = o.passwd;
            }
            return *this;
        }
        //the order of the returned string depends on QJsonDocument
        QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const{
            return MTL::get_str_from_QJsonObject(toJsonObject(),f);
        }

        QJsonObject toJsonObject() const{
            QJsonObject json;
            json.insert(M_CAST_STRING(account),account);
            json.insert(M_CAST_STRING(passwd),passwd);
            return json;
        }

        QString account;
        QString passwd;
    };
    enum ExitType{
        Ok,
        Cancel,
        Timeout
    };
    explicit MLoginDialog(QWidget *parent = 0);
    ~MLoginDialog();

    ExitType showExec(UserInfo &info,                 //will be set whatever the return-value is when this func return
                      int time = 120,                 // >0 enable timer, =0 no timer
                      const QString & acount_str = "",
                      const QString & passwd_str = "",
                      int acount_length = 11,
                      int passwd_length = 6,
                      const QString & acount_str_placeHolder = M_PLACE_HOLDER_ACCOUNT,
                      const QString & passwd_str_placeHolder = M_PLACE_HOLDER_PASSWD,
                      bool passwd_str_echoMode = true);

public slots:
    void append(const QString &);
    void cancel();
    void confirm();

protected slots:
    void button_cancel_slot();
    void button_ok_slot();
    void timeout_slot();
    void textChanged_slot(const QString &);

protected:
    virtual void resizeEvent(QResizeEvent *e);

    QEventLoop loop;
    QTimer timer;
    int time_left;
    int length_account;
    int length_passwd;
    QString text_returnButton;
    //
    MVirtualKeyboard *board;
    QGridLayout *layout_grid;
    QVBoxLayout *layout_vbox;
    QLineEdit *lineedit_account;
    QLineEdit *lineedit_passwd;
    QToolButton *button_cancel;
    QToolButton *button_ok;

private:
    Q_DISABLE_COPY(MLoginDialog)
};
/***************************************************** MKit:MConfirmForm ***/

class M_CLASS_LIB_DECL MConfirmDialog : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int width_default READ defaultWidth)
    Q_PROPERTY(int height_default READ defaultHeight)

public:
    explicit MConfirmDialog(QWidget *parent = 0);
    ~MConfirmDialog();

    //block forever when time = 0
    Q_INVOKABLE bool showExec(const QString& message,
                              int time = 10,
                              int w = 0,
                              int h = 0,
                              bool animation = true);

    int defaultWidth();
    int defaultHeight();

protected:
    void keyPressEvent(QKeyEvent *e);
    void changeEvent(QEvent *);
    virtual void resizeEvent(QResizeEvent *e);

protected slots:
    void flushThebuttonText();
    void button_cancel_slot();
    void button_ok_slot();

protected:
    QTimer timer;
    int timeLeft;
    QEventLoop loop;
    QString buttonText;
    int width_default;
    int height_default;

    QPropertyAnimation* animation;
    //
    QVBoxLayout *layout_v;
    QHBoxLayout *layout_h;
    QToolButton *button_ok;
    QToolButton *button_cancel;
    QLabel *label_time;
    QTextBrowser *text;
    QSpacerItem *spacer;

private:
    Q_DISABLE_COPY(MConfirmDialog)
};

/***************************************************** MKit:MPromptQWidget ***/

/* Global message dialog.
 *
 * Example :
 *
 *  MPROMPT_INIT;               //in main thread.
 *
 *  MPROMPT_MESSAGE("error...") //in other thread.
 *
 * */

#define MPROMPT_INIT MPromptQWidget::getObj()

#define MPROMPT_MESSAGE(message) do{                    \
    QMetaObject::invokeMethod(MPROMPT_INIT,             \
    "postMessage",                                      \
    Qt::QueuedConnection,                               \
    Q_ARG(QString,message));                            \
    }while(0)

class MPromptQWidget : public QWidget
{
    Q_OBJECT
public:
    static MPromptQWidget *getObj();

public slots:
    void postMessage(const QString &m);

private slots:
    void timeout_slot();

private:
    virtual void closeEvent(QCloseEvent *e);

    explicit MPromptQWidget(QWidget *parent = 0);
    ~MPromptQWidget();

    static MPromptQWidget *obj;

    QTextBrowser *textBrowser;

    QLabel *label;
    QSpacerItem *spacerItem;
    QToolButton *button;
    QVBoxLayout *vb;

    QHBoxLayout *hb;

    QTimer timer;
    int aliveTime;
};

/***************************************************** MKit:MSerialPort ***/

#ifdef Q_OS_LINUX
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#endif //Q_OS_LINUX

#define M_LENGTH_READBUFFER_MSERIALPORT 4096

class M_CLASS_LIB_DECL MSerialPort : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("Author", "Tengfei Du")
public:
    enum BaudRate{
        Baud0      = 0,
        Baud50     = 50,
        Baud75     = 75,
        Baud110    = 110,
        Baud134    = 134,
        Baud150    = 150,
        Baud200    = 200,
        Baud300    = 300,
        Baud600    = 600,
        Baud1200   = 1200,
        Baud1800   = 1800,
        Baud2400   = 2400,
        Baud4800   = 4800,
        Baud7200   = 7200,
        Baud9600   = 9600,
        Baud14400  = 14400,
        Baud19200  = 19200,
        Baud28800  = 28800,
        Baud38400  = 38400,
        Baud57600  = 57600,
        Baud76800  = 76800,
        Baud115200 = 115200,
        Baud128000 = 128000,
        Baud230400 = 230400,
        Baud460800 = 460800,
        Baud576000 = 576000,
        Baud921600 = 921600
    };
    enum DataBits{
        Data5=5,
        Data6=6,
        Data7=7,
        Data8=8
    };
    enum Parity{
        NoParity   = 0,
        EvenParity = 1,
        OddParity  = 2,
        SpaceParity = 3,//
        MarkParity  = 4  //
    };
    enum StopBits{
        OneOrOneDotFiveStop = 0,//1,1.5 stop bit
        TwoStop = 1             //2 stop bit
    };
    explicit MSerialPort(QObject *parent = 0);
    virtual ~MSerialPort();

    //first step
    //return false, if the file is already opened
    bool setPortName(const QString &port);

    //second step
    //open file and connect signal
    bool open(bool block = false);

    //third step
    bool setAttr(int baudrate = MSerialPort::Baud9600,
                 int databits = MSerialPort::Data8,
                 Parity Parity = MSerialPort::NoParity,
                 StopBits stop = MSerialPort::OneOrOneDotFiveStop,
                 //follow control:     None,RTS/CTS,XON/XOFF
                 //None:    softwareHandshake=false,hardwareHandshake=false
                 //RTS/CTS: softwareHandshake=false,hardwareHandshake=true
                 //XON/XOFF:softwareHandshake=true,hardwareHandshake=false
                 bool softwareHandshake = false,
                 bool hardwareHandshake = false);
    int close();
    /*****************************************/

    int read(uchar *des,int len = M_LENGTH_READBUFFER_MSERIALPORT);

    int write(uchar *data,int len);
    /*****************************************/

    //return >= 0 for data read length
    //return -1 for error, extern int errno was set
    static int readTimeout(int fd,
                           uchar *buff,
                           int length,
                           int timeUs = 1000 * 1000 * 3);

    //return > 0 for data read length
    //return < 0 on error, extern int errno was set
    static int readTillEnd(int fd,
                           uchar *buff,
                           int buffLength,
                           uchar *endFlag,
                           int endFlagLength);
    /*****************************************/
    bool isOpen() const;

    QString portName() const;
    int handle() const;

    QString errorString() const;
    int error() const;
    /*****************************************/
    //clear buffer
    int flush();
    //push data
    int syncfs();

signals:
    //fourth step
    void readReady(int fd);

protected:
    void setNotifier();

protected:
    int fd;
    QString port;
    QSocketNotifier *notifier;
    QString errorStr;

private:
    Q_DISABLE_COPY(MSerialPort)
};
/***************************************************** MKit:MBubbleForm ***/

#ifdef Q_OS_WIN32
class M_CLASS_LIB_DECL MBubbleForm : public QDialog
{
    Q_OBJECT
public:
    MBubbleForm();
    Q_INVOKABLE void showDlg(const QString &strTitle , const QString &strText);

private slots:
    void onMove();
    void onStay();
    void onClose();

private:
    Q_DISABLE_COPY(MBubbleForm)

    QTimer* m_pShowTimer;
    QTimer* m_pStayTimer;
    QTimer* m_pCloseTimer;
    QPoint  m_point;
    float   m_dTransparent;
    int     m_nDesktopHeight;

    QLabel  m_textLabel;
    QLabel  m_titleLabel;
    QLabel  m_lineLabel;
    QPushButton  m_closeBtn;
};
#endif //Q_OS_WIN32
/***************************************************** MKit:MClock ***/

class M_CLASS_LIB_DECL MClock : public QWidget
{
    Q_OBJECT
public:
    MClock(QWidget *parent = 0);
    virtual QSize sizeHint() const ;

public slots:
    void setHourHandColor(const QColor &color);
    void setMinuteHandColor(const QColor &color);
    void setSecondHandColor(const QColor &color);

protected:
    virtual void paintEvent(QPaintEvent *event) ;
    virtual void resizeEvent(QResizeEvent *event) ;

    QColor color_background;
    QColor color_hour;
    QColor color_minute;
    QColor color_second;

private:
    Q_DISABLE_COPY(MClock)

};
/***************************************************** MKit:MListPictureView ***/

class M_CLASS_LIB_DECL MListPictureView : public QWidget
{
    Q_OBJECT
public:
    MListPictureView(QWidget *parent = 0);
    ~MListPictureView();
    const QList<QPixmap> & pictures() const;
    int count() const;
    int currentIndex() const;
    bool isRunning() const;

public slots:
    void add(const QPixmap &);
    void clear();
    void setCurrentIndex(int index);
    void start(int ms = 1000 * 5);
    void stop();
    void next();
    void preNext();

signals:
    void clicked(int index);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    bool isLeftButton(const QPoint &p);
    bool isRightButton(const QPoint &p);

    QList<QPixmap> list_picture;
    int index_current;
    int interval_default;
    QTimer timer;
    bool hover_left;
    bool hover_right;
    qreal zhijin;

private:
    Q_DISABLE_COPY(MListPictureView)
};
/***************************************************** MKit:MAbstractSubject ***/

class MAbstractObserver;
class M_CLASS_LIB_DECL MAbstractSubject
{
public:
    MAbstractSubject();

    virtual ~MAbstractSubject();

    /**
     * @brief addClient
     * @param o
     * This function do NOT responsible for the pointer
     */
    virtual void addObserver(MAbstractObserver *o);

    virtual void removeObserver(MAbstractObserver *o);

    /**
     * @brief notify
     * Call Observer·s function to make them know something has changed
     * Use the mutex for better
     */
    virtual void notify() = 0;

protected :
    //protection for the list
    QMutex mutex_list_observer;
    /**
     * @brief list_observer
     * Read me in child and call the specific function to send data
     */
    QList<MAbstractObserver* > list_observer;
};
/***************************************************** MKit:MAbstractObserver ***/

class M_CLASS_LIB_DECL MAbstractObserver
{
public:
    MAbstractObserver();

    virtual ~MAbstractObserver();
    /**
     * @brief update
     * @param data
     * do NOT delete the pointer in child
     */
    virtual void update(const void *data) = 0;
};
/***************************************************** MKit:MHeader ***/

class M_CLASS_LIB_DECL MHeaderItem{
public:
    MHeaderItem(int index = -1,const QString &name = "Unknown");
    MHeaderItem(const MHeaderItem &other);
    virtual ~MHeaderItem();

    MHeaderItem &operator =(const MHeaderItem &other);
    bool operator ==(const MHeaderItem &it) const;

    bool isValid() const;
    QString toString() const;
    //the order of the retruned string depends on QJsonDocument
    QString toJsonString(QJsonDocument::JsonFormat f = QJsonDocument::Compact) const;
    QJsonObject toJsonObject() const;

    //must from 0 and be unique
    mutable int index;
    //different item can have same name
    mutable QString name;
};
/*****************************************
 *
 * T may be an enum
 *
 * like: enum UserInfo{name,id,passwd,money...}
 *
 * used to give a name to column or row item
 *
 * **************************************/
template<class T>
class MHeader{
public:
    MHeader(){}
    MHeader(const MHeader &other){map = other.map;}
    virtual ~MHeader(){}
    MHeader &operator =(const MHeader &other){
        if(this != &other){
            map = other.map;
        }
        return *this;
    }

    MHeaderItem getItemByType(T type) const{ return map.value(type);}

    MHeaderItem getItemByIndex(int index) const{
        QList<MHeaderItem> list = map.values();
        for(QList<MHeaderItem>::ConstIterator it = list.constBegin();
            it != list.constEnd();
            it++){
            if(it->index == index){
                return *it;
            }
        }
        return MHeaderItem();
    }
    QMap<T , MHeaderItem> getMap() const     { return map; }
    int size() const                         { return map.size(); }
    void insert(T type,const MHeaderItem &it){ map.insert(type,it); }
    void clear()                             { map.clear(); }

protected:
    mutable QMap<T , MHeaderItem> map;
};
/***************************************************** MKit:MXmlTreeWidget ***/

class M_CLASS_LIB_DECL MXmlTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit MXmlTreeWidget(QWidget *parent = 0);

    bool read(const QByteArray &data);
    /**
     * @brief write
     * @param device must be opened,
     *               use QBuffer if u want to save data to RAM
     * @return
     * WARNING:
     *      this function has a BUG in Qt5.4.2!
     *      use toByteArray() instead.
     */
    bool write(QIODevice *device);

    //
    static QString get_str_json_from_QDomNamedNodeMap(const QDomNamedNodeMap &map,
                                                      QJsonDocument::JsonFormat format = QJsonDocument::Compact);
    //
    static QByteArray get_str_formart_from_XmlString(const QByteArray &data);
    //
    static QByteArray get_str_from_QDomElement(const QDomElement &e);
    /*
     * NOTE:
     *  the returned QDomElement is a reference,
     *  change the element will change the arg1.
     *
     *  Use QDomNode::cloneNode(bool deep = true) const,
     *  if you want a full copy.
     * */
    static QDomElement get_element_by_id(const QDomElement &e,const QString &id);
    /*
     * NOTE:
     *  the returned QDomElement is a reference,
     *  but change the element will NOT change the argument data
     * */
    static QDomElement get_element_by_id(const QByteArray &data,const QString &id);

    Q_INVOKABLE static QString get_attribute_by_id(const QByteArray &data,
                                                   const QString &id,
                                                   const QString &attr = QString("disabled"));
    /*
     * on success, return new data which has been changed,
     * otherwise return the old data.
     * */
    static QByteArray set_attribute_by_id(const QByteArray &data,
                                          const QString &id,
                                          const QString &attrName = "disabled",
                                          const QString &attrValue = "false",
                                          int indent = 2);
    Q_INVOKABLE static QString get_value_by_id(const QByteArray &data,const QString &id);
    /*
     * returns a QByteArray containing the data encoded as UTF-8.
     * */
    QByteArray toByteArray(int indent = 2) const;

protected:
    virtual bool edit(const QModelIndex & index, EditTrigger trigger, QEvent * event);

private slots:
    void updateDomElement_slot(QTreeWidgetItem *item, int column);

private:
    void parse_element_by_recursion(const QDomElement &element,    QTreeWidgetItem *parentItem = 0);
    QTreeWidgetItem *createItem(const QDomElement &element,   QTreeWidgetItem *parentItem = 0);

    QDomDocument domDocument;
    QHash<QTreeWidgetItem *, QDomElement> domElementForItem;
    QIcon folderIcon;

    Q_DISABLE_COPY(MXmlTreeWidget)
};

/***************************************************** MKit:MTiXmlDocument ***/

#ifdef M_ENABLE_TINYXML_262

#include "tinyxml.h"

/**
 * EXAMPLE:
 *
 * Read from file:
 *
 *  MTiXmlDocument xml("hello.xml");
 *  xml.LoadFile(TIXML_ENCODING_UTF8);
 *  auto root = xml.RootElement();
 *  //...
 *  QByteArray data = xml.toByteArray();
 *
 * Read from memory:
 *
 *  MTiXmlDocument xml;
 *  xml.parse(".........", 0, TIXML_ENCODING_UTF8)
 *  auto root = xml.RootElement();
 *  //...
 */
class M_CLASS_LIB_DECL MTiXmlDocument : public TiXmlDocument
{
public:
    MTiXmlDocument();

    MTiXmlDocument( const char * documentName );

    MTiXmlDocument( const MTiXmlDocument& copy );
    MTiXmlDocument& operator =( const MTiXmlDocument& copy );

    virtual ~MTiXmlDocument();

    /*
     * return NULL if not exist,
     *
     * Change the return TiXmlElement will also change the arg1.
     * use TiXmlElement.Clone() to get a full copy.
     *
     * */
    static TiXmlElement *get_element_by_id(TiXmlElement *e,const char *id);

    static bool set_attribute_by_id(TiXmlElement *e,
                                    const char *id,
                                    const char *attrName = "disabled",
                                    const char *attrValue = "false");

    static QString get_attribute_by_id(TiXmlElement *e,const char *id,const char *attrName = "disabled");

    static QList<QPair<QString,QString> > get_attributes_from_TiXmlElement(TiXmlElement *e);

    QByteArray toByteArray() const;
};

#endif //M_ENABLE_TINYXML_262

/***************************************************** MKit:MPaper ***/

template<class T>
class MPaper
{
public:
    MPaper(){
        clear();
    }
    MPaper(const T &value){
        write(value);
    }
    MPaper(const MPaper<T> &other){
        data = other.data;
        empty = other.empty;
    }
    virtual ~MPaper(){}

    MPaper &operator =(const MPaper<T> &other){
        if(this != &other){
            data = other.data;
            empty = other.empty;
        }
        return *this;
    }

    MPaper &operator =(const T &t){
        write(t);
        return *this;
    }

    void write(const T &t){
        data = t;
        empty = false;
    }
    T read(const T &t = T()) const {return isEmpty() ? t : data;}
    T take(const T &t = T()){
        if(isEmpty())
            return t;
        T tt = data;
        clear();
        return tt;
    }
    void clear(){empty = true;}

    bool isEmpty() const {return empty;}

protected:
    T data;
    bool empty;
};

/***************************************************** MKit:MObject ***/

class MObject{
public:
    MObject();
    virtual ~MObject();

    //{00000000-0000-0000-0000-000000000000}
    QString id() const;

protected:
    /*
     * uuid of this object,
     * the id can only be set when object was created.
     */
    QString _id;

private:
    Q_DISABLE_COPY(MObject)
};

/*********************************TCP server using thread pool*******************************************/


/******************************************* MKit:MTcpConnectionHandler ***/

/*
 * Subclass and add your business.
 */
class MTcpConnectionHandler : public QTcpSocket
{
    Q_OBJECT
public:
    /** Must provide in subclass ! **/
    MTcpConnectionHandler();
    virtual ~MTcpConnectionHandler();

    /**
     * Must provide in subclass.
     *
     * Designed for MTcpThreadHandler and it will auto delete tcp when disconnected.
     *
     * It`s caller`s responsible to delete the memory.
     */
    virtual MTcpConnectionHandler *createNew();

private:
    Q_DISABLE_COPY(MTcpConnectionHandler)
};
/******************************************* MKit:MTcpThreadHandler ***/
/*
 * Example for the required configuration settings:
 *
 *   MaxConnnectionPerThread=100
 *
 */
class MTcpThreadHandler : public QThread
{
    Q_OBJECT
public:
    MTcpThreadHandler(QSettings* setgs,MTcpConnectionHandler *cnn);
    virtual ~MTcpThreadHandler();

    /** Return true if connections < MaxConnnectionPerThread **/
    bool isAvailable() const;

    /** Return true if no connections. **/
    bool isEmpty() const;

    int available() const;
    int establishedTCPs() const;

    /** Acquire one source. **/
    bool tryAcquire();

public slots:
    void handleConnection(qintptr socketDescriptor);

protected slots:
    void clearEmptyPointer();
    void destroyed_slot(QObject *o);

protected:
    virtual void run();

    QSettings* settings;

    /** User business **/
    MTcpConnectionHandler *cnn;

    mutable QMutex* mutex;
    QSemaphore sem;
    QList<QPointer<MTcpConnectionHandler > > list_connection;

private:
    Q_DISABLE_COPY(MTcpThreadHandler)
};

/******************************************* MKit:MTcpThreadPool ***/
/*
 * Example for the required configuration settings:
 *
 *   cleanupInterval=60000
 *   maxThreads=100
 *   minThreads=1
 *
 */
class MTcpThreadPool : public QObject
{
    Q_OBJECT
public:
    MTcpThreadPool(QSettings *settings,MTcpConnectionHandler *cnn);
    virtual ~MTcpThreadPool();

    /**
     * Get a free thread,or 0 if no avilable.
     * The thread source is already acquired.
     * */
    MTcpThreadHandler *getAvialableThreadHandler();

protected slots:
    void cleanup();

protected:
    QSettings *settings;
    MTcpConnectionHandler *cnn;

    QList<MTcpThreadHandler *> list_thread;
    QTimer timer_clean;

private:
    Q_DISABLE_COPY(MTcpThreadPool)
};

/******************************************* MKit:MTcpListener ***/

/**
 * How To Use :
 *
 *   QSettings *set = new QSettings(CONFIG_FILE,QSettings::IniFormat);
 *   set->beginGroup("listener");
 *   MTcpConnectionHandler *handler = new MTcpConnectionHandler;
 *   MTcpListener *listener = new MTcpListener(set,handler);
 *
 * .ini :
 *
 *   [listener]
 *   MaxConnnectionPerThread=2
 *   cleanupInterval=60000
 *   maxThreads=3
 *   ;minThreads=1
 *   host=127.0.0.1
 *   port=10000
 *
 */

/*
 * Example for the required configuration settings:
 *
 *   host=127.0.0.1
 *   port=10000
 *
 */
class  MTcpListener : public QTcpServer
{
    Q_OBJECT
public:
    /** Already called listen() in this constructor. **/
    MTcpListener(QSettings* settings, MTcpConnectionHandler* requestHandler, QObject* parent = NULL);

    /** Destructor */
    virtual ~MTcpListener();

    /**
      Restart listeing after close().
    */
    void listen();

    /**
     Closes the listener, waits until all pending requests are processed,
     then closes the connection pool.
    */
    void close();

protected:
    /** Serves new incoming connection requests */
    void incomingConnection(qintptr socketDescriptor);

private:
    Q_DISABLE_COPY(MTcpListener)

    /** Configuration settings for the TCP server */
    QSettings* settings;

    /** Point to the reuqest handler which processes all TCP requests */
    MTcpConnectionHandler* cnn;

    /** Pool of connection handlers */
    MTcpThreadPool* pool;
};

/*********************************TCP server using thread pool 2*******************************************/

/******************************************* MKit:MTcpConnectionHandler2 ***/

/*
 * Subclass and add your business.
 */
class MTcpConnectionHandler2 : public QTcpSocket,public MObject
{
    Q_OBJECT
public:
    /** Must provide in subclass ! **/
    MTcpConnectionHandler2();
    virtual ~MTcpConnectionHandler2();

private:
    Q_DISABLE_COPY(MTcpConnectionHandler2)
};

/******************************************* MKit:MTcpThreadHandler2 ***/
/*
 * Example for the required configuration settings:
 *
 *   MaxConnnectionPerThread=100
 *
 */
class MTcpThreadHandler2 : public QThread,public MObject
{
    Q_OBJECT
public:
    /**
     * This constructor already called moveToThread(this),
     *
     * Which means all it`s slots will be executed in my own thread.
     */
    MTcpThreadHandler2(QSettings* setgs);
    virtual ~MTcpThreadHandler2();

    /** Return true if connections < MaxConnnectionPerThread **/
    bool isAvailable() const;

    /** Return true if no connections. **/
    bool isEmpty() const;

    int available() const;
    int establishedTCPs() const;

    /** Acquire one source. **/
    bool tryAcquire();

public slots:
    /**
     * Auto create and delete MTcpConnectionHandler2 when tcp disconnected.
     * */
    void handleConnection(qintptr socketDescriptor);

protected slots:
    void clearEmptyPointer();
    void destroyed_slot(QObject *o);

protected:
    /**
     *  User business,
     *
     *  This function is auto called by MTcpThreadHandler2.
     * */
    virtual MTcpConnectionHandler2 *createTcpHandler();
    /**
     * Already called exec() in this function,
     *
     * When override,remember to call me in your funtion.
     * */
    virtual void run();

    QSettings* settings;

    mutable QMutex* mutex;
    QSemaphore sem;
    QList<QPointer<MTcpConnectionHandler2 > > list_connection;

private:
    Q_DISABLE_COPY(MTcpThreadHandler2)
};
/******************************************* MKit:MTcpThreadPool2 ***/
/*
 * Example for the required configuration settings:
 *
 *   cleanupInterval=60000
 *   maxThreads=100
 *   minThreads=1
 *
 */
class MTcpThreadPool2 : public QObject
{
    Q_OBJECT
public:
    MTcpThreadPool2(QSettings *settings);
    virtual ~MTcpThreadPool2();

    /**
     * Get a free thread,or 0 if no avilable.
     * The thread source is already acquired.
     */
    MTcpThreadHandler2 *getAvialableThreadHandler();

public slots:
    /**
     * Clear all thread(waits all thread finished) no matter empty or not.
     */
    void clear();

protected slots:
    /**
     * Just clear a empty thread for each time.
     */
    void cleanup();

protected:
    /** This function is auto called by MTcpThreadPool2. **/
    virtual MTcpThreadHandler2 *createThreadHandler();

    QSettings *settings;

    QList<MTcpThreadHandler2 *> list_thread;
    /**
     * For clear empty thread.
     */
    QTimer timer_clean;

private:
    Q_DISABLE_COPY(MTcpThreadPool2)
};
/******************************************* MKit:MTcpListener2 ***/

/**
   How To Use :

     QSettings *set = new QSettings(CONFIG_FILE,QSettings::IniFormat);
     set->beginGroup("listener");
     MTcpThreadPool2 *p = new MTcpThreadPool2(set);
     MTcpListener2 *listener = new MTcpListener2(set,p);

   .ini :

     [listener]
     MaxConnnectionPerThread=2
     cleanupInterval=60000
     maxThreads=3
     ;minThreads=1
     host=127.0.0.1
     port=10000

 */

/*
 * Example for the required configuration settings:
 *
 *   host=127.0.0.1
 *   port=10000
 *
 */
class  MTcpListener2 : public QTcpServer
{
    Q_OBJECT
public:
    /**
     * Already called listen() in this constructor.
     *
     * The ownership of pool is transferred to this MTcpListener2.
     * */
    MTcpListener2(QSettings* settings, MTcpThreadPool2* pool, QObject* parent = NULL);

    /** Destructor */
    virtual ~MTcpListener2();

    /**
      Restart listeing after close().
    */
    void listen();

    /**
     Closes the listener, waits until all pending requests are processed,
     then clear the connection pool.
    */
    void close();

protected:
    /** Serves new incoming connection requests */
    void incomingConnection(qintptr socketDescriptor);

    /** Configuration settings for the TCP server */
    QSettings* settings;

    /** Pool of connection handlers */
    MTcpThreadPool2* pool;

private:
    Q_DISABLE_COPY(MTcpListener2)
};

/*********************************TCP server using thread pool 3*******************************************/

/******************************************* MKit:MTcpFactory ***/

class MTcpFactory
{
public:
    MTcpFactory();
    virtual ~MTcpFactory();

    /** Must provide in subclass ! **/
    virtual QTcpSocket *creatSocket();

private:
    Q_DISABLE_COPY(MTcpFactory)
};

/******************************************* MKit:MTcpThreadHandler3 ***/
/*
 * Example for the required configuration settings:
 *
 *   MaxConnnectionPerThread=100
 *
 */
class MTcpThreadHandler3 : public QThread,public MObject
{
    Q_OBJECT
public:
    /**
     * This constructor already called moveToThread(this),
     *
     * Which means all it`s slots will be executed in my own thread.
     */
    MTcpThreadHandler3(QSettings* setgs, MTcpFactory *MTcpFactory_);
    virtual ~MTcpThreadHandler3();

    /** Return true if connections < MaxConnnectionPerThread **/
    bool isAvailable() const;

    /** Return true if no connections. **/
    bool isEmpty() const;

    int available() const;
    int establishedTCPs() const;

    /** Acquire one source. **/
    bool tryAcquire();

public slots:
    /**
     * Auto create and delete MTcpConnectionHandler2 when tcp disconnected.
     */
    void handleConnection(qintptr socketDescriptor);

protected slots:
    void clearEmptyPointer();
    void destroyed_slot(QObject *o);

protected:
    /**
     * Already called exec() in this function,
     *
     * When override,remember to call me in your funtion.
     */
    virtual void run();

    MTcpFactory *MTcpFactory_;

    QSettings* settings;

    mutable QMutex* mutex;
    QSemaphore sem;
    QList<QPointer<QTcpSocket > > list_connection;

    friend class MTcpListener3;

private:
    Q_DISABLE_COPY(MTcpThreadHandler3)
};
/******************************************* MKit:MTcpThreadPool2 ***/
/*
 * Example for the required configuration settings:
 *
 *   cleanupInterval=60000
 *   maxThreads=100
 *   minThreads=1
 *
 * */
class MTcpThreadPool3 : public QObject
{
    Q_OBJECT
public:
    MTcpThreadPool3(QSettings *settings,MTcpFactory *MTcpFactory_);
    virtual ~MTcpThreadPool3();

    /**
     * Get a free thread,or 0 if no avilable.
     * The thread source is already acquired.
     * */
    MTcpThreadHandler3 *getAvialableThreadHandler();

public slots:
    /**
     * Clear all thread(waits all thread finished) no matter empty or not.
     * */
    void clear();

protected slots:
    /**
     * Just clear a empty thread for each time.
     * */
    void cleanup();

protected:
    MTcpFactory *MTcpFactory_;

    QSettings *settings;

    QList<MTcpThreadHandler3 *> list_thread;
    /**
     * For clear empty thread.
     * */
    QTimer timer_clean;

    friend class MTcpListener3;

private:
    Q_DISABLE_COPY(MTcpThreadPool3)
};
/******************************************* MKit:MTcpListener3 ***/

/**
   How To Use :

     QSettings *set = new QSettings(CONFIG_FILE,QSettings::IniFormat);
     set->beginGroup("listener");
     MTcpFactory *p = new MTcpFactory();
     MTcpListener3 *listener = new MTcpListener3(set,p);

   .ini :

     [listener]
     MaxConnnectionPerThread=2
     cleanupInterval=60000
     maxThreads=3
     ;minThreads=1
     host=127.0.0.1
     port=10000

 * */

/*
 * Example for the required configuration settings:
 *
 *   host=127.0.0.1
 *   port=10000
 *
 */
class  MTcpListener3 : public QTcpServer
{
    Q_OBJECT
public:
    /**
     * Already called listen() in this constructor.
     *
     * The ownership of MTcpFactory_ is NOT transferred to this object.
     * The ownership of settings is NOT transferred to this object.
     */
    MTcpListener3(QSettings* settings, MTcpFactory *MTcpFactory_, QObject* parent = NULL);

    /** Destructor */
    virtual ~MTcpListener3();

    /**
      Restart listeing after close().
    */
    void listen();

    /**
     Closes the listener, waits until all pending requests are processed,
     then clear the connection pool.
    */
    void close();

protected:
    /** Serves new incoming connection requests */
    void incomingConnection(qintptr socketDescriptor);

    MTcpFactory *MTcpFactory_;

    /** Configuration settings for the TCP server */
    QSettings* settings;

    /** Pool of connection handlers */
    MTcpThreadPool3* pool;

private:
    Q_DISABLE_COPY(MTcpListener3)
};

/******************************************************** MKit:MWatchDog ***/
class MWatchDog : public QObject
{
    Q_OBJECT
public:
    explicit MWatchDog(QObject *parent = 0);
    ~MWatchDog();

    /** return > 0 if dog is alive. **/
    qint64 remainingTime() const;
    bool isAlive() const;

public slots:
    /** Call this before start(). **/
    void setTimeLimit(int limitMs = 1000 * 60 * 5);

    void start();
    void stop();

    /**  Equivalent to calling start(). **/
    void feedDog();

signals:
    /** Will be emitted only ONCE for each alive dog. **/
    void hungry();

private:
    Q_DISABLE_COPY(MWatchDog)

    QTimer dog;
    int timeLimitMs;
    qint64 lastFeedTime;
};
/******************************************************** MKit:MDataParer ***/
class MDataParser : public QObject
{
    Q_OBJECT
public:
    explicit MDataParser(QObject *parent = 0);
    ~MDataParser();

    void setHeader(const QByteArray &header = ":");
    void setEnder(const QByteArray &ender = "\r\n");

    void clearBuffer();
    QByteArray buffer() const;

    /** Same as append(). **/
    void operator <<(const QByteArray &value);

public slots:
    void append(const QByteArray &data);

signals:
    /** header and ender are deleted. **/
    void frameDetected(const QByteArray &frame);

private:
    Q_DISABLE_COPY(MDataParser)

    QByteArray header;
    QByteArray ender;
    QByteArray _buffer;
};
/******************************************************** MKit:MStabilizer ***/

class MStabilizer : public QObject
{
    Q_OBJECT
public:
    explicit MStabilizer(QObject *parent = 0);
    ~MStabilizer();

    void setSize(int sz = 5);
    void setRange(ld rg = 500);

    void clear();

public slots:
    void append(ld value);

signals:
    void stabilized(ld value);

private:
    Q_DISABLE_COPY(MStabilizer)

    QList<ld > queue;
    int size;
    ld range;
};
/******************************************************** MKit:MDuplicateFilter ***/
class MDuplicateFilter : public QObject
{
    Q_OBJECT
public:
    enum FilterType{
        Amount = 0,
        Period = 1,
        AmountAndPeriod = 2
    };
    explicit MDuplicateFilter(QObject *parent = 0);
    ~MDuplicateFilter();

    /** The max number of buffered items. **/
    void setSize(int sz = 100);
    /** The number of target items from end. **/
    void setAmount(int amt = 20);
    /** Recent period. **/
    void setPeriod(qint64 prd = 1000 * 30);

    void setType(MDuplicateFilter::FilterType t = Amount);

    void clear();

    /** Same as append(). **/
    void operator <<(const QString &value);

public slots:
    void append(const QString &value);

signals:
    void filtered(QString value,bool notDuplicate);

private:
    Q_DISABLE_COPY(MDuplicateFilter)

    QList< QPair<QString, // data
    qint64                // currentMSecsSinceEpoch()
    > > queue;
    int size;             // max size of queue
    int amount;
    qint64 period;
    FilterType type;
};


/******************************************************** MKit:MXlsxDocument ***/

#ifdef M_ENABLE_QTXLSXWRITER_MASTER

#include "xlsxdocument.h"

typedef struct {QVariant data; QXlsx::Format format;} MXlsxDocumentCell;

typedef QList<MXlsxDocumentCell> MXlsxDocumentRow;

typedef QList<QList<MXlsxDocumentCell > > MXlsxDocumentMatrix;

class MXlsxDocument : public QXlsx::Document
{
    Q_OBJECT
public:
    explicit MXlsxDocument(QObject *parent = 0);
    MXlsxDocument(const QString &xlsxName, QObject *parent=0);
    MXlsxDocument(QIODevice *device, QObject *parent=0);
    ~MXlsxDocument();

    void setMatrix(const MXlsxDocumentMatrix & matrix);
    void clear(const QXlsx::CellRange &range,const QXlsx::Format &format = QXlsx::Format());

private:
    Q_DISABLE_COPY(MXlsxDocument)
};

#endif //M_ENABLE_QTXLSXWRITER_MASTER

/******************************************************** MKit:MMongocBase ***/

#ifdef M_ENABLE_MONGOC1140

#include "mongoc.h"

class MMongocBase : public MError
{
public:
    MMongocBase(bool callInitFunction = true);
    virtual ~MMongocBase();

    static QString bson_to_QString(const bson_t *bson);
    /*
     * A newly allocated bson_t that should be freed with bson_destroy() if successful,otherwise NULL returned.
     **/
    static bson_t *bson_from_QJsonObject(const QJsonObject &json);

    static void bson_destroy_list(QList<bson_t *> &list);
    /*
     * This function will destroy the old object and create a new one.
     * */
    static void bson_remove(bson_t **bs,const QString &key);

    static QStringList bson_keys(const bson_t *bs);
    /*
     * Returns NULL if key not exist,it is a invalid pointer if u destroyed the bs after this call.
     * */
    static const bson_value_t *bson_value(const bson_t *bs,const QString &key);
    /*
     * mongodb://root:123456@localhost:27017/?appname=tf.du
     * */
    virtual void setUri(const QString &uri = "mongodb://localhost:27017/?appname=connect-example");

    virtual bool connect();
    virtual void disConnect();

    virtual bool insert(const QString &dbName,const QString &collectionName,const bson_t *doc);
    virtual bool insertBulk(const QString &dbName,const QString &collectionName,const QList<bson_t *> &bulk);
    virtual bool find(const QString &dbName,
                      const QString &collectionName,
                      const bson_t *filter,
                      const bson_t *opts,  //opts can be NULL.
                      QList<bson_t *> &out //It is caller`s responsible to free bson_t *.
                      );
    virtual bool updateMany(const QString &dbName,
                            const QString &collectionName,
                            const bson_t *where,
                            const bson_t *set,
                            const bson_t *opts = NULL ); //opts can be NULL

    virtual bool update_if_exist_or_insert(const QString &dbName,
                                           const QString &collectionName,
                                           const bson_t *set,  //Auto use $set when mongoc_collection_update_many().
                                           const bson_t *where);
    virtual bool deleteMany(const QString &dbName,
                             const QString &collectionName,
                             const bson_t *where,
                             const bson_t *opts = NULL );    //opts can be NULL

    /*
     * Do NOT delete mongoc_client_t *.
     * */
    virtual mongoc_client_t *getClient() const;
    /*
     * Do NOT delete mongoc_client_pool_t *.
     * */
    virtual mongoc_client_pool_t *getPool() const;

protected:
    bool _insert(const QString &dbName,
                 const QString &collectionName,
                 const bson_t *doc,
                 mongoc_client_t *client);
    bool _insertBulk(const QString &dbName,
                     const QString &collectionName,
                     const QList<bson_t *> &bulk,
                     mongoc_client_t *client);
    bool _find(const QString &dbName,
               const QString &collectionName,
               const bson_t *filter,
               const bson_t *opts,  //opts can be NULL.
               QList<bson_t *> &out,//It is caller`s responsible to free bson_t *.
               mongoc_client_t *client);
    bool _updateMany(const QString &dbName,
                     const QString &collectionName,
                     const bson_t *where,
                     const bson_t *set,
                     const bson_t *opts,  //opts can be NULL.
                     mongoc_client_t *client);
    bool _update_if_exist_or_insert(const QString &dbName,
                                    const QString &collectionName,
                                    const bson_t *set,  //Auto use $set when mongoc_collection_update_many().
                                    const bson_t *where,
                                    mongoc_client_t *client);
    bool _deleteMany(const QString &dbName,
                     const QString &collectionName,
                     const bson_t *where,
                     const bson_t *opts,        //opts can be NULL.
                     mongoc_client_t *client);

    QString uri;
    static bool inited;
};

/******************************************************** MKit:MScopedMongodb ***/
/**
  EXAMPLE:

    MScopedMongodb db;
    db.setUri(...);
    db.connect();
    db.find(...);
    //...

 * */
class MScopedMongodb : public MMongocBase
{
public:
    MScopedMongodb(bool callInitFunction = true);
    virtual ~MScopedMongodb();

    virtual bool connect();
    virtual void disConnect();

    virtual bool insert(const QString &dbName,const QString &collectionName,const bson_t *doc);
    virtual bool insertBulk(const QString &dbName,const QString &collectionName,const QList<bson_t *> &bulk);
    virtual bool find(const QString &dbName,
                      const QString &collectionName,
                      const bson_t *filter,
                      const bson_t *opts,  //opts can be NULL.
                      QList<bson_t *> &out //It is caller`s responsible to free bson_t *.
                      );
    virtual bool updateMany(const QString &dbName,
                            const QString &collectionName,
                            const bson_t *where,
                            const bson_t *set,
                            const bson_t *opts = NULL ); //opts can be NULL

    virtual bool update_if_exist_or_insert(const QString &dbName,
                                           const QString &collectionName,
                                           const bson_t *set,  //Auto use $set when mongoc_collection_update_many().
                                           const bson_t *where);
    virtual bool deleteMany(const QString &dbName,
                            const QString &collectionName,
                            const bson_t *where,
                            const bson_t *opts = NULL );    //opts can be NULL

    /*
     * Do NOT delete mongoc_client_t *.
     * */
    virtual mongoc_client_t *getClient() const;
    /*
     * Need to free mongoc_collection_t* with mongoc_collection_destroy().
     * */
    mongoc_collection_t *getCollection(const QString &dbName,const QString &collectionName);

protected:
    mongoc_client_t *client;

private:
    Q_DISABLE_COPY(MScopedMongodb)
};

/******************************************************** MKit:MPooledMongodb ***/

class MPooledMongodb : public MMongocBase
{
public:
    MPooledMongodb(bool callInitFunction = true);
    virtual ~MPooledMongodb();

    virtual bool connect();
    virtual void disConnect();

    virtual bool insert(const QString &dbName,const QString &collectionName,const bson_t *doc);
    virtual bool insertBulk(const QString &dbName,const QString &collectionName,const QList<bson_t *> &bulk);
    virtual bool find(const QString &dbName,
                      const QString &collectionName,
                      const bson_t *filter,
                      const bson_t *opts,  //opts can be NULL.
                      QList<bson_t *> &out //It is caller`s responsible to free bson_t *.
                      );

    /*
     * Do NOT delete mongoc_client_pool_t *.
     * */
    virtual mongoc_client_pool_t *getPool() const;

protected:
    mongoc_client_pool_t *pool;

private:
    Q_DISABLE_COPY(MPooledMongodb)
};

#endif //M_ENABLE_MONGOC1140

/******************************************************** MKit:MAutoRntTCP ***/
/*
 * An auto-reconnect TCP.
 *
 * A TCP with a timer can reconnect to server at the right time.
 * */
class MAutoRntTCP : public QTcpSocket
{
    Q_OBJECT
public:
    /*
     * Timer will be started in this constructor by default.
     * */
    explicit MAutoRntTCP(QObject *parent = 0);
    ~MAutoRntTCP();

    /*
     * Timer needs these info.
     * */
    void setAddr(const QString &ip = "127.0.0.1",int port = 8888);
    /*
     * Timer will call this func.
     * */
    void connect2host();

    /*
     * Called in constructor. Start OR restart.
     * */
    void startRnt(int interval = 1000 * 10);
    void stopRnt();

protected slots:
    void timeout_reconnect_slot();

protected:
    QTimer *timer_reconnect;
    QString ip;
    int port;
};

/******************************************************** MKit:MTable ***/

typedef QPair<QList<QJsonObject>,QList<QJsonObject> > TwoListJson;

class MTable : public MError
{
public:
    MTable(const QString &name = "human");
    MTable(const MTable &other);

    virtual ~MTable();

    MTable &operator =(const MTable &other);
    /*
     * Only compare row data,NOT including table name.
     * */
    bool operator ==(const MTable &other);
    /*
     * Only compare row data,NOT including table name.
     * */
    bool operator !=(const MTable &other);
    /*
     * Same as insert().
     * */
    MTable &operator <<(const QJsonObject &json);
    /*
     * Returns the row data at row position r as a modifiable reference.
     * r must be a valid row position in the table (i.e., 0 <= r < rowCount()).
     * */
    QJsonObject &operator [](int r);
    /*
     * This is an overloaded function.
     * */
    const QJsonObject &operator [](int r) const;

    void setName(const QString &name);
    QString getName() const;

    int rowCount() const;
    bool isEmpty() const;
    void inventOrder();
    /*
     * Same as DELETE FROM ...
     * */
    void clear();

    /*
     * Column name of table for each row.
     * */
    QList<QStringList> fieldName() const;

    /*
     * Export sql file.
     * */
    QString exprt2InsertSql() const;
    QString exprt2JsonStr(QJsonDocument::JsonFormat format = QJsonDocument::Compact) const;

    /*
     * Return false if json is empty.
     * */
    bool insert(const QJsonObject &json);
    /*
     * Same as clear() if where is empty.
     * */
    void del(const QJsonObject &where = QJsonObject());
    /*
     * Update all rows if where is empty.
     * */
    void update(const QJsonObject &set,const QJsonObject &where);
    /*
     * Return all rows if where is empty.
     * */
    QList<QJsonObject> select(const QJsonObject &where = QJsonObject()) const;
    /*
     * Same as select() if set is empty.
     * Update all rows if where is empty.
     *
     * Return rows which contains where in QPair<T1, T2>,T1 is before update,T2 is after update.
     * */
    TwoListJson select_and_update(const QJsonObject &where,const QJsonObject &set = QJsonObject());
    /*
     * update() with set if where is exist,otherwise insert() with set.
     * */
    void update_if_exist_or_insert(const QJsonObject &set,const QJsonObject &where);

protected:
    QList<QJsonObject> table;
    QString name;
};

/******************************************************** MKit:MSettings ***/
class MSettings
{
public :
    /*
     * Only for QSettings::IniFormat UTF-8.
     */
    MSettings(const QString &file);
    virtual ~MSettings();

    /*
     * Save to default if file is empty.
     */
    void save(const QString &file = QString());

    QMap<QString ,QVariant> map;
    QString file;
};

/******************************************************** MKit:MDurationTime ***/
class MDurationTime
{
public:
    MDurationTime(qint64 duration = 0);
    MDurationTime(const MDurationTime &other);

    virtual ~MDurationTime();

    MDurationTime & operator = (const MDurationTime &other);

    void setDuration(qint64 d);

    /*
     * Convert to format like "00-00:00:00" .
     */
    QString toString() const;

protected:
    int day;
    int hour;
    int minute;
    int second;
    int millisecond;
    qint64 duration;
};

/******************************************************** MKit:MTcpSocket ***/
class MTcpSocket : public QObject
{
    Q_OBJECT
public:
    enum CSType{
        Client = 0,
        Server = 1
    };

    explicit MTcpSocket(QObject *parent = 0);
    ~MTcpSocket();

    void setType(CSType t = MTcpSocket::Client);
    CSType getType() const;

    void setAddr(const QString &ip,int port);
    QPair<QString, int> getAddr()const;

    virtual bool start();
    virtual void stop();

    virtual qint64 write(const QByteArray &b);

    virtual bool isConnected() const;

signals:
    void readyRead(const QByteArray &byte);

private slots:
    void newConnection_slot();
    void readyRead_slot();

protected:
    MAutoRntTCP *tcp_client;
    QTcpSocket *tcp_server;
    QTcpServer *server;

    QString ip;
    int port;
    CSType type;
};
/******************************************************** MKit:MCSBClient ***/

//  FROM https://github.com/aliyun/csb-sdk/
//
//  -------------------------------------------------------------------------
//
//  signstr=_api_access_key=ak&_api_name=httpjsonbody&_api_timestamp=1588173696559&_api_version=1.0.0
//
//  signature=m29YxfcRV2gBZO+SKE/axQQ/w7g=
//
//
//  POST /test?name=a&age=12&title=test HTTP/1.1
//  Host: 127.0.0.1:8086
//  Accept: */*
//  _api_name:httpjsonbody
//  _api_version:1.0.0
//  _api_access_key:ak
//  _api_timestamp:1588173696559
//  _api_signature:m29YxfcRV2gBZO+SKE/axQQ/w7g=
//  Content-Type:application/json
//  Content-Length: 26
//
//  {"a":"csb云服务总线"}
//
//  -------------------------------------------------------------------------
//
//  signstr=_api_access_key=ak&_api_name=httpjson&_api_timestamp=1588175172105&_api_version=1.0.0&age=100&name=wiseking&title=god
//
//  signature=OeJY641QE+4Y3gHRkkd/K87BpIU=
//
//
//  POST /httpjson HTTP/1.1
//  Host: 127.0.0.1:8086
//  Accept: */*
//  _api_name:httpjson
//  _api_version:1.0.0
//  _api_access_key:ak
//  _api_timestamp:1588175172105
//  _api_signature:OeJY641QE+4Y3gHRkkd/K87BpIU=
//  Content-Length: 31
//  Content-Type: application/x-www-form-urlencoded
//
//  name=wiseking&age=100&title=god

//  -------------------------------------------------------------------------
//  -------------------------------------------------------------------------
//
//  EXAMPLE1:
//
//    // POST /test?name=a&age=12&title=test HTTP/1.1
//    // Content-Type: application/json
//    // _api_access_key: ak
//    // _api_name: httpjsonbody
//    // _api_signature: m29YxfcRV2gBZO+SKE/axQQ/w7g=
//    // _api_timestamp: 1588173696559
//    // _api_version: 1.0.0
//    // Accept: */*
//    // Content-Length: 26
//    // Connection: Keep-Alive
//    // Accept-Encoding: gzip, deflate
//    // Accept-Language: zh-CN,en,*
//    // User-Agent: Mozilla/5.0
//    // Host: 127.0.0.1:9999
//    //
//    // {"a":"csb云服务总线"}
//
//    MCSBClient *csb = new MCSBClient();
//    QString urll = "http://127.0.0.1:9999/test?name=a&age=12&title=test";
//    QString api = "httpjsonbody";
//    QString version = "1.0.0";
//    QString ak = "ak";
//    QString sk = "sk";
//    QString body = "{\"a\":\"csb云服务总线\"}";
//    csb->doPostJsonString(urll,body.toStdString().c_str(),api,version,ak,sk);
//
//  EXAMPLE2:
//
//    // POST /httpjson HTTP/1.1
//    // Content-Type: application/x-www-form-urlencoded
//    // _api_access_key: ak
//    // _api_name: httpjson
//    // _api_signature: OeJY641QE+4Y3gHRkkd/K87BpIU=
//    // _api_timestamp: 1588175172105
//    // _api_version: 1.0.0
//    // Accept: */*
//    // Content-Length: 31
//    // Connection: Keep-Alive
//    // Accept-Encoding: gzip, deflate
//    // Accept-Language: zh-CN,en,*
//    // User-Agent: Mozilla/5.0
//    // Host: 127.0.0.1:9999
//    //
//    // name=wiseking&age=100&title=god
//
//    MCSBClient *csb = new MCSBClient();
//    QString urll = "http://127.0.0.1:9999/httpjson";
//    QString api = "httpjson";
//    QString version = "1.0.0";
//    QString ak = "ak";
//    QString sk = "sk";
//    QString body = "name=wiseking&age=100&title=god";
//    csb->doPost(urll,body.toStdString().c_str(),api,version,ak,sk);

class MCSBClient : public QObject
{
    Q_OBJECT
public:
    explicit MCSBClient(QObject *parent = 0,bool debug = false);

signals:
    void finished2(const MHttpDataPackage &res);

public slots:
    void doPostJsonString(const QString &url,
                          const QByteArray &jsonStr,
                          const QString &api,
                          const QString &version,
                          const QString &ak,
                          const QString &sk,
                          int timeout_ms = 0);

    void doPost(const QString &url,
                const QByteArray &body,
                const QString &api,
                const QString &version,
                const QString &ak,
                const QString &sk,
                int timeout_ms = 0);

protected:
    void post(QNetworkRequest &req,const QJsonObject &headers,const QByteArray &body,int timeout_ms = 0);
    /*
     * data like :
     *
     * name=wiseking&age=100&title=god
     */
    static QJsonObject toJson(const QString &data) ;

    /*
     * returns like :
     *
     * name=wiseking&age=100&title=god
     */
    static QString http_build_query(const QJsonObject &json);

    /*
     * headers of signed for QNetworkRequest.
     */
    QJsonObject sign(const QByteArray &params,
                     const QString &api,
                     const QString &version,
                     const QString &ak,
                     const QString &sk) ;

    bool debug;
    MHttpHandler *MHttpHandler_;
};

/******************************************************** MKit:MBind ***/
/**
  EXAMPLE:

    MBinder *MBind_ = new MBinder();
    connect(MBind_,
            SIGNAL(binded(QList<MBindItem>,int)),
            this,
            SLOT(binded_slot(QList<MBindItem>,int)));

    MBind_->setId(1);
    MBind_->setTimeout(1000);

    MBindItem barcode,weight,cube;
    barcode.name = "barcode";
    barcode.value = "123456789";

    weight.name = "weigth";
    weight.value = 100;

    cube.name = "cube";
    cube.value = "100,200,300";

    MBind_->start();
    MBind_->setItem(barcode);
    MBind_->setItem(weight);
    MBind_->setItem(cube);
    MBind_->setItem(cube); //cover old value.
 */

typedef struct MBindItem{
    QString name;
    QVariant value;

    QString toString() const;
}MBindItem;

class MBinder : public QObject
{
    Q_OBJECT
public :
    explicit MBinder(QObject *parent = 0);

    void setId(int id = -1);
    int getId() const;

    void setExpireTime(int timeout_ms = 500);

    /*
     * Clear all items and start timing.
     */
    void start();

    void setItem(const MBindItem &item);

signals:
    /*
     * This signal will be sent constant on-time.
     */
    void binded(const QList<MBindItem > &list, int binderId);

protected slots:
    void timeout_slot();

protected:
    QList<MBindItem > list;
    int timeout_ms;
    QTimer *timer;
    int id;
};

/******************************************************** MKit:MDeviceBase ***/

class MDeviceBase : public QObject, public MError
{
    Q_OBJECT
public :
    explicit MDeviceBase(QObject *parent = 0);

    /*
     * Default true.
     */
    virtual bool isConnected() const;

};

#endif //MKIT_H
