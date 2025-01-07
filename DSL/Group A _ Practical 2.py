# FINDING SADDLE POINT IN MATRIX
mat = []
m = int(input("Enter no. of rows : "))
n = int(input("Enter no. of cols : "))
for i in range(0,m):
    a = []
    for j in range(0,n):
        num = int(input("Enter no. : "))
        a.append(num)
    mat.append(a)
for i in range(0,m):
    for j in range(0,n):
        print(mat[i][j], end=" ")
    print()
def saddle():
    for i in range(0,m):
        min_row = mat[i][0]
        col = 0
        # min = min_row
        for j in range(0,n):
            if(min_row > mat[i][j]):
                min_row = mat[i][j]
                col = j
        saddlepoint = True
        max = mat[0][col]
        for k in range(0,m):
            if(mat[k][col] > max):
                saddlepoint = False
                break
        if(min_row == max):
            return min_row, i, col
            break
if(saddle()):
    val,col,row = saddle()
    print("Saddle point is : ",val,"\t","Position of saddle point is : ",col,row)
else:
    print("No Saddlepoint found")
