A_rows = 3
A_columns = 2
A = [[1, 2], [3, 4], [5, 6]]

B_rows = 2
B_columns = 3
B = [[1, 2, 3], [4, 5, 6]]

C = [[0] * B_columns for _ in range(A_rows)]

for i in range(A_rows):
    for j in range(B_columns):
        x = 0
        for k in range(A_columns):
            x = x + (A[i][k] * B[k][j])

        C[i][j] = x

print(C)
