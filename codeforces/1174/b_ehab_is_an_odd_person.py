def run(arr):
    has_even = False
    has_odd = False

    for number in arr:
        if number % 2 == 0:
            has_even = True
        else:
            has_odd = True

    if has_even and has_odd:
        arr.sort()

    str_numbers = map(str, arr)
    return ' '.join(str_numbers)


n = raw_input()
numbers = list(map(int, raw_input().split()))

print(run(numbers))
