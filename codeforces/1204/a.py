# https://codeforces.com/contest/1204/problem/A

def run(s):
    if s == '0' or s == '1':
        return print(0)

    # calculate how many 4^x place
    # result = len(s) / 2

    # if result.is_integer():
    #     # arrive at the same time as depart, can remove 1
    #     if s.count('1') <= 1:
    #         result -= 1
    # else:
    #     result += 1

    # print(int(result))

    result = None
    # if len(s) % 2 == 0:
    #     if s.count('1') == 1:
    #         result = len(s) / 2
    #     else:
    #         result = (len(s) / 2) + 1
    # else:
    #     if s.count('1') == 1:
    #         result = (len(s) - 1) / 2
    #     else:
    #         result = (len(s) + 1) / 2

    if len(s) % 2 == 1:
        if s.count('1') == 1:
            result = (len(s) - 1) / 2
        else:
            result = (len(s) + 1) / 2
    else:
        # if s.count('1') == 1:
        result = len(s) / 2

    print(int(result))


# in binary format 100000000
s = input()
run(s)

# run('0') # 0
# run('1') # 0
# run('10') # 1
# run('11') # 1
# run('100000000') # 4
# run('100') # 1
# run('101') # 2
# run('111') # 2
# run('10100') # 3
# run('10001') # 3
# run('11111') # 3
# run('10111') # 3

# run('10000000000') # int(11 / 2) = 5
# run('100000000000') # int(12 / 2) = 6

# run('1111') # 2
# run('1000') # 2
# run('1001') # 2
