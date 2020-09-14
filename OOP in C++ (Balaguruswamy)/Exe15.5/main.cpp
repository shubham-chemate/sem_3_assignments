#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for(int i=0; i<str.size(); i++){
        if(str[i]==' '){
            str[i] = '_';
        }
    }
    cout << str << endl;

    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='e'){
            cnt++;
        }
    }
    cout << "e: " << cnt << endl;

    return 0;
}
