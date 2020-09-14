# DS Assignment 02 : Operations on String
# Name : Shubham Chemate
# Roll Number : 21118

class String():

    # constructor function, it takes string as optional argument
    def __init__(self, s=""):
        self.mystring = []
        self.strLen = 0
        for char in s:
            if char == '#':
                break
            self.mystring.append(char)
            self.strLen += 1
        self.mystring.append("#")

    # function to get char at given index
    def getChar(self, index):
        return self.mystring[index]

    # function to get length of string
    # Note: string terminating character i.e. '#' is not considered in a length of string
    def getstrLen(self):
        return self.strLen

    # function to append character to mystring
    def appendChar(self, c):
        self.mystring[self.strLen] = c
        self.mystring.append("#")
        self.strLen += 1

    # function to get input character by character
    def getInputByCharacter(self):
        print("\nNOTE : End the string with '#' character")
        print("Enter the string : ")

        while(True):
            char = input()
            if char == '#':
                break
            self.appendChar(char)

    # function get input (as a inbuilt string) and then convert it into list of character (defined by me)
    def getInputBySentence(self):
        print("\nNOTE : End the string with '#' character")

        s = input("Input the string : ")

        for char in s:
            if char == "#":
                break
            self.appendChar(char)

    # function returns largest word in the string as a object of string class
    def getLargestWord(self):
        largestLength = 0
        largestWord = String()

        currentLength = 0
        currentWord = String()
        for char in self.mystring:
            if char == " " or char == "#":
                if currentLength > largestLength:
                    largestLength = currentLength
                    largestWord = currentWord
                currentLength = 0
                currentWord = String()
            else:
                currentLength += 1
                currentWord.appendChar(char)

        return largestWord

    # function returns the number of appearace of input character in a string
    def getCharCount(self, c):
        cnt = 0
        for char in self.mystring:
            if char == c:
                cnt += 1
        return cnt

    # function checks if string is pallindrome or not
    def isPallindrome(self):
        for i in range(self.strLen // 2):
            if self.mystring[i] != self.mystring[self.strLen - i - 1]:
                return False
        return True

    # function return the index of first occurance of substring, if not found returns -1
    def getSubStrIndex(self, substr):

        for i in range(self.strLen):
            if self.mystring[i] == substr.getChar(0):
                j = i
                for k in range(substr.getstrLen()):
                    if self.mystring[j] != substr.getChar(k):
                        break
                    j += 1
                if (j - i) == substr.getstrLen():
                    return i

        return -1

    # function will count occurances of currentWord in myTempStr
    def getCountAndRemove(self, currentWord, myTempStr):
        currentWordCount = 0
        for i in range(self.strLen):
            if (myTempStr[i] == currentWord.getChar(0)):
                j = i
                for k in range(currentWord.getstrLen()):
                    if myTempStr[j] != currentWord.getChar(k):
                        break
                    j += 1
                if (j - i) == currentWord.getstrLen():
                    currentWordCount += 1
                    j = i
                    for k in range(currentWord.getstrLen()):
                        myTempStr[j] = "~"
                        j += 1

        return (myTempStr, currentWordCount)

    # function to count occurance of each word in the string
    def getAllWordsCount(self):
        myTempStr = self.mystring

        res = []

        currentWord = String()
        for i in range(self.strLen + 1):
            if myTempStr[i] == "~":
                continue
            if myTempStr[i] == " " or myTempStr[i] == "#":
                if currentWord.getstrLen() != 0:
                    (myTempStr, currentWordCount) = self.getCountAndRemove(
                        currentWord, myTempStr)
                    res.append([currentWord, currentWordCount])
                currentWord = String()
            else:
                currentWord.appendChar(myTempStr[i])

        return res

    # function to compare two strings
    def areStringsEqual(self, anotherStr):
        if self.strLen != anotherStr.getstrLen():
            return False

        for i in range(self.strLen):
            if self.mystring[i] != anotherStr.getChar(i):
                return False

        return True

    # function to print the string
    def Print(self):
        for char in self.mystring:
            if char == '#':
                continue
            print(char, end="")
        print()


def main():

    while(True):

        S = String()
        S.getInputBySentence()
        print("Given string is : ")
        S.Print()

        print('''\nEnter number :
        1 to display word with largest length in a string
        2 to find frequency of paricular character in a string
        3 to check wheather the string is pallindrome or not
        4 to display index of first appearance of substring
        5 to count the occurances of word in a string
        0 to terminate the program''')
        choice = int(input("Enter your choice here : "))

        if choice == 0:
            break
        elif choice == 1:
            largestWord = S.getLargestWord()
            print("Largest world in the string is : ")
            largestWord.Print()
        elif choice == 2:
            c = input("Enter a character to find it's frequency : ")
            frequency = S.getCharCount(c)
            print("The char '" + c + "' is appeared",
                  frequency, "times in the string.")
        elif choice == 3:
            if S.getstrLen() == 0:
                print("The string is empty.")
            elif S.isPallindrome():
                print("The string is pallindrome.")
            else:
                print("The string is not pallindrome.")
        elif choice == 4:
            substr = String()
            substr.getInputBySentence()
            substrIndex = S.getSubStrIndex(substr)

            if substrIndex == -1:
                print("The substring you have entered is not present in given string.")
            else:
                print("The index is", substrIndex)
        elif choice == 5:
            if S.getstrLen() == 0:
                print("The sentence you have entered is empty.")
            else:
                allWordsCount = S.getAllWordsCount()
                print("The occurance count of each word in a given string is : ")
                for item in allWordsCount:
                    print("Word is : ", end="")
                    item[0].Print()
                    print("Occurance Count : ", item[1])

        else:
            print("ERROR: Invalid Input. Enter proper code again.")


main()

# Separate pdf file of screenshot of testcases is attached.
