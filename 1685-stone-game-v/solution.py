from functools import cache
from itertools import accumulate

class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        s = list(accumulate(stoneValue, initial=0))

        @cache
        def dp(l, r):
            if l == r:
                return 0

            ans = 0
            left = 0
            right = s[r + 1] - s[l]

            for k in range(l, r):
                left += stoneValue[k]
                right -= stoneValue[k]

                if left < right:
                   
                    if ans >= 2 * left:
                        continue

                    ans = max(ans, left + dp(l, k))

                elif left > right:
                   
                    if ans >= 2 * right:
                        break

                    ans = max(ans, right + dp(k + 1, r))

                else:
                    ans = max(
                        ans,
                        left + dp(l, k),
                        right + dp(k + 1, r)
                    )

            return ans

        return dp(0, n - 1)
