import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        t=0
        n=len(grid)
        m=len(grid[0])
        visited={}
        pq=[(grid[0][0],0,0)]
        
        dire=[(0,1),(1,0),(-1,0),(0,-1)]
        dist = [[float('inf') for _ in range(m)] for _ in range(n)]
        dist[0][0]=0
        while pq:
            cost,r,c=heapq.heappop(pq)
            if(r,c)==(n-1,m-1):
                return dist[r][c]
            for i,j in dire:
                nr=r+i
                nc=c+j
                if(0<=nr<n and 0<=nc<m):
                    n_cost=max(cost,grid[nr][nc])
                    if(n_cost<dist[nr][nc]):
                       dist[nr][nc]=n_cost 
                       heapq.heappush(pq,(n_cost,nr,nc))
        return -1            


        
        
