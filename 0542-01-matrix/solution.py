from collections import deque
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows=len(mat)
        cols=len(mat[0])
        queue=deque()
        dist=[]
        for i in range(rows):
            arr=[]
            for j in range(cols):
                arr.append(-1)
            dist.append(arr)

        for i in range(rows):
            for j in range(cols):
                if mat[i][j]==0:
                    queue.append((i,j))
                    dist[i][j]=0

        dire=[(0,1),(1,0),(-1,0),(0,-1)]
        while queue:
            size=len(queue)
            
            r,c=queue.popleft()
            for dr,dc in dire:
                nr=r+dr
                nc=c+dc
                if(nr>=0 and nr<rows and nc>=0 and nc<cols and dist[nr][nc]==-1):
                    dist[nr][nc]=dist[r][c]+1
                    queue.append((nr,nc))

        return dist


        
