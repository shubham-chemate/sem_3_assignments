#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2, str3, strm1;
    cin >> str1;
    cin >> str2;
    cin >> str3;
    strm1 = str1 + " " + str2 + " " + str3;
    cout << "strm1: str1 + str2 + str3 = " << strm1 << endl;
    str1.append(" ");
    str1.append(str2);
    str1.append(" ");
    str1.append(str2);
    cout << "strm2: str1 + str2 + str3 = " << str1 << endl;
    return 0;
}
