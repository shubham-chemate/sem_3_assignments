#include <iostream>

using namespace std;

template <class T, int n>
class vect
{
private:
    T arr[n];
public:
    vect(){}
    vect(T *p)
    {
        for(int i=0; i<n; i++){
            arr[i] = p[i];
        }
    }
    T maxVect()
    {
        T m = arr[0];
        for(int i=0; i<n; i++){
            if(arr[i]>m){
                m = arr[i];
            }
        }
        return m;
    }

};

int main()
{
    vect <float, 3> v;
    float a[] = {1.0, 2.0, 3.0};
    v = a;
    cout << "Max: " << v.maxVect();
    return 0;
}
