from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:

        # (value, original_index)
        arr = sorted((nums[i], i) for i in range(n))

        # position of each original index in sorted order
        pos = [0] * n
        for i, (_, idx) in enumerate(arr):
            pos[idx] = i

        # component id of every position in sorted order
        comp = [0] * n

        # next[i] = furthest sorted position reachable in one jump
        next_pos = [0] * n

        j = 0
        cid = 0

        for i in range(n):
            while j + 1 < n and arr[j + 1][0] - arr[i][0] <= maxDiff:
                j += 1

            next_pos[i] = j

            if i > 0 and arr[i][0] - arr[i - 1][0] > maxDiff:
                cid += 1
            comp[i] = cid

        LOG = 18  # since 2^17 > 1e5

        jump = [next_pos]

        for _ in range(1, LOG):
            prev = jump[-1]
            curr = [0] * n
            for i in range(n):
                curr[i] = prev[prev[i]]
            jump.append(curr)

        ans = []

        for u, v in queries:

            pu = pos[u]
            pv = pos[v]

            if pu > pv:
                pu, pv = pv, pu

            if comp[pu] != comp[pv]:
                ans.append(-1)
                continue

            if pu == pv:
                ans.append(0)
                continue

            cur = pu
            steps = 0

            for k in range(LOG - 1, -1, -1):
                if jump[k][cur] < pv:
                    cur = jump[k][cur]
                    steps += 1 << k

            ans.append(steps + 1)

        return ans
