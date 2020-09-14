#include <iostream>
#include <string>

using namespace std;

class car
{
private:
    string name;
    string company;
    float cc;
    float price;
public:
    car(){}
    car(string n, string comp, float cap, float val)
    {
        name = n;
        company = comp;
        cc = cap;
        price = val;
    }
    void Display()
    {
        cout << "Name: " << name << endl << "Company: " << company << endl << "CC: " << cc << endl << "Price(in Lakhs): " << price << endl;
    }
};

int main()
{
    car c1, c2("Night Rod", "Harley", 998.99, 7);
    c2.Display();
    return 0;
}
