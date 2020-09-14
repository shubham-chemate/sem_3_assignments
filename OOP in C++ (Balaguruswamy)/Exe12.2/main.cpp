#include <iostream>

using namespace std;

template <class T>
class vect
{
private:
    T *arr;
    int s;
public:
    void makeVector(int n)
    {
        arr = new T[s = n];
        cout << "Enter elements: \n";
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
    }
    void modify(int i, T val)
    {
        arr[i] = val;
    }
    void multiply(int n)
    {
        for(int i=0; i<s; i++){
            arr[i] = arr[i] * n;
        }
    }
    void display()
    {
        for(int i=0; i<s; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vect <float> v;
    v.makeVector(4);
    v.display();
    v.modify(2, 9.8);
    v.display();
    v.multiply(2);
    v.display();

    return 0;
}
