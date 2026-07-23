class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
       n=len(image)
       m=len(image[0]) 
    #    visited=set() 
       dire=[(0,1),(1,0),(0,-1),(-1,0)]
       def dfs(a,b,inc):
        #  visited.add((a,b))
         for r,c in dire:
            nr=r+a
            nc=c+b
            if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==inc ):
                image[nr][nc]=color
                dfs(nr,nc,inc)
       original=image[sr][sc]
       if original==color:
        return image
       image[sr][sc]=color
       dfs(sr,sc,original)
       return image         

        
