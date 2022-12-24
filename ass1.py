""" 
Experiment No. 1: In a second year computer engineering class, group A students play cricket, group B students play   badminton and group C students play football.
                   Write a python program using functions to compute following:
                   a) List of students who play both cricket and badminton.
                   b) List of students who play either cricket or badminton but not both.
                   c) Number of students who play neither cricket nor badminton.
                   d) Number of students who play cricket and football but not badminton.
(NOTE : While realising the group, duplicate entries should be avoided. Do not use SET built-in functions)

"""
# utility - remove duplicate


def removeDuplicate(list1):
    temp = []
    for ele in list1:
        if ele not in temp:
            temp.append(ele)

# List of students who play both


def allPlay(list1, list2):
    list3 = list1.copy()  # save student who play all - union operation
    for s1 in list2:
        if s1 not in list3:
            list3.append(s1)

    return list3

# students who play both game - common player(intersection operation)


def bothPlay(list1, list2):
    list3 = []
    for s1 in list1:
        if s1 in list2:
            list3.append(s1)
    return list3

# student who play only one game - difference operation (A-B)


def playOnlyOne(list1, list2):
    list3 = []
    for s1 in list1:
        if s1 not in list2:
            list3.append(s1)
    return list3

# List of students who play either cricket or badminton but not both - symmetric difference operation


def notBothPlay(list1, list2):
    p1 = playOnlyOne(list1, list2)
    p2 = playOnlyOne(list2, list1)
    p3 = playOnlyOne(allPlay(list1, list2), bothPlay(list1, list2))
    return p3


# main
SEcomp = []

noStudent = int(
    input("Enter the Number of student present in class SE computer: "))

for i in range(0, noStudent):
    name = str(input("Enter "+str(i+1)+" student name: "))
    SEcomp.append(name)

print("\n\nStudents of SEcomp: ")
print(SEcomp)


# group A students : who play cricket
Cricket = []
noCricket = int(
    input("\nEnter the Number of students present in Group A- who play cricket : "))

for i in range(0, noCricket):
    name = str(input("Enter "+str(i+1)+" student name who play cricket: "))
    Cricket.append(name)

Cricket = removeDuplicate(Cricket)
print("\nStudents who play Cricket: ")
print(Cricket)


# group B students : who play badminton
Badminton = []
noBadminton = int(
    input("\nEnter the Number of students present in Group B- who play badminton : "))

for i in range(0, noBadminton):
    name = str(input("Enter "+str(i+1)+" student name who play badminton: "))
    Badminton.append(name)

Badminton = removeDuplicate(Badminton)
print("\nStudents who play badminton: ")
print(Badminton)


# group C students : who play Football
Football = []
noFootball = int(
    input("\n\nEnter the Number of students present in Group C- who play Football : "))

for i in range(0, noFootball):
    name = str(input("Enter "+str(i+1)+" student name who play Football: "))
    Football.append(name)

Football = removeDuplicate(Football)
print("\n\nStudents who play badminton: ")

print(Football)


# Perform operations of List data as mention in problem statement

flag = 1

while(flag == 1):
    print("\n\n--------------------MENU--------------------\n")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. List of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit\n")
    ch = int(input("Enter your Choice (from 1 to 5) :"))

    # 1) List of students who play both cricket and badminton
    if ch == 1:
        CricketAndBadminton = bothPlay(Cricket, Badminton)
        print("\nStudents who play both cricket and badminton :")
        print(CricketAndBadminton)
        print()

    elif ch == 2:
        # 2) List of students who play either cricket or badminton but not both
        CricketOrBadminton = notBothPlay(Cricket, Badminton)
        print("\nList of students who play either cricket or badminton but not both:")
        print(CricketOrBadminton)

    elif ch == 3:
        # 3) Number of students who play neither cricket nor badminton
        neitherPlayCB = playOnlyOne(SEcomp, allPlay(Cricket, Badminton))
        print("\nNumber of students who play neither cricket nor badminton: ")
        print(neitherPlayCB)

    elif ch == 4:
        # 4) Number of students who play cricket and football but not badminton
        notBadminton = playOnlyOne(allPlay(Cricket, Football), Badminton)
        print("\nNumber of students who play cricket and football but not badminton: ")
        print(notBadminton)

    ex = str(input("Do you want to conntinue?(yes/no)"))
    if(ex == "no"):
        flag = 0
    else:
        flag = 1
