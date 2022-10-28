// Program Description:  C++ type (class) that can hold unlimited decimal integer
//                       values and performs arithmetic operations on them.

// Examples: 101 + 200 = 301
//           200 - 100 = 100
//           -300 - 100 = -400
//           1000 - 100 = 0
//           1000 - (-100) = 1100
//           2010 + (-10) = 2000
//           2000 - 1 = 1999
//           3000 - 10000 = -7000
//           800 + 20 = 820
//           100 + 1300 = 1400


#include <iostream>
#include "BigDecimal.h"
#include "BigDecimal.cpp"
using namespace std;

int main()
{
    BigDecimalInt a("100"), b("-1");
    cout << (a - b) << endl;
    return 0;
}

