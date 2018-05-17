TEMPLATE = app
CONFIG += console \
          c11

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ExtendibleHashing.c \
    main.c \
    Bucket.c \
    "../../Linked_Lists/Singly_Linked_List/LinkedList.c" \
    Directory.c

HEADERS += \
    ExtendibleHashing.h \
    Bucket.h \
    "../../Linked_Lists/Singly_Linked_List/LinkedList.h" \
    Directory.h
