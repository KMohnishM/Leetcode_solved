class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        search=set(nums)
        start=min(nums)
        end=max(nums)
        ans=[]
        for i in range(start,end):
            if i not in search:
                ans.append(i)
        return ans        


        

        
