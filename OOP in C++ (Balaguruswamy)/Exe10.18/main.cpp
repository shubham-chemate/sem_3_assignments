#include <iostream>
#include <iomanip>

using namespace std;

ostream & myManip(ostream & output)
{
    output.width(10);
    output.setf(ios::left,ios::adjustfield);
    output.precision(2);
    output.fill('*');
    output.setf(ios::showpoint);
    return output;
}

int main()
{
    float PI = 22.0 / 7.0;
    cout << myManip << PI << endl;
    cout << myManip << 2.40 << endl;
    return 0;
}
