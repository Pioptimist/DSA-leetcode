/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root, int k, int &cnt) {
        if (root == nullptr)
            return -1;   // means not found (assuming all BST values >= 0)

        // 1️⃣ Check left subtree
        int leftRes = inorder(root->left, k, cnt);
        if (leftRes != -1)
            return leftRes;

        // 2️⃣ Visit current node
        cnt++;
        if (cnt == k)
            return root->val;

        // 3️⃣ Check right subtree
        return inorder(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, k, cnt);
    }

};