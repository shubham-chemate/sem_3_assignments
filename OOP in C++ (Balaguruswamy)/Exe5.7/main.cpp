#include <iostream>
#include <stdio.h>

using namespace std;

class faculty
{
private:
    char ID[10];
    char name[20];
    char post[10];
    char qualifi[30];
    char add[40];
public:
    void setData()
    {
        cout << "Enter ID: " << endl;
        cin >> ID;
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter post: " << endl;
        cin >> post;
        fflush(stdin);
        cout << "Enter qualifications: " << endl;
        gets(qualifi);
        cout << "Enter address: " << endl;
        gets(add);
    }
    void showData()
    {
        cout << endl << "Displaying details....." << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Post: " << post << endl;
        cout << "Qualification: " << qualifi << endl;
        cout << "Address: " << add << endl;
    }
};

int main()
{
    faculty f;
    f.setData();
    f.showData();
    return 0;
}
