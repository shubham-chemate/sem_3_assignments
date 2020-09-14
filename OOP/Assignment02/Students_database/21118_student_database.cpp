#include <iostream>
#include <string>

using namespace std;

class PersonalInfo
{
private:
    string blood_group, driving_licence_no, DOB, address;
    int telephone_no;

public:
    PersonalInfo() {}
    void getData()
    {
        cout << "Enter DOB (DD/MM/YYYY) : ";
        cin >> DOB;
        cout << "Enter blood group : ";
        cin >> blood_group;
        cout << "Enter Address : ";
        fflush(stdin); // Clearing input buffer
        getline(cin, address);
        cout << "Enter Driving Licence Number : ";
        cin >> driving_licence_no;
        cout << "Enter Telephone Number : ";
        cin >> telephone_no;
    }
    inline void showData()
    {
        cout << "Date of Birth (DD/MM/YYYY) : " << DOB << endl;
        cout << "Blood Group : " << blood_group << endl;
        cout << "Address : " << address << endl;
        cout << "Driving Licence Number : " << driving_licence_no << endl;
        cout << "Telephone Number : " << telephone_no << "\n\n";
    }
    ~PersonalInfo() {}

    friend class Student;
};

class Student
{
private:
    static int cnt;
    string name, Class;
    int rollNo, div;
    PersonalInfo personal_info;
public:
    Student() {
        cnt++;
    }
    Student(const Student &s)
    {
        name = s.name;
        Class = s.Class;
        div = s.div;
        rollNo = s.rollNo;
        personal_info = s.personal_info;
        cnt++;
    }
    static int getStudentCount()
    {
        return cnt;
    }
    void getData()
    {
        try {
            cout << "Enter roll number (between 1 to 86) : ";
            cin >> rollNo;
            if(rollNo < 1 || rollNo > 86)
                throw 1;

            cout << "Enter name : ";
            fflush(stdin);
            getline(cin, name);

            cout << "Enter class (class should be FE, SE, TE, BE) : ";
            cin >> Class;
            if (!(Class != "FE" || Class != "SE" || Class != "TE" || Class != "BE"))
                throw 2;

            cout << "Enter div (div should be in 1 to 11) : ";
            cin >> div;
            if(div < 1 || div > 11)
                throw 3;

            cout << "Enter Personal Info : \n";
            personal_info.getData();
        }
        catch(int x) {
            if(x == 1)
                cout << "ERROR: Invalid Roll Number. It should be between (1 and 86)\n";
            if(x == 3)
                cout << "ERROR: Invalid Division. It should be between (1 and 11).\n";
            if(x == 2)
                cout << "ERROR: Invalid Class. It should be FE, SE, TE or BE.\n";
            exit(1);
        }
    }
    inline void showData()
    {
        cout << "Student Info for roll number : " << rollNo << endl;
        cout << "Name : " << name << endl;
        cout << "Class : " << Class << ", Div : " << div << endl;
        personal_info.showData();
    }
    ~Student()
    {
        cout << "The data of student of roll number " << rollNo << " is deleted from database\n";
        cnt--;
    }
};

int Student::cnt = 0;

int main()
{
    int student_count = 0;
    cout << "For how many students do you want to create database?? ";
    cin >> student_count;
    Student* student_array = new Student[student_count];
    for(int i=0; i<student_count; i++) {
        cout << "\nEnter data for student number : " << i + 1 << endl;
        student_array[i].getData();
        cout << "Student number " << i + 1 << " is created successfully.\n";
    }

    cout << "\nThere are " << Student::getStudentCount() << " students in the database.\n";

    for(int i=0; i<student_count; i++) {
        cout << "\n";
        student_array[i].showData();
    }

    // Copy Constructor
    Student s(student_array[0]);
    cout << "=========Copy Constructor (Used for copying data of 1st Student)=========" << endl;
    s.showData();

    delete[] student_array;
    return 0;
}
