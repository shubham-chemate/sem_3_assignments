#include <iostream>

using namespace std;

class shape
{
protected:
    double length;
    double height;
public:
    void getData(double l, double h = 0)
    {
        length = l;
        height = h;
    }
    virtual void displayArea()
    {
        cout << "Area is " << length * height << endl;
    }
};

class triangle : public shape
{
public:
    void displayArea()
    {
        cout << "Area of triangle is " << 0.5 * (length * height) << endl;
    }
};

class rectangle : public shape
{
public:
    void displayArea()
    {
        cout << "Area of rectangle is " << length * height << endl;
    }
};

int main()
{
    shape *RP, *TP;
    triangle t;
    rectangle r;
    RP = &r;
    TP = &t;
    RP->getData(10, 20);
    RP->displayArea();
    TP->getData(10, 20);
    TP->displayArea();
    return 0;
}
