class Solution {
public://optimal-> start calculation height from bottom
    int diameter=0;
    int maxDiameter(TreeNode* root){
        if(root==nullptr) return 0;

        //we will do post order traversal , calculate leftheight then rightheight and then the depth will be leftheight and rightheight;

        int lh=maxDiameter(root->left);
        int rh=maxDiameter(root->right);

        diameter=max(diameter,lh+rh);

        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         maxDiameter(root);
         return diameter;

    }
};