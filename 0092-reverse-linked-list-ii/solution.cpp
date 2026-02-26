class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevLeft = &dummy;

        
        for (int i = 1; i < left; i++) {
            prevLeft = prevLeft->next;
        }

        ListNode* curr = prevLeft->next;

        
        ListNode* prev = NULL;
        for (int i = 0; i <= right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        
        prevLeft->next->next = curr;
        prevLeft->next = prev;

        return dummy.next;
    }
};
