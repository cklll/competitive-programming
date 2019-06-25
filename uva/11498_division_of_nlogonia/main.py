def solve(dx, dy, x, y):
    if x == dx or y == dy:
        return 'divisa'

    if x > dx and y > dy:
        return 'NE'

    if x > dx:
        return 'SE'

    if x < dx and y > dy:
        return 'NO'

    if x < dx:
        return 'SO'

def run():
    while True:
        n = int(input())
        if n == 0:
            return

        division_point_x, division_point_y = map(int, input().split())

        for i in range(n):
            x, y = map(int, input().split())
            result = solve(division_point_x, division_point_y, x, y)
            print(result)

if __name__ == "__main__":
    run()
