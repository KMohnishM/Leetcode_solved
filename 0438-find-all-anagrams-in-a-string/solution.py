from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # c1=Counter(p)
        c1={}
        for i in p:
            if (i in c1):
                c1[i]+=1
            else:
                c1[i]=1
        k=len(p)
        n=len(s)    
        if(k>n):
            return []
        # c2=Counter(s[:k])
        c2={}
        for i in range(k):
            if(s[i] in c2):
                c2[s[i]]+=1
            else:
                c2[s[i]]=1

        ans=[]
        if(c2==c1):
            ans.append(0)
        

        for i in range(k,n):
             c2[s[i-k]]-=1
             if(c2[s[i-k]]==0):
                del c2[s[i-k]]
             if(s[i] in c2):
                c2[s[i]]+=1
             else:
                c2[s[i]]=1
            #  print(c1,c2)   
             if(c2==c1):
                ans.append(i-k+1)
        return ans              
