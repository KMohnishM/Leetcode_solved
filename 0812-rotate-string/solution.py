class Solution(object):
    def rotateString(self, s, goal):
        if(len(goal)==len(s)):
            a=s+s
            if(goal in a):
                return True
            return False
        else:
            return False    

        
