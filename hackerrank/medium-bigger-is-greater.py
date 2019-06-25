# https://www.hackerrank.com/challenges/bigger-is-greater/problem
# ref https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
def biggerIsGreater(w):
    longest_suffix = w[-1]
    pivot_position = len(w) - 1
    pivot = ''
    for i in range(len(w) - 2, -1, -1):
        if w[i] >= w[i + 1]:
            pivot_position = i
        else:
            break

    if pivot_position == 0:
        return 'no answer'
    
    
    pivot_position -= 1

    for i in range(len(w) - 1, pivot_position, -1):
        if w[i] > w[pivot_position]:
            new_w = w[:pivot_position] + w[i] + w[pivot_position + 1:i] + w[pivot_position] + w[i + 1:]
            break

    left_part = new_w[:pivot_position + 1]
    right_part = new_w[pivot_position + 1:]
    right_part = ''.join(sorted(right_part))

    return left_part + right_part

tests = [
    ('ab', 'ba'),
    ('bb', 'no answer'),
    ('hefg', 'hegf'),
    ('dhck', 'dhkc'),
    ('dkhc', 'hcdk')
]

for test in tests:
    result = biggerIsGreater(test[0])
    if test[1] == result:
        print('OK')
    else:
        print('NOT OK -', test[0], test[1], result)


