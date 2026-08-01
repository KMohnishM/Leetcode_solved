class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n=len(obstacleGrid)
        m=len(obstacleGrid[0])
        dp = [[0] * m for _ in range(n)]
        ch=0
        for i in range(n-1,-1,-1):
           if(obstacleGrid[i][m-1]==1):
             ch=1 
           if ch==0:
             dp[i][m-1]=1
           else:
             ch=1
        ch=0     
        for j in range(m-1,-1,-1):
           if(obstacleGrid[n-1][j]==1):
            ch=1
           if ch==0:
            dp[n-1][j]=1
           else:
            ch=1

        for i in range(n-2,-1,-1):
            for j in range(m-2,-1,-1):
                if(obstacleGrid[i][j]==0):
                    dp[i][j]=dp[i+1][j]+dp[i][j+1]
                else:
                    dp[i][j]=0
        return dp[0][0]              

                
        
