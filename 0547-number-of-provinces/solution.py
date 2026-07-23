class Solution:
    

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
      visit=set()
      n=len(isConnected)
      count=0
      def dfs(a):
        visit.add(a)
        for j in range(n):
            if isConnected[a][j]==1 and j not in visit:
                dfs(j)
      for i in range(n):
        # visited=set()
        if i not in visit:
            # visit.add(i)
            dfs(i)
            count+=1
      return count      



        
