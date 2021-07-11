#include <essentials.h>

N::Process:: Process  (QObject * parent)
           : QProcess (          parent)
{
}

N::Process:: Process(void)
{
}

N::Process::~Process(void)
{
}

int N::Process::system(const char * command)
{
  return ::system(command);
}

#ifndef Q_OS_WIN

pid_t N::Process::fork(void)
{
  return ::fork();
}

#endif
