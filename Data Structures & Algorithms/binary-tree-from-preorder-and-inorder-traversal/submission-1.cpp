class Solution {
public://approach-2>using map instea of linear search in inorder
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx,unordered_map<int,int>&mp){
        if(start>end) return nullptr;

        int rootVal=preorder[idx];//root hogya

        idx++;//current root work done , update it

        int i=mp[rootVal];//index of root in inorder array

         TreeNode* root=new TreeNode(rootVal);

         root->left=solve(preorder,inorder,start,i-1,idx,mp);
         root->right=solve(preorder,inorder,i+1,end,idx,mp);

         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        unordered_map<int,int>mp;

        for(int i=0;i<inorder.size();i++){//store the element->index for inorder array
            mp[inorder[i]]=i;
        }

        int idx=0;//traverse  index on preorder array

        return solve(preorder,inorder,0,n-1,idx,mp);
    }
};