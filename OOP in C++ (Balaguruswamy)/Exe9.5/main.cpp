#include <iostream>

using namespace std;

class Array
{
private:
    int sizeOfArray;
    int* arrayP;
public:
    void setData()
    {
        cout << "Enter Size:\n";
        cin >> sizeOfArray;
        arrayP = new int[sizeOfArray];
        cout << "Enter Elements:\n";
        for(int i=0; i<sizeOfArray; i++){
            cin >> arrayP[i];
        }
    }
    void showData()
    {
        cout << "Showing Array:\n";
        for(int i=0; i<sizeOfArray; i++){
            cout << arrayP[i] << " ";
        }
        cout << endl;
    }
    friend void sortArray(Array &a);
};

int main()
{
    Array a;
    a.setData();
    cout << "Before Sorting..\n";
    a.showData();
    sortArray(a);
    cout << "After Sorting..\n";
    a.showData();
    return 0;
}

void sortArray(Array &a)
{
    for(int i=0; i<a.sizeOfArray; i++){
        for(int j=i+1; j<a.sizeOfArray; j++){
            if(a.arrayP[i]>a.arrayP[j]){
                int temp;
                temp = a.arrayP[i];
                a.arrayP[i] = a.arrayP[j];
                a.arrayP[j] = temp;
            }
        }
    }
}
