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

class circle : public shape
{
public:
    void displayArea()
    {
        cout << "Area of circle is " << 3.14 * length * length << endl;
    }
};

int main()
{
    shape *RP, *TP, *CP;
    triangle t;
    rectangle r;
    circle c;
    RP = &r;
    TP = &t;
    CP = &c;
    RP->getData(10, 20);
    RP->displayArea();
    TP->getData(10, 20);
    TP->displayArea();
    CP->getData(1);
    CP->displayArea();
    return 0;
}
