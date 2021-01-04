TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lfltk_gl -lGLU -lGL -lfltk -lm -lX11
LIBS += -lXext -lpthread -lXinerama -lXfixes -lXcursor
LIBS += -lXft -lXrender -lfontconfig -ldl -lelf -lsimavr

QMAKE_CC=/usr/lib/ccache/bin/clang
QMAKE_CXX=/usr/lib/ccache/bin/clang++
QMAKE_CXXFLAGS += -mtune=native
QMAKE_CFLAGS += -mtune=native
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CFLAGS_RELEASE += -O3

SOURCES += \
        button.c \
        fltk.cxx \
        main.cpp

HEADERS += \
    button.h \
    fltk.h
