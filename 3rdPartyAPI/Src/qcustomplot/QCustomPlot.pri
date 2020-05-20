#-------------------------------------------------
#
#sudo apt-get install mesa-common-dev
#
#-------------------------------------------------


INCLUDEPATH  += $$PWD
HEADERS +=    $$PWD/qcustomplot.h
SOURCES +=    $$PWD/qcustomplot.cpp

DISTFILES += $$PWD/*.txt

qtHaveModule(printsupport): QT += printsupport
