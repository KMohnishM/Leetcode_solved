from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        visited=set()
        queue=deque()
        queue.append(0)
        visited.add(0)
        while queue:
            key=queue.popleft()
            for i in rooms[key]:
                if i not in visited:
                    queue.append(i)
                    visited.add(i)
        return len(visited)==len(rooms)
            

