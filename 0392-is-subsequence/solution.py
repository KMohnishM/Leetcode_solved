class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if (len(s)==0):
            return True
        i=0
        n=len(s)
        for j in range(len(t)):
            if(s[i]==t[j]):
                i+=1
                if(i==n):
                    return True
        return False            
                
