class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        c2 = c3 = c5 = c7 = 0
        temp = t
        while temp % 2 == 0: c2 += 1; temp //= 2
        while temp % 3 == 0: c3 += 1; temp //= 3
        while temp % 5 == 0: c5 += 1; temp //= 5
        while temp % 7 == 0: c7 += 1; temp //= 7

        if temp > 1:
            return "-1"

        n = len(num)

        digit_factors = [
            (0, 0, 0, 0),
            (0, 0, 0, 0),
            (1, 0, 0, 0),
            (0, 1, 0, 0),
            (2, 0, 0, 0),
            (0, 0, 1, 0),
            (1, 1, 0, 0),
            (0, 0, 0, 1),
            (3, 0, 0, 0),
            (0, 2, 0, 0)
        ]

        def build_suffix(f2, f3, f5, f7, space):
            needed = (f3 + 1) // 2 + (f2 + 2) // 3 + f7 + f5
            if f2 % 3 == 1 and f3 % 2 == 1:
                needed -= 1
            if needed > space:
                return None
            
            res = []
            while f3 >= 2: res.append('9'); f3 -= 2
            while f2 >= 3: res.append('8'); f2 -= 3
            while f7 >= 1: res.append('7'); f7 -= 1
            if f2 >= 1 and f3 >= 1: res.append('6'); f2 -= 1; f3 -= 1
            while f5 >= 1: res.append('5'); f5 -= 1
            while f2 >= 2: res.append('4'); f2 -= 2
            while f3 >= 1: res.append('3'); f3 -= 1
            while f2 >= 1: res.append('2'); f2 -= 1

            res.extend(['1'] * (space - len(res)))
            res.sort()
            return "".join(res)

        pref2 = [0] * (n + 1)
        pref3 = [0] * (n + 1)
        pref5 = [0] * (n + 1)
        pref7 = [0] * (n + 1)
        first_zero = n

        for idx, ch in enumerate(num):
            if ch == '0':
                first_zero = idx
                break
            d = int(ch)
            f2, f3, f5, f7 = digit_factors[d]
            pref2[idx + 1] = pref2[idx] + f2
            pref3[idx + 1] = pref3[idx] + f3
            pref5[idx + 1] = pref5[idx] + f5
            pref7[idx + 1] = pref7[idx] + f7

        for i in range(min(n, first_zero), -1, -1):
            p2, p3, p5, p7 = pref2[i], pref3[i], pref5[i], pref7[i]
            r2, r3, r5, r7 = max(0, c2 - p2), max(0, c3 - p3), max(0, c5 - p5), max(0, c7 - p7)

            if i == n:
                if r2 == 0 and r3 == 0 and r5 == 0 and r7 == 0:
                    return num
                continue

            start_digit = int(num[i]) + 1
            for d in range(start_digit, 10):
                f2, f3, f5, f7 = digit_factors[d]
                rem2, rem3, rem5, rem7 = max(0, r2 - f2), max(0, r3 - f3), max(0, r5 - f5), max(0, r7 - f7)
                
                suf = build_suffix(rem2, rem3, rem5, rem7, n - 1 - i)
                if suf is not None:
                    return num[:i] + str(d) + suf

        target_len = n + 1
        while True:
            suf = build_suffix(c2, c3, c5, c7, target_len)
            if suf is not None:
                return suf
            target_len += 1
