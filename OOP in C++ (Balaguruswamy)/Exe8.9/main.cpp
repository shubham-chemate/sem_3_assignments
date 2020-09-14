#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string name;
    string company;
    float price;
private:

};

class Manual
{

};

class TwoWheeler : public Vehicle, public Manual
{

};

class ThreeWheeler : public Vehicle
{

};

class FourWheeler : public Vehicle
{

};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
