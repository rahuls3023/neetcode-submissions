class Solution {
public://brute force using stack
    void reorderList(ListNode* head) {
        stack<ListNode*>st;

        ListNode* temp=head;

        while(temp!=nullptr){
            st.push(temp);
            temp=temp->next;
        }

        ListNode* current=head;

        int n=st.size();

        for(int i=0;i<n/2;i++){
             // Store the next node before changing any links.
            ListNode* nextNode = current->next;

            // Get the last node from the stack.
            ListNode* lastNode = st.top();
            st.pop();

            // Connect current node to the last node.
            current->next = lastNode;

             // Connect the last node to the original next node.
            lastNode->next = nextNode;

            // Move to the next node of the first half.
            current = nextNode;
        }
         // Break the old connection to avoid a cycle.
        current->next = nullptr;
    }
};
