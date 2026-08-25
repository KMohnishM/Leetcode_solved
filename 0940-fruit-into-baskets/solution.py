class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cnt={}
        l=0
        ans=0
        for i,t in enumerate(fruits):
            if(t in cnt):
                cnt[t]+=1
            else:
                cnt[t]=1
            while(len(cnt)>2):
                cnt[fruits[l]]-=1
                if(cnt[fruits[l]]==0):
                    del cnt[fruits[l]]
                l+=1
            ans=max(ans,i-l+1)
        return ans                    
