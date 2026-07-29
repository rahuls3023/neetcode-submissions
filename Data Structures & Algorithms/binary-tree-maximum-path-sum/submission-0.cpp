class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        // Current node ke saath left ya right me se best one-side path
        int koi_ek_side_acha = max(left, right) + root->val;

        // Path current node par turn le raha hai:
        // left subtree + current node + right subtree
        int niche_ka_acha = root->val + left + right;

        // Dono children ko ignore karke sirf current node lena
        int sirf_root_acha = root->val;

        // Current node par possible sabhi valid paths me se maximum store karo
        maxSum = max({
            maxSum,
            koi_ek_side_acha,
            niche_ka_acha,
            sirf_root_acha
        });

        // Parent ko sirf ek continuous side return kar sakte hain:
        // current node alone, current + left, ya current + right.
        // Dono sides return nahi kar sakte, warna parent add hone par Y-shape ban jayegi.
        return max(sirf_root_acha, koi_ek_side_acha);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};