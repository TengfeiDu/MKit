INCLUDEPATH  += $$PWD/include
 
HEADERS += \ 
    $$PWD/include/amqp_framing.h \ 
    $$PWD/include/amqp.h \ 
    $$PWD/include/amqp_tcp_socket.h \ 
 
 
LIBS += $$PWD/bin/librabbitmq.4.dll
