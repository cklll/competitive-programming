def run(a, b):
    max_a = max(a)
    max_b = max(b)

    print(max_a, max_b)


input() # ignore array a size
a = list(map(int, input().split()))

input() # ignore array b size
b = list(map(int, input().split()))


run(a, b)
