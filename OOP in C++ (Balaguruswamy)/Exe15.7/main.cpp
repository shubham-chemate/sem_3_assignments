#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <string> v;
    string str, tempstr;
    for(int i=0; i<5; i++){
        cin >> str;
        v.push_back(str);
    }

    for(int i=0; i<5; i++){
        for(int j=i; j<5; j++){
            if(v[i]>v[j]){
                tempstr = v[i];
                v[i] = v[j];
                v[j] = tempstr;
            }
        }
    }

    for(int i=0; i<5; i++){
        cout << v[i] << " ";
    }
    return 0;
}
