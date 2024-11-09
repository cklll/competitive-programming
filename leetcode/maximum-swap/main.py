# https://leetcode.com/problems/maximum-swap/

class Solution:
    def maximumSwap(self, num: int) -> int:
        l = list(map(int, list(str(num))))

        bucket = [-1 for _ in range(10)]
        for i in range(len(l)):
            bucket[l[i]] = i

        # print(bucket)
        for i in range(len(l)):
            digit = l[i]
            # print(f'i = {i} ; digit={digit}')

            for j in range(9, digit, -1):
                # print(f'j={j}; bucket[j]={bucket[j]}')

                if bucket[j] != -1 and bucket[j] > i:
                    l[i] = j
                    l[bucket[j]] = digit

                    return  int(''.join(map(str, l)))
        return num


print(Solution().maximumSwap(12))
print(Solution().maximumSwap(123))
print(Solution().maximumSwap(321))
