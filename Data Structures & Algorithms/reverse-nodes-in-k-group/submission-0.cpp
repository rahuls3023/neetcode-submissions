class Solution {
public: // Optimal approach using recursion

    // Returns the total number of nodes in the linked list
    int getlength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // If linked list is empty or has only one node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find the length of the current linked list
        int length = getlength(head);

        // If remaining nodes are less than k,
        // they should remain unchanged
        if (length < k) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int position = 0;

        // Reverse the first k nodes
        while (position < k) {

            // Store the next node before changing the link
            ListNode* forward = curr->next;

            // Reverse the current node's pointer
            curr->next = prev;

            // Move both pointers one step ahead
            prev = curr;
            curr = forward;

            position++;
        }

        /*
            One group of k nodes has been reversed.

            prev = new head of the reversed group
            head = last node of the reversed group
            curr = head of the remaining linked list
        */

        // Recursively reverse the remaining linked list
        if (curr != nullptr) {
            ListNode* recursionHead = reverseKGroup(curr, k);

            // Connect the current reversed group
            // with the remaining reversed linked list
            head->next = recursionHead;
        }

        // Return the new head of the current reversed group
        return prev;
    }
};