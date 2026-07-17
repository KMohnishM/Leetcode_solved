from typing import List
from bisect import bisect_left

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:

        mx = max(nums)
        freq = [0] * (mx + 1)
        for x in nums:
            freq[x] += 1

        exact = [0] * (mx + 1)
        for g in range(mx, 0, -1):

           
            cnt = 0
            for multiple in range(g, mx + 1, g):
                cnt += freq[multiple]
            pairs = cnt * (cnt - 1) // 2

            multiple = 2 * g
            while multiple <= mx:
                pairs -= exact[multiple]
                multiple += g

            exact[g] = pairs

       
        prefix = [0] * (mx + 1)
        for g in range(1, mx + 1):
            prefix[g] = prefix[g - 1] + exact[g]

        ans = []

        for q in queries:
            l, r = 1, mx
            while l < r:
                mid = (l + r) // 2
                if prefix[mid] > q:
                    r = mid
                else:
                    l = mid + 1
            ans.append(l)

        return ans
