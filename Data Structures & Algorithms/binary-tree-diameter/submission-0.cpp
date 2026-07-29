class Solution {
public://brute force
int diameter=0;
    int maxDiameter(TreeNode* root){
        if(root==nullptr) return 0;

        int leftSideDepth=maxDiameter(root->left);

        int rightSideDepth=maxDiameter(root->right);

        diameter=max(diameter,leftSideDepth+rightSideDepth);

        return 1+max(leftSideDepth,rightSideDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         maxDiameter(root);

         return diameter;
    }
};