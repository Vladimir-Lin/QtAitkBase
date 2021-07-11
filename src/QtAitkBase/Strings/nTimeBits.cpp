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
//////////////////////////////////////////////////////////////////////////////
#include "qtaitkbase.h"
//////////////////////////////////////////////////////////////////////////////
QT_BEGIN_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
N::TimeBits:: TimeBits     (void)
            : BooleanArray (    )
            , Interval     (3600)
{
}

N::TimeBits:: TimeBits     ( const TimeBits & timeBits )
            : BooleanArray (                           )
            , Interval     ( 3600                      )
{
  DateTimes = timeBits . DateTimes  ;
  Interval  = timeBits . Interval   ;
  BooleanArray::assign ( timeBits ) ;
}

N::TimeBits::~TimeBits (void)
{
}

qint64 N::TimeBits::sizeHint (
         QDateTime startTime ,
         QDateTime endTime   ,
         int       dt        )
{
  qint64 rt                            ;
  rt  = startTime . secsTo ( endTime ) ;
  rt += ( dt - 1 )                     ;
  if ( dt <= 0 ) return rt             ;
  rt /= dt                             ;
  return rt                            ;
}

int N::TimeBits::TimeInterval(void) const
{
  return Interval ;
}

void N::TimeBits::setParameters (
       QDateTime startTime      ,
       QDateTime realStart      ,
       QDateTime endTime        ,
       int       dt             )
{
  DateTimes [ "Start" ] = startTime ;
  DateTimes [ "Real"  ] = realStart ;
  DateTimes [ "End"   ] = endTime   ;
  Interval              = dt        ;
}

void N::TimeBits::setBlob(int items,unsigned char * bitArray)
{
  assign ( items , bitArray , false ) ;
}

QDateTime & N::TimeBits::TimeValue(QString key)
{
  return DateTimes [ key ] ;
}

void N::TimeBits::setTime(QString key,QDateTime dt)
{
  DateTimes [ key ] = dt ;
}

QDateTime N::TimeBits::toDateTime(qint64 index)
{
  QDateTime ST = DateTimes [ "Start" ] ;
  qint64 ds = index                    ;
  ds *= Interval                       ;
  ST  = ST . addSecs ( ds )            ;
  return ST                            ;
}

qint64 N::TimeBits::toIndex(QDateTime time)
{
  qint64 ds                                     ;
  ds  = DateTimes [ "Start" ] . secsTo ( time ) ;
  ds /= Interval                                ;
  return ds                                     ;
}

bool N::TimeBits::setBool(QDateTime t,bool v)
{
  return BooleanArray::setBool ( toIndex ( t ) , v ) ;
}

bool N::TimeBits::toggle(QDateTime t)
{
  return BooleanArray::toggle ( toIndex ( t ) ) ;
}

bool N::TimeBits::operator [ ] (QDateTime t)
{
  return at ( t ) ;
}

bool N::TimeBits::at(QDateTime t)
{
  return BooleanArray::at ( toIndex ( t ) ) ;
}

N::TimeBits & N::TimeBits::operator = (const TimeBits & timeBits)
{
  DateTimes = timeBits . DateTimes  ;
  Interval  = timeBits . Interval   ;
  BooleanArray::assign ( timeBits ) ;
  return ( *this )                  ;
}

//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////

