def solve(well_height, climb_distance, slide_distance, fatigue_factor):
    decrement = climb_distance * (fatigue_factor / 100)

    day = 0
    current_height = 0
    current_climb_distance = climb_distance
    while True:
        day += 1

        current_height += current_climb_distance

        if current_height > well_height:
            return "success on day {}".format(day)

        current_height -= slide_distance

        if current_height < 0:
            return "failure on day {}".format(day)

        current_climb_distance -= decrement
        current_climb_distance = max(current_climb_distance, 0)

def run():
    while True:
        well_height, climb_distance, slide_distance, fatigue_factor = list(map(int, input().split()))

        if well_height == 0:
            return

        print(solve(well_height, climb_distance, slide_distance, fatigue_factor))

if __name__ == "__main__":
    run()
