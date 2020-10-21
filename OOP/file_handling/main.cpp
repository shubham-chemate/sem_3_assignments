#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream write_file;
    write_file.open("userRecord.txt");
    string str;

    // writing user info (name and email) to the file.
    int n;
    cout << "How many users: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter name: ";
        fflush(stdin); getline(cin, str);
        write_file << "User id: " << i << "\nName: " << str << endl;
        cout << "Enter email: ";
        getline(cin, str);
        write_file << "Email: " << str << "\n\n";
    }
    write_file.close();

    // Reading information of the file
    cout << "\n~~~~~~~~~~Reading From the File~~~~~~~~~~\n";
    ifstream read_file;
    read_file.open("userRecord.txt");
    while (read_file) {
        getline(read_file, str);
        cout << str << endl;
    }
    read_file.close();

    return 0;
}
