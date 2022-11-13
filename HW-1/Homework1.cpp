#include "b.h"  // This also includes a.h

int main()
{
    // Function test() is part of the a.h header which is included in the b.h header
    test();

    // Function boo() is part of the b.h header
    boo();

    return 0;
}