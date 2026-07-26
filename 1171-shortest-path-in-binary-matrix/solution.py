from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        queue=deque()
        dire=[(0,1),(1,0),(-1,0),(0,-1),(1,1),(-1,-1),(-1,1),(1,-1)]
        if grid[0][0]==1:
            return -1
        dist=1
        queue.append((0,0))
        
        while queue:
          size=len(queue)
          for _ in range(size):
            r,c=queue.popleft()
            if(r==n-1 and c==m-1):
                return dist
            for i,j in dire:
                nr=r+i
                nc=c+j
                if(0<=nr<n and 0<=nc<m and grid[nr][nc]==0):
                    
                    queue.append((nr,nc))
                    
                    grid[nr][nc]=1
          dist+=1        
        return -1     


