class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum=0
        prod=1
        s=str(n)
        for i in s:
            sum+=int(i)
            prod*=int(i)
        return n%(sum+prod)==0    
        
