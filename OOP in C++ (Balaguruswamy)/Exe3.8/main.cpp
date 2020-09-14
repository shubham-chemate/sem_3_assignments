#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    cout<<setw(10)<<"X"<<setw(10)<<"0.1"<<setw(10)<<"0.2"<<setw(10)<<"0.3"<<setw(10)<<"0.4"<<setw(10)<<"0.5"<<setw(10)<<"0.6"<<setw(10)<<"0.7"<<setw(10)<<"0.8"<<setw(10)<<"0.9"<<endl;
    for(int i=0; i<10; i++){
        cout<<setw(10)<<i;
        for(float j=0.1; j<1.0;){
                printf("%10f", pow(2.71, -(i+j)));
            //cout<<setw(10)<<pow(2.71, -(i+j));
            j=j+0.1;
        }
        cout<<endl;
    }
    return 0;
}
