from collections import deque
from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph=defaultdict(list)
        indegree=[0 for _ in range(numCourses)]
        for u,v in prerequisites:
            # print(u,v)
            graph[v].append(u)
            indegree[u]+=1
        queue=deque()
        for i in range(numCourses):    
            if(indegree[i]==0):
                queue.append(i)
        count=0
        while queue:
            u=queue.popleft()
            count+=1
            for i in graph[u]:
                indegree[i]-=1
                if(indegree[i]==0):
                    queue.append(i)
        return count==numCourses

