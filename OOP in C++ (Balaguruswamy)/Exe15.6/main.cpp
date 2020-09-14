#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector <string> v;
    for(int i=0; i<str.size(); i++){
        if(str[i]== 'I'){
            string sub = str.substr(i, 2);
            v.push_back(sub);
        }
    }

    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == "It"){
            cnt++;
        }
    }
    cout << "Count: " << cnt;

    return 0;
}
