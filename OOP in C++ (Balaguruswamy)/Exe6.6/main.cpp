#include <iostream>

using namespace std;

class primeNumber
{
public:
    primeNumber(int x)
    {
        int test = 0;
        for(int i=2; i<x; i++){
            if(x % i == 0){
                test = 1;
                break;
            }
        }
        if(test == 0){
            cout << "Prime Number." << endl;
        }
        else{
            cout << "Composite Number." << endl;
        }
    }
};

int main()
{
    primeNumber x = 37;
    return 0;
}
