class Set:

    def __init__(self):
        self.myset = []  # List to store set elements
        self.length = 0  # variable to keep record of number of elements in a set

    def getLength(self):
        return self.length

    def getElement(self, index):
        return self.myset[index]

    # method to check whether element is present in the set or not (return value : boolean)
    def isContain(self, element):
        for i in range(self.length):
            if self.myset[i] == element:
                return True
        return False

    def addElement(self, element):  # method to add element in a set (return value : None)
        # if set already contains element then return
        if (self.isContain(element)):
            return
        # else add element to the set
        self.myset.append(element)
        self.length += 1

    # method to find intersection of set with another set (return value : Object of class Set)
    def intersection(self, anotherSet):
        intersectionSet = Set()

        for i in range(self.length):
            # if another set contains the ith element of this set, add the element to the intersection set
            if anotherSet.isContain(self.myset[i]):
                intersectionSet.addElement(self.myset[i])

        return intersectionSet

    # method to find union of set with another set (return value : Object of class Set)
    def union(self, anotherSet):
        unionSet = Set()
        m = self.length

        # Adding all elements of first set to the union set
        for i in range(m):
            unionSet.addElement(self.myset[i])

        # Adding those elements of second set to the union set which are not present in first set
        present_in_another_but_not_in_self = anotherSet.difference(self)
        n = present_in_another_but_not_in_self.getLength()

        for j in range(n):
            unionSet.addElement(
                present_in_another_but_not_in_self.getElement(j))

        return unionSet

    # method to get difference of first set with second set (return value : Object of class Set)
    def difference(self, anotherSet):
        differenceSet = Set()
        m = self.length

        # Adding those elements of first set to difference set which are not present in second set
        for i in range(m):
            if anotherSet.isContain(self.myset[i]):
                continue
            differenceSet.addElement(self.myset[i])

        return differenceSet

    def readElement(self, count):  # method to get elements as input from the user
        for i in range(count):
            print("Enter name of player ", i + 1, " : ")
            play_name = input()
            self.addElement(play_name)

    def PrintSet(self):  # method to print set elements
        if (self.length == 0):
            print("No students")

        for i in range(len(self.myset)):
            print(self.myset[i], end=", ")
        print("\n")


def main():

    # Creating Objects of Set Class : A = Students Playing Cricket, B = Students Playing Badminton, C = Students Playing Football
    A = Set()
    B = Set()
    C = Set()

    # Taking Input for Cricket Players
    cric_players = int(
        input("Enter the number of students who plays cricket : "))
    A.readElement(cric_players)

    print("Students who plays cricket are : ", end=" ")
    A.PrintSet()

    # Taking Input for Badminton Players
    bad_players = int(
        input("Enter the number of students who plays badminton : "))
    B.readElement(bad_players)

    print("Students who plays badminton are : ", end=" ")
    B.PrintSet()

    # Taking Input for Football Players
    foot_players = int(
        input("Enter the number of students who plays Football : "))
    C.readElement(foot_players)

    print("Students who plays football are : ", end=" ")
    C.PrintSet()

    while(True):
        print('''Select
        a for Students Playing Both Cricket and Badminton
        b for Students Playing Cricket or Badminton but not Both
        c for Number of Students playing neither Cricket nor Badminton
        d for Number of Students playing cricket and football but not badminton
        0 to Exit from the program\n''')
        choice = input("Enter your choice here : ")

        if(choice == '0'):
            break

        if(choice == 'a'):
            # Problem a : Students Playing Both Cricket and Badminton
            cric_and_bad = A.intersection(B)
            print("Students Who plays both cricket and badminton are : ", end="")
            cric_and_bad.PrintSet()

        if(choice == 'b'):
            # Problem b : Students Playing Cricket or Badminton but not Both
            cric_and_bad_both = A.intersection(B)
            cric_or_bad = A.union(B)
            cric_or_bad_but_not_both = cric_or_bad.difference(
                cric_and_bad_both)
            print("Students Who plays cricket or badminton but not both are : ", end="")
            cric_or_bad_but_not_both.PrintSet()

        if(choice == 'c'):
            # Problem c : Number of Students playing neither Cricket nor Badminton
            cric_or_bad = A.union(B)
            neither_cric_nor_bad = C.difference(cric_or_bad)
            print("Number of students who play neither cricket nor badminton is : ",
                  neither_cric_nor_bad.getLength())
            print("Students who play neither cricket nor badminton are : ", end="")
            neither_cric_nor_bad.PrintSet()

        if(choice == 'd'):
            # Problem d : Number of Students playing cricket and football but not badminton
            cric_and_foot = A.intersection(C)
            cric_and_foot_but_not_bad = cric_and_foot.difference(B)
            print("Number of Students who play cricket and football but not badminton is : ",
                  cric_and_foot_but_not_bad.getLength())
            print(
                "Students who plays cricket and football but not badminton are : ", end="")
            cric_and_foot_but_not_bad.PrintSet()


main()


# test case #1
# Input:
# students playing cricket : {A, B, C}
# students playing badminton : {A, B, C}
# students playing football : {A, B, C}
# Output:
# a. {A, B, C}
# b. No students
# c. 0, No students
# d. 0, No students

# test case #2
# Input:
# students playing cricket : {}
# students playing badminton : {A, B, C, D}
# students playing football : {C, A, E, F}
# Output:
# a. No students
# b. {A, B, C, D}
# c. 2, {E, F}
# d. 0, No students

# test case #3
# Input:
# students playing cricket : {A, B, C, D}
# students playing badminton : {C, D, E}
# students playing football : {E, A, B, F, G}
# Output:
# a. {C, D}
# b. {A, B, E}
# c. 2, {F, G}
# d. 2, {A, B}
