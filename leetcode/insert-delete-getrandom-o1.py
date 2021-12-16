# https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/

import random

class RandomizedSet:

    def __init__(self):
        self.data = []
        self.val_to_index = {}


    def insert(self, val: int) -> bool:
        if val in self.data:
            return False
        self.data.append(val)
        self.val_to_index[val] = len(self.data) - 1
        return True


    def remove(self, val: int) -> bool:
        # strategy: move the last element in the list to the deleted position
        if val in self.data:
            last_element = self.data[-1]

            if last_element == val:
                pass
            else:
                index_to_delete = self.val_to_index[val]
                self.data[index_to_delete] = last_element
                self.val_to_index[last_element] = index_to_delete

            del self.data[-1] # delete last item should be O(1)
            del self.val_to_index[val]
            return True

        return False


    def getRandom(self) -> int:
        index = random.randint(0, len(self.data)-1)
        return self.data[index]
