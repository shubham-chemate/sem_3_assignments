#include <iostream>

using namespace std;

int** readMatrix(int, int);

int main()
{
    cout << "Enter m, n\n";
    int m, n;
    cin >> m >> n;

    int** mat = readMatrix(m, n);

    cout << "\nMatrix:\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int** readMatrix(int m, int n)
{
    int** mat = new int*[m];
    for(int i=0; i<m; i++){
        mat[i] = new int[n];
    }

    cout << "Enter elements:\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << j+1 << " - ";
            cin >> mat[i][j];
        }
    }

    return mat;
}
