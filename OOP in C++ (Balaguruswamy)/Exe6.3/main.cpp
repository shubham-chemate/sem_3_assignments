#include <iostream>
#include <string.h>

using namespace std;

class book
{
private:
    char author[40];
    char title[40];
    char publisher[40];
    int pos;
public:
    void setData()
    {
        cout << "Enter author, title, publisher and pos: " << endl;
        cin >> author >> title >> publisher >> pos;
    }
    void showData()
    {
        cout << "The book details are as follows: " << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock Position: " << pos << endl;
    }
    char* getTitle()
    {
        return (title);
    }
    char* getAuthor()
    {
        return (author);
    }
};

int main()
{
    book b[5];
    for(int i=0; i<5; i++){
        b[i].setData();
    }

    char author[40];
    char title[40];
    cout << "Please enter the title and author of book: " << endl;
    cin >> title>> author;

    int test = 0;
    for(int i=0; i<5; i++){
        if((strcmp(b[i].getAuthor(), author) == 0) && (strcmp(b[i].getTitle(), title) == 0)){
            b[i].showData();
            test = 1;
            break;
        }
    }
    if(test == 0){
        cout << "The book you have entered is currently unavailable in the inventory." <<endl;
    }

    return 0;
}
