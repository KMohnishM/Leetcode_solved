from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_count=Counter(s1)
        k=len(s1)
        n=len(s2)
        if(k>n):
            return False
        s2_count=Counter(s2[:k])
        if(s1_count==s2_count):
            return True

        for i in range(k,n):
            s2_count[s2[i]]+=1
            if s2_count[s2[i-k]]==1:
                del s2_count[s2[i-k]]
            else:
                s2_count[s2[i-k]]-=1
            if(s1_count==s2_count):
                return True
        return False
        
