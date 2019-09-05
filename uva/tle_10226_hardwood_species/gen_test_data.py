# < 10000 species
# < 1000000 trees


test_case_string = ''
for i in range(1, 1000001):
    specie = str(i % 10000)
    test_case_string += specie + '\n'

test_case_string += '\n'

# 5 test case
# 1 test case seem enough
# final_string = '5\n\n' + (test_case_string * 5)

final_string = '1\n\n' + test_case_string

with open('large_in.txt', 'w') as text_file:
    text_file.write(final_string)
