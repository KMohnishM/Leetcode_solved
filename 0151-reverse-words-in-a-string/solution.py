class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        words = s.strip().split()
        
        return ' '.join(words[::-1])

