class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        l=s.split()
        return len(l[len(l)-1])
        
