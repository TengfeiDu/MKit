#include "MKit.h"
#include <QNetworkInterface>
#include <QTime>
#include <QGuiApplication>
#include <QScreen>
#include <QDesktopWidget>
#include <QUiLoader>
#include <QCryptographicHash>
#include <QBitmap>
#include <QFile>
#include <QCryptographicHash>
#include <QFileInfo>
#include <QMutexLocker>
#include <QScopedArrayPointer>
#include <QReadLocker>
#include <QWriteLocker>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QLineEdit>
#include <QSqlError>
#include <QUuid>
#include <QHeaderView>
#include <QBuffer>
#include <QTextCodec>

/*******************************************************************MTL:begin**********/

MTL::MTL(){}

MTL::MTL(const MTL &){}

MTL & MTL::operator =(const MTL &other){
    (void)other;
    return *this;
}

MTL::~MTL(){}

#ifdef Q_OS_WIN32
void MTL::keyboard_clicked_str(const QString &data)
{
    QList<uchar> list;
    for(int i = 0; i < data.length(); i++){
        list << data.at(i).toLatin1();
    }
    // ! @ # $ % ^ & * ( ) _ + { } | : " < > ?
    //                     - = [ ] \ ; ' , . /
    // ~ `
    for(int i = 0; i < list.size(); i++){
        uchar c = list.at(i);
        if(c >= '0' && c <= '9'){
            M_KEYBOARD_DOWN_AND_UP(c);
        } else if(c >= 'a' && c <= 'z'){
            M_KEYBOARD_DOWN_AND_UP(c - 32);
        } else if(c >= 'A' && c <= 'Z'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(c);
            M_KEYBOARD_UP(VK_SHIFT);
        }

        else if(c == '!'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('1');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '@'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('2');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '#'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('3');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '$'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('4');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '%'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('5');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '^'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('6');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '&'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('7');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '*'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('8');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '('){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('9');
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == ')'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP('0');
            M_KEYBOARD_UP(VK_SHIFT);
        }

        else if(c == '_'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_MINUS);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '-'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_MINUS);
        }

        else if(c == '+'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_PLUS);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '='){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_PLUS);
        }

        else if(c == '{'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_4);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '['){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_4);
        }

        else if(c == '}'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_6);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == ']'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_6);
        }

        else if(c == '|'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_5);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '\\'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_5);
        }

        else if(c == ':'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_1);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == ';'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_1);
        }

        else if(c == '"'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_7);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '\''){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_7);
        }

        else if(c == '<'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_COMMA);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == ','){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_COMMA);
        }

        else if(c == '>'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_PERIOD);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '.'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_PERIOD);
        }

        else if(c == '?'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_2);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '/'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_2);
        }

        else if(c == '~'){
            M_KEYBOARD_DOWN(VK_SHIFT);
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_3);
            M_KEYBOARD_UP(VK_SHIFT);
        } else if(c == '`'){
            M_KEYBOARD_DOWN_AND_UP(VK_OEM_3);
        }

        else if(c == ' '){
            M_KEYBOARD_DOWN_AND_UP(VK_SPACE);
        }
    }
}
#endif //Q_OS_WIN32

QReadWriteLock MTL::lock_setting_file;

#ifdef Q_OS_LINUX
void MTL::mSleep(long int second,long int nanoSecond)
{
    if(second <= 0 && nanoSecond <= 0)return ;
    struct timespec t;
    t.tv_sec=second;
    t.tv_nsec=nanoSecond;
    pselect(0,0,0,0,&t,0);
}
#endif
void MTL::delete_all_items_by_recursion_private(QTreeWidgetItem *it)
{
    if(it){
        int count = it->childCount();
        if(count > 0){
            QList<QTreeWidgetItem *> list;
            for(int i = 0 ; i < count; i++){
                list << it->child(i);
            }
            foreach (QTreeWidgetItem *item, list) {
                if(item->childCount() > 0){
                    MTL::delete_all_items_by_recursion_private(item);
                }else{
                    delete item;
                }
            }
        }
        delete it;
    }
}
void MTL::delete_all_items_by_recursion(QTreeWidget* tree)
{
    if(tree){
        int count = tree->topLevelItemCount();
        if(count > 0){
            QList<QTreeWidgetItem* > list;
            for(int i = 0; i < count; i++){
                list << tree->topLevelItem(i);
            }
            foreach (QTreeWidgetItem *item, list) {
                MTL::delete_all_items_by_recursion_private(item);
            }
        }
    }
}


#ifdef Q_OS_LINUX
quint64 MTL::mGetFreeDisk(const QString &path)
{
#ifdef Q_OS_LINUX
    struct statfs diskInfo;
    statfs(path.toStdString().c_str(), &diskInfo);
    quint64 blocksize = diskInfo.f_bsize;
    //quint64 freeDisk = diskInfo.f_bfree * blocksize;
    quint64 availableDisk = diskInfo.f_bavail * blocksize;
    return availableDisk>>20;
#else
    1=1;
    return 0;
#endif
}
#endif
QString MTL::get_md5_from_file(const QString &file)
{
    if(QFileInfo(file).isFile()){
        ullint totalSize = 0;
        ullint defaultReadSize = 1024*4;
        ullint read = 0;
        QByteArray tmp;
        QCryptographicHash md(QCryptographicHash::Md5);

        QFile f(file);
        if(f.open(QIODevice::ReadOnly)){
            totalSize = f.size();
            while(1){
                tmp = f.read(M_MINIMUM(totalSize - read, defaultReadSize));
                if(tmp.size() <= 0)break;
                read += tmp.size();
                md.addData(tmp);
                tmp.clear();
            }
            f.close();
            return QString(md.result().toHex());
        }
    }
    return "";
}

QString MTL::get_md5_from_data(const QByteArray &bData)
{
    QCryptographicHash md(QCryptographicHash::Md5);
    md.addData(bData);
    return QString(md.result().toHex());
}
void MTL::set_mask(QWidget* w,int yuanJiaoBanJin_x,int yuanJiaoBanJin_y)
{
    if(w){
        QBitmap map(w->size());
        map.fill();

        QPainter p(&map);
        p.setBrush(Qt::black);
        p.setPen(Qt::NoPen);
        p.setRenderHint(QPainter::Antialiasing);
        p.drawRoundedRect(map.rect(),yuanJiaoBanJin_x,yuanJiaoBanJin_y);

        w->setMask(map);
    }
}

void MTL::set_ellipse_mask(QWidget *w)
{
    if(w){
        QBitmap map(w->size());
        map.fill();

        QPainter p(&map);
        p.setBrush(Qt::black);
        p.setPen(Qt::NoPen);
        p.setRenderHint(QPainter::Antialiasing);
        int height = M_MINIMUM(map.width(),map.height());
        p.drawEllipse(map.width()/2,0,height,height);

        w->setMask(map);
    }
}

void MTL::connect_signal_and_slot(QWidget* uiWidget,QObject* slotObj)
{
    if(!uiWidget || !slotObj)return ;

    QObjectList objList =uiWidget->findChildren<QObject*>();
#if MDBG
    MDG << objList
        << uiWidget
        << slotObj;
#endif
    const QMetaObject *mObj = slotObj->metaObject();
    for(int i=0;i<mObj->methodCount();i++)
    {
        if(mObj->method(i).methodType()== QMetaMethod::Slot)
        {
            //on_XXX_clicked()
            QString slotName=QString(mObj->method(i).methodSignature());
            if(slotName.indexOf("on_")==0)
            {
                for(int j=0;j<objList.size();j++)
                {
                    QString ObjNameTmp=objList.at(j)->objectName();
                    if((slotName.indexOf(ObjNameTmp)==3)
                            && (slotName.mid(ObjNameTmp.length()+3,1)=="_")
                            && (slotName.mid(ObjNameTmp.length()+3+1).length()>0) )
                    {
                        QString signal=slotName.mid(ObjNameTmp.length()+3+1);
                        const QMetaObject *senderObj= objList.at(j)->metaObject();
                        int signalIndex= senderObj->indexOfSignal(signal.toStdString().c_str());

                        if(signalIndex>0)
                        {
                            QMetaObject::connect(objList.at(j),signalIndex,slotObj,i);
                            while(mObj->method(i+1).attributes() & QMetaMethod::Cloned)
                            {
                                i++;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
QWidget * MTL::load_ui_from_file(const QString& uiFileName,QWidget* parent)
{
    QWidget* widget = NULL;
    QUiLoader loader;
    QFile file(uiFileName);
    if(file.exists()){
        if(file.open(QFile::ReadOnly)){
            widget = loader.load(&file, parent);
            file.close();
        }
    }
    return widget;
}

void MTL::set_config(const QString& f,
                     const QString& key,
                     const QVariant& value)
{
    QWriteLocker lock(&MTL::lock_setting_file);
    QSettings file(f,QSettings::IniFormat);
    file.setIniCodec("UTF-8");
    file.setValue(key,value);
}
QVariant MTL::get_config(const QString& f,
                         const QString& key)
{
    QVariant ret ;
    if(QFile::exists(f)){
        QReadLocker lock(&MTL::lock_setting_file);
        QSettings file(f,QSettings::IniFormat);
        file.setIniCodec("UTF-8");
        ret = file.value(key);
    }
    return ret;
}

QMap<QString, QVariant> MTL::get_config(const QString &file)
{
    QMap<QString ,QVariant > map;
    if(QFile::exists(file)){
        QReadLocker lock(& MTL::lock_setting_file);
        QSettings f(file,QSettings::IniFormat);
        f.setIniCodec("UTF-8");
        QStringList list = f.allKeys();
        foreach (const QString & key, list) {
            map.insert(key,f.value(key));
        }
    }
    return  map;
}

void MTL::set_config(const QString &file, const QMap<QString, QVariant> &map)
{
    if(map.size() > 0){
        QWriteLocker lock(&MTL::lock_setting_file);
        QSettings f(file,QSettings::IniFormat);
        f.setIniCodec("UTF-8");
        QList<QString > list = map.keys();
        foreach (const QString &key, list) {
            f.setValue(key,map.value(key));
        }
    }
}

QByteArray MTL::get_data_from_file(const QString & file)
{
    QByteArray ret;
    QFile f(file);
    if(f.exists() && f.open(QIODevice::ReadOnly)){
        ret = f.readAll();
        f.close();
    }
    return ret;
}

bool MTL::set_data_2_file(const QString &file, const QByteArray &data, MTL::WriteType t)
{
    bool ret = false;
    QFile f(file);
    QDir d = QFileInfo(file).absoluteDir();
    if(!d.exists() && !QDir().mkpath(d.absolutePath())){
        goto end;
    }
    if(!f.open(t == MTL::Append ? QIODevice::Append : QIODevice::ReadWrite)){
        goto end;
    }
    switch (t) {
    case MTL::ClearAndWrite:{
        if(!f.resize(0)){
            goto end2;
        }
        break;
    }
    case MTL::FromBegin:
    case MTL::Append:
    default:
        break;
    }
    ret = f.write(data) >= 0;
end2:
    f.close();
end:
    return ret;
}

void MTL::set_center(QWidget* widget)
{
    if(widget){
        QDesktopWidget *desktopWidget = QApplication::desktop();
        QRect rect = desktopWidget->screenGeometry(desktopWidget->primaryScreen());
        widget->move((rect.width() - widget->width()) / 2,
                     (rect.height() - widget->height()) / 2);
    }
}
QPixmap MTL::get_picture_of_desktop()
{
    return QGuiApplication::primaryScreen()->grabWindow(QApplication::desktop()->winId());
}

QString MTL::get_time_now(TimeType type,bool hasMillisecond)
{
    QString time = hasMillisecond ? M_TIME_NOW_MILLISECONDS : M_TIME_NOW_SECONDS;
    switch (type) {
    case MTL::Normal:{
        return time;
    }
    case MTL::Plain:{
        QString str = time;
        str.replace(QString("-"),QString(""));
        str.replace(QString(" "),QString(""));
        str.replace(QString(":"),QString(""));
        str.replace(QString("."),QString(""));
        return str;
    }
    default:{
        return time;
    }
    }
}
#ifdef Q_OS_LINUX
QString MTL::mGetHighPrecisionTime()
{
    struct timespec time={0, 0};
    int ret=clock_gettime(CLOCK_REALTIME, &time);
    return ret<0?"":QString().sprintf("%010lu.%09lus", time.tv_sec, time.tv_nsec);
}
#endif
QString MTL::get_rand_str(RandType type,int length)
{
    switch (type) {
    case MTL::Number: {
        return MTL::get_number_str_private(length);
    }
    case MTL::Character: {
        return MTL::get_character_str_private(length);
    }
    case MTL::NumberAndCharacter: {
        return MTL::get_rand_str_private(length);
    }
    default: {
        return "";
    }
    }
}
QString MTL::get_character_str_private(int length)
{
    QString tmp;
    for(uchar i = 0; i < 26; i++){
        tmp += QString().append(QChar('a' + i));
    }
    tmp += tmp.toUpper();
    int max = length;
    QString str = "";
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    for(int i = 0; i < max; i++){
        int ir = qrand()%tmp.length();
        str[i] = tmp.at(ir);
    }
    return str;
}
QString MTL::get_number_str_private(int length)
{
    QString tmp = QString("0123456789");
    int max = length;
    QString str = "";
    QTime t;
    t = QTime::currentTime();
    ::qsrand(t.msec() + t.second() * 1000);
    for(int i = 0; i < max; i++){
        int ir = ::qrand()%tmp.length();
        str[i] = tmp.at(ir);
    }
    return str;
}
QString MTL::get_rand_str_private(int length)
{
    QString tmp;
    for(uchar i = 0; i < 26; i++){
        tmp += QString().append(QChar('a' + i));
    }
    tmp = QString("0123456789") + tmp + tmp.toUpper();
    int max = length;
    QString str = "";
    QTime t= QTime::currentTime();
    ::qsrand(t.msec()+t.second()*1000);
    for(int i = 0; i < max; i++){
        int ir = ::qrand()%tmp.length();
        str[i] = tmp.at(ir);
    }
    return str;
}

void MTL::kill_character(uchar *source,
                         int len,
                         uchar uc)
{
    if(source && len > 0){
        uchar *tmp = NULL;
        tmp = (uchar *)::malloc(len);
        if(tmp){
            uchar *old = tmp;
            ::memset(tmp, 0, len);
            for(int i = 0; i < len; i++){
                if(source[i] != uc)
                    *tmp++ = source[i];
            }
            ::memset(source, 0, len);
            ::memcpy(source, old, len);
            ::free(old);
        }
    }
}
QString MTL::kill_last_character(const QString &str,const QString &kill)
{
    if(str.length() > 0
            && kill.length() > 0){
        if(QString(str[str.length() - 1]) == kill)
            return MTL::kill_last_character(str.mid(0,str.length() - 1), kill);
    }
    return str;
}
QString MTL::get_hex_str_from_uchar_upper(uchar A)
{
    static const uchar data[16] = {'0','1','2','3','4',
                                   '5','6','7','8','9',
                                   'A','B','C','D','E','F'};
    return QString("%1%2").arg(QChar(data[A / 16])).arg(QChar(data[A % 16]));
}
QJsonObject MTL::get_json_obj_from_QString(const QString &str)
{
    QByteArray byte_array;
    QJsonDocument parse_doucment;
    QJsonParseError json_error;

    byte_array = byte_array.append(str);
    parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError){
        return parse_doucment.object();
    }
    return QJsonObject();
}

QString MTL::get_str_json_array_from_QListQPair(const QList<QPair<QByteArray, QByteArray> > &l, QJsonDocument::JsonFormat format)
{
    QJsonArray array;
    for(int i = 0; i < l.size(); i++){
        QJsonObject json;
        json.insert(QString().append(l.at(i).first),
                    QJsonValue(QString().append(l.at(i).second)));
        array.append(QJsonValue(json));
    }
    return MTL::get_str_from_QJsonArray(array, format);
}

QString MTL::get_str_from_QJsonObject(const QJsonObject &json,QJsonDocument::JsonFormat format)
{
    QJsonDocument doc;
    doc.setObject(json);
    return QString().append(doc.toJson(format));
}

QString MTL::get_str_from_QJsonArray(const QJsonArray &array,QJsonDocument::JsonFormat format)
{
    QJsonDocument doc;
    doc.setArray(array);
    return QString().append(doc.toJson(format));
}
QJsonObject MTL::get_mac()
{
    QJsonObject json;
    QList<QNetworkInterface> listAddress = QNetworkInterface::allInterfaces();
    for(int i = 0; i < listAddress.size(); i++){
        json.insert(listAddress.at(i).humanReadableName(),
                    QJsonValue(listAddress.at(i).hardwareAddress()));
    }
    return json;
}
QString MTL::get_bit_str_from_uchar_length_8(uchar number,bool reverseOrder)
{
    /***
     * 0x77->01110111
     *
     * */
    QString ret = "";
    QString zero = "0";
    QString one = "1";
    for (int i = 0; i < 8; i++){
        if((number) & (0x01 << i)){
            ret = one + ret;
        }else{
            ret = zero + ret;
        }
    }
    if(reverseOrder){
        QString rett = "";
        for(int i = 0; i < ret.length(); i++){
            rett += ret.mid(ret.length() - 1 - i, 1);
        }
        ret = rett;
    }
    return ret;
}
QString MTL::get_bit_str_from_uint_length_32(uint number)
{
    QString rett = "";
    int loop = sizeof(number);
    for(int i = 0; i < loop; i++){
        rett += MTL::get_bit_str_from_uchar_length_8((number >> ((loop - 1 - i) * 8)) & 0xff);
    }
    return rett;
}

uint MTL::get_uint_from_hex_str(const QString & hexstr)
{
    QRegExp rg("^[0-9a-fA-F]+$");
    if(rg.exactMatch(hexstr)){
        bool ok = false;
        uint ut = hexstr.toUInt(&ok, 16);
        if(ok)
            return ut;
    }
    return 0;
}

QString MTL::get_hex_str_from_uint_length_8_upper(uint number)
{
    return MTL::get_hex_str_from_uchar_upper(number >> 24) +
            MTL::get_hex_str_from_uchar_upper((number >> 16) & 0xff) +
            MTL::get_hex_str_from_uchar_upper((number >> 8) & 0xff) +
            MTL::get_hex_str_from_uchar_upper(number & 0xff);
}

QString MTL::get_hex_str_from_ulonglong_length_16_upper(ullint number)
{
    return MTL::get_hex_str_from_uint_length_8_upper(number >> 32) +
            MTL::get_hex_str_from_uint_length_8_upper(number & 0x00000000ffffffff);
}
#ifdef M_ENABLE_QRENCODE
QImage MTL::get_2d_code(const QString & str,
                        int size,
                        int version,
                        QRecLevel level,
                        QRencodeMode hint,
                        int casesensitive)
{
    QRcode *qrcode = NULL;
    qrcode = QRcode_encodeString(str.toStdString().c_str(),
                                 version,
                                 level,
                                 hint,
                                 casesensitive);

    QImage qrImage2(size,size,QImage::Format_RGB32);
    QPainter painter(&qrImage2);
    QColor fg("black");
    QColor bg("white");
    painter.setBrush(bg);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,
                     0,
                     qrImage2.size().width(),
                     qrImage2.size().height());
    painter.setBrush(fg);
    int s = qrcode->width > 0 ? qrcode->width : 1;
    double w = qrImage2.size().width() - 6;
    double h = qrImage2.size().height() - 6;
    double aspect = w / h;
    double scale = ((aspect > 1.0) ? h : w) / s;
    for(int y = 0; y < s; y++){
        for(int x = 0; x < s; x++){
            if(qrcode->data[y * s + x] & 0x01){
                QRectF r(x * scale + (qrImage2.size().width() - w) / 2,
                         y * scale + (qrImage2.size().height() - h) / 2,
                         scale,
                         scale);
                painter.drawRects(&r,1);
            }
        }
    }
    QRcode_free(qrcode);
    return qrImage2;
}
#endif
QString MTL::get_hex_str_from_uchar_array_upper(const char *array,
                                                int length,
                                                bool autoAddPrefix,
                                                bool autoAddSpace)
{
    QString ret = "";
    if(array && length > 0){
        for(int i = 0; i < length; i++){
            ret += MTL::get_hex_str_from_uchar_upper(array[i]);
            if(autoAddSpace && i != length - 1){
                ret += " ";
            }
        }
        if(autoAddPrefix && ret.length() > 0){
            ret = QString("0x").append(ret);
        }
    }
    return ret;
}

QString MTL::get_hex_str_from_uchar_array_upper(const QByteArray &data, bool autoAddPrefix, bool autoAddSpace)
{
    return MTL::get_hex_str_from_uchar_array_upper(data.data(),data.length(),autoAddPrefix,autoAddSpace);
}

QString MTL::get_hex_str_format_from_QByteArray(const QByteArray &data, const QString &separator, int indent)
{
    QString out;
    for(int i = 0; i < data.length(); i++){
        out += QString("0x%1").arg(MTL::get_hex_str_from_uchar_upper(data.at(i)));
        if(i != data.length() - 1){
            out += separator;
        }
        if((i + 1) % indent == 0){
            out += "\n";
        }
    }
    return out;
}

QJsonArray MTL::get_hex_str_json_formart_from_QByteArray(const QByteArray &data, const QString &sep, int indent)
{
    QJsonArray ret;
    int rows = 0;
    int left = 0;
    if(indent > 0){
        rows = data.length() / indent;
        left = data.length() % indent;
    } else{
        rows = 0;
        left = data.length();
    }
    for(int i = 0; i < rows; i++){
        QJsonObject tmp;
        QString row;
        for(int j = 0; j < indent; j++){
            row += QString("0x%1").arg(MTL::get_hex_str_from_uchar_upper(data.at(i * indent + j)));
            if(j != indent - 1)
                row += sep;
        }
        tmp.insert(QString::number(i),row);
        ret.append(tmp);
    }
    if(left > 0){
        QJsonObject tmp;
        QString row;
        for(int i = 0; i < left; i++){
            row += QString("0x%1").arg(MTL::get_hex_str_from_uchar_upper(data.at(rows * indent + i)));
            if(i != left - 1)
                row += sep;
        }
        tmp.insert(QString::number(rows),row);
        ret.append(tmp);
    }
    return ret;
}

bool MTL::compress_data_from_file_2_file_by_qCompress(const QString &inFile, const QString &outFile, QByteArray &outData, int compressionLevel)
{
    QByteArray data = MTL::get_data_from_file(inFile);
    data = qCompress(data,compressionLevel);
    data = QByteArray().append(MTL::get_hex_str_format_from_QByteArray(data));
    outData = data;
    return MTL::set_data_2_file(outFile,data);
}

bool MTL::uncompress_data_2_file_by_qUncompress(const QString &outFile, QByteArray &outData, const uchar *array, int length)
{
    QByteArray data = qUncompress(array,length);
    outData = data;
    return MTL::set_data_2_file(outFile,data);
}

QString MTL::get_bit_str_from_uchar_array(const uchar *array,
                                          int length)
{
    QString ret = "";
    if(array && length > 0){
        for(int i = 0; i < length; i++){
            ret += MTL::get_bit_str_from_uchar_length_8(array[i]);
        }
    }
    return ret;
}

QString MTL::get_bit_str_from_uchar_array(const QByteArray &d)
{
    return MTL::get_bit_str_from_uchar_array((uchar *)d.data(),d.length());
}

bool MTL::get_binary_data_from_hex_str(const uchar *hexStr,
                                       int length,
                                       QByteArray &out)
{
    if((length % 2) != 0
            || !hexStr
            || length <= 0)
        return false;
    uchar *tmp = new uchar[length]();
    QScopedArrayPointer<uchar> pp(tmp);
    (void)pp;
    if(!tmp)
        return false;
    ::memcpy(tmp,hexStr,length);
    //to upper
    for(int i = 0; i < length; i++){
        if(tmp[i] <= 'z'
                && tmp[i] >= 'a'){
            tmp[i] = tmp[i] - ('a' - 'A');
        }
    }
    for(int i = 0; i < length; i++){
        if( (tmp[i] >= '0' && tmp[i] <= '9')
                || (tmp[i] >= 'A' && tmp[i] <= 'F')){
            continue;
        }
        else return false;
    }

    out.clear();
    for(int i = 0; i < length; i += 2){
        uchar a = tmp[i] <= '9' ? tmp[i] - '0' : (tmp[i] - 'A' + 10);
        uchar b = tmp[i + 1] <= '9' ? tmp[i + 1] - '0' : (tmp[i + 1] - 'A' + 10);
        out.append(a * 16 + b);
    }
    return true;
}

bool MTL::is_big_endian()
{
    uint A = 0x12345678;
    uchar* volatile B = (uchar*)&A;
#if MDBG
    MDG<<B;
    MDG<<MTL::mGetObj()->mUchar22BitsHex(*B++)<<B;
    MDG<<MTL::mGetObj()->mUchar22BitsHex(*B++)<<B;
    MDG<<MTL::mGetObj()->mUchar22BitsHex(*B++)<<B;
    MDG<<MTL::mGetObj()->mUchar22BitsHex(*B)<<B;
    B=(uchar*)&A;
    MDG<<B<<MTL::mGetObj()->mUchar22BitsHex(*B++);
    MDG<<B<<MTL::mGetObj()->mUchar22BitsHex(*B++);
    MDG<<B<<MTL::mGetObj()->mUchar22BitsHex(*B++);
    MDG<<B<<MTL::mGetObj()->mUchar22BitsHex(*B);
#endif
    return *B != 0x78;
}

QString MTL::get_data_type_size()
{
    QString ret;
    ret.append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned char))        .arg(sizeof(uchar))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned short))       .arg(sizeof(unsigned short))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned int))         .arg(sizeof(uint))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned long))        .arg(sizeof(unsigned long))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned long int))    .arg(sizeof(unsigned long int))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned long long))   .arg(sizeof(unsigned long long))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(unsigned long long int)).arg(sizeof(unsigned long long int))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(float))                .arg(sizeof(float))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(double))               .arg(sizeof(double))).append(M_ENTER);;
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(long double))          .arg(sizeof(long double))).append(M_ENTER);
    ret.append(QString("%1 = %2").arg(M_CAST_STRING(void *))               .arg(sizeof(void *)));
    return ret;
}

uchar MTL::encode_and_decode(uchar A)
{
    A = (A & 0x0f) << 4 | (A & 0xf0) >> 4;
    A = (A & (0x03 << 6)) >> 2 | (A & (0x03 << 4)) << 2 | (A & (0x03 << 2)) >> 2 | (A & (0x03 << 0)) << 2;
    return ~A;
}

QByteArray MTL::iconvt(const QByteArray &data, CodeType type)
{
    QByteArray ret = "";

    static bool init = false;
    static QMutex mutex;
    QMutexLocker lock(&mutex);

    static int dic[][2] = {
    #   include "cp936_to_unicode.txt"
    };

    static QHash<int ,int> hh_cp936_to_unicode;
    static QHash<int ,int> hh_unicode_to_cp936;

    if(!init){
        init = true;
        for(int i = 0; i < (int)M_SIZE_ARRAY_ELEMENTS(dic); i++){
            hh_cp936_to_unicode.insert(dic[i][0],dic[i][1]);
            hh_unicode_to_cp936.insert(dic[i][1],dic[i][0]);
        }
    }

    //utf-8 :
    //1110 xxxx,10xx xxxx,10xx xxxx
    //0xxx xxxx

    //gbk :
    //1xxx xxxx,xxxx xxxx
    //0xxx xxxx

    if(type == MTL::UTF8_2_GBK){
        for(int i = 0; i < data.length();){
            uchar tmp = data.at(i);
            if(tmp >> 7 == 0){
                ret.append(tmp);
                i++;
                continue;
            } else if((tmp & 0xe0) == 0xe0){
                if(i + 2 < data.length()){
                    uint unicode = 0;
                    uchar *p = (uchar *)&unicode;
                    p[1] = ((data.at(i) & 0x0f) << 4) | ((data.at(i + 1) >> 2) & 0x0f);
                    p[0] = ((data.at(i + 1) & 0x03) << 6) | (data.at(i + 2) & 0x3f);
                    unicode = hh_unicode_to_cp936.value(unicode,0xffffffff);
                    if(unicode == 0xffffffff){
                        ret.append('*');
                    } else{
                        ret.append(p[1]).append(p[0]);
                    }
                }
                i += 3;
                continue;
            }else {
                i++;
            }
        }
    } else if(type == MTL::GBK_2_UTF8){
        for(int i = 0; i < data.length();){
            uchar tmp = data.at(i);
            if(tmp >> 7 == 0){
                ret.append(tmp);
                i++;
                continue;
            } else if(tmp >> 7 == 1){
                if(i + 1 < data.length()){
                    uint gbk = 0;
                    uchar *p = (uchar *)&gbk;
                    p[1] = data.at(i);
                    p[0] = data.at(i + 1);
                    uint unicode = hh_cp936_to_unicode.value(gbk ,0xffffffff);
                    if(unicode == 0xffffffff){
                        ret.append('*');
                    } else {
                        p = (uchar *)&unicode;
                        uchar utf8[3] = {0xe0,0x80,0x80};
                        utf8[0] = utf8[0] | (p[1] >> 4);
                        utf8[1] = utf8[1] | (((p[1] & 0x0f)) << 2) | (p[0] >> 6);
                        utf8[2] = utf8[2] | (p[0] & 0x3f);
                        ret.append(utf8[0]).append(utf8[1]).append(utf8[2]);
                    }
                }
                i += 2;
                continue;
            }else {
                i++;
            }
        }
    }
    return ret;
}

QByteArray MTL::iconvt_QTextCodec(const QByteArray &data, MTL::CodeType type)
{
    QByteArray ret = "";
    QTextCodec *c = QTextCodec::codecForName("GBK");
    if(!c)
        return ret;
    switch (type) {
    case MTL::GBK_2_UTF8:
        ret = c->toUnicode(data).toStdString().c_str();
        break;
    case MTL::UTF8_2_GBK:
        ret = c->fromUnicode(data.data());
        break;
    default:
        break;
    }
    return ret;
}


#ifdef Q_OS_WIN32

QByteArray MTL::iconvt_WCHAR(const QByteArray &data, MTL::CodeType type)
{
    QByteArray ret = "";
    switch (type) {
    case MTL::GBK_2_UTF8:{
        int n = MultiByteToWideChar(CP_ACP, 0, data.data(), -1, NULL, 0);
        WCHAR *str1 = new WCHAR[n]();
        MScopedPointer<WCHAR > p(str1,MScopedPointer<WCHAR >::ArrayPointer);
        MultiByteToWideChar(CP_ACP, 0, data.data(), -1, str1, n);
        n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
        char *str2 = new char[n]();
        MScopedPointer<char > pp(str2,MScopedPointer<char >::ArrayPointer);
        WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
        ret = str2;
        break;
    }
    case MTL::UTF8_2_GBK:{
        int len = MultiByteToWideChar(CP_UTF8, 0, data.data(), -1, NULL, 0);
        unsigned short * wszGBK = new unsigned short[len + 1]();
        memset(wszGBK, 0, len * 2 + 2);
        MultiByteToWideChar(CP_UTF8, 0, (char*)data.data(), -1, (wchar_t*)wszGBK, len);

        len = WideCharToMultiByte(CP_ACP, 0, (wchar_t*)wszGBK, -1, NULL, 0, NULL, NULL);
        char *szGBK = new char[len + 1]();
        memset(szGBK, 0, len + 1);
        WideCharToMultiByte(CP_ACP,0, (wchar_t*)wszGBK, -1, (char*)szGBK, len, NULL, NULL);
        ret = szGBK;
        M_DELETE_TO_NULL_ARRAY(wszGBK);
        M_DELETE_TO_NULL_ARRAY(szGBK);
        break;
    }
    default:
        break;
    }
    return ret;
}
#endif //Q_OS_WIN32

#if (QT_VERSION <= QT_VERSION_CHECK(5, 4, 2)) && M_ENABLE_ICONV
QByteArray MTL::iconvt(const uchar *src,
                       uint length_src,
                       const char *from,
                       const char *to,
                       uint length_tmp_how_many_times_than_length_src)
{
    QByteArray ret;
    if(from && to && src){
        size_t length_tmp = length_src * length_tmp_how_many_times_than_length_src;
        uchar *tmp = new uchar[length_tmp]();
        MScopedPointer<uchar > p(tmp);
        (void)p;
        size_t length_out = 0;

        iconv_t cd = ::iconv_open(to,from);
        if(cd){
            //iconv will change these parameters
            size_t length_des_available = length_tmp;
            size_t length_src_request = length_src;
            uchar *p_moving_src = (uchar *)src;
            uchar *p_moving_des = tmp;

            int ok = ::iconv(cd, (char **)&p_moving_src, &length_src_request, (char **)&p_moving_des, &length_des_available);
            if(ok != -1){
                length_out = length_tmp - length_des_available;
                ret = QByteArray((char *)tmp,(int)length_out);
            }
            ::iconv_close(cd);
        }
    }
    return ret;
}
#endif

llint MTL::time_2_time(const QString &from, const QString &to)
{
    QString str1 = from.trimmed();
    QString str2 = to.trimmed();
    QDateTime dt1 = QDateTime::fromString(str2,M_TIME_FORMAT_WITH_MILLISECONDS);
    QDateTime dt2 = QDateTime::fromString(str1,M_TIME_FORMAT_WITH_MILLISECONDS);
    return dt2.msecsTo(dt1);
}

QString MTL::get_canlendar()
{
    return QString(MTL::get_data_from_file(":/QRC/canlendar_length_1102258.txt"));
}
#ifdef Q_OS_LINUX
QString MTL::mGetHardDiskSerialNumber()
{
    QString ret="";
    struct hd_driveid id;
    int fd = open("/dev/sda", O_RDONLY|O_NONBLOCK);
    if (fd < 0) {
        return ret;
    }
    if(!ioctl(fd, HDIO_GET_IDENTITY, &id))
    {
        ret= QString().append(QByteArray((const char*)id.serial_no,sizeof(id.serial_no)));
    }
    ::close(fd);
    return ret.trimmed();
}

bool MTL::mIsValidSerial8250(const QString &systemLocation)
{
    if(!QFile::exists(systemLocation))return false;

    const mode_t flags = O_RDWR | O_NONBLOCK | O_NOCTTY|O_LARGEFILE|O_CLOEXEC;
    const int fd = ::open(QFileInfo(systemLocation).absoluteFilePath().toLocal8Bit().constData(),
                          flags,
                          0777);
    if (fd != -1) {
        ::fcntl(fd, F_SETFD, FD_CLOEXEC);
        struct serial_struct serinfo;
        const int retval = ::ioctl(fd, TIOCGSERIAL, &serinfo);
        ::close(fd);
        if (retval != -1 && serinfo.type != PORT_UNKNOWN)
            return true;
    }
    return false;
}

QString MTL::mGetUUID()
{
    uchar data[100]={0};
    FILE*f=NULL;
    f=popen("uuidgen","r");
    if(!f)return "";
    char *ret=::fgets((char*)data,sizeof(data),f);
    (void)ret;
    ::pclose(f);
    return QString().append(QByteArray((char*)data)).trimmed();
}
#endif

QMap<ullint, QList<ld >* > MTL::map_data;

bool MTL::is_stable(ld newData,int times,ld range)
{
    if(times < 2) return false;

    QList<long double> *data = NULL;
    ullint threadid = (ullint)M_CURRENT_THREAD_OBJECT->currentThreadId();
    if(!map_data.contains(threadid)){
        map_data.insert(threadid,new QList<long double>());
    }
    data = map_data.value(threadid);
    data->append(newData);

    if(data->size() >= times){
        QList<long double> dataTmp;
        for(int i = 0; i < times; i++){
            dataTmp << data->at(data->size() - times + i);
        }
        bool ret = true;
        for(int i = 0; i < dataTmp.size() - 1; i++){
            if(fabsl(dataTmp.at(dataTmp.size() - 1) - dataTmp.at(i)) > fabsl(range)){
                ret = false;
                break;
            }
        }
        int removeCount = data->size() - times;
        for(int i = 0; (i < removeCount + 1) && !data->isEmpty(); i++){
            data->takeFirst();
        }
        return ret;
    }
    return false;
}

QString MTL::add_msecond(const QString &time, qint64 ms)
{
    QRegExp reg(M_REGEXP_TIME);
    if(!reg.exactMatch(time)){
        return time;
    }
    QDateTime dt = QDateTime::fromString(time,M_TIME_FORMAT_WITH_MILLISECONDS);
    return dt.addMSecs(ms).toString(M_TIME_FORMAT_WITH_MILLISECONDS).trimmed();
}

QString MTL::get_last_cut_str(const QString &data, const QString &flag)
{
    QString tmp = "";
    int index = data.lastIndexOf(flag);
    if(index >= 0){
        tmp = data.mid(0,index);
        index = tmp.lastIndexOf(flag);
        if(index >= 0){
            tmp = tmp.mid(index + flag.length());
        }
    }
    return tmp;
}

QString MTL::get_str_json_array_from_QStringList(const QStringList &l, QJsonDocument::JsonFormat format)
{
    QJsonArray arr;
    for(int i = 0; i < l.size(); i++){
        QJsonObject json;
        json.insert(QString("%1").arg(i), QJsonValue(l.at(i)));
        arr.append(QJsonValue(json));
    }
    return MTL::get_str_from_QJsonArray(arr,format);
}

QString MTL::get_str_json_array_from_QList_QString(const QList<QString> &l, QJsonDocument::JsonFormat format)
{
    QStringList data;
    foreach (const QString &it, l) {
        data << it;
    }
    return MTL::get_str_json_array_from_QStringList(data,format);
}


QString MTL::get_str_json_array_from_QXmlStreamAttributes(const QXmlStreamAttributes &attr,
                                                          QJsonDocument::JsonFormat format)
{
    QJsonArray array;
    foreach (const QXmlStreamAttribute &it, attr) {
        QJsonObject tmp;
        tmp.insert(it.name().toString(),it.value().toString());
        array.append(tmp);
    }
    return MTL::get_str_from_QJsonArray(array,format);
}


QByteArray MTL::translate_data(const QByteArray &data, bool encode)
{
    QByteArray ret = data;
    if(encode){
        ret.replace("*","*1");
        ret.replace("#","*2");
    }else{
        ret.replace("*2","#");
        ret.replace("*1","*");
    }
    return ret;
}

QSize MTL::get_QSize_from_int(int n)
{
    if(n > 0){
        int total = n;
        int sqr = (int)::sqrt(total);
        int sub = total - sqr * sqr;
        int quZheng = sub / sqr;
        int quYu = sub % sqr;
        int w = sqr + quZheng;
        int h = sqr + (quYu == 0 ? 0 : 1);
        return QSize(M_MAXIMUM(w,h),M_MINIMUM(w,h));
    }
    return QSize();
}

QList<QByteArray> MTL::split(const QByteArray &data, const QByteArray &sep)
{
    QList<QByteArray> ret;
    if(data.length() < 1)
        return ret;
    if(sep.length() < 1)
        return ret << data;
    int index = data.indexOf(sep);
    if(index < 0)
        return ret << data;
    QByteArray ok = data.mid(0,index);
    ret << ok;
    QByteArray left = data.mid(index + sep.length());
    if(left.length() < 1)
        return ret;
    index = left.indexOf(sep);
    return index >= 0 ? ret << split(left,sep) : ret << left;
}

bool MTL::contains(const QJsonObject &container, const QJsonObject &item)
{
    QJsonObject tmp = container;
    QStringList keys = tmp.keys();
    foreach (const QString &key, keys) {
        if(!item.contains(key))
            tmp.remove(key);
    }
    return tmp == item;
}

QString MTL::get_str_from_QJsonValue(const QJsonValue &value)
{
    switch (value.type()) {
    case QJsonValue::Null:
        return "Null";
    case QJsonValue::Bool:
        return value.toBool() ? "true" : "false";
    case QJsonValue::Double:
        return QString::number(value.toDouble());
    case QJsonValue::String:
        return value.toString();
    case QJsonValue::Array:
        return MTL::get_str_from_QJsonArray(value.toArray());
    case QJsonValue::Object:
        return MTL::get_str_from_QJsonObject(value.toObject());
    case QJsonValue::Undefined:
        return "Undefined";
    default:
        return "Error QJsonValue Type";
    }
}

QJsonObject MTL::add(const QJsonObject &json1, const QJsonObject &json2)
{
    QJsonObject ret = json1;
    for(QJsonObject::const_iterator it = json2.constBegin(); it != json2.constEnd(); it++){
        ret.insert(it.key(),it.value());
    }
    return ret;
}

QByteArray MTL::hash_hmac(const QByteArray &keyy, const QByteArray &baseString)
{
    QByteArray key = keyy;
    int blockSize = 64; // HMAC-SHA-1 block size, defined in SHA-1 standard
    if (key.length() > blockSize) { // if key is longer than block size (64), reduce key length with SHA-1 compression
        key = QCryptographicHash::hash(key, QCryptographicHash::Sha1);
    }
    QByteArray innerPadding(blockSize, char(0x36)); // initialize inner padding with char "6"
    QByteArray outerPadding(blockSize, char(0x5c)); // initialize outer padding with char "/"
    // ascii characters 0x36 ("6") and 0x5c ("/") are selected because they have large
    // Hamming distance (http://en.wikipedia.org/wiki/Hamming_distance)
    for (int i = 0; i < key.length(); i++) {
        innerPadding[i] = innerPadding[i] ^ key.at(i); // XOR operation between every byte in key and innerpadding, of key length
        outerPadding[i] = outerPadding[i] ^ key.at(i); // XOR operation between every byte in key and outerpadding, of key length
    }
    // result = hash ( outerPadding CONCAT hash ( innerPadding CONCAT baseString ) ).toBase64
    QByteArray total = outerPadding;
    QByteArray part = innerPadding;
    part.append(baseString);
    total.append(QCryptographicHash::hash(part, QCryptographicHash::Sha1));
    QByteArray hashed = QCryptographicHash::hash(total, QCryptographicHash::Sha1);
         /// 注意——>把字符串hashed转换为Hex，内存中的ASCII码arrayFromHexString
    QByteArray arrayFromHexString = QByteArray::fromHex(hashed.toHex());
    //qDebug()<<"hmacSha1内存中的ASCII码 arrayFromHexString \n"<<arrayFromHexString.toHex();
    return arrayFromHexString;
}



#ifdef M_ENABLE_FFMPEG
QImage MTL::mYuv420p2rgb24(const uchar * const data[],
                           const int linesize[],
                           int width,
                           int height,
                           AVPixelFormat fmt)
{
    QImage mage;
    int ret=0;
    typedef struct DATA{
        uchar* data[4];
        int lineSize[4];
    }DATA;
    static DATA DATA_obj={NULL};
    static int w=0;
    static int h=0;
    static AVPixelFormat sourceFmt=AV_PIX_FMT_NONE;
    AVPixelFormat targetFmt=AV_PIX_FMT_RGB24;
    static SwsContext *SwsContextObj = NULL;

    if(!data || !linesize || width <=0 || height <= 0)
    {
        goto end;
    }
    if(w != width || h != height || fmt != sourceFmt)
    {
        if(SwsContextObj)
            sws_freeContext(SwsContextObj);
        SwsContextObj = NULL;
    }
    w=width;
    h=height;
    sourceFmt=fmt;
    if(!SwsContextObj)
    {
        SwsContextObj = sws_getContext(w, h, sourceFmt,
                                       w, h, targetFmt,
                                       SWS_BICUBIC,
                                       NULL, NULL, NULL);
        if( !SwsContextObj )
        {
            goto end;
        }
    }
    if(!DATA_obj.data[0])
    {
        ret=av_image_alloc(DATA_obj.data, DATA_obj.lineSize,w, h, targetFmt, 1);
        if(ret < 0)
        {
            goto end;
        }
    }
    ret=sws_scale(SwsContextObj,
                  data,
                  linesize,
                  0,
                  height,
                  DATA_obj.data,
                  DATA_obj.lineSize);
    if(ret <= 0)
    {
        goto end;
    }
    return QImage(DATA_obj.data[0],w,h,QImage::Format_RGB888).copy();
end:
    return mage;
}
#endif //M_ENABLE_FFMPEG

#ifdef M_ENABLE_OPENCV
QImage MTL::mCvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        //  qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        //  qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
#endif //M_ENABLE_OPENCV
/*******************************************************************MKeyBoard:begin**********/
MKeyBoard::MKeyBoard(const QStringList& buttonObjName,
                     QWidget *UIwidget,
                     const QString& toolButtonName_cap,
                     const QString& toolButtonName_del,
                     QObject *parent) :
    QObject(parent)
{
    this->uper=false;
    this->button_cap=toolButtonName_cap;
    this->button_del=toolButtonName_del;
    this->list_buttonName=buttonObjName;
    this->UIwidget=UIwidget;
    bool isRepeat=true;

    foreach (const QString &name, this->list_buttonName) {
        QToolButton *p = this->UIwidget->findChild<QToolButton *>(name);
        if(p){
            p->setAutoRepeat(isRepeat);
            QObject::connect(p,
                             SIGNAL(clicked()),
                             this,
                             SLOT(clicked_slot()),
                             Qt::QueuedConnection);
        }
        p = NULL;
    }
}

MKeyBoard::~MKeyBoard(){}

void MKeyBoard::clicked_slot()
{
    QToolButton* btn = M_SENDER_DYNAMIC_CAST(QToolButton);
    if (btn != NULL)
    {
        if(btn->objectName()==this->button_cap)
        {
            this->uper=!this->uper;
            QRegExp rg("^[a-zA-Z]{1}$");
            foreach (const QString &name, this->list_buttonName) {
                QToolButton *p=this->UIwidget->findChild<QToolButton *>(name);
                if(p){
                    if(rg.exactMatch(p->text())){
                        this->uper ?
                                    p->setText(p->text().toUpper()) :
                                    p->setText(p->text().toLower());
                    }
                }
                p=NULL;
            }
            return;
        }
        if(btn->objectName()==this->button_del)
        {
            QWidget *p=NULL;
            p=this->UIwidget->focusWidget();
            if(NULL == p)return;
            QString strName=p->objectName();
            QString strText="";
            //qDebug()<<strName;
            QLineEdit *pEdit=this->UIwidget->findChild<QLineEdit *>(strName);
            //qDebug()<<__LINE__<<pEdit;
            if(NULL != pEdit && pEdit->text()!="")
            {
                strText=pEdit->text();
                int i=pEdit->cursorPosition();
                int j=pEdit->selectionStart();
                if( j < 0)
                {
                    if(i > 0)
                    {   strText=strText.mid(0,i-1)+strText.mid(i);
                        pEdit->setText(strText);
                        pEdit->setCursorPosition(i-1);
                    }
                }
                else
                {
                    QString strSelection=pEdit->selectedText();
                    if(strSelection.length() > 0)
                    {
                        strText=strText.mid(0,j)+strText.mid(j+strSelection.length());
                        pEdit->setText(strText);
                        pEdit->setCursorPosition(j);
                    }
                }
            }
            return;
        }
        QRegExp rg("^[a-zA-Z0-9_-]{1}$");
        if(rg.exactMatch(btn->text()))
        {
            QString strKey=btn->text();
            QWidget *p=NULL;
            p=this->UIwidget->focusWidget();
            if(NULL == p)return;
            QString strName=p->objectName();
            QString strText="";
            //qDebug()<<strName;
            {
                QLineEdit *pEdit=this->UIwidget->findChild<QLineEdit *>(strName);
                //qDebug()<<__LINE__<<pEdit;
                if(NULL != pEdit)
                {
                    strText=pEdit->text();
                    int i=pEdit->cursorPosition();
                    int j=pEdit->selectionStart();
                    if( j < 0)
                    {
                        if(i >= 0)
                        {
                            pEdit->setText(strText.mid(0,i)+strKey+strText.mid(i));
                            pEdit->setCursorPosition(i+strKey.length());
                        }
                    }
                    else
                    {
                        QString strSelection=pEdit->selectedText();
                        if(strSelection.length() > 0)
                        {
                            pEdit->setText(strText.mid(0,j)+strKey+strText.mid(j+strSelection.length()));
                            pEdit->setCursorPosition(j+strKey.length());
                        }
                    }
                }
            }
            return;
        }
    }

}
/*******************************************************************MLog:begin**********/
MLogger::MLogger( ){}

MLogger::MLogger(const MLogger &other){(void)other;}

MLogger &MLogger::operator =(const MLogger &other)
{
    if(&other != this){
        //do something ...
    }
    return *this;
}

MLogger::~MLogger(){}

QMutex MLogger::mutex;

void MLogger::log(const QString &content, const QString &fileNamePrefix, const QString &path)
{
    if(fileNamePrefix.length() <= 0
            || path.length() <= 0
            || content.length() <= 0) {
        return ;
    }
    if(!QDir(path).exists()){
        if(!QDir().mkpath(path))
            return ;
    }
    QString absolutePath = QDir(path).absolutePath();
    QString today = MTL::get_time_now().mid(0,QString("2016-01-01").length());
    QString logDir = absolutePath + "/" + today;
    //mkdir
    if(!QDir(logDir).exists()){
        if(!QDir().mkpath(logDir))
            return ;
    }
    //target full path
    QString absoluteFilePath = logDir + "/" + fileNamePrefix + "_" + today + ".log";
    QFile file(absoluteFilePath);

    QMutexLocker locker(&mutex);
    (void)locker;
    if(file.open(QIODevice::Append)) {
        file.write(content.toStdString().c_str());
        file.flush();
        file.close();
    }
}

MQThreadLogger::MQThreadLogger(QObject *parent) : QThread(parent)
{
    moveToThread(this);
    start();
}

MQThreadLogger *MQThreadLogger::obj = NULL;

MQThreadLogger *MQThreadLogger::getObj()
{
    return obj ? obj : obj = new MQThreadLogger;
}

void MQThreadLogger::destroyObj()
{
    if(obj && obj->isRunning()){
        obj->terminate();
        obj->wait();
    }
    M_DELETE_TO_NULL(obj);
}

void MQThreadLogger::log(const QString &data, const QString &filename_prefix)
{
    MLogger::log(data,filename_prefix);
}

void MQThreadLogger::run()
{
    try{
        exec();
    }catch(...){
        MDG_WARNING << QString("%1 error happend.").arg(M_CAST_STRING(MQThreadLogger));
    }
}
/*******************************************************************MDatabase:begin**********/
MDatabase::MDatabase(){}

MDatabase::~MDatabase(){}

MDatabase::MDatabase(const MDatabase &){}

MDatabase &MDatabase::operator =(const MDatabase &)
{
    return *this;
}

QMutex MDatabase::mutex;

QMap<QString,
QMap<QString,
QJsonObject
> > MDatabase::map_threadName_connection_json;

QMap<QString,
QSqlDatabase
> MDatabase::map_connection_QSqlDatabase;

QThreadStorage<QPair<QJsonObject,QSqlDatabase>* > MDatabase::buffer;

QSqlDatabase MDatabase::getDatabase(const QString &databaseName,
                                    const QString &type,
                                    const QString &hostName,
                                    int port,
                                    const QString &userName,
                                    const QString &passwd)
{
    QSqlDatabase ret;
    QJsonObject json_file;
    QString databasename = databaseName;
    bool isSqlite = false;
    //check parameter
    if(databasename.length() <= 0){
        return ret;
    }
    //prepare flag
    if(type != "QSQLITE"){
        if(hostName.length() <= 0){
            return ret;
        }
        json_file.insert("HostName",hostName);
        json_file.insert("Port",port);
    }else{
        //mkdir
        QFileInfo info(databasename);
        if(!info.absoluteDir().exists()){
            QDir().mkpath(info.absolutePath());
        }
        databasename = info.absoluteFilePath();
        isSqlite = true;
    }
    json_file.insert("DatabaseName",databasename);
    json_file.insert("Driver",type);
    json_file.insert("UserName",userName);
    json_file.insert("Passwd",passwd);

    //check thread name
    QString threadName = M_CURRENT_THREAD_OBJECT->objectName();
    QString uuid = QUuid::createUuid().toString();
    if(!QRegExp("^\\{[0-9a-f]{8}-([0-9a-f]{4}-){3}[0-9a-f]{12}\\}$").exactMatch(threadName)){
        M_CURRENT_THREAD_OBJECT->setObjectName(uuid);
        threadName = uuid;
    }

    //check it if exist
    bool hasConnection = false;
    QString realConnection;
    //protection
    QMutexLocker locker(&mutex);
    QMap<QString,QJsonObject> map_tmp = map_threadName_connection_json.value(threadName);
    QMap<QString,QJsonObject>::const_iterator it_tmp;
    for(it_tmp = map_tmp.constBegin(); it_tmp != map_tmp.constEnd(); it_tmp++){
        if(it_tmp.value() == json_file){
            hasConnection = true;
            realConnection = it_tmp.key();
            break;
        }
    }
    if(hasConnection){
        //check the database if exist
        if(map_connection_QSqlDatabase.contains(realConnection)){
            ret = map_connection_QSqlDatabase.value(realConnection);
        }else{
            //internal error
            MDG_WARNING << QString("BUG,connection exist,but database object was lost,connection:[%1],parameter:[%2],thread name:[%3]")
                           .arg(realConnection)
                           .arg(MTL::get_str_from_QJsonObject(json_file))
                           .arg(threadName)
                        << "\n"
                        << map_threadName_connection_json
                        << "\n"
                        << map_connection_QSqlDatabase;
        }
    }else{
        //generate new connection
        QList<QString > list_connection = map_threadName_connection_json.value(threadName).keys();
        int number = -1;
        for(int i = 0; i < list_connection.size(); i++){
            int number_tmp = QString(list_connection.at(i)).replace(QRegExp("^*._"),"").toInt();
            if(number_tmp > number){
                number = number_tmp;
            }
        }
        QString newConnectionName = QString("%1_%2").arg(threadName).arg(++number);
        if(map_threadName_connection_json.value(threadName).keys().contains(newConnectionName)){
            //internal error
            MDG_WARNING << QString("BUG,add new connection:[%1],connection already exist,thread name:[%2],parameter:[%3]")
                           .arg(newConnectionName)
                           .arg(threadName)
                           .arg(MTL::get_str_from_QJsonObject(json_file))
                        << "\n"
                        << map_threadName_connection_json
                        << "\n"
                        << map_connection_QSqlDatabase;
        }
        QString str_err;
        register bool opened = false;
        {
            //new connection
            QSqlDatabase db = QSqlDatabase::addDatabase(type,newConnectionName);
            if(!isSqlite){
                db.setHostName(hostName);
                db.setPort(port);
            }
            db.setDatabaseName(databasename);
            db.setUserName(userName);
            db.setPassword(passwd);
            opened = db.open();
            if(opened){
                if(!map_threadName_connection_json.contains(threadName)){
                    //first add
                    QMap<QString ,QJsonObject> list_json;
                    list_json.insert(newConnectionName,json_file);
                    map_threadName_connection_json.insert(threadName,list_json);
                }else{
                    //
                    QMap<QString,QMap<QString ,QJsonObject> >::iterator it;
                    for(it = map_threadName_connection_json.begin(); it != map_threadName_connection_json.end(); it++){
                        if(it.key() == threadName){
                            it.value().insert(newConnectionName,json_file);
                            break;
                        }
                    }
                }
                if(!map_connection_QSqlDatabase.contains(newConnectionName)){
                    map_connection_QSqlDatabase.insert(newConnectionName,db);
                    ret = db;
                }else{
                    //internal error
                    MDG_WARNING << QString("BUG,save connection:[%1],connection already exist,thread name:[%2],parameter:[%3]")
                                   .arg(newConnectionName)
                                   .arg(threadName)
                                   .arg(MTL::get_str_from_QJsonObject(json_file))
                                << "\n"
                                << map_threadName_connection_json
                                << "\n"
                                << map_connection_QSqlDatabase
                                << "\n"
                                << db;
                }
            }else{
                str_err = db.lastError().text();
            }
        }
        //remove it when open failed
        if(!opened){
            QSqlDatabase::removeDatabase(newConnectionName);
            //
            MDG_WARNING << QString("add new connection:[%1],open database failed,err:[%2],thread name:[%3],parameter:[%4]")
                           .arg(newConnectionName)
                           .arg(str_err)
                           .arg(threadName)
                           .arg(MTL::get_str_from_QJsonObject(json_file))
                        << "\n"
                        << map_threadName_connection_json
                        << "\n"
                        << map_connection_QSqlDatabase;
        }
    }
    /*
    MDG << map_threadName_connection_db
        << "\n"
        << map_connection_db;
        */
    return ret;
}

/*********************************************************MDatabaseConnectionPool:begin**********/


MDatabaseInfo::MDatabaseInfo(const QString &databaseName,
                             const QString &type,
                             const QString &userName,
                             const QString &passwd,
                             const QString &hostName,
                             int port)
{
    this->name = databaseName;
    this->type = type;
    this->hostName = hostName;
    this->port = port;
    this->user = userName;
    this->passwd = passwd;
}

MDatabaseInfo::~MDatabaseInfo(){}

MDatabaseInfo::MDatabaseInfo(const MDatabaseInfo &info)
{
    name = info.name;
    type = info.type;
    hostName = info.hostName;
    port = info.port;
    user = info.user;
    passwd = info.passwd;
}

MDatabaseInfo &MDatabaseInfo::operator =(const MDatabaseInfo &info)
{
    if(this != &info){
        name = info.name;
        type = info.type;
        hostName = info.hostName;
        port = info.port;
        user = info.user;
        passwd = info.passwd;
    }
    return *this;
}

bool MDatabaseInfo::operator !=(const MDatabaseInfo &o) const
{
    return ! (*this == o);
}

bool MDatabaseInfo::operator ==(const MDatabaseInfo &o) const
{
    return toString() == o.toString();
}
QString MDatabaseInfo::toString() const
{
    return QString("[%1],[%2],[%3],[%4],[%5],[%6]")
            .arg(name)
            .arg(type)
            .arg(user)
            .arg(passwd)
            .arg(hostName)
            .arg(port);
}

QString MDatabaseInfo::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MDatabaseInfo::toJsonObject() const
{
    QJsonObject json;
    json.insert(M_CAST_STRING(name),name);
    json.insert(M_CAST_STRING(type),type);
    json.insert(M_CAST_STRING(user),user);
    json.insert(M_CAST_STRING(passwd),passwd);
    json.insert(M_CAST_STRING(hostName),hostName);
    json.insert(M_CAST_STRING(port),port);
    return json;
}

MDatabaseInfoWithTimestamp::MDatabaseInfoWithTimestamp(const MDatabaseInfo &info)
{
    this->info = info;
    time_last_access = M_TIME_NOW_MILLISECONDS;
}

MDatabaseInfoWithTimestamp::~MDatabaseInfoWithTimestamp(){}

MDatabaseInfoWithTimestamp::MDatabaseInfoWithTimestamp(const MDatabaseInfoWithTimestamp &o)
{
    info = o.info;
    time_last_access = o.time_last_access;
}

MDatabaseInfoWithTimestamp &MDatabaseInfoWithTimestamp::operator =(const MDatabaseInfoWithTimestamp &o)
{
    if(this != &o){
        info = o.info;
        time_last_access = o.time_last_access;
    }
    return *this;
}

QString MDatabaseInfoWithTimestamp::toString() const
{
    return QString("[%1],[%2]")
            .arg(info.toString())
            .arg(time_last_access);
}

QString MDatabaseInfoWithTimestamp::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MDatabaseInfoWithTimestamp::toJsonObject() const
{
    QJsonObject json;
    json.insert(M_CAST_STRING(info),info.toJsonObject());
    json.insert(M_CAST_STRING(time_last_access),time_last_access);
    return json;
}

MDatabaseConnectionPool::MDatabaseConnectionPool(QObject *p) : QObject(p)
{
    if(!mutex)
        mutex = new QMutex(QMutex::Recursive);
    timer.setParent(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(unused_check_slot()));
    enableConnectionWatcher(false);
}

MDatabaseConnectionPool::~MDatabaseConnectionPool()
{
    timer.stop();
    removeAll(false);
}

QMutex *MDatabaseConnectionPool::mutex = NULL;

QSqlDatabase MDatabaseConnectionPool::getDatabase(const MDatabaseInfo &info)
{
    QMutexLocker lock(mutex);
    //check if exist ...
    ConnectionMap::iterator it = pool.begin();
    for(; it != pool.end(); it++){
        MDatabaseInfoWithTimestamp &ifo = it.value();
        if(ifo.info == info){
            ifo.time_last_access = M_TIME_NOW_MILLISECONDS;
            return QSqlDatabase::database(it.key());
        }
    }
    QString uuid = QUuid::createUuid().toString();
    QSqlDatabase db = QSqlDatabase::addDatabase(info.type,uuid);
    db.setDatabaseName(info.name);
    db.setHostName(info.hostName);
    db.setPort(info.port);
    db.setUserName(info.user);
    db.setPassword(info.passwd);
    db.open();
    pool.insert(uuid,MDatabaseInfoWithTimestamp(info));
    return db;
}

ConnectionMap MDatabaseConnectionPool::getPool() const
{
    QMutexLocker lock(mutex);
    return  pool;
}

void MDatabaseConnectionPool::removeConnection(int timeout_ms, bool sendSignal)
{
    QMutexLocker lock(mutex);
    QList<QPair<QString,MDatabaseInfoWithTimestamp> > list_removed;

    QList<QString > keys = pool.keys();
    foreach (const QString &connectionName, keys) {
        llint time = MTL::time_2_time(pool.value(connectionName).time_last_access, M_TIME_NOW_MILLISECONDS);
        if(time >= timeout_ms){
            M_CLOSE_DATABASE(connectionName)
                    QSqlDatabase::removeDatabase(connectionName);

            list_removed << qMakePair(connectionName,pool.value(connectionName));
            pool.remove(connectionName);
        }
    }
    //
    if(sendSignal)
        sendRemovedSignal(list_removed);
}

void MDatabaseConnectionPool::removeConnection(const MDatabaseInfo &info, bool sendSignal)
{
    QMutexLocker lock(mutex);
    QList<QPair<QString,MDatabaseInfoWithTimestamp> > list_removed;

    QList<QString > keys = pool.keys();
    foreach (const QString &connectionName, keys) {
        if(pool.value(connectionName).info == info){
            M_CLOSE_DATABASE(connectionName)
                    QSqlDatabase::removeDatabase(connectionName);

            list_removed << qMakePair(connectionName,pool.value(connectionName));
            pool.remove(connectionName);
            return ;
        }
    }
    //
    if(sendSignal)
        sendRemovedSignal(list_removed);
}

void MDatabaseConnectionPool::removeAll(bool sendSignal)
{
    QMutexLocker lock(mutex);
    QList<QPair<QString,MDatabaseInfoWithTimestamp> > list_removed;

    ConnectionMap::ConstIterator it = pool.constBegin();
    for(; it != pool.constEnd(); it++){
        M_CLOSE_DATABASE(it.key())
                QSqlDatabase::removeDatabase(it.key());
        list_removed << qMakePair(it.key(),it.value());
    }
    pool.clear();
    //
    if(sendSignal)
        sendRemovedSignal(list_removed);
}

void MDatabaseConnectionPool::enableConnectionWatcher(bool yes, int time_unused_ms)
{
    timer.stop();
    if(yes){
        timer.start(time_unused_ms);
    }
}

void MDatabaseConnectionPool::unused_check_slot()
{
    removeConnection(timer.interval(),true);
}

void MDatabaseConnectionPool::sendRemovedSignal(const QList<QPair<QString, MDatabaseInfoWithTimestamp> > &s)
{
    for(QList<QPair<QString, MDatabaseInfoWithTimestamp> >::ConstIterator it = s.constBegin();
        it != s.constEnd();
        it++){
        emit removed((*it).first,(*it).second);
    }
}

MApplicationDatabaseConnectionPool::MApplicationDatabaseConnectionPool(QObject *p) : QObject(p)
{
    mutex = new QMutex(QMutex::Recursive);
    timer_unused_check.setParent(this);
    connect(&timer_unused_check,
            SIGNAL(timeout()),
            this,
            SLOT(timeout_timer_unused_check_slot()),
            M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
    enableConnectionWatcher(false);
}

MApplicationDatabaseConnectionPool::~MApplicationDatabaseConnectionPool()
{
    timer_unused_check.stop();
    removeAll(false);
    M_DELETE_TO_NULL(mutex);
}

QSqlDatabase MApplicationDatabaseConnectionPool::getDatabase(const MDatabaseInfo &info)
{
    QMutexLocker locker(mutex);
    QThread *currentThread = QThread::currentThread();
    for(ConnectionMap2::iterator it = pool.begin(); it != pool.end(); it++){
        //find exist ...
        if(it.key() == currentThread){
            ConnectionMap &map = it.value();
            for(ConnectionMap::iterator i = map.begin(); i != map.end(); i++){
                if(i.value().info == info){
                    i.value().time_last_access = M_TIME_NOW_MILLISECONDS;
                    return QSqlDatabase::database(i.key());
                }
            }
        }
    }
    //create new ...
    QString uuid = QUuid::createUuid().toString();
    QSqlDatabase db = QSqlDatabase::addDatabase(info.type,uuid);
    db.setDatabaseName(info.name);
    db.setHostName(info.hostName);
    db.setPassword(info.passwd);
    db.setPort(info.port);
    db.setUserName(info.user);
    db.open();
    for(ConnectionMap2::iterator it = pool.begin(); it != pool.end(); it++){
        if(it.key() == currentThread){
            ConnectionMap &map = it.value();
            map.insert(uuid,MDatabaseInfoWithTimestamp(info));
            return db;
        }
    }
    ConnectionMap map;
    map.insert(uuid,MDatabaseInfoWithTimestamp(info));
    pool.insert(currentThread,map);
    /*
     * keep in mind :
     *
     * signal and slot may exec in different thread,
     * in that case, slot will exec after signal !!!
     *
     * BUG example :
     *
     *  QThread *th = new QThread;
     *  ...
     *  delete th;
     *  th = new QThread;
     *  call getDatabase() in th thread;
     *
     * now that :
     *
     *  The QSqlDatabase you have got may belong to first thread,
     *  and it can not be used in second thread.
     *
     *  When control returns to event loop,the slot will be invoked,
     *  and will clear the first and second connection.
     *
     *  The two QThread* may be equal for high probability,cause memory is reusable.
     *
     * suggestion :
     *
     *  Do NOT new immediately after delete !
     *
     * */
    connect(currentThread,
            //This signal is emitted immediately before the object obj is destroyed, and can not be blocked.
            SIGNAL(destroyed(QObject*)),
            this,
            SLOT(destroyed_slot(QObject*))
            );
    return db;
}

const ConnectionMap2 &MApplicationDatabaseConnectionPool::getPool() const
{
    QMutexLocker locker(mutex);
    return  pool;
}

void MApplicationDatabaseConnectionPool::removeAll(bool sendSignal)
{
    QMutexLocker locker(mutex);
    //prepare signal
    QList<QPair<QThread *,MDatabaseInfoWithTimestamp> > list_removed;

    for(ConnectionMap2::ConstIterator it = pool.constBegin(); it != pool.constEnd(); it++){
        ConnectionMap map = it.value();
        for(ConnectionMap::ConstIterator i = map.constBegin(); i != map.constEnd(); i++){
            M_CLOSE_DATABASE(i.key())
                    QSqlDatabase::removeDatabase(i.key());
            //
            list_removed << qMakePair(it.key(),i.value());
        }
    }
    pool.clear();
    //send signal
    if(sendSignal)
        sendRemovedSignal(list_removed);
}

QString MApplicationDatabaseConnectionPool::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MApplicationDatabaseConnectionPool::toJsonObject() const
{
    QMutexLocker locker(mutex);
    QJsonObject ret;
    for(ConnectionMap2::ConstIterator it = pool.constBegin(); it != pool.constEnd(); it++){
        QThread *pp = it.key();
        QString thread = MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)pp);
        QJsonObject tmp_json;
        ConnectionMap tmp = it.value();
        for(ConnectionMap::ConstIterator i = tmp.constBegin(); i != tmp.constEnd(); i++){
            tmp_json.insert(i.key(),i.value().toString());
        }
        ret.insert(thread,tmp_json);
    }
    return ret;
}

void MApplicationDatabaseConnectionPool::removeConnection(const QThread *thread,bool sendSignal)
{
    //remove it`s all connections

    if(!thread)
        return ;
    QMutexLocker locker(mutex);
    //prepare signal
    QList<QPair<QThread *,MDatabaseInfoWithTimestamp> > list_removed;

    QThread *target = NULL;
    for(ConnectionMap2::ConstIterator it = pool.constBegin();  it != pool.constEnd(); it++){
        if(it.key() == thread){
            target = it.key();
            ConnectionMap map_connection = it.value();
            for(ConnectionMap::ConstIterator i = map_connection.constBegin(); i != map_connection.constEnd(); i++){
                M_CLOSE_DATABASE(i.key())
                        QSqlDatabase::removeDatabase(i.key());
                list_removed << qMakePair((QThread *)thread,i.value());
            }
        }
    }
    if(target){
        pool.remove(target);
    }
    //send signal
    if(sendSignal)
        sendRemovedSignal(list_removed);
}

void MApplicationDatabaseConnectionPool::removeConnection(const MDatabaseInfo &info,bool sendSignal)
{
    QMutexLocker locker(mutex);
    //prepare signal
    QList<QPair<QThread *,MDatabaseInfoWithTimestamp> > list_removed;

    for(ConnectionMap2::iterator it = pool.begin(); it != pool.end(); it++){
        ConnectionMap &map_connection = it.value();
        QList<QString> list_connection = map_connection.keys();
        foreach (const QString &connection, list_connection) {
            MDatabaseInfoWithTimestamp ifo = map_connection.value(connection);
            if(ifo.info == info){
                M_CLOSE_DATABASE(connection)
                        QSqlDatabase::removeDatabase(connection);
                map_connection.remove(connection);
                //
                list_removed << qMakePair(it.key(),ifo);
            }
        }
    }
    clearEmptyItem();
    //send signal
    if(sendSignal)
        sendRemovedSignal(list_removed);
}
void MApplicationDatabaseConnectionPool::removeConnection(int time_unused_ms,bool sendSignal)
{
    QMutexLocker locker(mutex);
    //prepare signal
    QList<QPair<QThread *,MDatabaseInfoWithTimestamp> > list_removed;

    for(ConnectionMap2::iterator it = pool.begin(); it != pool.end(); it++){
        ConnectionMap &map_connection = it.value();
        QList<QString> list_connection = map_connection.keys();
        foreach (const QString &connection, list_connection) {
            MDatabaseInfoWithTimestamp ifo = map_connection.value(connection);
            if(MTL::time_2_time(ifo.time_last_access, M_TIME_NOW_MILLISECONDS) >= time_unused_ms ){
                M_CLOSE_DATABASE(connection)
                        QSqlDatabase::removeDatabase(connection);
                map_connection.remove(connection);
                //
                list_removed << qMakePair(it.key(),ifo);
            }
        }
    }
    clearEmptyItem();
    //send signal
    if(sendSignal)
        sendRemovedSignal(list_removed);
}

void MApplicationDatabaseConnectionPool::enableConnectionWatcher(bool yes, int time_unused_ms)
{
    timer_unused_check.stop();
    if(yes){
        timer_unused_check.setInterval(time_unused_ms);
        timer_unused_check.start();
    }
}

void MApplicationDatabaseConnectionPool::destroyed_slot(QObject *obj)
{
    removeConnection(static_cast<QThread *>(obj),true);
}

void MApplicationDatabaseConnectionPool::timeout_timer_unused_check_slot()
{
    removeConnection(timer_unused_check.interval(),true);
}

void MApplicationDatabaseConnectionPool::sendRemovedSignal(const QList<QPair<QThread *, MDatabaseInfoWithTimestamp> > &r)
{
    for(QList<QPair<QThread *,MDatabaseInfoWithTimestamp> >::ConstIterator it = r.constBegin();
        it != r.constEnd();
        it++){
        emit removed((*it).first,(*it).second);
    }
}

void MApplicationDatabaseConnectionPool::clearEmptyItem()
{
    QList<QThread * > thread = pool.keys();
    foreach (QThread * td, thread) {
        if(pool.value(td).size() <= 0){
            pool.remove(td);
        }
    }
}

MScopedDatabase::MScopedDatabase(const MDatabaseInfo &info)
{
    if(!mutex)
        mutex = new QMutex(QMutex::Recursive);
    QMutexLocker lock(mutex);

    QString uuid = QUuid::createUuid().toString();
    QSqlDatabase db = QSqlDatabase::addDatabase(info.type,uuid);
    db.setDatabaseName(info.name);
    db.setHostName(info.hostName);
    db.setPassword(info.passwd);
    if (info.port > 0)
        db.setPort(info.port);
    db.setUserName(info.user);
    db.open();

    connectionName = uuid;
    dbInfo = info;
}

QMutex * MScopedDatabase::mutex = NULL;

MScopedDatabase::~MScopedDatabase()
{
    QMutexLocker lock(mutex);
    M_CLOSE_DATABASE(connectionName)
            QSqlDatabase::removeDatabase(connectionName);
}

QSqlDatabase MScopedDatabase::getDatabase() const
{
    QMutexLocker lock(mutex);
    return QSqlDatabase::database(connectionName);
}

MDatabaseInfo MScopedDatabase::getDatabaseInfo() const
{
    return dbInfo;
}
/***************************************************** MKit:MTran ***/
MTran::MTran(QSqlDatabase *d)
{
    db = d;
    transform = false;
    begin();
}

MTran::~MTran()
{
    rollback();
}

void MTran::begin()
{
    if(!transform){
        if(!db->transaction())
            MDG_WARNING << db->lastError().text();
        transform = true;
    }
}

void MTran::commit()
{
    if(transform){
        if(!db->commit())
            MDG_WARNING << db->lastError().text();
        transform = false;
    }
}

void MTran::rollback()
{
    if(transform){
        if(!db->rollback())
            MDG_WARNING << db->lastError().text();
        transform = false;
    }
}

/*******************************************************************MError:begin**********/
MMarkedInfo::MMarkedInfo()
{
    clear();
}

MMarkedInfo::MMarkedInfo(const QDateTime &time,
                         const QString &line,
                         const QString &file,
                         const QString &func,
                         const QString &compileTime,
                         const QThread *threadPointer,
                         const QString &threadName)
{
    this->time = time;
    this->line = line;
    this->file = file;
    this->func = func;
    this->compileTime = compileTime;
    this->threadPointer = threadPointer;
    this->threadName = threadName;
}

MMarkedInfo::MMarkedInfo(const MMarkedInfo &other)
{
    time = other.time;
    line = other.line;
    file = other.file;
    func = other.func;
    compileTime = other.compileTime;
    threadPointer = other.threadPointer;
    threadName = other.threadName;
}

MMarkedInfo::~MMarkedInfo(){  }

MMarkedInfo &MMarkedInfo::operator =(const MMarkedInfo &other)
{
    if(this != &other){
        time = other.time;
        line = other.line;
        file = other.file;
        func = other.func;
        compileTime = other.compileTime;
        threadPointer = other.threadPointer;
        threadName = other.threadName;
    }
    return *this;
}

QString MMarkedInfo::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MMarkedInfo::toJsonObject() const
{
    QJsonObject ret;
    ret.insert(M_CAST_STRING(time),time.toString(M_TIME_FORMAT_WITH_MILLISECONDS));
    ret.insert(M_CAST_STRING(line),line);
    ret.insert(M_CAST_STRING(file),file);
    ret.insert(M_CAST_STRING(func),func);
    ret.insert(M_CAST_STRING(compileTime),compileTime);
    ret.insert(M_CAST_STRING(threadPointer),"0x" + MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)threadPointer));
    ret.insert(M_CAST_STRING(threadName),threadName);
    return ret;
}

void MMarkedInfo::clear()
{
    time = QDateTime();
    line = "";
    file = "";
    func = "";
    compileTime = "";
    threadPointer = NULL;
    threadName = "";
}

MMarkedData::MMarkedData(const QJsonValue &data, const MMarkedInfo &info)
{
    this->data = data;
    this->info = info;
}

MMarkedData::MMarkedData(const MMarkedData &other)
{
    data = other.data;
    info = other.info;
}

MMarkedData::~MMarkedData(){ }

MMarkedData &MMarkedData::operator =(const MMarkedData &other)
{
    if(this != &other){
        data = other.data;
        info = other.info;
    }
    return *this;
}

QString MMarkedData::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MMarkedData::toJsonObject() const
{
    QJsonObject ret;
    ret.insert(M_CAST_STRING(data),data);
    ret.insert(M_CAST_STRING(info),info.toJsonObject());
    return ret;
}

void MMarkedData::clear()
{
    data = "";
    info.clear();
}


MError::MError(){  }

MError::MError(const MError &other){  errorData = other.errorData; }

MError::~MError(){}

MError &MError::operator =(const MError &other)
{
    if(this != &other){
        errorData = other.errorData;
    }
    return *this;
}

MMarkedData MError::getError() const
{
    return errorData;
}

bool MError::clearError(bool v)
{
    if(v)
        errorData.clear();
    return v;
}

/*******************************************************************MExpection:begin**********/
MExpection::MExpection(){}

MExpection::~MExpection(){}

MExpection::MExpection(const QString & time,
                       const QString &compiletime,
                       const QString &line,
                       const QString &file,
                       const QString &func,
                       const QString &threadId,
                       const QString &threadName,
                       const QString &str)
{
    this->time = time;
    this->compileTime = compiletime;
    this->line = line;
    this->file = file;
    this->func = func;
    this->threadId = threadId;
    this->threadName = threadName;
    this->text = str;
}

MExpection::MExpection(const MExpection &other)
{
    time = other.time;
    compileTime = other.compileTime;
    line = other.line;
    file = other.file;
    func = other.func;
    threadId = other.threadId;
    threadName = other.threadName;
    text = other.text;
}

MExpection &MExpection::operator=(const MExpection &other)
{
    if(this != &other){
        time = other.time;
        compileTime = other.compileTime;
        line = other.line;
        file = other.file;
        func = other.func;
        threadId = other.threadId;
        threadName = other.threadName;
        text = other.text;
    }
    return *this;
}

QString MExpection::toString() const
{
    return QString("%1[%2]")
            .arg(getAddr())
            .arg(text);
}

QString MExpection::toJsonString(QJsonDocument::JsonFormat f) const
{
    QJsonObject json;
    json.insert(M_CAST_STRING(time),time);
    json.insert(M_CAST_STRING(compileTime),compileTime);
    json.insert(M_CAST_STRING(line),line);
    json.insert(M_CAST_STRING(file),file);
    json.insert(M_CAST_STRING(func),func);
    json.insert(M_CAST_STRING(threadId),threadId);
    json.insert(M_CAST_STRING(threadName),threadName);
    json.insert(M_CAST_STRING(text),text);
    return MTL::get_str_from_QJsonObject(json,f);
}

QString MExpection::getAddr() const
{
    return QString("[%1][%2][%3][%4][%5][%6][%7]")
            .arg(time)
            .arg(compileTime)
            .arg(line)
            .arg(file)
            .arg(func)
            .arg(threadId)
            .arg(threadName);
}

QString MExpection::getText() const
{
    return text;
}
/*******************************************************************MLoad:begin**********/
MLoad::MLoad(QObject *parent) : QObject(parent)
{
    reply = NULL;
    filePathFull = "";
    timerEnabled = true;
    interval = 1000 * 60 * 5;
    timeout = false;
    timerid = 0;
}

MLoad::~MLoad()
{
    mAbort();
}

bool MLoad::mIsTimerRunning()
{
    return timerid > 0 ;
}

bool MLoad::mLoad(const QString &url,
                  const QByteArray &data,
                  const QString &filePathFull)
{
    if(url.length()<=0||
            filePathFull.length()<=0)return false;
    QDir().mkpath(QFileInfo(QFile(filePathFull)).absolutePath());

    QNetworkRequest req;
    req.setUrl(QUrl(url));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json;charset=utf-8");
    if(this->reply){
        disconnect(this->reply, 0, this, 0);
        this->reply->abort();
        this->reply->deleteLater();
        this->reply=NULL;
    }
    this->reply=manager.post(req,data);
    if(!this->reply){
        return false;
    }
    this->url=url;
    this->filePathFull=filePathFull;
    this->data=data;
    this->timeout=false;
#if MDBG
    MDG<<this->reply;
#endif
#if MDBG
    MDG<<
      #endif
          connect(this->reply,
                  SIGNAL(readyRead()),
                  this,
                  SLOT(readyRead_slot()),
                  M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
#if MDBG
    MDG<<
      #endif
          connect(this->reply,
                  SIGNAL(finished()),
                  this,
                  SLOT(finished_slot()),
                  M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
    if(this->timerid)
    {
        this->killTimer(this->timerid);
        this->timerid=0;
    }
    this->timerid=this->startTimer(this->interval);
    return true;
}

bool MLoad::mReLoad()
{
    return this->mLoad(this->url,this->data,this->filePathFull);
}

void MLoad::readyRead_slot()
{
    if(! this->reply )return ;
    if(this->reply->error())return;
    if(this->filePathFull.length()<1)return ;

    QFile f;
    f.setFileName(this->filePathFull);
    if(! f.open(QIODevice::Append))return;

    QByteArray rec;
    if(this->reply->isReadable())
    {
        rec=this->reply->readAll();
    }
    f.write(rec,rec.size());
    f.flush();
    f.close();
}

void MLoad::finished_slot()
{
    if(!this->reply)return ;

    QList<QPair<QByteArray,QByteArray> > header;
    QNetworkReply::NetworkError error=QNetworkReply::NoError;
    QUrl url=this->reply->url();
    error=this->reply->error();
    header=this->reply->rawHeaderPairs();

    this->reply->deleteLater();
    this->reply=NULL;
    if(this->timerid)
    {
        this->killTimer(this->timerid);
        this->timerid=0;
    }
    emit this->mFinished(url,
                         header,
                         this->timeout,
                         error,
                         QString().append(this->filePathFull),
                         QFile(this->filePathFull).size());
}

void MLoad::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == this->timerid && this->timerEnabled)
    {
        this->killTimer(this->timerid);
        this->timerid = 0;
        this->timeout = true;
        if(this->reply)
        {
            this->reply->abort();
        }
    }
}
bool MLoad::mIsDownloading(){
    return this->reply ? this->reply->isRunning() : false;
}

QByteArray MLoad::mGetPostedData()
{
    return this->data;
}
QString MLoad::mGetDownloadingFile(){
    return this->filePathFull;
}
QString MLoad::mGetPostedUrl(){
    return this->url;
}

void MLoad::mAbort()
{
    if(timerid)
    {
        killTimer(this->timerid);
        timerid=0;
    }
    if(reply)
    {
        disconnect(this->reply, 0, this, 0);
        abort();
        reply->deleteLater();
        this->reply=NULL;
    }
    this->timeout=false;
}

void MLoad::mSetTimerInterval(int i)
{
    this->interval=i;
}

void MLoad::mSetTimerEnabled(bool enable)
{
    this->timerEnabled=enable;
}
/*******************************************************************MMedia:begin**********/
MMedia::MMedia(QObject *parent) :QObject(parent)
{
    playList = NULL;
    player = NULL;
    videoWidget = NULL;
    isWarning = false;
}

MMedia* MMedia::obj = NULL;

MMedia* MMedia::getObj()
{
    return obj ? obj : obj = new MMedia();
}

MMedia::~MMedia()
{
    M_DELETE_TO_NULL(player);
    M_DELETE_TO_NULL(playList);
    M_DELETE_TO_NULL(videoWidget);
}
bool MMedia::play(const QStringList& sound_file,bool newWarning)
{
    bool playORnot = false;

    if(player &&
            (player->state() == QMediaPlayer::PlayingState
             ||player->state() == QMediaPlayer::PausedState)){
        if(!isWarning) {
            playORnot = true;
        } else {
            if(newWarning)
                playORnot = true;
        }
    } else  {
        playORnot = true;
    }
    if(!playORnot) {
        return false;
    } else  {
        isWarning = newWarning;
    }

    if(!player)
        player = new QMediaPlayer;

    if(player->state() == QMediaPlayer::PlayingState
            || player->state() == QMediaPlayer::PausedState) {
        player->stop();
    }

    M_DELETE_TO_NULL(playList);
    playList = new QMediaPlaylist;
    list_current_playing_file = sound_file;
    foreach (const QString &file, sound_file) {
        if(QFile::exists(file))
            playList->addMedia(QUrl::fromLocalFile(file));
    }

    playList->setCurrentIndex(1 - 1);
    player->setPlaylist(playList);
    player->play();
    return true;
}
void MMedia::stop()
{
    if(player){
        player->stop();
    }
}
void MMedia::pause()
{
    if(player){
        player->pause();
    }
}
void MMedia::resume()
{
    if(player){
        player->play();
    }
}
/*******************************************************************MMultiMediaWidget:begin**********/
MMultiMediaWidget::MMultiMediaWidget(QWidget *parent,MediaType TYPE) : QWidget(parent)
{
    this->label_pic = new QLabel;
    this->movie_pic = new QMovie;
    this->layOut = new QVBoxLayout;
    this->player = new QMediaPlayer;
    this->VideoWidget = new QVideoWidget;
    this->playList = new QMediaPlaylist;

    this->setLayout(this->layOut);
    this->layOut->setSpacing(0);
    this->layOut->setMargin(0);

    this->layOut->addWidget(this->label_pic);
    this->layOut->addWidget(this->VideoWidget);
    this->label_pic->setMovie(this->movie_pic);

    this->player->setVideoOutput(this->VideoWidget);
    this->player->setPlaylist(this->playList);

    this->setMediaType(TYPE);
}
void MMultiMediaWidget::mouseReleaseEvent(QMouseEvent *e)
{
    (void)e;
    emit this->mouseReleased();
}

void MMultiMediaWidget::chooseType(MediaType t)
{
    switch(t)
    {
    case MMultiMediaWidget::Animation:
        if(this->label_pic)        this->label_pic->setVisible(true);
        if(this->VideoWidget)      this->VideoWidget->setVisible(false);
        if(this->player)           this->player->stop();
        break;
    case MMultiMediaWidget::Video:
        if(this->label_pic)        this->label_pic->setVisible(false);
        if(this->VideoWidget)      this->VideoWidget->setVisible(true);
        if(this->movie_pic)        this->movie_pic->stop();
        break;
    default:
        MDG_WARNING << QString("unknow media type:[%1]").arg(t);
        break;
    }
}
QVBoxLayout *MMultiMediaWidget::vboxLayout()
{
    return this->layOut;
}
QLabel *MMultiMediaWidget::label()
{
    return this->label_pic;
}
QMovie *MMultiMediaWidget::movie()
{
    return this->movie_pic;
}
QVideoWidget *MMultiMediaWidget::videoWidget()
{
    return this->VideoWidget;
}
QMediaPlayer *MMultiMediaWidget::mediaPlayer()
{
    return this->player;
}
QMediaPlaylist *MMultiMediaWidget::mediaPlaylist()
{
    return this->playList;
}
void MMultiMediaWidget::setMediaType(MediaType t)
{
    this->type = t;
    this->chooseType(this->type);
}
MMultiMediaWidget::MediaType MMultiMediaWidget::mediaType()
{
    return this->type;
}
MMultiMediaWidget::~MMultiMediaWidget()
{
    M_DELETE_TO_NULL(this->label_pic);
    M_DELETE_TO_NULL(this->movie_pic);
    M_DELETE_TO_NULL(this->layOut);
    M_DELETE_TO_NULL(this->player);
    M_DELETE_TO_NULL(this->VideoWidget);
    M_DELETE_TO_NULL(this->playList);
#if MDBG
    MDG;
#endif
}
/*******************************************************************MPictureWidget:begin**********/
MPictureWidget::MPictureWidget(QWidget *parent) : QWidget(parent)
{
    model = Qt::IgnoreAspectRatio;
}

const QImage &MPictureWidget::picture() const
{
    return image_pic;
}

Qt::AspectRatioMode MPictureWidget::aspectRatioMode() const
{
    return model;
}

void MPictureWidget::setAspectRatioMode(Qt::AspectRatioMode s)
{
    Qt::AspectRatioMode oldStyle = this->model;
    model = s;
    if(model != oldStyle) {
        emit aspectRatioModeChanged(model);
    }
    update();
}

void MPictureWidget::setPicture(const QImage &p)
{
    image_pic = p;
    emit pictureChanged(this->image_pic);
    update();
}

void MPictureWidget::paintEvent(QPaintEvent *e)
{
    (void)e;
    if(!image_pic.isNull()){
        QPainter p(this);
        QImage tmp = image_pic.scaled(width(),height(),model);
        //align H,V center
        p.drawImage((width() - tmp.width()) / 2,(height() - tmp.height()) / 2,tmp);
    }
    return ;
}

void MPictureWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    (void)e;
    emit doubleClicked();
}

/******************************************************** MKit:MScopedCaller ***/
MScopedCaller::MScopedCaller(MCallback fun, void *param, MScopedCaller::CallerType t)
{
    this->fun = fun;
    this->param = param;
    this->type = t;
}

MScopedCaller::~MScopedCaller()
{
    if(type == MScopedCaller::Destroy){
        void **p = (void **)param;
        /*
         * Check, because some SDK provider didn`t check NULL pointer.
         * */
        if(fun && p && *p){
            /*
             * This may crash if give it a NULL.
             * */
            (*fun)(*p);
        }
    }else if(type == MScopedCaller::Normal){
        if(fun){
            /*
             * param can be NULL.
             * */
            (*fun)(param);
        }
    }
}
/*******************************************************************MPost:begin**********/
MHttp::MHttp(QObject *parent) : QObject(parent)
{
    this->timeout = false;
    this->timerid = 0;
    this->reply = NULL;
    this->setTimeout();
    connect(&this->manager,
            SIGNAL(finished(QNetworkReply*)),
            this,
            SLOT(finished_slot(QNetworkReply*)));
}

MHttp::~MHttp()
{
    if(this->reply){
        this->reply->deleteLater();
    }
    this->killTimer();
}

bool MHttp::post(const QString & url,
                 const QByteArray & data)
{
    QNetworkRequest req;
    req.setUrl(QUrl(url));
    req.setHeader(QNetworkRequest::ContentTypeHeader,
                  "application/json;charset=utf-8");
    return this->post(req,data);
}

bool MHttp::post(const QNetworkRequest &r, const QByteArray &data)
{
    if(r.url().isValid()){
        this->data = data;
        this->req = r;

        this->reply = this->manager.post(this->req,this->data);
        if(this->reply){
            this->MHttp::startTimer(this->interval);
            this->timeout = false;
            return true;
        }
    }
    return false;
}

bool MHttp::get(const QNetworkRequest &r)
{
    if(r.url().isValid()){
        this->req = r;

        this->reply = this->manager.get(r);
        if(this->reply){
            this->MHttp::startTimer(this->interval);
            this->timeout = false;
            return true;
        }
    }
    return false;
}
void MHttp::finished_slot(QNetworkReply *r)
{
    if(r == this->reply){
        this->killTimer();
        QByteArray rec;
        QList<QPair<QByteArray, QByteArray> > header;
        QNetworkReply::NetworkError err = QNetworkReply::NoError;
        QUrl url = r->url();
        if(r->isReadable()){
            rec = r->readAll();
        }else{
            MDG_WARNING << "HTTP respond is not readable!"
                        << r
                        << r->errorString();
        }
        header = r->rawHeaderPairs();
        err = r->error();
        r->deleteLater();
        this->reply = NULL;

        emit this->finished(url,header,rec,this->timeout,err);
    } else {
        MDG_WARNING << QString("HTTP respond handle error!")
                    << r
                    << "!="
                    << this->reply;
        r->deleteLater();
    }
}
void MHttp::abort()
{
    this->timeout = false;
    this->killTimer();
    if(this->reply){
        QNetworkReply *tmp = this->reply;
        this->reply = NULL;
        tmp->abort();
    }
}
void MHttp::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == this->timerid){
        this->killTimer();
        this->timeout = true;
        if(this->reply){
            this->reply->abort();
        }
    }
}

void MHttp::killTimer()
{
    if(this->timerid){
        this->QObject::killTimer(this->timerid);
        this->timerid = 0;
    }
}

void MHttp::startTimer(int interval)
{
    this->killTimer();
    this->timerid = this->QObject::startTimer(interval);
}
void MHttp::setTimeout(int interval)
{
    this->interval = interval;
}

QNetworkRequest MHttp::lastRequest() const
{
    return this->req;
}

QByteArray MHttp::lastPostedData() const
{
    return this->data;
}

bool MHttp::isFinished() const
{
    return this->reply ? this->reply->isFinished() : true;
}

/*******************************************************************MHttpHandler:begin**********/

MHttpHandler::MHttpHandler(QNetworkAccessManager *m, QObject *parent) : QObject(parent)
{
    manager = m;
    manager->setParent(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished_slot(QNetworkReply *)));
}

MHttpHandler::~MHttpHandler()
{
    QMap<QNetworkReply *,MHttpRequestData *>::iterator it = map.begin();
    for(; it != map.end(); it++){
        if(it.key())
            it.key()->deleteLater();
        if(it.value() && it.value()->timer)
            delete it.value()->timer;
        delete it.value();
    }
    map.clear();
    /*
     * When delete,it will NOT emit signal such as manager.finished(QNetworkReply*),
     * so,there is no need to
     *
     *     disconnect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished_slot(QNetworkReply*))).
     *
     * This feature has been tested.
     * */
    delete manager;
}

QJsonObject MHttpDataPackage::toJsonObject() const
{
    QJsonObject json;
    json.insert(M_CAST_STRING(req),req.toJsonObject());
    json.insert(M_CAST_STRING(replyHeaders),MTL::get_str_json_array_from_QListQPair(replyHeaders));
    json.insert(M_CAST_STRING(inData),inData.data());
    json.insert(M_CAST_STRING(error),error);
    return json;
}

QString MHttpDataPackage::toJsonStr(QJsonDocument::JsonFormat format) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),format);
}

bool MHttpHandler::post(const QNetworkRequest &req, const QByteArray &data, int timeout_ms)
{
    return createReply(req,data,timeout_ms,QNetworkAccessManager::PostOperation);
}

bool MHttpHandler::get(const QNetworkRequest &req, int timeout_ms)
{
    return createReply(req,QByteArray(),timeout_ms,QNetworkAccessManager::GetOperation);
}

MHttpDataPackage MHttpHandler::getLastResponse() const{    return lastResponse;}

bool MHttpHandler::createReply(const QNetworkRequest &req, const QByteArray &data, int timeout_ms,QNetworkAccessManager::Operation op)
{
    bool exist = false;
    QNetworkReply *reply = NULL;
    MHttpRequestData *reqdata = new MHttpRequestData();
    if(!reqdata)
        goto end;
    reqdata->createTime = M_TIME_NOW_MILLISECONDS;
    reqdata->uuid = QUuid::createUuid().toString();
    reqdata->data = data;
    reqdata->req = req;
    reqdata->timeout = timeout_ms;
    reqdata->timer = NULL;
    reqdata->operation = op;
    //
    if(timeout_ms > 0){
        QTimer *timer = new QTimer;
        if(!timer)
            goto end2;
        timer->setSingleShot(true);
        connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
        timer->start(timeout_ms);
        reqdata->timer = timer;
    }
    //Operation { HeadOperation, GetOperation, PutOperation, PostOperation, DeleteOperation, CustomOperation }
    switch (op) {
    case QNetworkAccessManager::HeadOperation:
        reply = manager->head(req);
        break;
    case QNetworkAccessManager::GetOperation:
        reply = manager->get(req);
        break;
    case QNetworkAccessManager::PutOperation:
        reply = manager->put(req,data);
        break;
    case QNetworkAccessManager::PostOperation:
        reply = manager->post(req,data);
        break;
    case QNetworkAccessManager::DeleteOperation:
        reply = manager->deleteResource(req);
        break;
    case QNetworkAccessManager::CustomOperation:
        reply = manager->sendCustomRequest(req,data);
        break;
    default:
        reply = NULL;
        break;
    }
    if(!reply)
        goto end3;
    //check if already exist
    //normally, this situation could not be possible
    for(QMap<QNetworkReply *,MHttpRequestData *>::iterator it = map.begin();
        it != map.end();   it++){
        if(it.key() == reply){
            exist = true;
            if(it.value() && it.value()->timer)
                delete it.value()->timer;
            delete it.value();
            break;
        }
    }
    if(exist)
        map.remove(reply);
    //bind the request and the reply
    map.insert(reply,reqdata);
    return true;
end3:
    delete reqdata->timer;
end2:
    delete reqdata;
end:
    return false;
}

void MHttpHandler::finished_slot(QNetworkReply *reply)
{
    if(!reply)
        return ;
    MHttpDataPackage response;
    MHttpRequestData reqdata;
    ListPairByteArray headers;
    QByteArray data;
    QNetworkReply::NetworkError err = (QNetworkReply::NetworkError)-1;
    /*
     * find the request data.
     * */
    MHttpRequestData *req = map.value(reply);
    if(req){
        reqdata = *req;
        delete req->timer;
    }else{
        MDG_WARNING << QString("BUG,MQNetworkRequestData* lost,QNetworkReply* is:[%1]")
                       .arg(MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)reply));
    }
    delete req;

    /*
     * read data.
     * */
    headers << reply->rawHeaderPairs();
    if(reply->isReadable())
        data = reply->readAll();
    err = reply->error();
    map.remove(reply);

    reply->deleteLater();
    /*
     * Save parameter.
     * */
    response.req = reqdata;
    response.replyHeaders = headers;
    response.inData = data;
    response.error = err;
    lastResponse = response;
    emit finished(reqdata,headers,data,err);
    emit finished2(response);
    emit finished3();
}

void MHttpHandler::timeout_slot()
{
    QTimer *timer = dynamic_cast<QTimer *>(sender());
    if(timer){
        QMap<QNetworkReply *,MHttpRequestData *>::iterator it = map.begin();
        /*
         * find the reply which the timer binding.
         * */
        for(; it != map.end(); it++){
            if(it.value() && it.value()->timer == timer && it.key()){
                //just close the reply
                //do not delete any thing !
                it.key()->abort();
                break;
            }
        }
    }
}

MHttpRequestData::MHttpRequestData()
{
    timer = NULL;
    timeout = 0;
    operation = (QNetworkAccessManager::Operation)-1;
}

MHttpRequestData::MHttpRequestData(const MHttpRequestData &other)
{
    req = other.req;
    data = other.data;
    uuid = other.uuid;
    createTime = other.createTime;
    timer = other.timer;
    timeout = other.timeout;
    operation = other.operation;
}

MHttpRequestData &MHttpRequestData::operator =(const MHttpRequestData &other)
{
    if(&other != this){
        req = other.req;
        data = other.data;
        uuid = other.uuid;
        createTime = other.createTime;
        timer = other.timer;
        timeout = other.timeout;
        operation = other.operation;
    }
    return *this;
}

MHttpRequestData::~MHttpRequestData(){}

QString MHttpRequestData::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MHttpRequestData::toJsonObject() const
{
    QJsonObject json,reqjson,header;
    reqjson.insert("url",req.url().toString());

    QList<QByteArray> headername = req.rawHeaderList();
    foreach (const QByteArray &name, headername) {
        header.insert(QString(name),QString(req.rawHeader(name)));
    }
    reqjson.insert("header",header);

    json.insert(M_CAST_STRING(req),reqjson);
    json.insert(M_CAST_STRING(data),QString(data));
    json.insert(M_CAST_STRING(uuid),uuid);
    json.insert(M_CAST_STRING(createTime),createTime);
    json.insert(M_CAST_STRING(timeout),timeout);
    json.insert(M_CAST_STRING(timer),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)timer));
    json.insert(M_CAST_STRING(operation),(int)operation);

    return json;
}

/*******************************************************************MQlabel:begin**********/
MRollingLabel::MRollingLabel(QWidget *parent) : QWidget(parent)
{
    this->ii = 0;
    this->setText("HELLO WORLD HELLO WORLD "
                  "HELLO WORLD HELLO WORLD "
                  "HELLO WORLD HELLO WORLD "
                  "HELLO WORLD HELLO WORLD!");
    QMap<double,QColor> L;
    L.insert(0.0,QColor(0,0,0));
    L.insert(1.0,QColor(255,0,0));
    this->setBackGroundColor(0.0,
                             0.0,
                             1.0,
                             0.0,
                             L);

    this->setTextColor(QColor(255,255,255));
    this->setTextFont(QFont("Arial", 30));

    this->setSpeedInterval(3);
    this->height_text = QFontMetrics(this->textFont()).height();
    this->width_text = QFontMetrics(this->textFont()).width(this->text());
    this->timer.start(1000/20);
    connect(&this->timer,SIGNAL(timeout()),this,SLOT(update()),Qt::QueuedConnection);
}

void MRollingLabel::paintEvent(QPaintEvent *e)
{
    (void)e;
    if(this->ii > this->width() + this->width_text){
        this->ii = 0;
    }
    this->ii += this->interval_speed;
    int x = this->width() - this->ii;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(0, 0);
    painter.save();
    QLinearGradient LL = QLinearGradient(this->width() * x1,
                                         this->height() * y1,
                                         this->width() * x2,
                                         this->height() * y2);
    LL.setSpread(QLinearGradient::PadSpread);
    QMap<double,QColor>::const_iterator itor = this->map_color.constBegin();
    while(itor != this->map_color.constEnd()){
        LL.setColorAt(itor.key(),itor.value());
        itor++;
    }
    painter.setBrush(QBrush(LL));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,0,this->width(),this->height());
    painter.restore();
    painter.translate(x,0);
    painter.setPen(this->color_pen);
    painter.setBrush(Qt::NoBrush);
    painter.setFont(this->font_text);
    painter.drawText(0,0,
                     this->width_text,this->height(),
                     Qt::AlignVCenter,this->text_str);
}
void MRollingLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    (void)ev;
    emit this->mouseReleased();
}
int MRollingLabel::textWidth()
{
    return this->width_text;
}
int MRollingLabel::textHeight()
{
    return this->height_text;
}
void MRollingLabel::setSpeedInterval(int interval)
{
    if(interval > 0)
        this->interval_speed = interval;
}
int MRollingLabel::speedInterval()
{
    return this->interval_speed;
}
void MRollingLabel::setText(const QString& str)
{
    this->text_str = str;
    this->width_text = QFontMetrics(this->textFont()).width(this->text());
    this->height_text = QFontMetrics(this->textFont()).height();
}
QString MRollingLabel::text()
{
    return this->text_str;
}
void MRollingLabel::setBackGroundColor(double X1,
                                       double Y1,
                                       double X2,
                                       double Y2,
                                       const QMap<double,QColor> & map)
{
    if(X1 < (double)0.0
            || X1 > (double)1.0
            || Y1 < (double)0.0
            || Y1 > (double)1.0
            || X2 < (double)0.0
            || X2 > (double)1.0
            || Y2 < (double)0.0
            || Y2 > (double)1.0)
        return ;
    this->x1 = X1;
    this->y1 = Y1;
    this->x2 = X2;
    this->y2 = Y2;
    if(!map.isEmpty()){
        this->map_color.clear();
        this->map_color = map;
    }
}
void MRollingLabel::backGroundColor(double & X1,
                                    double & Y1,
                                    double & X2,
                                    double & Y2,
                                    QMap<double,QColor> & map)
{
    X1 = this->x1;
    Y1 = this->y1;
    X2 = this->x2;
    Y2 = this->y2;
    map.clear();
    map = this->map_color;
}
void MRollingLabel::setTextColor(const QColor& color)
{
    this->color_pen = color;
}
QColor MRollingLabel::textColor()
{
    return this->color_pen;
}
void MRollingLabel::setTextFont(const QFont& font)
{
    this->font_text = font;
    this->width_text = QFontMetrics(this->textFont()).width(this->text());
    this->height_text = QFontMetrics(this->textFont()).height();
}
QFont MRollingLabel::textFont()
{
    return this->font_text;
}
MRollingLabel::~MRollingLabel(){}
/*******************************************************************MSingleApp:begin**********/
MSingleApp::MSingleApp()
{
    this->localServer = NULL;
    this->localSocket = NULL;
}
MSingleApp:: ~MSingleApp()
{
    M_DELETE_TO_NULL(this->localServer);
    M_DELETE_TO_NULL(this->localSocket);
}
bool MSingleApp::isSingle(const QString &singleKey)
{
    if(!this->localSocket){
        this->localSocket = new QLocalSocket;
    }
    this->localSocket->setServerName(singleKey);
    this->localSocket->connectToServer(singleKey);
    if(this->localSocket->waitForConnected(1000 * 3)) {
        //
        return false;
    } else {
        M_DELETE_TO_NULL(this->localSocket);
        if(!this->localServer) {
            this->localServer = new QLocalServer;
        }
        if(!this->localServer->listen(singleKey)){
            QAbstractSocket::SocketError errRet = this->localServer->serverError();
            if(errRet == QAbstractSocket::AddressInUseError) {
                QString socketFile = QDir::tempPath() + "/" + singleKey;
                if(QFile::exists(socketFile)){
                    if(!QLocalServer::removeServer(socketFile)) {
                        return false;
                    }
                }
                if(this->localServer->listen(singleKey)) {
                    //
                    return true;
                }
                return false;
            }
            return false;
        }
        return true;
    }
}
/*******************************************************************MTimeLabel:begin**********/
MTimeLabel *MTimeLabel::getObj()
{
    return obj ? obj : obj = new MTimeLabel();
}

void MTimeLabel::add(QLabel *l)
{
    if(!l)
        return ;
    bool has = false;
    for(int i = 0; i < this->list_label.size(); i++){
        if(this->list_label.at(i).data() == l){
            has = true;
            break;
        }
    }
    if(!has){
        this->list_label.append(QPointer<QLabel>(l));
    }
}

void MTimeLabel::remove(QLabel *l)
{
    if(!l)
        return ;
    for(int i = 0; i < this->list_label.size(); i++){
        if(this->list_label.at(i).data() == l){
            this->list_label.removeAt(i);
            break;
        }
    }

}

QList<QPointer<QLabel> > &MTimeLabel::list()
{
    return this->list_label;
}

void MTimeLabel::removeNullPointer()
{
    for(int i = 0; i < this->list_label.size(); i++){
        if(this->list_label.at(i).isNull()){
            this->list_label.removeAt(i);
        }
    }
}

void MTimeLabel::timerEvent(QTimerEvent *e)
{
    int id = e->timerId();
    if(id == this->timer_2_flush_id){
        for(int i = 0; i < this->list_label.size(); i++){
            if(!this->list_label.at(i).isNull()){
                this->list_label.at(i).data()->setText(MTL::get_time_now(MTL::Normal,false));
            }
        }
    }
}

MTimeLabel::MTimeLabel(QObject *parent) : QObject(parent)
{
    this->timer_2_flush_id = this->startTimer(1000 * 1);
}

MTimeLabel* MTimeLabel::obj = NULL;

/*******************************************************************MUi:begin**********/
MUi::MUi(const QString &name_ui_file,
         const QString &name_time_label,
         QWidget *parent_ui,
         QObject *parent_this): QObject(parent_this)
{
    this->interval_count_down_default_ms = 1000 * 1;
    this->code_exit_default = MUi::TimeOut;
    this->timer_id_close_window = 0;
    this->ui = MTL::load_ui_from_file(name_ui_file,parent_ui);

    this->name_label_time = name_time_label;
    this->resetCountingDownTime();
    QLabel *timeLabel = this->ui->findChild<QLabel*>(this->name_label_time);
    if(timeLabel){
        this->timer_id_close_window = this->startTimer(this->interval_count_down_default_ms);
    }
}

MUi:: ~MUi()
{
    if(this->timer_id_close_window > 0){
        this->killTimer(this->timer_id_close_window);
        this->timer_id_close_window = 0;
    }
    M_DELETE_TO_NULL(this->ui);
}

bool MUi::isCountingDownTimerRunning() const
{
    return this->timer_id_close_window > 0 ;
}

void MUi::show()
{
    if(ui) ui->show();
}

void MUi::hide()
{
    if(ui) ui->hide();
}

void MUi::raise()
{
    if(ui) ui->raise();
}

void MUi::showFullScreen()
{
    if(ui) ui->showFullScreen();
}
void MUi::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == this->timer_id_close_window){
        this->time_left_current_window--;
        QLabel *lb=this->ui->findChild<QLabel*>(this->name_label_time);
        if(lb){
            lb->setText(QString("%1").arg(this->time_left_current_window));
        }
        if(this->time_left_current_window <= 0){
            if(this->timer_id_close_window > 0){
                this->killTimer(this->timer_id_close_window);
                this->timer_id_close_window = 0;
            }
            this->loop.exit(this->code_exit_default);
        }
    }
    QObject::timerEvent(e);
}

void MUi::enableCountingDownTimer(bool b,bool resetWindowTime)
{
    if(b){
        if(this->timer_id_close_window <= 0){
            this->timer_id_close_window = this->startTimer(this->interval_count_down_default_ms);
        }
    }else{
        if(this->timer_id_close_window > 0){
            this->killTimer(this->timer_id_close_window);
            this->timer_id_close_window = 0;
        }
    }
    if(resetWindowTime){
        this->resetCountingDownTime();
    }
}

void MUi::connectSignalAndSlot(QObject* obj)
{
    MTL::connect_signal_and_slot(this->ui,obj);
}
void MUi::resetCountingDownTime(int time)
{
    this->time_left_current_window = time;
    QLabel *lb = this->ui->findChild<QLabel*>(this->name_label_time);
    if(lb){
        lb->setText(QString("%1").arg(this->time_left_current_window));
    }
}
/*******************************************************************MWaitForm:begin**********/
MWaitForm::MWaitForm(QWidget *parent) : QWidget(parent)
{
    connect(&this->timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
    this->lyout = new QHBoxLayout;
    this->label = new MKit_P::waitLabel(this);
    this->label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->lyout->addWidget(this->label);
    this->setLayout(this->lyout);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window
                     #ifdef Q_OS_LINUX
                         | Qt::X11BypassWindowManagerHint
                     #endif
                         );
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(0.7);
    this->setGeometry(this->geometry().x(),this->geometry().y(),260,210);
}
void MWaitForm::showExec(uint time)
{
    if(this->loop.isRunning())
        return;
    if(time > 0){
        this->timer.start(1000 * time);
    }
    this->show();
    this->raise();
    MTL::set_center(this);
    this->loop.exec();
    this->timer.stop();
    this->close();
}
void MWaitForm::timeout_slot()
{
    if(this->loop.isRunning()){
        this->loop.exit(0);
    }
}

void MWaitForm::resizeEvent(QResizeEvent *e)
{
    (void)e;
    MTL::set_mask(this,20,20);
}
void MWaitForm::exit()
{
    this->timeout_slot();
}
MWaitForm::~MWaitForm()
{
    M_DELETE_TO_NULL(this->label);
    M_DELETE_TO_NULL(this->lyout);
}

/*******************************************************************MLoginForm:begin**********/
MLoginDialog::MLoginDialog(QWidget *parent) : QWidget(parent)
{
    connect(&this->timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    this->layout_grid = new QGridLayout();
    this->layout_vbox = new QVBoxLayout();
    this->board = new MVirtualKeyboard(this);
    this->board->setFocusPolicy(Qt::NoFocus);

    this->layout_vbox->addLayout(this->layout_grid);
    this->layout_vbox->addWidget(this->board);

    this->lineedit_account = new QLineEdit(this);
    this->lineedit_passwd = new QLineEdit(this);
    this->button_cancel = new QToolButton(this);
    this->button_ok = new QToolButton(this);

    this->lineedit_account->setClearButtonEnabled(true);
    this->lineedit_passwd->setClearButtonEnabled(true);
    this->lineedit_account->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->lineedit_passwd->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->button_cancel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->button_ok->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->button_cancel->setFocusPolicy(Qt::NoFocus);
    this->button_ok->setFocusPolicy(Qt::NoFocus);
    this->button_cancel->setText("Cancel");
    this->button_ok->setText("Ok");
    this->text_returnButton = this->button_cancel->text();
    connect(this->button_cancel,SIGNAL(clicked()),this,SLOT(button_cancel_slot()),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
    connect(this->button_ok,SIGNAL(clicked()),this,SLOT(button_ok_slot()),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);

    this->layout_grid->addWidget(this->lineedit_account,0,0);
    this->layout_grid->addWidget(this->button_cancel,0,1);
    this->layout_grid->addWidget(this->lineedit_passwd,1,0);
    this->layout_grid->addWidget(this->button_ok,1,1);

    this->layout_grid->setColumnStretch(0,7);
    this->layout_grid->setColumnStretch(1,1);
    this->layout_vbox->setStretch(0,1);
    this->layout_vbox->setStretch(1,2);

    this->setLayout(this->layout_vbox);

    connect(this->lineedit_account,
            SIGNAL(textChanged(const QString & )),
            this,
            SLOT(textChanged_slot(const QString &)));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window
                     #ifdef Q_OS_LINUX
                         | Qt::X11BypassWindowManagerHint
                     #endif
                         );
    this->setWindowModality(Qt::ApplicationModal);
    this->setGeometry(this->geometry().x(),this->geometry().y(),650,320);

    this->setStyleSheet(MTL::get_data_from_file(":/QRC/qss/MLoginDialog.qss"));
}
MLoginDialog::ExitType MLoginDialog::showExec(MLoginDialog::UserInfo &info,
                                              int time,
                                              const QString &acount_str,
                                              const QString &passwd_str,
                                              int acount_length,
                                              int passwd_length,
                                              const QString &acount_str_placeHolder,
                                              const QString &passwd_str_placeHolder,
                                              bool passwd_str_echoMode)
{
    this->length_account = acount_length;
    this->length_passwd = passwd_length;
    this->time_left = time;
    if(this->time_left > 0){
        this->button_cancel->setText(QString("%1(%2)")
                                     .arg(this->text_returnButton)
                                     .arg(this->time_left));
        timer.start(1000);
    }

    this->show();
    this->raise();
    MTL::set_center(this);

    this->lineedit_account->setText(acount_str);
    this->lineedit_passwd->setText(passwd_str);
    this->lineedit_account->setPlaceholderText(QString(acount_str_placeHolder));
    this->lineedit_passwd->setPlaceholderText(QString(passwd_str_placeHolder));
    this->lineedit_account->setFocus();
    this->lineedit_passwd->setEchoMode(passwd_str_echoMode ? QLineEdit::Password : QLineEdit::Normal);

    int ret = loop.exec();
    this->timer.stop();
    this->hide();
    info.account = this->lineedit_account->text().trimmed();
    info.passwd = this->lineedit_passwd->text().trimmed();
    return (MLoginDialog::ExitType)ret;
}

void MLoginDialog::textChanged_slot(const QString & str)
{
    if(str.length() >= this->length_account)
        this->lineedit_passwd->setFocus();
}

void MLoginDialog::resizeEvent(QResizeEvent *e)
{
    (void)e;
    MTL::set_mask(this,10,10);
}

void MLoginDialog::timeout_slot()
{
    this->time_left--;
    this->button_cancel->setText(QString("%1(%2)")
                                 .arg(this->text_returnButton)
                                 .arg(this->time_left));
    if(this->time_left <= 0){
        this->loop.exit(MLoginDialog::Timeout);
    }
}

MLoginDialog::~MLoginDialog()
{
    M_DELETE_TO_NULL(this->board);
    M_DELETE_TO_NULL(this->lineedit_account);
    M_DELETE_TO_NULL(this->lineedit_passwd);
    M_DELETE_TO_NULL(this->button_cancel);
    M_DELETE_TO_NULL(this->button_ok);
    M_DELETE_TO_NULL(this->layout_grid);
    M_DELETE_TO_NULL(this->layout_vbox);
}


void MLoginDialog::append(const QString & str)
{
    QWidget *w = this->focusWidget();
    if(w){
        QLineEdit *le = dynamic_cast<QLineEdit*>(w);
        if(le){
            int index = le->cursorPosition();
            QString tmp = le->text();
            tmp.insert(index,str);
            le->setText(tmp);
        }
    }
}

void MLoginDialog::cancel()
{
    this->loop.exit(MLoginDialog::Cancel);
}

void MLoginDialog::confirm()
{
    this->loop.exit(MLoginDialog::Ok);
}

void MLoginDialog::button_cancel_slot()
{
    //return button
    this->loop.exit(MLoginDialog::Cancel);
}

void MLoginDialog::button_ok_slot()
{
    //confirm button
    this->loop.exit(MLoginDialog::Ok);
}

/*******************************************************************MConfirmForm:begin**********/

MConfirmDialog::MConfirmDialog(QWidget *parent) : QWidget(parent)
{
    this->button_ok = new QToolButton(this);
    this->button_cancel = new QToolButton(this);
    this->text = new QTextBrowser(this);
    this->label_time = new QLabel(this);
    this->layout_v = new QVBoxLayout();
    this->layout_h = new QHBoxLayout();
    this->spacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->layout_h->addWidget(this->label_time);
    this->layout_h->addSpacerItem(this->spacer);
    this->layout_h->addWidget(this->button_ok);
    this->layout_h->addWidget(this->button_cancel);

    this->layout_v->addWidget(this->text);
    this->layout_v->addLayout(this->layout_h);
    this->setLayout(this->layout_v);

    this->layout_v->setStretch(0,10);
    this->layout_v->setStretch(1,1);
    this->layout_h->setStretch(0,1);
    this->layout_h->setStretch(1,10);
    this->layout_h->setStretch(2,1);
    this->layout_h->setStretch(3,1);
    this->layout_h->setMargin(0);
    this->label_time->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->button_ok->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->button_cancel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->text->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->button_ok->setFocusPolicy(Qt::NoFocus);
    this->button_cancel->setFocusPolicy(Qt::NoFocus);
    this->text->setFocusPolicy(Qt::NoFocus);

    this->button_ok->setText("Ok");
    this->button_cancel->setText("Cancel");
    connect(this->button_ok,SIGNAL(clicked()),this,SLOT(button_ok_slot()),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
    connect(this->button_cancel,SIGNAL(clicked()),this,SLOT(button_cancel_slot()),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);

    this->animation = new QPropertyAnimation(this,"geometry");
    this->animation->setDuration(100 * 5);
    this->animation->setEasingCurve(QEasingCurve(QEasingCurve::OutElastic));
    connect(&this->timer,SIGNAL(timeout()),this,SLOT(flushThebuttonText()));
    this->timer.setInterval(1000);

    this->width_default = 560;
    this->height_default = 300;
    this->setGeometry(this->geometry().x(),this->geometry().y(),this->width_default,this->height_default);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window
                     #ifdef Q_OS_LINUX
                         | Qt::X11BypassWindowManagerHint
                     #endif
                         );
    this->setWindowModality(Qt::ApplicationModal);

    this->setStyleSheet(MTL::get_data_from_file(":/QRC/qss/MConfirmDialog.qss"));
}
MConfirmDialog::~MConfirmDialog()
{
    M_DELETE_TO_NULL(this->animation);
    M_DELETE_TO_NULL(this->button_cancel);
    M_DELETE_TO_NULL(this->button_ok);
    M_DELETE_TO_NULL(this->label_time);
    M_DELETE_TO_NULL(this->text);
    M_DELETE_TO_NULL(this->layout_h);
    M_DELETE_TO_NULL(this->layout_v);
}
bool MConfirmDialog::showExec(const QString& message,int time,int w,int h,bool animation)
{
    if(this->loop.isRunning()){
        if(this->isHidden())
            this->show();
        this->text->append(message);
        if(time > 0){
            this->timeLeft=time;
            this->timer.start();
        }else{
            this->timer.stop();
            this->label_time->clear();
        }
        return false;
    }

    QRect rect;
    rect.setX(this->geometry().x());
    rect.setY(this->geometry().y());
    rect.setWidth(w > 0 ? w : this->width_default);
    rect.setHeight(h > 0 ? h : this->height_default);
    this->setGeometry(rect);

    this->text->setText(message);

    this->timeLeft = time;
    if(this->timeLeft > 0) {
        this->timer.start();
        this->label_time->setText(QString::number(this->timeLeft));
    }else{
        this->timer.stop();
        this->label_time->clear();
    }
    this->show();
    this->raise();
    MTL::set_center(this);

    this->activateWindow();
    if(animation) {
        this->animation->setStartValue(QRect(this->x(), 0, this->width(), this->height()));
        this->animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
        this->animation->start();
    }
    int ret = this->loop.exec();
    this->timer.stop();
    this->hide();
    return ret == 1 ;
}
void MConfirmDialog::keyPressEvent(QKeyEvent *e)
{
    if(this->loop.isRunning() &&
            (e->key()==Qt::Key_Enter || e->key()==Qt::Key_Return) )
    {
        this->loop.exit(1);
    }
    if(this->loop.isRunning() &&
            (e->key() == Qt::Key_Escape))
    {
        this->loop.exit(0);
    }
}

void MConfirmDialog::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
    } else
        QWidget::changeEvent(event);
}

void MConfirmDialog::resizeEvent(QResizeEvent *e)
{
    (void)e;
    MTL::set_mask(this,10,10);
}
void MConfirmDialog::flushThebuttonText()
{
    this->timeLeft--;
    if(this->timeLeft <= 0) {
        this->loop.exit(0);
    }
    this->label_time->setText(QString("%1").arg(this->timeLeft));
}

void MConfirmDialog::button_cancel_slot()
{
    this->loop.exit(0);
}

void MConfirmDialog::button_ok_slot()
{
    this->loop.exit(1);
}
int MConfirmDialog::defaultWidth()
{
    return this->width_default;
}
int MConfirmDialog::defaultHeight()
{
    return this->height_default;
}

/*******************************************************************MPromptQWidget:begin**********/

MPromptQWidget *MPromptQWidget::getObj()
{
    return obj ? obj : obj = new MPromptQWidget;
}

MPromptQWidget *MPromptQWidget::obj = NULL;

void MPromptQWidget::postMessage(const QString &m)
{
    if(!isVisible()){
        textBrowser->clear();
    }
    textBrowser->append(m);
    timer.start(1000);
    aliveTime = 60 * 2;
    label->setText(QString::number(aliveTime));
    show();
}

void MPromptQWidget::timeout_slot()
{
    if(--aliveTime <= 0){
        close();
    }
    label->setText(QString::number(aliveTime));
}

void MPromptQWidget::closeEvent(QCloseEvent *e)
{
    timer.stop();
    QWidget::closeEvent(e);
}

MPromptQWidget::MPromptQWidget(QWidget *parent) : QWidget(parent)
{
    vb = new QVBoxLayout;
    hb = new QHBoxLayout;

    textBrowser = new QTextBrowser;

    label = new QLabel;
    label->setFont(QFont("Times", 10, QFont::Bold));

    spacerItem = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);

    button = new QToolButton;
    connect(button,SIGNAL(clicked()),this,SLOT(close()));
    button->setText("知道了");
    button->setMinimumSize(90,30);
    button->setMaximumSize(90,30);
    button->setFixedSize(90,30);

    hb->addWidget(label);
    hb->addItem(spacerItem);
    hb->addWidget(button);
    hb->setStretch(0,0);
    hb->setStretch(1,10);
    hb->setStretch(2,0);
    hb->setMargin(0);
    hb->setSpacing(0);

    vb->addWidget(textBrowser);
    vb->addLayout(hb);
    vb->setStretch(0,10);
    vb->setStretch(1,0);

    setLayout(vb);

    setWindowFlags((Qt::WindowFlags )(Qt::Window
                                      // | Qt::WindowStaysOnTopHint
                                      // | ~Qt::WindowTitleHint
                                      // | Qt::WindowMaximizeButtonHint
                                      // | Qt::WindowCloseButtonHint
                                      ));
    setWindowModality(Qt::ApplicationModal);
    setWindowTitle(" ");

    timer.setParent(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    setMinimumSize(480,260);
    MTL::set_center(this);
}

MPromptQWidget::~MPromptQWidget(){ }

/*******************************************************************MSerialPort:begin**********/

MSerialPort::MSerialPort(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_LINUX
    this->fd=-1;
    this->notifier=NULL;
    this->errorStr="";
    this->port="";
#else
    MDG_WARNING << "this class Only for Linux!!!";
    MDG_WARNING << "this class Only for Linux!!!";
    MDG_WARNING << "this class Only for Linux!!!";
#endif //Q_OS_LINUX
}
MSerialPort::~MSerialPort(){
#ifdef Q_OS_LINUX
    this->close();
#endif //Q_OS_LINUX
}
bool MSerialPort::isOpen() const{
#ifdef Q_OS_LINUX
    return this->fd > -1;
#else
    return false;
#endif //Q_OS_LINUX
}
QString MSerialPort::portName() const{
#ifdef Q_OS_LINUX
    return this->port;
#else
    return "";
#endif //Q_OS_LINUX
}

int MSerialPort::flush(){
#ifdef Q_OS_LINUX
    return ::tcflush(this->fd,TCIOFLUSH);
#else
    return 0;
#endif //Q_OS_LINUX
}

int MSerialPort::syncfs(){
#ifdef Q_OS_LINUX
    return ::syncfs(this->fd);
#else
    return 0;
#endif //Q_OS_LINUX
}
QString MSerialPort::errorString() const{
#ifdef Q_OS_LINUX
    return QString(::strerror(errno));
#else
    return "";
#endif //Q_OS_LINUX
}
int MSerialPort::error() const{
#ifdef Q_OS_LINUX
    return errno;
#else
    return 0;
#endif //Q_OS_LINUX
}
int MSerialPort::handle() const{
#ifdef Q_OS_LINUX
    return this->fd;
#else
    return 0;
#endif //Q_OS_LINUX
}
void MSerialPort::setNotifier(){
#ifdef Q_OS_LINUX
    if(this->isOpen())
    {
        M_DELETE_TO_NULL(this->notifier);
        this->notifier=new QSocketNotifier(this->fd,QSocketNotifier::Read);
        connect(this->notifier,
                SIGNAL(activated(int)),
                this,
                SIGNAL(readReady(int)),
                M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
    }
#endif //Q_OS_LINUX
}
bool MSerialPort::open(bool block){
#ifdef Q_OS_LINUX
    if(this->isOpen())return true;
    this->fd=::open(this->port.toStdString().c_str(), O_RDWR | O_NDELAY);
    if(this->fd < 0){
        return false;
    }
    ::tcflush(this->fd,TCIOFLUSH);
    //none block
    int n = fcntl(this->fd, F_GETFL, 0);
    int ret=::fcntl(this->fd, F_SETFL, (!block)?(n | O_NDELAY):(n & ~O_NDELAY) );
    //int ret=::fcntl(this->fd, F_SETFL, n & ~O_NDELAY);
    if(ret < 0){
        //must close the fd, and set NULL;
        //must close the fd, and set NULL;
        //must close the fd, and set NULL;
        ::close(this->fd);
        this->fd=-1;
        return false;
    }
    this->setNotifier();
    return true;
#else
    (void)block;
    return false;
#endif //Q_OS_LINUX
}
bool MSerialPort::setPortName(const QString &file){
#ifdef Q_OS_LINUX
    if(!this->isOpen()){
        this->port = file;
        return true;
    }else{
        return false;
    }
#else
    (void)file;
    return false;
#endif //Q_OS_LINUX
}
int MSerialPort::write(uchar *data,int len){
#ifdef Q_OS_LINUX
    return ::write(this->fd,data,len);
#else
    (void)data;
    (void)len;
    return 0;
#endif //Q_OS_LINUX
}
int MSerialPort::read(uchar *des,int len){
#ifdef Q_OS_LINUX
    return ::read(this->fd,des,len);
#else
    (void)des;
    (void)len;
    return 0;
#endif //Q_OS_LINUX
}
int MSerialPort::close(){
#ifdef Q_OS_LINUX
    M_DELETE_TO_NULL(this->notifier);
    int ret=::close(this->fd);
    this->fd=-1;
    return ret;
#else
    return 0;
#endif //Q_OS_LINUX
}
bool MSerialPort::setAttr(int baudrate,
                          int databits,
                          Parity Parity,
                          StopBits stop,
                          bool softwareHandshake,
                          bool hardwareHandshake)
{
#ifdef Q_OS_LINUX
    if(!this->isOpen()){
        return false;
    }
    struct termios newtio;
    ::memset(&newtio, 0, sizeof(newtio));
    if (tcgetattr(this->fd, &newtio) < 0){
        return false;
    }
    speed_t _baud=0;
    switch (baudrate)
    {
#ifdef B0
    case      0: _baud=B0;     break;
#endif
#ifdef B50
    case     50: _baud=B50;    break;
#endif
#ifdef B75
    case     75: _baud=B75;    break;
#endif
#ifdef B110
    case    110: _baud=B110;   break;
#endif
#ifdef B134
    case    134: _baud=B134;   break;
#endif
#ifdef B150
    case    150: _baud=B150;   break;
#endif
#ifdef B200
    case    200: _baud=B200;   break;
#endif
#ifdef B300
    case    300: _baud=B300;   break;
#endif
#ifdef B600
    case    600: _baud=B600;   break;
#endif
#ifdef B1200
    case   1200: _baud=B1200;  break;
#endif
#ifdef B1800
    case   1800: _baud=B1800;  break;
#endif
#ifdef B2400
    case   2400: _baud=B2400;  break;
#endif
#ifdef B4800
    case   4800: _baud=B4800;  break;
#endif
#ifdef B7200
    case   7200: _baud=B7200;  break;
#endif
#ifdef B9600
    case   9600: _baud=B9600;  break;
#endif
#ifdef B14400
    case  14400: _baud=B14400; break;
#endif
#ifdef B19200
    case  19200: _baud=B19200; break;
#endif
#ifdef B28800
    case  28800: _baud=B28800; break;
#endif
#ifdef B38400
    case  38400: _baud=B38400; break;
#endif
#ifdef B57600
    case  57600: _baud=B57600; break;
#endif
#ifdef B76800
    case  76800: _baud=B76800; break;
#endif
#ifdef B115200
    case 115200: _baud=B115200; break;
#endif
#ifdef B128000
    case 128000: _baud=B128000; break;
#endif
#ifdef B230400
    case 230400: _baud=B230400; break;
#endif
#ifdef B460800
    case 460800: _baud=B460800; break;
#endif
#ifdef B576000
    case 576000: _baud=B576000; break;
#endif
#ifdef B921600
    case 921600: _baud=B921600; break;
#endif
    default:
        _baud=B9600;
        break;
    }
    cfsetospeed(&newtio, (speed_t)_baud);
    cfsetispeed(&newtio, (speed_t)_baud);
    /* We generate mark and space parity ourself. */
    if (databits == 7 &&
            (Parity==MSerialPort::MarkParity || Parity ==MSerialPort::SpaceParity)){
        databits = 8;
    }
    switch (databits){
    case 5:
        newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS5;
        break;
    case 6:
        newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS6;
        break;
    case 7:
        newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS7;
        break;
    case 8:
    default:
        newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS8;
        break;
    }
    newtio.c_cflag |= CLOCAL | CREAD;

    //parity
    newtio.c_cflag &= ~(PARENB | PARODD);
    if (Parity ==MSerialPort::EvenParity){
        newtio.c_cflag |= PARENB;
    }else if (Parity==MSerialPort::OddParity){
        newtio.c_cflag |= (PARENB | PARODD);
    }
    newtio.c_cflag &= ~CRTSCTS;

    //stopbits
    if (stop==MSerialPort::TwoStop){
        newtio.c_cflag |= CSTOPB;
    }else{
        newtio.c_cflag &= ~CSTOPB;
    }
    newtio.c_iflag=IGNBRK;
    //software handshake
    if (softwareHandshake){
        newtio.c_iflag |= IXON | IXOFF;
    }else{
        newtio.c_iflag &= ~(IXON|IXOFF|IXANY);
    }

    newtio.c_lflag=0;
    newtio.c_oflag=0;
    newtio.c_cc[VTIME]=1;
    newtio.c_cc[VMIN]=1;
    //tcflush(m_fd, TCIFLUSH);
    if (tcsetattr(this->fd, TCSANOW, &newtio) < 0){
        return false;
    }
    int mcs=0;
    ::ioctl(this->fd, TIOCMGET, &mcs);
    mcs |= TIOCM_RTS;
    ::ioctl(this->fd, TIOCMSET, &mcs);
    if (tcgetattr(this->fd, &newtio) < 0){
        return false;
    }
    //hardware handshake
    if (hardwareHandshake){
        newtio.c_cflag |= CRTSCTS;
    }else{
        newtio.c_cflag &= ~CRTSCTS;
    }
    if (tcsetattr(this->fd, TCSANOW, &newtio) < 0){
        return false;
    }
    ::tcflush(this->fd,TCIOFLUSH);
    //this->mSetNotifier();
    return true;
#else
    (void)baudrate;
    (void)databits;
    (void)Parity;
    (void)stop;
    (void)softwareHandshake;
    (void)hardwareHandshake;
    return false;
#endif //Q_OS_LINUX
}
int MSerialPort::readTimeout(int fd,
                             uchar *buff,
                             int length,
                             int timeUs)
{
#ifdef Q_OS_LINUX
    if(fd < 0||
            ! buff||
            length <= 0)return -1;
    fd_set rfds;
    struct timeval tv;
    int retval=0;
    int read=0;
    /* Wait up to five seconds. */
    tv.tv_sec = timeUs/1000/1000;
    tv.tv_usec = timeUs%(1000*1000);
    while(1)
    {
        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);
        retval = ::select(fd+1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */

        if (retval == -1)
        {
            //perror("select()");
            return -1;
        }
        else if (retval)
        {
            //printf("Data is available now.\n");
            /* FD_ISSET(0, &rfds) will be true. */
            if(!FD_ISSET(fd,&rfds))return -1;
            int ret=::read(fd,buff+read,length-read);
            if(ret>=0)
            {
                read += ret;
                if(read >= length)
                {
                    return read;
                }
            }
            else if(ret < 0)return -1;
        }
        else
        {
            //printf("No data within five seconds.\n");
            return read;
        }
    }
#else
    (void)fd;
    (void)buff;
    (void)length;
    (void)timeUs;
    return 0;
#endif //Q_OS_LINUX
}

int MSerialPort::readTillEnd(int fd,
                             uchar *buff,
                             int buffLength,
                             uchar *endFlag,
                             int endFlagLength)
{
#ifdef Q_OS_LINUX
    if(fd<0||
            !buff||
            !endFlag||
            endFlagLength<=0||
            buffLength<endFlagLength)
        return -1;
    int read=0;

    while(1)
    {
        int ret=::read(fd,buff+read,buffLength-read);
        if(ret<0)
            return -1;
        else if(ret)
        {
            read+=ret;
        }
        if(read>=endFlagLength)
        {
            for(int i=0;i<read;i++)
            {
                if(i+endFlagLength<=read)
                {
                    volatile bool isSame=true;
                    for(int j=0;j<endFlagLength;j++)
                    {
                        if(buff[i+j]!=endFlag[j])
                        {
                            isSame=false;
                            goto next;
                        }
                    }
                    if(isSame)
                    {
                        goto end;
                    }
                }
next:
                (void)0;
            }
        }
        ::usleep(1000*10);
    }
end:
    return read;
#else
    (void)fd;
    (void)buff;
    (void)buffLength;
    (void)endFlag;
    (void)endFlagLength;
    return 0;
#endif //Q_OS_LINUX
}

/*******************************************************************MBubbleForm:begin**********/
#ifdef Q_OS_WIN32
MBubbleForm::MBubbleForm()
{
    this->setFixedSize(300 , 200);
    m_pShowTimer = new QTimer(this);
    m_pStayTimer = new QTimer(this);
    m_pCloseTimer = new QTimer(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:#646464");
    m_titleLabel.setParent(this);
    m_titleLabel.setGeometry(0,0,275,25);
    m_titleLabel.setStyleSheet("background-color:#444444;color:rgb(255,255,255);font-size:15px");

    m_closeBtn.setParent(this);
    m_closeBtn.setGeometry(275 , 0 , 25 , 25);
    m_closeBtn.setStyleSheet("background-color:#444444;margin:1px;border-image:url(./ico/close.png);");

    m_textLabel.setParent(this);
    m_textLabel.setGeometry(0,50,300,150);
    m_textLabel.setStyleSheet("color:#FFFFFF ; font-size:20px");
    m_textLabel.setAlignment(Qt::AlignCenter);

    connect(m_pShowTimer, SIGNAL(timeout()), this, SLOT(onMove()));
    connect(m_pStayTimer, SIGNAL(timeout()), this, SLOT(onStay()));
    connect(m_pCloseTimer, SIGNAL(timeout()), this, SLOT(onClose()));
    connect(&m_closeBtn , SIGNAL(clicked()) , this , SLOT(onStay()));
}

void MBubbleForm::showDlg(const QString &strTitle, const QString &strText)
{
    this->m_pShowTimer->stop();
    this->m_pCloseTimer->stop();
    this->m_pStayTimer->stop();
    this->hide();

    m_dTransparent = 1.0;
    setWindowOpacity(m_dTransparent);
    m_textLabel.setText(strText);
    m_titleLabel.setText(QString(" %1").arg(strTitle));

    this->show();
    this->raise();

    QRect rect = QApplication::desktop()->availableGeometry();
    m_nDesktopHeight = rect.height();
    m_point.setX(rect.width() - width() + rect.x());
    m_point.setY(rect.height() - height() + rect.y());
    move(m_point.x(), m_point.y());
    m_pShowTimer->start(5);
}

void MBubbleForm::onMove()
{
    m_nDesktopHeight--;
    move(m_point.x(), m_nDesktopHeight);
    if (m_nDesktopHeight <= m_point.y()){
        m_pShowTimer->stop();
        m_pStayTimer->start(5000);
    }
}

void MBubbleForm::onStay()
{
    m_pStayTimer->stop();
    m_pCloseTimer->start(100);
}

void MBubbleForm::onClose()
{
    m_dTransparent -= 0.1;
    if (m_dTransparent <= 0.0) {
        m_pCloseTimer->stop();
        close();
    } else{
        setWindowOpacity(m_dTransparent);
    }
}
#endif //Q_OS_WIN32
/*******************************************************************MClock:begin**********/
MClock::MClock(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
    timer->start(1000);

    QColor backcolor(0xff, 0xff, 0x99, 150);
    QColor secondColor(0, 0, 255, 255);
    this->color_background = backcolor;
    this->color_hour = secondColor;
    this->color_minute = secondColor;
    this->color_second = secondColor;
}
void MClock::paintEvent(QPaintEvent *)
{
    static const qreal localSide = 200.0;
    //
    static const QPoint hourHand[3] = {
        QPoint(3, 8),
        QPoint(-3, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(3, 8),
        QPoint(-3, 8),
        QPoint(0, -70)
    };
    static const QPoint secondHand[3] = {
        QPoint(3, 8),
        QPoint(-3, 8),
        QPoint(0, -90)
    };

    //
    QColor hourColor = this->color_hour;
    QColor backcolor = this->color_minute;
    QColor secondColor = this->color_second;
    QColor backColor = this->color_background;

    //diameter
    int side = M_MINIMUM(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2, height() / 2);
    painter.scale(side / localSide, side / localSide);

    //background
    painter.setBrush(backColor);
    painter.setPen(backColor);
    painter.drawEllipse(-100, -100, 200, 200);

    painter.save();

    //hour point
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, M_SIZE_ARRAY_ELEMENTS(hourHand));
    painter.restore();

    //hour point mark
    painter.setPen(hourColor);
    painter.setBrush(Qt::NoBrush);
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
        painter.drawText(-4,-80,10,10,Qt::AlignCenter,QString("%1").arg(i+1));
    }

    painter.save();
    //minute point
    painter.setPen(Qt::NoPen);
    painter.setBrush(backcolor);
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, M_SIZE_ARRAY_ELEMENTS(minuteHand));
    painter.restore();

    //minute point mark
    painter.setPen(backcolor);
    painter.setBrush(Qt::NoBrush);
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0){
            painter.drawLine(92, 0, 96, 0);
        }
        painter.rotate(6.0);
    }

    //second point
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, M_SIZE_ARRAY_ELEMENTS(secondHand));

    painter.restore();
    return ;
}
QSize MClock::sizeHint() const{  return QSize(100, 100);}

void MClock::setHourHandColor(const QColor &color){  this->color_hour = color;}

void MClock::setMinuteHandColor(const QColor &color){ this->color_minute = color;}

void MClock::setSecondHandColor(const QColor &color){ this->color_second = color;}

void MClock::resizeEvent(QResizeEvent *)
{
    int side = M_MINIMUM(width(), height());
    QRegion maskedRegion(width() / 2 - side / 2,
                         height() / 2 - side / 2,
                         side,
                         side,
                         QRegion::Ellipse);
    this->setMask(maskedRegion);
}
/*******************************************************************MVirtualKeyboard:begin**********/

MVirtualKeyboard::MVirtualKeyboard(QWidget *parent) : QWidget(parent)
{
    this->prefixName = QUuid::createUuid().toString().replace("-","").replace("{","").replace("}","") + "_";
    this->upper = false;
    this->layout_h_1 = new QHBoxLayout();
    this->layout_h_1->setObjectName(this->prefixName + QStringLiteral("layout_h_1"));
    this->layout_h_2 = new QHBoxLayout();
    this->layout_h_2->setObjectName(this->prefixName + QStringLiteral("layout_h_2"));
    this->layout_h_3 = new QHBoxLayout();
    this->layout_h_3->setObjectName(this->prefixName + QStringLiteral("layout_h_3"));
    this->layout_h_4 = new QHBoxLayout();
    this->layout_h_4->setObjectName(this->prefixName + QStringLiteral("layout_h_4"));
    this->layout_v = new QVBoxLayout();
    this->layout_v->setObjectName(this->prefixName + QStringLiteral("layout_v"));
    this->spacer_1 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->spacer_2 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->spacer_3 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);

    //first row
    QStringList l1;
    l1 << this->prefixName + "toolButton_q"
       << this->prefixName + "toolButton_w"
       << this->prefixName + "toolButton_e"
       << this->prefixName + "toolButton_r"
       << this->prefixName + "toolButton_t"
       << this->prefixName + "toolButton_y"
       << this->prefixName + "toolButton_u"
       << this->prefixName + "toolButton_i"
       << this->prefixName + "toolButton_o"
       << this->prefixName + "toolButton_p";
    foreach (const QString &button, l1) {
        QToolButton *b = new QToolButton(this);
        b->setObjectName(button);
        b->setText(button.mid(button.length() - 1));
        this->layout_h_1->addWidget(b);
        this->list_button << b;
    }

    //second row
    QStringList l2;
    l2 << this->prefixName + "toolButton_a"
       << this->prefixName + "toolButton_s"
       << this->prefixName + "toolButton_d"
       << this->prefixName + "toolButton_f"
       << this->prefixName + "toolButton_g"
       << this->prefixName + "toolButton_h"
       << this->prefixName + "toolButton_j"
       << this->prefixName + "toolButton_k"
       << this->prefixName + "toolButton_l";
    this->layout_h_2->addSpacerItem(this->spacer_1);
    foreach (const QString &button, l2) {
        QToolButton *b = new QToolButton(this);
        b->setObjectName(button);
        b->setText(button.mid(button.length() - 1));
        this->layout_h_2->addWidget(b);
        this->list_button << b;
    }
    this->layout_h_2->addSpacerItem(this->spacer_2);

    //third row
    QStringList l3;
    l3 << this->prefixName + "toolButton_z"
       << this->prefixName + "toolButton_x"
       << this->prefixName + "toolButton_c"
       << this->prefixName + "toolButton_v"
       << this->prefixName + "toolButton_b"
       << this->prefixName + "toolButton_n"
       << this->prefixName + "toolButton_m";
    this->layout_h_3->addSpacerItem(this->spacer_3);
    foreach (const QString &button, l3) {
        QToolButton *b = new QToolButton(this);
        b->setObjectName(button);
        b->setText(button.mid(button.length() - 1));
        this->layout_h_3->addWidget(b);
        this->list_button << b;
    }
    QToolButton *toolButton_cap=new QToolButton(this);
    toolButton_cap->setObjectName(this->prefixName + "toolButton_cap");
    toolButton_cap->setText(QString("Caps"));
    this->layout_h_3->addWidget(toolButton_cap);
    this->list_button << toolButton_cap;

    //fourth row
    QToolButton *toolButton__=new QToolButton(this);
    toolButton__->setObjectName(this->prefixName + "toolButton__");
    toolButton__->setText("-");
    this->layout_h_4->addWidget(toolButton__);
    this->list_button << toolButton__;

    QToolButton *toolButton___=new QToolButton(this);
    toolButton___->setObjectName(this->prefixName + "toolButton___");
    toolButton___->setText("_");
    this->layout_h_4->addWidget(toolButton___);
    this->list_button << toolButton___;

    QToolButton *toolButton_dou=new QToolButton(this);
    toolButton_dou->setObjectName(this->prefixName + "toolButton_dou");
    toolButton_dou->setText(",");
    this->layout_h_4->addWidget(toolButton_dou);
    this->list_button << toolButton_dou;

    QToolButton *toolButton_dot=new QToolButton(this);
    toolButton_dot->setObjectName(this->prefixName + "toolButton_dot");
    toolButton_dot->setText(".");
    this->layout_h_4->addWidget(toolButton_dot);
    this->list_button << toolButton_dot;

    QToolButton *toolButton_left=new QToolButton(this);
    toolButton_left->setObjectName(this->prefixName + "toolButton_left");
    toolButton_left->setText("/");
    this->layout_h_4->addWidget(toolButton_left);
    this->list_button << toolButton_left;

    QToolButton *toolButton_backslash=new QToolButton(this);
    toolButton_backslash->setObjectName(this->prefixName + "toolButton_backslash");
    toolButton_backslash->setText("\\");
    this->layout_h_4->addWidget(toolButton_backslash);
    this->list_button << toolButton_backslash;

    QToolButton *toolButton_wen=new QToolButton(this);
    toolButton_wen->setObjectName(this->prefixName + "toolButton_wen");
    toolButton_wen->setText("?");
    this->layout_h_4->addWidget(toolButton_wen);
    this->list_button << toolButton_wen;

    QToolButton *toolButton_equal=new QToolButton(this);
    toolButton_equal->setObjectName(this->prefixName + "toolButton_equal");
    toolButton_equal->setText("=");
    this->layout_h_4->addWidget(toolButton_equal);
    this->list_button << toolButton_equal;

    QToolButton *toolButton_fen=new QToolButton(this);
    toolButton_fen->setObjectName(this->prefixName + "toolButton_fen");
    toolButton_fen->setText(";");
    this->layout_h_4->addWidget(toolButton_fen);
    this->list_button << toolButton_fen;

    QToolButton *toolButton_mao=new QToolButton(this);
    toolButton_mao->setObjectName(this->prefixName + "toolButton_mao");
    toolButton_mao->setText(":");
    this->layout_h_4->addWidget(toolButton_mao);
    this->list_button << toolButton_mao;

    QToolButton *toolButton_smaller=new QToolButton(this);
    toolButton_smaller->setObjectName(this->prefixName + "toolButton_smaller");
    toolButton_smaller->setText("<");
    this->layout_h_4->addWidget(toolButton_smaller);
    this->list_button << toolButton_smaller;

    QToolButton *toolButton_bigger=new QToolButton(this);
    toolButton_bigger->setObjectName(this->prefixName + "toolButton_bigger");
    toolButton_bigger->setText(">");
    this->layout_h_4->addWidget(toolButton_bigger);
    this->list_button << toolButton_bigger;

    QToolButton *toolButton_and=new QToolButton(this);
    toolButton_and->setObjectName(this->prefixName + "toolButton_and");
    toolButton_and->setText("&&");
    this->layout_h_4->addWidget(toolButton_and);
    this->list_button << toolButton_and;

    this->layout_v->addLayout(this->layout_h_1);
    this->layout_v->addLayout(this->layout_h_2);
    this->layout_v->addLayout(this->layout_h_3);
    this->layout_v->addLayout(this->layout_h_4);

    //1 2 2 2 2 2 2 2 2 2 1
    this->layout_h_2->setStretch(0,1);
    for(int i = 0; i < 9; i++){
        this->layout_h_2->setStretch(i + 1,2);
    }
    this->layout_h_2->setStretch(10,1);

    //1 1 1 1 1 1 1 1 2
    for(int i = 0; i < 8; i++){
        this->layout_h_3->setStretch(i,1);
    }
    this->layout_h_3->setStretch(8,2);

    //button attributes
    foreach (QToolButton *b, this->list_button) {
        connect(b,SIGNAL(clicked(bool)),this,SLOT(clicked_slot(bool)),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
        b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        b->setAutoRepeat(true);
        b->setFocusPolicy(Qt::NoFocus);
    }

    //digital keyboard
    this->keyboard_digit = new MDigitVirtualKeyboard(this);

    //main layout
    this->layout_h_main = new QHBoxLayout();
    this->layout_h_main->addLayout(this->layout_v);
    this->layout_h_main->addWidget(this->keyboard_digit);
    this->layout_h_main->setStretch(0,3);
    this->layout_h_main->setStretch(1,1);
    this->layout_h_main->setMargin(0);
    this->setLayout(this->layout_h_main);
    this->setFocusPolicy(Qt::NoFocus);
}

MVirtualKeyboard::~MVirtualKeyboard()
{
    foreach (QToolButton *b, this->list_button) {
        M_DELETE_TO_NULL(b);
    }
    this->list_button.clear();
    M_DELETE_TO_NULL(this->layout_h_1);
    M_DELETE_TO_NULL(this->layout_h_2);
    M_DELETE_TO_NULL(this->layout_h_3);
    M_DELETE_TO_NULL(this->layout_h_4);
    M_DELETE_TO_NULL(this->layout_v);
    M_DELETE_TO_NULL(this->keyboard_digit);
    M_DELETE_TO_NULL(this->layout_h_main);
}

void MVirtualKeyboard::clicked_slot(bool)
{
    QToolButton *b = M_SENDER_DYNAMIC_CAST(QToolButton);
    if(b){
        if(QRegExp("^[A-Za-z]$").exactMatch(b->text())){
            QWidget *w=qApp->focusWidget();
            if(w){
                QKeyEvent *e=new QKeyEvent(QEvent::KeyPress,(int)b->text().toUpper().data()->toLatin1(),Qt::NoModifier,b->text());
                qApp->postEvent(w,e);
                e=new QKeyEvent(QEvent::KeyRelease,(int)b->text().toUpper().data()->toLatin1(),Qt::NoModifier,b->text());
                qApp->postEvent(w,e);
            }
            return ;
        }
        if(QRegExp("^[-_/\\\\<>,.:;?=]$").exactMatch(b->text())
                || b->text() == "&&"){
            QWidget *w=qApp->focusWidget();
            if(w){
                QKeyEvent *e=new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,b->text().mid(0,1));
                qApp->postEvent(w,e);
                e=new QKeyEvent(QEvent::KeyRelease,Qt::Key_A,Qt::NoModifier,b->text().mid(0,1));
                qApp->postEvent(w,e);
            }
            return ;
        }
        if(b->objectName() == this->prefixName + "toolButton_cap"){
            this->upper = !this->upper;
            QList<QToolButton*> l=this->findChildren<QToolButton*>(QRegExp(QString("^%1toolButton_[a-zA-Z]$").arg(this->prefixName)));
            foreach (QToolButton *button, l) {
                if(button){
                    this->upper ? button->setText(button->text().toUpper()) : button->setText(button->text().toLower());
                }
            }
            return ;
        }
    }
}

/*******************************************************************MDigitVirtualKeyboard:begin**********/
MDigitVirtualKeyboard::MDigitVirtualKeyboard(QWidget *parent) : QWidget(parent)
{
    this->prefixName = QUuid::createUuid().toString().replace("-","").replace("{","").replace("}","") + "_";
    //digital keybord
    this->layout_grid = new QGridLayout();
    for(int i = 7; i < 10; i++){
        QToolButton *toolButton_0 = new QToolButton(this);
        toolButton_0->setObjectName(this->prefixName + QString("toolButton_%1").arg(i));
        toolButton_0->setText(QString("%1").arg(i));
        this->list_button << toolButton_0;
        this->layout_grid->addWidget(toolButton_0,0,i-7);
    }
    for(int i = 4; i < 7; i++){
        QToolButton *toolButton_0 = new QToolButton(this);
        toolButton_0->setObjectName(this->prefixName + QString("toolButton_%1").arg(i));
        toolButton_0->setText(QString("%1").arg(i));
        this->list_button << toolButton_0;
        this->layout_grid->addWidget(toolButton_0,1,i-4);
    }
    for(int i = 1; i < 4; i++){
        QToolButton *toolButton_0 = new QToolButton(this);
        toolButton_0->setObjectName(this->prefixName + QString("toolButton_%1").arg(i));
        toolButton_0->setText(QString("%1").arg(i));
        this->list_button << toolButton_0;
        this->layout_grid->addWidget(toolButton_0,2,i-1);
    }
    QToolButton *toolButton_0 = new QToolButton(this);
    toolButton_0->setObjectName(this->prefixName + QString("toolButton_%1").arg(0));
    toolButton_0->setText(QString("%1").arg(0));
    this->list_button << toolButton_0;
    this->layout_grid->addWidget(toolButton_0,3,0);

    QToolButton *toolButton_del = new QToolButton(this);
    toolButton_del->setObjectName(this->prefixName + "toolButton_del");
    toolButton_del->setText("Del");
    this->list_button << toolButton_del;
    this->layout_grid->addWidget(toolButton_del,3,1,1,2);

    //button attributes
    foreach (QToolButton *b, this->list_button) {
        connect(b,SIGNAL(clicked(bool)),this,SLOT(clicked_slot(bool)),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
        b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        b->setAutoRepeat(true);
        b->setFocusPolicy(Qt::NoFocus);
    }
    //main layout
    this->layout_grid->setMargin(0);
    this->setLayout(this->layout_grid);
    this->setFocusPolicy(Qt::NoFocus);
}

MDigitVirtualKeyboard::~MDigitVirtualKeyboard()
{
    foreach (QToolButton *b, this->list_button) {
        M_DELETE_TO_NULL(b);
    }
    this->list_button.clear();
    M_DELETE_TO_NULL(this->layout_grid);
}

void MDigitVirtualKeyboard::clicked_slot(bool)
{
    QToolButton *b = M_SENDER_DYNAMIC_CAST(QToolButton);
    if(b){
        if(QRegExp("^[0-9]$").exactMatch(b->text())){
            QWidget *w=qApp->focusWidget();
            if(w){
                QKeyEvent *e=new QKeyEvent(QEvent::KeyPress,(int)b->text().toUpper().data()->toLatin1(),Qt::NoModifier,b->text());
                qApp->postEvent(w,e);
                e=new QKeyEvent(QEvent::KeyRelease,(int)b->text().toUpper().data()->toLatin1(),Qt::NoModifier,b->text());
                qApp->postEvent(w,e);
            }
            return ;
        }
        if(b->objectName() == this->prefixName + "toolButton_del"){
            QWidget *w=qApp->focusWidget();
            if(w){
                QKeyEvent *e=new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier);
                qApp->postEvent(w,e);
                e=new QKeyEvent(QEvent::KeyRelease,Qt::Key_Backspace,Qt::NoModifier);
                qApp->postEvent(w,e);
            }
            return ;
        }
    }
}

/*******************************************************************MListPictureView:begin**********/

MListPictureView::MListPictureView(QWidget *parent) : QWidget(parent)
{
    //defaul index
    this->index_current = -1;
    this->hover_left = false;
    this->hover_right = false;
    this->interval_default = 1000 * 5;
    connect(&this->timer,SIGNAL(timeout()),this,SLOT(next()),M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);
}

MListPictureView::~MListPictureView(){  this->stop();}

const QList<QPixmap> &MListPictureView::pictures() const{ return this->list_picture;}

int MListPictureView::count() const{ return this->list_picture.size();}

int MListPictureView::currentIndex() const{ return this->index_current;}

bool MListPictureView::isRunning() const{ return this->timer.isActive();}

void MListPictureView::add(const QPixmap &map)
{
    this->list_picture.append(map);
    this->update();
}
void MListPictureView::clear()
{
    this->list_picture.clear();
    this->index_current = -1;
    this->update();
}

void MListPictureView::setCurrentIndex(int index)
{
    if(index < this->list_picture.size()
            && index >= 0){
        this->index_current = index;
    }
    this->update();
}

void MListPictureView::next()
{
    if(this->index_current >= 0){
        this->index_current++;
        if(this->index_current >= this->list_picture.size()){
            this->index_current = 0;
        }
    }
    this->update();
}

void MListPictureView::preNext()
{
    if(this->index_current >= 0){
        this->index_current--;
        if(this->index_current < 0){
            this->index_current = this->list_picture.size() - 1;
        }
    }
    this->update();
}

void MListPictureView::stop(){ this->timer.stop();}

void MListPictureView::start(int ms)
{
    this->interval_default = ms;
    this->timer.start(ms);
}

void MListPictureView::paintEvent(QPaintEvent *)
{
    //prepare picture
    QPixmap map;
    if(this->index_current >= 0
            && this->index_current < this->list_picture.size()){
        map = this->list_picture.at(this->index_current);
    }
    QImage mage = map.toImage();
    if(mage.isNull()){
        mage = QImage(this->width(),this->height(),QImage::Format_RGB888);
        QPainter p(&mage);
        p.fillRect(mage.rect(),Qt::white);
    }

    //diameter of the button
    qreal side = this->height() / 10;
    this->zhijin = side;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //background
    painter.drawImage(0,0,
                      mage.scaled(this->width(),
                                  this->height(),
                                  Qt::IgnoreAspectRatio));
    painter.save();
    painter.translate(side, this->height() / 2);
    //left button clicked
    if(this->hover_left){
        painter.setBrush(Qt::red);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(-side / 2,-side / 2, side, side);
    }
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::blue);
    painter.drawLine(-side / 2,0, 0,-side / 2);
    painter.drawLine(-side / 2,0, 0,side / 2);

    painter.restore();
    painter.save();
    painter.translate(this->width() - side,this->height() / 2);
    //right button clicked
    if(this->hover_right){
        painter.setBrush(Qt::red);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(-side / 2,-side / 2, side, side);
    }
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::blue);
    painter.drawLine(side / 2,0, 0,-side / 2);
    painter.drawLine(side / 2,0, 0,side / 2);

    //text
    painter.restore();
    int width_text = this->width() / 10;
    int height_text = this->height() / 10;
    painter.translate(this->width() - width_text, this->height() - height_text);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::red);
    painter.setFont( QFont("Times", 10, QFont::Bold));
    painter.drawText(0, 0, QString("%1/%2").arg(this->index_current + 1).arg(this->list_picture.size()));
}

void MListPictureView::mouseMoveEvent(QMouseEvent *e)
{
    // hover
    QPoint p = e->pos();
    if(this->isLeftButton(p)){
        //stop timer on hover
        this->stop();
        this->hover_left = true;
        this->update();
        return ;
    }
    if(this->isRightButton(p)){
        this->stop();
        this->hover_right = true;
        this->update();
        return ;
    }
    if(!this->isRunning()){
        this->start(this->interval_default);
    }
    this->hover_left = false;
    this->hover_right = false;
    this->update();
}

void MListPictureView::mouseReleaseEvent(QMouseEvent *e)
{
    QPoint p = e->pos();
    if(this->isLeftButton(p)){
        this->preNext();
        return ;
    }
    if(this->isRightButton(p)){
        this->next();
        return ;
    }
    if(this->index_current >= 0){
        emit this->clicked(this->index_current);
    }
}

void MListPictureView::enterEvent(QEvent *e)
{
    (void)e;
    this->setMouseTracking(true);
}

void MListPictureView::leaveEvent(QEvent *e)
{
    (void)e;
    this->setMouseTracking(false);
}

bool MListPictureView::isLeftButton(const QPoint &p)
{
    QPoint yuandian(this->zhijin,this->height() / 2);
    QPoint start_left(yuandian.x() - this->zhijin / 2, yuandian.y() - this->zhijin / 2);
    QPoint end_left(yuandian.x() + this->zhijin / 2, yuandian.y() + this->zhijin / 2);

    return p.x() >= start_left.x()
            && p.y() >= start_left.y()
            && p.x() <= end_left.x()
            && p.y() <= end_left.y();
}

bool MListPictureView::isRightButton(const QPoint &p)
{
    QPoint yuandian_right(this->width() - this->zhijin,this->height() / 2);
    QPoint start_right(yuandian_right.x() - this->zhijin / 2,yuandian_right.y() - this->zhijin / 2);
    QPoint end_right(yuandian_right.x() + this->zhijin / 2,yuandian_right.y() + this->zhijin / 2);

    return p.x() >= start_right.x()
            && p.y() >= start_right.y()
            && p.x() <= end_right.x()
            && p.y() <= end_right.y();
}
/*******************************************************************MAbstractSubject:begin**********/
MAbstractSubject::MAbstractSubject(){}

MAbstractSubject::~MAbstractSubject(){}

void MAbstractSubject::addObserver(MAbstractObserver *o)
{
    QMutexLocker locker(&this->mutex_list_observer);
    if(o && !this->list_observer.contains(o)){
        this->list_observer << o;
    }
}

void MAbstractSubject::removeObserver(MAbstractObserver *o)
{
    if(o){
        QMutexLocker locker(&this->mutex_list_observer);
        this->list_observer.removeOne(o);
    }
}
/*******************************************************************MAbstractObserver:begin**********/
MAbstractObserver::MAbstractObserver(){}

MAbstractObserver::~MAbstractObserver(){}

/*******************************************************************MTimeQLabel:begin**********/
MTimeQLabel::MTimeQLabel(QWidget *p) : QLabel(p)
{
    timer.setParent(this);
    timer.start(1000 * 1);
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
}

MTimeQLabel::~MTimeQLabel()
{
    timer.stop();
}

void MTimeQLabel::timeout_slot()
{
    setText(M_TIME_NOW_SECONDS);
}

/*******************************************************************MQmlTool:begin**********/

MQmlTool::MQmlTool(QObject *parent) : QObject(parent){}

QString MQmlTool::getTime()
{
    return M_TIME_NOW_MILLISECONDS;
}

QByteArray MQmlTool::get_data_from_file(const QString &file)
{
    return MTL::get_data_from_file(file);
}

void MQmlTool::set_config(const QString &f, const QString &key, const QVariant &value)
{
    MTL::set_config(f,key,value);
}

void MQmlTool::set_data_2_file(const QString &file, const QByteArray &data, int type)
{
    MTL::set_data_2_file(file,data,(MTL::WriteType)type);
}

QVariant MQmlTool::get_config(const QString &f, const QString &key)
{
    return MTL::get_config(f,key);
}


void MQmlTool::log(const QString &lg, const QString &type)
{
    HITLOG(lg,type);
}

/*******************************************************************MQmlKeyboardInputDialog:begin**********/

MQmlKeyboardInputDialog::MQmlKeyboardInputDialog(QObject *parent) : QObject(parent)
{
    timer.start(1000);
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout()));
    time_left_second = 120;

    widget_main = new QWidget(0);
    widget_main->setFixedSize(650,320);
    MTL::set_center(widget_main);
    widget_main->setWindowFlags(widget_main->windowFlags() | Qt::FramelessWindowHint
                            #ifdef Q_OS_LINUX
                                | Qt::X11BypassWindowManagerHint
                            #endif
                                );
    widget_main->setWindowModality(Qt::ApplicationModal);

    layout_v = new QVBoxLayout();
    layout_h = new QHBoxLayout();
    edit = new QLineEdit(widget_main);
    edit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    edit->setClearButtonEnabled(true);

    button_ok = new QToolButton(widget_main);
    button_ok->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button_ok->setText("Ok");
    connect(button_ok,SIGNAL(clicked(bool)),this,SLOT(clicked_slot_ok(bool)));
    button_cancel = new QToolButton(widget_main);
    button_cancel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button_cancel->setText("Cancel");
    connect(button_cancel,SIGNAL(clicked(bool)),this,SLOT(clicked_slot_cancel(bool)));

    kb = new MVirtualKeyboard(widget_main);
    kb->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    label_time = new QLabel(widget_main);
    label_time->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    label_time->setText(QString("%1").arg(time_left_second));
    spacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);

    widget_main->setLayout(layout_v);
    layout_v->addWidget(edit);
    layout_v->addWidget(kb);
    layout_v->addLayout(layout_h);

    layout_h->addWidget(label_time);
    layout_h->addSpacerItem(spacer);
    layout_h->addWidget(button_ok);
    layout_h->addWidget(button_cancel);
    layout_h->setStretch(0,1);
    layout_h->setStretch(1,10);
    layout_h->setStretch(2,1);
    layout_h->setStretch(3,1);

    layout_v->setStretch(0,1);
    layout_v->setStretch(1,5);
    layout_v->setStretch(2,1);

    this->widget_main->setStyleSheet(MTL::get_data_from_file(":/QRC/qss/MQmlKeyboardInputDialog.qss"));
}

MQmlKeyboardInputDialog::~MQmlKeyboardInputDialog()
{
    timer.stop();
    M_DELETE_TO_NULL(layout_h);
    M_DELETE_TO_NULL(layout_v);
    M_DELETE_TO_NULL(widget_main);
}

QString MQmlKeyboardInputDialog::text() const
{
    return this->edit->text();
}

bool MQmlKeyboardInputDialog::isVisible() const
{
    return widget_main->isVisible();
}

QString MQmlKeyboardInputDialog::styleSheet() const
{
    return this->widget_main->styleSheet();
}

void MQmlKeyboardInputDialog::show()
{
    setVisible();
}

void MQmlKeyboardInputDialog::hide()
{
    setVisible(false);
}

void MQmlKeyboardInputDialog::setVisible(bool v)
{
    widget_main->setVisible(v);
    if(v){
        time_left_second = 120;
    }
}

void MQmlKeyboardInputDialog::setText(const QString &data)
{
    this->edit->setText(data);
}

void MQmlKeyboardInputDialog::setStyleSheet(const QString &sheet)
{
    this->widget_main->setStyleSheet(sheet);
}

void MQmlKeyboardInputDialog::timeout()
{
    if(this->isVisible()){
        this->time_left_second--;
        this->label_time->setText(QString("%1").arg(time_left_second));
        if(time_left_second <= 0){
            this->clicked_slot_cancel(true);
        }
    }
}

void MQmlKeyboardInputDialog::clicked_slot_ok(bool)
{
    this->setVisible(false);
    emit this->ok();
}

void MQmlKeyboardInputDialog::clicked_slot_cancel(bool)
{
    this->setVisible(false);
    emit this->cancel();
}
/*******************************************************************MHeaderItem:begin**********/
MHeaderItem::MHeaderItem(int index, const QString &name)
{
    this->index = index;
    this->name = name;
}

MHeaderItem::~MHeaderItem(){}

MHeaderItem::MHeaderItem(const MHeaderItem &other)
{
    index = other.index;
    name = other.name;
}
MHeaderItem &MHeaderItem::operator =(const MHeaderItem &other)
{
    if(this != &other){
        index = other.index;
        name = other.name;
    }
    return *this;
}
bool MHeaderItem::operator ==(const MHeaderItem &it) const{    return index == it.index;}

bool MHeaderItem::isValid() const{   return index > -1;}

QString MHeaderItem::toString() const{    return QString("%1,%2").arg(index).arg(name);}

QString MHeaderItem::toJsonString(QJsonDocument::JsonFormat f) const
{
    return MTL::get_str_from_QJsonObject(toJsonObject(),f);
}

QJsonObject MHeaderItem::toJsonObject() const
{
    QJsonObject json;
    json.insert(M_CAST_STRING(index),index);
    json.insert(M_CAST_STRING(name),name);
    return json;
}

/*******************************************************************MXmlTreeWidget:begin**********/

MXmlTreeWidget::MXmlTreeWidget(QWidget *parent) : QTreeWidget(parent)
{
    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon), QIcon::Normal, QIcon::On);
}

bool MXmlTreeWidget::write(QIODevice *device)
{
    if(device){
        const int IndentSize = 4;

        QTextStream out(device);
        domDocument.save(out, IndentSize);
        return true;
    }
    return false;
}

bool MXmlTreeWidget::read(const QByteArray &data)
{
    domElementForItem.clear();
    domDocument.clear();
    clear();

    QTreeWidgetItem *header = new QTreeWidgetItem;
    header->setText(0,tr("key"));
    header->setText(1,tr("value"));
    setHeaderItem(header);
    this->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    if(data.length() > 0){
        bool ok = this->domDocument.setContent(data);
        if(ok){
            QDomElement root = domDocument.documentElement();

            disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
                       this, SLOT(updateDomElement_slot(QTreeWidgetItem*,int)));

            this->parse_element_by_recursion(root);

            connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
                    this, SLOT(updateDomElement_slot(QTreeWidgetItem*,int)));
            return true;
        }
    }
    return false;
}

QString MXmlTreeWidget::get_str_json_from_QDomNamedNodeMap(const QDomNamedNodeMap &map, QJsonDocument::JsonFormat format)
{
    QJsonObject json;
    for(int i = 0; i < map.size(); i++){
        QDomNode node = map.item(i);
        if(node.nodeType() == QDomNode::AttributeNode){
            QDomAttr at = node.toAttr();
            json.insert(at.name(),at.value());
        }
    }
    return MTL::get_str_from_QJsonObject(json,format);
}

QByteArray MXmlTreeWidget::get_str_formart_from_XmlString(const QByteArray &data)
{
    QByteArray ret;
    if(data.length() > 0){
        QDomDocument *d = new QDomDocument;
        MScopedPointer<QDomDocument> pp(d);
        (void)pp;
        if(d->setContent(data)){
            ret = d->toByteArray();
        }
    }
    return ret;
}

QByteArray MXmlTreeWidget::get_str_from_QDomElement(const QDomElement &e)
{
    QByteArray ret;
    if(!e.isNull()){
        QDomDocument doc;
        QDomElement rootElement = doc.createElement(e.tagName());
        if(e.hasAttributes()){
            QDomNamedNodeMap map = e.attributes();
            for(int i = 0; i < map.size(); i++){
                rootElement.setAttribute(map.item(i).toAttr().name(),
                                         map.item(i).toAttr().value());
            }
        }
        if(e.hasChildNodes()){
            QDomNodeList list = e.childNodes();
            for(int i = 0; i < list.size(); i++){
                rootElement.appendChild(list.at(i).cloneNode());
            }
        }
        doc.appendChild(rootElement);
        ret = doc.toByteArray();
    }
    return ret;
}


QDomElement MXmlTreeWidget::get_element_by_id(const QByteArray &data, const QString &id)
{
    QDomElement ret;
    QDomDocument doc;
    bool ok = doc.setContent(data);
    if(ok){
        QDomElement e = doc.documentElement();
        ret = get_element_by_id(e,id);
    }
    return ret;
}

QString MXmlTreeWidget::get_attribute_by_id(const QByteArray &data, const QString &id, const QString &attr)
{
    QDomElement e = get_element_by_id(data,id);
    return e.attribute(attr);
}

QString MXmlTreeWidget::get_value_by_id(const QByteArray &data, const QString &id)
{
    QDomElement e = get_element_by_id(data,id);
    QDomNodeList list = e.childNodes();
    if(list.length() > 0){
        return list.at(0).toText().data();
    }
    return "";
}

QByteArray MXmlTreeWidget::toByteArray(int indent) const
{
    return domDocument.toByteArray(indent);
}

QByteArray MXmlTreeWidget::set_attribute_by_id(const QByteArray &data,
                                               const QString &id,
                                               const QString &attrName,
                                               const QString &attrValue,
                                               int indent)
{
    QDomDocument doc;
    bool ok = doc.setContent(data);
    if(ok){
        QDomElement e = doc.documentElement();
        QDomElement ele = get_element_by_id(e,id);
        if(!ele.isNull()){
            ele.setAttribute(attrName,attrValue);
            return doc.toByteArray(indent);
        }
    }
    return data;
}
QDomElement MXmlTreeWidget::get_element_by_id(const QDomElement &e,const QString &id)
{
    QDomElement ret;
    if(e.isElement()){
        if(e.hasAttributes()){
            if(e.attribute("id") == id){
                return ret = e;
            }
        }
        QDomNodeList list = e.childNodes();
        for(int i = 0; i < list.size(); i++){
            QDomNode node = list.at(i);
            if(node.nodeType() == QDomNode::ElementNode){
                ret = get_element_by_id(node.toElement(),id);
                if(!ret.isNull()){
                    return  ret;
                }
            }
        }
    }
    return ret;
}

void MXmlTreeWidget::parse_element_by_recursion(const QDomElement &element, QTreeWidgetItem *parentItem)
{
    if(element.isElement()){
        QTreeWidgetItem *item = this->createItem(element,parentItem);
        item->setText(0,element.tagName());
        item->setIcon(0,folderIcon);
        //get attributes
        if(element.hasAttributes()){
            QDomNamedNodeMap map = element.attributes();
            for(int i = 0; i < map.size(); i++){
                QTreeWidgetItem *item_attr = this->createItem(element,item);
                //ONLY allow attr can be editable
                item_attr->setFlags(item->flags() | Qt::ItemIsEditable);
                item_attr->setText(0,map.item(i).toAttr().name());
                item_attr->setText(1,map.item(i).toAttr().value());
            }
        }
        //get childs
        if(element.hasChildNodes()){
            QDomNodeList list = element.childNodes();
            for(int i = 0; i < list.size(); i++){
                QDomNode node = list.at(i);
                QDomNode::NodeType t = node.nodeType();
                if(t == QDomNode::ElementNode){
                    parse_element_by_recursion(node.toElement(),item);
                }
            }
        }
    }
}

bool MXmlTreeWidget::edit(const QModelIndex &index, QAbstractItemView::EditTrigger trigger, QEvent *event)
{
    //disable edit of column 0
    if(index.column() == 0){
        return false;
    }
    return QTreeWidget::edit(index,trigger,event);
}

void MXmlTreeWidget::updateDomElement_slot(QTreeWidgetItem *item, int column)
{
    QDomElement element = domElementForItem.value(item);
    if (!element.isNull()) {
        //ONLY allow editable for column 1
        switch (column) {
        case 1:
            element.setAttribute(item->text(0),item->text(column));
            break;
        default:
            break;
        }
    }
}

QTreeWidgetItem *MXmlTreeWidget::createItem(const QDomElement &element, QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item = NULL;
    parentItem ?
                item = new QTreeWidgetItem(parentItem) :
            item = new QTreeWidgetItem((QTreeWidget *)this);
    domElementForItem.insert(item, element);
    return item;
}

/*******************************************************************MTiXmlDocument:begin**********/
#ifdef M_ENABLE_TINYXML_262
MTiXmlDocument::MTiXmlDocument() : TiXmlDocument(){}

MTiXmlDocument::MTiXmlDocument(const char *documentName) : TiXmlDocument(documentName){}

MTiXmlDocument::MTiXmlDocument(const MTiXmlDocument &copy) : TiXmlDocument(copy){}

MTiXmlDocument &MTiXmlDocument::operator =(const MTiXmlDocument &copy){
    if(&copy != this){
        TiXmlDocument::operator =(copy);
    }
    return *this;
}

MTiXmlDocument::~MTiXmlDocument(){}

TiXmlElement *MTiXmlDocument::get_element_by_id(TiXmlElement *e, const char *id)
{
    TiXmlElement *ret = NULL;
    if(e && id && ::strlen(id) > 0){
        if(e->Attribute("id") && ::strcmp(e->Attribute("id"),id) == 0){
            return  ret = e;
        }
        if(!e->NoChildren()){
            for(TiXmlElement *child = e->FirstChildElement(); child; child = child->NextSiblingElement()){
                ret = get_element_by_id(child,id);
                if(ret) return ret;
            }
        }
    }
    return ret;
}

bool MTiXmlDocument::set_attribute_by_id(TiXmlElement *e,
                                         const char *id,
                                         const char *attrName,
                                         const char *attrValue)
{
    bool ret = false;
    TiXmlElement *target = get_element_by_id(e,id);
    if(target && attrName && ::strlen(attrName) && attrValue){
        target->SetAttribute(attrName,attrValue);
        ret = true;
    }
    return ret;
}

QString MTiXmlDocument::get_attribute_by_id(TiXmlElement *e, const char *id, const char *attrName)
{
    QString ret = "";
    TiXmlElement *target = get_element_by_id(e,id);
    if(target && attrName && ::strlen(attrName)){
        ret = QString(target->Attribute(attrName));
    }
    return ret;
}

QList<QPair<QString, QString> > MTiXmlDocument::get_attributes_from_TiXmlElement(TiXmlElement *e)
{
    QList<QPair<QString,QString> > ret;
    for(TiXmlAttribute *att = e->FirstAttribute(); att && e; att = att->Next()){
        ret << qMakePair(QString(att->Name()),QString(att->Value()));
    }
    return ret;
}

QByteArray MTiXmlDocument::toByteArray() const
{
    TiXmlPrinter printer;
    printer.SetIndent("\t");
    Accept(&printer);
    return QByteArray(printer.CStr(),printer.Size());
}
#endif //M_ENABLE_TINYXML_262

/*******************************************************************MObject:begin**********/
MObject::MObject(){  _id = QUuid::createUuid().toString();}

MObject::~MObject(){ }

QString MObject::id() const{    return _id;}

/*********************************TCP server using thread pool*******************************************/

/*******************************************************************MTcpConnectionHandler:begin**********/
MTcpConnectionHandler::MTcpConnectionHandler() : QTcpSocket(){
    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpConnectionHandler),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    MDG << "new QTcpSocket:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpConnectionHandler::~MTcpConnectionHandler(){
    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpConnectionHandler),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("socketDescriptor",socketDescriptor());
    json.insert("state",MTL::get_str_from_enum_value<QAbstractSocket>("SocketState",state()));
    MDG << "delete QTcpSocket:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpConnectionHandler *MTcpConnectionHandler::createNew(){  return new MTcpConnectionHandler();}

/*******************************************************************MTcpThreadHandler:begin**********/
MTcpThreadHandler::MTcpThreadHandler(QSettings *setgs, MTcpConnectionHandler *cnn) : QThread()
{
    mutex = new QMutex(QMutex::Recursive);
    moveToThread(this);

    settings = setgs;
    this->cnn = cnn;

    sem.release(setgs->value("MaxConnnectionPerThread",100).toInt());

    start();

    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("default QSemaphore",sem.available());
    MDG << "new thread handler:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpThreadHandler::~MTcpThreadHandler()
{
    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    MDG << "delete thread handler:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);

    quit();
    wait();
    M_DELETE_TO_NULL(mutex);
}

void MTcpThreadHandler::run()
{
    try{
        exec();
    }catch(...){
        MDG_WARNING << "unknown error happened in thread handler.";
    }
    //delete the object in my own thread.
    foreach (QPointer<MTcpConnectionHandler> p, list_connection) {
        MTcpConnectionHandler *tcp = p.data();
        /*
         * Do NOT accept it`s signal.
         * Cause QTcpSocket`s ~QTcpSocket() will emit destroyed(QObject*) and disconnected() signal.
         * */
        if(tcp){
            disconnect(tcp,SIGNAL(destroyed(QObject*)),this,SLOT(destroyed_slot(QObject*)));
            disconnect(tcp,SIGNAL(disconnected()),tcp,SLOT(deleteLater()));
        }
        delete tcp;
    }
    list_connection.clear();
}

void MTcpThreadHandler::handleConnection(qintptr socketDescriptor)
{
    QMutexLocker lock(mutex);

    //create object in my own thread.
    MTcpConnectionHandler *ne = cnn->createNew();

    //auto delete when disconnected.
    connect(ne,SIGNAL(disconnected()),ne,SLOT(deleteLater()));

    //Use queued connection,make sure the QPointer is already set NULL when clearEmptyPointer().
    connect(ne,
            SIGNAL(destroyed(QObject*)),
            this,
            SLOT(destroyed_slot(QObject*)),
            M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);

    list_connection << QPointer<MTcpConnectionHandler>(ne);

    bool ok = ne->setSocketDescriptor(socketDescriptor);
    if(!ok){
        MDG_WARNING << QString("cannot initialize socket:[%1],err:[%2]")
                       .arg(socketDescriptor)
                       .arg(ne->errorString());
        ne->deleteLater();
    }
    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("socketDescriptor",socketDescriptor);
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert("MTcpConnectionHandler list",list_connection.length());
    json.insert("TCP handler",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)ne));

    MDG << "handle new TCP:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpThreadHandler::clearEmptyPointer()
{
    QMutexLocker lock(mutex);
    for(int i = list_connection.length() - 1; i >= 0; i--){
        if(list_connection.at(i).isNull()){
            list_connection.removeAt(i);
            sem.release();
        }
    }

    QJsonObject json;
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert("MTcpConnectionHandler list",list_connection.length());
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    MDG << "release QSemaphore:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpThreadHandler::destroyed_slot(QObject *o)
{
    (void)o;
    QTimer::singleShot(100,this,SLOT(clearEmptyPointer()));
}

bool MTcpThreadHandler::isAvailable() const
{
    QMutexLocker lock(mutex);
    return sem.available() > 0;
}

bool MTcpThreadHandler::isEmpty() const
{
    QMutexLocker lock(mutex);
    return sem.available() == settings->value("MaxConnnectionPerThread",100).toInt();
}

int MTcpThreadHandler::available() const
{
    QMutexLocker lock(mutex);
    return sem.available();
}

int MTcpThreadHandler::establishedTCPs() const
{
    QMutexLocker lock(mutex);
    return settings->value("MaxConnnectionPerThread",100).toInt() - sem.available();
}

bool MTcpThreadHandler::tryAcquire()
{
    bool ret = false;
    if(mutex->tryLock()){
        ret = sem.tryAcquire();
        mutex->unlock();
    }
    return ret;
}
/*******************************************************************MTcpThreadPool:begin**********/
MTcpThreadPool::MTcpThreadPool(QSettings *set, MTcpConnectionHandler *cnn)
{
    this->settings = set;
    this->cnn = cnn;
    timer_clean.start(set->value("cleanupInterval",1000 * 60 * 1).toInt());
    connect(&timer_clean,SIGNAL(timeout()),this,SLOT(cleanup()));
}

MTcpThreadPool::~MTcpThreadPool()
{
    foreach (MTcpThreadHandler *thread, list_thread) {
        delete thread;
    }
    list_thread.clear();
    timer_clean.stop();
}

MTcpThreadHandler *MTcpThreadPool::getAvialableThreadHandler()
{
    //find a avilable thread
    foreach (MTcpThreadHandler *thread, list_thread) {
        //acquire the source now
        if(thread->tryAcquire()){
            return thread;
        }
    }
    //create new
    int maxThreads = settings->value("maxThreads",100).toInt();
    if(list_thread.length() < maxThreads){
        MTcpThreadHandler *thread = new MTcpThreadHandler(settings,cnn);
        //acquire the source now
        bool ok = thread->tryAcquire();
        M_ASSERT(ok);
        list_thread << thread;
        return thread;
    }
    return 0;
}

void MTcpThreadPool::cleanup()
{
    int minThreads = settings->value("minThreads",0).toInt();
    int counter = 0;
    //find the empty thread
    for(int i = list_thread.length() - 1; i >= 0; i--){
        MTcpThreadHandler *t = list_thread.at(i);
        if(t->isEmpty()){
            if(++counter > minThreads){
                delete t;
                list_thread.removeAt(i);
                break; // remove only one handler in each interval
            }
        }
    }
}
/*******************************************************************MTcpListener:begin**********/
MTcpListener::MTcpListener(QSettings *settings, MTcpConnectionHandler *requestHandler, QObject *parent)
    :QTcpServer(parent)
{
    pool = 0;
    this->settings = settings;
    cnn = requestHandler;

    qRegisterMetaType<qintptr>("qintptr");
    listen();
}

MTcpListener::~MTcpListener()
{
    close();
    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    MDG << "delete listener:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpListener::listen()
{
    if (!pool)
    {
        pool = new MTcpThreadPool(settings,cnn);
    }
    QString host = settings->value("host").toString();
    int port = settings->value("port").toInt();
    QHostAddress hst = host.isEmpty() ? QHostAddress::Any : QHostAddress(host);
    QTcpServer::listen(hst, port);
    if (!isListening())
    {
        MDG_WARNING << QString("Cannot bind on port %1: %2")
                       .arg(port)
                       .arg(errorString());
    }
    else {
        QJsonObject json;
        json.insert("ip",hst.toString());
        json.insert("port",port);
        json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
        MDG << "listen on:\n"
            << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
    }
}

void MTcpListener::close()
{
    QTcpServer::close();

    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("serverAddress",serverAddress().toString());
    json.insert("serverPort",serverPort());
    MDG << "listen close:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);

    M_DELETE_TO_NULL(pool);
}

void MTcpListener::incomingConnection(qintptr socketDescriptor)
{
    MTcpThreadHandler* freeHandler = NULL;
    if (pool)
    {
        freeHandler = pool->getAvialableThreadHandler();
    }

    // Let the handler process the new connection.
    if (freeHandler)
    {
        // The descriptor is passed via event queue because the handler lives in another thread
        QMetaObject::invokeMethod(freeHandler, "handleConnection", Qt::QueuedConnection, Q_ARG(qintptr, socketDescriptor));
    }
    else
    {
        // Reject the connection
        MDG_WARNING << "HttpListener: Too many incoming connections";
        QTcpSocket* socket = new QTcpSocket(this);
        socket->setSocketDescriptor(socketDescriptor);
        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
        //socket->write("HTTP/1.1 503 too many connections\r\nConnection: close\r\n\r\nToo many connections\r\n");
        socket->disconnectFromHost();
    }
}
/******************************************************* MKit::MTcpConnectionHandler2 ***/
MTcpConnectionHandler2::MTcpConnectionHandler2() : QTcpSocket(),MObject()
{
    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpConnectionHandler),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "new QTcpSocket:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpConnectionHandler2::~MTcpConnectionHandler2()
{
    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpConnectionHandler),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("socketDescriptor",socketDescriptor());
    json.insert("state",MTL::get_str_from_enum_value<QAbstractSocket>("SocketState",state()));
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "delete QTcpSocket:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

/******************************************************* MKit::MTcpThreadHandler2 ***/
MTcpThreadHandler2::MTcpThreadHandler2(QSettings *setgs) : QThread()
{
    mutex = new QMutex(QMutex::Recursive);
    moveToThread(this);

    settings = setgs;
    sem.release(setgs->value("MaxConnnectionPerThread",100).toInt());

    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("default QSemaphore",sem.available());
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "new thread handler:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpThreadHandler2::~MTcpThreadHandler2()
{
    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "delete thread handler:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
    M_DELETE_TO_NULL(mutex);
}

void MTcpThreadHandler2::run()
{
    try{
        exec();
    }catch(...){
        MDG_WARNING << "unknown error happened in thread handler.";
    }
    //delete the object in my own thread.
    foreach (QPointer<MTcpConnectionHandler2> p, list_connection) {
        MTcpConnectionHandler2 *tcp = p.data();
        /*
         * Do NOT accept it`s signal.
         * Cause QTcpSocket`s ~QTcpSocket() will emit destroyed(QObject*) and disconnected() signal.
         * */
        if(tcp){
            disconnect(tcp,SIGNAL(destroyed(QObject*)),this,SLOT(destroyed_slot(QObject*)));
            disconnect(tcp,SIGNAL(disconnected()),tcp,SLOT(deleteLater()));
        }
        delete tcp;
    }
    list_connection.clear();
}

void MTcpThreadHandler2::handleConnection(qintptr socketDescriptor)
{
    QMutexLocker lock(mutex);

    //create object in my own thread.
    MTcpConnectionHandler2 *ne = createTcpHandler();

    //auto delete when disconnected.
    connect(ne,SIGNAL(disconnected()),ne,SLOT(deleteLater()));

    //Use queued connection,make sure the QPointer is already set NULL when clearEmptyPointer().
    connect(ne,
            SIGNAL(destroyed(QObject*)),
            this,
            SLOT(destroyed_slot(QObject*)),
            M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);

    list_connection << QPointer<MTcpConnectionHandler2>(ne);

    bool ok = ne->setSocketDescriptor(socketDescriptor);
    if(!ok){
        MDG_WARNING << QString("cannot initialize socket:[%1],err:[%2]")
                       .arg(socketDescriptor)
                       .arg(ne->errorString());
        ne->deleteLater();
    }
    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("socketDescriptor",socketDescriptor);
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert("MTcpConnectionHandler list",list_connection.length());
    json.insert("TCP handler",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)ne));
    json.insert("TCP id",ne->id());
    json.insert(M_CAST_STRING(_id),_id);

    MDG << "handle new TCP:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpConnectionHandler2 *MTcpThreadHandler2::createTcpHandler()
{
    return new MTcpConnectionHandler2();
}

void MTcpThreadHandler2::clearEmptyPointer()
{
    QMutexLocker lock(mutex);
    for(int i = list_connection.length() - 1; i >= 0; i--){
        if(list_connection.at(i).isNull()){
            list_connection.removeAt(i);
            sem.release();
        }
    }

    QJsonObject json;
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert("MTcpConnectionHandler list",list_connection.length());
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "release QSemaphore:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpThreadHandler2::destroyed_slot(QObject *o)
{
    (void)o;
    QTimer::singleShot(100,this,SLOT(clearEmptyPointer()));
}

bool MTcpThreadHandler2::isAvailable() const
{
    QMutexLocker lock(mutex);
    return sem.available() > 0;
}

bool MTcpThreadHandler2::isEmpty() const
{
    QMutexLocker lock(mutex);
    return sem.available() == settings->value("MaxConnnectionPerThread",100).toInt();
}

int MTcpThreadHandler2::available() const
{
    QMutexLocker lock(mutex);
    return sem.available();
}

int MTcpThreadHandler2::establishedTCPs() const
{
    QMutexLocker lock(mutex);
    return settings->value("MaxConnnectionPerThread",100).toInt() - sem.available();
}

bool MTcpThreadHandler2::tryAcquire()
{
    bool ret = false;
    if(mutex->tryLock()){
        ret = sem.tryAcquire();
        mutex->unlock();
    }
    return ret;
}
/******************************************* MKit:MTcpThreadPool2 ***/
MTcpThreadPool2::MTcpThreadPool2(QSettings *settings)
{
    this->settings = settings;
    timer_clean.start(settings->value("cleanupInterval",1000 * 60 * 1).toInt());
    connect(&timer_clean,SIGNAL(timeout()),this,SLOT(cleanup()));
}

MTcpThreadPool2::~MTcpThreadPool2()
{
    timer_clean.stop();
    clear();
}

MTcpThreadHandler2 *MTcpThreadPool2::getAvialableThreadHandler()
{
    //find a avilable thread
    foreach (MTcpThreadHandler2 *thread, list_thread) {
        //acquire the source now
        if(thread->tryAcquire()){
            return thread;
        }
    }
    //create new
    int maxThreads = settings->value("maxThreads",100).toInt();
    if(list_thread.length() < maxThreads){
        MTcpThreadHandler2 *thread = createThreadHandler();
        //...
        thread->start();
        //acquire the source now
        bool ok = thread->tryAcquire();
        M_ASSERT(ok);
        list_thread << thread;
        return thread;
    }
    return 0;
}

void MTcpThreadPool2::clear()
{
    foreach (MTcpThreadHandler2 *thread, list_thread) {
        //...
        thread->quit();
        thread->wait();
        delete thread;
    }
    list_thread.clear();
}

void MTcpThreadPool2::cleanup()
{
    int minThreads = settings->value("minThreads",0).toInt();
    int counter = 0;
    //find the empty thread
    for(int i = list_thread.length() - 1; i >= 0; i--){
        MTcpThreadHandler2 *t = list_thread.at(i);
        if(t->isEmpty()){
            if(++counter > minThreads){
                //...
                t->quit();
                t->wait();
                delete t;
                list_thread.removeAt(i);
                break; // remove only one handler in each interval
            }
        }
    }
}

MTcpThreadHandler2 *MTcpThreadPool2::createThreadHandler()
{
    return new MTcpThreadHandler2(settings);
}

/******************************************* MKit:MTcpListener2 ***/
MTcpListener2::MTcpListener2(QSettings *settings, MTcpThreadPool2 *pool, QObject *parent) : QTcpServer(parent)
{
    this->pool = pool;
    this->settings = settings;
    qRegisterMetaType<qintptr>("qintptr");
    listen();
}

MTcpListener2::~MTcpListener2()
{
    close();
    M_DELETE_TO_NULL(pool);

    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    MDG << "delete listener:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpListener2::listen()
{
    QString host = settings->value("host").toString();
    int port = settings->value("port").toInt();
    QHostAddress hst = host.isEmpty() ? QHostAddress::Any : QHostAddress(host);
    QTcpServer::listen(hst, port);
    if (!isListening())
    {
        MDG_WARNING << QString("Cannot bind on port %1: %2")
                       .arg(port)
                       .arg(errorString());
    }
    else {
        QJsonObject json;
        json.insert("ip",hst.toString());
        json.insert("port",port);
        json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
        MDG << "listen on:\n"
            << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
    }
}

void MTcpListener2::close()
{
    QTcpServer::close();
    if(pool)
        pool->clear();

    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("serverAddress",serverAddress().toString());
    json.insert("serverPort",serverPort());
    MDG << "listen close:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpListener2::incomingConnection(qintptr socketDescriptor)
{
    MTcpThreadHandler2* freeHandler = NULL;
    if (pool)
    {
        freeHandler = pool->getAvialableThreadHandler();
    }

    // Let the handler process the new connection.
    if (freeHandler)
    {
        // The descriptor is passed via event queue because the handler lives in another thread
        QMetaObject::invokeMethod(freeHandler, "handleConnection", Qt::QueuedConnection, Q_ARG(qintptr, socketDescriptor));
    }
    else
    {
        // Reject the connection
        MDG_WARNING << "HttpListener: Too many incoming connections";
        QTcpSocket* socket = new QTcpSocket(this);
        socket->setSocketDescriptor(socketDescriptor);
        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
        //socket->write("HTTP/1.1 503 too many connections\r\nConnection: close\r\n\r\nToo many connections\r\n");
        socket->disconnectFromHost();
    }
}


/******************************************* MKit:MTcpFactory ***/

MTcpFactory::MTcpFactory()
{

}

MTcpFactory::~MTcpFactory()
{

}

QTcpSocket *MTcpFactory::creatSocket()
{
    return new QTcpSocket();
}

/******************************************* MKit:MTcpThreadHandler3 ***/

MTcpThreadHandler3::MTcpThreadHandler3(QSettings *setgs, MTcpFactory *MTcpFactory_): QThread()
{
    mutex = new QMutex(QMutex::Recursive);
    moveToThread(this);

    settings = setgs;
    this->MTcpFactory_ = MTcpFactory_;
    sem.release(setgs->value("MaxConnnectionPerThread",100).toInt());

    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("default QSemaphore",sem.available());
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "new thread handler:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

MTcpThreadHandler3::~MTcpThreadHandler3()
{
    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "delete thread handler:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
    M_DELETE_TO_NULL(mutex);
}

void MTcpThreadHandler3::run()
{
    try{
        exec();
    }catch(...){
        MDG_WARNING << "unknown error happened in thread handler.";
    }
    //delete the object in my own thread.
    foreach (QPointer<QTcpSocket> p, list_connection) {
        QTcpSocket *tcp = p.data();
        /*
         * Do NOT accept it`s signal.
         * Cause QTcpSocket`s ~QTcpSocket() will emit stateChanged(QAbstractSocket::UnconnectedState),disconnected() and destroyed(QObject*) signal.
         * */
        if(tcp){
            disconnect(tcp,SIGNAL(destroyed(QObject*)),this,SLOT(destroyed_slot(QObject*)));
            disconnect(tcp,SIGNAL(disconnected()),tcp,SLOT(deleteLater()));
        }
        delete tcp;
    }
    list_connection.clear();
}

void MTcpThreadHandler3::handleConnection(qintptr socketDescriptor)
{
    QMutexLocker lock(mutex);

    //create object in my own thread.
    QTcpSocket *ne = MTcpFactory_->creatSocket();

    //auto delete when disconnected.
    connect(ne,SIGNAL(disconnected()),ne,SLOT(deleteLater()));

    //Use queued connection,make sure the QPointer is already set NULL when clearEmptyPointer().
    connect(ne,
            SIGNAL(destroyed(QObject*)),
            this,
            SLOT(destroyed_slot(QObject*)),
            M_CONNECTION_TYPE_QUEUED_AND_UNIQUE);

    list_connection << QPointer<QTcpSocket>(ne);

    bool ok = ne->setSocketDescriptor(socketDescriptor);
    if(!ok){
        MDG_WARNING << QString("cannot initialize socket:[%1],err:[%2]")
                       .arg(socketDescriptor)
                       .arg(ne->errorString());
        ne->deleteLater();
    }
    QJsonObject json;
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("socketDescriptor",socketDescriptor);
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert("MTcpConnectionHandler list",list_connection.length());
    json.insert("TCP handler",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)ne));
    //json.insert("TCP id",ne->id());
    json.insert(M_CAST_STRING(_id),_id);

    MDG << "handle new TCP:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}


void MTcpThreadHandler3::clearEmptyPointer()
{
    QMutexLocker lock(mutex);
    for(int i = list_connection.length() - 1; i >= 0; i--){
        if(list_connection.at(i).isNull()){
            list_connection.removeAt(i);
            sem.release();
        }
    }
    QJsonObject json;
    json.insert("available QSemaphore",available());
    json.insert("established TCP",establishedTCPs());
    json.insert("MTcpConnectionHandler list",list_connection.length());
    json.insert("thread",MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert(M_CAST_STRING(_id),_id);
    MDG << "release QSemaphore:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpThreadHandler3::destroyed_slot(QObject *o)
{
    (void)o;
    QTimer::singleShot(100,this,SLOT(clearEmptyPointer()));
}

bool MTcpThreadHandler3::isAvailable() const
{
    QMutexLocker lock(mutex);
    return sem.available() > 0;
}

bool MTcpThreadHandler3::isEmpty() const
{
    QMutexLocker lock(mutex);
    return sem.available() == settings->value("MaxConnnectionPerThread",100).toInt();
}

int MTcpThreadHandler3::available() const
{
    QMutexLocker lock(mutex);
    return sem.available();
}

int MTcpThreadHandler3::establishedTCPs() const
{
    QMutexLocker lock(mutex);
    return settings->value("MaxConnnectionPerThread",100).toInt() - sem.available();
}

bool MTcpThreadHandler3::tryAcquire()
{
    bool ret = false;
    if(mutex->tryLock()){
        ret = sem.tryAcquire();
        mutex->unlock();
    }
    return ret;
}
/******************************************* MKit:MTcpThreadPool3 ***/
MTcpThreadPool3::MTcpThreadPool3(QSettings *settings,MTcpFactory *MTcpFactory_)
{
    this->MTcpFactory_ = MTcpFactory_;
    this->settings = settings;
    timer_clean.start(settings->value("cleanupInterval",1000 * 60 * 1).toInt());
    connect(&timer_clean,SIGNAL(timeout()),this,SLOT(cleanup()));
}

MTcpThreadPool3::~MTcpThreadPool3()
{
    timer_clean.stop();
    clear();
}

MTcpThreadHandler3 *MTcpThreadPool3::getAvialableThreadHandler()
{
    //find a avilable thread
    foreach (MTcpThreadHandler3 *thread, list_thread) {
        //acquire the source now
        if(thread->tryAcquire()){
            return thread;
        }
    }
    //create new
    int maxThreads = settings->value("maxThreads",100).toInt();
    if(list_thread.length() < maxThreads){
        MTcpThreadHandler3 *thread = new MTcpThreadHandler3(settings,MTcpFactory_);
        //...
        thread->start();
        //acquire the source now
        bool ok = thread->tryAcquire();
        M_ASSERT(ok);
        list_thread << thread;
        return thread;
    }
    return 0;
}

void MTcpThreadPool3::clear()
{
    foreach (MTcpThreadHandler3 *thread, list_thread) {
        //...
        thread->quit();
        thread->wait();
        delete thread;
    }
    list_thread.clear();
}

void MTcpThreadPool3::cleanup()
{
    int minThreads = settings->value("minThreads",0).toInt();
    int counter = 0;
    //find the empty thread
    for(int i = list_thread.length() - 1; i >= 0; i--){
        MTcpThreadHandler3 *t = list_thread.at(i);
        if(t->isEmpty()){
            if(++counter > minThreads){
                //...
                t->quit();
                t->wait();
                delete t;
                list_thread.removeAt(i);
                break; // remove only one handler in each interval
            }
        }
    }
}

/******************************************* MKit:MTcpListener3 ***/
MTcpListener3::MTcpListener3(QSettings *settings, MTcpFactory *MTcpFactory_, QObject *parent) : QTcpServer(parent)
{
    pool = new MTcpThreadPool3(settings,MTcpFactory_);
    this->settings = settings;
    this->MTcpFactory_ = MTcpFactory_;
    qRegisterMetaType<qintptr>("qintptr");
    listen();
}

MTcpListener3::~MTcpListener3()
{
    close();
    M_DELETE_TO_NULL(pool);

    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    MDG << "delete listener:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpListener3::listen()
{
    QString host = settings->value("host").toString();
    int port = settings->value("port").toInt();
    QHostAddress hst = host.isEmpty() ? QHostAddress::Any : QHostAddress(host);
    QTcpServer::listen(hst, port);
    if (!isListening())
    {
        MDG_WARNING << QString("Cannot bind on port %1: %2")
                       .arg(port)
                       .arg(errorString());
    }
    else {
        QJsonObject json;
        json.insert("ip",hst.toString());
        json.insert("port",port);
        json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
        MDG << "listen on:\n"
            << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
    }
}

void MTcpListener3::close()
{
    QTcpServer::close();
    if(pool)
        pool->clear();

    QJsonObject json;
    json.insert(M_CAST_STRING(MTcpListener),MTL::get_hex_str_from_ulonglong_length_16_upper((ullint)this));
    json.insert("serverAddress",serverAddress().toString());
    json.insert("serverPort",serverPort());
    MDG << "listen close:\n"
        << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented);
}

void MTcpListener3::incomingConnection(qintptr socketDescriptor)
{
    MTcpThreadHandler3* freeHandler = NULL;
    if (pool)
    {
        freeHandler = pool->getAvialableThreadHandler();
    }

    // Let the handler process the new connection.
    if (freeHandler)
    {
        // The descriptor is passed via event queue because the handler lives in another thread
        QMetaObject::invokeMethod(freeHandler, "handleConnection", Qt::QueuedConnection, Q_ARG(qintptr, socketDescriptor));
    }
    else
    {
        // Reject the connection
        MDG_WARNING << "HttpListener: Too many incoming connections";
        QTcpSocket* socket = new QTcpSocket(this);
        socket->setSocketDescriptor(socketDescriptor);
        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
        //socket->write("HTTP/1.1 503 too many connections\r\nConnection: close\r\n\r\nToo many connections\r\n");
        socket->disconnectFromHost();
    }
}

/******************************************************** MKit:MWatchDog ***/
MWatchDog::MWatchDog(QObject *parent) : QObject(parent)
{
    dog.setParent(this);
    dog.setSingleShot(true);
    connect(&dog,SIGNAL(timeout()),this,SIGNAL(hungry()));
    lastFeedTime = 0;
    setTimeLimit();
}

MWatchDog::~MWatchDog(){  stop();}

qint64 MWatchDog::remainingTime() const
{
    qint64 pastTime = QDateTime::currentMSecsSinceEpoch() - lastFeedTime;
    return dog.interval() - pastTime;
}

bool MWatchDog::isAlive() const{  return dog.isActive();}

void MWatchDog::start()
{
    dog.start(timeLimitMs);
    lastFeedTime = QDateTime::currentMSecsSinceEpoch();
}

void MWatchDog::stop(){  dog.stop();}

void MWatchDog::setTimeLimit(int limitMs){  timeLimitMs = limitMs;}

void MWatchDog::feedDog(){  start();}

/******************************************************** MKit:MDataParer ***/
MDataParser::MDataParser(QObject *parent) : QObject(parent)
{
    setHeader();
    setEnder();
}

MDataParser::~MDataParser(){}

void MDataParser::setHeader(const QByteArray &header){ this->header = header;}

void MDataParser::setEnder(const QByteArray &ender){ this->ender = ender;}

void MDataParser::clearBuffer(){    _buffer.clear();}

QByteArray MDataParser::buffer() const{    return _buffer;}

void MDataParser::operator <<(const QByteArray &value){    append(value);}

void MDataParser::append(const QByteArray &data)
{
    _buffer += data;
    //find seperator
    QByteArray sep = ender.length() > 0 ? ender : header;
    QByteArray sep2 = header;
    if(header.length() < 1 || ender.length() < 1){
        sep2 = "";
    }
    if(sep.length() < 1){
        return ;
    }
    int lastIndex = _buffer.lastIndexOf(sep);
    if(lastIndex < 0){
        return ;
    }
    QByteArray target = _buffer.mid(0,lastIndex);
    _buffer = _buffer.mid(lastIndex + sep.length());
    if(target.length() < 1){
        return ;
    }
    QList<QByteArray> ret = MTL::split(target,sep);
    foreach (QByteArray tmp, ret) {
        if(tmp.length() < 1){
            continue;
        }
        if(sep2.length() > 0){
            tmp.replace(sep2,"");
        }
        emit frameDetected(tmp);
    }
}

/******************************************************** MKit:MStabilizer ***/
MStabilizer::MStabilizer(QObject *parent) : QObject(parent)
{
    setSize();
    setRange();
}

MStabilizer::~MStabilizer(){}

void MStabilizer::setSize(int sz){    size = sz;}

void MStabilizer::setRange(ld rg){    range = rg;}

void MStabilizer::clear(){   queue.clear();}

void MStabilizer::append(ld value)
{
    queue << value;
    if(queue.length() < size)
        return ;
    bool stable = true;
    for(int i = 0; i < queue.length() - 1; i++){
        if(fabsl(value - queue.at(i)) > fabsl(range)){
            stable = false;
            break;
        }
    }
    int removeCount = queue.length() - size;
    for(int i = 0; (i < removeCount + 1 ) && !queue.isEmpty(); i++){
        queue.removeFirst();
    }
    if(stable)
        emit stabilized(value);
}

/******************************************************** MKit:MDuplicateFilter ***/

MDuplicateFilter::MDuplicateFilter(QObject *parent):QObject(parent)
{
    setSize();
    setAmount();
    setPeriod();
    setType();
}

MDuplicateFilter::~MDuplicateFilter(){    }

void MDuplicateFilter::setSize(int sz){    size = sz;}

void MDuplicateFilter::setAmount(int amt){    amount = amt;}

void MDuplicateFilter::setPeriod(qint64 prd){    period = prd;}

void MDuplicateFilter::setType(MDuplicateFilter::FilterType t){    type = t;}

void MDuplicateFilter::clear(){    queue.clear();}

void MDuplicateFilter::operator <<(const QString &value){    append(value);}

void MDuplicateFilter::append(const QString &value)
{
    //check amount
    bool noDuplicateInAmount = true;
    /** Total elements **/
    int queueLength = queue.length();
    /** Target elements for compare. **/
    int min = M_MINIMUM(queueLength, amount);
    for(int i = 0; i < min; i++){
        /** From end to beginning. **/
        if(queue.at(queueLength - 1 - i).first == value){
            noDuplicateInAmount = false;
            break;
        }
    }
    //check period
    bool noDuplicateInPeriod = true;
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    for(int i = 0; i < queueLength; i++){
        /** From end to beginning. **/
        QPair<QString,qint64> item = queue.at(queueLength - 1 - i);
        if((item.second + period) < currentTime){
            break;
        }
        if(item.first == value){
            noDuplicateInPeriod = false;
            break;
        }
    }
    //add item
    queue << QPair<QString,qint64>(value,currentTime);
    //remove item from head
    int remove = queue.length() - size;
    for(int i = 0; i < remove && !queue.isEmpty(); i++){
        queue.removeFirst();
    }

    switch(type){
    case Amount:
        emit filtered(value,noDuplicateInAmount);
        break;
    case Period:
        emit filtered(value,noDuplicateInPeriod);
        break;
    case AmountAndPeriod:
        emit filtered(value,noDuplicateInAmount || noDuplicateInPeriod);
        break;
    default:
        MDG_WARNING << QString("unknown filter type:%1").arg((int)type);
        break;
    }
}

/******************************************************** MKit:MXlsxDocument ***/
#ifdef M_ENABLE_QTXLSXWRITER_MASTER

MXlsxDocument::MXlsxDocument(QObject *parent) : QXlsx::Document(parent){}

MXlsxDocument::MXlsxDocument(const QString &xlsxName, QObject *parent) : QXlsx::Document(xlsxName,parent){}

MXlsxDocument::MXlsxDocument(QIODevice *device, QObject *parent) : QXlsx::Document(device,parent){}

MXlsxDocument::~MXlsxDocument(){}

void MXlsxDocument::setMatrix(const MXlsxDocumentMatrix &matrix)
{
    for(int i = 0; i < matrix.length(); i++){
        MXlsxDocumentRow row = matrix.at(i);
        for(int j = 0; j < row.length(); j++){
            MXlsxDocumentCell cell = row.at(j);
            write(QString("%1%2").arg(QString(QChar('A' + j))).arg(i + 1),cell.data,cell.format);
        }
    }
}

void MXlsxDocument::clear(const QXlsx::CellRange &range, const QXlsx::Format &format)
{
    for(int i = range.topLeft().row(); i <= range.bottomRight().row(); i++){
        for(int j = range.topLeft().column(); j <= range.bottomRight().column(); j++){
            write(i,j,"",format);
        }
    }
}


#endif //M_ENABLE_QTXLSXWRITER_MASTER


/******************************************************** MKit:MMongocBase ***/

#ifdef M_ENABLE_MONGOC1140

MMongocBase::MMongocBase(bool callInitFunction): MError()
{
    if (!inited && callInitFunction){
        mongoc_init();
        inited = true;
    }
    setUri();
}

MMongocBase::~MMongocBase(){}

QString MMongocBase::bson_to_QString(const bson_t *bson)
{
    QString ret = "";
    if(!bson)
        return ret;
    char *jsonStr = bson_as_json(bson,NULL);
    if(jsonStr){
        ret = QString(jsonStr);
        bson_free(jsonStr);
    }
    return ret;
}

bson_t *MMongocBase::bson_from_QJsonObject(const QJsonObject &json)
{
    QString jsonStr = MTL::get_str_from_QJsonObject(json);
    std::string sstr = jsonStr.toStdString();
    bson_error_t err;
    bson_t *ret = bson_new_from_json((uint8_t *)sstr.c_str(),sstr.length(),&err);
    if(!ret){
        MDG_WARNING << QString("Convert json 2 bson error:%1,%2,%3")
                       .arg(err.code)
                       .arg(err.domain)
                       .arg(err.message);
    }
    return ret;
}

void MMongocBase::bson_destroy_list(QList<bson_t *> &list)
{
    foreach (bson_t *b, list) {
        ::bson_destroy(b);
    }
}

void MMongocBase::bson_remove(bson_t **bs, const QString &key)
{
    if(!bs || !*bs)
        return ;
    bson_t *newbs = bson_new();
    bson_iter_t iter;

    if (bson_iter_init (&iter, *bs)) {
        while (bson_iter_next (&iter)) {
            QString k = bson_iter_key(&iter);
            if(k != key){
                BSON_APPEND_VALUE(newbs,k.toStdString().c_str(),bson_iter_value(&iter));
            }
        }
    }
    ::bson_destroy(*bs);
    *bs = newbs;
}

QStringList MMongocBase::bson_keys(const bson_t *bs)
{
    QStringList ret;
    if(!bs)
        return ret;
    bson_iter_t iter;
    if (bson_iter_init (&iter, bs)) {
        while (bson_iter_next (&iter)) {
            ret << QString(bson_iter_key(&iter));
        }
    }
    return ret;
}

const bson_value_t *MMongocBase::bson_value(const bson_t *bs, const QString &key)
{
    const bson_value_t *v = NULL;
    if(!bs)
        return v;
    bson_iter_t iter;
    if (bson_iter_init (&iter, bs)) {
        while (bson_iter_next (&iter)) {
            if(QString(bson_iter_key(&iter)) == key){
                v = bson_iter_value(&iter);
                break;
            }
        }
    }
    return v;
}

void MMongocBase::setUri(const QString &uri){    this->uri = uri;}

bool MMongocBase::connect(){    return true;}

void MMongocBase::disConnect(){}

bool MMongocBase::insert(const QString &dbName, const QString &collectionName, const bson_t *doc)
{
    (void)dbName;(void)collectionName;(void)doc;
    return true;
}

bool MMongocBase::insertBulk(const QString &dbName, const QString &collectionName, const QList<bson_t *> &bulk)
{
    (void)dbName;(void)collectionName;(void)bulk;
    return true;
}

bool MMongocBase::find(const QString &dbName, const QString &collectionName, const bson_t *filter, const bson_t *opts, QList<bson_t *> &out)
{
    (void)dbName;(void)collectionName;(void)filter;(void)opts;(void)out;
    return true;
}

bool MMongocBase::updateMany(const QString &dbName, const QString &collectionName, const bson_t *where, const bson_t *set, const bson_t *opts)
{
    (void)dbName;(void)collectionName;(void)where;(void)set;(void)opts;
    return true;
}

bool MMongocBase::update_if_exist_or_insert(const QString &dbName, const QString &collectionName, const bson_t *set, const bson_t *where)
{
    (void)dbName;(void)collectionName;(void)where;(void)set;
    return true;
}

bool MMongocBase::deleteMany(const QString &dbName, const QString &collectionName, const bson_t *where, const bson_t *opts)
{
    (void)dbName;(void)collectionName;(void)where;(void)opts;
    return true;
}


mongoc_client_t *MMongocBase::getClient() const{   return NULL;}

mongoc_client_pool_t *MMongocBase::getPool() const{    return NULL;}

bool MMongocBase::_insert(const QString &dbName,
                          const QString &collectionName,
                          const bson_t *doc,
                          mongoc_client_t *client)
{
    bool ret = false;
    mongoc_collection_t *collection = NULL;
    bson_error_t error;
    if(!client){
        errorData = MMARKEDDATA(QString("client == NULL"));
        return ret;
    }
    if(!doc){
        errorData = MMARKEDDATA(QString("doc == NULL"));
        return ret;
    }
    collection = mongoc_client_get_collection(client,
                                              dbName.toStdString().c_str(),
                                              collectionName.toStdString().c_str());
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_collection_destroy,&collection)
            if(!collection){
        errorData = MMARKEDDATA(QString("New mongoc_collection_t error."));
        return ret;
    }
    ret = mongoc_collection_insert (collection, MONGOC_INSERT_NONE, doc, NULL, &error);
    if(!ret){
        errorData = MMARKEDDATA(QString("insert error:%1,%2,%3")
                                .arg(error.code)
                                .arg(error.domain)
                                .arg(error.message));
    }
    return clearError(ret);
}

bool MMongocBase::_insertBulk(const QString &dbName,
                              const QString &collectionName,
                              const QList<bson_t *> &bulk,
                              mongoc_client_t *client)
{
    bool ret = false;
    mongoc_collection_t *collection = NULL;
    bson_error_t error;
    mongoc_bulk_operation_t *blk = NULL;
    if(bulk.length() < 1){
        errorData = MMARKEDDATA(QString("bulk is empty."));
        return ret;
    }
    if(!client){
        errorData = MMARKEDDATA(QString("client == NULL"));
        return ret;
    }
    collection = mongoc_client_get_collection(client,
                                              dbName.toStdString().c_str(),
                                              collectionName.toStdString().c_str());
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_collection_destroy,&collection)
            if(!collection){
        errorData = MMARKEDDATA(QString("New mongoc_collection_t error."));
        return ret;
    }
    blk = mongoc_collection_create_bulk_operation_with_opts (collection, NULL);
    MSCOPEDCALLER_DESTROY_SAFE(pp,mongoc_bulk_operation_destroy,&blk)
            if(!blk){
        errorData = MMARKEDDATA(QString("mongoc_collection_create_bulk_operation_with_opts() error."));
        return ret;
    }
    foreach (const bson_t *doc, bulk) {
        if(doc)
            mongoc_bulk_operation_insert (blk, doc);
    }
    if (!mongoc_bulk_operation_execute (blk, NULL, &error)) {
        errorData = MMARKEDDATA(QString("insert error:%1,%2,%3")
                                .arg(error.code)
                                .arg(error.domain)
                                .arg(error.message));
        return ret;
    }
    ret = true;
    return clearError(ret);
}

bool MMongocBase::_find(const QString &dbName,
                        const QString &collectionName,
                        const bson_t *filter,
                        const bson_t *opts,
                        QList<bson_t *> &out,
                        mongoc_client_t *client)
{
    bool ret = false;
    mongoc_collection_t *collection = NULL;
    mongoc_cursor_t *cursor = NULL;
    const bson_t *doc = NULL;
    if(!client){
        errorData = MMARKEDDATA(QString("client == NULL"));
        return ret;
    }
    if(!filter){
        errorData = MMARKEDDATA(QString("filter == NULL"));
        return ret;
    }
    collection = mongoc_client_get_collection(client,
                                              dbName.toStdString().c_str(),
                                              collectionName.toStdString().c_str());
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_collection_destroy,&collection)
            if(!collection){
        errorData = MMARKEDDATA(QString("New mongoc_collection_t error."));
        return ret;
    }
    cursor = mongoc_collection_find_with_opts (collection, filter, opts, NULL);
    MSCOPEDCALLER_DESTROY_SAFE(pp,mongoc_cursor_destroy,&cursor)
            if(!cursor){
        errorData = MMARKEDDATA(QString("mongoc_collection_find_with_opts() error."));
        return ret;
    }
    out.clear();
    while (mongoc_cursor_next (cursor, &doc)) {
        if(!doc)
            continue;
        out << (bson_t *)bson_copy(doc);
    }
    ret = true;
    return clearError(ret);
}

bool MMongocBase::_updateMany(const QString &dbName,
                              const QString &collectionName,
                              const bson_t *where,
                              const bson_t *set,
                              const bson_t *opts,
                              mongoc_client_t *client)
{
    bool ret = false;
    mongoc_collection_t *collection = NULL;
    bson_error_t error;
    if(!client){
        errorData = MMARKEDDATA(QString("client == NULL"));
        return ret;
    }
    if(!set){
        errorData = MMARKEDDATA(QString("update == NULL"));
        return ret;
    }
    if(!where){
        errorData = MMARKEDDATA(QString("where == NULL"));
        return ret;
    }
    collection = mongoc_client_get_collection(client,
                                              dbName.toStdString().c_str(),
                                              collectionName.toStdString().c_str());
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_collection_destroy,&collection)
            if(!collection){
        errorData = MMARKEDDATA(QString("New mongoc_collection_t error."));
        return ret;
    }
    if(!mongoc_collection_update_many(collection,where,set,opts,NULL,&error)){
        errorData = MMARKEDDATA(QString("update error:%1,%2,%3")
                                .arg(error.code)
                                .arg(error.domain)
                                .arg(error.message));
        return ret;
    }
    ret = true;
    return clearError(ret);
}

bool MMongocBase::_update_if_exist_or_insert(const QString &dbName,
                                             const QString &collectionName,
                                             const bson_t *set,
                                             const bson_t *where,
                                             mongoc_client_t *client)
{
    bool ret = false;
    mongoc_collection_t *collection = NULL;
    mongoc_cursor_t *cursor = NULL;
    const bson_t *doc = NULL;
    bson_error_t error;
    if(!client){
        errorData = MMARKEDDATA(QString("client == NULL"));
        return ret;
    }
    if(!where){
        errorData = MMARKEDDATA(QString("where == NULL"));
        return ret;
    }
    if(!set){
        errorData = MMARKEDDATA(QString("set == NULL"));
        return ret;
    }
    collection = mongoc_client_get_collection(client,
                                              dbName.toStdString().c_str(),
                                              collectionName.toStdString().c_str());
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_collection_destroy,&collection)
            if(!collection){
        errorData = MMARKEDDATA(QString("New mongoc_collection_t error."));
        return ret;
    }
    cursor = mongoc_collection_find_with_opts (collection, where, NULL, NULL);
    MSCOPEDCALLER_DESTROY_SAFE(pp,mongoc_cursor_destroy,&cursor)
            if(!cursor){
        errorData = MMARKEDDATA(QString("mongoc_collection_find_with_opts() error."));
        return ret;
    }
    bool exist = false;
    while (mongoc_cursor_next (cursor, &doc)) {
        if(doc){
            exist = true;
            break;
        }
    }
    if(exist){
        bson_t *sett = bson_new();
        MSCOPEDCALLER_DESTROY_SAFE(ppp,::bson_destroy,&sett);
        BSON_APPEND_DOCUMENT(sett,"$set",set);
        if( ! mongoc_collection_update_many(collection,where,sett,NULL,NULL,&error)){
            errorData = MMARKEDDATA(QString("update error:%1,%2,%3")
                                    .arg(error.code)
                                    .arg(error.domain)
                                    .arg(error.message));
            return ret;
        }
    }else{
        if( ! mongoc_collection_insert (collection, MONGOC_INSERT_NONE, set, NULL, &error)){
            errorData = MMARKEDDATA(QString("insert error:%1,%2,%3")
                                    .arg(error.code)
                                    .arg(error.domain)
                                    .arg(error.message));
            return ret;
        }
    }
    ret = true;
    return clearError(ret);
}

bool MMongocBase::_deleteMany(const QString &dbName,
                              const QString &collectionName,
                              const bson_t *where,
                              const bson_t *opts,
                              mongoc_client_t *client)
{
    bool ret = false;
    mongoc_collection_t *collection = NULL;
    bson_error_t error;
    if(!client){
        errorData = MMARKEDDATA(QString("client == NULL"));
        return ret;
    }
    if(!where){
        errorData = MMARKEDDATA(QString("where == NULL"));
        return ret;
    }
    collection = mongoc_client_get_collection(client,
                                              dbName.toStdString().c_str(),
                                              collectionName.toStdString().c_str());
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_collection_destroy,&collection)
            if(!collection){
        errorData = MMARKEDDATA(QString("New mongoc_collection_t error."));
        return ret;
    }
    if(!mongoc_collection_delete_many(collection,where,opts,NULL,&error)){
        errorData = MMARKEDDATA(QString("update error:%1,%2,%3")
                                .arg(error.code)
                                .arg(error.domain)
                                .arg(error.message));
        return ret;
    }
    ret = true;
    return clearError(ret);
}

bool MMongocBase::inited = false;

/******************************************************** MKit:MScopedMongodb ***/

MScopedMongodb::MScopedMongodb(bool callInitFunction): MMongocBase(callInitFunction)
{
    client = NULL;
}

MScopedMongodb::~MScopedMongodb()
{
    disConnect();
}

bool MScopedMongodb::connect()
{
    disConnect();

    client = mongoc_client_new(uri.toStdString().c_str());
    if(!client){
        errorData = MMARKEDDATA(QString("New mongo client error:%1").arg(uri));
        return false;
    }
    return clearError(true);
}

void MScopedMongodb::disConnect()
{
    if(client){
        mongoc_client_destroy(client);
        client = NULL;
    }
}

bool MScopedMongodb::insert(const QString &dbName,
                            const QString &collectionName,
                            const bson_t *doc)
{
    return _insert(dbName,collectionName,doc,client);
}

bool MScopedMongodb::insertBulk(const QString &dbName, const QString &collectionName, const QList<bson_t *> &bulk)
{
    return _insertBulk(dbName,collectionName,bulk,client);
}


bool MScopedMongodb::find(const QString &dbName,
                          const QString &collectionName,
                          const bson_t *filter,
                          const bson_t *opts,
                          QList<bson_t *> &out)
{
    return _find(dbName,collectionName,filter,opts,out,client);
}

bool MScopedMongodb::updateMany(const QString &dbName, const QString &collectionName, const bson_t *where, const bson_t *set, const bson_t *opts)
{
    return _updateMany(dbName,collectionName,where,set,opts,client);
}

bool MScopedMongodb::update_if_exist_or_insert(const QString &dbName, const QString &collectionName, const bson_t *set, const bson_t *where)
{
    return _update_if_exist_or_insert(dbName,collectionName,set,where,client);
}

bool MScopedMongodb::deleteMany(const QString &dbName, const QString &collectionName, const bson_t *where, const bson_t *opts)
{
    return _deleteMany(dbName,collectionName,where,opts,client);
}

mongoc_client_t *MScopedMongodb::getClient() const{    return client;}

mongoc_collection_t *MScopedMongodb::getCollection(const QString &dbName, const QString &collectionName)
{
    return mongoc_client_get_collection(client,dbName.toStdString().c_str(),collectionName.toStdString().c_str());
}

/******************************************************** MKit:MPooledMongodb ***/

MPooledMongodb::MPooledMongodb(bool callInitFunction) : MMongocBase(callInitFunction)
{
    pool = NULL;
}

MPooledMongodb::~MPooledMongodb()
{
    disConnect();
}

bool MPooledMongodb::connect()
{
    disConnect();

    bool ret = false;
    bson_error_t error;
    mongoc_uri_t *urit = mongoc_uri_new_with_error(uri.toStdString().c_str(),&error);
    MSCOPEDCALLER_DESTROY_SAFE(p,mongoc_uri_destroy,&urit)
            if(!urit){
        errorData = MMARKEDDATA(QString("mongoc_uri_new_with_error() error:%1,%2,%3")
                                .arg(error.code)
                                .arg(error.domain)
                                .arg(error.message));
        return ret;
    }
    pool = mongoc_client_pool_new (urit);
    if(!pool){
        errorData = MMARKEDDATA(QString("mongoc_client_pool_new() error."));
        return ret;
    }
    ret = true;
    return clearError(ret);
}

void MPooledMongodb::disConnect()
{
    if(pool){
        mongoc_client_pool_destroy(pool);
        pool = NULL;
    }
}

bool MPooledMongodb::insert(const QString &dbName, const QString &collectionName, const bson_t *doc)
{
    bool ret = false;
    if(!pool){
        errorData = MMARKEDDATA(QString("pool == NULL"));
        return ret;
    }
    mongoc_client_t *client = mongoc_client_pool_pop (pool);
    if(!client){
        errorData = MMARKEDDATA("mongoc_client_pool_pop() error.");
        return ret;
    }
    ret = _insert(dbName,collectionName,doc,client);
    mongoc_client_pool_push(pool,client);
    return clearError(ret);
}

bool MPooledMongodb::insertBulk(const QString &dbName, const QString &collectionName, const QList<bson_t *> &bulk)
{
    bool ret = false;
    if(!pool){
        errorData = MMARKEDDATA(QString("pool == NULL"));
        return ret;
    }
    mongoc_client_t *client = mongoc_client_pool_pop (pool);
    if(!client){
        errorData = MMARKEDDATA("mongoc_client_pool_pop() error.");
        return ret;
    }
    ret = _insertBulk(dbName,collectionName,bulk,client);
    mongoc_client_pool_push(pool,client);
    return clearError(ret);
}

bool MPooledMongodb::find(const QString &dbName, const QString &collectionName, const bson_t *filter, const bson_t *opts, QList<bson_t *> &out)
{
    bool ret = false;
    if(!pool){
        errorData = MMARKEDDATA(QString("pool == NULL"));
        return ret;
    }
    mongoc_client_t *client = mongoc_client_pool_pop (pool);
    if(!client){
        errorData = MMARKEDDATA("mongoc_client_pool_pop() error.");
        return ret;
    }
    ret = _find(dbName,collectionName,filter,opts,out,client);
    mongoc_client_pool_push(pool,client);
    return clearError(ret);
}

mongoc_client_pool_t *MPooledMongodb::getPool() const{    return pool;}


#endif //M_ENABLE_MONGOC1140


/******************************************************** MKit:MAutoRntTCP ***/
MAutoRntTCP::MAutoRntTCP(QObject *parent) : QTcpSocket(parent)
{
    timer_reconnect = new QTimer(this);
    connect(timer_reconnect,SIGNAL(timeout()),this,SLOT(timeout_reconnect_slot()));
    startRnt();
}

MAutoRntTCP::~MAutoRntTCP(){}

void MAutoRntTCP::setAddr(const QString &ip, int port)
{
    this->ip = ip;
    this->port = port;
}

void MAutoRntTCP::connect2host()
{
    connectToHost(QHostAddress(ip),port);
}

void MAutoRntTCP::startRnt(int interval)
{
    timer_reconnect->start(interval);
}

void MAutoRntTCP::stopRnt()
{
    timer_reconnect->stop();
}

void MAutoRntTCP::timeout_reconnect_slot()
{
    if(state() == QTcpSocket::UnconnectedState){
        connect2host();
    }
}
/******************************************************** MKit:MTable ***/
MTable::MTable(const QString &name) : MError()
{
    setName(name);
}

MTable::MTable(const MTable &other) : MError(other)
{
    table = other.table;
    name = other.name;
}

MTable::~MTable(){}

MTable &MTable::operator =(const MTable &other)
{
    if(&other != this){
        MError::operator =(other);
        table = other.table;
        name = other.name;
    }
    return *this;
}

bool MTable::operator ==(const MTable &other)
{
    return table == other.select();
}

bool MTable::operator !=(const MTable &other)
{
    return ! this->operator ==(other);
}

MTable &MTable::operator <<(const QJsonObject &json)
{
    insert(json);
    return *this;
}

const QJsonObject &MTable::operator [](int r) const
{
    return table[r];
}

QJsonObject &MTable::operator [](int r)
{
    return table[r];
}

void MTable::setName(const QString &name){    this->name = name;}

QString MTable::getName() const{    return name;}

int MTable::rowCount() const{    return table.length();}

bool MTable::isEmpty() const
{
    return table.length() == 0;
}

void MTable::inventOrder()
{
    int length = table.length();
    for(int i = 0; i < length / 2; i++){
        QJsonObject tmp = table[i];
        table[i] = table[length - i - 1];
        table[length - i - 1] = tmp;
    }
}

void MTable::clear(){    table.clear();}

QList<QStringList> MTable::fieldName() const
{
    QList<QStringList> ret;
    foreach (const QJsonObject &row, table) {
        ret << row.keys();
    }
    return ret;
}

QString MTable::exprt2InsertSql() const
{
    QString ret;
    foreach (const QJsonObject &row, table) {
        QString sql = QString("insert into %1 (").arg(name);
        QString values = "(";
        QStringList keys = row.keys();
        foreach (const QString &key, keys) {
            sql += QString("'%1',").arg(key);
            values += QString("'%1',").arg(MTL::get_str_from_QJsonValue(row.value(key)));
        }
        if(sql.mid(sql.length() - 1, 1) == ",")
            sql = sql.mid(0,sql.length() - 1);
        if(values.mid(values.length() - 1, 1) == ",")
            values = values.mid(0,values.length() - 1);
        sql += ") values";
        values += ")";
        sql += values;
        sql += ";\n";
        ret += sql;
    }
    return ret;
}

QString MTable::exprt2JsonStr(QJsonDocument::JsonFormat format) const
{
    QString ret;
    foreach (const QJsonObject &row , table) {
        ret += MTL::get_str_from_QJsonObject(row,format);
        ret += "\n";
    }
    return ret;
}


bool MTable::insert(const QJsonObject &json)
{
    bool ret = false;
    if(json.isEmpty()){
        errorData = MMARKEDDATA("json is empty.");
        return ret;
    }
    table << json;
    ret = true;
    return clearError(ret);
}

void MTable::del(const QJsonObject &where)
{
    if(where.isEmpty()){
        table.clear();
        return ;
    }
    for(int i = table.length() - 1; i >= 0; i--){
        if(MTL::contains(table.at(i),where)){
            table.removeAt(i);
        }
    }
}

void MTable::update(const QJsonObject &set, const QJsonObject &where)
{
    for(int i = 0; i < table.length(); i++){
        //find target row
        QJsonObject &r = table[i];
        if(MTL::contains(r,where)){
            //insert data
            for(QJsonObject::const_iterator itt = set.constBegin();
                itt != set.constEnd();
                itt++){
                r.insert(itt.key(),itt.value());
            }
        }
    }
}

QList<QJsonObject> MTable::select(const QJsonObject &where) const
{
    QList<QJsonObject> ret;
    if(where.isEmpty())
        return ret << table;
    foreach (const QJsonObject &json, table) {
        if(MTL::contains(json,where)){
            ret << json;
        }
    }
    return ret;
}

TwoListJson MTable::select_and_update(const QJsonObject &where, const QJsonObject &set)
{
    QPair<QList<QJsonObject>, QList<QJsonObject> > p;
    QList<QJsonObject> ret,ret2;
    for(int i = 0; i < table.length(); i++){
        //find target row
        QJsonObject &r = table[i];
        if(MTL::contains(r,where)){
            ret << r;
            //insert data
            for(QJsonObject::const_iterator itt = set.constBegin();
                itt != set.constEnd();
                itt++){
                r.insert(itt.key(),itt.value());
            }
            ret2 << r;
        }
    }
    p.first = ret;
    p.second = ret2;
    return p;
}

void MTable::update_if_exist_or_insert(const QJsonObject &set, const QJsonObject &where)
{
    if(select(where).length() > 0){
        update(set,where);
    }else{
        insert(set);
    }
}

/******************************************************** MKit:MSettings ***/
MSettings::MSettings(const QString &file)
{
    QSettings set(file,QSettings::IniFormat);
    set.setIniCodec("UTF-8");
    QStringList keys = set.allKeys();
    foreach (const QString &key, keys) {
        map.insert(key,set.value(key));
    }
}

MSettings::~MSettings(){}

void MSettings::save(const QString &file)
{
    QString f = file.isEmpty() ? this->file : file;
    QSettings set(f,QSettings::IniFormat);
    set.setIniCodec("UTF-8");
    for(QMap<QString,QVariant>::const_iterator it = map.constBegin();
        it != map.constEnd();
        it++){
        set.setValue(it.key(),it.value());
    }
}

/******************************************************** MKit:MDurationTime ***/
MDurationTime::MDurationTime(qint64 duration)
{
    setDuration(duration);
}

MDurationTime::~MDurationTime(){}

MDurationTime &MDurationTime::operator =(const MDurationTime &other)
{
    if(this != &other){
        day = other.day;
        hour = other.hour;
        minute = other.minute;
        second = other.second;
        millisecond = other.millisecond;
        duration = other.duration;
    }
    return *this;
}

MDurationTime::MDurationTime(const MDurationTime &other)
{
    day = other.day;
    hour = other.hour;
    minute = other.minute;
    second = other.second;
    millisecond = other.millisecond;
    duration = other.duration;
}

void MDurationTime::setDuration(qint64 d)
{
    duration = d;
    day = d / (3600 * 1000 * 24);
    hour = (d % (24 * 3600 * 1000) ) / (3600 * 1000);
    minute = (d % (3600 * 1000) ) / (60 * 1000);
    second = (d % (60 * 1000) ) / 1000;
    millisecond = d % 1000;
}

QString MDurationTime::toString() const
{
    return QString().sprintf("%02d-%02d:%02d:%02d",day,hour,minute,second);
}



/******************************************************** MKit:MTcpSocket ***/
MTcpSocket::MTcpSocket(QObject *parent): QObject(parent)
{
    tcp_client = new MAutoRntTCP(this);
    connect(tcp_client,SIGNAL(readyRead()),this,SLOT(readyRead_slot()));
    tcp_server = NULL;
    server  = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection_slot()));
}

MTcpSocket::~MTcpSocket(){}

void MTcpSocket::setType(MTcpSocket::CSType t)
{
    type = t;
}

MTcpSocket::CSType MTcpSocket::getType() const
{
    return type;
}

QPair<QString, int> MTcpSocket::getAddr() const
{
    QPair<QString, int> p;
    p.first = ip;
    p.second = port;
    return p;
}

void MTcpSocket::setAddr(const QString &ip, int port)
{
    this->ip = ip;
    this->port = port;
}

bool MTcpSocket::start()
{
    if(type == MTcpSocket::Client){
        tcp_client->setAddr(ip,port);
        tcp_client->connect2host();
        return true;
    }
    else if(type == MTcpSocket::Server){
        if(server->isListening())
            server->close();
        return server->listen(QHostAddress(ip),port);
    }
    return false;
}

void MTcpSocket::stop()
{
    tcp_client->abort();
    if(tcp_server)
        tcp_server->abort();
    server->close();
}

qint64 MTcpSocket::write(const QByteArray &b)
{
    if(type == MTcpSocket::Client){
        if(tcp_client)
            return tcp_client->write(b);
    }
    else if(type == MTcpSocket::Server){
        if(tcp_server)
            return tcp_server->write(b);
    }
    return -1;
}

bool MTcpSocket::isConnected() const
{
    bool ret = false;
    if(type == MTcpSocket::Client){
        if(tcp_client){
            ret = tcp_client->state() == QTcpSocket::ConnectedState;
        }
    }
    else if(type == MTcpSocket::Server){
        if(tcp_server){
            ret = tcp_server->state() == QTcpSocket::ConnectedState;
        }
    }
    return ret;
}

void MTcpSocket::newConnection_slot()
{
    QTcpSocket *tcp = server->nextPendingConnection();
    if(!tcp)
        return ;
    delete tcp_server;
    tcp_server = tcp;
    connect(tcp_server,SIGNAL(readyRead()),this,SLOT(readyRead_slot()));
}

void MTcpSocket::readyRead_slot()
{
    if(type == MTcpSocket::Client){
        emit readyRead(tcp_client->readAll());
    }
    else if(type == MTcpSocket::Server){
        emit readyRead(tcp_server->readAll());
    }
}

/******************************************************** MKit:MList ***/
MNode *MNode_create()
{
    MNode *p = (MNode *)malloc(sizeof(MNode));
    memset(p,0,sizeof(MNode));
    return p;
}

void MNode_destroy(MNode *node)
{
    free(node);
}

MList *MList_create()
{
    MList *p = (MList*)malloc(sizeof(MList));
    memset(p,0,sizeof(MList));
    return p;
}

void MList_clear(MList *list)
{
    if(!list)
        return ;
    MNode *p = 0;
    for(p = list->head; p; ){
        MNode *next = p->next;
        free(p);
        p = next;
    }
    list->head = 0;
    list->last = 0;
    list->length = 0;
}

void MList_destroy(MList *list)
{
    MList_clear(list);
    free(list);
}

void MList_append(MList *list, const MNode *node)
{
    if(!list)
        return ;
    if(!node)
        return ;
    if(list->length < 1){
        list->head = (MNode *)node;
        list->last = (MNode *)node;
        list->length = 1;
    }else{
        list->last->next = (MNode *)node;
        list->last = (MNode *)node;
        list->length++;
    }
}

MNode *MList_takeFirst(MList *list)
{
    MNode *ret = 0;
    if(!list)
        return ret;
    if(list->length < 1)
        return ret;
    MNode *p = list->head;
    if(list->length == 1){
        list->head = 0;
        list->last = 0;
        list->length = 0;
        ret = p;
        return ret;
    }
    if(list->length >= 2){
        list->head = p->next;
        list->length--;
        ret = p;
        return ret;
    }
    return ret;
}

MNode *MList_takeLast(MList *list)
{
    MNode *ret = 0;
    if(!list)
        return ret;
    if(list->length < 1)
        return ret;
    MNode *p = list->last;
    if(list->length == 1){
        list->head = 0;
        list->last = 0;
        list->length = 0;
        ret = p;
        return ret;
    }
    if(list->length >= 2){
        MNode *pre = MList_at(list,list->length - 2);
        pre->next = 0;
        list->last = pre;
        list->length--;
        ret = p;
        return ret;
    }
    return ret;
}

MNode *MList_takeAt(MList *list, int index)
{
    MNode *ret = 0;
    //0 1 2 3
    if(!list)
        return ret;
    if(list->length < 1)
        return ret;
    if(index >= list->length)
        return ret;
    if(index == 0)
        return MList_takeFirst(list);
    if(index == list->length - 1){
        return MList_takeLast(list);
    }
    MNode *pre = MList_at(list,index - 1);
    MNode *target = pre->next;
    MNode *next = pre->next->next;
    pre->next = next;
    list->length--;
    ret = target;
    return ret;
}

MNode *MList_at(MList *list, int index)
{
    if(!list)
        return 0;
    MNode *ret = 0;
    MNode *p = list->head;
    int i = 0;
    for( ; i < list->length; i++){
        if(i == index){
            ret = p;
            return ret;
        }
        p = p->next;
    }
    return ret;
}

/***************************************************** MKit:MVector ***/
void MVector_destroy(MVector *v)
{
    MVector_clear(v);
    free(v);
}

MVector *MVector_create(int length)
{
    int itemSize = sizeof(void *);
    MVector *v = (MVector *)malloc(sizeof(MVector));
    void *p = 0;
    if(length > 0){
        p = (void *)malloc(itemSize * length);
        memset(p, 0, itemSize * length);
    }
    v->data = (void **)p;
    v->used = 0;
    v->length = length;
    return v;
}

void MVector_clear(MVector *v)
{
    if(!v)
        return ;
    free(v->data);
    v->data = 0;
    v->used = 0;
    v->length = 0;
}

void MVector_push_back(MVector *v, void *item)
{
    if(!v)
        return ;
    if(v->used + 1 > v->length){
        MVector_add(v,1);
    }
    v->data[v->used++] = item;
}

void *MVector_pop_back(MVector *v)
{
    if(!v || v->used < 1)
        return 0;
    return v->data[--v->used];
}

void *MVector_pop_front(MVector *v)
{
    if(!v || v->used < 1)
        return 0;
    int itemSize = sizeof(void *);
    void *p = v->data[0];
    memcpy((char *)v->data + 0, (char *)v->data + itemSize, itemSize * (v->used - 1) );
    v->used--;
    return p;
}

void MVector_add(MVector *v, int length)
{
    if(!v || length < 1)
        return ;
    int itemSize = sizeof(void *);
    void *p = (void *)realloc(v->data, itemSize * (v->length + length) );
    v->data = (void **)p;
    v->length += length;
    memset((void *)((char *)v->data + v->used * itemSize), 0, itemSize * length);
}

/******************************************************** MKit:MCSBClient ***/
MCSBClient::MCSBClient(QObject *parent,bool debug) : QObject(parent)
{
    this->debug = debug;
    MHttpHandler_ = new MHttpHandler(new QNetworkAccessManager,this);
    connect(MHttpHandler_,SIGNAL(finished2(MHttpDataPackage)),this,SIGNAL(finished2(MHttpDataPackage)));
}

void MCSBClient::doPostJsonString(const QString &url,
                            const QByteArray &jsonStr,
                            const QString &api,
                            const QString &version,
                            const QString &ak,
                            const QString &sk,
                            int timeout_ms)
{
    QJsonObject headers = sign("",api,version,ak,sk);

    QNetworkRequest req;
    req.setUrl(QUrl(url));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    post(req,headers,jsonStr,timeout_ms);
}

void MCSBClient::doPost(const QString &url,
                  const QByteArray &body,
                  const QString &api,
                  const QString &version,
                  const QString &ak,
                  const QString &sk,
                  int timeout_ms)
{
    QJsonObject headers = sign(body,api,version,ak,sk);

    QNetworkRequest req;
    req.setUrl(QUrl(url));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    post(req,headers,body,timeout_ms);
}

void MCSBClient::post(QNetworkRequest &req, const QJsonObject &headers,const QByteArray &body,int timeout_ms)
{
    for(QJsonObject::const_iterator it = headers.constBegin(); it != headers.constEnd(); it++){
        req.setRawHeader(it.key().toStdString().c_str(), it.value().toString().toStdString().c_str());
    }
    req.setRawHeader("Accept","*/*");

    if(debug){
        QJsonObject json;
        QList<QByteArray > list = req.rawHeaderList();
        for(int i = 0; i < list.length(); i++){
            QString key = list.value(i);
            json.insert(key, req.rawHeader(key.toStdString().c_str()).data());
        }
        MDG_QSTRING(s) << "headers:" << MTL::get_str_from_QJsonObject(json,QJsonDocument::Indented)
                       << "url:" << req.url()
                       << "body:" << body;
        MDG << s;
    }

    MHttpHandler_->post(req,body,timeout_ms);
}

QJsonObject MCSBClient::sign(const QByteArray &params,
                       const QString &api,
                       const QString &version,
                       const QString &ak,
                       const QString &sk)
{
    qint64 time = QDateTime::currentMSecsSinceEpoch();

    QJsonObject json;
    json.insert("_api_name",api);
    json.insert("_api_version",version);
    json.insert("_api_access_key",ak);
    json.insert("_api_timestamp",QString::number(time));

    QJsonObject json_body = toJson(params);
    QJsonObject json_sign = MTL::add(json,json_body);

    QString signstr = http_build_query(json_sign);

    QString signature = MTL::hash_hmac(sk.toStdString().c_str(), signstr.toStdString().c_str()).toBase64();
    if(debug){
        MDG_QSTRING(s) << "signstr:" << signstr
                       << "signature:" << signature;
        MDG << s;
    }

    QJsonObject headers = json;
    headers.insert("_api_signature",signature);

    return headers;
}

QString MCSBClient::http_build_query(const QJsonObject &json)
{
    QString signstr = "";
    QStringList list = json.keys();
    list.sort();
    for(int i = 0 ; i < list.length(); i++){
        QString key = list.value(i);
        signstr += QString("%1=%2%3")
                .arg(key)
                .arg(MTL::get_str_from_QJsonValue(json.value(key)))
                .arg(i == (list.length() - 1) ? "" : "&");
    }
    return signstr;
}

QJsonObject MCSBClient::toJson(const QString &dataa)
{
    //name=wiseking&age=100&title=god
    QByteArray data = dataa.toStdString().c_str();
    QJsonObject ret;
    QList<QByteArray > list = data.split('&');
    for(int i = 0 ; i < list.length(); i++){
        QByteArray row = list.value(i);
        int index = row.indexOf("=");
        if(index > 0)
            ret.insert(row.mid(0,index).data(),row.mid(index + 1).data());
    }
    return ret;
}


/******************************************************** MKit:MCString ***/

MCString *MCString_create()
{
    MCString *MCString_ = (MCString *)malloc(sizeof(MCString));
    memset(MCString_,0,sizeof(MCString));
    return MCString_;
}

void MCString_destroy(MCString *MCString_)
{
    MCString_clear(MCString_);
    free(MCString_);
}

void MCString_append(MCString *MCString_, const char *str, int length)
{
    if(!MCString_ || !str || length < 1){
        return ;
    }
    int total = MCString_->length + length;
    char *data = (char *)realloc(MCString_->str, total);
    memcpy(data + MCString_->length, str, length);
    MCString_->str = data;
    MCString_->length = total;
}

char *MCString_c_str(const MCString *MCString_)
{
    char *str = (char *)malloc(MCString_->length + 1);
    memset(str, 0, MCString_->length + 1);
    memcpy(str,MCString_->str,MCString_->length);
    return str;
}

MCString *MCString_mid(const MCString *MCString_, int index, int length)
{
    MCString *ret = MCString_create();
    if(MCString_->length > index){
        int l = 0;
        l = index + length > MCString_->length ? MCString_->length - index : length;
        MCString_append(ret, MCString_->str + index, l);
    }
    return ret;
}

void MCString_clear(MCString *MCString_)
{
    if(MCString_){
        free(MCString_->str);
        MCString_->str = 0;
        MCString_->length = 0;
    }
}

int MCString_indexOf(const MCString *MCString_,const char *str, int length)
{
    int index = -1;
    if(MCString_ && str && length > 0){
        for(int i = 0; i <= MCString_->length - length; i++){
            if(strncmp(MCString_->str + i, str, length) == 0){
                index = i;
                break;
            }
        }
    }
    return index;
}

int MCString_lastIndexOf(const MCString *MCString_, const char *str, int length)
{
    int index = -1;
    if(MCString_ && str && length > 0){
        for(int i = MCString_->length - length; i >= 0; i--){
            if(strncmp(MCString_->str + i, str, length) == 0){
                index = i;
                break;
            }
        }
    }
    return index;
}

MCString *MCString_clone(const MCString *MCString_)
{
    MCString *ret = MCString_create();
    MCString_append(ret, MCString_->str, MCString_->length);
    return ret;
}

/******************************************************** MKit:MBind ***/

MBinder::MBinder(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
    timer->setSingleShot(true);

    setId();
    setExpireTime();
}

void MBinder::setId(int id)
{
    this->id = id;
}

int MBinder::getId() const
{
    return id;
}

void MBinder::setExpireTime(int timeout_ms)
{
    this->timeout_ms = timeout_ms;
}

void MBinder::start()
{
    list.clear();
    timer->start(timeout_ms);
}

void MBinder::setItem(const MBindItem &item)
{
    for(int i = 0; i < list.length(); i++){
        MBindItem &it = list[i];
        if(it.name == item.name){
            it.value = item.value;
            return ;
        }
    }
    list << item;
}

void MBinder::timeout_slot()
{
    emit binded(list, id);
}


QString MBindItem::toString() const
{
    QJsonObject json;
    json.insert(M_CAST_STRING(name),name);
    json.insert(M_CAST_STRING(value),value.toString());
    return MTL::get_str_from_QJsonObject(json);
}

/******************************************************** MKit:MDeviceBase ***/

MDeviceBase::MDeviceBase(QObject *parent) : QObject(parent),MError()
{

}

bool MDeviceBase::isConnected() const
{
    return true;
}
