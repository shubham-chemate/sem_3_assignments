#include <iostream>
#include <cmath>

using namespace std;

long long fact(int n);

int main()
{
    float x;
    cin>>x;

    double sum=0;
    for(int i=0; i<10; i++){
        sum=sum+pow(-1,i)*(pow(x,2*i+1)/fact(2*i+1));
    }

    cout<<"Sum is "<<sum;
    return 0;
}

long long fact(int n)
{
    if(n==0){return 1;}
    return(n*fact(n-1));
}
