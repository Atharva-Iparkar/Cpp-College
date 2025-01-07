mat = []
for i in range (0,2):
    a = []
    for j in range (0,2):
        n = int(input("Enter no. : "))
        a.append(n)
    mat.append(a)
for i in range(0, 2):
    for j in range(0,2):
        print(mat[i][j], end=" ")
    print()

