/****************************************************************************************
**
**  GNU Lesser General Public License Usage
**  This file may be used under the terms of the GNU Lesser General Public License
**  version 3 as published by the Free Software Foundation and appearing in the file
**  LICENSE.LGPL3 included in the packaging of this file. Please review the following
**  information to ensure the GNU Lesser General Public License version 3 requirements
**  will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
****************************************************************************************/

#ifndef VSIMPLE_VPRETTY_FUNCTION_H
#define VSIMPLE_VPRETTY_FUNCTION_H

#include "details/vplatform.h"

//=======================================================================================

#if( defined(V_COMPILER_MINGW) || defined(V_COMPILER_GNU) )

    #define V_PRETTY_FUNCTION __PRETTY_FUNCTION__

#elif( defined(V_COMPILER_MSVC) )

    #define V_PRETTY_FUNCTION __FUNCSIG__
#else
    //  It is the 11th stantard.
    #define V_PRETTY_FUNCTION __func__
#endif

//=======================================================================================

#endif // VSIMPLE_VPRETTY_FUNCTION_H
