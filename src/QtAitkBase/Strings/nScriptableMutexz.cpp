#include <essentials.h>

#ifndef QT_STATIC

N::ScriptableMutex:: ScriptableMutex ( QObject * parent )
                   : QObject         (           parent )
                   , QScriptable     (                  )
                   , Mutexz          (                  )
{
}

N::ScriptableMutex::~ScriptableMutex (void)
{
}

void N::ScriptableMutex::lock(int index)
{
  ME [ index ] . lock ( ) ;
}

void N::ScriptableMutex::lock(qint64 index)
{
  ME [ index ] . lock ( ) ;
}

void N::ScriptableMutex::lock(QString key)
{
  ME [ key ] . lock ( ) ;
}

void N::ScriptableMutex::unlock(int index)
{
  ME [ index ] . unlock ( ) ;
}

void N::ScriptableMutex::unlock(qint64 index)
{
  ME [ index ] . unlock ( ) ;
}

void N::ScriptableMutex::unlock(QString key)
{
  ME [ key ] . unlock ( ) ;
}

QScriptValue N::MutexAttachment(QScriptContext * context,QScriptEngine * engine)
{
  Q_UNUSED ( context )                                           ;
  N::ScriptableMutex * mutex = new N::ScriptableMutex ( engine ) ;
  return engine -> newQObject ( mutex )                          ;
}

#endif
