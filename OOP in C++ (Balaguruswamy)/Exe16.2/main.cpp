#include <iostream>

using namespace std;

namespace Constant
{
    const int i = 5;
    const int j = 7;
}

using namespace Constant;

int main()
{
    cout << i*j;
    return 0;
}
