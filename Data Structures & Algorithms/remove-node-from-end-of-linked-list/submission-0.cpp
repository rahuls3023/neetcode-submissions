class Solution {
public://brute force by finding length
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;

        int length=0;
        
        while(temp!=nullptr){
            length++;
            temp=temp->next;
        }

        int stepsToMove=length-n;

        
        if (stepsToMove == 0) {
            return head->next;
        }

        temp=head;
        ListNode* prev=head;

        while(stepsToMove--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=nullptr;
        return head;
    }
};
