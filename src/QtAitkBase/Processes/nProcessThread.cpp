#include <essentials.h>

N::ProcessThread:: ProcessThread (QObject * parent)
                 : QThread       (          parent)
{
  working = false                                                   ;
  process = new N::Process(this)                                    ;
  #define PCONNECT(func)                                            \
    QObject::connect(process,SIGNAL(func),this,SLOT(func))          ;
  PCONNECT ( error                   ( QProcess::ProcessError   ) ) ;
  PCONNECT ( finished                ( int,QProcess::ExitStatus ) ) ;
  PCONNECT ( readyReadStandardError  (                          ) ) ;
  PCONNECT ( readyReadStandardOutput (                          ) ) ;
  PCONNECT ( started                 (                          ) ) ;
  PCONNECT ( stateChanged            ( QProcess::ProcessState   ) ) ;
  #undef  PCONNECT
}

N::ProcessThread::~ProcessThread (void)
{
}

bool N::ProcessThread::Start(void)
{
  nKickOut ( working , false ) ;
  start    (                 ) ;
  return true                  ;
}

bool N::ProcessThread::Stop(void)
{
  working = false ;
  return true     ;
}

int N::ProcessThread::Write(QByteArray commands)
{
  int rt = (int)process->write(commands) ;
  process->waitForBytesWritten(        ) ;
  return rt                              ;
}

int N::ProcessThread::Write(QString commands)
{
  return Write(commands.toUtf8());
}

void N::ProcessThread::error(QProcess::ProcessError error)
{
  Q_UNUSED(error) ;
}

void N::ProcessThread::finished(int exitCode,QProcess::ExitStatus exitStatus)
{
  Q_UNUSED ( exitCode   ) ;
  Q_UNUSED ( exitStatus ) ;
  working = false         ;
}

void N::ProcessThread::readyReadStandardError(void)
{
  QByteArray ERR = process->readAllStandardError() ;
  emit STDERR ( ERR )                              ;
}

void N::ProcessThread::readyReadStandardOutput(void)
{
  QByteArray OUTPUT = process->readAllStandardOutput() ;
  emit STDOUT ( OUTPUT )                               ;
}

void N::ProcessThread::started(void)
{
}

void N::ProcessThread::stateChanged(QProcess::ProcessState newState)
{
  Q_UNUSED ( newState ) ;
}

void N::ProcessThread::run(void)
{
  nDropOut ( working )                ;
  working = true                      ;
  process->start(Program,Arguments)   ;
  if (!process->waitForStarted(5000)) {
    working = false                   ;
    return                            ;
  }                                   ;
  while (working)                     {
    usleep(10000)                     ;
  }                                   ;
  process->close()                    ;
}
