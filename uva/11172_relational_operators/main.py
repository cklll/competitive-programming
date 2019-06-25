def solve(a, b):
    if a > b:
        return '>'
    elif b > a:
        return '<'
    else:
        return '='

def run():
    n = int(input())

    for i in range(n):
        a, b = map(int, input().split())
        result = solve(a, b)
        print(result)

if __name__ == "__main__":
    run()
