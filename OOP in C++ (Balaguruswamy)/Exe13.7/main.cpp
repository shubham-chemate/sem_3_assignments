#include <iostream>

using namespace std;

void random(int n)
{
    cout << n << endl;
    if(n==0) throw 0;
    random(n-2);
}

int main()
{
    try
    {
        random(16);
    }
    catch(int)
    {
        cout << "Catched.\n";
    }
    return 0;
}
