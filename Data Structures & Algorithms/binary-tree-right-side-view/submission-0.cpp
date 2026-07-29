class Solution {
public://approac-1>
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return {};

        q.push(root);

        vector<int>ans;

        while(!q.empty()){
            vector<int>level;
            int size=q.size();
            
            for(int i=0;i<size;i++){
                auto current=q.front();
                q.pop();

                if(i==size-1){
                    ans.push_back(current->val);
                }

                if(current->left!=NULL){
                    q.push(current->left);
                }

                if(current->right!=NULL){
                    q.push(current->right);
                }
            }
        }
        return ans;
    }
};