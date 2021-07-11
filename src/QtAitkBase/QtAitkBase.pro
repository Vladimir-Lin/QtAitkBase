NAME         = QtAitkBase
TARGET       = $${NAME}
QT           = core
QT          -= gui

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}
HEADERS     += $${PWD}/qtaitkbase.h

SOURCES     += $${PWD}/qtaitkbase.cpp
