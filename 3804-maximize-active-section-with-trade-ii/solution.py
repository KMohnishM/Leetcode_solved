from dataclasses import dataclass
import itertools

@dataclass
class Group:
    start: int
    length: int

class SparseTable:
    def __init__(self, nums: list[int]):
        self.n = len(nums)
        # st[i][j] := max(nums[j..j + 2^i - 1])
        self.st = [[0] * (self.n + 1) for _ in range(self.n.bit_length() + 1)]
        self.st[0] = nums[:]
        for i in range(1, self.n.bit_length() + 1):
            for j in range(self.n - (1 << i) + 1):
                self.st[i][j] = max(self.st[i - 1][j], self.st[i - 1][j + (1 << (i - 1))])

    def query(self, l: int, r: int) -> int:
        """Returns max(nums[l..r])."""
        if l > r:
            return 0
        i = (r - l + 1).bit_length() - 1
        return max(self.st[i][l], self.st[i][r - (1 << i) + 1])

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: list[list[int]]) -> list[int]:
        ones = s.count('1')
        zero_groups, zero_group_index = self._get_zero_groups(s)
        
        if not zero_groups:
            return [ones] * len(queries)
        
        st = SparseTable(self._get_zero_merge_lengths(zero_groups))
        
        def get_max_active(l: int, r: int) -> int:
            # Partial lengths at boundaries
            left = (-1 if zero_group_index[l] == -1 else 
                    (zero_groups[zero_group_index[l]].length - (l - zero_groups[zero_group_index[l]].start)))
            right = (-1 if zero_group_index[r] == -1 else 
                     (r - zero_groups[zero_group_index[r]].start + 1))
            
            # Adjacent group range for full merges
            start_adj, end_adj = self._map_adjacent(zero_group_index[l] + 1,
                                                    zero_group_index[r] if s[r] == '1' else zero_group_index[r] - 1)
            
            active = ones
            
            # Case: same zero group covering whole query
            if (s[l] == '0' and s[r] == '0' and 
                zero_group_index[l] + 1 == zero_group_index[r]):
                active = max(active, ones + left + right)
            elif start_adj <= end_adj:
                active = max(active, ones + st.query(start_adj, end_adj))
            
            # Partial left + full next
            if (s[l] == '0' and zero_group_index[l] + 1 <= 
                (zero_group_index[r] if s[r] == '1' else zero_group_index[r] - 1)):
                active = max(active, ones + left + zero_groups[zero_group_index[l] + 1].length)
            
            # Full prev + partial right
            if (s[r] == '0' and zero_group_index[l] < zero_group_index[r] - 1):
                active = max(active, ones + right + zero_groups[zero_group_index[r] - 1].length)
            
            return active
        
        return [get_max_active(l, r) for l, r in queries]
    
    def _get_zero_groups(self, s: str):
        """Returns zero groups and index of group for each position."""
        zero_groups = []
        zero_group_index = []
        for i in range(len(s)):
            if s[i] == '0':
                if i > 0 and s[i-1] == '0':
                    zero_groups[-1].length += 1
                else:
                    zero_groups.append(Group(i, 1))
            zero_group_index.append(len(zero_groups) - 1 if zero_groups else -1)
        return zero_groups, zero_group_index
    
    def _get_zero_merge_lengths(self, zero_groups: list[Group]) -> list[int]:
        """Sums of lengths of adjacent 1-segments (via zero groups)."""
        return [a.length + b.length for a, b in itertools.pairwise(zero_groups)]
    
    def _map_adjacent(self, start: int, end: int) -> tuple[int, int]:
        """Map to valid adjacent group indices for range query."""
        return start, end - 1
