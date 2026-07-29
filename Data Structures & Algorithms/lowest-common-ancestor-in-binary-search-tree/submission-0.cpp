class Solution {
public:
    TreeNode* solve(TreeNode* root,TreeNode*p,TreeNode*q){
        if(root==nullptr) return nullptr;
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;

        TreeNode* leftans=solve(root->left,p,q);
        TreeNode* rightans=solve(root->right,p,q);

        if(leftans==nullptr && rightans==nullptr) return nullptr;

        else if(leftans==nullptr && rightans!=nullptr) return rightans;

        else if(leftans!=NULL && rightans==NULL) return leftans;

        else return root;
    }  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};