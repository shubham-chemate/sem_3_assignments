=======================5.1=========================
class Account
{
private:
    char *name;
    ..
    ..
public:
    Account(char *pName, char *pAccoNo, char *pAccType, float bal)
    {
        int length = strlen(pName);
        name = new char[len+1];
        strcpy(name, pName);
        ..
        ..
    }
};

=======================5.2=========================
#include <iostream>

using namespace std;

class vectorclass
{
private:
    float *p;
    int sizeOfVector;
public:
    vectorclass(int a)
    {
        sizeOfVector = a;
        p = new float[a];
        cout << "Enter Values.." << endl;
        for(int i=0; i<a; i++){
            cin >> *(p+i);
        }
    }
};

int main()
{
    vectorclass v(5);
    return 0;
}

=======================5.5=========================
class DM
{
private:
    float m;
    float cm;
public:
    DM(float mv, float cmv)
    {
        m = mv;
        cm = cmv;
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
