class Solution {
public://kind of brute -> 2 traversal
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root==nullptr) return nullptr;

        
        //1st-> find the key node
        TreeNode* parent = NULL;
        TreeNode* temp = root;

        while( temp!=nullptr && temp->val!=key){
            if(temp->val>key){
                //left side jao
                parent=temp;
                temp=temp->left;
            }
            else{
                parent=temp;
                temp=temp->right;
            }
        }
        if(temp == nullptr) return root;

        //ab delete wala part krege, as temp us key node pe hoga

        //4 cases ho skte h for delete

        //1st case-> agar sirf right child h
        if(temp->left==nullptr && temp->right!=nullptr){
            //agar delete hone waali node root h
            if(parent==nullptr){
                root=temp->right;
            }

            //agar temp parent ka left child h
            else if(parent->left==temp){
                parent->left=temp->right;
            }
            else{
                //agar temp, parent ka right child h
                parent->right=temp->right;
            }
        }

        //2nd case-> leaf node hai
        else if(temp->left==nullptr && temp->right==nullptr){
            // Agar root hi leaf node hai
            if(parent == nullptr) {
                return nullptr;
            }
            
            //agar temp left child h parent ka
             if(parent->left==temp){
                parent->left=nullptr;
            }
            else{
                parent->right=nullptr;
            }
        }

        //3rd case-> agar sirf left child h
        else if(temp->left!=nullptr && temp->right==nullptr){
            if(parent==nullptr){
                root=temp->left;
            }
            
            //agar temp , parent ka left child h
            else if(parent->left==temp){
                parent->left=temp->left;
            }
            else{
                //agar temp, parent ka right h
                parent->right=temp->left;
            }
        }


        //4th case-> if left and right dono h

        //right subtree ka minimum uthao, as vo temp se bda hoga and right sidr me sbse chota
        else{
            //temp->left!=nullptr && temp->right!=nullptr//

            TreeNode* succParent=temp;
            TreeNode* succ=temp->right;

            //search for minimum value in right subtree
            while(succ->left!=nullptr){
                succParent=succ;
                succ=succ->left;
            }

            //copy successor value into temp
            temp->val=succ->val;

            //ab succ ko htao
            //succ ka left child to kbhi hoga hi nhi , agar ho skta h to right child
            if(succParent->left==succ){
                //successor is the left child of its parent
                succParent->left=succ->right;
            }
            else{
                succParent->right=succ->right;//ye bhul jauga
            }
        }
        return root;
    }
};