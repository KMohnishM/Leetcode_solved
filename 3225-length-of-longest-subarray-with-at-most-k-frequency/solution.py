class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n=len(nums)
        freq_last={}
        l=0
        ans=0
        for right,i in enumerate(nums):
            if i not in freq_last:
                freq_last[i]=1
            else:
                if freq_last[i]+1>k:
                   while(l<n and freq_last[i]+1>k):
                    freq_last[nums[l]]=freq_last[nums[l]]-1
                    l+=1  
                freq_last[i]=freq_last[i]+1
            ans=max(ans,right-l+1)    
                   
        return ans           
                        

