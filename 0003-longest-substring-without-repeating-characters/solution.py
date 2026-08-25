class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cnt={}
        l=0
        n=len(s)
        ans=0
        for i,ch in enumerate(s):
            if(ch in cnt):
                cnt[ch]+=1
            else:
                cnt[ch]=1
            while(cnt[ch]>1):
                cnt[s[l]]-=1
                l+=1
            ans=max(ans,i-l+1)
        return ans    
