#include <essentials.h>

#pragma pack(push,1)

typedef struct StreamHeaderPacket  {
  char          CIOS      [  4 ]   ; // 04
  qint32        Type               ; // 08
  quint64       Uuid               ; // 16
  char          Signature [ 12 ]   ; // 28
  unsigned char Data      [ 32 ]   ; // 60
  quint32       Adler              ; // 64
}               StreamHeaderPacket ;

#pragma pack(pop)

N::StreamHeader:: StreamHeader (void)
                : QByteArray   (    )
{
  Default ( ) ;
}

N::StreamHeader::~StreamHeader (void)
{
}

void N::StreamHeader::Default(void)
{
  StreamHeaderPacket * SHP               ;
  resize ( 64 )                          ;
  fill   ( 0  )                          ;
  SHP  = (StreamHeaderPacket *) data ( ) ;
  SHP -> CIOS [ 0 ] = 'C'                ;
  SHP -> CIOS [ 1 ] = 'I'                ;
  SHP -> CIOS [ 2 ] = 'O'                ;
  SHP -> CIOS [ 3 ] = 'S'                ;
}

unsigned int N::StreamHeader::Adler(void)
{
  QByteArray B   ( data ( ) , 60 ) ;
  return ADLER32 ( B             ) ;
}

void N::StreamHeader::setType(int type)
{
  StreamHeaderPacket * SHP                      ;
  SHP         = (StreamHeaderPacket *) data ( ) ;
  SHP -> Type = type                            ;
}

int N::StreamHeader::Type(void)
{
  StreamHeaderPacket * SHP              ;
  SHP = (StreamHeaderPacket *) data ( ) ;
  return (int) SHP -> Type              ;
}

void N::StreamHeader::setUuid (SUID uuid)
{
  StreamHeaderPacket * SHP              ;
  SHP  = (StreamHeaderPacket *)data ( ) ;
  SHP -> Uuid = uuid                    ;
}

SUID N::StreamHeader::Uuid(void)
{
  StreamHeaderPacket * SHP              ;
  SHP = (StreamHeaderPacket *) data ( ) ;
  return (SUID) SHP -> Uuid             ;
}

void N::StreamHeader::setSignature(QString signature)
{
  QByteArray           B = signature . toUtf8 ( )    ;
  int                  L = B         . size   ( )    ;
  StreamHeaderPacket * SHP                           ;
  SHP = (StreamHeaderPacket *) data ( )              ;
  ::memset ( SHP -> Signature , 0 , 12 )             ;
  if ( L > 0 )                                       {
    if ( L > 11 ) L = 11                             ;
    ::memcpy ( SHP -> Signature , B . data ( ) , L ) ;
  }                                                  ;
}

bool N::StreamHeader::isSignature(QString signature)
{
  QByteArray           B = signature . toUtf8 ( )                  ;
  int                  L = B         . size   ( )                  ;
  StreamHeaderPacket * SHP                                         ;
  SHP = (StreamHeaderPacket *) data ( )                            ;
  if ( L >  11 ) L = 11                                            ;
  if ( L <= 0  ) return false                                      ;
  return ( 0 == ::memcmp ( SHP -> Signature , B . data ( ) , L ) ) ;
}

QString N::StreamHeader::Signature(void)
{
  char                 SIGN [ 16 ]        ;
  StreamHeaderPacket * SHP                ;
  SHP = (StreamHeaderPacket *) data ( )   ;
  ::memset ( SIGN , 0              , 16 ) ;
  ::memcpy ( SIGN , SHP->Signature , 12 ) ;
  return QString :: fromUtf8 ( SIGN )     ;
}

void N::StreamHeader::setStreamInfo (QByteArray B)
{
  int                  L = B . size ( )         ;
  StreamHeaderPacket * SHP                      ;
  SHP = (StreamHeaderPacket *) data ( )         ;
  ::memset ( SHP->Data , 0 , 32 )               ;
  if ( L > 0 )                                  {
    if ( L > 32 ) L = 32                        ;
    ::memcpy ( SHP -> Data , B . data ( ) , L ) ;
  }                                             ;
}

QByteArray N::StreamHeader::StreamInfo(void)
{
  StreamHeaderPacket * SHP                         ;
  SHP = (StreamHeaderPacket *) data ( )            ;
  QByteArray B ( (const char *) SHP -> Data , 32 ) ;
  return     B                                     ;
}

void N::StreamHeader::setChecksum(void)
{
  StreamHeaderPacket * SHP                       ;
  SHP          = (StreamHeaderPacket *) data ( ) ;
  SHP -> Adler = (qint32) Adler              ( ) ;
}

bool N::StreamHeader::isValid(void)
{
  StreamHeaderPacket * SHP                          ;
  SHP = (StreamHeaderPacket *) data ( )             ;
  if ( SHP -> CIOS [ 0 ] != 'C' ) return false      ;
  if ( SHP -> CIOS [ 1 ] != 'I' ) return false      ;
  if ( SHP -> CIOS [ 2 ] != 'O' ) return false      ;
  if ( SHP -> CIOS [ 3 ] != 'S' ) return false      ;
  return ( ( (qint32) Adler ( ) ) == SHP -> Adler ) ;
}
