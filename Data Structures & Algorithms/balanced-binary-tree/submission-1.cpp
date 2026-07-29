class Solution {
public://optimal approach
    int checkHeight(TreeNode* root){
        if(root==nullptr) return 0;

        //calculate left subtree height
        int leftHeight=checkHeight(root->left);
        if(leftHeight==-1) return -1;

        //calculate right subtreee height
        int rightHeight=checkHeight(root->right);
        if(rightHeight==-1) return -1;

        //check current node
        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }

        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root)!=-1;
    }
};