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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;  
        }
        int r=n/2;
        if(r==0){return NULL;}
        ListNode* temp1=head;
        while(r>1){
           r--;
           temp1=temp1->next;
        }
        ListNode* temp2=temp1;
        temp2=temp2->next;
        temp1->next=temp2->next;
        
        return head;
    }
};
