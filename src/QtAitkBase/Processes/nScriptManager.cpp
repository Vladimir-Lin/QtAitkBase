#include <essentials.h>

#ifndef QT_STATIC

N::ScriptManager:: ScriptManager (void)
{
}

N::ScriptManager:: ScriptManager (const ScriptManager & manager)
{
  Creators = manager . Creators ;
}

N::ScriptManager::~ScriptManager (void)
{
}

int N::ScriptManager::AttachCreators (QScriptEngine & engine)
{
  QStringList K = Creators . keys ( )                                     ;
  QString     S                                                           ;
  if ( K . count ( ) <= 0 ) return 0                                      ;
  QScriptValue global                                                     ;
  global = engine . globalObject ( )                                      ;
  foreach ( S , K )                                                       {
    global . setProperty ( S  , engine . newFunction ( Creators [ S ] ) ) ;
  }                                                                       ;
  return K . count ( )                                                    ;
}

N::ScriptManager & N::ScriptManager::operator = (const ScriptManager & manager)
{
  Creators = manager . Creators ;
  return ME                     ;
}

QScriptValue N::ExecuteJs(QString script,QString entry,ScriptManager & manager)
{
  QScriptEngine    Engine                                 ;
  QScriptValue     func                                   ;
  QScriptValue     global                                 ;
  QScriptValue     callx                                  ;
  QScriptValue     again                                  ;
  QScriptValue     source                                 ;
  QScriptValueList args                                   ;
  /////////////////////////////////////////////////////////
  manager . AttachCreators        ( Engine              ) ;
  func    = Engine . evaluate     ( script              ) ;
  source  = QScriptValue          ( script              ) ;
  global  = Engine . globalObject (                     ) ;
  global  . setProperty           ( "Original" , source ) ;
  callx   = global . property     ( entry               ) ;
  /////////////////////////////////////////////////////////
  if ( callx . isFunction ( ) )                           {
    again = callx . call ( func , args  )                 ;
    return again                                          ;
  } else                                                  {
    return QScriptValue ( false )                         ;
  }                                                       ;
  /////////////////////////////////////////////////////////
  return QScriptValue ( true )                            ;
}

#endif
