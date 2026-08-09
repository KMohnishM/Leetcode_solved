class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        memo = {}

        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = piles[i] + suffix[i + 1]

        def dfs(i, M):
            if i >= n:
                return 0

            if (i, M) in memo:
                return memo[(i, M)]

            best = 0

            for X in range(1, 2 * M + 1):
                if i + X > n:
                    break

               
                total = suffix[i]

              
                bob = dfs(i + X, max(M, X))

              
                alice = total - bob

                best = max(best, alice)

            memo[(i, M)] = best
            return best

        return dfs(0, 1)
