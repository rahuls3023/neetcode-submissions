class Solution {
public://brute force using stack
    void reorderList(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return ;

        vector<ListNode*>elements;
        ListNode* temp=head;

        while(temp!=nullptr){
            elements.push_back(temp);
            temp=temp->next;
        }

        //now traverse over array
        int left=0;
        int right=elements.size()-1;

        while(left<right){
            elements[left]->next=elements[right];
            left++;

            if(left==right) break;

            elements[right]->next=elements[left];
            right--;
        }
        elements[left]->next=nullptr;
    }
};
