from collections import Counter
from typing import List


class Solution:

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = Counter(nums)
       
        ans = [item[0] for item in sorted(c.items(), key=lambda x: x[1], reverse=True)[:k]]
        return ans
