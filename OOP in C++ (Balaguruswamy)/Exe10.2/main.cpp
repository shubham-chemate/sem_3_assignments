#include <iostream>
#include <iomanip>

using namespace std;

class values
{
private:
    char name[20];
    int code;
    float cost;
public:
    void setValues()
    {
        cin >> name;
        cin >> code;
        cin >> cost;
    }
    void showValues()
    {
        cout << endl;
        cout.fill('-');
        cout.width(10);
        cout.setf(ios::left, ios::adjustfield);
        cout << name;
        cout.width(10);
        cout << code;
        cout.width(10);
        cout.setf(ios::right, ios::adjustfield);
        cout << cost;
    }
};

const int s = 3;

int main()
{
    cout << "Enter name, code, cost\n";

    values v[s];

    for(int i=0; i<s; i++){
        v[i].setValues();
    }

    cout << endl;
    cout.fill('-');
    cout.width(10);
    cout.setf(ios::left, ios::adjustfield);
    cout << "NAME";
    cout.width(10);
    cout << "CODE";
    cout.width(10);
    cout.precision(4);
    cout.setf(ios::showpoint);
    cout.setf(ios::right, ios::adjustfield);
    cout << "COST";

    for(int i=0; i<s; i++){
        v[i].showValues();
    }

    return 0;
}
