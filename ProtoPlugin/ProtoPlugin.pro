CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(protowidgetplugin)
TEMPLATE    = lib

HEADERS     = protowidgetplugin.h
SOURCES     = protowidgetplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(protowidget.pri)

FORMS += \
    dialog.ui
