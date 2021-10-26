# https://www.quastor.org/p/partitioning-relational-databases
# You are given an array of integers sorted in non-decreasing order.

# Write a function that removes any duplicates in the array so that each element appears only once.

# Your function must use constant space, so your space complexity must be O(1).

# The function should return k, where k is the number of unique items in the array. The first k items in the array should be the unique integers in sorted order from least to greatest.

# The elements in the array after the first k elements can be whatever you choose.

# Your function should run in O(n) or better.

# --------
# my solution is not completely tested
def solve(arr):
    if len(arr) == 1:
        return 1

    next_empty_index = None
    prev = arr[0]
    k = 1
    for i in range(1, len(arr)):
        if arr[i] == prev:
            arr[i] = None
            if next_empty_index is None:
                next_empty_index = i
        else:
            prev = arr[i]
            k += 1
            if next_empty_index is not None:
                arr[next_empty_index] = arr[i]
                arr[i] = None
                next_empty_index += 1

    return k


# Note: array will modify be reference
arr = [1, 1, 2]
print(solve(arr), arr)

arr = [1, 1, 1, 1, 2]
print(solve(arr), arr)

arr = [1, 1, 2, 2, 3, 4, 5, 5]
print(solve(arr), arr)

arr = [1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 6, 7]
print(solve(arr), arr)
