# https://leetcode.com/problems/the-skyline-problem/
# !! TODO

from typing import List



# case 1 - the new building is taller than all current_buildings, and within ranges
#    __
#   |  |
#   |  |
#  _______
# |       |
# |       |

# case 2 - the new building is taller than all current_buildings, and right is outside range
#    ___________
#   |           |
#   |           |
#  _______      |
# |       |     |
# |       |     |

# case 3 - the new building is shorter than all current_buildings, and within ranges
#  ______________
# |              |
# |   _______    |
# |  |       |   |
# |  |       |   |
# |  |       |   |

# case 4 - the new building is shorter than all current_buildings, and right is outside range
#  ______________
# |              |
# |   ___________|___
# |  |               |
# |  |               |
# |  |               |

# case 5 - the new building completely outside range
#  ______________
# |              |
# |              |   _______________
# |              |  |               |
# |              |  |               |
# |              |  |               |


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        buildings.sort(key=lambda x: (x[0], x[2], x[1]))

        current_buildings = [buildings[0]]
        result = [[buildings[0][0], buildings[0][2]]]

        for building in buildings[1:]:
            left, right, height = building

            current_buildings_left = min([b[0] for b in current_buildings])
            current_buildings_right = max([b[1] for b in current_buildings])

            # case 5
            if right > current_buildings_right:
                result.append(current_buildings_right, )













Solution().getSkyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]])
# [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
