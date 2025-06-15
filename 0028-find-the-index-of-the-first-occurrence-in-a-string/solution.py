class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle)>len(haystack):
            return -1
        for w in range(len(haystack)):
            if haystack[w]==needle[0]:
                if haystack[w:w+len(needle)]==needle:
                    return w
        return -1
