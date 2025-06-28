class Solution:
    def largestOddNumber(self, num):
        # walk from the rightmost digit to the left
        for i in range(len(num) - 1, -1, -1):
            if (ord(num[i]) - 48) & 1:          # faster odd-check than int()
                return num[: i + 1]             # longest odd-ending prefix
        return ""                               # no odd digit found

