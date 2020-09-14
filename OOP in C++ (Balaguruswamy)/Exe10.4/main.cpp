#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int fact(int n);

int main()
{
    double e = 0;

    for(int i=0; i<20; i++){
        e = e + (1.0 / fact(i));
    }
    cout << setprecision(5) << e;
    return 0;
}

int fact(int n)
{
    if(n==0 || n==1){
        return 1;
    }
    return (n*fact(n-1));
}
