from collections import Counter
from math import factorial

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        freq = Counter(s)

        half = {}
        mid = ""

        for ch in sorted(freq):
            half[ch] = freq[ch] // 2
            if freq[ch] % 2:
                mid = ch

        total = sum(half.values())
        ways = factorial(total)
        for v in half.values():
            ways //= factorial(v)

        if ways < k:
            return ""

        ans = []
        rem = total

        while rem:
            for ch in sorted(half):
                if half[ch] == 0:
                    continue

                nxt = ways * half[ch] // rem

                if nxt >= k:
                    ans.append(ch)
                    ways = nxt
                    half[ch] -= 1
                    rem -= 1
                    break
                else:
                    k -= nxt

        left = "".join(ans)
        return left + mid + left[::-1]
