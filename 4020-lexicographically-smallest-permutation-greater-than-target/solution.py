from collections import Counter

class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:

        freq = Counter(s)
        keys = sorted(freq)

        ans = []
        for i in range(len(target)):
            if freq[target[i]] > 0:
                ans.append(target[i])
                freq[target[i]] -= 1
            else:
                bigger = None
                for ch in keys:
                    if ch > target[i] and freq[ch] > 0:
                        bigger = ch
                        break

                if bigger is not None:
                    ans.append(bigger)
                    freq[bigger] -= 1
                    for ch in keys:
                        ans.append(ch * freq[ch])

                    return ''.join(ans)                
                break
        freq = Counter(s)

        for i in range(len(target)):
            freq[target[i]] -= 1
            if freq[target[i]] < 0:
                break
        
        for i in range(len(target) - 1, -1, -1):           
            remaining = Counter(s)
            possible = True
            for j in range(i):
                remaining[target[j]] -= 1
                if remaining[target[j]] < 0:
                    possible = False
                    break
            if not possible:
                continue

            for ch in keys:
                if ch > target[i] and remaining[ch] > 0:
                    result = target[:i] + ch
                    remaining[ch] -= 1
                    for x in keys:
                        result += x * remaining[x]

                    return result

        return ""
