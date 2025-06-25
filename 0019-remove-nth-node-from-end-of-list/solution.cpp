class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ---------- 1. First pass: compute length ----------
        int len = 0;
        for (ListNode* p = head; p; p = p->next) ++len;

        // Node position to delete from the *start* (0-indexed):
        int k = len - n;                // k == 0 → delete the head

        // ---------- 2. Second pass: stop one node before target ----------
        ListNode dummy(0, head);        // handles “delete head”
        ListNode* prev = &dummy;
        for (int i = 0; i < k; ++i) {
            prev = prev->next;          // after loop, prev->next is target
        }

        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;

        return dummy.next;
    }
};

