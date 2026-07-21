class Solution {
public://optimal-> using min heap
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;//{value, node_address}

        //push the head of each list into heap

        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val,lists[i]});//lists[i] will directly point to the head of that list
            }
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* current=dummy;

        while(!pq.empty()){
            auto mini=pq.top();
             ListNode* node=mini.second;

             pq.pop();

             current->next=node;

             current=current->next;

              //push next nodes
            if(node->next!=nullptr){
                pq.push({node->next->val,node->next});
            }
        }
        return dummy->next;

    }
};