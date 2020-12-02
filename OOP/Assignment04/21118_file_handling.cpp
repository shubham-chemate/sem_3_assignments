#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int id = 0;
    while(true) {
        int choice;
        cout << "Enter\n0 to exit\n1 to write to a file\n2 to append to file\n3 to read from file\n:";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) {
            ofstream write_file;
            write_file.open("userRecord.txt");
            string str;

            // writing user info (name and email) to the file.
            int n;
            cout << "How many users: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter name: ";
                fflush(stdin);
                getline(cin, str);
                write_file << "User id: " << id++ << "\nName: " << str << endl;
                cout << "Enter email: ";
                getline(cin, str);
                write_file << "Email: " << str << "\n\n";
            }
            write_file.close();
        }
        else if (choice == 2) {
            ofstream append_file;
            append_file.open("userRecord.txt", ios :: app);
            if (!append_file.is_open()) {
                cout << "file not found";
                continue;
            }
            string str;

            // writing user info (name and email) to the file.
            int n;
            cout << "How many users: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter name: ";
                fflush(stdin);
                getline(cin, str);
                append_file << "User id: " << id++ << "\nName: " << str << endl;
                cout << "Enter email: ";
                getline(cin, str);
                append_file << "Email: " << str << "\n\n";
            }
            append_file.close();
        }
        else {
            // Reading information of the file
            cout << "\n~~~~~~~~~~Reading From the File~~~~~~~~~~\n";
            ifstream read_file;
            string str;
            read_file.open("userRecord.txt");
            while (read_file) {
                getline(read_file, str);
                cout << str << endl;
            }
            read_file.close();
        }
    }

    return 0;
}
