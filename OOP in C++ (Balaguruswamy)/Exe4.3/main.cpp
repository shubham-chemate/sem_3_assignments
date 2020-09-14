#include <iostream>

using namespace std;

int** readMatrix(int, int=3);
void showMatrix(int **mat, int m, int n=3);

int main()
{
    int** mat = readMatrix(2);

    showMatrix(mat, 2);

    return 0;
}

int** readMatrix(int m, int n)
{
    int** mat = new int*[n];
    for(int i=0; i<n; i++){
        mat[i] = new int[m];
    }

    cout << "Enter elements:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << j+1 << " - ";
            cin >> mat[i][j];
        }
    }

    return mat;
}

void showMatrix(int **mat, int n, int m)
{
    cout << "\nMatrix:\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
