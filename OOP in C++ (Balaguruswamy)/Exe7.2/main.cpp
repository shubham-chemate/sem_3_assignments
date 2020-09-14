#include <iostream>
#include <cmath>

using namespace std;

class Polar
{
private:
    float r;
    float theta;
public:
    Polar(){}
    Polar(float x, float y)
    {
        r = x;
        theta = y;
    }
    void showData()
    {
        cout << "(" << r << "," << theta << ")" << endl;
    }
    Polar operator+(Polar P)
    {
        Polar R;
        float x, y;
        x = r * cos(theta) + P.r * cos(P.theta);
        y = r * sin(theta) + P.r * sin(P.theta);
        R.r = sqrt(x * x + y * y);
        R.theta = atan(y / x);
        return R;
    }
};

int main()
{
    Polar P(45.5, 1.20), Q(36.78, 0.76);
    Polar R;
    R = P + Q;
    P.showData();
    Q.showData();
    R.showData();
    return 0;
}
