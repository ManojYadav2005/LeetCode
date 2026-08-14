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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1=l1;
    ListNode* temp2=l2;
    ListNode* dummy=new ListNode(-1);
    ListNode* curr=dummy;


    int carry=0;
    while(temp1!=NULL || temp2!=NULL){
    int sm=carry;
    if(temp1!=NULL){
    sm=sm+temp1->val;
    temp1=temp1->next;
    }
    if(temp2!=NULL){
    sm=sm+temp2->val;
    temp2=temp2->next;
    }
    ListNode* newnode=new ListNode(sm%10);
    curr->next=newnode;
    carry=sm/10;
    curr=curr->next;
    }  
    if(carry){
    ListNode* newnode=new ListNode(carry);
    curr->next=newnode;
    }   
    return dummy->next;
    }
};