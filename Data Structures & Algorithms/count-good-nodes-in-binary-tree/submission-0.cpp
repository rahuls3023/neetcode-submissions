/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root,int maxValue){
        if(root==nullptr) return 0;

        int count=0;

        //current node will be good only if 
        //no previous node in path has a value greater than maxValue;

        if(root->val>=maxValue){
            count=1;
        }

        // Update maximum value for child paths.
        int newMax = max(maxValue, root->val);

        count+=solve(root->left,newMax);
        count+=solve(root->right,newMax);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};
