#-------------------------------------------------
#
# Project created by QtCreator 2012-09-23T23:14:15
#
# Das gesamte Projekt steht unter der GPL v3 Lizenz!
#
#-------------------------------------------------

QT          += core gui

TARGET = 2D-Game-Creator
TEMPLATE = app

RC_FILE = 		2D-Game-Creator/res/appicon.rc \


SOURCES += 	2D-Game-Creator/main/main.cpp\
           	2D-Game-Creator/main/mainwindow.cpp \
           	2D-Game-Creator/about/about.cpp	\
           	2D-Game-Creator/editor/hero_editor/hero_editor.cpp \
           	2D-Game-Creator/editor/hero_editor/hero_editor_void.cpp \
           	2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.cpp \
		2D-Game-Creator/editor/monster_editor/monster_editor.cpp \
		2D-Game-Creator/editor/monster_editor/monster_editor_void.cpp \
    		2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.cpp \
    		2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.cpp \
    		2D-Game-Creator/simulation/kampfsimulation/kampfsimulation.cpp \

HEADERS  += 	2D-Game-Creator/main/mainwindow.h \
            	2D-Game-Creator/about/about.h \
            	2D-Game-Creator/editor/hero_editor/hero_editor.h \
            	2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.h \
		2D-Game-Creator/editor/monster_editor/monster_editor.h	\
    		2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.h \
    		2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.h \
    		2D-Game-Creator/simulation/kampfsimulation/kampfsimulation.h \
		
FORMS    += 	2D-Game-Creator/main/mainwindow.ui \
            	2D-Game-Creator/about/about.ui \
            	2D-Game-Creator/editor/hero_editor/hero_editor.ui \
		2D-Game-Creator/editor/monster_editor/monster_editor.ui \
            	2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.ui \
    		2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.ui \
    		2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.ui \
    		2D-Game-Creator/simulation/kampfsimulation/kampfsimulation.ui \

RESOURCES += 	2D-Game-Creator/res/ress_con.qrc \


