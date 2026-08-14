/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     ListNode* checkCycle(ListNode *head) {
     
     ListNode* slow=head;
     ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast) return fast; 
    }
    return NULL;

     }
    ListNode *detectCycle(ListNode *head) {
    
     ListNode* slow=head;
     ListNode* fastnew=checkCycle(head);
     if (fastnew == NULL) return NULL;
     
     while(slow!=fastnew){
     slow=slow->next;
     fastnew=fastnew->next;
     }
     return slow;
    }
};