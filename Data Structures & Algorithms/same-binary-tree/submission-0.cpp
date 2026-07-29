class Solution {
public:
    bool checkForIt(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr && root2==nullptr) return true;
        
        if(root1==nullptr || root2==nullptr) return false;

        if(root1->val!=root2->val) return false;

        return checkForIt(root1->left,root2->left) && checkForIt(root1->right,root2->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkForIt(p,q);
    }
};