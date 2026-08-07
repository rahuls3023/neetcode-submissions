class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp=head;
        int len=0;

        while(temp!=nullptr){
            temp=temp->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;

        int length=getLength(head);

        if(length<k){
            return head;
        }

        ListNode* prev=nullptr;
        ListNode* curr=head;
        int position=0;

        //reverse first k nodes
        while(position<k){
            ListNode* forward = curr->next;

            curr->next=prev;
            prev=curr;

            curr=forward;

            position++;
        }

        if(curr!=nullptr){
            ListNode* recursionHead=reverseKGroup(curr,k);

            head->next=recursionHead;
        }
        return prev;
    }
};