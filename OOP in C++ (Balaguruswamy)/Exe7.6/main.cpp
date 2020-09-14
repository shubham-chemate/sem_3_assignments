#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    float a, b;
public:
    Complex(){}
    Complex(float x, float y)
    {
        a = x;
        b = y;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return temp;
    }
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.a = (a * c.a) - (b * c.b);
        temp.b = (a * c.b) + (b * c.a);
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.a = ((a * c.a) + (b * c.b)) / (pow(c.a, 2) + pow(c.b, 2));
        temp.b = -((a * c.b) + (b * c.a)) / (pow(c.a, 2) + pow(c.b, 2));
        return temp;
    }
    Complex operator-()
    {
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }
    void showData()
    {
        cout << "The complex number is..\n";
        cout << a << "+i(" << b << ")\n";
    }
};

int main()
{
    Complex c1(3,4), c2(5,6), c3, c4, c5, c6;
    c3 = c1 + c2;
    c4 = c1 * c2;
    c3.showData();
    c4.showData();
    c5 = c1 / c2;
    c5.showData();
    c6 = -c1;
    c6.showData();
    return 0;
}
