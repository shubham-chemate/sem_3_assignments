#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class person
{
protected:
    char *nameP;
    char *codeP;
public:
    void updateName()
    {
        delete []nameP;
        char newName[50];
        cout << "\n\nEnter new name: \n";
        fflush(stdin);
        gets(newName);
        int len = strlen(newName);
        nameP = new char[len+1];
        strcpy(nameP, newName);
        cout << "\n\nName is successfully Updated.\n\n";
    }

};

class account : virtual public person
{
protected:
    float pay;
public:
    void updatePay()
    {
        cout << "\n\nEnter new pay: \n";
        cin >> pay;
        cout << "\n\nPay is successfully updated.\n\n";
    }

};

class admin : virtual public person
{
protected:
    int experience;
public:
    void addExp()
    {
        int n;
        cout << "\n\nEnter experience to be added: \n";
        cin >> n;
        experience = experience + n;
        cout << "Experience is successfully updated.\n\n";
    }

};

class master : public account, public admin
{
public:
    void setData(char *nP, char *cP, float p, int e)
    {
        int len;
        len = strlen(nP);
        nameP = new char[len + 1];
        strcpy(nameP, nP);
        len = strlen(cP);
        codeP = new char[len + 1];
        strcpy(codeP, cP);
        pay = p;
        experience = e;
    }
    void showData()
    {
        cout << "\n\nThe details of a master are as follows:\n\n";
        cout << "Name: " << nameP << endl;
        cout << "Code: " << codeP << endl;
        cout << "Experience: " << experience << endl;
        cout << "Pay: " << pay << endl;
    }

};

int main()
{
    master m;
    char strn[50], strc[50];
    float p;
    int exp;
    cout << "Enter name: " << endl;
    cin >> strn;
    cout << "Enter code: " << endl;
    cin >> strc;
    cout << "Enter Pay: " << endl;
    cin >> p;
    cout << "Enter experience: " << endl;
    cin >> exp;
    m.setData(strn, strc, p, exp);
    m.showData();
    m.updateName();
    m.updatePay();
    m.addExp();
    m.showData();

    return 0;
}
