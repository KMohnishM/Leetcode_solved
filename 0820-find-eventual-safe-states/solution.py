from collections import defaultdict
from collections import deque
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        gr=defaultdict(list)
        for i in range(len(graph)):
            for j in range(len(graph[i])):
                gr[graph[i][j]].append(i)
        # print(gr)        
        # safe_st=[]
        queue=deque()
        outdegree=[-1]*(len(graph))
        for i in range(len(graph)):
            if(len(graph[i])==0):
                queue.append(i)
                # safe_st.append(i)
            outdegree[i]=len(graph[i])    

        while queue:
            sf=queue.popleft()
            for i in gr[sf]:
                
                    outdegree[i]-=1
                    if(outdegree[i]==0):
                        queue.append(i)
                        # safe_st.append(i)
        # safe_st.sort()
        # return safe_st
        return [i for i in range(len(graph)) if outdegree[i] == 0]

        
        
