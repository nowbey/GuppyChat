TEMPLATE = app
QT += \
    widgets \
    network
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += \
    ClientChat.h \
    ClientConnection.h \
    ClientTabChat.h

SOURCES += main.cpp \
    ClientChat.cpp \
    ClientConnection.cpp \
    ClientTabChat.cpp

FORMS += \
    ClientChat.ui \
    ClientConnection.ui \
    ClientTabChat.ui

RESOURCES += \
    Images.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../GC_common/build-GC_common-Desktop-Debug/release/ -lGC_common
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../GC_common/build-GC_common-Desktop-Debug/debug/ -lGC_common
else:unix: LIBS += -L$$PWD/../GC_common/build-GC_common-Desktop-Debug/ -lGC_common

INCLUDEPATH += $$PWD/../GC_common/build-GC_common-Desktop-Debug
DEPENDPATH += $$PWD/../GC_common/build-GC_common-Desktop-Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../GC_common/build-GC_common-Desktop-Debug/release/libGC_common.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../GC_common/build-GC_common-Desktop-Debug/debug/libGC_common.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../GC_common/build-GC_common-Desktop-Debug/release/GC_common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../GC_common/build-GC_common-Desktop-Debug/debug/GC_common.lib
else:unix: PRE_TARGETDEPS += $$PWD/../GC_common/build-GC_common-Desktop-Debug/libGC_common.a


