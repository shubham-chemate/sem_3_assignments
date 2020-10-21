#include <iostream>
#include <string>

using namespace std;

class publication
{
protected:
    string title;
    float price;
public:
    void getPubDetail()
    {
        cout << "Enter the title : ";
        fflush(stdin);
        getline(cin, title);
        cout << "Enter the price : ";
        try {
            cin >> price;
            if (price < 0) throw(0);
        }
        catch(...) {
            price = 0;
        }
    }
    void showPubDetail()
    {
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }
};

class book : public publication
{
private:
    int page_count;

public:
    void getBookDetail()
    {
        cout << "Enter the details of book : \n";
        getPubDetail();
        try {
            cout << "Enter the number of pages : ";
            cin >> page_count;
            if (page_count < 0) throw(0);
        }
        catch(...) {
            page_count = 0;
        }
    }
    void showBookDetail()
    {
        cout << "\nThe details of the Book are as follows : \n";
        showPubDetail();
        cout << "Number of Pages : " << page_count << endl;
    }
};

class tape : public publication
{
private:
    float playing_time;

public:
    void getTapeDetail()
    {
        cout << "Enter the details of Tape : \n";
        getPubDetail();
        try {
            cout << "Enter the playing time (in minutes) : ";
            cin >> playing_time;
            if (playing_time < 0) throw(0);
        }
        catch(...) {
            playing_time = 0;
        }
    }
    void showTapeDetail()
    {
        cout << "\nThe details of the Tape are as follows : \n";
        showPubDetail();
        cout << "Total Playing time in minutes : " << playing_time << endl;
    }
};

int main()
{
    book mybook;
    mybook.getBookDetail();
    cout << endl;
    tape mytape;
    mytape.getTapeDetail();

    mybook.showBookDetail();
    mytape.showTapeDetail();
    return 0;
}
