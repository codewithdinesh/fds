# Assignment03 = DSL (Matrix operations)
# Multipliction function
def multiply(lst1, lst2):
    result_m = []
    if (len(lst1) == len(lst2[0])):
        for i in range(len(lst1)):
            r_m = []
            for j in range(len(lst1[0])):
                mul = 0
                for k in range(len(lst2[0])):
                    mul = mul + lst1[i][k] * lst2[k][j]
                    r_m.append(mul)
            result_m.append(r_m)
        return result_m
    else:
        print("No. of rows of 1st matrix are not equal to no. of coloumns of 2nd matrix")

# Substraction function


def substract(lst1, lst2):
    result_s = []
    if (len(lst1) == len(lst2) and len(lst1[0]) == len(lst2[1])):
        for i in range(len(lst1)):
            r_s = []
            for j in range(len(lst1[0])):
                sub = lst1[i][j] - lst2[i][j]
                r_s.append(sub)
            result_s.append(r_s)
        return result_s
    else:
        print("Dimensions of matrices did not match")

# Addition function


def add(lst1, lst2):
    result_a = []
    if (len(lst1) == len(lst2) and len(lst1[0]) == len(lst2[1])):
        for i in range(len(lst1)):
            r_a = []
            for j in range(len(lst1[0])):
                add = lst1[i][j] + lst2[i][j]
                r_a.append(add)
            result_a.append(r_a)
        return result_a
    else:
        print("Dimensions of matrices did not match")

# Input function


def matrix_input():
    row = int(input("Enter no. of rows: "))
    col = int(input("Enter no. of coloumns: "))
    lst = []
    for i in range(row):
        r_ele = []
        for j in range(col):
            ele = int(input(f"Enter element in row {i+1} and coloumn {j+1}: "))
            r_ele.append(ele)
        lst.append(r_ele)
    return lst


# Matrix input
lst01 = matrix_input()
lst02 = matrix_input()

# Mathematical operations
addition = add(lst01, lst02)
substraction = substract(lst01, lst02)
multiplication = multiply(lst01, lst02)

# Output
print("\nAddition of two matrices: ", addition)
print("\nSubstraction of two matrices: ", substraction)
print("\nMultiplication of two matrices: ", multiplication)
