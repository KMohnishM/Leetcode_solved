
from collections import deque
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        n=len(grid)
        m=len(grid[0])
        queue=deque()
        visited=set()
        dire=[(0,1),(0,-1),(1,0),(-1,0)]
        queue.append((0,0,0))
        visited.add((0,0,0))
        dist=0
        while queue:
            size=len(queue)
            for _ in range(size):
                i,j,ob=queue.popleft()
                if i==n-1 and j==m-1:
                    return dist
                for r,c in dire:
                    nr=r+i
                    nc=c+j
                    if 0<=nr<n and 0<=nc<m :

                        nob=ob+grid[nr][nc]
                        if nob<=k and (nr,nc,nob) not in visited: 
                            visited.add((nr,nc,nob))
                            queue.append((nr,nc,nob))    
            dist+=1
        # print(dist)
        return -1                
                    

        
            
