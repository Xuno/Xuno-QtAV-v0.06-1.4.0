/******************************************************************************
    QtAV:  Media play library based on Qt and FFmpeg
    Copyright (C) 2012-2014 Wang Bin <wbsecg1@gmail.com>

*   This file is part of QtAV

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
******************************************************************************/


#ifndef QTAV_GLOBAL_H
#define QTAV_GLOBAL_H

#include <stdarg.h>
#include <qglobal.h>
#include "dptr.h"

#if defined(BUILD_QTAV_LIB)
#  undef Q_AV_EXPORT
#  define Q_AV_EXPORT Q_DECL_EXPORT
#else
#  undef Q_AV_EXPORT
#  define Q_AV_EXPORT Q_DECL_IMPORT //only for vc?
#endif
#define Q_AV_PRIVATE_EXPORT Q_AV_EXPORT


/* runtime version. used to compare with compile time version */
Q_AV_EXPORT unsigned QtAV_Version();
Q_AV_EXPORT QString QtAV_Version_String();
Q_AV_EXPORT QString QtAV_Version_String_Long();
Q_AV_EXPORT QString XUNO_QtAV_Version_String();
Q_AV_EXPORT QString XUNO_QtAV_Version_String_Long();

namespace QtAV {

enum LogLevel {
    LogOff = -1,
    LogDefault = 0,
    LogDebug,
    LogWarning,
    LogCritical,
    LogFatal,
    LogAll
};

Q_AV_EXPORT void about(); //popup a dialog
Q_AV_EXPORT void aboutFFmpeg();
Q_AV_EXPORT QString aboutFFmpeg_PlainText();
Q_AV_EXPORT QString aboutFFmpeg_HTML();
Q_AV_EXPORT void aboutQtAV();
Q_AV_EXPORT QString aboutQtAV_PlainText();
Q_AV_EXPORT QString aboutQtAV_HTML();

Q_AV_EXPORT void setLogLevel(LogLevel value);
Q_AV_EXPORT LogLevel logLevel();

Q_AV_EXPORT void setFFmpegLogHandler(void(*)(void *, int, const char *, va_list));

} //namespace QtAV

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#define QStringLiteral(X) QString::fromUtf8(X)
#endif //QT_VERSION
/*
 * msvc sucks! can not deal with (defined QTAV_HAVE_##FEATURE && QTAV_HAVE_##FEATURE)
 */
#define QTAV_HAVE(FEATURE) (defined QTAV_HAVE_##FEATURE && QTAV_HAVE_##FEATURE)

//TODO: always inline
/* --gnu option of the RVCT compiler also defines __GNUC__ */
#if defined(Q_CC_GNU) && !defined(Q_CC_RVCT)
#define GCC_VERSION_AT_LEAST(major, minor, patch) \
    (__GNUC__ > major || (__GNUC__ == major && (__GNUC_MINOR__ > minor \
    || (__GNUC_MINOR__ == minor && __GNUC_PATCHLEVEL__ >= patch))))
#else
/* Define this for !GCC compilers, just so we can write things like GCC_VERSION_AT_LEAST(4, 1, 0). */
#define GCC_VERSION_AT_LEAST(major, minor, patch) 0
#endif

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0) || defined(QT_WIDGETS_LIB)
#ifndef QTAV_HAVE_WIDGETS
#define QTAV_HAVE_WIDGETS 1
#endif //QTAV_HAVE_WIDGETS
#endif

#ifndef Q_DECL_OVERRIDE
#define Q_DECL_OVERRIDE
#endif
#ifndef Q_DECL_FINAL
#define Q_DECL_FINAL
#endif

#ifndef Q_FUNC_INFO
#define Q_FUNC_INFO __FUNCTION__
#endif

#if defined(BUILD_QTAV_LIB)
#include "utils/Logger.h"
//#undef qDebug()
#endif //BUILD_QTAV_LIB

#endif // QTAV_GLOBAL_H

