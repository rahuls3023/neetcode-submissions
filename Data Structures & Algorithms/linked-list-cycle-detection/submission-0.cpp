class Solution {
public://method-1>  brute force-> using hashset
    bool hasCycle(ListNode* head) {
         unordered_set<ListNode*> st;

        ListNode* temp=head;
        while(temp!=nullptr){
            if(st.find(temp)!=st.end()){
                return true;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};
