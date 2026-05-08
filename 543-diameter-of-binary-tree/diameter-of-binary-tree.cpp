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
    int find_max(TreeNode* node ,int &diameter){
        if(node == nullptr){
            return 0;
        }

        int lh = find_max(node->left , diameter);
        int rh = find_max(node->right , diameter);

        diameter = max(diameter , lh + rh);

        return 1 + max(lh , rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        find_max(root, diameter);
        return diameter;
        
    }
};