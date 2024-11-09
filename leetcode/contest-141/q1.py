
from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        result = []

        for num in nums:
            binary_text = bin(num)[2:]
            if num == 2:
                result.append(-1)
            elif len(binary_text) == binary_text.count('1'):
                new_binary_string = binary_text[1:]
                result.append(int(new_binary_string, 2))
            else:
                zero_index= binary_text.rfind('0')
                index_to_change = zero_index+1
                new_binary_string = binary_text[:index_to_change] + '0' + binary_text[index_to_change+1:]
                result.append(int(new_binary_string, 2))

        return result


print(Solution().minBitwiseArray([5]))
print(Solution().minBitwiseArray([37]))
print(Solution().minBitwiseArray([97]))
print(Solution().minBitwiseArray([71]))
# print(Solution().minBitwiseArray([2,3,5,7]))
# print(Solution().minBitwiseArray([11,13,31]))


print(Solution().minBitwiseArray([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]))
print(Solution().minBitwiseArray([99997981, 99998021, 99998051, 99998071, 99998099, 99998111, 99998147, 99998191, 99998207, 99998231, 99998251, 99998257, 99998291, 99998299, 99998323, 99998357, 99998363, 99998377, 99998413, 99998417]))
