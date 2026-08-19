class Solution {
public:
    bool solve(TreeNode* root, int targetSum) {

        //node exist nhi krta
        if(root == NULL) return false;

        //leaf node par aa gye
        if(root->left == NULL && root->right == NULL){
            return targetSum == root->val;
        }

        bool left = solve(root->left, targetSum - root->val);

        bool right = solve(root->right, targetSum - root->val);

        return (left || right);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};