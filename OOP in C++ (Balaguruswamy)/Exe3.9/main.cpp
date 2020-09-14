#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout<<"Enter no of numbers:"<<endl;
    int n;
    cin>>n;
    float arr[n];
    cout<<"Enter the numbers"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    float sum=0.0;
    for(int i=0; i<n; i++){
        sum=sum+arr[i];
    }
    float mean;
    mean=sum/n;
    cout<<"Mean is: "<<mean<<endl;
    float variance=0.0;
    for(int i=0; i<n; i++){
        variance=variance + pow(arr[i]-mean, 2);
    }
    variance/=n;
    cout<<"variance is: "<<variance<<endl;
    float SD=0;
    SD=sqrt(variance);
    cout<<"SD is:"<<SD<<endl;
    return 0;
}
