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
#include <QtCore>
//////////////////////////////////////////////////////////////////////////////
QT_BEGIN_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
#ifndef QT_STATIC
#    if defined(QT_BUILD_QTUUID_LIB)
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
//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
#endif
