/****************************************************************************************
**
**  VLIBS codebase, NIIAS
**
**  GNU Lesser General Public License Usage
**  This file may be used under the terms of the GNU Lesser General Public License
**  version 3 as published by the Free Software Foundation and appearing in the file
**  LICENSE.LGPL3 included in the packaging of this file. Please review the following
**  information to ensure the GNU Lesser General Public License version 3 requirements
**  will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************************/

// TODO!
//  Использован linux-овский popen/pclose для чтения подпроцессов. Не особо грамотно,
//  хотелось бы разобраться, чтобы были грамотные обертки для работы с процессами.

#include "gtest/gtest.h"
#include <iostream>

#include "vcompiler_traits.h"
using namespace std;

//=======================================================================================
void test_platform()
{
    #ifndef V_PLATFORM_NAME
        cout << "Has not V_PLATFORM_NAME macro" << endl;
        exit(1);
    #endif

    #ifndef V_PLATFORM_NAME_STR
        cout << "Has not V_PLATFORM_NAME_STR macro" << endl;
        exit(1);
    #endif

    cout << "V_PLATFORM_NAME_STR: " << V_PLATFORM_NAME_STR << endl;
}
//=======================================================================================
void test_compiler()
{
    #ifndef V_COMPILER_NAME
        cout << "Has not V_COMPILER_NAME macro" << endl;
        exit(1);
    #endif

    #ifndef V_COMPILER_NAME_STR
        cout << "Has not V_COMPILER_NAME_STR macro" << endl;
        exit(1);
    #endif

    cout << "V_COMPILER_NAME_STR: " << V_COMPILER_NAME_STR << endl;
}
//=======================================================================================
void test_endian()
{
    bool big    = v::endian::is_big();
    bool little = v::endian::is_little();

    if ( big && little )
    {
        cout << "big && little" << endl;
        exit(1);
    }
    if ( !big && !little )
    {
        cout << "!big && !little" << endl;
        exit(1);
    }

    const uint32_t val = 0x12345678;
    uint32_t rev = big ? v::endian::to_little_endian( val )
                       : v::endian::to_big_endian( val );

    if ( rev != 0x78563412 )
    {
        cout << "Bad reverse value: " << rev << endl;
        exit(1);
    }

    uint32_t same = little ? v::endian::to_little_endian( val )
                           : v::endian::to_big_endian( val );

    if ( same != 0x12345678 )
    {
        cout << "Bad same value: " << same << endl;
        exit(1);
    }

    auto rev2 = v::endian::reverse_val( val );
    if ( rev2 != 0x78563412 )
    {
        cout << "Bad reverse value: " << rev << endl;
        exit(1);
    }
    cout << "v::endian is OK" << endl;
}
//=======================================================================================


//=======================================================================================
int main()
{
    test_platform();
    test_compiler();
    test_endian();

    return 0;
}
//=======================================================================================
