#include <iostream>
#include <iomanip>

using namespace std;

class player
{
private:
    char name[20];
    int runs;
    int innings;
    int not_out;
    float avg;
public:
    void setData()
    {
        cin>>name>>runs>>innings>>not_out;
    }
    void calAvg()
    {
        avg=float(runs)/innings;
    }
    void showData()
    {
        cout<<setw(10)<<name<<setw(10)<<runs<<setw(10)<<innings<<setw(10)<<not_out<<setw(10)<<avg<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter number of players: "<<endl;
    cin>>n;
    cout<<"Enter name, runs, innings, no_out:"<<endl;
    player P[n];
    for(int i=0; i<n; i++){
        P[i].setData();
    }

    for(int i=0; i<n; i++){
        P[i].calAvg();
    }

    cout<<endl<<setw(10)<<"name"<<setw(10)<<"runs"<<setw(10)<<"innings"<<setw(10)<<"not_out"<<setw(10)<<"avg"<<endl;
    for(int i=0; i<n; i++){
        P[i].showData();
    }
    return 0;
}
