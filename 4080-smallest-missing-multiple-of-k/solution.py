class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        num=set(nums)
        i=1
        while True:
           tmp=k*i
           if(tmp not in num):
            return tmp
           i+=1 
        return 0    

