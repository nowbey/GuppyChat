TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += \
    FenClient.h \
    message.h

SOURCES += main.cpp \
    FenClient.cpp \
    message.cpp


FORMS += \
    FenClient.ui
