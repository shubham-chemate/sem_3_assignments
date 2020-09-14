#include <iostream>

using namespace std;

float area(int r);
int area(int l, int b);

int main()
{
    cout<<area(5.0)<<endl;
    cout<<area(3,2)<<endl;
    return 0;
}

inline float area(int r)
{
    return(3.14*r*r);
}

inline int area(int l, int b)
{
    return(l*b);
}
