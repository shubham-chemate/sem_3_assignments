#include <iostream>

using namespace std;

void test(int x)
{
    if(x == 0) {throw x;}
    if(x == -1) {throw 'x';}
    if(x == 1) {throw 1.0;}
}

int main()
{
    try
    {
        //test(0);
        test(-1);
        test(1);
    }
    catch(...)
    {
        cout << "Catched an exception.\n";
    }

    return 0;
}
