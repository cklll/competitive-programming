# https://onlinejudge.org/external/102/10226.pdf
# timeoue

def format_dict(tree_dict, total_len):
    species = list(tree_dict.keys())
    species.sort()

    result = ''
    for specie in species:
        percentage = '%.4f' % (tree_dict[specie] / total_len * 100)
        result += '{} {}\n'.format(specie, percentage)

    return result + '\n'

def run():
    n = int(input())
    input() # ignore empty line

    tree_dict = {}
    total_len = 0
    final_result = ''
    while n > 0:
        try:
            line = input()
        except EOFError:
            final_result += format_dict(tree_dict, total_len)
            print(final_result)
            return

        if line == '':
            final_result += format_dict(tree_dict, total_len)
            n -= 1
            tree_dict = {}
            total_len = 0
        else:
            total_len += 1
            if line in tree_dict:
                tree_dict[line] += 1
            else:
                tree_dict[line] = 1

    print(final_result)

run()
