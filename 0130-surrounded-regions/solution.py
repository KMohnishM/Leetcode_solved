class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        visited=set()
        n=len(board)
        m=len(board[0])
        dire=[(0,1),(1,0),(-1,0),(0,-1)]
        def dfs(a,b):
            visited.add((a,b))
            for r,c in dire:
                nr=r+a
                nc=c+b
                if(nr>=0 and nr<n and nc>=0 and nc<m and board[nr][nc]=='O' and (nr,nc) not in visited):
                    dfs(nr,nc)



        i=0
        for j in range(m):
            if (i,j) not in visited and board[i][j]=='O':
                dfs(i,j)
        i=n-1
        for j in range(m):
            if (i,j) not in visited and board[i][j]=='O':
                dfs(i,j)
        j=0
        for i in range(n):
            if (i,j) not in visited and board[i][j]=='O':
                dfs(i,j)
        j=m-1
        for i in range(n):
            if (i,j) not in visited and board[i][j]=='O':
                dfs(i,j)     
        for i in range(n):
            for j in range(m):
                if (i,j) not in visited :
                    board[i][j]='X'                   
        return board        
