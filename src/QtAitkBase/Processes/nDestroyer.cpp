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
N::Destroyer:: Destroyer ( void )                                            {
}
//////////////////////////////////////////////////////////////////////////////
N::Destroyer::~Destroyer ( void )                                            {
}
//////////////////////////////////////////////////////////////////////////////
bool N::Destroyer::Recycling ( void )                                        {
  return true                                                                ;
}
//////////////////////////////////////////////////////////////////////////////
bool N::Destroyer::Destructor ( void )                                       {
  return true                                                                ;
}
//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
