class Solution {
public://recursive
    int getMax(TreeNode* root){
        if(root==nullptr) return -1;

        while(root->right!=nullptr){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;

        if(root->val==key){

            //leaf node
            if(root->left==nullptr && root->right==nullptr){
                delete root;
                return nullptr;
            }

            //only left child
            if(root->left!=nullptr && root->right==nullptr){
                TreeNode* firstnode=root->left;
                root->left=nullptr;
                delete root;
                return firstnode;
            }

            //only right child
            if(root->left==nullptr && root->right!=nullptr){
                TreeNode* firstnode=root->right;
                root->right=nullptr;
                delete root;
                return firstnode;
            }

            //we have both nodes
            else if(root->left!=nullptr && root->right!=nullptr){
                int maxVal=getMax(root->left);
                root->val=maxVal;
                root->left=deleteNode(root->left,maxVal);
                return root;
            }
        }
        else{
            if(key<root->val){
                root->left=deleteNode(root->left,key);
            }
            else{
                root->right=deleteNode(root->right,key);
            }
        }
        return root;
    }
};