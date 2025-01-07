marks = []
n = int(input("Enter no. of students : "))
for i in range(0,n):
    a = int(input("Enter marks of students : "))
    marks.append(a)
print(marks)

def average():
    sum = 0
    for i in range(0,n):
        sum = sum + marks[i]
        avg = sum/n
    print("Average of  students : ",avg)
average()

def absent():
    absent = 0
    for i in range(0,n):
        if marks[i] == -1:
            absent += 1
    print("No. of Absent students : ",absent)
absent()
def max():
    max = marks[0]
    for i in marks:
        if i > max:
            max = i
    print("The max no. is : ",max)
max()
def min():
    min = marks[0]
    for i in marks:
        if i < min:
            min = i
    print("The min no. is : ",min)
min()
def countMax():
    count = 0
    max = marks[0]
    for i in marks:
        if i > max:
            max = i
    for i in marks:
        if i == max:
            count = count + 1
    print("The count of max no. is : ",count)
countMax()
def countMin():
    count = 0
    min = marks[0]
    for i in marks:
        if i < min:
            min = i
    for i in marks:
        if i == min:
            count = count + 1
    print("The count of min no. is : ",count)
countMin()
