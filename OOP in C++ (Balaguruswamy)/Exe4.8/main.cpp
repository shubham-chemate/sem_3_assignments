#include <iostream>

using namespace std;

int power(int m, int=2);
double power(double m, int=2);

int main()
{
    cout <<power(3,3)<< endl;
    cout <<power(3.4,3)<< endl;
    cout <<power(3,2)<< endl;
    cout <<power(3.4,2)<< endl;
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

int power(int m, int n)
{
    int result=1;
    for(int i=0; i<n; i++){
        result=result*m;
    }
    return result;
}
