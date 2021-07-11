#include <essentials.h>

#define STRINGS_SIGNATURE 0x73219601
#define CIOS_MARK         "CIOS"
#define USER_LENGTH       198
#define WRITE_FLAG        0x00000001
#define NO_WRITE_FLAG     ( WRITE_FLAG      ^ 0xFFFFFFFF )
#define OVERFLOW_FLAG     0x00000002
#define NO_OVERFLOW_FLAG  ( OVERFLOW_FLAG   ^ 0xFFFFFFFF )
#define PROCESS_FLAG      0x00000004
#define NO_PROCESS_FLAG   ( PROCESS_FLAG    ^ 0xFFFFFFFF )
#define NO_COMPACT_FLAG   0x80000000
#define COMPACT_FLAG      ( NO_COMPACT_FLAG ^ 0xFFFFFFFF )
#define LONG_FLAG         0x40000000
#define NO_LONG_FLAG      ( LONG_FLAG       ^ 0xFFFFFFFF )
#define IsAppProcess(p)   ( PROCESS_FLAG == ( p -> Flags & PROCESS_FLAG ) )

typedef struct                 {
  char    CIOS [           4 ] ;
  quint32 Signature            ;
  quint64 Flags                ;
  qint64  Size                 ;
  qint64  Occupied             ;
  qint32  Items                ;
  qint32  Format               ;
  qint32  Gaps                 ;
  qint32  Reading              ;
  qint32  Wait                 ;
  qint32  Interval             ;
  quint16 CRC16                ;
  char    User [ USER_LENGTH ] ;
} StringListHeader             ;

typedef struct                 {
  qint32  Length               ;
  char    Data [ 1 ]           ;
} ShortStringList              ;

typedef struct                 {
  qint64  Length               ;
  char    Data [ 1 ]           ;
} LongStringList               ;

N::Streaming::Strings:: Strings ( void )
                      : size    ( 0    )
                      , data    ( NULL )
{
}

N::Streaming::Strings:: Strings ( qint64 s , char * d )
                      : size    ( s                   )
                      , data    ( d                   )
{
}

N::Streaming::Strings:: Strings ( QByteArray & d )
                      : size    ( d . size ( )   )
                      , data    ( d . data ( )   )
{
}

N::Streaming::Strings:: Strings ( const Strings & s )
                      : size    ( s . size          )
                      , data    ( s . data          )
{
}

N::Streaming::Strings::~Strings(void)
{
}

qint64 N::Streaming::Strings::ToShort(char * block,QByteArray & B)
{
  if ( NULL == block ) return 0                         ;
  ShortStringList * p = (ShortStringList *) block       ;
  p -> Length = B . size ( )                            ;
  if ( p -> Length > 0 )                                {
    ::memcpy ( p -> Data , B . data ( ) , p -> Length ) ;
  }                                                     ;
  return ( sizeof(qint32) + p -> Length )               ;
}

qint64 N::Streaming::Strings::ToShort(char * block,QString & s)
{
  if ( NULL == block ) return 0                         ;
  ShortStringList * p = (ShortStringList *) block       ;
  QByteArray B = s . toUtf8 ( )                         ;
  p -> Length = B . size ( )                            ;
  if ( p -> Length > 0 )                                {
    ::memcpy ( p -> Data , B . data ( ) , p -> Length ) ;
  }                                                     ;
  return ( sizeof(qint32) + p -> Length )               ;
}

qint64 N::Streaming::Strings::FromShort(char * block,QString & s)
{
  if ( NULL == block ) return 0                                        ;
  ShortStringList * p = (ShortStringList *) block                      ;
  s . clear ( )                                                        ;
  if ( p -> Length > 0 )                                               {
    QByteArray B = QByteArray::fromRawData ( p -> Data , p -> Length ) ;
    s = QString::fromUtf8 ( B )                                        ;
  }                                                                    ;
  return ( sizeof(qint32) + p -> Length )                              ;
}

qint64 N::Streaming::Strings::ToLong(char * block,QByteArray & B)
{
  if ( NULL == block ) return 0                         ;
  LongStringList * p = (LongStringList *) block         ;
  p -> Length = B . size ( )                            ;
  if ( p -> Length > 0 )                                {
    ::memcpy ( p -> Data , B . data ( ) , p -> Length ) ;
  }                                                     ;
  return ( sizeof(qint64) + p -> Length )               ;
}

qint64 N::Streaming::Strings::ToLong(char * block,QString & s)
{
  if ( NULL == block ) return 0                         ;
  LongStringList * p = (LongStringList *) block         ;
  QByteArray B = s . toUtf8 ( )                         ;
  p -> Length = B . size ( )                            ;
  if ( p -> Length > 0 )                                {
    ::memcpy ( p -> Data , B . data ( ) , p -> Length ) ;
  }                                                     ;
  return ( sizeof(qint64) + p -> Length )               ;
}

qint64 N::Streaming::Strings::FromLong(char * block,QString & s)
{
  if ( NULL == block ) return 0                                        ;
  LongStringList * p = (LongStringList *) block                        ;
  s . clear ( )                                                        ;
  if ( p -> Length > 0 )                                               {
    QByteArray B = QByteArray::fromRawData ( p -> Data , p -> Length ) ;
    s = QString::fromUtf8 ( B )                                        ;
  }                                                                    ;
  return ( sizeof(qint64) + p -> Length )                              ;
}

bool N::Streaming::Strings::FromByteArray(int index,QString & s,QByteArray & d)
{
  Strings ss ( d )                           ;
  if ( ! ss . isSignature ( ) ) return false ;
  return ss . toString ( index , s )         ;
}

bool N::Streaming::Strings::FromByteArray(QStringList & s,QByteArray & d)
{
  Strings ss ( d )                           ;
  if ( ! ss . isSignature ( ) ) return false ;
  return ss . toStrings ( s )                ;
}

bool N::Streaming::Strings::ToByteArray(QStringList & s,QByteArray & d)
{
  Strings ss ( d )                            ;
  if ( ! ss . isSignature ( ) )               {
    if ( ! ss . Initialize ( ) ) return false ;
  }                                           ;
  return ss . toByteArray ( s )               ;
}

qint64 N::Streaming::Strings::blockHint(int blocks,int eachlength,bool longfmt)
{
  qint64 L = 0                                   ;
  L  = longfmt ? sizeof(qint64) : sizeof(qint32) ;
  L += eachlength                                ;
  L *= blocks                                    ;
  L += sizeof(StringListHeader)                  ;
  return L                                       ;
}

N::Streaming::Strings & N::Streaming::Strings::operator = (const Strings & s)
{
  size = s . size ;
  data = s . data ;
  return (*this)  ;
}

bool N::Streaming::Strings::isSignature(void)
{
  if ( size <  sizeof(StringListHeader) ) return false           ;
  if ( NULL == data                     ) return false           ;
  StringListHeader * p = (StringListHeader *) data               ;
  if ( 0 != ::memcmp ( p -> CIOS , CIOS_MARK ,4 ) ) return false ;
  return ( STRINGS_SIGNATURE == p -> Signature )                 ;
}

char * N::Streaming::Strings::Userdata(int & s)
{
  s = 0                                               ;
  if ( size <  sizeof(StringListHeader) ) return NULL ;
  if ( NULL == data                     ) return NULL ;
  StringListHeader * p = (StringListHeader *) data    ;
  s = USER_LENGTH                                     ;
  return p -> User                                    ;
}

bool N::Streaming::Strings::setGaps(int gaps)
{
  if ( size <  sizeof(StringListHeader) ) return false       ;
  if ( NULL == data                     ) return false       ;
  StringListHeader * p = (StringListHeader *) data           ;
  bool isLong = ( LONG_FLAG == ( p -> Format & LONG_FLAG ) ) ;
  if ( isLong )                                              {
    if ( gaps < 10 ) return false                            ;
  } else                                                     {
    if ( gaps <  6 ) return false                            ;
  }                                                          ;
  p -> Gaps = gaps                                           ;
  return true                                                ;
}

bool N::Streaming::Strings::setWaits(int waits)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  p -> Wait = waits                                    ;
  return true                                          ;
}

bool N::Streaming::Strings::setInterval(int interval)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  p -> Interval = interval                             ;
  return true                                          ;
}

bool N::Streaming::Strings::setEvents(bool appEvents)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  if ( appEvents )                                     {
    p -> Flags |= PROCESS_FLAG                         ;
  } else                                               {
    p -> Flags &= NO_PROCESS_FLAG                      ;
  }                                                    ;
  return true                                          ;
}

int N::Streaming::Strings::Gaps(void)
{
  if ( size <  sizeof(StringListHeader) ) return -1 ;
  if ( NULL == data                     ) return -1 ;
  StringListHeader * p = (StringListHeader *) data  ;
  return p -> Gaps                                  ;
}

int N::Streaming::Strings::Waits(void)
{
  if ( size <  sizeof(StringListHeader) ) return -1 ;
  if ( NULL == data                     ) return -1 ;
  StringListHeader * p = (StringListHeader *) data  ;
  return p -> Wait                                  ;
}

int N::Streaming::Strings::Interval(void)
{
  if ( size <  sizeof(StringListHeader) ) return -1 ;
  if ( NULL == data                     ) return -1 ;
  StringListHeader * p = (StringListHeader *) data  ;
  return p -> Interval                              ;
}

int N::Streaming::Strings::count(void)
{
  if ( size <  sizeof(StringListHeader) ) return -1 ;
  if ( NULL == data                     ) return -1 ;
  StringListHeader * p = (StringListHeader *) data  ;
  return p -> Items                                 ;
}

qint64 N::Streaming::Strings::BlockSize(void)
{
  if ( size <  sizeof(StringListHeader) ) return -1 ;
  if ( NULL == data                     ) return -1 ;
  StringListHeader * p = (StringListHeader *) data  ;
  return p -> Size                                  ;
}

qint64 N::Streaming::Strings::Occupied(void)
{
  if ( size <  sizeof(StringListHeader) ) return -1 ;
  if ( NULL == data                     ) return -1 ;
  StringListHeader * p = (StringListHeader *) data  ;
  return p -> Occupied                              ;
}

bool N::Streaming::Strings::setCompact(bool compact)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  if ( compact )                                       {
    p -> Format &= COMPACT_FLAG                        ;
  } else                                               {
    p -> Format |= NO_COMPACT_FLAG                     ;
  }                                                    ;
  return true                                          ;
}

bool N::Streaming::Strings::isCompact(void)
{
  if ( size <  sizeof(StringListHeader) ) return false            ;
  if ( NULL == data                     ) return false            ;
  StringListHeader * p = (StringListHeader *) data                ;
  return ( NO_COMPACT_FLAG != ( p -> Format & NO_COMPACT_FLAG ) ) ;
}

bool N::Streaming::Strings::setLongFormat(bool LongFormat)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  if ( LongFormat )                                    {
    p -> Format |= LONG_FLAG                           ;
  } else                                               {
    p -> Format &= NO_LONG_FLAG                        ;
  }                                                    ;
  return true                                          ;
}

bool N::Streaming::Strings::isLongFormat(void)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  return ( LONG_FLAG == ( p -> Format & LONG_FLAG ) )  ;
}

quint16 N::Streaming::Strings::Checksum(void)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  return p -> CRC16                                    ;
}

quint16 N::Streaming::Strings::doChecksum(void)
{
  if ( size <  sizeof(StringListHeader) ) return false            ;
  if ( NULL == data                     ) return false            ;
  StringListHeader * p = (StringListHeader *) data                ;
  /////////////////////////////////////////////////////////////////
  await ( true , p -> Wait , p -> Interval , IsAppProcess ( p ) ) ;
  quint16 CRC16                                                   ;
  p -> CRC16 = 0                                                  ;
  CRC16      = qChecksum ( data , (uint) size )                   ;
  p -> CRC16 = CRC16                                              ;
  /////////////////////////////////////////////////////////////////
  return CRC16                                                    ;
}

bool N::Streaming::Strings::Initialize(void)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  ::memcpy ( p -> CIOS , CIOS_MARK , 4 )               ;
  p -> Signature = STRINGS_SIGNATURE                   ;
  p -> Flags     = 0                                   ;
  p -> Size      = size                                ;
  p -> Occupied  = 0                                   ;
  p -> Items     = 0                                   ;
  p -> Format    = 0                                   ;
  p -> Gaps      = 256                                 ;
  p -> Reading   = 0                                   ;
  p -> Wait      = -1                                  ;
  p -> Interval  =  1                                  ;
  p -> CRC16     =  0                                  ;
  ::memset ( p -> User , 0 , USER_LENGTH )             ;
  return true                                          ;
}

bool N::Streaming::Strings::Clear(void)
{
  if ( size <  sizeof(StringListHeader) ) return false ;
  if ( NULL == data                     ) return false ;
  StringListHeader * p = (StringListHeader *) data     ;
  p -> Flags     = 0                                   ;
  p -> Occupied  = 0                                   ;
  p -> Items     = 0                                   ;
  p -> Reading   = 0                                   ;
  p -> CRC16     = 0                                   ;
  return true                                          ;
}

bool N::Streaming::Strings::Overflow(void)
{
  if ( size <  sizeof(StringListHeader) ) return false       ;
  if ( NULL == data                     ) return false       ;
  StringListHeader * p = (StringListHeader *) data           ;
  return ( OVERFLOW_FLAG == ( p -> Flags & OVERFLOW_FLAG ) ) ;
}

bool N::Streaming::Strings::canRead(void)
{
  StringListHeader * p = (StringListHeader *) data ;
  if ( p -> Reading > 0 ) return false             ;
  return ( 0 == ( p -> Flags & WRITE_FLAG ) )      ;
}

bool N::Streaming::Strings::canWrite(void)
{
  StringListHeader * p = (StringListHeader *) data ;
  return ( p -> Reading <= 0 )                     ;
}

bool N::Streaming::Strings::isLocked(bool write)
{
  if ( write ) return ( ! canWrite ( ) ) ;
  return              ( ! canRead  ( ) ) ;
}

bool N::Streaming::Strings::await(bool write,int msecs,int interval,bool events)
{
  if ( msecs < 0 )                              {
    while ( isLocked ( write ) )                {
      if ( interval > 0 )                       {
        if ( events ) Time::skip   ( interval ) ;
                 else Time::msleep ( interval ) ;
      }                                         ;
    }                                           ;
  } else                                        {
    QDateTime T = nTimeNow                      ;
    while ( isLocked ( write ) )                {
      if ( interval > 0 )                       {
        if ( events ) Time::skip   ( interval ) ;
                 else Time::msleep ( interval ) ;
      }                                         ;
      if ( T . msecsTo ( nTimeNow ) > msecs )   {
        return false                            ;
      }                                         ;
    }                                           ;
  }                                             ;
  return true                                   ;
}

bool N::Streaming::Strings::toString(int index,QString & s)
{
  if ( size <  sizeof(StringListHeader) ) return false                       ;
  if ( NULL == data                     ) return false                       ;
  StringListHeader * p = (StringListHeader *) data                           ;
  ////////////////////////////////////////////////////////////////////////////
  bool   overflow = ( OVERFLOW_FLAG   == ( p -> Flags & OVERFLOW_FLAG    ) ) ;
  if ( overflow            ) return false                                    ;
  if ( index >= p -> Items ) return false                                    ;
  ////////////////////////////////////////////////////////////////////////////
  bool   isLong   = ( LONG_FLAG       == ( p -> Format & LONG_FLAG       ) ) ;
  bool   compact  = ( NO_COMPACT_FLAG != ( p -> Format & NO_COMPACT_FLAG ) ) ;
  int    gaps     = p -> Gaps                                                ;
  char * a        = data + sizeof(StringListHeader)                          ;
  ////////////////////////////////////////////////////////////////////////////
  await ( false , p -> Wait , p -> Interval , IsAppProcess ( p ) )           ;
  p -> Reading ++                                                            ;
  ////////////////////////////////////////////////////////////////////////////
  if ( compact )                                                             {
    if ( index > 0 )                                                         {
      for (int i=0;i<index;i++)                                              {
        if ( isLong )                                                        {
          LongStringList  * v = (LongStringList  *) a                        ;
          a += sizeof(qint64)                                                ;
          a += v -> Length                                                   ;
        } else                                                               {
          ShortStringList * v = (ShortStringList *) a                        ;
          a += sizeof(qint32)                                                ;
          a += v -> Length                                                   ;
        }                                                                    ;
      }                                                                      ;
    }                                                                        ;
    if ( isLong ) FromLong  ( a , s )                                        ;
             else FromShort ( a , s )                                        ;
  } else                                                                     {
    a += ( gaps * index )                                                    ;
    if ( isLong ) FromLong  ( a , s )                                        ;
             else FromShort ( a , s )                                        ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  p -> Reading --                                                            ;
  ////////////////////////////////////////////////////////////////////////////
  return true                                                                ;
}

bool N::Streaming::Strings::toStrings(QStringList & s)
{
  if ( size <  sizeof(StringListHeader) ) return false                       ;
  if ( NULL == data                     ) return false                       ;
  StringListHeader * p = (StringListHeader *) data                           ;
  ////////////////////////////////////////////////////////////////////////////
  bool   overflow = ( OVERFLOW_FLAG   == ( p -> Flags & OVERFLOW_FLAG    ) ) ;
  if ( overflow ) return false                                               ;
  ////////////////////////////////////////////////////////////////////////////
  bool   isLong   = ( LONG_FLAG       == ( p -> Format & LONG_FLAG       ) ) ;
  bool   compact  = ( NO_COMPACT_FLAG != ( p -> Format & NO_COMPACT_FLAG ) ) ;
  int    gaps     = p -> Gaps                                                ;
  int    c        = p -> Items                                               ;
  char * a        = data + sizeof(StringListHeader)                          ;
  ////////////////////////////////////////////////////////////////////////////
  await ( false , p -> Wait , p -> Interval , IsAppProcess ( p ) )           ;
  p -> Reading ++                                                            ;
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0 ; i < c ; i++ )                                             {
    if ( compact )                                                           {
      QString v                                                              ;
      if ( isLong ) gaps = FromLong  ( a , v )                               ;
               else gaps = FromShort ( a , v )                               ;
      s << v                                                                 ;
    } else                                                                   {
      QString v                                                              ;
      if ( isLong )        FromLong  ( a , v )                               ;
               else        FromShort ( a , v )                               ;
      s << v                                                                 ;
    }                                                                        ;
    a += gaps                                                                ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  p -> Reading --                                                            ;
  ////////////////////////////////////////////////////////////////////////////
  return true                                                                ;
}

bool N::Streaming::Strings::toByteArray(QStringList & s)
{
  if ( size <  sizeof(StringListHeader) ) return false                       ;
  if ( NULL == data                     ) return false                       ;
  StringListHeader * p = (StringListHeader *) data                           ;
  ////////////////////////////////////////////////////////////////////////////
  bool   isLong   = ( LONG_FLAG       == ( p -> Format & LONG_FLAG       ) ) ;
  bool   compact  = ( NO_COMPACT_FLAG != ( p -> Format & NO_COMPACT_FLAG ) ) ;
  int    gaps     = p -> Gaps                                                ;
  char * a        = data + sizeof(StringListHeader)                          ;
  qint64 c        = s . count ( )                                            ;
  qint64 rest     = size - sizeof(StringListHeader)                          ;
  ////////////////////////////////////////////////////////////////////////////
  await ( true , p -> Wait , p -> Interval , IsAppProcess ( p ) )            ;
  if ( compact )                                                             {
    p -> Flags    |= WRITE_FLAG                                              ;
    p -> Flags    &= NO_OVERFLOW_FLAG                                        ;
    p -> Occupied  = sizeof(StringListHeader)                                ;
    p -> Items     = 0                                                       ;
    p -> CRC16     = 0                                                       ;
    //////////////////////////////////////////////////////////////////////////
    for (int i=0;i<c;i++)                                                    {
      QByteArray B = s [ i ] . toUtf8 ( )                                    ;
      gaps = B . size ( )                                                    ;
      if ( isLong )                                                          {
        gaps += sizeof(qint64)                                               ;
        if ( ( rest - gaps ) < 0 )                                           {
          p -> Flags |= OVERFLOW_FLAG                                        ;
          p -> Flags &= NO_WRITE_FLAG                                        ;
          return false                                                       ;
        }                                                                    ;
        ToLong  ( a , B )                                                    ;
      } else                                                                 {
        gaps += sizeof(qint32)                                               ;
        if ( ( rest - gaps ) < 0 )                                           {
          p -> Flags |= OVERFLOW_FLAG                                        ;
          p -> Flags &= NO_WRITE_FLAG                                        ;
          return false                                                       ;
        }                                                                    ;
        ToShort ( a , B )                                                    ;
      }                                                                      ;
      a             += gaps                                                  ;
      rest          -= gaps                                                  ;
      p -> Occupied += gaps                                                  ;
      p -> Items    ++                                                       ;
    }                                                                        ;
    //////////////////////////////////////////////////////////////////////////
    p -> Flags    &= NO_WRITE_FLAG                                           ;
  } else                                                                     {
    if ( ( c * gaps ) > rest ) return false                                  ;
    p -> Flags    |= WRITE_FLAG                                              ;
    p -> Flags    &= NO_OVERFLOW_FLAG                                        ;
    p -> Occupied  = sizeof(StringListHeader)                                ;
    p -> Occupied += ( c * gaps )                                            ;
    p -> Items     = c                                                       ;
    p -> CRC16     = 0                                                       ;
    //////////////////////////////////////////////////////////////////////////
    for (int i=0;i<c;i++)                                                    {
      QByteArray B = s [ i ] . toUtf8 ( )                                    ;
      int        c = B . size ( )                                            ;
      if ( isLong )                                                          {
        if ( ( c + sizeof(qint64) ) > gaps )                                 {
          c = gaps - sizeof(qint64)                                          ;
          if ( c >= 0 ) B . resize ( c ) ; else B . clear ( )                ;
        }                                                                    ;
        ToLong  ( a , B )                                                    ;
      } else                                                                 {
        if ( ( c + sizeof(qint32) ) > gaps )                                 {
          c = gaps - sizeof(qint32)                                          ;
          if ( c >= 0 ) B . resize ( c ) ; else B . clear ( )                ;
        }                                                                    ;
        ToShort ( a , B )                                                    ;
      }                                                                      ;
      a += gaps                                                              ;
    }                                                                        ;
    //////////////////////////////////////////////////////////////////////////
    p -> Flags    &= NO_WRITE_FLAG                                           ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  return true                                                                ;
}
