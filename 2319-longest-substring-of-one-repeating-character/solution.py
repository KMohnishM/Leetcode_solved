class Solution:
    def longestRepeating(self, s, queryCharacters, queryIndices):
        n = len(s)

       
        tree = [None] * (4 * n)

        def merge(left, right):
            lc, rc, lp, ls, lb, llen = left
            lc2, rc2, rp, rs, rb, rlen = right

           
            prefix = lp
            suffix = rs
            best = max(lb, rb)

            
            if rc == lc2:
                best = max(best, ls + rp)

               
                if lp == llen:
                    prefix = llen + rp

               
                if rs == rlen:
                    suffix = ls + rlen

            return [
                lc,
                rc2,
                prefix,
                suffix,
                best,
                llen + rlen
            ]

        def build(node, l, r):
            if l == r:
                
                tree[node] = [
                    s[l],   
                    s[l],   
                    1,      
                    1,      
                    1,      
                    1       
                ]
                return

            mid = (l + r) // 2

            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)

            tree[node] = merge(
                tree[node * 2],
                tree[node * 2 + 1]
            )

        def update(node, l, r, idx, ch):
            if l == r:
                tree[node] = [
                    ch, ch,
                    1, 1, 1, 1
                ]
                return

            mid = (l + r) // 2

            if idx <= mid:
                update(node * 2, l, mid, idx, ch)
            else:
                update(node * 2 + 1, mid + 1, r, idx, ch)

            tree[node] = merge(
                tree[node * 2],
                tree[node * 2 + 1]
            )

        build(1, 0, n - 1)

        ans = []

        for ch, idx in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, idx, ch)
            ans.append(tree[1][4])  

        return ans
