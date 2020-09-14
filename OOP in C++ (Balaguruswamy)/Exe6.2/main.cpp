#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class String
{
private:
    char *p;
    int len;
public:
    String()
    {
        len = 0;
    }
    String(char *ps)
    {
        len = strlen(ps);
        p = new char[len + 1];
        strcpy(p, ps);
    }
    void setData()
    {
        char str[50];
        cout << "Enter string: " << endl;
        gets(str);
        len = strlen(str);
        p = new char[len + 1];
        strcpy(p, str);
    }
    void showData()
    {
        cout << p << endl;
    }
    friend char* addStrings(String s1, String s2);
};

char* addStrings(String s1, String s2)
{
    strcat(s1.p, s2.p);
    return (s1.p);
}

int main()
{
    String s1;
    String s2("Well Done!!!");
    s1 = s2;
    s1.showData();
    s2.setData();
    char *p;
    p = addStrings(s1, s2);
    cout << p;
    return 0;
}
