# Name : Shubham Chemate
# Roll No. 21118 (E-1)
# DSL Mock Practical

import random

class ScoreSheet():
    def __init__(self):
        self.scores = []
        self.n = 0

    def readData(self):
        while (True) :
            self.n = int(input("How many students? "))
            if (self.n > 0) : break
            else: print("INVALID VALUE. Enter again.")

        i = 0
        while (i < self.n):
            x = float(input("Enter percentage: "))
            if (x > 100.0 or x < 0.0) :
                print ("INVALID VALUE. Enter again.")
            else :
                self.scores.append(x)
                i += 1
    
    def __Partition(self, left, right):
        # choosing random pivot 
        p = random.randrange(left, right+1)

        self.scores[p], self.scores[right] = self.scores[right], self.scores[p]

        i = 0
        pivotEle = self.scores[right]

        for j in range(self.n-1):
            if (self.scores[j] <= pivotEle):
                self.scores[j], self.scores[i] = self.scores[i], self.scores[j]
                i += 1
        
        self.scores[i], self.scores[right] = self.scores[right], self.scores[i]

        p = i

        return p
    
    def __SortUtil(self, left, right):
        if (left >= right): return

        pivotIndex = self.__Partition(left, right)
        self.__SortUtil(left, pivotIndex-1)
        self.__SortUtil(pivotIndex+1, right)

    def __Sort(self): # sort by quicksort algorithm
        left = 0
        right = self.n - 1
        self.__SortUtil(left, right)

    def PrintTop5Score(self):
        # Sorting before printing top 5 scores
        self.__Sort()

        print("Top five ranks with percentages:")
        rank = 1
        for score in range(self.n-1, -1, -1):
            if (score == 0):
                print("Rank", rank, ": ", self.scores[score])
            elif (self.scores[score] != self.scores[score-1]):
                print("Rank", rank, ": ", self.scores[score])
                rank += 1
            if (rank == 6):
                break

def main():
    SS = ScoreSheet()
    SS.readData()
    SS.PrintTop5Score()

main()
