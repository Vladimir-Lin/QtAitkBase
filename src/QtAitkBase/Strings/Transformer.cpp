#include <essentials.h>

QByteArray N::Shrink(Compressions::GeneralMethods type,const QByteArray & data,int level)
{
  switch (type)                      {
    case Compressions::QZ            :
      return   qCompress(data,level) ;
    case Compressions::RLE           :
      if (level>3) level = 3         ;
      if (level<1) level = 3         ;
      return RleCompress(data,level) ;
    case Compressions::GZ            :
      return  GzCompress(data,level) ;
    case Compressions::BZ            :
      return  BzCompress(data,level) ;
    case Compressions::XZ            :
      return  XzCompress(data,level) ;
  }                                  ;
  return data                        ;
}

QByteArray N::Expand(Compressions::GeneralMethods type,const QByteArray & data,int level)
{
  switch (type)                      {
    case Compressions::QZ            :
    return   qUncompress(data      ) ;
    case Compressions::RLE           :
      if (level>3) level = 3         ;
      if (level<1) level = 3         ;
    return RleUncompress(data,level) ;
    case Compressions::GZ            :
    return  GzUncompress(data      ) ;
    case Compressions::BZ            :
    return  BzUncompress(data      ) ;
    case Compressions::XZ            :
    return  XzUncompress(data      ) ;
  }                                  ;
  return data                        ;
}

QVariants N::Emptiness(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R            ;
  R << Paraments.first() ;
  R << (bool)true        ;
  R << (int)0            ;
  return R               ;
}

QVariants N::DataCopier(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                               ;
  R << Paraments[0]                         ;
  Target = Source                           ;
  R << (bool)(Target.size()==Source.size()) ;
  R << (int)Target.size()                   ;
  return R                                  ;
}

QVariants N::QzCompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 9                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    Target =  qCompress(Source,level)           ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::QzDecompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target =  qUncompress(Source)               ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}


QVariants N::GzCompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 9                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    Target = GzCompress(Source,level)           ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::GzDecompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target = GzUncompress(Source)               ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}


QVariants N::RleCompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 3                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    if (level>3 || level <1) level = 3          ;
    Target = RleCompress(Source,level)          ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::RleDecompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 3                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    if (level>3 || level <1) level = 3          ;
    Target = RleUncompress(Source,level)        ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::BzCompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 9                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    Target = BzCompress(Source,level)           ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::BzDecompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target = BzUncompress(Source)               ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::XzCompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 9                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    Target = XzCompress(Source,level)           ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::XzDecompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target = XzUncompress(Source)               ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::LzoCompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    int level = 9                               ;
    if (Paraments.count()>1)                    {
      level = Paraments[1].toInt()              ;
    }                                           ;
    Target = LzoCompress(Source,level)          ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::LzoDecompressor(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target = LzoUncompress(Source)              ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::Base32Encoder(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{ Q_UNUSED ( Paraments ) ;
  Q_UNUSED ( Target    ) ;
  QVariants  R           ;
  return     R           ;
}

QVariants N::Base32Decoder(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{ Q_UNUSED ( Paraments ) ;
  Q_UNUSED ( Target    ) ;
  QVariants  R           ;
  return     R           ;
}

QVariants N::Base64Encoder(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target = Source.toBase64()                  ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::Base64Decoder(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                   ;
  R << Paraments[0]                             ;
  if (Source.size()<=0) R << (bool)false ; else {
    Target = QByteArray::fromBase64(Source)     ;
    R << (bool)true                             ;
    R << (int)Target.size()                     ;
  }                                             ;
  return R                                      ;
}

QVariants N::MD4Encoder(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                       ;
  R << Paraments[0]                                 ;
  if (Source.size()<=0) R << (bool)false ; else     {
    QCryptographicHash md4(QCryptographicHash::Md4) ;
    md4.addData(Source)                             ;
    Target = md4.result()                           ;
    R << (bool)true                                 ;
    R << (int)Target.size()                         ;
  }                                                 ;
  return R                                          ;
}

QVariants N::MD5Encoder(QVariants & Paraments,const QByteArray & Source,QByteArray & Target)
{
  QVariants R                                       ;
  R << Paraments[0]                                 ;
  if (Source.size()<=0) R << (bool)false ; else     {
    QCryptographicHash md5(QCryptographicHash::Md5) ;
    md5.addData(Source)                             ;
    Target = md5.result()                           ;
    R << (bool)true                                 ;
    R << (int)Target.size()                         ;
  }                                                 ;
  return R                                          ;
}
