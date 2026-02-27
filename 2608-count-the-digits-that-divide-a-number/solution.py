class Solution(object):
    def countDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        count=0
        tmp=num
        while(tmp>0):
            tmp1=tmp%10
            if(num%tmp1==0):
                count+=1
            tmp=tmp/10
        return count        
              
