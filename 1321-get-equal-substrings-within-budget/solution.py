class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        cost=0
        l=0
        ans=0
        for i in range(len(s)):
            if(s[i]!=t[i]):
                cost+=abs(ord(s[i])-ord(t[i]))
            while(cost>maxCost):
                if(s[l]!=t[l]):
                    cost-=abs(ord(s[l])-ord(t[l]))
                l+=1
            ans=max(ans,i-l+1)
        return ans                
