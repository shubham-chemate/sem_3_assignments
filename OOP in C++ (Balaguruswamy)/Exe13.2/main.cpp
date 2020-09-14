#include <iostream>

using namespace std;

void test(int x)
{
    try
    {
        if(x == 1) throw x;
        else if(x == 0) throw 'x';
        else if(x == -1) throw 1.0;
        cout << "End of try block.\n";
    }
    catch(char c)
    {
        cout << "Cough char\n";
    }
    catch(int c)
    {
        cout << "Cough int\n";
    }
    catch(double c)
    {
        cout << "Cough double\n";
    }
    cout << "End of try-catch system.\n\n";
}

int main()
{
    cout << "Resting Multiple catches.\n" << endl;
    test(1);
    test(0);
    test(-1);
    test(2);
    return 0;
}
