#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class staff
{
protected:
    char *codeP;
    char *nameP;
};

class teacher : public staff
{
private:
    char *subjP;
    char *publicationP;
public:
    void setData(char *cP, char *nP, char *sP, char *pP)
    {
        int len;
        len = strlen(cP);
        codeP = new char[len + 1];
        strcpy(codeP, cP);
        len = strlen(nP);
        nameP = new char[len + 1];
        strcpy(nameP, nP);
        len = strlen(sP);
        subjP = new char[len + 1];
        strcpy(subjP, sP);
        len = strlen(cP);
        publicationP = new char[len + 1];
        strcpy(publicationP, pP);
    }
    void showData()
    {
        cout << "\n\nThe details of teacher are as follows:\n";
        cout << "Code: " << codeP << endl;
        cout << "Name: " << nameP << endl;
        cout << "Subject: " << subjP << endl;
        cout << "Publication: " << publicationP << endl;
    }
};

class typist : public staff
{
protected:
    int speed;
};

class officer : public staff
{
private:
    char grade;
public:
    void setData(char *cP, char *nP, char g)
    {
        int len;
        len = strlen(cP);
        codeP = new char[len + 1];
        strcpy(codeP, cP);
        len = strlen(nP);
        nameP = new char[len + 1];
        strcpy(nameP, nP);
        grade = g;
    }
    void showData()
    {
        cout << "\n\nThe details of officer are as follows:\n";
        cout << "Code: " << codeP << endl;
        cout << "Name: " << nameP << endl;
        cout << "Grade: " << grade << endl;
    }
};

class regular : public typist
{
public:
    void setData(char *cP, char *nP, int s)
    {
        int len;
        len = strlen(cP);
        codeP = new char[len + 1];
        strcpy(codeP, cP);
        len = strlen(nP);
        nameP = new char[len + 1];
        strcpy(nameP, nP);
        speed = s;
    }
    void showData()
    {
        cout << "\n\nThe details of regular typist are as follows:\n";
        cout << "Code: " << codeP << endl;
        cout << "Name: " << nameP << endl;
        cout << "Speed: " << speed << endl;
    }
};

class casual : public typist
{
private:
    float salary;
public:
    void setData(char *cP, char *nP, float s)
    {
        int len;
        len = strlen(cP);
        codeP = new char[len + 1];
        strcpy(codeP, cP);
        len = strlen(nP);
        nameP = new char[len + 1];
        strcpy(nameP, nP);
        salary = s;
    }
    void showData()
    {
        cout << "\n\nThe details of regular typist are as follows:\n";
        cout << "Code: " << codeP << endl;
        cout << "Name: " << nameP << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    teacher t;
    t.setData("PHY101", "ManishKumar", "Physics", "ThinkIIT");
    regular r;
    r.setData("TYPR101", "Amol", 40);
    casual c;
    c.setData("TYPC101", "Vinay", 1000);
    officer o;
    o.setData("OFFI101", "KumarSingh", 'A');
    t.showData();
    r.showData();
    c.showData();
    o.showData();
    return 0;
}
