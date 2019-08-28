# https://codeforces.com/contest/1204/problem/B

def run(n, l, r):
    max_result = 0
    num_of_max_num = n - r + 1
    max_num = 2 ** (r - 1)
    max_result = max_num * num_of_max_num
    for i in range(0, r - 1):
        max_result += 2 ** i

    min_result = 0
    num_of_one = n - l + 1
    min_result += num_of_one
    for i in range(1, l):
        min_result += (2 ** i)

    print(min_result, max_result)


n, l, r = list(map(int, input().split()))
run(n, l, r)
# run(4, 2, 2) # 5 7
# run(5, 1, 5) # 5 31
