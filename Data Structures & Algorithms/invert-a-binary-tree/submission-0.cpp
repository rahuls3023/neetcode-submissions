
class Solution {
public:
    TreeNode* solve(TreeNode* root){
        if(root==nullptr) return root;

        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        solve(root->left);
        solve(root->right);

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};
