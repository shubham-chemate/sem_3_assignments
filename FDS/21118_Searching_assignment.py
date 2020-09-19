def LinearSearch(lst, n, x):
    i = 0
    while (i < n and lst[i] != x):
        i += 1

    if (i < n):
        return i
    else:
        return -1


def SentinelSearch(lst, n, x):
    # Appending element at end of list to assure that element alays present
    lst.append(x)

    i = 0
    while lst[i] != x:
        i += 1

    if i < n:
        return i
    else:
        return -1


def BinarySearchRec(lst, left, right, x):
    # Condition to exit from recursion
    if (left > right):
        return -1

    mid = left + (right - left) // 2

    if lst[mid] == x:
        return mid
    elif x < lst[mid]:
        return BinarySearchRec(lst, left, mid - 1, x)
    else:
        return BinarySearchRec(lst, mid+1, right, x)


def BinarySearchIte(lst, n, x):
    left = 0
    right = n-1

    while (left <= right):
        mid = left + (right - left) // 2

        if lst[mid] == x:
            return mid
        elif x < lst[mid]:
            right = mid-1
        else:
            left = mid + 1

    return -1


def FiboSearch(lst, n, x):
    pass


def main():
    pass
