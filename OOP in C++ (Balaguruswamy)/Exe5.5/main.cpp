#include <iostream>

using namespace std;

class DB;

class DM
{
private:
    float m;
    float cm;
public:
    void setData()
    {
        cout << "Enter meters: " << endl;
        cin >> m;
        cout << "Enter centimeter: " << endl;
        cin >> cm;
    }
    friend void add(DM obj1, DB obj2);
};
class DB
{
private:
    float ft;
    float inches;
public:
    void setData()
    {
        cout << "Enter ft: " << endl;
        cin >> ft;
        cout << "Enter inches: " << endl;
        cin >> inches;
    }
    friend void add(DM obj1, DB obj2);
};

void add(DM obj1, DB obj2)
{
    cout << "Displaying sum...." << endl;
    DM obj3;
    obj3.m = obj1.m + (obj2.ft * 0.3048);
    obj3.cm = obj1.cm + (obj2.inches * 2.54);
    cout << obj3.m << "m  " << obj3.cm << "cm" << endl;
}

int main()
{
    DM m1;
    m1.setData();
    DB ft1;
    ft1.setData();
    add(m1, ft1);
    return 0;
}
