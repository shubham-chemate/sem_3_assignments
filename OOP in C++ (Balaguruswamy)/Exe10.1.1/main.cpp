
//Solving Problem Using Manipulators

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
        cout << setw(10) << setiosflags(ios::left) << name << setw(10) << code << setw(10) << setprecision(4) << setiosflags(ios::showpoint) << setiosflags(ios::right) << cost;
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
    cout << setw(10) << setiosflags(ios::left) << "NAME" << setw(10) << "CODE" << setw(10) << setprecision(4) << setiosflags(ios::showpoint) << setiosflags(ios::right) << "COST";
    for(int i=0; i<s; i++){
        v[i].showValues();
    }

    return 0;
}
