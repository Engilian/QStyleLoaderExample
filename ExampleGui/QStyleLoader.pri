win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QStyleLoader/release/ -lQStyleLoader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QStyleLoader/debug/ -lQStyleLoader
else:unix: LIBS += -L$$OUT_PWD/../QStyleLoader/ -lQStyleLoader

INCLUDEPATH += $$PWD/../QStyleLoader
DEPENDPATH += $$PWD/../QStyleLoader

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QStyleLoader/release/libQStyleLoader.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QStyleLoader/debug/libQStyleLoader.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QStyleLoader/release/QStyleLoader.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QStyleLoader/debug/QStyleLoader.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../QStyleLoader/libQStyleLoader.a
