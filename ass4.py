""" 
    Write a python program to maintain club members, sort on roll numbers in ascending order.
    Write function “Ternary_Search” to search whether particular student is member of club or not.
    Ternary search is modified binary search that divides array into 3 halves instead of two. 
"""


# Sorting - insertion sort

def Sort(list1):
    for i in range(1, len(list1)):
        key = list1[i]
        j = i-1
        while j >= 0 and key < list1[j]:
            list1[j+1] = list1[j]
            j -= 1

        list1[j+1] = key
    return list1


def InputStudent():
    n = int(input("Enter Number of students in club: "))
    roll_list = []
    for i in range(0, n):
        roll = int(input("Enter roll number of " + str(i+1) + " student : "))
        roll_list.append(roll)

    return roll_list


def displayStudent(students):
    for i in students:
        print(i)


# without reccursion
def TernarySearch(students, findRoll):
    left = 0
    right = len(students)-1
    while left <= right:
        mid1 = left + (right-left) // 3
        mid2 = left + 2 * (right-left) // 3

        if(findRoll == students[left]):
            return left

        elif findRoll == students[right]:
            return right

        elif findRoll < students[left] or findRoll > students[right]:
            return -1

        elif findRoll <= students[mid1]:
            right = mid1

        elif findRoll > students[mid1] and findRoll <= students[mid2]:
            left = mid1+1
            right = mid2

        else:
            left = mid2+1

    return -1


students = InputStudent()

sortedStudents = Sort(students.copy())

flag = 1
while flag == 1:
    print("\n\n..Menu..")
    print("1) Display Students list \n2) Sort Student List \n3) Search Student\n4) Exit")
    ch = int(input("\nEnter Choice: "))

    if ch == 1:
        displayStudent(students)

    elif ch == 2:
        displayStudent(sortedStudents)

    elif ch == 3:
        find = int(input("Enter the roll number to find out in List: "))
        index = TernarySearch(sortedStudents, find)

        if index != -1:
            print("Roll Number ", find, " is found at position ", index+1)
        else:
            print("Roll Number ", find, " Not found in list")

    else:
        flag = 0
