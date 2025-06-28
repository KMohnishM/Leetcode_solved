class Solution(object):
    def calculate(self, s):
        total, num, sign = 0, 0, 1
        stack = []

        for ch in s:
            if ch.isdigit():
                num = num * 10 + int(ch)
            elif ch == '+':
                total += sign * num
                num, sign = 0, 1
            elif ch == '-':
                total += sign * num
                num, sign = 0, -1
            elif ch == '(':
                stack.append((total, sign))
                total, num, sign = 0, 0, 1
            elif ch == ')':
                total += sign * num
                prev_total, prev_sign = stack.pop()
                total = prev_total + prev_sign * total
                num = 0

        return total + sign * num

