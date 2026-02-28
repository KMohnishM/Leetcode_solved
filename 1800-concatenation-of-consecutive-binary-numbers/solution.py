class Solution(object):
    def concatenatedBinary(self, n):
        """
        :type n: int
        :rtype: int
        """
        s=""
        for i in range(1,n+1):
            s+=format(i,'b')
        return int(s,2)%(1000000007)

        
