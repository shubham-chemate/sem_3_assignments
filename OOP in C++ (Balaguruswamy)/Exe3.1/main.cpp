#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    swap(a, b);
    cout<<"a="<<a<<" b="<<b;
    return 0;
}

void swap(int &ra, int &rb)
{
    int temp;
    temp=ra;
    ra=rb;
    rb=temp;
}
