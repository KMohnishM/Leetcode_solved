class Solution(object):
    def mirrorDistance(self, n):
        """
        :type n: int
        :rtype: int
        """
        s=str(n)
        t=s[::-1]
        return (abs(int(t)-n))
        
