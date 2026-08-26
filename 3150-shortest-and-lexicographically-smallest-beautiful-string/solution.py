class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ans=[]
        l=0
        cnt=0
        leng=100000
        for i,c in enumerate(s):
            if(c=='1'):
                cnt+=1
            while(cnt>=k):
                if(i-l+1<=leng):
                    leng=i-l+1
                    ans.append(int(s[l:i+1]))
                if(s[l]=='1'):
                    cnt-=1
                l+=1
        if len(ans)>0:
            return str(min(ans))
        return ""

        
