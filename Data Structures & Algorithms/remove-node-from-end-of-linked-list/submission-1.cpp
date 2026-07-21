class Solution {
public://optimal approach-> using slow and fast pointer
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;

        //move fast n steps ahead
        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        //if fast becomes null it means we have to delete the head node
        if(fast==nullptr){
            return head->next;
        }

        //move slow to the previous node of the node which has to be deleted from ll.
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }

        //now slow will be at the previous node of node , need to be deleted.
        slow->next=slow->next->next;

        return head;
    }
};