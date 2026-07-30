class Solution {
public://approach-1>
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx){
        if(start>end) return nullptr;

        int rootVal=preorder[idx];//root hogya

        int i=start;//current start se start krege and end tk jayege inorder me to find index of root

        for(;i<=end;i++){
            if(inorder[i]==rootVal)break;
        }

        idx++;//current root work done , update it

         TreeNode* root=new TreeNode(rootVal);

         root->left=solve(preorder,inorder,start,i-1,idx);
         root->right=solve(preorder,inorder,i+1,end,idx);

         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        int idx=0;//traverse  index on preorder array

        return solve(preorder,inorder,0,n-1,idx);
    }
};