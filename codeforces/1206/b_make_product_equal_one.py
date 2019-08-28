def run(arr):
    count = 0

    num_of_neg_one = 0
    num_of_zero = 0
    for num in arr:
        if num > 1:
            count += (num - 1)
        elif num < 0:
            count += (abs(num) - 1)
            num_of_neg_one += 1
        elif num == 0:
            num_of_zero += 1
            count += 1

    if num_of_neg_one % 2 == 0:
        pass # done
    else:
        if num_of_zero > 0:
            pass # done, just change one of the 0 to -1
        else:
            count += 2

    print(count)



input() # ignore size
arr = list(map(int, input().split()))

run(arr)
