#include <iostream>

using namespace std;

class FLOAT
{
private:
    float f;
public:
    FLOAT(){}
    FLOAT(float x)
    {
        f = x;
    }
    void showValue()
    {
        cout << "f: " << f << endl;
    }
    float operator+(FLOAT ft)
    {
        return(f + ft.f);
    }
    float operator-(FLOAT ft)
    {
        return(f - ft.f);
    }
    float operator*(FLOAT ft)
    {
        return(f * ft.f);
    }
    float operator/(FLOAT ft)
    {
        return(f / ft.f);
    }
};

int main()
{
    FLOAT f1(23.57), f2(12.45);
    FLOAT f3, f4, f5, f6;
    f3 = f1 + f2;
    f4 = f1 - f2;
    f5 = f1 * f2;
    f6 = f1 / f2;
    f1.showValue();
    f2.showValue();
    f3.showValue();
    f4.showValue();
    f5.showValue();
    f6.showValue();
    return 0;
}
