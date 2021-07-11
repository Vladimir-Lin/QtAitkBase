#include <essentials.h>

N::Mutexz:: Mutexz   ( void  )
          : spinLock ( false )
{
}

N::Mutexz:: Mutexz   (const Mutexz & mutexz)
          : spinLock ( false               )
{
  mutex = mutexz . mutex ;
  sutex = mutexz . sutex ;
}

N::Mutexz::~Mutexz(void)
{
  spinLock        = false                  ;
  TUIDs       IDs = mutex . keys ( )       ;
  QStringList SDs = sutex . keys ( )       ;
  TUID        id                           ;
  QString     sd                           ;
  foreach ( id , IDs ) delete mutex [ id ] ;
  foreach ( sd , SDs ) delete sutex [ sd ] ;
  mutex . clear ( )                        ;
  sutex . clear ( )                        ;
}

void N::Mutexz::SpinLock(void)
{
  while ( spinLock ) {
    Time::skip ( 1 ) ;
  }                  ;
}

QMutex & N::Mutexz::operator [ ] (int index)
{
  SpinLock ( )                                 ;
  spinLock = true                              ;
  if ( ! mutex . contains ( (qint64) index ) ) {
    mutex [ (qint64) index ] = new QMutex ( )  ;
  }                                            ;
  spinLock = false                             ;
  return * ( mutex [ (qint64) index ] )        ;
}

QMutex & N::Mutexz::operator [ ] (qint64 index)
{
  SpinLock ( )                        ;
  spinLock = true                     ;
  if ( ! mutex . contains ( index ) ) {
    mutex [ index ] = new QMutex ( )  ;
  }                                   ;
  spinLock = false                    ;
  return * ( mutex [ index ] )        ;
}

QMutex & N::Mutexz::operator [ ] (QString key)
{
  SpinLock ( )                      ;
  spinLock = true                   ;
  if ( ! sutex . contains ( key ) ) {
    sutex [ key ] = new QMutex ( )  ;
  }                                 ;
  spinLock = false                  ;
  return * ( sutex [ key ] )        ;
}
