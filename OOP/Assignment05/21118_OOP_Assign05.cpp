// OOP Assignment 5 by Shubham (Roll No: 21118)

#include <bits/stdc++.h>

using namespace std;

const int D = 100;

template <class T>
void SelectionSort(T arr[], int n)    // sort using selection sort algorithm
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

template <class T>
void getInput(T arr[D], int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Enter element no - " << i + 1 << ": ";
        cin >> arr[i];
    }
}

template <class T>
void PrintArray(T arr[D], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int int_arr[D];
    float float_arr[D];
    int n;
    while (true)
    {
        cout << "Which array do you want to sort??\n";
        cout << "1 for integer array\n2 for float array\n0 to exit\n:";
        int choice = 0;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter size of array: "; cin >> n;
            getInput(int_arr, n);
            cout << "Before Sorting: ";
            PrintArray(int_arr, n);
            SelectionSort(int_arr, n);
            cout << "After Sorting: ";
            PrintArray(int_arr, n);
        }
        else if (choice == 2)
        {
            cout << "Enter size of array: "; cin >> n;
            getInput(float_arr, n);
            cout << "Before Sorting: ";
            PrintArray(float_arr, n);
            SelectionSort(float_arr, n);
            cout << "After Sorting: ";
            PrintArray(float_arr, n);
        }
        else if (choice == 0)
            break;
        else
            cout << "INVALID CHOICE. Try Again.\n";
    }
    return 0;
}
