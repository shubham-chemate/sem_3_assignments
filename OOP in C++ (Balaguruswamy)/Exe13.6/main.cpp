#include <iostream>
#include <typeinfo>

using namespace std;

class random
{
private:
    double x, y;
public:
    void setData()
    {
        try
        {
            cout << "Enter two values: \n";
            cin >> x >> y;
            cout << typeid(x).name() << endl;
            cout << typeid(y).name() << endl;
            if(typeid(x).name() != "d" || typeid(y).name() != "d"){
                throw(0);
            }
        }
        catch(int)
        {
            cout << "ERROR: Type doesn't matches.\n";
            throw;
        }
    }
    void divide()
    {
        try
        {
            if(y == 0) throw 0;
            else {
                cout << "Division: " << x/y;
            }
        }
        catch(int)
        {
            cout << "ERROR: Divide by zero.\n\n";
        }
    }
};

int main()
{
    random r;
    try
    {
        r.setData();
        r.divide();
    }
    catch(int)
    {
        cout << "Program ends now.\n";
    }
    return 0;
}
