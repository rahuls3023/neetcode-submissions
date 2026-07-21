class Solution {
public://recursive approach
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* newHead=reverseList(head->next);//last tk jao

        head->next->next=head;
        head->next=nullptr;

        return newHead;
    }
};
