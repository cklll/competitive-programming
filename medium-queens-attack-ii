# https://www.hackerrank.com/challenges/queens-attack-2/problem

def get_direction(r_q, c_q, r_o, c_o): # o = obstacle
    if c_q == c_o: # same column
        if r_q < r_o: # obstacle on the top of queen
            return 0
        else: # bottom of queen
            return 4

    if r_q == r_o: # same row
        if c_q > c_o: # obstacle on the left of queen
            return 6
        else:
            return 2

    if abs(r_q - r_o) != abs(c_q - c_o):
        return -1

    if r_q > r_o:
        if c_q > c_o: # obstacle on the bottom left
            return 5
        else: # bottom right
            return 3

    if r_q < r_o:
        if c_q > c_o: # obstacle on the top left
            return 7
        else: # top right
            return 1

    raise Exception('this should not happen')
    

def calculate_distance(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def queensAttack(n, k, r_q, c_q, obstacles):
    # set obstacles outside the grid
    closest_obstacles = [
        (n + 1, c_q), 
        None, # set later
        (r_q, n + 1), 
        None, # set later
        (-0, c_q), 
        None, # set later
        (r_q, -0), 
        None, # set later
    ] # top, right top, right, ... left top

    counter = 0
    while not (closest_obstacles[1] and closest_obstacles[3] and closest_obstacles[5] and closest_obstacles[7]):
        counter += 1
        if not closest_obstacles[1]:
            if r_q + counter > n or c_q + counter > n:
                closest_obstacles[1] = (r_q + counter, c_q + counter)
                
        if not closest_obstacles[3]:
            if r_q - counter < 1 or c_q + counter > n:
                closest_obstacles[3] = (r_q - counter, c_q + counter)

        if not closest_obstacles[5]:
            if r_q - counter < 1 or c_q - counter < 1:
                closest_obstacles[5] = (r_q - counter, c_q - counter)
                
        if not closest_obstacles[7]:
            if r_q + counter > n or c_q - counter < 1:
                closest_obstacles[7] = (r_q + counter, c_q - counter)
    
    for obstacle in obstacles:
        r_o = obstacle[0]
        c_o = obstacle[1]
        direction = get_direction(r_q, c_q, r_o, c_o)

        if direction == -1:
            continue

        closest_obstacle = closest_obstacles[direction]
        r_closest = closest_obstacle[0]
        c_closest = closest_obstacle[1]
        original_distance = calculate_distance(r_q, c_q, r_closest, c_closest)
        new_distance = calculate_distance(r_q, c_q, r_o, c_o)

        if new_distance < original_distance:
            closest_obstacles[direction] = (r_o, c_o)

    total = 0

    for i in range(8):
        if i % 2 == 0:
            distance = abs(r_q - closest_obstacles[i][0]) + abs(c_q - closest_obstacles[i][1])
        else:
            distance = abs(r_q - closest_obstacles[i][0]) # just comparing row diff is enough

        total += distance - 1

    return total
