class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        window=[]
        n=len(nums)
        sum=0
        for i in range(n):
            sum+=nums[i]
            window.append(sum)
        l=0
        ans=window[k-1]/k
        for i in range(k,n):
            avg=(window[i]-window[l])/k
            ans=max(ans,avg)
            l+=1
        return ans    


