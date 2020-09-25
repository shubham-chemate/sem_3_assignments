#include <iostream>

using namespace std;

float getAverage(float* numbers, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += numbers[i];
    return (sum / n);
}

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;
    float *numbers = new float[n];
    cout << "Enter numbers separated by space: ";
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    float (*ptr_to_avg)(float*, int) = &getAverage;
    cout << "The average of numbers is ";
    cout << (*ptr_to_avg)(numbers, n) << endl;
    return 0;
}

//Output:
//How many numbers? 4
//Enter numbers separated by space: 1.2 3.2 4.2 5.8
//The average of numbers is 3.6
