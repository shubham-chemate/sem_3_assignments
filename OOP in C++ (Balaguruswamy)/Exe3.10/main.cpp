#include <iostream>
#include <iomanip>

using namespace std;

class user
{
private:
    char name[30];
    int units;
    int total_charge;
public:
    void setData()
    {
        cin>>name>>units;
    }
    void showData()
    {
        cout<<setw(30)<<name<<setw(10)<<units<<setw(10)<<total_charge<<endl;
    }
    void calculateCharge()
    {
        int charge=0;
        if(units<=100){
            charge=units * 60;
        }
        else if(units>100 && units<=300){
            charge=((units-100) * 80)+6000;
        }
        else if(units>300){
            charge=((units-300) * 90)+22000;
        }
        charge=charge/100;
        charge=charge+50;
        if(charge>=300){
            total_charge=charge+(0.15 * charge);
        }
        else {
            total_charge=charge;
        }
    }
};

int main()
{
    cout<<"Enter number of users: "<<endl;
    int n;
    cin>>n;

    user u[n];
    cout<<"Enter name and units: "<<endl;
    for(int i=0; i<n; i++){
        u[i].setData();
    }

    for(int i=0; i<n; i++){
        u[i].calculateCharge();
    }

    cout<<setw(30)<<"name"<<setw(10)<<"units"<<setw(10)<<"charges"<<endl;
    for(int i=0; i<n; i++){
        u[i].showData();
    }
    return 0;
}
