# <-- EXPAND to see the data classes
import fileinput
import json


class User(object):
    def __init__(self, id, opted_in):
        self.id = id
        self.opted_in = opted_in


class OptInChange(object):
    def __init__(self, user_id, action):
        self.user_id = user_id
        self.action = action

"""
    Sample Input:
        current_user_list: [
            User({
                id: 1,
                opted_in: false
            }),
            User({
                id: 19,
                opted_in: true
            }),
            User({
                id: 4,
                opted_in: true
            }),
            User({
                id: 54,
                opted_in: false
            })
        ]

        opt_in_change_log: [
            OptInChange({
                user_id: 19,
                action: 'opt_out'
            }),
            OptInChange({
                user_id: 1,
                action: 'opt_in'
            }),
            OptInChange({
                user_id: 71,
                action: 'opt_in'
            }),
            OptInChange({
                user_id: 19,
                action: 'opt_in'
            })
        ]

    Sample Output:
        [ 1, 71 ]
"""


def find_users_with_opt_change(current_user_list, opt_in_change_log):
    final_user_dict = {}
    initial_user_dict = {}
    for user in current_user_list:
        final_user_dict[user.id] = user.opted_in
        initial_user_dict[user.id] = user.opted_in

    for change_log in opt_in_change_log:
        final_user_dict[change_log.user_id] = change_log.action == 'opt_in'

    changed_user_ids = []
    for user_id, opted_in in final_user_dict.items():
        if user_id not in initial_user_dict:
            if opted_in:
                changed_user_ids.append(user_id)
        else:
            if opted_in != initial_user_dict[user_id]:
                changed_user_ids.append(user_id)

    changed_user_ids.sort()
    return changed_user_ids


# if __name__ == "__main__":
#     input_dict = json.loads(''.join([
#         line.strip()
#         for line in list(fileinput.input())
#     ]))

#     users = []
#     opt_in_change_log = []

#     for user in input_dict['users']:
#         users.append(User(user['id'], user['opted_in']))

#     for change_log_line in input_dict['change_log']:
#         opt_in_change_log.append(OptInChange(
#             change_log_line['user_id'],
#             change_log_line['action'],
#         ))

#     print(','.join(
#         str(user)
#         for user in find_users_with_opt_change(users, opt_in_change_log)
#     ))


current_user_list = [
    User(1, False),
    User(19, True),
    User(4, True),
    User(54, False)
]

opt_in_change_log = [
    OptInChange(19, 'opt_out'),
    OptInChange(1, 'opt_in'),
    OptInChange(71, 'opt_in'),
    OptInChange(19, 'opt_in')
]


print(find_users_with_opt_change(current_user_list, opt_in_change_log))
