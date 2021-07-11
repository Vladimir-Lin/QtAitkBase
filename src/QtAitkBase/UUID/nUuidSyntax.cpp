#include <essentials.h>

N::UuidSyntax:: UuidSyntax (void)
{
}

N::UuidSyntax::~UuidSyntax (void)
{
}

bool N::UuidSyntax::compare(int count,QStringList & args,char * patterns[])
{
  if ( args . count ( ) < count ) return false       ;
  for (int i=0;i<count;i++)                          {
    QString w = QString::fromUtf8 ( patterns [ i ] ) ;
    QString l = args [ i ] . toLower ( )             ;
    w = w . toLower ( )                              ;
    if ( w != l ) return false                       ;
  }                                                  ;
  return true                                        ;
}

QStringList N::UuidSyntax::Syntax(QString cmd)
{
  QStringList s                  ;
  QString     token              ;
  int         t                  ;
  int         i = 0              ;
  int         e = 0              ;
  t = cmd . length ( )           ;
  while ( i < t )                {
    QChar c = cmd . at ( i )     ;
    switch ( e )                 {
      case 0                     :
        if ( QChar('(') == c )   {
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
          s << "("               ;
        } else
        if ( QChar(')') == c )   {
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
          s << ")"               ;
        } else
        if ( QChar('+') == c )   {
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
          s << "+"               ;
        } else
        if ( QChar('-') == c )   {
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
          s << "-"               ;
        } else
        if ( QChar('&') == c )   {
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
          s << "&"               ;
        } else
        if ( QChar(' ') == c )   {
          e = 1                  ;
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
        } else
        if ( QChar('"') == c )   {
          e = 2                  ;
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
        } else                   {
          token . append ( c )   ;
        }                        ;
        i++                      ;
      break                      ;
      case 1                     :
        if ( QChar(' ') == c )   {
          i++                    ;
        } else
        if ( QChar('"') == c )   {
          e = 2                  ;
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
          i++                    ;
        } else                   {
          e = 0                  ;
        }                        ;
      break                      ;
      case 2                     :
        if ( QChar('"') == c )   {
          e = 0                  ;
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
        } else                   {
          token . append ( c )   ;
        }                        ;
        i++                      ;
      break                      ;
    }                            ;
  }                              ;
  if (token.length()>0)          {
    s << token                   ;
  }                              ;
  return s                       ;
}

bool N::UuidSyntax::isOperator(QString o)
{
  if ( "+" == o ) return true ;
  if ( "-" == o ) return true ;
  if ( "&" == o ) return true ;
  return false                ;
}

void N::UuidSyntax::addKey(QStringList & keys,QString k)
{
  if ( ! keys . contains ( k ) ) {
    keys << k                    ;
  }                              ;
}

bool N::UuidSyntax::Bracket(int & left,int & right,QStringList & s,QStringList & keys)
{
  int e = s . count ( )                                  ;
  if ( "(" != s [ left ] )                               {
    if ( ( e - right ) < 3                ) return false ;
    addKey ( keys , s [ right ] )                        ;
    right++                                              ;
    if ( right >= e                       ) return false ;
    if ( ! isOperator ( s [ right ] )     ) return false ;
    right++                                              ;
    if ( right >= e                       ) return false ;
    if ( "(" != s [ right ] )                            {
      addKey ( keys , s [ right ] )                      ;
      return true                                        ;
    }                                                    ;
    int L = right                                        ;
    int R = right                                        ;
    if ( ! Bracket ( L , R , s , keys )   ) return false ;
    right = R                                            ;
  } else                                                 { // Check ( ...
    if ( ( e - right ) < 5                ) return false ;
    right++                                              ;
    if ( right >= e                       ) return false ;
    if ( "(" == s [ right ] )                            { // Check ( ( ...
      int L = right                                      ;
      int R = right                                      ;
      if ( ! Bracket ( L , R , s , keys ) ) return false ;
      right = R                                          ;
    } else                                               {
      addKey ( keys , s [ right ] )                      ;
    }                                                    ;
    //////////////////////////////////////////////////////
    right++                                              ;
    if ( right >= e                       ) return false ;
    if ( ! isOperator ( s [ right ] )     ) return false ; // Check operator
    right++                                              ;
    if ( right >= e                       ) return false ;
    //////////////////////////////////////////////////////
    if ( "(" == s [ right ] )                            { // Check part B
      int L = right                                      ;
      int R = right                                      ;
      if ( ! Bracket ( L , R , s , keys ) ) return false ;
      right = R                                          ;
    } else                                               {
      addKey ( keys , s [ right ] )                      ;
    }                                                    ;
    //////////////////////////////////////////////////////
    right++                                              ;
    if ( right >= e                       ) return false ;
    if ( ")" != s [ right ]               ) return false ;
  }                                                      ;
  ////////////////////////////////////////////////////////
  return true                                            ;
}

bool N::UuidSyntax::isSyntax(int & left,int & right,QStringList s,QStringList & keys)
{
  if ( s . count ( ) <= 0 ) return false     ;
  if ( s . count ( ) == 1 )                  {
    keys << s [ 0 ]                          ;
    return true                              ;
  }                                          ;
  ////////////////////////////////////////////
  return Bracket ( left , right , s , keys ) ;
}

bool N::UuidSyntax::Operate(UUIDs & U,QString o,UUIDs & A,UUIDs & B)
{
  if ( "+" == o ) {
    U = A + B     ;
    return true   ;
  }               ;
  if ( "-" == o ) {
    U = A - B     ;
    return true   ;
  }               ;
  if ( "&" == o ) {
    U = A & B     ;
    return true   ;
  }               ;
  return false    ;
}

bool N::UuidSyntax::Bracket(UUIDs & U,int & left,int & right,QStringList & s,QMap<QString,UUIDs> & UM)
{
  UUIDs   A                                                ;
  UUIDs   B                                                ;
  QString o                                                ;
  int     e = s . count ( )                                ;
  if ( "(" != s [ left ] )                                 {
    if ( ( e - right ) < 3                  ) return false ;
    A = UM [ s [ right ] ]                                 ;
    right++                                                ;
    if ( right >= e                         ) return false ;
    if ( ! isOperator ( s [ right ] )       ) return false ;
    o = s [ right ]                                        ;
    right++                                                ;
    if ( right >= e                         ) return false ;
    if ( "(" != s [ right ] )                              {
      B = UM [ s [ right ] ]                               ;
      return Operate ( U , o , A , B )                     ;
    }                                                      ;
    int L = right                                          ;
    int R = right                                          ;
    if ( ! Bracket ( B , L , R , s , UM )   ) return false ;
    right = R                                              ;
  } else                                                   { // Check ( ...
    if ( ( e - right ) < 5                  ) return false ;
    right++                                                ;
    if ( right >= e                         ) return false ;
    if ( "(" == s [ right ] )                              { // Check ( ( ...
      int L = right                                        ;
      int R = right                                        ;
      if ( ! Bracket ( A , L , R , s , UM ) ) return false ;
      right = R                                            ;
    } else                                                 {
      A = UM [ s [ right ] ]                               ;
    }                                                      ;
    ////////////////////////////////////////////////////////
    right++                                                ;
    if ( right >= e                         ) return false ;
    if ( ! isOperator ( s [ right ] )       ) return false ; // Check operator
    o = s [ right ]                                        ;
    right++                                                ;
    if ( right >= e                         ) return false ;
    ////////////////////////////////////////////////////////
    if ( "(" == s [ right ] )                              { // Check part B
      int L = right                                        ;
      int R = right                                        ;
      if ( ! Bracket ( B , L , R , s , UM ) ) return false ;
      right = R                                            ;
    } else                                                 {
      B = UM [ s [ right ] ]                               ;
    }                                                      ;
    ////////////////////////////////////////////////////////
    right++                                                ;
    if ( right >= e                         ) return false ;
    if ( ")" != s [ right ]                 ) return false ;
  }                                                        ;
  //////////////////////////////////////////////////////////
  return Operate ( U , o , A , B )                         ;
}

bool N::UuidSyntax::Operate(UUIDs & U,QStringList s,QMap<QString,UUIDs> & UM)
{
  if ( s . count ( ) <= 0 ) return false       ;
  if ( s . count ( ) == 1 )                    {
    QString k = s [ 0 ]                        ;
    if ( ! UM . contains ( k ) ) return false  ;
    U = UM [ k ]                               ;
    return true                                ;
  }                                            ;
  //////////////////////////////////////////////
  int left  = 0                                ;
  int right = 0                                ;
  //////////////////////////////////////////////
  return Bracket ( U , left , right , s , UM ) ;
}

bool N::UuidSyntax::NamesOwners(SqlConnection & SC,QString Table,UUIDs & U,UUIDs & P)
{
  QString Q                                     ;
  SUID    u                                     ;
  foreach ( u , U )                             {
    Q = SC . sql . SelectFrom                   (
          "uuid"                                ,
          Table                                 ,
          QString("where `name` = %1").arg(u) ) ;
    SqlLoopNow ( SC , Q )                       ;
      SUID x = SC . Uuid ( 0 )                  ;
      if ( ! P . contains ( x ) ) P << x        ;
    SqlLoopErr ( SC , Q )                       ;
    SqlLoopEnd ( SC , Q )                       ;
  }                                             ;
  return ( P . count ( ) > 0  )                 ;
}

bool N::UuidSyntax::FilterType(SqlConnection & SC,QString Table,int Type,UUIDs & U,UUIDs & P)
{
  QString Q                       ;
  SUID    u                       ;
  foreach ( u , U )               {
    Q = SC . sql . SelectFrom     (
          "type"                  ,
          Table                   ,
          SC . WhereUuid ( u )  ) ;
    if ( SC . Fetch ( Q ) )       {
      int T = SC . Int ( 0 )      ;
      if ( T ==Type )             {
        if ( ! P . contains (u) ) {
          P << u                  ;
        }                         ;
      }                           ;
    }                             ;
  }                               ;
  return ( P . count ( ) > 0  )   ;
}

bool N::UuidSyntax::FetchEqual(SqlConnection & SC,QString Table,UUIDs & U,QString K)
{
  QString Q                                                              ;
  SUID    u                                                              ;
  ////////////////////////////////////////////////////////////////////////
  Q = QString("select `uuid` from %1 where `name` = :NAME ;").arg(Table) ;
  SC . Prepare ( Q                       )                               ;
  SC . Bind    ( "name" , K . toUtf8 ( ) )                               ;
  if ( SC . Exec ( ) ) while ( SC . Next ( ) )                           {
    u = SC . Uuid ( 0 )                                                  ;
    if ( ! U . contains ( u ) ) U << u                                   ;
  }                                                                      ;
  ////////////////////////////////////////////////////////////////////////
  return ( U . count ( ) > 0 )                                           ;
}

bool N::UuidSyntax::FetchLike(SqlConnection & SC,QString Table,UUIDs & U,QString K)
{
  QString Q                                                      ;
  QString W                                                      ;
  SUID    u                                                      ;
  ////////////////////////////////////////////////////////////////
  W = QString("where `name` like '%1' order by `id` asc").arg(K) ;
  Q = QString("select `uuid` from %1 %2 ;").arg(Table).arg(W)    ;
  SqlLoopNow ( SC , Q )                                          ;
    u = SC . Uuid ( 0 )                                          ;
    if ( ! U . contains ( u ) ) U << u                           ;
  SqlLoopErr ( SC , Q )                                          ;
  SqlLoopEnd ( SC , Q )                                          ;
  ////////////////////////////////////////////////////////////////
  return ( U . count ( ) > 0 )                                   ;
}

bool N::UuidSyntax::FetchRegexp(SqlConnection & SC,QString Table,UUIDs & U,QString K)
{
  QString Q                                                        ;
  QString W                                                        ;
  SUID    u                                                        ;
  //////////////////////////////////////////////////////////////////
  W = QString("where `name` regexp '%1' order by `id` asc").arg(K) ;
  Q = QString("select `uuid` from %1 %2 ;").arg(Table).arg(W)      ;
  SqlLoopNow ( SC , Q )                                            ;
    u = SC . Uuid ( 0 )                                            ;
    if ( ! U . contains ( u ) ) U << u                             ;
  SqlLoopErr ( SC , Q )                                            ;
  SqlLoopEnd ( SC , Q )                                            ;
  //////////////////////////////////////////////////////////////////
  return ( U . count ( ) > 0 )                                     ;
}
