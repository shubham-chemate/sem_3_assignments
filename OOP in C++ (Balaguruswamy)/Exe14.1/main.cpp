#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v(10);

    v[0] = 0;
    v[9] = 9;

    for(int i=1; i<9; i++){
        v[i] = 1;
    }

    for(int i=0; i<10; i++){
        cout << v[i] << " ";
    }

    return 0;
}
