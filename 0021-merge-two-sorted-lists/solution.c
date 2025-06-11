/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy; // Dummy node to simplify list construction
    struct ListNode* current = &dummy; // Pointer to build the merged list
    
    // Merge lists while both have nodes
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes from list1 or list2
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    return dummy.next; // Return head of merged list
}
