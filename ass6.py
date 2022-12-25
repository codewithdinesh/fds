"""
Write a Python program to store first year percentage of students in an array.
Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.
"""

# functions definations

# Partition for quick sort


def Partition(arr, left, right):
    pivot = arr[right]
    pointerI = left-1

    for j in range(left, right):
        if arr[j] <= pivot:
            pointerI = pointerI+1

            arr[pointerI], arr[j] = arr[j], arr[pointerI]

    arr[pointerI+1], arr[right] = arr[right], arr[pointerI+1]
    return pointerI+1


# quick sort - divide and conqure
def QuickSort(arr, left, right):
    if left < right:
        partition = Partition(arr, left, right)  # divide
        QuickSort(arr, left, partition - 1)  # left side
        QuickSort(arr, partition + 1, right)  # right side

    return arr

# input student score


def inputPercentage():
    n = int(input("Enter the Number of students :"))
    percentages = []
    for i in range(n):
        percentage = float(
            input("Enter Percentage of "+str(i+1)+" student : "))
        percentages.append(percentage)

    return percentages

# diplaying top 5 scores


def Top5(arr):
    print("Top 5 scores: \n")
    print(arr[-1:-6:-1], sep="\n")


# main
students = inputPercentage()
print("Students: ", students)

sortedStudents = QuickSort(students.copy(), 0, len(students)-1)

print("Sorted students score: ", sortedStudents)

Top5(sortedStudents)
