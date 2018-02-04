#-------------------------------------------------
#
# Project created by QtCreator 2018-01-20T12:31:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MonitorMadness
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        base/CMD/CMD.cpp \
        base/CPUCore/CPUCore.cpp \
        base/Maths/Maths.cpp \
        modules/BatteryModule/Battery.cpp \
        modules/CPUModule/CPUModule.cpp \
        modules/DiskModule/Disk.cpp \
        modules/MonitorCore/MonitorCore.cpp \
        modules/NetworkModule/Network.cpp \
        modules/RamModule/Ram.cpp \
        modules/TemperatureModule/Temperature.cpp \
        modules/UserModule/User.cpp

HEADERS += \
        mainwindow.h \
        base/CMD/CMD.hpp \
        base/CPUCore/CPUCore.hpp \
        base/Maths/Maths.hpp \
        modules/BatteryModule/Battery.hpp \
        modules/CPUModule/CPUModule.hpp \
        modules/DiskModule/Disk.hpp \
        modules/MonitorCore/MonitorCore.hpp \
        modules/NetworkModule/Network.hpp \
        modules/RamModule/Ram.hpp \
        modules/TemperatureModule/Temperature.hpp \
        modules/UserModule/User.hpp \
        modules/IMonitorModule.hpp

FORMS += \
        mainwindow.ui
