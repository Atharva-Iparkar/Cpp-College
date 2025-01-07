# SORTING
# CREATING A LIST
Marks = []
n = int(input("Enter no. of students : "))
for i in range(0, n):
    m = float(input("Enter marks : "))
    Marks.append(m)
print("List is : ")
print(Marks)

# BUBBLE SORT
def bubbleSort():
    for i in range(0, n):
        for j in range(0, n-i-1):
            if Marks[j] > Marks[j+1]:
                Marks[j],Marks[j+1] = Marks[j+1],Marks[j]
    print("Sorted List via Bubble Sort is : ")
    print(Marks)

# SELECTION SORT
def selectionSort():
    for i in range(0,n):
        min = i
        for j in range(i+1,n):
            if(Marks[min] > Marks[j]):
                min = j
        Marks[min],Marks[i] = Marks[i],Marks[min]
    print("Sorted List via Selection Sort is : ")
    print(Marks)

# TOP 5 SCORES
def topScores():
    print("Top 5 scores are : ")
    for i in range(1,6):
        print(Marks[-i])

choice = int(input(
    "1 : Bubble Sort    ""\n"
    "2 : Selection Sort    ""\n"
    "Enter your choice :"))

if choice == 1:
    bubbleSort()
    topScores()
if choice == 2:
    selectionSort()
    topScores()
