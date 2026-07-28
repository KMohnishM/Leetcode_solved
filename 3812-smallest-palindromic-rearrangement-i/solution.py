from collections import Counter
from string import ascii_lowercase

class Solution:
    def smallestPalindrome(self, s: str) -> str:
        cnt = Counter(s)
        
        t = ""
        ch = ""
        
        for c in ascii_lowercase:
            v = cnt[c] // 2
            t+=c*v
            cnt[c] -= v * 2
            if cnt[c] == 1:
                ch = c
        
        return t + ch + t[::-1]
