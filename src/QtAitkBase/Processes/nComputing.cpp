#include <essentials.h>

N::Computing:: Computing              ( void )
             : QtParallel::Dispatcher (      )
             , Thread                 (      )
{
  join ( new QtParallel::FileMethod ( "File" , this ) ) ;
}

N::Computing::~Computing (void)
{
  bool forceDrop = false           ;
  if ( NULL == Data . Controller ) {
    Data . Controller = &forceDrop ;
  }                                ;
  WaitThreads ( )                  ;
  Data . Controller = NULL         ;
}

void N::Computing::setHost(QString host,int p)
{
  setPort ( p ) ;
}

bool N::Computing::Cancellation(void)
{
  if ( NULL != Data . Controller )                  {
    if ( ! ( *( Data . Controller ) ) ) return true ;
  }                                                 ;
  return false                                      ;
}

QtParallel::Server * N::Computing::NewServer(void)
{
  QtParallel::Server * s                       ;
  s               = new QtParallel::Server ( ) ;
  s -> Controller = Data . Controller          ;
  return s                                     ;
}

bool N::Computing::NotifyNeighbor(QString myself,QString neighbor)
{
  QString P = QString ( "Probe[%1]"  ) . arg ( neighbor ) ;
  if ( Information . contains ( P ) )                     {
    if ( Information [ P ] . toBool ( ) ) return true     ;
  }                                                       ;
  /////////////////////////////////////////////////////////
  VarArgs args                                            ;
  args << myself                                          ;
  args << neighbor                                        ;
  args << 737                                             ;
  start ( TalkToNeighbor , args )                         ;
  /////////////////////////////////////////////////////////
  return true                                             ;
}

void N::Computing::TalkNeighbor(ThreadData * d)
{
  if ( d -> Arguments . count ( ) < 2 ) return           ;
  QString myself   = d -> Arguments [ 0 ] . toString ( ) ;
  QString neighbor = d -> Arguments [ 1 ] . toString ( ) ;
  Notify ( myself , neighbor , d -> Arguments )          ;
}

bool N::Computing::StartServer(SUID u)
{
  VarArgs args                   ;
  args << u                      ;
  start ( StartServerID , args ) ;
  return true                    ;
}

void N::Computing::LaunchServer(ThreadData * d)
{
  if ( d -> Arguments . count ( ) < 1 ) return    ;
  SUID u = d -> Arguments [ 0 ] . toULongLong ( ) ;
  RunServer ( u )                                 ;
}

void N::Computing::RunClient(SUID u)
{
  VarArgs args                     ;
  args << u                        ;
  start ( ExecuteClientID , args ) ;
}

void N::Computing::LaunchClient(ThreadData * d)
{
  if ( d -> Arguments . count ( ) < 1 ) return    ;
  SUID u = d -> Arguments [ 0 ] . toULongLong ( ) ;
  if ( u <= 0 ) return                            ;
  ExecuteClient ( u )                             ;
}

bool N::Computing::Prepare(bool existance)
{
  if ( tcpPort <= 0 ) return false                                           ;
  if ( udpPort <= 0 ) return false                                           ;
  if ( existance    )                                                        {
    if ( exists ( ) ) return false                                           ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  bool hasMyself = false                                                     ;
  for (int i = 0 ; ( ! hasMyself ) && ( i < companions . count ( ) ) ; i++ ) {
    if ( companions [ i ] -> isSelf ( ) ) hasMyself = true                   ;
  }                                                                          ;
  if ( ! hasMyself )                                                         {
    QtParallel::Companion  * self = new QtParallel::Companion  ( true  )     ;
    self -> setPort ( tcpPort )                                              ;
    Join            ( self    )                                              ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  start ( DetectUdpID   )                                                    ;
  start ( ProbeUdpID    )                                                    ;
  start ( CompanionID   )                                                    ;
  start ( AcceptMethods )                                                    ;
  ////////////////////////////////////////////////////////////////////////////
  return true                                                                ;
}

void N::Computing::run(int T,ThreadData * d)
{
  nDropOut   ( ! IsContinue ( d ) ) ;
  ItemRunner ( T , d              ) ;
}

bool N::Computing::ItemRunner(int T,ThreadData * d)
{
  switch ( T )              {
    case DetectUdpID        :
      DetectByUdp     (   ) ;
    return true             ;
    case ProbeUdpID         :
      ProbeByUdp      (   ) ;
    return true             ;
    case CompanionID        :
      WatchCompanions (   ) ;
    return true             ;
    case AcceptMethods      :
      RunListener     (   ) ;
    return true             ;
    case StartServerID      :
      LaunchServer    ( d ) ;
    return true             ;
    case TalkToNeighbor     :
      TalkNeighbor    ( d ) ;
    return true             ;
    case ExecuteClientID    :
      LaunchClient    ( d ) ;
    return true             ;
  }                         ;
  return false              ;
}
