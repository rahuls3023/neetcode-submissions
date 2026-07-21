class Solution {
public://brute force
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int>allValues;

        //store all values in one array
        for(auto list:lists){
             while(list!=nullptr){
                allValues.push_back(list->val);
                list=list->next;
            }
        }

        sort(allValues.begin(),allValues.end());

        ListNode* dummy=new ListNode(-1);
        ListNode* current=dummy;

        for(auto it:allValues){
            current->next=new ListNode(it);
            current=current->next;
        }
        return dummy->next;
    }
};