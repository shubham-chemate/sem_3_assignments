#include <iostream>

using namespace std;

template <class T>
void findMinMax(T *p, int n)
{
    T mi = p[0];
    T ma = p[0];
    for(int i=0; i<n; i++){
        if(p[i]>ma){
            ma = p[i];
        }
        if(p[i]<mi){
            mi = p[i];
        }
    }
    cout << "Min: " << mi << endl;
    cout << "Max: " << ma << endl;
}

int main()
{

    float arr[] = {1.0, 2.4, 0.5, 5.9};
    findMinMax(arr, 4);
    return 0;
}
