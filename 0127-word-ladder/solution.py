from collections import deque
import string

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0
            
        queue = deque([beginWord])
        dist = 1  
        
        while queue:
           
            for _ in range(len(queue)):
                word = queue.popleft()
                
               
                if word == endWord:
                    return dist
                
                
                for i in range(len(word)):
                    original_char = word[i]
                    
                    for ch in string.ascii_lowercase:
                        if ch == original_char:
                            continue
                            
                       
                        tmp = word[:i] + ch + word[i+1:]
                        
                        
                        if tmp in words:
                            queue.append(tmp)
                            words.remove(tmp) 
                            
                    
            dist += 1
            
        return 0
