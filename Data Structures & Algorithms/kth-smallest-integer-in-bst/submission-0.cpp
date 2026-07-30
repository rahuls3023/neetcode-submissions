class Solution {
public://approach-1> inorder traversal and return value
    void solve(TreeNode* root,vector<int>&inorder){
        if(root==nullptr) return;

        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        solve(root,inorder);

        return inorder[k-1];
    }
};