class Solution {
public://approach-1> using array
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>listArray;

        ListNode* temp1=list1;
        ListNode* temp2=list2;

        while(temp1!=nullptr){
            listArray.push_back(temp1->val);
            temp1=temp1->next;
        }

        while(temp2!=nullptr){
            listArray.push_back(temp2->val);
            temp2=temp2->next;
        }

        sort(listArray.begin(),listArray.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        for(int i=0;i<listArray.size();i++){
            ListNode* newNode = new ListNode(listArray[i]);
            current->next=newNode;
            current=current->next;
        }
        return dummy->next;
    }
};
