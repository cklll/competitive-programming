def run(arr):
    arr.sort()

    total = sum(arr)

    half_sum = sum(arr[:len(arr) / 2])
    if half_sum * 2 == total:
        return -1
    else:
        str_numbers = map(str, arr)
        return ' '.join(str_numbers)


n = raw_input()
numbers = list(map(int, raw_input().split()))

print(run(numbers))
