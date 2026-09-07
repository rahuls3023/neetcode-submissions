class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }

        TreeNode* temp=root;

        while(true){
            if(val>temp->val){
                if(temp->right==nullptr){
                    TreeNode* newNode=new TreeNode(val);
                    temp->right=newNode;
                    break;
                }
                else{
                    temp=temp->right;
                }
            }

            else{
                if(temp->left==nullptr){
                    TreeNode* newNode=new TreeNode(val);
                    temp->left=newNode;
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
        }
        return root;
    }
};