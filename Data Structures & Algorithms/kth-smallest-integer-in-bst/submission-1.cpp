class Solution {
public://count approach
    void solve(TreeNode*root,int k,int &count,int &answer){
        if(root==nullptr) return;

        solve(root->left,k,count,answer);

        count++;

        //instead of pushing into array check if we got kth smallest value
        if(count==k){
            answer=root->val;
            return;
        }

        solve(root->right,k,count,answer);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int answer=-1;

        solve(root,k,count,answer);
        return answer;
    }
};