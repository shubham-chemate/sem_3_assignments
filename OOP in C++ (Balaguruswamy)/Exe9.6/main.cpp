#include <iostream>

using namespace std;

int fact(int n)
{
    if(n == 1 || n == 0){
        return 1;
    }
    return(n * fact(n-1));
}

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;

    int (*factFuncPoint)(int);
    factFuncPoint = &fact;
    cout << n << "! = " << (*factFuncPoint)(n);
    return 0;
}
