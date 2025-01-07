# SORTING
# CREATING A LIST
Marks = []
n = int(input("Enter no. of students : "))
for i in range(0, n):
    m = int(input("Enter marks : "))
    Marks.append(m)
print("List is : ")
print(Marks)

# INSERTION SORT
def insertionSort():
    for i in range(1, n):
        temp = Marks[i]
        j = i - 1
        while j >= 0 and Marks[j] > temp:
            Marks[j + 1] = Marks[j]
            j = j - 1
        Marks[j + 1] = temp
    print("Sorted list via Insertion Sort is : ")
    print(Marks)

# SHELL SORT
def shellSort():
    n = int(input("Enter the number of students : "))
    marks = []
    for i in range(0, n):
        a = int(input("Enter the marks of students : "))
        marks.append(a)
    print("Marks of students : ", marks)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = marks[i]
            j = i
            while j >= gap and marks[j - gap] > temp:
                marks[j] = marks[j - gap]
                j = j - gap
            marks[j] = temp
        gap = gap // 2
    print("Sorted list via Shell Sort is : ")
    print(Marks)

# TOP FIVE SCORES
def top_five():
    print("Top 5 Scores : ")
    top5 = Marks[::-1]
    print("Top 5 scores: ", top5[:5])

choice = int(input(
    "1 : Insertion Sort    ""\n"
    "2 : Shell Sort    ""\n"
    "Enter your choice : "))

if choice == 1:
    insertionSort()
    top_five()
if choice == 2:
    shellSort()
    top_five()