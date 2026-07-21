class Solution {
public://optimal approach
    ListNode* recursive(ListNode*l1,ListNode*l2,int carry=0){
        if(l1==nullptr && l2==nullptr && carry==0) return 0;

        int a=l1?l1->val:0;
        int b=l2?l2->val:0;

        int sum=a+b+carry;
        int digit=sum%10;
        carry=sum/10;

        ListNode* newNode=new ListNode(digit);

        newNode->next=recursive(l1?l1->next:nullptr,l2?l2->next:nullptr,carry);

        return newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1,l2);
    }
};
