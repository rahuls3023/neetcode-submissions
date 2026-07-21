class Solution {
public://optimal approach using slow and fast pointer and merging.
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;

        ListNode* fast=head;
        ListNode* slow=head;

        //step-1> find middle
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        //step-2> reverse the second half
        ListNode* prev=nullptr;
        ListNode* current=slow->next;

        // Break the original list into two separate halves.
        slow->next = nullptr;

        while(current!=nullptr){

              // Store the next node before reversing the link.
            ListNode* nextNode = current->next;

            // Reverse the current node's pointer.
            current->next = prev;

            //move both pointer
            prev=current;
            current=nextNode;
        }

        //now we got 2 halves one simple and one reversed;

        // prev is now the head of the reversed second half.
        ListNode* first = head;
        ListNode* second = prev;

        //step-3> now attach the list alternatively

        while(second!=nullptr){
             // Save the next nodes before changing the links.
            ListNode* firstnext = first->next;
            ListNode* secondnext = second->next;

            // Insert one node from the second half
            // after one node from the first half.
            first->next = second;
            second->next = firstnext;

            //move both pointers
            first = firstnext;
            second = secondnext;
        }
    }
};
