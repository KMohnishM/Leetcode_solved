class Solution:
    def sumAndMultiply(self, n: int) -> int:
        if n==0:
            return 0
        tmp=str(n)
        x=""
        sum=0
        # print(tmp)
        for i in tmp:
            # print(i)
            if int(i)!=0:
                x+=i
                sum+=int(i)
        # print(x)        
        return int(x)*sum
        # return 0


        
