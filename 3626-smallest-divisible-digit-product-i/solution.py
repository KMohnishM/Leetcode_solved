class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def sum(i):
            ans=1
            while i>0:
                ans=ans*(i%10)
                i=i//10
            return ans    
        while True:
            if(sum(n)%t==0):
                return n
            else:
                n+=1    
        
