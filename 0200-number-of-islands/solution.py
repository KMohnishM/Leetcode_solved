class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited=set()
        n=len(grid)
        m=len(grid[0])
        count=0
        dir=[(1,0),(-1,0),(0,1),(0,-1)]
        def dfs(a,b):
            visited.add((a,b))
            for r,c in dir:
                nr=a+r
                nc=b+c
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]=='1' and (nr,nc) not in visited):
                    dfs(nr,nc)


        for i in range(n):
            # print(i)
            for j in range(m):
                
                if ((i,j) not in visited) and grid[i][j]=='1': 
                    # print(i,j)
                    dfs(i,j)
                    count+=1
        return count
