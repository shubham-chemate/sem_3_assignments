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

class education
{
protected:
    char *highestEduP;
    char *highestProQuaP;
};

class teacher : public staff, public education
{
private:
    char *subjP;
    char *publicationP;
public:
    void setData(char *cP, char *nP, char *sP, char *pP, char *EP, char *QP)
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
        len = strlen(EP);
        highestEduP = new char[len + 1];
        strcpy(highestEduP, EP);
        len = strlen(QP);
        highestProQuaP = new char[len + 1];
        strcpy(highestProQuaP, QP);
    }
    void showData()
    {
        cout << "\n\nThe details of teacher are as follows:\n";
        cout << "Code: " << codeP << endl;
        cout << "Name: " << nameP << endl;
        cout << "Subject: " << subjP << endl;
        cout << "Publication: " << publicationP << endl;
        cout << "Highest Edu: " << highestEduP << endl;
        cout << "Highest Qual: " << highestProQuaP << endl;
    }
};

class typist : public staff
{
protected:
    int speed;
};

class officer : public staff, public education
{
private:
    char grade;
public:
    void setData(char *cP, char *nP, char g, char *EP, char *QP)
    {
        int len;
        len = strlen(cP);
        codeP = new char[len + 1];
        strcpy(codeP, cP);
        len = strlen(nP);
        nameP = new char[len + 1];
        strcpy(nameP, nP);
        len = strlen(EP);
        highestEduP = new char[len + 1];
        strcpy(highestEduP, EP);
        len = strlen(QP);
        highestProQuaP = new char[len + 1];
        strcpy(highestProQuaP, QP);
        grade = g;
    }
    void showData()
    {
        cout << "\n\nThe details of officer are as follows:\n";
        cout << "Code: " << codeP << endl;
        cout << "Name: " << nameP << endl;
        cout << "Grade: " << grade << endl;
        cout << "Highest Edu: " << highestEduP << endl;
        cout << "Highest Qual: " << highestProQuaP << endl;
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
    t.setData("PHY101", "ManishKumar", "Physics", "ThinkIIT", "Mtech", "PhD");
    regular r;
    r.setData("TYPR101", "Amol", 40);
    casual c;
    c.setData("TYPC101", "Vinay", 1000);
    officer o;
    o.setData("OFFI101", "KumarSingh", 'A', "NDA", "INDIAN AIR FORCE");
    t.showData();
    r.showData();
    c.showData();
    o.showData();
    return 0;
}
