#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float  sum=0;


    for(int i=1; i<10; i++){
        sum=sum+pow(1.0/i,i);
    }

    cout<<sum;

    return 0;
}
