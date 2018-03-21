TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ExtendibleHashing.c \
    main.c \
    HashMap.c \
    Bucket.c

HEADERS += \
    ExtendibleHashing.h \
    Bucket.h \
    HashMap.h
