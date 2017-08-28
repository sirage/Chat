TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .



INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.15063.0/ucrt"



INCLUDEPATH += "C:/Qt/5.8/Src/qtwebengine/src/3rdparty/chromium/third_party/crashpad/crashpad/compat/non_win"

INCLUDEPATH += $$quote(C:\\Qt\\5.8\\Src\\qtwebengine\\src\\3rdparty\\chromium\\third_party\\mesa\\src\\include)

LIBS += -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10240.0/um/x86"
LIBS += -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.15063.0/ucrt/x86"


SOURCES += \
    main.cpp \
    win_server.cpp

HEADERS += \
    win_server.h
