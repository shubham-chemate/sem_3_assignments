# DS Assignment 03 : Operations on Matrix
# Name : Shubham Chemate
# Roll Number : 21118

class Matrix():

    # Constructor function : Creates 2D list to store matrix elements
    def __init__(self, rows=0, columns=0):

        if rows != 0 and columns != 0:
            self.rows = rows
            self.columns = columns
            self.mymatrix = [[0] * self.columns for _ in range(self.rows)]
            return

        while (rows == 0 or columns == 0):
            self.rows = int(input("Enter number of rows for matrix : "))
            self.columns = int(input("Enter number of columns for matrix: "))

            if (self.rows == 0 or self.columns == 0):
                print("Values of row and column are invalid. Enter Again.")
            else:
                break

        self.mymatrix = [[0] * self.columns for _ in range(self.rows)]

        print("Enter Elements for matrix: ")
        for i in range(self.rows):
            for j in range(self.columns):
                print("Enter element at index (", i, ", ", j, ") : ", end="")
                self.mymatrix[i][j] = int(input())

    # function returns element at index (i, j)
    def getElement(self, i, j):
        return self.mymatrix[i][j]

    # function assign value x to the element at index (i, j)
    def addElement(self, i, j, x):
        self.mymatrix[i][j] = x

    # function returns number of rows of matrix
    def getRowCount(self):
        return self.rows

    # function returns number of columns of matrix
    def getColCount(self):
        return self.columns

    # function adds two matrice : returns addition matrix
    def add(self, matrix_B):

        sum_matrix = Matrix(self.rows, self.columns)

        for i in range(self.rows):
            for j in range(self.columns):
                s = self.mymatrix[i][j] + matrix_B.getElement(i, j)
                sum_matrix.addElement(i, j, s)

        return sum_matrix

    # function substracts two matrices : returns substraction matrix
    def substract(self, matrix_B):
        diff_matrix = Matrix(self.rows, self.columns)

        for i in range(self.rows):
            for j in range(self.columns):
                s = self.mymatrix[i][j] - matrix_B.getElement(i, j)
                diff_matrix.addElement(i, j, s)

        return diff_matrix

    # function multiply two matrices : return multiplied matrix
    def multiply(self, matrix_B):
        prod_matrix = Matrix(self.rows, matrix_B.getColCount())

        for i in range(self.rows):
            for j in range(matrix_B.getColCount()):
                x = 0
                for k in range(self.columns):
                    x = x + (self.mymatrix[i][k] * matrix_B.getElement(k, j))
                prod_matrix.addElement(i, j, x)

        return prod_matrix

    # function returns transpose of matrix
    def getTranspose(self):
        transpose_matrix = Matrix(self.columns, self.rows)

        for i in range(self.rows):
            for j in range(self.columns):
                transpose_matrix.addElement(j, i, self.mymatrix[i][j])

        return transpose_matrix

    def Print(self):
        for i in range(self.rows):
            for j in range(self.columns):
                print(self.mymatrix[i][j], end="\t")
            print()


def main():

    while(True):

        print("\nEnter\n0 to Exit\n1 for matrix addition\n2 for matrix substraction\n3 for matrix multiplication\n4 to find transpose of matrix")
        choice = int(input("Enter here: "))

        if choice == 0:
            break

        elif choice == 4:
            matrix_A = Matrix()
            print("\nGiven matrix is : ")
            matrix_A.Print()
            matrix_A_transpose = matrix_A.getTranspose()
            print("\nTranspose of given matrix is : ")
            matrix_A_transpose.Print()

        elif choice == 1 or choice == 2 or choice == 3:
            matrix_A = Matrix()
            matrix_B = Matrix()
            print("\nFirst matrix is : ")
            matrix_A.Print()
            print("\nSecond Matrix is : ")
            matrix_B.Print()

            if choice == 1:
                if (matrix_A.getRowCount() != matrix_B.getRowCount()) or (matrix_A.getColCount() != matrix_B.getColCount()):
                    print("\nThe ADDITION of matrices is NOT POSSIBLE.")
                else:
                    add_matrix = matrix_A.add(matrix_B)
                    print("\nThe addition of matrices is : ")
                    add_matrix.Print()

            elif choice == 2:
                if (matrix_A.getRowCount() != matrix_B.getRowCount()) or (matrix_A.getColCount() != matrix_B.getColCount()):
                    print("\nThe SUBSTRACTION of matrices is NOT POSSIBLE.")
                else:
                    sub_matrix = matrix_A.substract(matrix_B)
                    print("\nThe substraction of matrices is : ")
                    sub_matrix.Print()
            else:
                if matrix_A.getColCount() != matrix_B.getRowCount():
                    print("\nThe MULTIPLICATION of matrices is NOT POSSIBLE.")
                else:
                    prod_matrix = matrix_A.multiply(matrix_B)
                    print("\nThe product of matrices is : ")
                    prod_matrix.Print()

        else:
            print("\nERROR : Invalid Choice. Choose Again.")


main()
