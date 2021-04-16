# KEY observation
# if there are 2 people with availability more than m/2 days
# then we can ALWAYS satisfy the constraint
# so in fact, we only need to care the person with most availability

from collections import defaultdict
import math

def solve(friends):
    num_days = len(friends)
    max_limit = math.ceil(num_days / 2)

    max_counter_hash = defaultdict(int)
    max_counter = 1
    max_friend = friends[0][0]
    for friends_of_day in friends:
        for friend in friends_of_day:
            max_counter_hash[friend] += 1
            if max_counter_hash[friend] > max_counter:
                max_counter = max_counter_hash[friend]
                max_friend = friend

    # we count how many day the max friend is alone
    max_friend_used_count = 0
    for i in range(num_days):
        if len(friends[i]) == 1 and friends[i][0] == max_friend:
            max_friend_used_count += 1

    result = []
    for i in range(num_days):
        if len(friends[i]) == 1:
            result.append(friends[i][0])
        else:
            # there is spare space for max_friend to use in this day.
            # just use it
            if max_friend in friends[i] and max_friend_used_count < max_limit:
                result.append(max_friend)
                max_friend_used_count += 1
            else:
                # otherwise, just use any other friend
                for friend in friends[i]:
                    if friend != max_friend:
                        result.append(friend)
                        break

    friend_used_counter_hash = defaultdict(int)
    for friend in result:
        friend_used_counter_hash[friend] += 1
        if friend_used_counter_hash[friend] > max_limit:
            return 'NO'

    return 'YES\n' + ' '.join(result)

def run():
    t = int(input())

    for i in range(t):
        num_friends, num_days = map(int, input().split())

        friends = []
        for day in range(num_days):
            _, *available_friends = input().split()
            friends.append(available_friends)

        print(solve(friends))


run()



# 1: x y
# 2: x y
# 3: x y
# 4: x y
# 5: x
