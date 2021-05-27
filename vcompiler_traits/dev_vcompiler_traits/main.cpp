#include <iostream>

#include "vcompiler_traits.h"


using namespace std;

int main()
{
    cout << "V_COMPILER_NAME_STR: " << V_COMPILER_NAME_STR << endl;
    cout << "V_PLATFORM_NAME_STR: " << V_PLATFORM_NAME_STR << endl;

    cout << "V_PRETTY_FUNCTION: "   << V_PRETTY_FUNCTION   << endl;

    cout << "is big endian: "    << v::endian::is_big()    << endl;
    cout << "is little endian: " << v::endian::is_little() << endl;

    return 0;
}
