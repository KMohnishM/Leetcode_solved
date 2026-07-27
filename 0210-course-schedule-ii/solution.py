from collections import deque
from collections import defaultdict
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
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
        order=[]
        count=0
        while queue:
            u=queue.popleft()
            order.append(u)
            count+=1
            for i in graph[u]:
                indegree[i]-=1
                if(indegree[i]==0):
                    queue.append(i)
                    # count+=1
        return order if count == numCourses else []

