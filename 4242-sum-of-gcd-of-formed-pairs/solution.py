import math
class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        maxel=-1
        prefixgcd=[]
        for i in range(len(nums)):
            maxel=max(maxel,nums[i])
            prefixgcd.append(math.gcd(nums[i],maxel))
        prefixgcd.sort()    
        l=0
        r=len(prefixgcd)-1
        ans=0

        while(l<r):
        #   print(prefixgcd[l],prefixgcd[r])
          ans+=gcd(prefixgcd[l],prefixgcd[r])
          l+=1
          r-=1
        return ans  

