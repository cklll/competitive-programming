# Complete the closest function below.
def closest(s, queries):
    index = {}
    for i in range(len(s)):
        current_char = s[i]
        if current_char not in index:
            index[current_char] = {}
            index[current_char]['last'] = -1

        prev_index = index[current_char]['last']
        index[current_char][i] = [prev_index, -1]
        
        if index[current_char]['last'] != - 1:
            index[current_char][prev_index][1] = i

        index[current_char]['last'] = i

    result = []
    for q in queries:
        char = s[q]
        if index[char][q][0] == -1 and index[char][q][1] == -1:
            result.append(-1)
        elif index[char][q][0] == -1:
            result.append(index[char][q][1])
        elif index[char][q][1] == -1:
            result.append(index[char][q][0])
        else:
            closest_index = index[char][q][0] if q - index[char][q][0] <= index[char][q][1] - q else index[char][q][1]
            result.append(closest_index)

    return result

# result = closest('hackerrank', [4, 1, 6, 8])
# print(result)

# result = closest('aaaaaa', [0,1,2,3,4,5])
# print(result)

# result = closest('a', [0])
# print(result)
# result = closest('ab', [0,1])
# print(result)

# result = closest('aa', [0,1])
# print(result)
# result = closest('aba', [0,1,2])
# print(result)
result = closest('abaa', [0,1,2,3])
print(result)
result = closest('abab', [0,1,2,3])
print(result)
result = closest('ababf', [0,1,2,3,4])
print(result)