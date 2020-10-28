import math

def CholeskyDecomposition (R):

    a = []
    M = []
        
    # Number of rows of transpose matrix == number of columns
    n = len (list(map(list, zip(*R)))) 

    # Define a, M
    a = [[0 for x in range(n)] for y in range(n)]
    M = [[0 for x in range(n)] for y in range(n)]

    for i in range(n):
        for j in range(n):
            a[i][j] = R[i][j]
            if i == j:
                M[i][j] = 1

    for i in range(n):  
        for j in range(n):
            U = a[i][j]
            for h in range (0,i,1):
                U = U - M[i][h] * M[j][h]
            if j == i:
                M[i][i] = math.sqrt(U)
            else:
                M[j][i] = U / M[i][i]
    return M


# Code below is for check function  ##############################################

#R = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6] , [0.7, 0.8, 0.9]]
R = [[1, 2, 3], [4, 5, 6] , [7, 8, 9]]

result = CholeskyDecomposition(R)

size = len(result)

for i in range(size):
    print(result[i])
