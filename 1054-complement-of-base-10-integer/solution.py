class Solution(object):
    def bitwiseComplement(self, n):
        """
        :type n: int
        :rtype: int
        """
        binary_str = bin(n)[2:]
        flipped_str = "".join('1' if bit == '0' else '0' for bit in binary_str)
        result = int(flipped_str, 2)
        return result
