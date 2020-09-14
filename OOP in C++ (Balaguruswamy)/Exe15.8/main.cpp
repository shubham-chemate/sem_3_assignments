#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("123456789");
    int cnt = 0;
    for(int i=0; i<5; i++){
        cnt = i;
        for(int j=0; j<9; j++){
            if(j>=4-i && j<4){
                cout << s[cnt];
                cnt += 1;
            }
            else if(j==4){
                cout << s[cnt];
            }
            else if(j<=4+i && j>4){
                --cnt;
                cout << s[cnt];
            }
            else{
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
