class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num) // 2

        left_sum = right_sum = 0
        left_q = right_q = 0

        for c in num[:n]:
            if c == '?':
                left_q += 1
            else:
                left_sum += int(c)

        for c in num[n:]:
            if c == '?':
                right_q += 1
            else:
                right_sum += int(c)

        diff = left_sum - right_sum

        if left_q == right_q:
            return diff != 0

        return 2 * diff + 9 * (left_q - right_q) != 0
