#include <iostream>

using namespace std;

class bank_acc
{
private:
    char name[20];
    int accno;
    int acc_type;
    float balance;
public:
    void setData()
    {
        cout <<  "Enter name, accno, acc_type and balance" << endl;
        cin >> name >> accno >> acc_type >> balance;
    }
    void addAmt()
    {
        float x;
        cout << "Enter amt to add: " << endl;
        cin >> x;
        balance = balance + x;
    }
    void withDraw()
    {
        float y;
        cout << "Enter amt to withdraw: " << endl;
        cin >> y;
        if(y>balance){
            cout << "Not enough balance to withdraw." << endl;
        }
        else {
            balance = balance - y;
        }
    }
    void nameAndBalance()
    {
        cout << endl << "Displaying Name and Balance...." << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    bank_acc a1;
    a1.setData();
    a1.nameAndBalance();
    a1.addAmt();
    a1.nameAndBalance();
    a1.withDraw();
    a1.nameAndBalance();
    return 0;
}
