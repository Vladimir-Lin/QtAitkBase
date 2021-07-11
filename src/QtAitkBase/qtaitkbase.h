/****************************************************************************
 *
 * Copyright (C) 2001 ~ 2021
 * 
 *  Neutrino International Inc.
 *  Oriphase Space Travelling Industry
 *
 * Author   : Brian Lin ( Foxman , Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com (2107437784)
 * LINE     : lin-foxman
 *
 ****************************************************************************/
#ifndef QT_AITK_BASE_H
#define QT_AITK_BASE_H
//////////////////////////////////////////////////////////////////////////////
#ifdef QT_CORE_LIB
#include <QtCore>
#endif
//////////////////////////////////////////////////////////////////////////////
#ifdef QT_NETWORK_LIB
#include <QtNetwork>
#endif
//////////////////////////////////////////////////////////////////////////////
#ifdef QT_SQL_LIB
#include <QtSql>
#endif
//////////////////////////////////////////////////////////////////////////////
#include <QtUUID>
//////////////////////////////////////////////////////////////////////////////
QT_BEGIN_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
#ifndef QT_STATIC
#    if defined(QT_BUILD_QTAITKBASE_LIB)
#      define Q_QTAITKBASE_EXPORT Q_DECL_EXPORT
#    else
#      define Q_QTAITKBASE_EXPORT Q_DECL_IMPORT
#    endif
#else
#      define Q_QTAITKBASE_EXPORT
#endif
//////////////////////////////////////////////////////////////////////////////
#define QT_AITK_BASE_LIB 1
#define QT_AITK_BASE_VERSION 202107112301
//////////////////////////////////////////////////////////////////////////////
typedef long long                        TUID                                ; // Timestamp for Star date calendar
typedef long double                      MUID                                ; // Timestamp for floating Star date calendar
typedef int                              CUID                                ; // Type IDs : Language ID , Type ID and so on
typedef unsigned long long               FUID                                ; // Flags
typedef QList     < bool               > BOOLs                               ; // List of Boolean
typedef QList     < TUID               > TUIDs                               ; // List of TUID
typedef QList     < CUID               > CUIDs                               ; // List of Type IDs
typedef QMap      < QString , QString  > KMAPs                               ; // String maps
typedef QMap      < QString , int      > UMAPs                               ; // String maps to integer
typedef QMap      < QString , SUID     > ZMAPs                               ; // String maps to SUID
typedef QMap      < QString , bool     > LMAPs                               ; // String maps to bool
typedef QMap      < QString , double   > OMAPs                               ; // String maps to double
typedef QMap      < QString , QVariant > WMAPs                               ; // String maps to variant
typedef QMap      < SUID    , SUID     > SMAPs                               ; // SUID conversion
typedef QMap      < SUID    , TUID     > GMAPs                               ; // TUID conversion
typedef QMap      < SUID    , int      > RMAPs                               ; // SUID maps to integer
typedef QMap      < SUID    , bool     > XMAPs                               ; // UUID Boolean maps
typedef QMap      < SUID    , QString  > NAMEs                               ; // SUID maps to name
typedef QMap      < int     , SUID     > CMAPs                               ; // integer maps to SUID
typedef QMap      < int     , TUID     > YMAPs                               ; // integer maps to TUID
typedef QMap      < int     , QString  > EMAPs                               ; // int maps to QString
typedef QMap      < int     , bool     > BMAPs                               ; // Boolean maps
typedef QMap      < int     , int      > IMAPs                               ; // Integer maps
typedef QMap      < int     , double   > DMAPs                               ; // Double maps
typedef QMap      < int     , void *   > HMAPs                               ; // Hull maps
typedef QMap      < void *  , void *   > AMAPs                               ; // Pointer to Pointer map
typedef QMultiMap < SUID    , SUID     > NMAPs                               ; // Multi SUID maps
typedef QPair     < TUID    , SUID     > TMAP                                ; // Time map
typedef QPair     < QString , QString  > VMAP                                ; // String pair
typedef QPair     < int     , void *   > PMAP                                ; // Property pair
typedef QList     < void    *          > VOIDs                               ; // pointers
typedef QList     < TMAP               > TMAPs                               ; // Time map items
typedef QList     < VMAP               > VMAPs                               ; // String pairs
typedef QList     < PMAP               > PMAPs                               ; // Property pairs
typedef QList     < QUrl               > URLs                                ;
typedef QList     < QVariant           > QVariants                           ;
typedef QStringList                      QStrings                            ;
typedef QVector   < int                > VectorInt                           ;
//////////////////////////////////////////////////////////////////////////////
// implicit_cast is possible supported on some version of C++ compiler
//////////////////////////////////////////////////////////////////////////////
#if defined(IMPLICIT_CAST_DEFINED)
#else
template<class T, class U> T implicit_cast( const U & x ) { return x ; }
#endif
//////////////////////////////////////////////////////////////////////////////
template<class T>
inline typename T::value_type maxitem ( const T & container )                {
  typename T::value_type m            = *container . begin ( )               ;
  for ( typename T::const_iterator i  =  container . begin ( )               ;
                                   i !=  container . end   ( )               ;
                                 ++i                                         )
    if ( m < (*i) ) m = *i                                                   ;
  return m                                                                   ;
}
//////////////////////////////////////////////////////////////////////////////
template<class T>
inline typename T::value_type minitem ( const T & container )                {
  typename T::value_type m            = *container . begin ( )               ;
  for ( typename T::const_iterator i  =  container . begin ( )               ;
                                   i !=  container . end   ( )               ;
                                 ++i                                         )
    if ( m > (*i) ) m = *i                                                   ;
  return m                                                                   ;
}
//////////////////////////////////////////////////////////////////////////////
namespace N                                                                  {
//////////////////////////////////////////////////////////////////////////////
/****************************************************************************\
 *                                                                          *
 *                                  Templates                               *
 *                                                                          *
\****************************************************************************/
template <typename T>
class Range                                                                  {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    T L                                                                      ;
    T R                                                                      ;
    //////////////////////////////////////////////////////////////////////////
    explicit Range ( void )                                                  {
    }
    //////////////////////////////////////////////////////////////////////////
    explicit Range ( T Left , T Right )                                      {
               L = Left                                                      ;
               R = Right                                                     ;
             }
    //////////////////////////////////////////////////////////////////////////
             Range ( const Range < T > & range )                             {
               L = range . L                                                 ;
               R = range . R                                                 ;
             }
    //////////////////////////////////////////////////////////////////////////
    virtual ~Range ( void )                                                  {
    }
    //////////////////////////////////////////////////////////////////////////
    bool isValid ( void )                                                    {
      return ! isWrong ( )                                                   ;
    }
    //////////////////////////////////////////////////////////////////////////
    bool isWrong ( void )                                                    {
      return     ( L > R )                                                   ;
    }
    //////////////////////////////////////////////////////////////////////////
    T Distance ( void )                                                      {
      return (T) ( R - L )                                                   ;
    }
    //////////////////////////////////////////////////////////////////////////
    T V ( void )                                                             {
      return (T) ( R - L )                                                   ;
    }
    //////////////////////////////////////////////////////////////////////////
    bool Between (T v )                                                      {
      if (v<L) return false                                                  ;
      if (v>R) return false                                                  ;
      return true                                                            ;
    }
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
}                                                                            ;
//////////////////////////////////////////////////////////////////////////////
template <typename T>
class LoopValue                                                              {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    T L                                                                      ;
    T R                                                                      ;
    T V                                                                      ;
    //////////////////////////////////////////////////////////////////////////
    explicit LoopValue ( void )                                              {
    }
    //////////////////////////////////////////////////////////////////////////
    explicit LoopValue ( T Value , T Left , T Right )                        {
               L = Left                                                      ;
               R = Right                                                     ;
               V = Value                                                     ;
             }
    //////////////////////////////////////////////////////////////////////////
    explicit LoopValue ( T Left , T Right )                                  {
               L = Left                                                      ;
               R = Right                                                     ;
               V = Left                                                      ;
             }
    //////////////////////////////////////////////////////////////////////////
    explicit LoopValue ( T Value )                                           {
               V = Value                                                     ;
             }
    //////////////////////////////////////////////////////////////////////////
             LoopValue ( const LoopValue < T > & loop )                      {
               L = loop . L                                                  ;
               R = loop . R                                                  ;
               V = loop . V                                                  ;
             }
    //////////////////////////////////////////////////////////////////////////
    virtual ~LoopValue ( void )                                              {
    }
    //////////////////////////////////////////////////////////////////////////
    T & operator () ( void )                                                 {
      return V                                                               ;
    }
    //////////////////////////////////////////////////////////////////////////
    bool isValid ( void )                                                    {
      if ( L > R ) return false                                              ;
      if ( V < L ) return false                                              ;
      if ( V > R ) return false                                              ;
      return true                                                            ;
    }
    //////////////////////////////////////////////////////////////////////////
    bool isWrong ( void )                                                    {
      if ( L > R ) return true                                               ;
      if ( V < L ) return true                                               ;
      if ( V > R ) return true                                               ;
      return false                                                           ;
    }
    //////////////////////////////////////////////////////////////////////////
    T Distance ( void )                                                      {
      return (T) ( R - L )                                                   ;
    }
    //////////////////////////////////////////////////////////////////////////
    bool Between ( T v )                                                     {
      if ( v < L ) return false                                              ;
      if ( v > R ) return false                                              ;
      return true                                                            ;
    }
    //////////////////////////////////////////////////////////////////////////
    T & operator ++ ( void )                                                 {
      ++V                                                                    ;
      if ( V > R ) V = L                                                     ;
      return V                                                               ;
    }
    //////////////////////////////////////////////////////////////////////////
    T & operator -- ( void )                                                 {
      --V                                                                    ;
      if ( V < L ) V = R                                                     ;
      return V                                                               ;
    }
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
}                                                                            ;
//////////////////////////////////////////////////////////////////////////////
/****************************************************************************\
 *                                                                          *
 *                                  Typedefs                                *
 *                                                                          *
\****************************************************************************/
typedef Range     < char           > RangeTiny                               ;
typedef Range     < unsigned char  > RangeByte                               ;
typedef Range     < short          > RangeShort                              ;
typedef Range     < unsigned short > RangeUShort                             ;
typedef Range     < int            > RangeInt                                ;
typedef Range     < unsigned int   > RangeUInt                               ;
typedef Range     < TUID           > RangeTuid                               ;
typedef Range     < SUID           > RangeUuid                               ;
typedef Range     < float          > RangeFloat                              ;
typedef Range     < double         > RangeDouble                             ;
typedef Range     < long double    > RangeLongDouble                         ;
typedef RangeTuid                    TimePeriod                              ;
//////////////////////////////////////////////////////////////////////////////
typedef LoopValue < char           > LoopTiny                                ;
typedef LoopValue < unsigned char  > LoopByte                                ;
typedef LoopValue < short          > LoopShort                               ;
typedef LoopValue < unsigned short > LoopUShort                              ;
typedef LoopValue < int            > LoopInt                                 ;
typedef LoopValue < unsigned int   > LoopUInt                                ;
typedef LoopValue < TUID           > LoopTuid                                ;
typedef LoopValue < SUID           > LoopUuid                                ;
//////////////////////////////////////////////////////////////////////////////
/****************************************************************************\
 *                                                                          *
 *                          Function Definitions                            *
 *                                                                          *
\****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
class Q_QTAITKBASE_EXPORT Destroyer                                          ;
class Q_QTAITKBASE_EXPORT Anything                                           ;
class Q_QTAITKBASE_EXPORT BooleanArray                                       ;
class Q_QTAITKBASE_EXPORT TimeBits                                           ;
class Q_QTAITKBASE_EXPORT Enabler                                            ;
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
/****************************************************************************\
 * Destroyer is a class that helps to destroy any classes which does not    *
 * know when will it is about to be destroyed.                              *
\****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
class Q_QTAITKBASE_EXPORT Destroyer                                          {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    explicit     Destroyer  ( void )                                         ;
    virtual     ~Destroyer  ( void )                                         ;
    //////////////////////////////////////////////////////////////////////////
    virtual bool Recycling  ( void )                                         ;
    virtual bool Destructor ( void )                                         ;
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
}                                                                            ;
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
/****************************************************************************\
 *                                                                          *
 *                              Lore Unification                            *
 *                                                                          *
 * Many knowledge assimilation processs require a `lore anything`           *
 * for vagueness description.                                               *
 *                                                                          *
 * N::Anything is the implementation to contain any lore that required to   *
 * go through knowledge transformation process.  It can be used to describe *
 * `anything` in the CIOS system.                                           *
 *                                                                          *
\****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
class Q_QTAITKBASE_EXPORT Anything                                           {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    SUID                          uuid                                       ;
    int                           type                                       ;
    QVariant::Type                solo                                       ;
    QStringList                   strings                                    ;
    UUIDs                         uuids                                      ;
    VarArgs                       arguments                                  ;
    VarArgLists                   commands                                   ;
    ByteArrays                    arrays                                     ;
    QMap < QString , VarArgs    > locators                                   ;
    QMap < QString , QByteArray > partitions                                 ;
    //////////////////////////////////////////////////////////////////////////
    explicit   Anything           ( void                                   ) ;
               Anything           ( const Anything & any                   ) ;
               Anything           (       Anything & any                   ) ;
               Anything           (       QString  & string                ) ;
               Anything           (       char       value                 ) ;
               Anything           (       int        value                 ) ;
               Anything           (       double     value                 ) ;
               Anything           (       TUID       value                 ) ;
               Anything           (       SUID       value                 ) ;
    virtual   ~Anything           ( void                                   ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual Anything & operator = ( const Anything & any                   ) ;
    virtual Anything & operator = (       Anything & any                   ) ;
    virtual Anything & operator = (       QString  & string                ) ;
    virtual Anything & operator = (       char       value                 ) ;
    virtual Anything & operator = (       int        value                 ) ;
    virtual Anything & operator = (       double     value                 ) ;
    virtual Anything & operator = (       TUID       value                 ) ;
    virtual Anything & operator = (       SUID       value                 ) ;
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
}                                                                            ;
//////////////////////////////////////////////////////////////////////////////
typedef QMap<QString,Anything> AlmostAnything                                ;
//////////////////////////////////////////////////////////////////////////////
class Q_QTAITKBASE_EXPORT BooleanArray                                       {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    explicit       BooleanArray ( void                                     ) ;
                   BooleanArray ( const BooleanArray & boolean             ) ;
                   BooleanArray ( int items                                ) ;
    virtual       ~BooleanArray ( void                                     ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual void   clear        ( void                                     ) ;
    virtual void   reset        ( bool value = false                       ) ;
    virtual qint64 items        ( void                               ) const ;
    virtual qint64 size         ( void                               ) const ;
    virtual void * BitsData     ( void                               ) const ;
    virtual qint64 setItems     ( qint64 items                             ) ;
    virtual void   assign       ( const BooleanArray & boolean             ) ;
    virtual qint64 assign       ( qint64          items                      ,
                                  unsigned char * bitArray                   ,
                                  bool            allocation = false       ) ;
    virtual bool   setBool      ( qint64 index , bool value                ) ;
    virtual bool   toggle       ( qint64 index                             ) ;
    virtual bool   operator [ ] ( qint64 index                             ) ;
    virtual bool   at           ( qint64 index                             ) ;
    virtual qint64 FirstFalse   ( qint64 index                             ) ;
    //////////////////////////////////////////////////////////////////////////
    BooleanArray & operator  =  ( const BooleanArray & boolean             ) ;
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
    bool            allocation                                               ;
    qint64          maxBits                                                  ;
    qint64          bits                                                     ;
    qint64          bytes                                                    ;
    unsigned char * bitArray                                                 ;
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
}                                                                            ;
//////////////////////////////////////////////////////////////////////////////
class Q_QTAITKBASE_EXPORT TimeBits : public BooleanArray                     {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    explicit            TimeBits      ( void                               ) ;
                        TimeBits      ( const TimeBits & timeBits          ) ;
    virtual            ~TimeBits      ( void                               ) ;
    //////////////////////////////////////////////////////////////////////////
    static  qint64      sizeHint      ( QDateTime startTime                  ,
                                        QDateTime endTime                    ,
                                        int       dt                       ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual void        setParameters ( QDateTime startTime                  ,
                                        QDateTime realStart                  ,
                                        QDateTime endTime                    ,
                                        int       dt                       ) ;
    virtual void        setBlob       ( int             items                ,
                                        unsigned char * bitArray           ) ;
    virtual QDateTime & TimeValue     ( QString key                        ) ;
    virtual void        setTime       ( QString key , QDateTime time       ) ;
    virtual int         TimeInterval  ( void                         ) const ;
    //////////////////////////////////////////////////////////////////////////
    virtual QDateTime   toDateTime    ( qint64    index                    ) ;
    virtual qint64      toIndex       ( QDateTime time                     ) ;
    virtual bool        setBool       ( QDateTime time , bool value        ) ;
    virtual bool        toggle        ( QDateTime time                     ) ;
    virtual bool        operator [ ]  ( QDateTime time                     ) ;
    virtual bool        at            ( QDateTime time                     ) ;
    //////////////////////////////////////////////////////////////////////////
    TimeBits          & operator  =   ( const TimeBits & timeBits          ) ;
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
    QMap < QString , QDateTime > DateTimes                                   ;
    int                          Interval                                    ;
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
} ;
//////////////////////////////////////////////////////////////////////////////
class Q_QTAITKBASE_EXPORT Enabler                                            {
  ////////////////////////////////////////////////////////////////////////////
  public                                                                     :
    //////////////////////////////////////////////////////////////////////////
    explicit            Enabler      ( bool lock = false                   ) ;
                        Enabler      ( const Enabler & enabler             ) ;
                        Enabler      (       Enabler & enabler             ) ;
    virtual            ~Enabler      ( void                                ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual CUIDs       IntKeys      ( void                                ) ;
    virtual bool        setEnabled   ( int Id , bool enable                ) ;
    virtual bool        hasEnabled   ( int Id                              ) ;
    virtual bool        isEnabled    ( int Id                              ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual bool &      operator [ ] ( int Id                              ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual UUIDs       UuidKeys     ( void                                ) ;
    virtual bool        setEnabled   ( SUID Id , bool enable               ) ;
    virtual bool        hasEnabled   ( SUID Id                             ) ;
    virtual bool        isEnabled    ( SUID Id                             ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual bool &      operator [ ] ( SUID Id                             ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual QStringList StringKeys   ( void                                ) ;
    virtual bool        setEnabled   ( QString Id , bool enable            ) ;
    virtual bool        hasEnabled   ( QString Id                          ) ;
    virtual bool        isEnabled    ( QString Id                          ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual bool &      operator [ ] ( QString Id                          ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual bool        isAllTrue    ( void                                ) ;
    virtual bool        isAllFalse   ( void                                ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual bool        canLock      ( void                                ) ;
    virtual bool        setLock      ( bool lock                           ) ;
    //////////////////////////////////////////////////////////////////////////
    virtual void        ClearEnabler ( void                                ) ;
    //////////////////////////////////////////////////////////////////////////
  protected                                                                  :
    //////////////////////////////////////////////////////////////////////////
  private                                                                    :
    //////////////////////////////////////////////////////////////////////////
    QMutex locker                                                            ;
    bool   shouldLock                                                        ;
    BMAPs  PrivateEnablings                                                  ;
    XMAPs  UuidEnablings                                                     ;
    LMAPs  StringEnablings                                                   ;
    //////////////////////////////////////////////////////////////////////////
    void lockUp  ( void )                                                    ;
    void unleash ( void )                                                    ;
    //////////////////////////////////////////////////////////////////////////
}                                                                            ;
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
#endif
