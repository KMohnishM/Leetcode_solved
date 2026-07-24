from typing import List

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        dp = [{0}, set(), set(), set()]

        for x in nums:
            new = [s.copy() for s in dp]

            for k in range(2, -1, -1):
                for val in dp[k]:
                    new[k + 1].add(val ^ x)

            dp = new

        return len(set(nums) | dp[3])
