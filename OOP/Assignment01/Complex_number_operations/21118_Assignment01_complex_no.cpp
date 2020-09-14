#include <iostream>

using namespace std;

class Complex
{
private:
    float real, img;
public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    inline Complex operator + (Complex C)
    {
        Complex res;
        res.real = real + C.real;
        res.img = img + C.img;
        return res;
    }
    inline Complex operator - (Complex C)
    {
        Complex res;
        res.real = real - C.real;
        res.img = img - C.img;
        return res;
    }
    inline Complex operator * (Complex C)
    {
        Complex res;
        res.real = (real * C.real) - (img * C.img);
        res.img = (real * C.img) + (img * C.real);
        return res;
    }
    Complex operator / (Complex C)
    {
        float divFact = (C.real * C.real) + (C.img * C.img);
        Complex res;
        res.real = ((real * C.real) + (img * C.img)) / divFact;
        res.img = (-(real * C.img) + (img * C.real)) / divFact;
        return res;
    }
    friend ostream & operator << (ostream & out, Complex &C);
    friend istream & operator >> (istream & in, Complex &C);
};

ostream & operator << (ostream & out, Complex &C)
{
    out << C.real;
    out << " + i(" << C.img << ")";
    return out;
}

istream & operator >> (istream & in, Complex &C)
{
    in >> C.real;
    in >> C.img;
    return in;
}

int main()
{
    Complex c1, c2;
    cout << "Enter the values of a and b for first complex number : \n";
    cin >> c1;
    cout << "\nEnter the values of a and b for second complex number : \n";
    cin >> c2;

    int choice;
    do {
        cout << "\n\nChoose Operation :\n0 to Exit\n1 for addition\n2 for substraction\n3 for multiplication\n4 for division\n";
        cout << "Enter Here : ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                Complex add = c1 + c2;
                cout << "Addition is : ";
                cout << add;
                break;
            }
        case 2:
            {
                Complex sub = c1 - c2;
                cout << "Subtraction is : ";
                cout << sub;
                break;
            }
        case 3:
            {
                Complex prod = c1 * c2;
                cout << "Multiplication is : ";
                cout << prod;
                break;
            }
        case 4:
            {
                Complex div = c1 / c2;
                cout << "Division is : ";
                cout << div;
                break;
            }
        }
    }
    while (choice != 0);

    return 0;
}
