class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited=set()
        n=len(grid)
        m=len(grid[0])
        mx=0
        dir=[(0,1),(1,0),(-1,0),(0,-1)]
        def dfs(a,b)->int:
            area=1
            visited.add((a,b))
            for r,c in dir:
                nr=r+a
                nc=c+b
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and (nr,nc) not in visited):
                    area+=dfs(nr,nc)
            return area        

        for i in range(n):
            for j in range(m):
                if (i,j) not in visited and grid[i][j]==1:
                  
                  mx=max(mx,dfs(i,j))    
        return mx

