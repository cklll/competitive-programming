# https://leetcode.com/problems/reverse-integer/submissions/

class Solution:
    def reverse(self, x: int) -> int:
        positive_bounds = [2,1,4,7,4,8,3,6,4,7]
        negative_bounds = [2,1,4,7,4,8,3,6,4,8]

        is_positive = x >= 0
        if not is_positive:
            x = -x

        # store x as list
        digits = []
        i = x
        while i > 0:
            remainder = i % 10
            i //= 10
            digits.append(remainder)

        if len(digits) == len(positive_bounds):
            for i in range(len(digits)):
                if is_positive:
                    if digits[i] > positive_bounds[i]:
                        return 0
                    if digits[i] < positive_bounds[i]:
                        break
                else:
                    if digits[i] > negative_bounds[i]:
                        return 0
                    if digits[i] < negative_bounds[i]:
                        break

        base = 1
        result = 0
        while len(digits) > 0:
            digit = digits.pop()
            result += base * digit
            base *= 10

        if not is_positive:
            result = -result

        return result

print(Solution().reverse(0)) # 0

print(Solution().reverse(1)) # 1
print(Solution().reverse(-1)) # -1

print(Solution().reverse(123)) # 321
print(Solution().reverse(-123)) # -321

print(Solution().reverse(-9999999999)) # 0
print(Solution().reverse(9999999999)) # 0

print(Solution().reverse(2147483412)) # 2143847412
print(Solution().reverse(-2147483412)) # -2143847412
