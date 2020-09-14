#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float V;
    int P=1000;
    float r=0.10;
    cout<<setw(10)<<"P"<<setw(10)<<"r"<<setw(10)<<"n"<<setw(10)<<"V"<<endl;
    for(int n=1; n<11; n++){
        V = P * pow(1+r, n);
        cout<<setw(10)<<P<<setw(10)<<r<<setw(10)<<n<<setw(10)<<V<<endl;
        r=r+0.01;
        P=P+1000;
    }
    return 0;
}
