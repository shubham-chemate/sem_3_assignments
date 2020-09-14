#include <iostream>
#include <cmath>

using namespace std;

class Polar
{
private:
    float r, theta;
public:
    Polar(){}
    Polar(float r, float theta)
    {
        this->r = r;
        this->theta = theta;
    }
    float getr()
    {
        return r;
    }
    float gettheta()
    {
        return theta;
    }

};

class Rectangular
{
private:
    float x, y;
public:
    Rectangular(){}
    Rectangular(float p, float q)
    {
        x = p;
        y = q;
    }
    Rectangular(Polar p)
    {
        x = (p.getr()) * cos(p.gettheta());
        y = (p.getr()) * sin(p.gettheta());
    }
    void showData()
    {
        cout << "The rectangular representation is...." << endl;
        cout << "(" << x << ", " << y << ")" <<endl;
    }
};

int main()
{
    Polar p1(35, 2.45);
    Rectangular r1;
    r1 = p1;
    r1.showData();
    return 0;
}
