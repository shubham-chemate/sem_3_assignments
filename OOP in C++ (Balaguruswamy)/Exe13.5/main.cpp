#include <iostream>

using namespace std;

void divide(double x, double y)
{
    cout << "Inside Function.\n";
    try
    {
        if(y == 0.0){throw y;}
        else{
            cout << "Division = " << x/y << endl;
        }
    }
    catch(double)
    {
        cout << "Cough double inside function\n";
        throw;
    }
    cout << "End of Function.\n\n";
}

int main()
{
    cout << "Inside main\n" << endl;
    try
    {
        divide(10.5, 2.0);
        divide(20.0, 0.0);
    }
    catch(double)
    {
        cout << "Cough double inside main\n";
    }
    cout << "End of main \n";
    return 0;
}
