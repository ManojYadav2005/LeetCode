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
   
    ListNode* reverse(ListNode* slowhead){
    ListNode* temp=slowhead;
    ListNode* prev=NULL;

    while(temp!=NULL){
    ListNode* front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
    }
    return prev;
    }


    bool isPalindrome(ListNode* head){
    if (head==NULL || head->next==NULL) return true;
    
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    } 
    ListNode* newhead=reverse(slow); 

    ListNode* start=head;

    while(newhead!=NULL){
    if(start->val !=newhead->val) return false;
    start=start->next;
    newhead=newhead->next;
    } 
     return true;
    }
};