#include <iostream>
#include <string>
#include <list>

using namespace std;

class student
{
private:
    string name;
    int roll_number;
public:
    void setData(string n, int rn)
    {
        name = n;
        roll_number = rn;
    }
    void showData()
    {
        cout << name << " " << roll_number << endl;
    }
    int getRoll()
    {
        return roll_number;
    }
    string getName()
    {
        return name;
    }
};

int main()
{
    int roll;
    string name;
    student arr[5];
    list <student> l;

    cout << "Enter name and roll number(for five students): \n";

    for(int i=0; i<5; i++){
        cin >> name;
        cin >> roll;
        arr[i].setData(name, roll);
        l.push_back(arr[i]);
    }

    cout << "Showing List Items: \n";
    list<student> :: iterator p;
    for(p=l.begin(); p!=l.end(); p++){
        (*p).showData();
    }

    cout << "Enter roll number: \n";
    cin >> roll;

    for(p=l.begin(); p!=l.end(); p++){
        if((*p).getRoll() == roll){
            cout << (*p).getName() << endl;
        }
    }

    return 0;
}
