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
    TreeNode* f(TreeNode* node, int val, int d , int curr){
        if(node == NULL) return NULL;

        if(curr == d-1){
            TreeNode* lefttemp = node->left;
            TreeNode* righttemp = node->right;

            node->left = new TreeNode(val);
            node->right = new TreeNode(val);

            node->left->left =  lefttemp;
            node->right->right = righttemp;

            return node;
        }

        node->left = f(node->left , val , d, curr + 1);
        node->right = f(node->right , val , d , curr + 1);

        return node;


    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int curr = 1;

        return f(root , val , depth , curr);
    }
};