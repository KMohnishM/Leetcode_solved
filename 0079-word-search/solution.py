class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])

        directions = [(0,1), (1,0), (-1,0), (0,-1)]
        visited = set()

        def dfs(i, j, k):
            if k == len(word):
                return True

            if not (0 <= i < n and 0 <= j < m):
                return False

            if (i, j) in visited:
                return False

            if board[i][j] != word[k]:
                return False

            visited.add((i, j))

            for dr, dc in directions:
                if dfs(i + dr, j + dc, k + 1):
                    return True

            visited.remove((i, j))

            return False

        for i in range(n):
            for j in range(m):
                if dfs(i, j, 0):
                    return True

        return False
