NAME         = QtAitkBase
TARGET       = $${NAME}
QT           = core
QT          -= gui
QT          += network
QT          += sql
QT          += QtUUID

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}
HEADERS     += $${PWD}/qtaitkamacros.h
HEADERS     += $${PWD}/qtaitkanamespaces.h
HEADERS     += $${PWD}/qtaitkbase.h

SOURCES     += $${PWD}/qtaitkbase.cpp

include ($${PWD}/Decision/Decision.pri)
include ($${PWD}/Processes/Processes.pri)
include ($${PWD}/Strings/Strings.pri)
include ($${PWD}/UUID/UUID.pri)
