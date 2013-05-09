#-------------------------------------------------
#
# Project created by QtCreator 2012-09-23T23:14:15
#
# Das gesamte Projekt steht unter der GPL v3 Lizenz!
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2D-Game-Creator
TEMPLATE = app\

TRANSLATIONS += 2D-Game-Creator/translation/german_DE.ts \
                2D-Game-Creator/translation/english_UK.ts \
		2D-Game-Creator/translation/russia_RUS.ts \
		2D-Game-Creator/translation/french_FRA.ts \

RC_FILE += 	2D-Game-Creator/res/appicon.rc \


SOURCES += 	2D-Game-Creator/main/main.cpp \
                2D-Game-Creator/main/mainwindow.cpp \
		2D-Game-Creator/diverses/ext_lib/qcustomplot.cpp \
                2D-Game-Creator/diverses/option.cpp \
                2D-Game-Creator/diverses/about.cpp \
                2D-Game-Creator/editor/main_editor.cpp \
    		2D-Game-Creator/kampf_simulator/kampfsimulator.cpp \
                2D-Game-Creator/kampf_simulator/kampfsimulator_simulation.cpp \
    2D-Game-Creator/editor/ui_funktionen.cpp \
    2D-Game-Creator/editor/main_editor_lvl.cpp

HEADERS  += 	2D-Game-Creator/main/mainwindow.h \
    		2D-Game-Creator/diverses/global.h \
		2D-Game-Creator/diverses/ext_lib/qcustomplot.h \
                2D-Game-Creator/diverses/option.h \
                2D-Game-Creator/diverses/about.h \
                2D-Game-Creator/diverses/global.h \
                2D-Game-Creator/editor/main_editor.h \
    		2D-Game-Creator/kampf_simulator/kampfsimulator.h \
                2D-Game-Creator/kampf_simulator/kampfsimulator_simulation.h \
    2D-Game-Creator/editor/main_editor_lvl.h

FORMS    += 	2D-Game-Creator/main/mainwindow.ui \
                2D-Game-Creator/diverses/option.ui \
                2D-Game-Creator/diverses/about.ui \
                2D-Game-Creator/editor/main_editor.ui \
                2D-Game-Creator/kampf_simulator/kampfsimulator.ui \
                2D-Game-Creator/kampf_simulator/kampfsimulator_simulation.ui \
    2D-Game-Creator/editor/main_editor_lvl.ui


RESOURCES += 	2D-Game-Creator/res/ress_con.qrc \

QT +=           printsupport
