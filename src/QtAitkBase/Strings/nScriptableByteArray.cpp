#include <Essentials>

#ifndef QT_STATIC

N::ScriptableByteArray:: ScriptableByteArray ( QObject * parent )
                       : QObject             (           parent )
                       , QScriptable         (                  )
                       , QByteArray          (                  )
{
}

N::ScriptableByteArray::~ScriptableByteArray (void)
{
}

void N::ScriptableByteArray::Clear(void)
{
  clear ( ) ;
}

N::ScriptableByteArray & N::ScriptableByteArray::Remove(int pos,int len)
{
  remove ( pos , len ) ;
  return ME            ;
}

QString N::ScriptableByteArray::Mid(int pos,int len)
{
  QByteArray B = mid ( pos , len ) ;
  return QString::fromUtf8 ( B )   ;
}

int N::ScriptableByteArray::IndexOf (const QString & str,int from)
{
  QByteArray B = str . toUtf8 ( ) ;
  return indexOf ( B , from )     ;
}

N::ScriptableByteArray & N::ScriptableByteArray::Prepend(const QString & str)
{
  QByteArray B = str . toUtf8 ( ) ;
  prepend ( B )                   ;
  return ME                       ;
}

N::ScriptableByteArray & N::ScriptableByteArray::Append(const QString & str)
{
  QByteArray B = str . toUtf8 ( ) ;
  append ( B )                    ;
  return ME                       ;
}

N::ScriptableByteArray & N::ScriptableByteArray::Insert(int i,const QString & str)
{
  QByteArray B = str . toUtf8 ( ) ;
  insert ( i , B )                ;
  return ME                       ;
}

N::ScriptableByteArray & N::ScriptableByteArray::Replace(int pos,int len, const QString & after)
{
  QByteArray A = after  . toUtf8 ( ) ;
  replace ( pos , len , A )          ;
  return ME                          ;
}

N::ScriptableByteArray & N::ScriptableByteArray::Replace(const QString & before, const QString & after)
{
  QByteArray B = before . toUtf8 ( ) ;
  QByteArray A = after  . toUtf8 ( ) ;
  replace ( B , A )                  ;
  return ME                          ;
}

int N::ScriptableByteArray::Load(QString filename)
{
  QByteArray B                       ;
  clear             (              ) ;
  File::toByteArray ( filename , B ) ;
  append            ( B            ) ;
  return size       (              ) ;
}

bool N::ScriptableByteArray::Save(QString filename)
{
  return File::toFile ( filename , * (QByteArray *) this ) ;
}

int N::ScriptableByteArray::Size(void)
{
  return size ( ) ;
}

void N::ScriptableByteArray::Resize(int s)
{
  resize ( s ) ;
}

void N::ScriptableByteArray::Chop(int s)
{
  chop ( s ) ;
}

bool N::ScriptableByteArray::Contains (const QString & str)
{
  QByteArray B = str . toUtf8 ( ) ;
  return contains ( B )           ;
}

QString N::ScriptableByteArray::toString (void)
{
  return QString::fromUtf8 ( *(QByteArray *) this ) ;
}

QString N::ScriptableByteArray::toString (QString codec)
{
  QTextCodec * c = QTextCodec::codecForName ( codec . toUtf8 ( ) ) ;
  if ( NULL == c ) return ""                                       ;
  return  c -> toUnicode ( *(QByteArray *) this )                  ;
}

QString N::ScriptableByteArray::Left(int len)
{
  QByteArray L = left ( len )    ;
  return QString::fromUtf8 ( L ) ;
}

QString N::ScriptableByteArray::Right(int len)
{
  QByteArray R = right ( len )   ;
  return QString::fromUtf8 ( R ) ;
}

QString N::ScriptableByteArray::At(int index)
{
  QChar c = at ( index ) ;
  return QString ( c )   ;
}

QString N::ScriptableByteArray::Between(int pos,QString S,QString E)
{
  QString    r                           ;
  QByteArray b                           ;
  int        s                           ;
  int        e                           ;
  s  = indexOf ( S . toUtf8 ( ) , pos  ) ;
  if ( s < 0 ) return r                  ;
  s += S . length ( )                    ;
  e  = indexOf ( E . toUtf8 ( ) , s    ) ;
  if ( e < 0 ) return r                  ;
  b  = mid     ( s              , e -s ) ;
  return QString::fromUtf8 ( b )         ;
}

QScriptValue N::ByteArrayAttachment(QScriptContext * context,QScriptEngine * engine)
{
  N::ScriptableByteArray * bytes = new N::ScriptableByteArray ( engine ) ;
  return engine -> newQObject  ( bytes   )                               ;
}

#endif
