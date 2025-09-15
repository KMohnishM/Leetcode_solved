class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        l1=text.split(" ");
        count=len(l1)
        
        for i in range(0,len(l1)):
            for j in range(0,len(l1[i])):
                if  l1[i][j] in brokenLetters:
                    count-=1
                    break
        return count
                    
