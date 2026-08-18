from collections import defaultdict
class Solution:

  def largestInteger(self, nums: List[int], k: int) -> int:
    n = len(nums)
    cnt = defaultdict(int)

   
    for i in range(n - k + 1):
      subarray_unique = set(nums[i : i + k])
      for val in subarray_unique:
        cnt[val] += 1

   
    ans = -1
    for val, count in cnt.items():
      if count == 1 and val > ans:
        ans = val

    return ans
