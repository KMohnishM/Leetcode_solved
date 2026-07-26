class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        visitedp=set()
        visitedal=set()
        n=len(heights)
        m=len(heights[0]) 
        dire=[(0,1),(1,0),(-1,0),(0,-1)]
        def dfs(i,j,visited):
            visited.add((i,j))
            for r,c in dire:
                nr=r+i
                nc=c+j
                if(0<=nr<n and 0<=nc<m and (nr,nc) not in visited and heights[nr][nc]>=heights[i][j]):
                    dfs(nr,nc,visited)

        ans=[]
        
        i=0
        for j in range(m):
            
            dfs(i,j,visitedp)
        j=0
        for i in range(n):
            
            dfs(i,j,visitedp)    
        i=n-1
        for j in range(m):
            dfs(i,j,visitedal)
        j=m-1
        for i in range(n):
            dfs(i,j,visitedal)
        for ele in visitedp:
            if ele in visitedal:
                ans.append([ele[0],ele[1]])
        return ans                    
