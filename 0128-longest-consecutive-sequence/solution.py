class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n=len(nums)
        visited=set()
        numset=set(nums)
        ans=0
        for i in numset:
            
            if i-1 not in numset :
               a=i
               le=1 
               while a+1 in numset:
                   le+=1
                   a+=1
               ans=max(ans,le)
            #    visited.add(i)
        return ans               
                
                   

        
        
