class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:

        LEFT = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)
        MID = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)
        RIGHT = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)

        rows = {}

        for row, seat in reservedSeats:
            rows[row] = rows.get(row, 0) | (1 << seat)

        ans = (n - len(rows)) * 2

        for mask in rows.values():

            if mask & LEFT == 0 and mask & RIGHT == 0:
                ans += 2

            elif (
                mask & LEFT == 0
                or mask & MID == 0
                or mask & RIGHT == 0
            ):
                ans += 1

        return ans
