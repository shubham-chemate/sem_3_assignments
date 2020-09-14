#include <iostream>

using namespace std;

class shop
{
public:
    virtual void setValues() = 0;
};

class kitchen : public shop
{
private:
    int milk;
    int food;
public:
    void setValues()
    {
        cout << "Enter milk: \n";
        cin >> milk;
        cout << "Enter food: \n";
        cin >> food;
    }
    void showValues()
    {
        cout << "\n\nShowing Kitchen: \n";
        cout << "Milk: " << milk << endl << "Food: " << food << endl;
    }
};

class appliances : public shop
{
private:
    int clothes;
    int furnisher;
public:
    void setValues()
    {
        cout << "Enter Clothes: \n";
        cin >> clothes;
        cout << "Enter furnisher: \n";
        cin >> furnisher;
    }
    void showValues()
    {
        cout << "\n\nShowing appliances: \n";
        cout << "Clothes: " << clothes << endl << "Furnisher: " << furnisher << endl;
    }
};

int main()
{
    cout << "Welcome!!!\n\n" << endl;
    kitchen K;
    K.setValues();
    K.showValues();
    appliances A;
    A.setValues();
    A.showValues();
    return 0;
}
