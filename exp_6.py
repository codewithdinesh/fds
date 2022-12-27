"""
Write a Python program to store first year percentage of students in an array.
Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.
"""

# Function for accepting the percentage of the Students


def input_percentage():
    perc = []
    number_of_students = int(input("Enter the number of Students : "))
    for i in range(number_of_students):
        perc.append(
            float(input("Enter the percentage of Student {0} : ".format(i+1))))
    return perc

# Function for printing the percentage of the Students


def print_percentage(perc):

    for i in range(len(perc)):
        print(perc[i], sep="\n")

# Function for performing partition of the Data


def Partition(array, low, high):

    # choose the rightmost element as pivot
    pivot = array[high]

    # pointer for greater element
    i = low - 1

    # traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        if array[j] <= pivot:
            # if element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1

            # swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])

    # swap the pivot element with the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])

    # return the position from where partition is done
    return i + 1


# Function for performing Quick Sort on the Data
def Quick_Sort(perc, start, end):
    if start < end:
        partition = Partition(perc, start, end)
        Quick_Sort(perc, start, partition-1)
        Quick_Sort(perc, partition+1, end)


# Function for Displaying Top Five Percentages of Students


def display_top_five(perc):

    print("Top Five Percentages are : ")
    if len(perc) < 5:
        start, stop = len(perc) - 1, -1
    else:
        start, stop = len(perc) - 1, len(perc) - 6
    for i in range(start, stop, -1):
        print(perc[i], sep="\n")


# Main
unsorted_percentage = []
sorted_percentage = []
flag = 1
while flag == 1:
    print("\n--------------------MENU--------------------")
    print("1. Accept the Percentage of Students")
    print("2. Display the Percentages of Students")
    print("3. Perform Quick Sort on the Data")
    print("4. Exit")
    ch = int(input("Enter your choice (from 1 to 4) : "))

    if ch == 1:
        unsorted_percentage = input_percentage()

    elif ch == 2:
        print_percentage(unsorted_percentage)

    elif ch == 3:
        print("Percentages of Students after performing Quick Sort : ")

        Quick_Sort(
            unsorted_percentage, 0, len(unsorted_percentage)-1)

        print("Sorted a: ", unsorted_percentage)
        a = input(
            "Do you want to display the Top 5 Percentages of Students (yes/no) : ")
        if a == 'yes':
            display_top_five(sorted_percentage)
    elif ch == 4:
        print("Thanks for using this program!!")
        flag = 0
    else:
        print("Invalid Choice!!")
