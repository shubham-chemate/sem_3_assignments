#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float pi = 22.0 / 7.0;
    for(int i=1; i<=10; i++){
        cout.precision(i+1);
        cout << pi << endl;
    }
    return 0;
}
