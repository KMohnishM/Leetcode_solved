from collections import Counter
from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        c1=Counter(t)
        l=0
        ans=1000000
        c2=defaultdict(int)
        need=len(c1)
        have=0
        result=""
        for i,ch in enumerate(s):
           c2[ch]+=1
           if(ch in c1 and c2[ch]==c1[ch]):
              have+=1
           if(have==need):
              while(have==need):
                if i - l + 1 < ans:
                    ans = i - l + 1
                    result = s[l:i+1]
                if(s[l] in c1 and c2[s[l]]==c1[s[l]]):
                    break
                c2[s[l]]-=1
                l+=1

        return result        


