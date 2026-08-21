from math import gcd

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:

        n = len(coins)

        
        coins.sort()
        filtered = []

        for c in coins:
            if not any(c % x == 0 for x in filtered):
                filtered.append(c)

        coins = filtered
        n = len(coins)

        def lcm(a, b):
            return a // gcd(a, b) * b

        def count(x):
            total = 0

          
            for mask in range(1, 1 << n):

                curr_lcm = 1
                bits = 0
                valid = True

                for i in range(n):
                    if mask & (1 << i):
                        curr_lcm = lcm(curr_lcm, coins[i])

                        
                        if curr_lcm > x:
                            valid = False
                            break

                        bits += 1

                if not valid:
                    continue

              
                amount = x // curr_lcm

              
                if bits % 2 == 1:
                    total += amount
                else:
                    total -= amount

            return total

       
        left = 1
        right = min(coins) * k

        while left < right:
            mid = (left + right) // 2

            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left
