#include <iostream>

using namespace std;

class A
{
    int a;
public:
    void seta(int n)
    {
        if(n == 0) throw 0;
        a = n;
    }
    void showa()
    {
        cout << "a: " << a << endl;
    }
};

class B : public A
{
    int b;
public:
    void setVal(int m, int n)
    {
        try
        {
            b = m;
            seta(n);
        }
        catch(int)
        {
            cout << "ERROR: n is zero.\n";
            throw;
        }
    }
    void show()
    {
        showa();
        cout << "b: " << b << endl;
    }
};

int main()
{

    B b;
    try
    {
        b.setVal(3, 0);
        b.show();
    }
    catch(int)
    {
        cout << "Program terminated.\n";
    }
    return 0;
}
