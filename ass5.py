
""" Write a python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order
using
a) Selection Sort
b) Bubble sort and display top five scores. """


# Input students
def InputStudent():
    n = int(input("Enter Number of Students: "))
    percentages = []
    for i in range(n):
        percentage = float(
            input("Enter Percentage of "+str(i+1) + " student: "))
        percentages.append(percentage)
    return percentages
# Selection sort: sort the number by min number


def SelectionSort(arr):
    for i in range(len(arr)):
        minIndex = i

        for j in range(i+1, len(arr)):
            if arr[j] < arr[minIndex]:
                minIndex = j

        (arr[i], arr[minIndex]) = (arr[minIndex], arr[i])  # swap
    return arr


# Bubble sort : sort adjecent element

def BubbleSort(arr):
    for i in range(len(arr)):
        for j in range(0, len(arr)-i-1):
            if arr[j] > arr[j+1]:
                (arr[j], arr[j+1]) = (arr[j+1], arr[j])  # swap

    return arr


def TopFive(Arr):
    print("\nTop 5 percentage are: ")
    print(Arr[-1:-6:-1], sep="\n")


students = InputStudent()

print("Students : ", students)

flag = 1

while flag == 1:
    print("\n\n1) Sort with Selection Sort\n2) Sort with Bubble Sort and Display Top Five Scores \n")
    ch = int(input("Enter Choice"))

    if ch == 1:
        print("Students after Selection Sort", SelectionSort(students.copy()))
    if ch == 2:
        sortedStudents = BubbleSort(students)
        print("Students after Bubble sort", sortedStudents)
        TopFive(sortedStudents)
    else:

        flag = 0
