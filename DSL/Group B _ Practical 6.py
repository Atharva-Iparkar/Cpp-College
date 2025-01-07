def pivot_pos(list1, first, last):
    pivot = list1[first]
    left = first + 1
    right = last
    while True:
        while left <= right and list1[left] <= pivot:
            left += 1
        while left <= right and list1[right] >= pivot:
            right -= 1
        if right < left:
            break
        else:
            list1[left], list1[right] = list1[right], list1[left]
    list1[first], list1[right] = list1[right], list1[first]
    return right

def quick_sort(list1, first, last):
    if first < last:
        p = pivot_pos(list1, first, last)
        quick_sort(list1, first, p - 1)
        quick_sort(list1, p + 1, last)

def top_five(sorted_list):
    print("Top 5 Scores : ")
    top5 = sorted_list[::-1]  # Reverse to get top scores
    print("Top 5 scores: ", top5[:5])

# Input section
x = int(input("Enter No. of Elements: "))
list1 = []
for i in range(x):
    num = int(input("Enter No. to Be sorted: "))
    list1.append(num)

print("Original List: ", list1)
l = len(list1)
quick_sort(list1, 0, l - 1)
print("Sorted List: ", list1)
top_five(list1)
