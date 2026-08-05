from collections import defaultdict
class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        gr=defaultdict(list)
        for i in range(len(invocations)):
            gr[invocations[i][0]].append(invocations[i][1])
            
        sus=set()
        def dfs(node):
            sus.add(node)
            for nei in gr[node]:
                if(nei not in sus):
                    dfs(nei)
        dfs(k)
        check=0
        for i in range(n):
            if i not in sus:
                for nei in gr[i]:
            
                    if nei in sus:
                        check=1
                              
        ans=[]
        if check==0:
            for i in range(n):
                if i not in sus:
                    ans.append(i)
        else:
            for i in range(n):
                ans.append(i)
                            
    
        
        
        
        return ans        


