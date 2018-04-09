include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD\\\"

HEADERS +=     tst_test1.h \
    ../app/myfunc.h \
    fibonachi_test.h

SOURCES +=     main.cpp \
    ../app/myfunc.c

INCLUDEPATH += ../app


SOURCES += \
    ../app/showlengths.c \
    ../app/text/create_text.c \
    ../app/text/process_forward.c \
    ../app/text/cursors.c \
    ../app/text/tracer.c \
    ../app/text/delete_line.c \
    ../app/text/append_line.c \
    ../app/text/remove_all.c \
    ../app/load.c


HEADERS += \
    ../app/text/text.h \
    ../app/common.h \


QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

