#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

class staff
{
protected:
    char *nameP;
    char *codeP;
public:
    void setName()
    {
        cout << "Enter name: " << endl;
        char str[100];
        fflush(stdin);
        gets(str);
        int len = strlen(str);
        nameP = new char[len + 1];
        strcpy(nameP, str);
        cout << "Enter code: " << endl;
        fflush(stdin);
        gets(str);
        len = strlen(str);
        codeP = new char[len + 1];
        strcpy(codeP, str);
    }
    void showName()
    {
        cout << "\n\nName: " << nameP << endl << "Code: " << codeP << endl;
    }
};

class teacher
{
private:
    char* subjectP;
    char* pubP;
    staff forTeacher;
public:
    void setData()
    {
        forTeacher.setName();
        char str[100];
        cout << "Enter Subject: \n";
        fflush(stdin);
        gets(str);
        int len = strlen(str);
        subjectP = new char[len + 1];
        strcpy(subjectP, str);
        cout << "Enter Publications: \n";
        fflush(stdin);
        gets(str);
        len = strlen(str);
        pubP = new char[len + 1];
        strcpy(pubP, str);
    }
    void showData()
    {
        cout << "Showing data of teacher:\n";
        forTeacher.showName();
        cout << "Subject: " << subjectP << endl << "Publications: " << pubP << endl;
    }
};

class typist
{
protected:
    int speed;
    staff forTypist;
public:
    void setSpeed()
    {
        forTypist.setName();
        cout << "Enter speed: \n";
        cin >> speed;
    }
    void showSpeed()
    {
        forTypist.showName();
        cout << "Speed : " << speed << endl;
    }
};

class regular
{
private:
    typist forRegular;
    float salary;
public:
    void setData()
    {
        forRegular.setSpeed();
        cout << "Enter salary for Regular Typist: \n";
        cin >> salary;
    }
    void showData()
    {
        cout << "Showing data of regular typist: \n";
        forRegular.showSpeed();
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    teacher T;
    T.setData();
    regular R;
    R.setData();
    T.showData();
    R.showData();
    return 0;
}
