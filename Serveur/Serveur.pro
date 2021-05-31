TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += FenServeur.h \
    client.h \
    message.h
SOURCES += FenServeur.cpp main.cpp \
    client.cpp \
    message.cpp
