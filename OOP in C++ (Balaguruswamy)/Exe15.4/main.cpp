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
    cout << str;
    return 0;
}
