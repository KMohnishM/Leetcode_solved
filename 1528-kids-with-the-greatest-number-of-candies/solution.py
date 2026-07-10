class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxi=-1
        for nums in candies:
            if nums>maxi:
                maxi=nums
        ans=[]
        for i in candies:
            if (i+extraCandies>=maxi):
                ans.append(True)
            else:
                ans.append(False)            
        return ans
