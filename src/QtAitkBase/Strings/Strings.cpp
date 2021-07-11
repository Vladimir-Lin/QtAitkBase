#include <essentials.h>

void RegisterEssentials(void)
{
  RegisterUUIDs        ( ) ;
  RegisterZMQ          ( ) ;
  RegisterTransformers ( ) ;
  RegisterParallels    ( ) ;
  RegisterCompressors  ( ) ;
  RegisterArchivers    ( ) ;
}

typedef struct         {
  N::VarArgs arguments ;
} HiddenArguments      ;

typedef struct      {
  void * pointer    ;
} VoidStructureData ;

QVariant VoidVariant(void * pointer)
{
  QByteArray B ( sizeof(VoidStructureData) , 0 )            ;
  VoidStructureData * p = (VoidStructureData *)B . data ( ) ;
  p -> pointer = pointer                                    ;
  return QVariant(B)                                        ;
}

void * VariantToVoid(QVariant v)
{
  QByteArray B = v . toByteArray ( )                        ;
  VoidStructureData * p = (VoidStructureData *)B . data ( ) ;
  if ( IsNull ( p ) ) return NULL                           ;
  return p -> pointer                                       ;
}

QVariant ArgsToVariant (N::VarArgs & args)
{
  HiddenArguments * ha = new HiddenArguments ( )            ;
  ha -> arguments = args                                    ;
  QByteArray B ( sizeof(VoidStructureData) , 0 )            ;
  VoidStructureData * p = (VoidStructureData *)B . data ( ) ;
  p -> pointer = ha                                         ;
  return QVariant(B)                                        ;
}

N::VarArgs VariantToArgs(QVariant v)
{
  N::VarArgs args                                           ;
  QByteArray B = v . toByteArray ( )                        ;
  VoidStructureData * p = (VoidStructureData *)B . data ( ) ;
  if ( IsNull ( p  ) ) return args                          ;
  HiddenArguments * ha = (HiddenArguments *) p -> pointer   ;
  if ( IsNull ( ha ) ) return args                          ;
  args = ha -> arguments                                    ;
  delete ha                                                 ;
  return args                                               ;
}

char * operator <= (char * string,QByteArray & blob)
{
  string = blob . data ( ) ;
  return string            ;
}

char * operator <= (char * string,QString qs)
{
  char * s = qs.toUtf8().data() ;
  if (IsNull(s)) return string  ;
  ::strcpy ( string , s )       ;
  return string                 ;
}

QString N::Reverse(QString str)
{
  int len = str.length()      ;
  nKickOut ( len <= 0 , "" )  ;
  QString r                   ;
  int j = len - 1             ;
  for (int i=0;i<len;i++,j--) {
    r . append ( str.at(j) )  ;
  }                           ;
  return r                    ;
}

void N::printf(QString message,bool lf,bool cr)
{
  QTextCodec * codec = QTextCodec::codecForLocale() ;
  QByteArray   M     = codec->fromUnicode(message)  ;
  int          L     = M . size ( )                 ;
  ///////////////////////////////////////////////////
  if ( L <= 0 )                                     {
    if (lf || cr)                                   {
      char f [ 64 ]                                 ;
      ::strcpy         ( f    , ""    )             ;
      if (cr) ::strcat ( f    , "\r"  )             ;
      if (lf) ::strcat ( f    , "\n"  )             ;
      #if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
      qDebug           ( f            )             ;
      #else
      ::printf         ( "%s" , f     )             ;
      #endif
    }                                               ;
    return                                          ;
  }                                                 ;
  ///////////////////////////////////////////////////
  char * p = new char[L+16]                         ;
  memset   ( p , 0        , L+16 )                  ;
  memcpy   ( p , M.data() , L    )                  ;
  if (lf || cr)                                     {
    char f [ 64 ]                                   ;
    ::strcpy         ( f , ""      )                ;
    if (cr) ::strcat ( f , "\r"    )                ;
    if (lf) ::strcat ( f , "\n"    )                ;
    ::strcat         ( p , f       )                ;
  }                                                 ;
  #if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
  qDebug             ( p           )                ;
  #else
  ::printf           ( "%s" , p    )                ;
  #endif
  delete [] p                                       ;
}

QStringList N::SplitQuotes(QString command)
{
  QStringList s                  ;
  QString     token              ;
  int         t                  ;
  int         i = 0              ;
  int         h = 0              ;
  int         e = 0              ;
  t = command . length ( )       ;
  while ( i < t )                {
    QChar c = command . at ( i ) ;
    switch ( e )                 {
      case 0                     :
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
      break                      ;
      case 1                     :
        if ( QChar(' ') == c )   {
        } else
        if ( QChar('"') == c )   {
          e = 2                  ;
          if (token.length()>0)  {
            s << token           ;
            token . clear ( )    ;
          }                      ;
        } else                   {
          e = 0                  ;
          token . append ( c )   ;
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
      break                      ;
    }                            ;
    i++                          ;
  }                              ;
  if (token.length()>0)          {
    s << token                   ;
  }                              ;
  return s                       ;
}

QStringList N::CommandTokens(QString command)
{
  if ( command.contains('"') )        {
    return N::SplitQuotes ( command ) ;
  }                                   ;
  /////////////////////////////////////
  QString c = command                 ;
  c = c . replace ( "\r" , "" )       ;
  c = c . replace ( "\n" , "" )       ;
  /////////////////////////////////////
  QStringList s = c.split(" ")        ;
  return s                            ;
}

QStringList toStrings(CUIDs & I)
{
  QStringList S             ;
  int         i             ;
  foreach (i,I)             {
    S << QString::number(i) ;
  }                         ;
  return S                  ;
}

QStringList operator - (QStringList & A,QStringList & B)
{
  QString     S         ;
  QStringList R         ;
  foreach (S,A)         {
    if (!B.contains(S)) {
      R << S            ;
    }                   ;
  }                     ;
  return R              ;
}

typedef struct      {
  SUID    u         ;
  QString s         ;
} PrivateStringTwin ;

static bool PrivateStringTwinLessThan      (
              const PrivateStringTwin & s1 ,
              const PrivateStringTwin & s2 )
{
  int r = QString :: compare ( s1.s , s2.s ) ;
  return ( r < 0 )                           ;
}

bool SortedUuids(NAMEs & names,UUIDs & uuids)
{
  if (names.count()<=0) return false ;
  UUIDs U = names . keys ( )         ;
  SUID  u                            ;
  int   t = U.count()                ;
  ////////////////////////////////////
  if (t<2)                           {
    uuids << U                       ;
    return true                      ;
  }                                  ;
  ////////////////////////////////////
  QList<PrivateStringTwin> PST       ;
  foreach (u,U)                      {
    PrivateStringTwin p              ;
    p.u = u                          ;
    p.s = names [ u ]                ;
    PST << p                         ;
  }                                  ;
  ////////////////////////////////////
  qStableSort                        (
    PST . begin ( )                  ,
    PST . end   ( )                  ,
    PrivateStringTwinLessThan      ) ;
  ////////////////////////////////////
  for (int i=0;i<t;i++)              {
    uuids << PST[i].u                ;
  }                                  ;
  ////////////////////////////////////
  return true                        ;
}

bool toStrings(NAMEs & names,UUIDs & uuids,QStringList & strings)
{
  if (names.count()<=0)      {
    return false             ;
  }                          ;
  SUID  u                    ;
  foreach (u,uuids)          {
    if (names.contains(u))   {
      strings << names [ u ] ;
    }                        ;
  }                          ;
  return true                ;
}

N::VarArgs & operator << (N::VarArgs & args,QStringList & strings)
{
  QString n               ;
  foreach ( n , strings ) {
    args << n             ;
  }                       ;
  return args             ;
}

QStringList & operator << (QStringList & strings,N::VarArgs & args)
{
  int t = args . count ( )               ;
  if ( t <= 0 ) return strings           ;
  for (int i=0;i<t;i++)                  {
    strings << args [ i ] . toString ( ) ;
  }                                      ;
  return strings                         ;
}

QStringList & operator <= ( QStringList & s , QVariants & v )
{
  int total = v . count ( )          ;
  if ( total <= 0 ) return s         ;
  for (int i = 0 ; i < total ; i++ ) {
    s << v [ i ] . toString ( )      ;
  }                                  ;
  return s                           ;
}

QVariants & operator <= ( QVariants & v , QStringList & s )
{
  int total = s . count ( )          ;
  if ( total <= 0 ) return v         ;
  for (int i = 0 ; i < total ; i++ ) {
    v << s [ i ]                     ;
  }                                  ;
  return v                           ;
}

bool CopyToArray(char * buffer,int length,QString s)
{
  QByteArray S = s . toUtf8 ( )             ;
  int        m = length - 1                 ;
  ::memset ( buffer , 0 , length )          ;
  if ( S . size ( ) <= 0 ) return false     ;
  if ( S . size ( ) <  m ) m = S . size ( ) ;
  char * p = (char *) S . data ( )          ;
  ::memcpy ( buffer , p , m )               ;
  return true                               ;
}

QByteArray Between(QByteArray & data,int pos,QString start,QString end)
{
  QByteArray b                                      ;
  int        s                                      ;
  int        e                                      ;
  s  = data . indexOf ( start . toUtf8 ( ) , pos  ) ;
  if ( s < 0 ) return b                             ;
  s += start . length ( )                           ;
  e  = data . indexOf ( end   . toUtf8 ( ) , s    ) ;
  if ( e < 0 ) return b                             ;
  b  = data . mid     ( s                  , e -s ) ;
  return b                                          ;
}
