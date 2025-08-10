/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;

        // Push all nodes into stack
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        int carry = 0;
        // Process from last node to first
        while (!st.empty()) {
            ListNode* node = st.top();
            st.pop();

            int val = node->val * 2 + carry;
            node->val = val % 10;
            carry = val / 10;
        }

        // If there's still carry, create new head
        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};
