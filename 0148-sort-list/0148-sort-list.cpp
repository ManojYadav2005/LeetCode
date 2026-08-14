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
    ListNode* findmiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    }
    return slow;
    }
    
    ListNode* merge(ListNode* temp1,ListNode* temp2){
    
    ListNode* dummy=new ListNode(-1);
    ListNode* res=dummy;

    while(temp1!=NULL && temp2!=NULL){
    if(temp1->val<=temp2->val){
    res->next=temp1;
    res=res->next;
    temp1=temp1->next;
    }
    else{
    res->next=temp2;
    res=res->next;
    temp2=temp2->next;
    }
    }
    if(temp1) res->next=temp1;
    else res->next=temp2;

    return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    
    // Find last node of first half
    ListNode* middle=findmiddle(head);  
    // Split kro left aur right half mein
    ListNode* right=middle->next;
    middle->next=NULL;

    ListNode* left=head;
    // Recursively sort both halves
    left=sortList(left);
    right=sortList(right);
    
    // Merge sorted halves
    return merge(left,right);

    }
};