# Name : Shubham Chemate
# Subject : DS Lab - Sorting Assignment
# Roll No : 21118

import random


class ScoreSheet():

    def __init__(self):
        self.__marks = []
        self.__n = 0

    def readData(self):
        while (True):
            self.__n = int(input("How many students? "))
            if self.__n <= 0:
                print("Invalid number of students. Enter again.")
            else:
                break

        print("Enter percentage of students:")
        for i in range(self.__n):
            x = float(input())
            if x < 100 and x >= 0:
                self.__marks.append(x)
            else:
                print("INVALID INPUT. Enter again.")
                i -= 1

    def InsertionSort(self):
        for i in range(self.__n):
            val = self.__marks[i]
            hole = i
            while (hole > 0 and self.__marks[hole-1] > val):
                self.__marks[hole] = self.__marks[hole-1]
                hole -= 1
            self.__marks[hole] = val

    def ShellSort(self):
        gap = self.__n // 2

        while (gap > 0):
            j = gap
            while (j < self.__n):
                i = j - gap
                while (i >= 0):
                    if (self.__marks[i+gap] < self.__marks[i]):
                        # swapping
                        temp = self.__marks[i+gap]
                        self.__marks[i+gap] = self.__marks[i]
                        self.__marks[i] = temp
                    i -= gap
                j += 1
            gap = gap // 2

    def __Partition(self, left, right):
        p = random.randrange(left, right+1)
        self.__marks[right], self.__marks[p] = self.__marks[p], self.__marks[right]
        p = right
        i = left - 1
        for j in range(left, right):
            if (self.__marks[j] <= self.__marks[p]):
                i += 1
                self.__marks[j], self.__marks[i] = self.__marks[i], self.__marks[j]
        self.__marks[p], self.__marks[i+1] = self.__marks[i+1], self.__marks[p]
        return i + 1

    def __QuickSortUtil(self, left, right):
        if (left >= right):
            return
        pivot = self.__Partition(left, right)
        self.__QuickSortUtil(left, pivot-1)
        self.__QuickSortUtil(pivot+1, right)

    def QuickSort(self):
        self.__QuickSortUtil(0, self.__n-1)

    def PrintTop5Score(self):
        rank = 1
        for i in range(self.__n-1, -1, -1):
            if (i == 0):
                print("Rank", rank, ": ", self.__marks[i])
            elif (self.__marks[i] != self.__marks[i-1]):
                print("Rank", rank, ": ", self.__marks[i])
                rank += 1
            if (rank == 6):
                break


def main():

    while (True):
        result = ScoreSheet()
        result.readData()
        print("\n--------Enter--------\n0 to Exit\n1 to Sort by Insertion Sort\n2 to Sort by Shell Sort\n3 to Sort by Quick Sort")
        choice = int(input("Enter here: "))

        if (choice == 0):
            break
        elif choice == 1:
            result.InsertionSort()
        elif choice == 2:
            result.ShellSort()
        elif choice == 3:
            result.QuickSort()
        else:
            print("INVALID INPUT. Enter again.")
            continue

        result.PrintTop5Score()


main()
