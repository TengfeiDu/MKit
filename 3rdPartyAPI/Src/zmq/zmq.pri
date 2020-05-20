

INCLUDEPATH += $$PWD/zeromq-4.3.2/include \
                $$PWD/zmqpp-4.2.0/include \
                $$PWD/zmqpp-4.2.0/include/zmqpp

HEADERS += $$PWD/zeromq-4.3.2/include/zmq.h \
            $$PWD/zeromq-4.3.2/include/zmq_utils.h \
            $$PWD/zmqpp-4.2.0/include/zmqpp_export.h  \
$$PWD/zmqpp-4.2.0/include/zmqpp/actor.hpp            \
$$PWD/zmqpp-4.2.0/include/zmqpp/auth.hpp             \
$$PWD/zmqpp-4.2.0/include/zmqpp/byte_ordering.hpp    \
$$PWD/zmqpp-4.2.0/include/zmqpp/compatibility.hpp    \
$$PWD/zmqpp-4.2.0/include/zmqpp/context.hpp          \
$$PWD/zmqpp-4.2.0/include/zmqpp/context_options.hpp  \
$$PWD/zmqpp-4.2.0/include/zmqpp/curve.hpp            \
$$PWD/zmqpp-4.2.0/include/zmqpp/exception.hpp        \
$$PWD/zmqpp-4.2.0/include/zmqpp/frame.hpp            \
$$PWD/zmqpp-4.2.0/include/zmqpp/inet.hpp             \
$$PWD/zmqpp-4.2.0/include/zmqpp/loop.hpp             \
$$PWD/zmqpp-4.2.0/include/zmqpp/message.hpp          \
$$PWD/zmqpp-4.2.0/include/zmqpp/poller.hpp           \
$$PWD/zmqpp-4.2.0/include/zmqpp/proxy.hpp            \
$$PWD/zmqpp-4.2.0/include/zmqpp/proxy_steerable.hpp  \
$$PWD/zmqpp-4.2.0/include/zmqpp/reactor.hpp          \
$$PWD/zmqpp-4.2.0/include/zmqpp/signal.hpp           \
$$PWD/zmqpp-4.2.0/include/zmqpp/socket.hpp           \
$$PWD/zmqpp-4.2.0/include/zmqpp/socket_mechanisms.hpp\
$$PWD/zmqpp-4.2.0/include/zmqpp/socket_options.hpp   \
$$PWD/zmqpp-4.2.0/include/zmqpp/socket_types.hpp     \
$$PWD/zmqpp-4.2.0/include/zmqpp/z85.hpp              \
$$PWD/zmqpp-4.2.0/include/zmqpp/zap_request.hpp      \
$$PWD/zmqpp-4.2.0/include/zmqpp/zmqpp.hpp


LIBS += $$PWD/zeromq-4.3.2/bin/libzmq.dll \
        $$PWD/zmqpp-4.2.0/bin/libzmqpp.dll
