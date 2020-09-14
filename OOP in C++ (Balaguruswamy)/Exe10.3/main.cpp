#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    char str[200];
    cin.getline(str, 200);

    int c = 0, l = 0, w = 1;
    for(int i=0; i<strlen(str); i++){
        c++;
        if(str[i] == ' '){
            w++;
        }
        else if(str[i] == '.'){
            l++;
        }
    }
    cout << setw(10) << setiosflags(ios::left) << "Lines" << setw(10) << setiosflags(ios::right) << l << endl;
    cout << setw(10) << setiosflags(ios::left) << "Words" << setw(10) << setiosflags(ios::right) << w << endl;
    cout << setw(10) << setiosflags(ios::left) << "Characters" << setw(10) << setiosflags(ios::right) << c << endl;
    return 0;
}
