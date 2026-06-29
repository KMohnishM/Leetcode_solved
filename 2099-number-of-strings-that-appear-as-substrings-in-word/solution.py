class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        count=0
        for words in patterns:
            if words in word:
                count=count+1
        return count         
        
