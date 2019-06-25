def solve(a, b, c):
    salaries = [a, b, c]
    salaries.sort()
    return salaries[1]

def run():
    n = int(input())

    for i in range(n):
        a, b, c = map(int, input().split())
        result = solve(a, b, c)
        print("Case {}: {}".format(i + 1, result))

if __name__ == "__main__":
    run()
