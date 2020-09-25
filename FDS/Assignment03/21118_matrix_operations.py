# DS Assignment 03 : Operations on Matrix
# Name : Shubham Chemate
# Roll Number : 21118
class Matrix():

    # Constructor function : Creates empty list to store matrix elements
    def __init__(self, rows=0, columns=0):
        self.rows = rows
        self.columns = columns
        self.mymatrix = [[0] * self.columns for _ in range(self.rows)]

    # function to read matrix
    def readMatrix(self):
        while (self.rows == 0 or self.columns == 0):
            self.rows = int(input("Enter number of rows for matrix : "))
            self.columns = int(input("Enter number of columns for matrix: "))

            if (self.rows == 0 or self.columns == 0):
                print("Values of rows and columns are invalid. Enter Again.")
            else:
                break

        self.mymatrix = [[0] * self.columns for _ in range(self.rows)]

        print("Enter Elements for matrix: ")
        for i in range(self.rows):
            for j in range(self.columns):
                print("Enter element at index (", i, ", ", j, ") : ", end="")
                self.mymatrix[i][j] = int(input())

    # function checks for empty matrix : returns boolean value
    def isEmpty(self):
        if (self.rows == 0 or self.columns == 0):
            return True
        else:
            return False

    # function returns element at index (i, j)
    def getElement(self, i, j):
        return self.mymatrix[i][j]

    # function assign value x to the element at index (i, j)
    def setElement(self, i, j, x):
        self.mymatrix[i][j] = x

    # function returns number of rows of matrix
    def getRowCount(self):
        return self.rows

    # function returns number of columns of matrix
    def getColCount(self):
        return self.columns

    # function adds two matrices : returns addition matrix
    def add(self, matrix_B):
        if (self.rows != matrix_B.getRowCount()) or (self.columns != matrix_B.getColCount()):
            return Matrix()
        else:
            sum_matrix = Matrix(self.rows, self.columns)
            for i in range(self.rows):
                for j in range(self.columns):
                    s = self.mymatrix[i][j] + matrix_B.getElement(i, j)
                    sum_matrix.setElement(i, j, s)
            return sum_matrix

    # function substracts two matrices : returns substraction matrix
    def substract(self, matrix_B):
        if (self.rows != matrix_B.getRowCount()) or (self.columns != matrix_B.getColCount()):
            return Matrix()
        else:
            diff_matrix = Matrix(self.rows, self.columns)
            for i in range(self.rows):
                for j in range(self.columns):
                    s = self.mymatrix[i][j] - matrix_B.getElement(i, j)
                    diff_matrix.setElement(i, j, s)
            return diff_matrix

    # function multiply two matrices : return multiplied matrix
    def multiply(self, matrix_B):
        if self.columns != matrix_B.getRowCount():
            return Matrix()
        else:
            prod_matrix = Matrix(self.rows, matrix_B.getColCount())
            for i in range(self.rows):
                for j in range(matrix_B.getColCount()):
                    x = 0
                    for k in range(self.columns):
                        x = x + (self.mymatrix[i][k] *
                                 matrix_B.getElement(k, j))
                    prod_matrix.setElement(i, j, x)
            return prod_matrix

    # function returns transpose of matrix
    def getTranspose(self):
        transpose_matrix = Matrix(self.columns, self.rows)

        for i in range(self.rows):
            for j in range(self.columns):
                transpose_matrix.setElement(j, i, self.mymatrix[i][j])

        return transpose_matrix

    # function prints the matrix
    def Print(self):
        for i in range(self.rows):
            for j in range(self.columns):
                print(self.mymatrix[i][j], end="\t")
            print()


def main():

    while(True):

        print("\n--------Enter--------\n0 to Exit\n1 for matrix addition\n2 for matrix substraction\n3 for matrix multiplication\n4 to find transpose of matrix")
        choice = int(input("Enter here: "))

        if choice == 0:
            break

        elif choice == 4:
            matrix_A = Matrix()
            matrix_A.readMatrix()
            print("\nGiven matrix is : ")
            matrix_A.Print()
            A_transpose = matrix_A.getTranspose()
            print("\nTranspose of given matrix is : ")
            A_transpose.Print()

        elif choice == 1 or choice == 2 or choice == 3:
            matrix_A = Matrix()
            matrix_A.readMatrix()
            matrix_B = Matrix()
            matrix_B.readMatrix()
            print("\nFirst matrix is : ")
            matrix_A.Print()
            print("\nSecond Matrix is : ")
            matrix_B.Print()

            if choice == 1:
                add_matrix = matrix_A.add(matrix_B)
                if (add_matrix.isEmpty()):
                    print("\nThe ADDITION of matrices is NOT POSSIBLE.")
                else:
                    print("\nThe addition of matrices is : ")
                    add_matrix.Print()

            elif choice == 2:
                sub_matrix = matrix_A.substract(matrix_B)
                if (sub_matrix.isEmpty()):
                    print("\nThe SUBSTRACTION of matrices is NOT POSSIBLE.")
                else:
                    print("\nThe substraction of matrices is : ")
                    sub_matrix.Print()

            else:
                prod_matrix = matrix_A.multiply(matrix_B)
                if (prod_matrix.isEmpty()):
                    print("\nThe MULTIPLICATION of matrices is NOT POSSIBLE.")
                else:
                    print("\nThe product of matrices is : ")
                    prod_matrix.Print()

        else:
            print("\nERROR : Invalid Choice. Choose Again.")


main()
