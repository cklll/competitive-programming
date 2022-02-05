from collections import defaultdict

# strategy
# we try to fill the value by diagonals, from top left to bottom right
# KEY observation
# we should make each diagonal to have the same value since we are filling in this order
# if not, imagine this state
# 1 2
# 3 0
# then alice will say "1" and we will lose

response_mapping = {
    '1': ['2', '3', '23'],
    '2': ['3', '1', '13'],
    '3': ['1', '2', '12'],
}

# split function because i can early exit
def fill_next(grid, limited_cells, alice):
    keys_to_check = response_mapping[alice]
    for key in keys_to_check[:2]:
        for i in range(len(limited_cells[key])):
            cell = limited_cells[key][i]
            x, y = cell[0], cell[1]

            # already filled, skip
            if grid[x][y]:
                # TODO: better remove item as well
                continue

            value = key[0]
            grid[x][y]



def play():
    n = int(input())
    grid = [[None for _ in range(n+1)]] * (n+1)

    # key is the limited options, values are the positions
    limited_cells = defaultdict([])

    # specially handle first case
    alice = input()
    x = 1
    y = 1
    if alice == '1':
        grid[x][y] = '2'
        limited_cells["13"] += [(1, 2), (2, 1)]
    if alice == '2':
        grid[x][y] = '3'
        limited_cells["12"] += [(1, 2), (2, 1)]
    if alice == '3':
        grid[x][y] = '1'
        limited_cells["23"] += [(1, 2), (2, 1)]

    print(f'{grid[x][y]} {x} {y}', flush=True)



    for i in range(n*n - 1):
        alice = input()
        fill_next(grid, limited_cells, alice)


        if limited_cells[alice]:
            cell = limited_cells[alice][0].pop(0)

            grid[x][y] = alice



play()
