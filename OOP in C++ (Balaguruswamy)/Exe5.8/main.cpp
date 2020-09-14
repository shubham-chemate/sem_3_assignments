#include <iostream>
#include <cmath>

using namespace std;

class simpleInterest
{
private:
    float P;
    float r;
    float t;
public:
    void setData()
    {
        cout << "Enter p, r, t:" << endl;
        cin >> P >> r >> t;
    }
    friend void calculateSI(simpleInterest s);
};

class compoundInterest
{
private:
    float P;
    float r;
    float t;
    float n;
public:
    void setData()
    {
        cout << "Enter p, r, t, n:" << endl;
        cin >> P >> r >> t >> n;
    }
    friend void calculateCI(compoundInterest s);
};

void calculateSI(simpleInterest s)
{
    cout << "Calculating Simple Interest...." << endl;
    float simpleInterest :: *pP = & simpleInterest :: P;
    simpleInterest *pSI;
    pSI = &s;
    float A;
    A = (s.*pP) * ( 1 + (s.r * pSI -> t));
    cout << "Value of A is " << A << endl;
}

void calculateCI(compoundInterest s)
{
    cout << "Calculating Compound Interest...." << endl;
    float compoundInterest :: *pP = & compoundInterest :: P;
    float compoundInterest :: *pr = & compoundInterest :: r;
    compoundInterest *pSI;
    pSI = &s;
    float A;
    A = (s.*pP) * pow(1 + (pSI -> r) / (s.n), (s.n) * (pSI -> t));
    cout << "Value of A is " << A << endl;
}

int main()
{
    simpleInterest s;
    s.setData();
    calculateSI(s);
    compoundInterest c;
    c.setData();
    calculateCI(c);
    return 0;
}
