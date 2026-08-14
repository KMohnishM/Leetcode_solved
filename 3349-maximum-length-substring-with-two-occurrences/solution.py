class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        frq_m={}
        l=0
        ans=0
        for right,i in enumerate(s):
            frq_m[i]=frq_m.get(i,0)+1
            while frq_m[i]>2:
                frq_m[s[l]]-=1
                l+=1
            ans=max(ans,right-l+1)
        return ans        

        
