include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../Lab9Prog/IKeypad.h \
        ../Lab9Prog/ILatch.h \
        ../Lab9Prog/lockcontroller.h \
        tst_test9lab.h

SOURCES += \
        ../Lab9Prog/lockcontroller.cpp \
        main.cpp

INCLUDEPATH += C:\Users\Arthur\Documents\Lab9Prog
