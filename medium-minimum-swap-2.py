# https://www.hackerrank.com/challenges/minimum-swaps-2/problem

# Time: O(nlog(n))
# Space: O(n)

def minimumSwaps(arr):
    sorted_arr = sorted(arr)
    sorted_index = {}
    arr_index = {}
    for i in range(len(sorted_arr)):
        sorted_value = sorted_arr[i]
        sorted_index[sorted_value] = i

        original_value = arr[i]
        arr_index[original_value] = i
        
    result = 0
    
    for i in range(len(arr)):
        if arr[i] != sorted_arr[i]:
            result += 1

            current_value = arr[i]
            correct_value = sorted_arr[i]

            arr[i] = correct_value

            current_value_new_position = arr_index[correct_value]
            arr[current_value_new_position] = current_value

            arr_index[current_value] = current_value_new_position
            
    return result




print(minimumSwaps([4, 3, 1, 2]))
print(minimumSwaps([2, 3, 4, 1, 5]))
print(minimumSwaps([1, 3, 5, 2, 4, 6, 8]))
print(minimumSwaps([1,2,3,4,5,6,7,8,9]))
print(minimumSwaps([5,4,3,2,1,6]))
print(minimumSwaps([5, 10, 15, 20, 30]))
print(minimumSwaps([5, 10, 90, 20, 30]))


