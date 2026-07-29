from collections import deque
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead_set = set(deadends)
        if "0000" in dead_set:
            return -1
        if target == "0000":
            return 0
            
        queue = deque([("0000", 0)])
        visited = {"0000"}
        
        while queue:
            current_str, dist = queue.popleft()
            
            if current_str == target:
                return dist
                
            for i in range(4):
                digit = int(current_str[i])
                for move in (1, -1):
                    new_digit = (digit + move) % 10
                    next_str = current_str[:i] + str(new_digit) + current_str[i+1:]
                    
                    if next_str not in visited and next_str not in dead_set:
                        visited.add(next_str)
                        queue.append((next_str, dist + 1))
                        
        return -1
