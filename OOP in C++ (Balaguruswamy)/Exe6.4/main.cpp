#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class book
{
private:
    char author[40];
    char title[40];
    char publisher[40];
    int pos;
    float price;
public:
    void setData()
    {
        cout << "Enter author, title, publisher, price and pos: " << endl;
        cin >> author >> title >> publisher >> price >> pos;
    }
    void showData()
    {
        cout << endl << "The book details are as follows: " << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock Position: " << pos << endl;
        cout << "Price: " << price << endl;
    }
    void updatePrice(float val)
    {
        price = val;
    }
    char* getTitle()
    {
        return (title);
    }
    char* getAuthor()
    {
        return (author);
    }
    void getCopies(int c)
    {
        pos = pos - c;
        cout << "Successfull!!!" << endl;
    }
};

int scount = 0;
int fcount = 0;

const int cap = 1;

int main()
{
    book b[cap];
    for(int i=0; i<cap; i++){
        b[i].setData();
    }


    cout << "Enter title of book to update price: " << endl;
    fflush(stdin);
    char titleToPrice[40];
    gets(titleToPrice);
    cout << "Enter new price: " << endl;
    float newPrice;
    cin >> newPrice;
    for(int i=0; i<cap; i++){
        if(strcmp(titleToPrice, b[i].getTitle()) == 0){
            b[i].updatePrice(newPrice);
            break;
        }
    }

    do{

    char author[40];
    char title[40];
    cout << "Please enter the title and author of book: " << endl;
    cin >> title >> author;

    int test = 0;
    int copies;
    for(int i=0; i<cap; i++){
        if((strcmp(b[i].getAuthor(), author) == 0) && (strcmp(b[i].getTitle(), title) == 0)){
            b[i].showData();
            cout << "Please enter the number of copies required: " << endl;
            cin >> copies;
            b[i].getCopies(copies);
            test = 1;
            scount++;
            break;
        }
    }
    if(test == 0){
        fcount++;
        cout << "The book you have entered is currently unavailable in the inventory." <<endl;
    }

    cout << "Press 11 to continue and 00 to exit" << endl;
    int loopFlow;
    cin >> loopFlow;
    if(loopFlow == 00){
        break;
    }

    }while(1);

    cout << endl << endl << "Number of Successful transactions is " << scount << endl;
    cout << "Number of Unsuccessful transactions is " << fcount << endl << endl;


    cout << endl << "===================================" << endl;
    cout << "New status of the store is..." << endl;
    for(int i=0; i<cap; i++){
        b[i].showData();
    }

    return 0;
}
