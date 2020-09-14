#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> v;
    string str;
    for(int i=0; i<5; i++){
        cin >> str;
        v.push_back(str);
    }

    for(int i=0; i<5; i++){
        if(v[i].at(1)=='B' || v[i].at(1)=='C'){
            cout << v[i] << endl;
        }
    }

    return 0;
}
