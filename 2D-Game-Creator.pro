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

TRANSLATIONS += 2D-Game-Creator/translation/german_DE.ts \
                2D-Game-Creator/translation/english_UK.ts \
		2D-Game-Creator/translation/russia_RUS.ts \
		2D-Game-Creator/translation/french_FRA.ts \

RC_FILE += 	2D-Game-Creator/res/appicon.rc \

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
    		2D-Game-Creator/editor/effekt_editor/effekt_editor.cpp \
    		2D-Game-Creator/diverses/option.cpp \
    		2D-Game-Creator/editor/ausruestungs_editor/ausruestung.cpp \
    		2D-Game-Creator/editor/klassen_editor/klassen_editor.cpp

HEADERS  += 	2D-Game-Creator/main/mainwindow.h \
            	2D-Game-Creator/about/about.h \
            	2D-Game-Creator/editor/hero_editor/hero_editor.h \
            	2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.h \
		2D-Game-Creator/editor/monster_editor/monster_editor.h	\
    		2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.h \
    		2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.h \
    		2D-Game-Creator/simulation/kampfsimulation/kampfsimulation.h \
    		2D-Game-Creator/editor/effekt_editor/effekt_editor.h \
    		2D-Game-Creator/diverses/option.h \
    		2D-Game-Creator/editor/ausruestungs_editor/ausruestung.h \
   		2D-Game-Creator/editor/klassen_editor/klassen_editor.h
		
FORMS    += 	2D-Game-Creator/main/mainwindow.ui \
            	2D-Game-Creator/about/about.ui \
            	2D-Game-Creator/editor/hero_editor/hero_editor.ui \
		2D-Game-Creator/editor/monster_editor/monster_editor.ui \
            	2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.ui \
    		2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.ui \
    		2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.ui \
    		2D-Game-Creator/simulation/kampfsimulation/kampfsimulation.ui \
    		2D-Game-Creator/editor/effekt_editor/effekt_editor.ui \
    		2D-Game-Creator/diverses/option.ui \
    		2D-Game-Creator/editor/ausruestungs_editor/ausruestung.ui \
    		2D-Game-Creator/editor/klassen_editor/klassen_editor.ui

RESOURCES += 	2D-Game-Creator/res/ress_con.qrc \

