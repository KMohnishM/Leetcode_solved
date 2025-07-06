# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        s=""
        curr=head
        while curr:
           s+=str(curr.val)
           curr=curr.next
        if s==s[::-1] :
            return True
        else:
            return False        


        
