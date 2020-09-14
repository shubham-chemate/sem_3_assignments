#include <iostream>

using namespace std;

int main()
{
    int b;
    int arr[6]={0};
    while(1){
        cout<<"Enter Ballot: (0 to end)"<<endl;
        cin>>b;
        if(b==0){break;}
            switch(b)
            {
                case 1:
                arr[1]=arr[1]+1;
                break;
                case 2:
                arr[2]=arr[2]+1;
                break;
                case 3:
                arr[3]=arr[3]+1;
                break;
                case 4:
                arr[4]=arr[4]+1;
                break;
                case 5:
                arr[5]=arr[5]+1;
                break;
                default:
                arr[0]=arr[0]+1;
            }
    }

    for(int i=0; i<6; i++){
        if(i==0){
            cout<<"spoilt ballot: "<<arr[i]<<endl;
            continue;
        }
        cout<<i<<": "<<arr[i]<<endl;
    }
    return 0;
}
