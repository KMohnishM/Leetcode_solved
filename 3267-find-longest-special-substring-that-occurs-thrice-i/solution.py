import re
class Solution:
    def maximumLength(self, s: str) -> int:
        n=len(s)
        spe=[]
        i=0
        while i<n:
            spe.append(s[i])
            tmp=s[i]
            while i+1<n and s[i+1]==s[i]:
                i+=1
                tmp+=s[i]
                spe.append(tmp)
            i+=1    
        ans=-1
        for i in spe:
            pattern = rf"(?=({re.escape(i)}))"
            count = len(re.findall(pattern,s))
            if(count>=3):
                ans=max(ans,len(i))
        return ans        
        
