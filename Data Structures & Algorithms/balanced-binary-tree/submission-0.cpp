class Solution {
public://brute force
    int height(TreeNode* root){
        if(root==nullptr) return 0;

        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};