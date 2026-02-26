class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> st;

        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* curr = slow->next;
        slow->next = NULL;  

        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        
        curr = head;

        while (!st.empty()) {
            ListNode* tmp = curr->next;
            ListNode* topNode = st.top();
            st.pop();

            curr->next = topNode;
            topNode->next = tmp;

            curr = tmp;
        }
    }
};
