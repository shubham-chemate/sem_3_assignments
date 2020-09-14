#include <iostream>

using namespace std;

void createVector(int M);

int main()
{
    int M;
    cout<<"Enter size: "<<endl;
    cin>>M;
    createVector(M);
    return 0;
}

void createVector(int M)
{
    int *p=new int[M];
    cout<<"Succesfully Created!!";
    delete []p;
}
