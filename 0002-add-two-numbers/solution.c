/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; // Dummy node to simplify list construction
    struct ListNode* current = &dummy; // Pointer to build the result list
    int carry = 0; // Carry for addition

    // Continue while there are digits or a carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        // Get values from l1 and l2, use 0 if list is exhausted
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        // Calculate sum and new carry
        int total = x + y + carry;
        carry = total / 10;
        int digit = total % 10;

        // Create new node for the current digit
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = digit;
        current->next = NULL;

        // Move to next nodes if available
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next; // Return the head of the result list
}
