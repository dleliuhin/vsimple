/****************************************************************************************
**
**  VSIMPLE codebase
**
**  GNU Lesser General Public License Usage
**  This file may be used under the terms of the GNU Lesser General Public License
**  version 3 as published by the Free Software Foundation and appearing in the file
**  LICENSE.LGPL3 included in the packaging of this file. Please review the following
**  information to ensure the GNU Lesser General Public License version 3 requirements
**  will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************************/

/*!
 * \authors Alexander Gromtsev, Dmitrii Leliuhin
 * \date June 2020
 */

//! \todo
//!  Использован linux-овский popen/pclose для чтения подпроцессов. Не особо грамотно,
//!  хотелось бы разобраться, чтобы были грамотные обертки для работы с процессами.

#include "test_vcompiler_traits.h"

#include "vcompiler_traits.h"

#include <iostream>

using namespace std;

//=======================================================================================
TEST( test_vcompiler_traits, test_platform )
{
#ifndef V_PLATFORM_NAME
    ASSERT_DEATH(
                {
                    exit( EXIT_FAILURE );
                }, "Has not V_PLATFORM_NAME macro" );
#endif

#ifndef V_PLATFORM_NAME_STR
    ASSERT_DEATH(
                {
                    exit( EXIT_FAILURE );
                }, "Has not V_PLATFORM_NAME_STR macro" );
#endif

    ASSERT_FALSE( string( V_PLATFORM_NAME_STR ).empty() );
}
//=======================================================================================
TEST( test_vcompiler_traits, test_compiler )
{
#ifndef V_COMPILER_NAME
    ASSERT_DEATH(
                {
                    exit( EXIT_FAILURE );
                }, "Has not V_COMPILER_NAME macro" );
#endif

#ifndef V_COMPILER_NAME_STR
    ASSERT_DEATH(
                {
                    exit( EXIT_FAILURE );
                }, "Has not V_COMPILER_NAME_STR macro" );
#endif

    ASSERT_FALSE( string( V_COMPILER_NAME_STR ).empty() );
}
//=======================================================================================
TEST( test_vcompiler_traits, test_endian )
{
    constexpr bool big    = v::endian::is_big();
    constexpr bool little = v::endian::is_little();

    ASSERT_NE( big, little );

    constexpr uint32_t val = 0x12345678;

    const uint32_t rev = big
                         ? v::endian::to_little_endian( val )
                         : v::endian::to_big_endian( val );

    ASSERT_TRUE( rev == 0x78563412 );

    const uint32_t same = little
                          ? v::endian::to_little_endian( val )
                          : v::endian::to_big_endian( val );

    ASSERT_TRUE( same == 0x12345678 );

    const auto rev2 = v::endian::reverse_val( val );

    ASSERT_TRUE( rev2 == 0x78563412 );
}
//=======================================================================================
