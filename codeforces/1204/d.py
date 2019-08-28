# https://codeforces.com/contest/1204/problem/D1

# def run(s):
#     # find max non-decreasing number
#     max_start_index = 0
#     max_end_index = 0
#     max_length = 1

#     current_start_index = 0

#     for i in range(1, len(s)):
#         # reset index
#         if (s[i] == '0' and s[i-1] == '1'):
#             length = i - current_start_index

#             if length > max_length:
#                 max_length = length
#                 max_start_index = current_start_index
#                 max_end_index = i - 1
#             elif length == max_length:
#                 pass # need to think whether middle is better, brute forcing is not feasible if max_length is 1 but the string is long

#             current_start_index = i

#         # handle last number
#         if i == len(s) - 1:
#             if int(s[i]) >= int(s[i-1]):
#                 length = i - current_start_index + 1
#                 # if non-increasing sequence is at the end = the best (maybe?)
#                 if length >= max_length:
#                     max_length = length
#                     max_start_index = current_start_index
#                     max_end_index = i


#     print(max_start_index, max_end_index, max_length)

def run(s):
    pairs = []
    current_start_index = 0

    for i in range(1, len(s)):
        # reset index
        if (s[i] == '0' and s[i-1] == '1'):
            pairs.append((current_start_index, i-1))
            current_start_index = i

        # handle last number
        if i == len(s) - 1:
            pairs.append((current_start_index, i))

# run('110') # 010
run('100') # 100
# run('010') # 010
# run('0001111') # 0000000
# run('0111 0011 00111 0111 01 000') # 0011 0011 00001 0111 01 000


# say non-increasing length = 5
# total length = 20

# 00001000010000100000, ending with it = best, 3's 1

# start index = 4, end with 8
# 00010000100001000010, 4's 1

# start index = 5, end with 9, start index % max_length = best
# 00001000010000100000

# start index = 6, end with 10
# 00010100000100001000
# 100001
