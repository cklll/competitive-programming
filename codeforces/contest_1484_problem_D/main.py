import math


# strategy
# keep a list of next_genres, it returns the next genre index
# when genres[index+1] is deleted, update next_genres[index] to next_genres[index+1]
# then we also prepare another list of gcd1_tuples
# this contains the consecutive genres where their gcd is 1
# when a genre is deleted and next_genres is updated, we check if the new pair is gcd1
# if it's 1, we append to the end of the list and process it later
# this way, we can ignore the irrelevant genres (gcd != 1) while keep growing the answer

def solve(genres):
    deleted_set = [False] * len(genres)
    deleted_orders = []

    next_indices = [(i+1 if i+1 < len(genres) else 0) for i in range(len(genres))]

    gcd1_pairs = []
    # first pass of the list, to generate the round of genre list to delete
    for i in range(len(genres)):
        gcd = math.gcd(genres[i], genres[next_indices[i]])
        if gcd == 1:
            gcd1_pairs.append((i, next_indices[i]))

    i = 0
    while i < len(gcd1_pairs):
        pair = gcd1_pairs[i]

        first_index = pair[0]
        second_index = pair[1]

        if deleted_set[first_index] or deleted_set[second_index]:
            i += 1
            continue

        deleted_orders.append(second_index)
        deleted_set[second_index] = True
        next_indices[first_index] = next_indices[second_index]

        gcd = math.gcd(genres[first_index], genres[next_indices[first_index]])
        if gcd == 1:
            gcd1_pairs.append((first_index, next_indices[first_index]))

        i += 1

    return deleted_orders

def run():
    t = int(input())

    for i in range(t):
        _n = int(input())
        genres = list(map(int, input().split()))
        deleted_orders = solve(genres)

        result = [str(len(deleted_orders))]
        for index in deleted_orders:
            result.append(str(index + 1))
        print(' '.join(result))


run()
