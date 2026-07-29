from collections import defaultdict
import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph=defaultdict(list)
        for u,v,w in flights:
            graph[u].append((v,w))
        # dist=[[float('inf')for _ in range(k+2)]]*(n)
        # print(dist)
        dist = [[float('inf')] * (k + 2) for _ in range(n)]
        # print(dist)
        dist[src][0]=0
        heap=[(0,src,0)]
        while heap:
            d, u, stops = heapq.heappop(heap)

            if d > dist[u][stops]:
                continue

          
            if u == dst:
                return d

            if stops == k + 1:
                continue

            for v, w in graph[u]:
                newCost = d + w

                if newCost < dist[v][stops + 1]:
                    dist[v][stops + 1] = newCost
                    heapq.heappush(heap, (newCost, v, stops + 1))
                        
                
        ans=min(dist[dst])
        return ans if ans != float("inf") else -1
        


        
        
