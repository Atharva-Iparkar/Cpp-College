A = []
B = []
Res = []
row = int(input("Enter no. of rows : "))
cols = int(input("Enter no. of cols : "))
def CreateMatrix(X):
    for i in range(0,row):
        temp = []
        for j in range(0,cols):
            num = int(input("Enter a no. : "))
            temp.append(num)
        X.append(temp)
    print(X)

def Addition():
    for i in range(0, row):
        temp = []
        for j in range(0, cols):
            num = 0
            temp.append(num)
        Res.append(temp)

    for i in range(0,row):
        for j in range(0,cols):
            Res[i][j] = A[i][j] + B[i][j]
    print(Res)

def Substraction():
    for i in range(0,row):
        for j in range(0,cols):
            Res[i][j] = A[i][j] - B[i][j]
    print(Res)

def Multiplication():
    for i in range(0,row):
        for j in range(0,cols):
            for k in range(0,cols):
                Res[i][j] = Res[i][j] + (A[i][k] * B[j][k])
    print(Res)

def Transpose():
    for i in range(0,row):
        for j in range(0,cols):
            Res[j][i] = A[i][j]
    print(Res)

CreateMatrix(A)
CreateMatrix(B)
print("Addition of matrix is : ")
Addition()
print("Substraction of matrix is : ")
Substraction()
print("Transpose of matrix is : ")
Transpose()
print("Multipication of matrix is : ")
Multiplication()
print("Length of matrix A is : ",(len(A)))
