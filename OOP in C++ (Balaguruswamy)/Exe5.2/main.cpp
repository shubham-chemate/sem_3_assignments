#include <iostream>

using namespace std;

class vectorclass
{
private:
    float *p;
    int sizeOfVector;
public:
    void createVector(int a)
    {
        sizeOfVector = a;
        p = new float[a];
        cout << "Enter Values....." << endl;
        for(int i=0; i<a; i++){
            cin >> *(p+i);
        }
    }
    void modify(int b, float val)
    {
        *(p+b-1) = val;
    }
    void multiplyByScalar(int b, int val)
    {
        *(p+b-1) = val * *(p+b-1);
    }
    void display()
    {
        cout << endl << "Displaying the Vector....." << endl;
        for(int i=0; i<sizeOfVector; i++){
            cout << *(p+i) << ", ";
        }
    }

};

int main()
{
    vectorclass v1;
    v1.createVector(5);
    v1.display();
    v1.modify(5, 6.0);
    v1.multiplyByScalar(4, 2);
    v1.display();
    return 0;
}
