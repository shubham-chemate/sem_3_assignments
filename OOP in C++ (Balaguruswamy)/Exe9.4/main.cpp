#include <iostream>

using namespace std;

class Complex
{
private:
    int a, b;
public:
    void setData(int x, int y)
    {
        a = x;
        b = y;
    }
    void showData()
    {
        cout << a << "+i(" << b << ")\n" ;
    }
    friend void Swap(Complex* c1p, Complex* c2p);
};

int main()
{
    Complex c1, c2;
    c1.setData(5,6);
    cout << "Showing c1: ";
    c1.showData();
    c2.setData(2,3);
    cout << "Showing c2: ";
    c2.showData();
    Swap(&c1,&c2);
    cout << "\n\nAfter Swapping...\n";
    cout << "Showing c1: ";
    c1.showData();
    cout << "Showing c2: ";
    c2.showData();
    return 0;
}

void Swap(Complex* c1p, Complex* c2p)
{
    int temp;
    temp = c1p->a;
    c1p->a = c2p->a;
    c2p->a = temp;
    temp = c1p->b;
    c1p->b = c2p->b;
    c2p->b = temp;
}
