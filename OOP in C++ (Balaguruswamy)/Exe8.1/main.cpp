#include <iostream>
#include <cstring>

using namespace std;

const int minimum = 500;
const int service_charge = 100;
const float r = 0.15;

class account
{
protected:
    char *name;
    int accNo;
    char *accType;
public:
    account(){}
    account(char *p1, int n, char *p2)
    {
        int len = strlen(p1);
        name = new char[len+1];
        strcpy(name, p1);
        len = strlen(p2);
        accType = new char[len+1];
        strcpy(accType, p2);
        accNo = n;
        cout << "Account is successfully created.\n\n";
    }
};

class cur_acct : public account
{
private:
    float balance;
public:
    cur_acct(char *p1, int n, char *p2, float b) : account(p1, n, p2)
    {
        balance = b;
    }
    void deposite(float d)
    {
        balance = d;
        cout << "Amount " << d << " is deposited successfully.\n";
    }
    void withdraw(float w)
    {
        if(balance > w){
            balance = balance - w;
            cout << "Withdrawal Successful." << endl;
            if(balance < minimum){
                cout << "Your current balance: " << balance << "\nService charge(as balance is less than " << minimum << "): " << service_charge << "\n";
                cout << "You must store minimum Rs." << minimum - balance << " to avoid service charge.\n";
                cout << "If you want to deposite press 1 else press 0: " << endl;
                int test = 0;
                cin >> test;
                if(test){
                    cout << "Please enter amount to add: \n";
                    float amt;
                    cin >> amt;
                    balance += amt;
                    cout << "Amount added successfully.\n";
                }
                else{
                    balance = balance - service_charge;
                    cout << "As you choosen 0 your net balance is " << balance << endl;
                }
            }
        }
        else{
            cout << "Not Enough Balance.\nWithdrawal failed.\n";
        }
    }
    void displayBalance()
    {
        cout << "Your current balance is " << balance << endl;
    }
};

class sav_acct : public account
{
private:
    float balance;
    int d, m, y;
public:
    sav_acct(char *p1, int n, char *p2, float b) : account(p1, n, p2)
    {
        balance = b;
    }
    void setDate(int x, int y, int z){d = x; m = y; this->y = z;}
    void deposite()
    {
        cout << "Enter dd/mm/yy:\n";
        int x, y, z;
        cin >> x >> y >> z;
        setDate(x, y, z);
        cout << "Enter amount to deposit:\n";
        float d;
        cin >> d;
        balance += d;
        cout << "Balance updated successfully.\n";
    }
    void withdraw()
    {
        cout << "Enter amount to withdraw: " << endl;
        float w;
        cin >> w;
        if(balance > w){
            balance = balance - w;
            cout << "Withdrawal Successful." << endl;
            if(balance < minimum){
                cout << "Your current balance: " << balance << "\nService charge(as balance is less than " << minimum << "): " << service_charge << "\n";
                cout << "You must deposit minimum Rs." << minimum - balance << " to avoid service charge.\n";
                cout << "If you want to deposit amount press 1 else press 0: " << endl;
                int test = 0;
                cin >> test;
                if(test){
                    cout << "Please enter amount to add: \n";
                    float amt;
                    cin >> amt;
                    balance += amt;
                    cout << "Amount added successfully.\n";
                }
                else{
                    balance = balance - service_charge;
                    cout << "As you choosen 0 your net balance is " << balance << endl;
                }
            }
        }
        else{
            cout << "Not Enough Balance to withdraw.\nWithdrawal failed.\n";
        }
    }
    void displayBalance()
    {
        cout << "Your current balance is " << balance << endl;
    }
    void interest()
    {
        int D[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int d1, y1, m1;
        cout << "Enter today's date(dd/mm/yy):\n";
        cin >> d1 >> m1 >> y1;
        int iday, fday;
        for(int i=0; i<m1; i++){
            fday += D[i];
        }
        for(int i=0; i<m; i++){
            iday += D[i];
        }
        int tday;
        tday = fday - iday;
        float ty = float(tday) / 365 + y1 - y;
        float inter;
        inter = ty * r * balance;
        cout << "Interest is: " << inter << "\n";
        balance =+ inter;
    }
};

int main()
{
    sav_acct SA("Rimo", 12345, "Savings", 10000);
    SA.displayBalance();
    SA.deposite();
    SA.withdraw();
    SA.displayBalance();
    SA.interest();
    SA.displayBalance();
    return 0;
}
