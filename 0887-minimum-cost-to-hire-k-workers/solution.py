import heapq

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:

        workers = []

        for i in range(len(quality)):
            ratio = wage[i] / quality[i]
            workers.append((ratio, quality[i]))

        
        workers.sort()

        max_heap = []
        total_quality = 0
        ans = float('inf')

        for ratio, q in workers:

            heapq.heappush(max_heap, -q)
            total_quality += q

            
            if len(max_heap) > k:
                removed = -heapq.heappop(max_heap)
                total_quality -= removed

            
            if len(max_heap) == k:
                ans = min(ans, ratio * total_quality)

        return ans
