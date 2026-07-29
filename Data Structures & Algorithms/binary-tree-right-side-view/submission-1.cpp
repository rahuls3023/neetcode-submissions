class Solution {
public://DFS
    void solve(TreeNode* root, int level, vector<int>& ans) {
        // Base case
        if(root == nullptr) {
            return;
        }

        // If this is the first node we are visiting at this level,
        // then it is the rightmost node because we visit the right subtree first.
        if(level == ans.size()) {
            ans.push_back(root->val);
        }

        // Visit right subtree first
        solve(root->right, level + 1, ans);

        // Then visit left subtree
        solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        // Start DFS from level 0
        solve(root, 0, ans);

        return ans;
    }
};