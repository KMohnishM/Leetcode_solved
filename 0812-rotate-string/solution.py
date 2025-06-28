class Solution:    
    def rotateString(self, s, goal):
        #your code goes here
        a=s+s
        if len(s)!=len(goal):
            return False
        if(goal in a):
          print("true") 
          return True
        else:
            return False     
           
