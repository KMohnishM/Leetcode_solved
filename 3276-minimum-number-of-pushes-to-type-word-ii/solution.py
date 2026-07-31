class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = sorted(Counter(word).values(), reverse=True)

        ans = 0
        for i, f in enumerate(freq):
            # print(i,f)
            ans += f * ((i // 8) + 1)
        return ans
 
        
