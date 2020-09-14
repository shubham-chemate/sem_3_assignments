#include <iostream>

using namespace std;

inline int maxi(int a, int b, int c);

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    cout<<maxi(a, b, c);
    return 0;
}

inline int maxi(int a, int b, int c)
{
    if(a>b &&a>c){
        return a;
    }
    else if(b>c){
        return b;
    }
    else{
        return c;
    }
}
