class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n, m = len(word1), len(word2)

        suf = [0] * (n + 1)
        j = m - 1
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1]
            if j >= 0 and word1[i] == word2[j]:
                suf[i] += 1
                j -= 1

        ans = []
        i = 0
        used = False

        for j in range(m):
            while i < n:
                if word1[i] == word2[j]:
                    ans.append(i)
                    i += 1
                    break

                if not used and suf[i + 1] >= m - j - 1:
                    ans.append(i)
                    used = True
                    i += 1
                    break

                i += 1
            else:
                return []

        return ans
