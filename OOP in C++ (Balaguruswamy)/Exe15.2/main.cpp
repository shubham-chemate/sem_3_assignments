#include <iostream>

using namespace std;

int main()
{

    string str = "Well Done!";

    string :: iterator p = str.begin();

    while(p != str.end()){
        cout << *p;
        p++;
    }
    cout << endl << "END";

    return 0;
}
