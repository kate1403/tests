TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    myfunc.c \
    editor.c \
    showevenbeforodd.c \
    showwordbeginnings.c \
    save.c \
    text/tracer.c \
    show.c \
    text/create_text.c \
    text/delete_line.c \
    text/remove_all.c \
    text/process_forward.c \
    text/process_forward2.c \
    text/process_forward_extra_option.c \
    load.c \
    text/cursors.c \
    showlengths.c \
    text/append_line.c \
    text/rc.c

HEADERS += \
    myfunc.h \
    text/text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DISTFILES += \
    load.o \
    text/tracer.o \
    load.o \
    show.o \
    shownum.o \
    text/create_text.o \
    text/delete_line.o \
    text/remove_all.o \
    text/process_forward.o \
    text/process_forward2.o \
    text/process_forward_extra_option.o \
    text/cursors.o \
    showlengths.o \
    text/append_line.o \
    text/rc.o \
    hello.txt \
    123.txt
