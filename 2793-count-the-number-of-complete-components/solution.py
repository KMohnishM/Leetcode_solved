from collections import defaultdict

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        ans = 0

        def dfs(node):
            nonlocal nodes, edge_count

            visited[node] = True
            nodes += 1
            edge_count += len(graph[node])

            for nei in graph[node]:
                if not visited[nei]:
                    dfs(nei)

        for i in range(n):
            if not visited[i]:
                nodes = 0
                edge_count = 0

                dfs(i)

                edge_count //= 2  # every edge counted twice

                if edge_count == nodes * (nodes - 1) // 2:
                    ans += 1

        return ans
