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
private:
    ListNode* headNode;
public:
    Solution(ListNode* head) {
        headNode = head;
        srand(time(NULL)); // seed the random generator
    }
    
    int getRandom() {
        int scope = 1;
        int chosenVal = 0;
        ListNode* curr = headNode;
        
        while (curr) {
            // With probability 1/scope, choose current node's valu
            if (rand() % scope == 0) {
                chosenVal = curr->val;
            }
            scope++;
            curr = curr->next;
        }
        return chosenVal;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
