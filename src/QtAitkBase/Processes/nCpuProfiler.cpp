#include <essentials.h>

N::CPU::Profiler:: Profiler ( void                           )
                 : data     ( NULL                           )
                 , size     ( 0                              )
                 , index    ( 86400                          )
                 , date     ( QDate::currentDate         ( ) )
                 , time     ( QTime::currentTime         ( ) )
                 , Lastest  ( QDateTime::currentDateTime ( ) )
                 , Zero     ( QTime ( 0 , 0 , 0 , 0 )        )
{
  setValue ( "Period" , "Hourly" ) ;
  setValue ( "Flush"  , false    ) ;
  setValue ( "Record" , true     ) ;
}

N::CPU::Profiler::~Profiler (void)
{
}

int N::CPU::Profiler::sizeHint(void)
{
  return ( 86400 * 2 * sizeof(qint16) ) ;
}

bool N::CPU::Profiler::setData(QByteArray & d)
{
  int s = d . size ( )                 ;
  if ( s < sizeHint ( ) ) return false ;
  data = (qint16 *) d . data ( )       ;
  size =            d . size ( )       ;
  return true                          ;
}

bool N::CPU::Profiler::setData(void * d,int s)
{
  if ( s < sizeHint ( ) ) return false ;
  data = (qint16 *) d                  ;
  size =            s                  ;
  return true                          ;
}

QVariant N::CPU::Profiler::value(QString key)
{
  return variables [ key ] ;
}

QVariant N::CPU::Profiler::setValue(QString key,QVariant v)
{
  variables [ key ] = v    ;
  return variables [ key ] ;
}

int N::CPU::Profiler::addTrigger(Trigger * trigger)
{
  Triggers << trigger         ;
  return Triggers . count ( ) ;
}

void N::CPU::Profiler::RunTriggers(QDateTime & now,qint16 usage)
{
  int c = Triggers . count ( )                          ;
  if ( c <= 0 ) return                                  ;
  QList<Trigger *> Deletions                            ;
  ///////////////////////////////////////////////////////
  for (int i = 0 ; i < c ; i++ )                        {
    Trigger * t = Triggers [ i ]                        ;
    if ( NULL != t )                                    {
      if ( t -> variables [ "Deletion" ] . toBool ( ) ) {
        Deletions << t                                  ;
      } else                                            {
        t -> Fire ( now , usage )                       ;
      }                                                 ;
    }                                                   ;
  }                                                     ;
  ///////////////////////////////////////////////////////
  if ( Deletions . count ( ) <= 0 ) return              ;
  c = Deletions . count ( )                             ;
  for (int i=0;i<c;i++)                                 {
    Trigger * t = Deletions [ i ]                       ;
    if ( NULL != t )                                    {
      int p = Triggers . indexOf ( t )                  ;
      if ( p >= 0 ) Triggers . takeAt ( p )             ;
      if ( t -> variables [ "Destroy" ] . toBool ( ) )  {
        delete t                                        ;
      }                                                 ;
    }                                                   ;
  }                                                     ;
}

void N::CPU::Profiler::Empty(int pos)
{
  ::memset ( &data [ pos ] , 0 , sizeof(qint16) * 86400 ) ;
}

bool N::CPU::Profiler::Load(int pos,QString filename)
{
  QFile F ( filename )                                                 ;
  if ( ! F . exists ( ) ) return false                                 ;
  if ( ! F . open ( QIODevice::ReadOnly ) ) return false               ;
  qint64 r = F . read ( (char *) &data[pos] , sizeof(qint16) * 86400 ) ;
  F . close ( )                                                        ;
  return ( r == ( sizeof(qint16) * 86400 ) )                           ;
}

bool N::CPU::Profiler::Load(int pos)
{
  if ( ! variables . contains ( "Path" ) ) return false                      ;
  if ( ! variables . contains ( "Name" ) ) return false                      ;
  ////////////////////////////////////////////////////////////////////////////
  QString path = variables [ "Path" ] . toString ( )                         ;
  QString name = variables [ "Name" ] . toString ( )                         ;
  QDir    dir  = QDir ( path )                                               ;
  QString filename                                                           ;
  filename = QString("%1-%2.cpu").arg(name).arg(date.toString("yyyy-MM-dd")) ;
  filename = dir . absoluteFilePath ( filename )                             ;
  return Load ( pos , filename )                                             ;
}

bool N::CPU::Profiler::Save(int pos,QString filename)
{
  QFile F ( filename )                                                  ;
  if ( ! F . open ( QIODevice::WriteOnly ) ) return false               ;
  qint64 r = F . write ( (char *) &data[pos] , sizeof(qint16) * 86400 ) ;
  F . close ( )                                                         ;
  return ( r == ( sizeof(qint16) * 86400 ) )                            ;
}

bool N::CPU::Profiler::Save(int pos)
{
  if ( ! variables . contains ( "Path" ) ) return false                      ;
  if ( ! variables . contains ( "Name" ) ) return false                      ;
  ////////////////////////////////////////////////////////////////////////////
  QString path = variables [ "Path" ] . toString ( )                         ;
  QString name = variables [ "Name" ] . toString ( )                         ;
  QDir    dir  = QDir ( path )                                               ;
  QString filename                                                           ;
  filename = QString("%1-%2.cpu").arg(name).arg(date.toString("yyyy-MM-dd")) ;
  filename = dir . absoluteFilePath ( filename )                             ;
  dir      . mkpath ( path )                                                 ;
  return Save ( pos , filename )                                             ;
}

void N::CPU::Profiler::addComsumption(QDateTime & now,qint16 usage)
{
  if ( NULL == data ) return            ;
  QDate d = now . date ( )              ;
  QTime t = now . time ( )              ;
  if ( d != date )                      {
    if ( index >= 86400 )               {
      Empty ( 0     )                   ;
      index = 0                         ;
    } else                              {
      Empty ( 86400 )                   ;
      index = 86400                     ;
    }                                   ;
  }                                     ;
  ///////////////////////////////////////
  QDateTime B ( d , Zero )              ;
  int offset = B . secsTo ( now )       ;
  if ( offset >= 0     )                {
    if ( offset <  86400 )              {
      offset         += index           ;
      data [ offset ] = usage           ;
    }                                   ;
  }                                     ;
  ///////////////////////////////////////
  date = d                              ;
  time = t                              ;
}

void N::CPU::Profiler::setComsumption(qint16 usage)
{
  QDateTime now = nTimeNow                            ;
  bool      r   = variables [ "Record" ] . toBool ( ) ;
  if ( r ) addComsumption ( now , usage )             ;
  RunTriggers             ( now , usage )             ;
}

bool N::CPU::Profiler::isTimeUp(void)
{
  QString   period = variables [ "Period" ] . toString ( ) ;
  QDateTime now    = nTimeNow                              ;
  //////////////////////////////////////////////////////////
  period = period . toLower ( )                            ;
  if ( "hourly" == period )                                {
    QDate d = now     . date ( )                           ;
    QDate D = Lastest . date ( )                           ;
    if ( d != D ) return true                              ;
    QTime t = now     . time ( )                           ;
    QTime T = Lastest . time ( )                           ;
    return ( t . hour ( ) != T . hour ( ) )                ;
  } else
  if ( "daily"  == period )                                {
    QDate d = now     . date ( )                           ;
    QDate D = Lastest . date ( )                           ;
    return ( d != D )                                      ;
  }                                                        ;
  return false                                             ;
}

void N::CPU::Profiler::Flush(void)
{
  if ( ! variables [ "Flush" ] . toBool ( ) ) return ;
  QMutexLocker locker ( & Writing )                  ;
  if ( isTimeUp ( ) )                                {
    QDateTime now = nTimeNow                         ;
    QDate     d   = now     . date ( )               ;
    QDate     D   = Lastest . date ( )               ;
    int       pos = index                            ;
    if ( d != D )                                    {
      if ( pos <= 0 ) pos = 86400                    ;
                 else pos = 0                        ;
    }                                                ;
    if ( Save  ( pos ) ) Lastest = now               ;
  }                                                  ;
}

void N::CPU::Profiler::Store(void)
{
  Save ( index ) ;
}
