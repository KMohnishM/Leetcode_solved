from collections import defaultdict, deque
from typing import List

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)

        if n == 1:
            return 0

        value_to_indices = defaultdict(list)

        for i, value in enumerate(arr):
            value_to_indices[value].append(i)

        queue = deque([0])
        visited = [False] * n
        visited[0] = True

        steps = 0

        while queue:
            for _ in range(len(queue)):
                index = queue.popleft()

                if index == n - 1:
                    return steps

                neighbors = []

                if index - 1 >= 0:
                    neighbors.append(index - 1)

                if index + 1 < n:
                    neighbors.append(index + 1)

                neighbors.extend(value_to_indices[arr[index]])

                for next_index in neighbors:
                    if not visited[next_index]:
                        visited[next_index] = True
                        queue.append(next_index)

                
                value_to_indices[arr[index]].clear()

            steps += 1

        return -1
