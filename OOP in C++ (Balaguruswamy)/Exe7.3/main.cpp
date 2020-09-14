#include <iostream>

using namespace std;

class MAT
{
private:
    int **p;
    int row, col;
public:
    MAT(int m, int n)
    {
        row = m;
        col = n;
        p = new int*[m];
        for(int i=0; i<n; i++){
            p[i] = new int[n];
        }
        cout << "\n\nSpace is created for matrix." << endl;
    }
    MAT(){}
    void setElement(int i, int j, int value)
    {
        p[i][j] = value;
    }
    MAT operator+(MAT m2)
    {
        MAT temp(row, col);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                temp.p[i][j] = p[i][j] + m2.p[i][j];
            }
        }
        return temp;
    }
    void showElement(int i, int j)
    {
        cout << p[i][j] << " ";
    }
    int getRow()
    {
        return row;
    }
    int getColumn()
    {
        return col;
    }
    friend MAT operator*(MAT m1, MAT m2);
};

MAT operator*(MAT m1, MAT m2)
{
    int m, n;
    m = m1.getRow();
    n = m1.getColumn();
    MAT temp(m, n);
    int sum;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum = 0;
            for(int k=0; k<m; k++){
                sum = sum + (m1.p[i][k] * m2.p[k][j]);
            }
            temp.p[i][j] = sum;
            //temp.p[i][j] = (m1.p[i][0] * m2.p[0][j]) + (m1.p[i][1] * m2.p[1][j]) + (m1.p[i][2] * m2.p[2][j]);
        }
    }
    return temp;

}

const int sizem = 2;
int main()
{
    MAT arr[sizem];
    cout << "Enter size of matrix: " << endl;
    int m, n;
    cin >> m >> n;
    for(int k=0; k<sizem; k++){
        arr[k] = MAT(m,n);
        cout << "Enter elements of matrix: " << endl;
        int value;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> value;
                arr[k].setElement(i, j, value);
            }
        }
        cout << "Matrix-" << k+1 << " initialized." << endl << endl;
    }

    cout << "Showing matrix-1:" << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[0].showElement(i,j);
        }
        cout << endl;
    }

    cout << "Showing matrix-2:" << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[1].showElement(i,j);
        }
        cout << endl;
    }

    MAT sum;
    sum = arr[0] + arr[1];

    cout << "\n\nPerforming sum....\n\n";
    cout << "Sum is\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum.showElement(i,j);
        }
        cout << endl;
    }

    MAT product;
    product = arr[0] * arr[1];
    cout << "\n\nPerforming product....\n\n";
    cout << "Product is\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            product.showElement(i,j);
        }
        cout << endl;
    }

    return 0;
}
