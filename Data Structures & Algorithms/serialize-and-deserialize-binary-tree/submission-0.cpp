// Serialize using level order traversal.
// "N" represents a null node.
// During deserialization, stringstream is used to extract values separated by commas.

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // Empty tree
        if(root == nullptr) return "";

        // Queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);

        string ans = "";

        while(!q.empty()) {

            // Get the current node
            TreeNode* node = q.front();
            q.pop();

            // If current node is null, store "N"
            if(node == nullptr) {
                ans += "N,";
                continue;
            }

            // Store the current node's value
            ans += to_string(node->val) + ",";

            // Push both children into the queue.
            // No need to check for null because null children
            // are also required to preserve the structure of the tree.
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }


    // Decodes the serialized string back into a binary tree.
    TreeNode* deserialize(string data) {

        // Empty string means empty tree
        if(data.empty()) return nullptr;

        // Stringstream helps us read values separated by commas
        stringstream s(data);
        string str;

        // First value represents the root node
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        // Queue stores the nodes whose children are yet to be created
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            // Get the current parent node
            TreeNode* node = q.front();
            q.pop();


            // -------- LEFT CHILD --------

            // Read the next value from the serialized string
            getline(s, str, ',');

            // If it is not "N", create the left child
            if(str != "N") {

                TreeNode* leftnode = new TreeNode(stoi(str));

                // Attach left child to current node
                node->left = leftnode;

                // Push it because we need to construct its children later
                q.push(leftnode);
            }


            // -------- RIGHT CHILD --------

            // Read the next value from the serialized string
            getline(s, str, ',');

            // If it is not "N", create the right child
            if(str != "N") {

                TreeNode* rightnode = new TreeNode(stoi(str));

                // Attach right child to current node
                node->right = rightnode;

                // Push it because we need to construct its children later
                q.push(rightnode);
            }
        }

        // Return the reconstructed binary tree
        return root;
    }
};