QT          += core gui widgets
CONFIG      += c++11

SOURCES += \
    main.cpp \
    example_mw.cpp \
    user_widget.cpp

HEADERS += \
    example_mw.h \
    user_widget.h

FORMS += \
    example_mw.ui \
    user_widget.ui

include (QStyleLoader.pri)

RESOURCES += \
    res.qrc
