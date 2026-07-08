from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        
        prefConcat = [0] * (n + 1)

       
        prefCount = [0] * (n + 1)

      
        prefSum = [0] * (n + 1)

       
        pow10 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        for i in range(n):
            d = ord(s[i]) - ord('0')

            prefSum[i + 1] = prefSum[i] + d

            if d == 0:
                prefConcat[i + 1] = prefConcat[i]
                prefCount[i + 1] = prefCount[i]
            else:
                prefConcat[i + 1] = (prefConcat[i] * 10 + d) % MOD
                prefCount[i + 1] = prefCount[i] + 1

        ans = []

        for l, r in queries:
           
            k = prefCount[r + 1] - prefCount[l]

            x = (
                prefConcat[r + 1]
                - prefConcat[l] * pow10[k]
            ) % MOD

            digitSum = prefSum[r + 1] - prefSum[l]

            ans.append((x * digitSum) % MOD)

        return ans
