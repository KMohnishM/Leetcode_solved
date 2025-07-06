# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        seen = {}     
        curr = head
        i = 0

        while curr:
            if curr in seen:
                # print("tail connects to node index")
                # print(seen[curr])
                return curr         
            else:
                seen[curr] = i
                i += 1
                curr = curr.next

        # print("no cycle")
        return None   

