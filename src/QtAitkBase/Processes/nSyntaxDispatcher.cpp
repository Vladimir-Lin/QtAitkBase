#include <essentials.h>

N::SyntaxDispatcher:: SyntaxDispatcher(void)
                    : History         (NULL)
{
}

N::SyntaxDispatcher::~SyntaxDispatcher(void)
{
}

void N::SyntaxDispatcher::setHistory(QByteArray * history)
{
  History = history ;
}

void N::SyntaxDispatcher::Report(QString message)
{
  if ( NULL == History           ) return ;
  if ( message . length ( ) <= 0 ) return ;
  QByteArray U = message . toUtf8 ( )     ;
  History -> append ( U )                 ;
}
