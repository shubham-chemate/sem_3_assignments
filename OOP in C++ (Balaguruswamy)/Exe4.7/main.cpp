#include <iostream>

using namespace std;

double power(double m, int=2);

int main()
{
    double m;
    int n;
    cin>>m>>n;
    cout<<power(m,n);
    return 0;
}

double power(double m, int n)
{
    double result=1;
    for(int i=0; i<n; i++){
        result=result*m;
    }
    return result;
}
