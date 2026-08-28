from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        freq = Counter(s)

        odd = [ch for ch in freq if freq[ch] % 2]

        if len(odd) > 1:
            return ""

        mid = odd[0] if odd else ""

        half = Counter()
        for ch in freq:
            half[ch] = freq[ch] // 2

        m = len(s) // 2
        keys = sorted(half)

        def make_pal(left):
            return left + mid + left[::-1]

        def build_smallest(freq):
            res = ""
            for ch in keys:
                res += ch * freq[ch]
            return res

        target_left = target[:m]

        for i in range(m):
            if half[target_left[i]] > 0:
                half[target_left[i]] -= 1
            else:
                break
        else:
            left = target_left
            candidate = make_pal(left)

            if candidate > target:
                return candidate

            half = Counter()
            for ch in freq:
                half[ch] = freq[ch] // 2

        for i in range(m - 1, -1, -1):
            remaining = Counter()

            for ch in freq:
                remaining[ch] = freq[ch] // 2

            valid = True

            for j in range(i):
                remaining[target_left[j]] -= 1
                if remaining[target_left[j]] < 0:
                    valid = False
                    break

            if not valid:
                continue

            for ch in keys:
                if ch > target_left[i] and remaining[ch] > 0:
                    remaining[ch] -= 1

                    left = target_left[:i] + ch
                    left += build_smallest(remaining)

                    candidate = make_pal(left)

                    if candidate > target:
                        return candidate

        return ""
