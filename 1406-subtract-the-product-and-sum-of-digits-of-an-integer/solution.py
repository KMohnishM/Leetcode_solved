class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        prod=1
        sum=0
        tmp=n
        while(tmp>0):
            sum+=tmp%10
            prod*=tmp%10
            tmp=tmp/10
        return prod-sum    
        
