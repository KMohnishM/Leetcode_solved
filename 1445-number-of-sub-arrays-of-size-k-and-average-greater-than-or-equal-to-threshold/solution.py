class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        currsum=sum(arr[:k])
        ans=0
        if(currsum/k)>=threshold:
            ans=1
        n=len(arr)
        for i in range(k,n):
            currsum+=arr[i]-arr[i-k]
            if(currsum/k)>=threshold:
                ans+=1
        return ans        

        
        
