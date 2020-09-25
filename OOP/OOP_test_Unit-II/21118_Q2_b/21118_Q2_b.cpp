#include <iostream>
#include <string>

using namespace std;

void Swap(string* str1, string* str2)
{
    string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void SortString(string* strarr, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j  = i+1; j < n; j++) {
            if (strarr[i] > strarr[j])
                Swap(&strarr[i], &strarr[j]);
        }
    }
}

int main()
{
    int n;
    cout << "How many days? ";
    cin >> n;

    string *days = new string[n];
    cout << "Enter days one by one:\n";
    for (int i = 0; i < n; i++)
        cin >> days[i];

    SortString(days, n);

    cout << "Alphabetically Sorted Days : ";
    for (int i = 0; i < n; i++)
        cout << days[i] << " ";

    cout << endl;
    return 0;
}

//Output:
//How many days? 5
//Enter days one by one:
//Sun
//Mon
//Wed
//Thu
//Fri
//Alphabetically Sorted Days : Fri Mon Sun Thu Wed
