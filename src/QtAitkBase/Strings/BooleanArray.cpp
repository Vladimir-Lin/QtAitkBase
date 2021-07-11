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


#include <essentials.h>

#if   defined(CLF_NAMESPACE)
using namespace CLF ;
#elif defined(LF_NAMESPACE)
using namespace LF  ;
#else
using namespace N   ;
#endif

#ifdef CLF_ALIGNMENT
#define BA_ALIGNMENT CLF_ALIGNMENT
#else
// default 64 bits alignment
#define BA_ALIGNMENT 64
#endif

BooleanArray:: BooleanArray ( void  )
             : allocation   ( false )
             , maxBits      ( 0     )
             , bits         ( 0     )
             , bytes        ( 0     )
             , bitArray     ( NULL  )
{
}

BooleanArray:: BooleanArray ( const BooleanArray & boolean )
             : allocation   ( false                        )
             , maxBits      ( 0                            )
             , bits         ( 0                            )
             , bytes        ( 0                            )
             , bitArray     ( NULL                         )
{
  assign ( boolean ) ;
}

BooleanArray:: BooleanArray ( int items )
             : allocation   ( false     )
             , maxBits      ( 0         )
             , bits         ( 0         )
             , bytes        ( 0         )
             , bitArray     ( NULL      )
{
  setItems ( items ) ;
  reset    ( false ) ;
}

BooleanArray::~BooleanArray (void)
{
  if ( allocation )     {
    delete [ ] bitArray ;
  }                     ;
  bitArray = NULL       ;
}

void BooleanArray::clear(void)
{
  if ( allocation )     {
    delete [ ] bitArray ;
  }                     ;
  allocation = false    ;
  maxBits    = 0        ;
  bits       = 0        ;
  bytes      = 0        ;
  bitArray   = NULL     ;
}

void BooleanArray::reset(bool value)
{
  if ( bytes <= 0 ) return          ;
  unsigned char v = 0               ;
  if (value) v = 0xFF               ;
  ::memset ( bitArray , v , bytes ) ;
}

qint64 BooleanArray::items(void) const
{
  return maxBits ;
}

qint64 BooleanArray::size(void) const
{
  return bytes ;
}

void * BooleanArray::BitsData(void) const
{
  return (void *) bitArray ;
}

qint64 BooleanArray::setItems(qint64 items)
{
  if ( items <= 0 ) return 0                                       ;
  bool            alloc    = allocation                            ;
  qint64          oldBytes = bytes                                 ;
  unsigned char * oldArray = bitArray                              ;
  allocation = true                                                ;
  maxBits    = items                                               ;
  bytes      = 8 * ( ( items + BA_ALIGNMENT - 1 ) / BA_ALIGNMENT ) ;
  bits       = 8 * bytes                                           ;
  bitArray   = new unsigned char [ bytes ]                         ;
  if ( ( oldBytes > 0 ) && ( NULL != oldArray ) )                  {
    if ( oldBytes > bytes ) oldBytes = bytes                       ;
    ::memcpy ( bitArray , oldArray , oldBytes )                    ;
    if ( alloc ) delete [] oldArray                                ;
  }                                                                ;
  return bytes                                                     ;
}

void BooleanArray::assign(const BooleanArray & boolean)
{
  if ( allocation ) delete [] bitArray               ;
  allocation = boolean . allocation                  ;
  maxBits    = boolean . maxBits                     ;
  bits       = boolean . bits                        ;
  bytes      = boolean . bytes                       ;
  if ( allocation )                                  {
    bitArray = new unsigned char [ bytes ]           ;
    ::memcpy ( bitArray , boolean.bitArray , bytes ) ;
  } else                                             {
    bitArray = boolean . bitArray                    ;
  }                                                  ;
}

qint64 BooleanArray::assign(qint64 items,unsigned char * BitArray,bool alloc)
{
  allocation = alloc                                               ;
  maxBits    = items                                               ;
  bytes      = 8 * ( ( items + BA_ALIGNMENT - 1 ) / BA_ALIGNMENT ) ;
  bits       = 8 * bytes                                           ;
  bitArray   = BitArray                                            ;
  return items                                                     ;
}

bool BooleanArray::setBool(qint64 index,bool value)
{
  #ifdef CLF_ACCELERATION
  #else
  if ( NULL  == bitArray ) return false ;
  if ( index >= maxBits  ) return false ;
  #endif
  unsigned char mask   = 1              ;
  qint64        shift  = index % 8      ;
  qint64        at     = index / 8      ;
  #ifdef CLF_ACCELERATION
  #else
  if ( at >= bytes ) return false       ;
  #endif
  if ( shift > 0 ) mask <<= shift       ;
  if ( value )                          {
    bitArray [ at ] |= mask             ;
  } else                                {
    mask            ^= 0xFF             ;
    bitArray [ at ] &= mask             ;
  }                                     ;
  return value                          ;
}

bool BooleanArray::toggle(qint64 index)
{
  #ifdef CLF_ACCELERATION
  #else
  if ( NULL  == bitArray ) return false ;
  if ( index >= maxBits  ) return false ;
  #endif
  bool          result = false          ;
  unsigned char mask   = 1              ;
  unsigned char blob   = 0              ;
  qint64        shift  = index % 8      ;
  qint64        at     = index / 8      ;
  #ifdef CLF_ACCELERATION
  #else
  if ( at >= bytes ) return false       ;
  #endif
  if ( shift > 0 ) mask <<= shift       ;
  bitArray [ at ] ^= mask               ;
  blob   = bitArray [ at ]              ;
  result = ( ( blob & mask ) == mask )  ;
  return result                         ;
}

bool BooleanArray::operator [] (qint64 index)
{
  return at ( index ) ;
}

bool BooleanArray::at(qint64 index)
{
  #ifdef CLF_ACCELERATION
  #else
  if ( NULL  == bitArray ) return false ;
  if ( index >= maxBits  ) return false ;
  #endif
  bool          result = false          ;
  unsigned char mask   = 1              ;
  unsigned char blob   = 0              ;
  qint64        shift  = index % 8      ;
  qint64        at     = index / 8      ;
  #ifdef CLF_ACCELERATION
  #else
  if ( at >= bytes ) return false       ;
  #endif
  if ( shift > 0 ) mask <<= shift       ;
  blob   = bitArray [ at ]              ;
  result = ( ( blob & mask ) == mask )  ;
  return result                         ;
}

qint64 BooleanArray::FirstFalse(qint64 index)
{
  if ( ! at ( index ) ) return index             ;
  ////////////////////////////////////////////////
  index++                                        ;
  if ( 0 != ( index % 64 ) )                     {
    qint64 eid = index                           ;
    eid += 63                                    ;
    eid /= 64                                    ;
    eid *= 64                                    ;
    for (qint64 i=index;i<eid;i++)               {
      if ( i < maxBits )                         {
        if ( ! at ( i ) ) return i               ;
      } else return -1                           ;
      index ++                                   ;
    }                                            ;
  }                                              ;
  ////////////////////////////////////////////////
  quint64 * flags = (quint64 *) bitArray         ;
  qint64    pos   = index                        ;
  pos /= 64                                      ;
  while ( index < maxBits )                      {
    if ( 0xFFFFFFFFFFFFFFFFLL != flags [ pos ] ) {
      qint64 eid = index + 64                    ;
      for (qint64 i=index;i<eid;i++)             {
        if ( i < maxBits )                       {
          if ( ! at ( i ) ) return i             ;
        } else return -1                         ;
      }                                          ;
    }                                            ;
    pos   ++                                     ;
    index += 64                                  ;
  }                                              ;
  ////////////////////////////////////////////////
  return index                                   ;
}

BooleanArray & BooleanArray::operator = (const BooleanArray & boolean)
{
  assign ( boolean ) ;
  return ( *this   ) ;
}

//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
