# https://www.hackerrank.com/challenges/encryption/problem

def get_row_col(s):
    lower = math.floor(math.sqrt(len(s)))
    upper = math.ceil(math.sqrt(len(s)))
    
    min_area = upper * upper
    min_row = upper
    min_col = upper
    
    for i in range(lower, upper + 1):
        for j in range(i, upper + 1):
            if i * j >= len(s):
                if min_area > i * j:
                    min_row = i
                    min_col = j
                    min_area = i * j
    return [min_row, min_col]

def encryption(s):
    
    [row, col] = get_row_col(s)
    print(row, col)
    
    result = ''
    row_counter = 0
    col_counter = 0
    for char in s:
        result += s[col * row_counter + col_counter]
        
        row_counter += 1
        if (row_counter % row == 0) or (col * row_counter + col_counter >= len(s)):
            row_counter = 0
            col_counter += 1
            result += ' '
            
    return result.strip()
