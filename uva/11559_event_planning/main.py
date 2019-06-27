def solve(hotel_prices, hotel_beds, budget, num_of_participants):
    results = []

    for price, beds in zip(hotel_prices, hotel_beds):
        cost = price * num_of_participants
        if cost > budget:
            continue
        for bed_num in beds:
            if bed_num >= num_of_participants:
               results.append(cost)
               break

    if len(results) == 0:
        return 'stay home'

    return min(results)




def run():
    while True:
        try:
            num_of_participants, budget, num_of_hotels, num_of_weeks = list(map(int, input().split()))
        except EOFError:
            return

        hotel_prices = []
        hotel_beds = [] # 2d array
        for i in range(num_of_hotels):
            hotel_prices.append(int(input()))
            hotel_beds.append(list(map(int, input().split())))

        print(solve(hotel_prices, hotel_beds, budget, num_of_participants))





if __name__ == "__main__":
    run()
