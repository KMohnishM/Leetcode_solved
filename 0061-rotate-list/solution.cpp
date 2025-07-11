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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
          return NULL;
        }
        ListNode* temp=head;
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
       
        temp->next=head;
        
        k=k%count;
        
        ListNode* temp2=head;
        count=count-k-1;
        for(int i=0;i<count;i++){
            temp2=temp2->next;
        }
        ListNode* result=temp2->next;
        temp2->next=NULL;
        return result;
    }
};
