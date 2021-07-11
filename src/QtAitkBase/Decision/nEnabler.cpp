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
#include "qtaitkamacros.h"
#include "qtaitkanamespaces.h"
#include "qtaitkbase.h"
//////////////////////////////////////////////////////////////////////////////
QT_BEGIN_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
N::Enabler:: Enabler    ( bool lock                                          )
           : shouldLock (      lock                                          )
{
}
//////////////////////////////////////////////////////////////////////////////
N::Enabler:: Enabler          ( const Enabler & enabler                      )
           : shouldLock       ( enabler . shouldLock                         )
           , PrivateEnablings ( enabler . PrivateEnablings                   )
           , UuidEnablings    ( enabler . UuidEnablings                      )
           , StringEnablings  ( enabler . StringEnablings                    )
{
}
//////////////////////////////////////////////////////////////////////////////
N::Enabler:: Enabler          ( Enabler & enabler                            )
           : shouldLock       ( enabler . shouldLock                         )
           , PrivateEnablings ( enabler . PrivateEnablings                   )
           , UuidEnablings    ( enabler . UuidEnablings                      )
           , StringEnablings  ( enabler . StringEnablings                    )
{
}
//////////////////////////////////////////////////////////////////////////////
N::Enabler::~Enabler ( void )                                                {
}
//////////////////////////////////////////////////////////////////////////////
void N::Enabler::ClearEnabler ( void )                                       {
  PrivateEnablings . clear    (      )                                       ;
  UuidEnablings    . clear    (      )                                       ;
  StringEnablings  . clear    (      )                                       ;
}
//////////////////////////////////////////////////////////////////////////////
CUIDs N::Enabler::IntKeys ( void )                                           {
  return PrivateEnablings . keys ( )                                         ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::setEnabled ( int Id , bool enable )                         {
  lockUp  ( )                                                                ;
  PrivateEnablings [ Id ] = enable                                           ;
  unleash ( )                                                                ;
  return enable                                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::hasEnabled          ( int Id )                              {
  return PrivateEnablings . contains ( Id     )                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::isEnabled ( int Id )                                        {
  if ( ! hasEnabled ( Id ) ) return false                                    ;
  return PrivateEnablings [ Id ]                                             ;
}
//////////////////////////////////////////////////////////////////////////////
bool & N::Enabler::operator [ ] ( int Id )                                   {
  if ( ! hasEnabled ( Id ) )                                                 {
    PrivateEnablings [ Id ] = false                                          ;
  }                                                                          ;
  return PrivateEnablings [ Id ]                                             ;
}
//////////////////////////////////////////////////////////////////////////////
UUIDs N::Enabler::UuidKeys ( void )                                          {
  return UuidEnablings . keys ( )                                            ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::setEnabled ( SUID Id , bool enable )                        {
  lockUp  ( )                                                                ;
  UuidEnablings [ Id ] = enable                                              ;
  unleash ( )                                                                ;
  return enable                                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::hasEnabled       ( SUID Id )                                {
  return UuidEnablings . contains ( Id      )                                ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::isEnabled ( SUID Id )                                       {
  if ( ! hasEnabled ( Id ) ) return false                                    ;
  return UuidEnablings [ Id ]                                                ;
}
//////////////////////////////////////////////////////////////////////////////
bool & N::Enabler::operator [ ] ( SUID Id )                                  {
  if ( ! hasEnabled ( Id ) )                                                 {
    UuidEnablings [ Id ] = false                                             ;
  }                                                                          ;
  return UuidEnablings [ Id ]                                                ;
}
//////////////////////////////////////////////////////////////////////////////
QStringList N::Enabler::StringKeys ( void )                                  {
  return StringEnablings . keys    (      )                                  ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::setEnabled ( QString Id , bool enable )                     {
  lockUp  ( )                                                                ;
  StringEnablings [ Id ] = enable                                            ;
  unleash ( )                                                                ;
  return enable                                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::hasEnabled         ( QString Id )                           {
  return StringEnablings . contains (         Id )                           ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::isEnabled ( QString Id )                                    {
  if ( ! hasEnabled ( Id ) ) return false                                    ;
  return StringEnablings [ Id ]                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool & N::Enabler::operator [ ] ( QString Id )                               {
  if ( ! hasEnabled ( Id ) )                                                 {
    StringEnablings [ Id ] = false                                           ;
  }                                                                          ;
  return StringEnablings [ Id ]                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::isAllTrue ( void )                                          {
  bool result = false                                                        ;
  lockUp  ( )                                                                ;
  if ( PrivateEnablings . count ( ) > 0 )                                    {
    CUIDs       IDs = PrivateEnablings . keys ( )                            ;
    int         id                                                           ;
    foreach ( id , IDs )                                                     {
      if ( ! PrivateEnablings [ id ] ) return false                          ;
    }                                                                        ;
    result = true                                                            ;
  }                                                                          ;
  if ( UuidEnablings    . count ( ) > 0 )                                    {
    UUIDs       IDs = UuidEnablings    . keys ( )                            ;
    SUID        id                                                           ;
    foreach ( id , IDs )                                                     {
      if ( ! UuidEnablings    [ id ] ) return false                          ;
    }                                                                        ;
    result = true                                                            ;
  }                                                                          ;
  if ( StringEnablings  . count ( ) > 0 )                                    {
    QStringList IDs = StringEnablings . keys ( )                             ;
    QString     id                                                           ;
    foreach ( id , IDs )                                                     {
      if ( ! StringEnablings  [ id ] ) return false                          ;
    }                                                                        ;
    result = true                                                            ;
  }                                                                          ;
  unleash ( )                                                                ;
  return result                                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::isAllFalse ( void )                                         {
  bool result = false                                                        ;
  lockUp  ( )                                                                ;
  if ( PrivateEnablings . count ( ) > 0 )                                    {
    CUIDs       IDs = PrivateEnablings . keys ( )                            ;
    int         id                                                           ;
    foreach ( id , IDs )                                                     {
      if ( PrivateEnablings [ id ] ) return false                            ;
    }                                                                        ;
    result = true                                                            ;
  }                                                                          ;
  if ( UuidEnablings    . count ( ) > 0 )                                    {
    UUIDs       IDs = UuidEnablings    . keys ( )                            ;
    SUID        id                                                           ;
    foreach ( id , IDs )                                                     {
      if ( UuidEnablings    [ id ] ) return false                            ;
    }                                                                        ;
    result = true                                                            ;
  }                                                                          ;
  if ( StringEnablings  . count ( ) > 0 )                                    {
    QStringList IDs = StringEnablings . keys ( )                             ;
    QString     id                                                           ;
    foreach ( id , IDs )                                                     {
      if ( StringEnablings  [ id ] ) return false                            ;
    }                                                                        ;
    result = true                                                            ;
  }                                                                          ;
  unleash ( )                                                                ;
  return result                                                              ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::canLock ( void )                                            {
  return shouldLock                                                          ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Enabler::setLock ( bool lock )                                       {
  shouldLock = lock                                                          ;
  return shouldLock                                                          ;
}
//////////////////////////////////////////////////////////////////////////////
void N::Enabler::lockUp ( void )                                             {
  if ( ! shouldLock ) return                                                 ;
  locker . lock   ( )                                                        ;
}
//////////////////////////////////////////////////////////////////////////////
void N::Enabler::unleash ( void )                                            {
  if ( ! shouldLock ) return                                                 ;
  locker . unlock ( )                                                        ;
}
//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
