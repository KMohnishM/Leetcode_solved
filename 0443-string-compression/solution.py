class Solution:
    def compress(self, chars: List[str]) -> int:
        i=0
        l=0
        n=len(chars)
        while(i<n):
            ch=chars[i]
            j=1
            # print(i,j)
            while(i+1!=n and ch==chars[i+1]):
               j+=1
               i+=1        
            chars[l]=ch
            l+=1 
            i+=1    
            
            if(j!=1):
               for digit in str(j):
                    chars[l] = digit
                    l+= 1
                
                 
        
        # print(chars)
        return l   

