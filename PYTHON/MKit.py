#!/usr/bin/env python
# -*- coding: utf-8 -*-
#@author:tf.du
#@date:2019-01-20

'''
    Character Encoding:

    ddd = QtCore.QString("中国A")
    bytearray = QtCore.QByteArray().append(ddd)
    print MTL().get_hex_str_from_QByteArray(bytearray,True,True)         #0xE4 B8 AD E5 9B BD 41                   RIGHT
    print MTL().get_hex_str_from_QByteArray(ddd.toAscii(),True,True)     #0xE4 B8 AD E5 9B BD 41                   RIGHT
    print MTL().get_hex_str_from_QByteArray(ddd.toLatin1(),True,True)    #0xE4 B8 AD E5 9B BD 41                   RIGHT
    print MTL().get_hex_str_from_QByteArray(ddd.toLocal8Bit(),True,True) #0x3F 3F 2D 3F 3F 3F 41                   ERROR
    print MTL().get_hex_str_from_QByteArray(ddd.toUtf8(),True,True)      #0xC3 A4 C2 B8 C2 AD C3 A5 C2 9B C2 BD 41 ERROR
'''

import sys,time,datetime,os,json,SendKeys,win32api,win32con
import serial,serial.tools.list_ports
from PyQt4 import QtGui, QtCore,QtNetwork,uic,QtXml
from pykeyboard import *
from pymouse import *

##########################################################################
"""
MDG(sys._getframe().f_lineno, __file__, ... )

log = {}
log["message"] = ""
log["data"] = ""
log["line"] = sys._getframe().f_lineno
log["file"] = __file__
log["func"] = sys._getframe().f_code.co_name

print MTL.get_json_str_from_dict(log,2)
"""

def MDG(*args):
    str = "[{}]".format(MTL().get_time_now())
    for i in range(args.__len__()):
        str += "[{}]".format(args[i])
    print str

##########################################################################
class MTL(object):
    def __init__(self):
        object.__init__(self)

    @staticmethod
    def get_time_now():
        ''' -> python str '''
        dt = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')
        f = "2018-01-01 12:12:59.000"
        return  dt[0 : len(f)]

    @staticmethod
    def get_binary_str_from_uchar(uchar,reverseOrder = False):
        ''' -> python str '''
        uchar &=  0xff
        ret = ""
        for i in range(8):
            if (uchar >> (8 - i - 1)) & 0x01 == 0x01:
                ret += "1"
            else:
                ret += "0"
        if reverseOrder:
            tmp = ""
            for i in range(8):
                tmp += ret[8 - i - 1]
            ret = tmp
        return ret

    @staticmethod
    def get_binary_str_from_uint(uint,autoAddSpace = False):
        ''' -> python str '''
        uint = uint & 0xffffffff
        ret = ""
        for i in range(4):
            ret += MTL.get_binary_str_from_uchar(uint >> ((4 - i - 1) * 8))
            if autoAddSpace and i != 3:
                ret += " "
        return ret

    @staticmethod
    def get_hex_str_from_uint_upper(uint):
        ''' -> python str '''
        uint = uint & 0xffffffff
        ret = ""
        for i in range(4):
            ret += MTL.get_hex_str_from_ucahr_upper(uint >> ((4 - i - 1) * 8))
        return ret

    @staticmethod
    def get_hex_str_from_ucahr_upper(uchar):
        ''' -> python str '''
        ret = ""
        uchar  &= 0xff
        symbol = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
        ret = symbol[uchar / 16] + symbol[uchar % 16]
        return ret

    @staticmethod
    def get_hex_str_from_uchar_array_upper(array,autoAddPrefix = False,autoAddSpace = False):
        ''' -> python str '''
        ret = ""
        length = len(array)
        for i in range(length):
            ret += MTL.get_hex_str_from_ucahr_upper(array[i] & 0xff)
            if autoAddSpace and i != length - 1:
                ret += " "
        if autoAddPrefix and ret.__len__() > 0:
            ret = "0x" + ret
        return ret

    @staticmethod
    def get_QByteArray_from_rawdata(array):
        ''' -> QByteArray '''
        hexStr = MTL.get_hex_str_from_uchar_array_upper(array)
        return  QtCore.QByteArray.fromHex(hexStr)

    @staticmethod
    def get_hex_str_from_python_str(str):
        ''' -> python str '''
        return MTL.get_hex_str_from_uchar_array_upper(MTL.get_array_ascii_from_str(str))

    @staticmethod
    def get_hex_str_from_QByteArray(qbytearray,autoAddPrefix = False,autoAddSpace = False):
        ''' -> python str '''
        data = []
        data_in = QtCore.QByteArray(qbytearray)
        for i in range(data_in.length()):
            data.append(ord(data_in.at(i)))
        return MTL.get_hex_str_from_uchar_array_upper(data,autoAddPrefix,autoAddSpace)

    @staticmethod
    def get_array_ascii_from_str(str):
        ''' -> list[int] '''
        return map(ord,str)

    @staticmethod
    def set_data_2_file(file,array):
        """ Only for uchar array """
        f = open(file,"wb+")
        for i in range(len(array)):
            f.write(chr(array[i] & 0xff))
        f.close()

    @staticmethod
    def get_data_from_file(file_str):
        """  -> QByteArray """
        f = QtCore.QFile(file_str)
        ret = QtCore.QByteArray()
        if f.open(QtCore.QIODevice.ReadOnly):
            ret = f.readAll()
            f.close()
        return ret

    @staticmethod
    def get_json_str_from_dict(j, indent = 0):
        '''  -> python str'''
        if indent > 0:
            return json.dumps(j, separators=(",", ":"), indent=indent,ensure_ascii=False)
        return json.dumps(j, separators=(",", ":"),ensure_ascii=False)

    @staticmethod
    def split(qbytearray_data,qbytearray_sep):
        ''' -> list[QByteArray] '''
        '''
         *      QByteArray dd(",1,,2,3465,");
         *      MDG << MTL::split(dd,",")
         *          << MTL::split(dd,",,,")
         *          << MTL::split(dd,",,");
                ("", "1", "", "2", "3465") (",1,,2,3465,") (",1", "2,3465,")
        '''
        ret = []
        data = QtCore.QByteArray(qbytearray_data)
        sep = QtCore.QByteArray(qbytearray_sep)
        if data.length() < 1:
            return ret
        if sep.length() < 1:
            ret.append(data)
            return ret
        index = data.indexOf(sep)
        if index < 0:
            ret.append(data)
            return ret
        ok = data.mid(0,index)
        ret.append(ok)
        left = data.mid(index + sep.length())
        if left.length() < 1:
            return  ret
        index = left.indexOf(sep)
        if index >= 0:
            retTmp = MTL.split(left,sep)
            for i in retTmp:
                ret.append(i)
        else:
            ret.append(left)
        return  ret

    @staticmethod
    def keybd_event_down(key = win32con.VK_RETURN):
        win32api.keybd_event(key, 0, 0, 0)

    @staticmethod
    def keybd_event_up(key = win32con.VK_RETURN):
        win32api.keybd_event(key, 0, win32con.KEYEVENTF_KEYUP, 0)

    @staticmethod
    def keybd_event_down_and_up(key = win32con.VK_RETURN):
        win32api.keybd_event(key, 0, 0, 0)
        win32api.keybd_event(key, 0, win32con.KEYEVENTF_KEYUP, 0)

    @staticmethod
    def keyboard_clicked_str(str = "hello world"):
        kb = PyKeyboard()
        kb.type_string(str)

##########################################################################
class MQNetworkRequestData(QtCore.QObject):
    def __init__(self,parent = None,
                 req = QtNetwork.QNetworkRequest(),data = QtCore.QByteArray(),
                 uuid = QtCore.QUuid().createUuid().toString(),
                 createTime = MTL().get_time_now(),timeout = 0,
                 operation = QtNetwork.QNetworkAccessManager.PostOperation):
        QtCore.QObject.__init__(self,parent)
        self.req = req
        self.data = data
        self.uuid = uuid
        self.createTime = createTime
        self.timeout  = timeout
        self.operation = operation

    def toDict(self):
        req = {}
        req["url"] = QtCore.QByteArray().append(self.req.url().toString()).data()
        header = {}
        list = self.req.rawHeaderList()
        for i in list:
            header["{}".format(i)] = self.req.rawHeader(i).data()
        req["header"] = header
        req["uuid"] = QtCore.QByteArray().append(self.uuid).data()
        req["createTime"] = self.createTime
        req["timeout"] = self.timeout
        req["operation"] = self.operation
        req["data"] = self.data.data()
        return  req
##########################################################################
class MHttpHandler(QtCore.QObject):
    '''
    Create NEW for EACH http request.
    Example:
        def finished(req,headers,inData,error):
            print MTL().get_json_str_from_dict(req.toDict(),2)
            print MTL().get_json_str_from_dict(headers,2)
            print inData
            print error
        nn = MHttpHandler()
        nn.finished.connect(finished)
        req = QtNetwork.QNetworkRequest()
        req.setUrl(QtCore.QUrl("http://www.jd.com"))
        req.setHeader(QtNetwork.QNetworkRequest.ContentTypeHeader,"application/json;charset=utf-8")
        nn.post(req,QtCore.QByteArray("123.000"),1000 * 5)
    '''
    finished = QtCore.pyqtSignal(MQNetworkRequestData,object,QtCore.QByteArray,QtNetwork.QNetworkReply.NetworkError)

    def __init__(self, parent=None):
        QtCore.QObject.__init__(self,parent)
        self._req = MQNetworkRequestData()
        self._replyHeaders  = {}
        self._inData = QtCore.QByteArray()
        self._error = 0
        self._manager = QtNetwork.QNetworkAccessManager(self)
        self._manager.finished.connect(self._finished_slot)
        self._timer = QtCore.QTimer(self)
        self._timer.setSingleShot(True)
        self._timer.timeout.connect(self._timeout_slot)
        self._rep = QtCore.QObject(self)

    def post(self,req = QtNetwork.QNetworkRequest(),data = QtCore.QByteArray(),timeout_ms = 0):
        self._createReply(req = req,data = data,timeout_ms = timeout_ms,operation = QtNetwork.QNetworkAccessManager.PostOperation)

    def get(self,req = QtNetwork.QNetworkRequest(),timeout_ms = 0):
        self._createReply(req = req,timeout_ms = timeout_ms,operation = QtNetwork.QNetworkAccessManager.GetOperation)

    def _createReply(self,req,data = QtCore.QByteArray(),timeout_ms = 0,operation = QtNetwork.QNetworkAccessManager.PostOperation):
        self._req.req = req
        self._req.data = data
        self._req.uuid = QtCore.QUuid().createUuid().toString()
        self._req.createTime = MTL().get_time_now()
        self._req.timeout  = timeout_ms
        self._req.operation = operation
        if timeout_ms > 0 :
            self._timer.start(timeout_ms)
        if operation == QtNetwork.QNetworkAccessManager.PostOperation:
            self._rep = self._manager.post(req,data)
        elif operation == QtNetwork.QNetworkAccessManager.GetOperation:
            self._rep = self._manager.get(req)

    @QtCore.pyqtSlot(QtNetwork.QNetworkReply)
    def _finished_slot(self, reply):
        if reply.isReadable():
            self._inData  = reply.readAll()
        self._error = reply.error()
        replyHeader = reply.rawHeaderPairs()
        reply.deleteLater()
        self._timer.stop()
        self._replyHeaders = {}
        for i in replyHeader:
            self._replyHeaders["{}".format(i[0])] = i[1].data()
        self.finished.emit(self._req,self._replyHeaders,self._inData,self._error)

    @QtCore.pyqtSlot()
    def _timeout_slot(self):
        self._rep.abort()
##########################################################################
class MBlackBoard():
    def __init__(self):
        self._isEmpty = True
        self._data = ""

    def clear(self):
        self._isEmpty = True

    def isEmpty(self):
        return self._isEmpty

    def write(self,data):
        self._data = data
        self._isEmpty = False

    def read(self):
        return self._data

    def take(self):
        data = self._data
        self.clear()
        return data
##########################################################################
class MLogger(QtCore.QThread):
    def __init__(self,parent = None):
        QtCore.QThread.__init__(self,parent)
        self.moveToThread(self)
        self.start()

    def run(self):
        self.exec_()

    @QtCore.pyqtSlot(QtCore.QByteArray,QtCore.QByteArray,QtCore.QByteArray)
    def log(self,data,path = "./log",prefixFileName = "DEFAULT"):
        #MDG(sys._getframe().f_lineno, __file__,self,data,path,prefixFileName)
        ''' prepare filename '''
        time = MTL().get_time_now()[0 : "2018-01-01".__len__()]
        ''' check dir  '''
        path = path + "/" + time
        dir = QtCore.QDir(QtCore.QString(path))
        if not dir.exists():
            dir.mkpath(".")
        fullname = path + "/" + prefixFileName + "_" + time + ".log"
        ''' write data '''
        f = QtCore.QFile()
        f.setFileName(QtCore.QString(fullname))
        if f.open(QtCore.QIODevice.Append):
            f.write(data)
            f.close()

Instance_Singleton_MLogger = MBlackBoard()
def get_instance_MLogger():
    if Instance_Singleton_MLogger.isEmpty():
        Instance_Singleton_MLogger.write(MLogger())
    return Instance_Singleton_MLogger.read()

def HITLOG(data,path = "./log",prefixFileName = "DEFAULT"):
    data = QtCore.QString("[%1][%2]\n").arg(MTL().get_time_now()).arg(data)
    data = QtCore.QByteArray().append(data)
    logger = get_instance_MLogger()
    QtCore.QMetaObject.invokeMethod(logger,"log",QtCore.Qt.QueuedConnection,
                                    QtCore.Q_ARG("QByteArray",data),QtCore.Q_ARG("QByteArray",path),
                                    QtCore.Q_ARG("QByteArray", prefixFileName))
##########################################################################
class MTimeLabel(QtGui.QLabel):
    def __init__(self,parent = None):
        QtGui.QLabel.__init__(self,parent)
        self.timer = QtCore.QTimer(self)
        self.timer.timeout.connect(self.timeout_slot)
        self.timer.start(1000 * 1)

    @QtCore.pyqtSlot()
    def timeout_slot(self):
        self.setText(QtCore.QString(MTL().get_time_now()).mid(0,"2019-08-08 12:12:12".__len__()))

##########################################################################
class MQDomDocument(QtXml.QDomDocument):
    def __init__(self):
        QtXml.QDomDocument.__init__(self)

    def get_element_by_id(self, id_QString):
        ''' -> QDomElement '''
        ret = QtXml.QDomElement()
        id = QtCore.QString(id_QString)
        root = self.documentElement()
        if not root.isElement():
            return  ret
        return self.get_element_by_id_from_QDomElement(root, id_QString)

    @staticmethod
    def get_element_by_id_from_QDomElement(QDomElement, id = "001"):
        ''' -> QDomElement '''
        ret = QtXml.QDomElement()
        if QDomElement.isElement() and QDomElement.hasAttributes() and QDomElement.attribute("id") == id:
            return  ret
        childList = QDomElement.childNodes()
        for i in range(childList.size()):
            node = childList.at(i)
            if node.nodeType() == QtXml.QDomNode.ElementNode:
                ret = MQDomDocument.get_element_by_id_from_QDomElement(node.toElement(), id)
                if not ret.isNull():
                    return  ret
        return ret
##########################################################################
class MQStackedWidget(QtGui.QStackedWidget):
    def __init__(self,parent = None):
        QtGui.QStackedWidget.__init__(self,parent)

    def setWidget(self,QWidget):
        ''' return list[QWidget] which has been removed but NOT deleted '''
        ret = []
        count = self.count()
        for index in range(count):
            w = self.widget(index)
            self.removeWidget(w)
            ret.append(w)
        self.addWidget(QWidget)
        return ret

    def getAllWidget(self):
        ''' -> list[QWidget] '''
        ret = []
        count = self.count()
        for index in range(count):
            w = self.widget(index)
            ret.append(w)
        return ret

    def clear(self):
        ''' remove and delete all QWidget '''
        count = self.count()
        for index in range(count):
            w = self.widget(index)
            self.removeWidget(w)
            w.deleteLater()

##########################################################################
class MSerialWatcher(QtCore.QObject):

    readyRead = QtCore.pyqtSignal(QtCore.QByteArray)

    def __init__(self,parent = None):
        QtCore.QObject.__init__(self,parent)
        self.serial = MBlackBoard()
        self.timer = QtCore.QTimer(self)
        self.timer.timeout.connect(self._timeout_slot)
        self.startReadWatcher()

    def __del__(self):
        return

    def setTargetSerial(self,serial):
        self.serial.write(serial)

    def startReadWatcher(self,interval_ms = 100):
        self.timer.start(interval_ms)

    @QtCore.pyqtSlot()
    def _timeout_slot(self):
        if self.serial.isEmpty():
            return
        data = str(self.serial.read().read_all())
        if data.__len__() < 1:
            return
        data = QtCore.QByteArray(data)
        self.readyRead.emit(data)
##########################################################################
class MDataParser(QtCore.QObject):

    ''' header and ender are deleted. '''
    frameDetected = QtCore.pyqtSignal(QtCore.QByteArray)

    def __init__(self,parent = None):
        QtCore.QObject.__init__(self,parent)
        self._buffer = QtCore.QByteArray()
        self._header = QtCore.QByteArray()
        self._ender = QtCore.QByteArray()
        self.setHeader()
        self.setEnder()

    def setHeader(self,qbytearray = ":"):
        self._header = QtCore.QByteArray(qbytearray)

    def setEnder(self,qbytearray = "\r\n"):
        self._ender = QtCore.QByteArray(qbytearray)

    def append(self,qbytearray):
        self._buffer += QtCore.QByteArray(qbytearray)
        sep = self._ender if self._ender.length() > 0 else self._header
        sep2 = self._header
        if self._header.length() < 1 or self._ender.length() < 1:
            sep2 = ""
        if sep.length() < 1:
            return
        lastIndex = self._buffer.lastIndexOf(sep)
        if lastIndex < 0:
            return
        target = self._buffer.mid(0,lastIndex)
        self._buffer = self._buffer.mid(lastIndex + sep.length())
        if target.length() < 1:
            return
        ret = MTL.split(target,sep)
        for i in ret:
            if i.length() < 1:
                continue
            if sep2.length() > 0:
                i.replace(sep2,"")
            self.frameDetected.emit(i)


##########################################################################
class MWatchDog(QtCore.QObject):
    """  Will be emitted only ONCE for each alive dog. """
    hungry = QtCore.pyqtSignal()

    def __init__(self, parent=None):
        QtCore.QObject.__init__(self, parent)
        self._dog = QtCore.QTimer()
        self._dog.setParent(self)
        self._dog.setSingleShot(True)
        self._dog.timeout.connect(self.hungry)
        self._timeLimitMs = 0
        self._lastFeedTime = 0
        self.setTimeLimit()

    def remainingTime(self):
        """ return > 0 if dog is alive. """
        pastTime = QtCore.QDateTime.currentMSecsSinceEpoch() - self._lastFeedTime
        return self._dog.interval() - pastTime

    def isAlive(self):
        return self._dog.isActive()

    def setTimeLimit(self, limitMs=1000 * 60 * 5):
        """ Call this before start(). """
        self._timeLimitMs = limitMs

    def start(self):
        self._dog.start(self._timeLimitMs)
        self._lastFeedTime = QtCore.QDateTime.currentMSecsSinceEpoch()

    def stop(self):
        self._dog.stop()

    def feedDog(self):
        """ Equivalent to calling start(). """
        self.start()
##########################################################################
class MStabilizer(QtCore.QObject):

    stabilized = QtCore.pyqtSignal(object)

    def __init__(self,parent = None):
        QtCore.QObject.__init__(self,parent)
        self._size = 0
        self._range = 0
        self._queue = []
        self.setSize()
        self.setRange()

    def setSize(self,sz = 5):
        self._size = sz

    def setRange(self,rg = 500):
        self._range = rg

    def clear(self):
        length = self._queue.__len__()
        for i in range(length):
            self._queue.pop(0)

    def append(self,value):
        self._queue.append(value)
        if self._queue.__len__() < self._size:
            return
        stable = True
        for i in range(self._queue.__len__() - 1):
            if QtCore.qAbs(value - self._queue[i]) > QtCore.qAbs(self._range):
                stable = False
                break
        removeCount = self._queue.__len__() - self._size
        for i in range(removeCount - 1):
            if self._queue.__len__() > 0:
                self._queue.pop(0)
        if stable:
            self.stabilized.emit(value)
##########################################################################
class MDuplicateFilter(QtCore.QObject):

    """ value, bool_NotDuplicate """
    filtered = QtCore.pyqtSignal(object,object)

    def __init__(self,parent = None):
        QtCore.QObject.__init__(self,parent)
        self._queue = []
        self._size = 0
        self._amount = 0
        self._period = 0
        self._type = 0
        self.setSize()
        self.setAmount()
        self.setPeriod()
        self.setType(MDuplicateFilter.Amount)

    def setSize(self,sz = 100):
        self._size = sz

    def setAmount(self,amt = 20):
        self._amount = amt

    def setPeriod(self,prd = 1000 * 30):
        self._period = prd

    def setType(self,t):
        self._type = t

    def clear(self):
        for i in range(self._queue.__len__()):
            self._queue.pop(0)

    def append(self,value):
        noDuplicateInAmount = True
        queueLength = self._queue.__len__()
        min = queueLength if queueLength < self._amount else self._amount
        for i in range(min):
            if self._queue[queueLength - 1 - i][0] == value:
                noDuplicateInAmount = False
                break
        noDuplicateInPeriod = True
        currentTime = QtCore.QDateTime.currentMSecsSinceEpoch()
        for i in range(queueLength):
            item = self._queue[queueLength - 1 - i]
            if item[1] + self._period < currentTime:
                break
            if item[0] == value:
                noDuplicateInPeriod = False
                break

        self._queue.append((value,currentTime))

        remove = self._queue.__len__() - self._size
        for i in range(remove):
            if self._queue.__len__() > 0:
                self._queue.pop(0)

        if self._type == MDuplicateFilter.Amount:
            self.filtered.emit(value,noDuplicateInAmount)
        if self._type == MDuplicateFilter.Period:
            self.filtered.emit(value,noDuplicateInPeriod)
        if self._type == MDuplicateFilter.AmountAndPeriod:
            self.filtered.emit(value,noDuplicateInAmount or noDuplicateInPeriod)

    Amount = 0
    Period = 1
    AmountAndPeriod = 2
##########################################################################

if __name__ == "__main__":
    app = QtGui.QApplication([])

    data = QtCore.QByteArray(",1,,2,3465,")
    print MTL().split(data, QtCore.QByteArray(","))
    print MTL().split(data, QtCore.QByteArray(",,,"))
    print MTL().split(data, QtCore.QByteArray(",,"))

    app.exec_()




