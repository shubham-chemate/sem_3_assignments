#include <iostream>

using namespace std;

int main()
{
    cout << "Enter two numbers to divide(x/y):\n";
    float x, y;
    cin >> x >> y;
    try
    {
        if(y == 0){throw(0);}
        cout << "Result: " << x / y;
    }
    catch(int)
    {
        cout << "ERROR: Division by zero.\n";
    }
    return 0;
}
