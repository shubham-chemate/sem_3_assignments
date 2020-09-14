#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char *str;
    int len;
public:
    String()
    {
        str = new char[len + 1];
    }
    String(char *p)
    {
        len = strlen(p);
        str = new char[len + 1];
        strcpy(str, p);
    }
    bool operator==(String &S)
    {
        if(strcmp(str, S.str) == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    ~String()
    {
        delete []str;
    }
};

int main()
{
    String S1("Ramesh"), S2("Suresh");
    if(S1 == S2){
        cout << "Equal Strings.\n";
    }
    else {
        cout << "Unequal Strings.\n";
    }
    return 0;
}
