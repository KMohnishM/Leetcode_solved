class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        total_pushes = 0
        
        for i in range(n):
            multiplier = (i // 8) + 1
            total_pushes += multiplier
            
        return total_pushes
