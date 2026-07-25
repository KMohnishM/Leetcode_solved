class Solution:
    def maxProduct(self, n: int) -> int:
        arr=[]
        while(n>0):
            tmp=n%10
            arr.append(tmp)
            n=n//10
        arr.sort(reverse=True)
        
        return arr[0]*arr[1]    
        
