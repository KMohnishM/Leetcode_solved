class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        MOD = 10**9 + 7
        n = len(board)

      
        dp_score = [[-1] * n for _ in range(n)]
        dp_count = [[0] * n for _ in range(n)]

        dp_score[0][0] = 0
        dp_count[0][0] = 1

        for i in range(n):
            for j in range(n):

                if board[i][j] == 'X':
                    continue

                if i == 0 and j == 0:
                    continue

                best = -1
                ways = 0

                for x, y in [(i - 1, j), (i, j - 1), (i - 1, j - 1)]:
                    if x < 0 or y < 0:
                        continue

                    if dp_score[x][y] == -1:
                        continue

                    if dp_score[x][y] > best:
                        best = dp_score[x][y]
                        ways = dp_count[x][y]

                    elif dp_score[x][y] == best:
                        ways = (ways + dp_count[x][y]) % MOD

                if best == -1:
                    continue

                val = 0
                if board[i][j].isdigit():
                    val = int(board[i][j])

                dp_score[i][j] = best + val
                dp_count[i][j] = ways % MOD

        if dp_score[n - 1][n - 1] == -1:
            return [0, 0]

        return [dp_score[n - 1][n - 1], dp_count[n - 1][n - 1]]
