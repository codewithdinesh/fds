
""" Write a python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order
using
a) Selection Sort
b) Bubble sort and display top five scores. """

mlist = []
number = int(input("Enter the no of students in FE. : "))

print("Enter the percentage of each students as integer ( please press enter after each entry.)")

for i in range(0, number):
    ele = int(input())
    mlist.append(ele)
print(mlist)


def selection_sort(marklist, n):
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if marklist[j] < marklist[min_index]:
                min_index = j
        (marklist[i], marklist[min_index]) = (marklist[min_index], marklist[i])


selection_sort(mlist, number)
print('The array after sorting in ascending order by selection sort is : ')
print(mlist)


def bubble_sort(lst):
    for i in range(len(lst)-1, 0, -1):
        for j in range(i):
            if lst[j] > lst[j+1]:
                temp = lst[j]
                lst[j] = lst[j+1]
                lst[j+1] = temp


bubble_sort(mlist)
print('The array after sorting in ascending order by bubble sort is : ')
for i in range(len(mlist)):
    print(mlist[i], end=" ")

# print("% d" % mlist[i],end=" ")


def top_5_score(lst):
    print("\n Top 5 marks are: ")
    print(*lst[-1:-6:-1], sep="\n")


top_5_score(mlist)

# _______________End of program_______________
