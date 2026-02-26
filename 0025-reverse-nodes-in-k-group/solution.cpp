class Solution {
public:
    ListNode* knode(ListNode* temp, int k) {
        while (temp && --k) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = knode(groupPrev->next, k);
            if (!kth) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};
