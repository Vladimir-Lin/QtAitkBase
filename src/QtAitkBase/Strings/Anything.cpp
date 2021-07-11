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
N::Anything:: Anything ( void )                                              {
  uuid = 0                 ;
  type = 0                 ;
  solo = QVariant::Invalid ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything:: Anything (const Anything & any)
{
  nMemberCopy ( any , uuid       ) ;
  nMemberCopy ( any , type       ) ;
  nMemberCopy ( any , solo       ) ;
  nMemberCopy ( any , strings    ) ;
  nMemberCopy ( any , arguments  ) ;
  nMemberCopy ( any , commands   ) ;
  nMemberCopy ( any , arrays     ) ;
  nMemberCopy ( any , locators   ) ;
  nMemberCopy ( any , partitions ) ;
}

N::Anything:: Anything (Anything & any)
{
  nMemberCopy ( any , uuid       ) ;
  nMemberCopy ( any , type       ) ;
  nMemberCopy ( any , solo       ) ;
  nMemberCopy ( any , strings    ) ;
  nMemberCopy ( any , arguments  ) ;
  nMemberCopy ( any , commands   ) ;
  nMemberCopy ( any , arrays     ) ;
  nMemberCopy ( any , locators   ) ;
  nMemberCopy ( any , partitions ) ;
}

N::Anything:: Anything (QString & string)
{
  uuid = 0                 ;
  type = 0                 ;
  solo = QVariant::String  ;
  arguments << string      ;
}

N::Anything:: Anything (char value)
{
  uuid = 0                  ;
  type = 0                  ;
  solo = QVariant::Char     ;
  arguments << QChar(value) ;
}

N::Anything:: Anything (int value)
{
  uuid = 0             ;
  type = 0             ;
  solo = QVariant::Int ;
  arguments << value   ;
}

N::Anything:: Anything (double value)
{
  uuid = 0                ;
  type = 0                ;
  solo = QVariant::Double ;
  arguments << value      ;
}

N::Anything:: Anything (TUID value)
{
  uuid = 0                  ;
  type = 0                  ;
  solo = QVariant::LongLong ;
  arguments << value        ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything:: Anything (SUID value)
{
  uuid = 0                   ;
  type = 0                   ;
  solo = QVariant::ULongLong ;
  arguments << value         ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything::~Anything (void)
{
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (const Anything & any)
{
  nMemberCopy ( any , uuid       ) ;
  nMemberCopy ( any , type       ) ;
  nMemberCopy ( any , solo       ) ;
  nMemberCopy ( any , strings    ) ;
  nMemberCopy ( any , arguments  ) ;
  nMemberCopy ( any , commands   ) ;
  nMemberCopy ( any , arrays     ) ;
  nMemberCopy ( any , locators   ) ;
  nMemberCopy ( any , partitions ) ;
  return ME                        ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (Anything & any)
{
  nMemberCopy ( any , uuid       ) ;
  nMemberCopy ( any , type       ) ;
  nMemberCopy ( any , solo       ) ;
  nMemberCopy ( any , strings    ) ;
  nMemberCopy ( any , arguments  ) ;
  nMemberCopy ( any , commands   ) ;
  nMemberCopy ( any , arrays     ) ;
  nMemberCopy ( any , locators   ) ;
  nMemberCopy ( any , partitions ) ;
  return ME                        ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (QString & string)
{
  arguments  . clear ( )  ;
  solo = QVariant::String ;
  arguments << string     ;
  return ME               ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (char value)
{
  arguments  . clear ( )    ;
  solo = QVariant::Char     ;
  arguments << QChar(value) ;
  return ME                 ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (int value)
{
  arguments  . clear ( ) ;
  solo = QVariant::Int   ;
  arguments << value     ;
  return ME              ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (double value)
{
  arguments  . clear ( )  ;
  solo = QVariant::Double ;
  arguments << value      ;
  return ME               ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (TUID value)
{
  arguments  . clear ( )    ;
  solo = QVariant::LongLong ;
  arguments << value        ;
  return ME                 ;
}
//////////////////////////////////////////////////////////////////////////////
N::Anything & N::Anything::operator = (SUID value)
{
  arguments  . clear ( )     ;
  solo = QVariant::ULongLong ;
  arguments << value         ;
  return ME                  ;
}
//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
