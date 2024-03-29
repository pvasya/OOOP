QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    historywindow.cpp \
    main.cpp \
    mainwindow.cpp \
    settingswindow.cpp \
    test_mynotesmaker.cpp

HEADERS += \
    historywindow.h \
    mainwindow.h \
    openai.hpp \
    settingswindow.h \
    test_mynotesmaker.h

FORMS += \
    historywindow.ui \
    mainwindow.ui \
    settingswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    img/1.png \
    img/2.png \
    img/3.png \
    img/4.png \
    img/5.png \
    img/6.png \
    img/animation.gif \
    img/close_btn_icon.png \
    img/close_btn_iconred.png \
    img/hide-removebg.png \
    img/hidered-removebg.png \
    img/max-removebg.png \
    img/maxred-removebg.png \
    img/pin-removebg.png \
    img/pinred-removebg.png \
    img/setting.png \
    img/settingblack.png \
    img/standartred-removebg.png \
    img/unpin-removebg.png \
    img/unpinred-removebg.png

LIBS += -LC:/curl/lib
LIBS += -lcurl
INCLUDEPATH += C:/curl/include
