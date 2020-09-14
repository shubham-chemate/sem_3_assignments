#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char s1[] = "This is Object Oriented Programming in Cpp";
    char s2[] = "xpp";

    if(lexicographical_compare(s1, s1+strlen(s1), s2, s2+strlen(s2))){
        cout << "Smaller";
    }
    else{
        cout << "Not Smaller.";
    }
    return 0;
}
