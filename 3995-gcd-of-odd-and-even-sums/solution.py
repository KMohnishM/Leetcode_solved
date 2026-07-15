import math
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumodd=pow(n,2)
        sumeven=sumodd+n
        return math.gcd(sumodd,sumeven)
