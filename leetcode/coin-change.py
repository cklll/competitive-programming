# https://leetcode.com/problems/coin-change/

from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # DP
        table = []
        coins.sort()

        for current_amount in range(1, amount + 1):
            new_item = -1

            for coin in coins:
                prev_index = current_amount - coin - 1

                if coin == current_amount:
                    new_item = 1
                    continue
                if prev_index < 0:
                    continue

                if table[prev_index] != -1:
                    if new_item != -1:
                        new_item = min(new_item, table[prev_index] + 1)
                    else:
                        new_item = table[prev_index] + 1


            table.append(new_item)

        return table[-1]


print(Solution().coinChange([1, 2, 5], 11))
print(Solution().coinChange([2], 3))
print(Solution().coinChange([2], 3))
