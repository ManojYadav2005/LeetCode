class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        for(int i=0;i<k;i++) {
        if(temp==NULL)return head;
        temp=temp->next;
        }
        ListNode* prev=NULL;
        ListNode* temp1=head;

        for(int i=0;i<k;i++){
        ListNode* front=temp1->next;
        temp1->next=prev;
        prev=temp1;
        temp1=front;
        }
        head->next=reverseKGroup(temp1,k); 
        return prev;
    }
};