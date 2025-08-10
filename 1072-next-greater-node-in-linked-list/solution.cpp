class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        // Step 1: Store all values
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        vector<int> result(values.size(), 0);
        stack<int> st; // stores indices

        // Step 2: Monotonic stack
        for (int i = 0; i < values.size(); i++) {
            while (!st.empty() && values[i] > values[st.top()]) {
                result[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

