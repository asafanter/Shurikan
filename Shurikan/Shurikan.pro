TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Analyzing/IPerformanceWatch.cpp \
    Analyzing/PerformanceWatch.cpp

HEADERS += \
    Shurikan_types.h \
    Shurikan.h \
    Analyzing/IPerformanceWatch.h \
    Analyzing/PerformanceWatch.h \
    Analyzing/PerformanceWatch_types.h \
    Analyzing/Analyzing.h


