#include <iostream>
#include <string>

using namespace std;

class publication
{
protected:
    string title;
    float price;
public:
    publication() {}
    publication(string title, float price)
    {
        this->title = title;
        this->price = price;
    }
};

class book : public publication
{
private:
    int page_count;

public:
    book() {}
    book(string title, float price, int page_count) : publication(title, price)
    {
        this->page_count = page_count;
    }
    void getData()
    {
        cout << "Enter the title of book : ";
        cin >> title;
        cout << "Enter the price of book : ";
        cin >> price;
        cout << "Enter the number of pages in a book : ";
        cin >> page_count;
    }
    void showData()
    {
        cout << "\nThe details of the Book are as follows : \n";
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
        cout << "Number of Pages : " << page_count << endl;
    }
};

class tape : public publication
{
private:
    float playing_time;

public:
    tape() {}
    tape(string title, float price, float playing_time) : publication(title, price)
    {
        this->playing_time = playing_time;
    }
    void getData()
    {
        cout << "Enter the title of Tape : ";
        cin >> title;
        cout << "Enter the price of Tape : ";
        cin >> price;
        cout << "Enter the playing time of Tape in minutes : ";
        cin >> playing_time;
    }
    void showData()
    {
        cout << "\nThe details of the Tape are as follows : \n";
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
        cout << "Total Playing time in minutes : " << playing_time << endl;
    }
};

int main()
{
    book mybook;
    mybook.getData();
    cout << endl;
    tape mytape;
    mytape.getData();

    mybook.showData();
    mytape.showData();
    return 0;
}
