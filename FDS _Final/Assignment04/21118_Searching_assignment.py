# Name : Shubham Chemate
# Subject : DS Lab
# Roll No : 21118

class studentList():

    def __init__(self):
        self.__students = []
        self.__n = 0
        self.__loop_run_count = 0

    def getLoopRunCount(self):
        return self.__loop_run_count

    def readData(self):

        while (True):
            self.__n = int(input("How many students? "))
            if self.__n <= 0:
                print("Invalid number of students. Enter again.")
            else:
                break

        print("Enter roll numbers:")
        for i in range(self.__n):
            x = int(input())
            if x not in self.__students and x > 0:
                self.__students.append([x, i])
            elif x <= 0:
                print("Invalid roll number. Enter again.")
                i -= 1

    def Sort(self):
        for i in range(self.__n):
            for j in range(i+1, self.__n):
                if (self.__students[i][0] > self.__students[j][0]):
                    temp = self.__students[i]
                    self.__students[i] = self.__students[j]
                    self.__students[j] = temp

    def LinearSearch(self, x):
        self.__loop_run_count = 0
        i = 0
        while i < self.__n and self.__students[i][0] != x:
            self.__loop_run_count += 1
            i += 1

        if i < self.__n:
            return i
        else:
            return -1  # if element not found

    def SentinelSearch(self, x):
        # Appending element at end of list to assure that element always present
        self.__students.append([x, self.__n])
        self.__loop_run_count = 0

        i = 0
        while self.__students[i][0] != x:
            self.__loop_run_count += 1
            i += 1

        if i < self.__n:
            return i
        else:
            return -1  # if element not found

    def BinarySearch(self, x):
        self.Sort()
        self.__loop_run_count = 0

        left = 0
        right = self.__n-1

        while left <= right:
            self.__loop_run_count += 1
            mid = left + (right - left) // 2

            if self.__students[mid][0] == x:
                return self.__students[mid][1]
            elif x < self.__students[mid][0]:
                right = mid-1
            else:
                left = mid + 1

        return -1  # if element not found

    def __BinarySearchRUtil(self, left, right, x):
        self.__loop_run_count += 1
        if left > right:
            return -1

        mid = left + (right - left) // 2
        if self.__students[mid][0] == x:
            return self.__students[mid][1]
        elif x < self.__students[mid][0]:
            return self.__BinarySearchRUtil(left, mid-1, x)
        else:
            return self.__BinarySearchRUtil(mid+1, right, x)

    def BinarySearchR(self, x):
        self.__loop_run_count = 0
        self.Sort()
        return self.__BinarySearchRUtil(0, self.__n, x)

    def FiboSearch(self, x):
        self.Sort()
        self.__loop_run_count = 0

        # generating fibonacci sequence
        fibo = []
        fibo.append(0)
        fibo.append(1)
        i = 1
        while fibo[i] < self.__n:
            fibo.append(fibo[i] + fibo[i-1])
            i += 1

        offset = -1
        while fibo[i] > 1:
            self.__loop_run_count += 1
            j = min(offset+fibo[i-2], self.__n-1)

            if self.__students[j][0] == x:
                return self.__students[j][1]
            elif x < self.__students[j][0]:
                i -= 2
            else:
                i -= 1
                offset = j

        if fibo[i-1] != 0 and self.__students[offset+1] == x:
            return self.__students[offset+1][1]

        return -1  # if element not found


def main():
    event = studentList()
    event.readData()

    while (True):
        x = int(input("\nEnter roll number of student to search in the list: "))

        print("\n--------Enter--------\n0 to Exit\n1 to find by Linear Search\n2 to find by Sentinel Search\n3 to find by Binary Search\n4 to find by Fibonacci Search")
        choice = int(input("Enter here: "))

        if choice == 0:
            break
        elif choice == 1:
            index = event.LinearSearch(x)
        elif choice == 2:
            index = event.SentinelSearch(x)
        elif choice == 3:
            index = event.BinarySearch(x)
        elif choice == 4:
            index = event.FiboSearch(x)
        else:
            print("INVALID INPUT. Enter again.")
            continue

        if index != -1:
            print("Student of roll number", x,
                  "attended the program.")
            print("Index: ", index)
        else:
            print("Student of roll number", x,
                  "haven't attended the program.")
        print("Loop runs", event.getLoopRunCount(),
              "times to check the presence of student.")


main()

# Separete pdf file is attached containing screenshots of testcases.
