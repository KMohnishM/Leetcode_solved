class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        memo = {}

        def max_diff(i):
            if i >= n:
                return 0

            if i in memo:
                return memo[i]

            best = float('-inf')
            curr_sum = 0

            for k in range(3):
                if i + k < n:
                    curr_sum += stoneValue[i + k]
                    best = max(best, curr_sum - max_diff(i + k + 1))

            memo[i] = best
            return best

        diff = max_diff(0)

        if diff > 0:
            return "Alice"
        elif diff < 0:
            return "Bob"
        else:
            return "Tie"
