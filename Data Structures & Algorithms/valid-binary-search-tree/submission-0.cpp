class Solution {
public:
    bool solve(TreeNode* root,long long minValue,long long maxValue){
        if(root==nullptr) return true;

        bool isCurrentNodeinRange=root->val>minValue && root->val<maxValue;

        bool leftcheck=solve(root->left,minValue,root->val);

        bool rightcheck=solve(root->right,root->val,maxValue);

        return leftcheck && rightcheck && isCurrentNodeinRange;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};