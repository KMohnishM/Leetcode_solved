from collections import defaultdict
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # ans=[0,0]
        graph=defaultdict(list)
        # visited=set()
        
        def dfs(node , parent , tar , visited):
           if node==tar:
            return True
           visited.add(node)
           for nei in graph[node]:
             if nei!=parent:
                if dfs(nei,node,tar,visited):
                    return True
           return False
             


        for u,v in edges:
            visited=set()
            if not dfs(u,-1,v,visited):
                graph[u].append(v)
                graph[v].append(u)
            else:
                return [u,v]
        


     
