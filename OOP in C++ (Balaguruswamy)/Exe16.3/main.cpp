#include <iostream>

using namespace std;

float area(float r)
{
    return(3.14*r*r);
}

int area(int a, int b)
{
    return(a*b);
}

int main()
{

    cout << area(2.1) << endl;
    cout << area(2, 3) << endl;
    return 0;
}
